#include "MyEngine.hpp"

MyEngine::MyEngine(uint scrWidth, uint scrHeight, int vsync){

    //Keyboard keys to false
    for (uint i = 0; i < 255; i++) keyboard[i] = false;

    SCR_WIDTH = scrWidth;
    SCR_HEIGHT = scrHeight;

    this->vsync = vsync;
}

int MyEngine::init(){
    //Initialize GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //Create window
    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "myEngine2D", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, MyEngine::framebuffer_size_callback);
    //We can only disable vsync when we set a current context
    glfwSwapInterval(vsync);

    //Load OpenGL pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glEnable(GL_DEPTH_TEST | GL_CULL_FACE);
    //Vertex of a quad maded out of 2 triangles
    vertices = new float[40]{
    // positions          // colors           // texture coords
         0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   0.09f, 0.09f, // top right
         0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   0.09f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 0.09f  // top left  
    };

    indices = new uint[6]{
        0, 2, 1,
        0, 3, 2
    };

    glViewport(0,0,SCR_WIDTH, SCR_HEIGHT);

    shader = new Shader("../shaders/vertex.glsl", "../shaders/fragment.glsl");
    camera = new Camera(SCR_WIDTH, SCR_HEIGHT);
    shader->use();
    camera->update(*shader);
    //Generate a buffer and assigned and index to the VAO, VBO and EVO
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 40, vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint) * 6, indices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // texture coord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    
    // load and create a texture 
    // -------------------------
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    // load image, create texture and generate mipmaps
    stbi_set_flip_vertically_on_load(true);
    int width, height, nrChannels;
    unsigned char *data = stbi_load("../Player2.png", &width, &height, &nrChannels, 0);
    if (data)
    {

        // note that the awesomeface.png has transparency and thus an alpha channel, so make sure to tell OpenGL the data type is of GL_RGBA
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

    // tell opengl for each sampler to which texture unit it belongs to (only has to be done once)
    // -------------------------------------------------------------------------------------------
    shader->use(); // don't forget to activate/use the shader before setting uniforms!
    // either set it manually like so:
    shader->setInt("myTexture", 0);
    return 0;
}


void MyEngine::setScene(Scene *s){
    scene = s;
}


int MyEngine::startMainLoop(){
    auto start = std::chrono::high_resolution_clock::now();
    uint64_t elapsedTime;
    uint64_t elapsedTime2;

    uint64_t UPS = 1000000000/60;
    uint64_t nanoseconds = 1000000000;
    uint FPS = 0;
    uint UPSR = 0;

    // render loop
    // -----------
    shader = new Shader("../shaders/vertex.glsl", "../shaders/fragment.glsl");
    shader->use();
    glm::vec2 pos(0.7f, 0.7f);
    shader->setVec2("tilePos", pos);
    float textmov = 0.002f;

    
    while (!glfwWindowShouldClose(window))
    {

        auto finish = std::chrono::high_resolution_clock::now();
        elapsedTime += std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count();
        elapsedTime2 += std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count();
        start = finish;

        shader->use();

        if(elapsedTime2 >= nanoseconds){
            std::cout << "FPS: " << FPS <<  " UPS: " << UPSR << std::endl;
            elapsedTime2 = 0;
            FPS = 0; UPSR = 0;
        }
        FPS++; 
        if (elapsedTime >= UPS){
            elapsedTime = 0;
            pos.x +=textmov;
            shader->use();
            shader->setVec2("tilePos", pos);
            UPSR++;
            
            scene->update();
            if (keyboard[GLFW_KEY_D] == true)
                camera->translate(glm::vec3(0.02f, 0.0f, 0.0f));
            if (keyboard[GLFW_KEY_A])
                camera->translate(glm::vec3(-0.02f, 0.0f, 0.0f));
            if (keyboard[GLFW_KEY_W])
                camera->translate(glm::vec3(0.0f, 0.02f, 0.0f));
            if (keyboard[GLFW_KEY_S])
                camera->translate(glm::vec3(0.0f, -0.02f, 0.0f));
            if (keyboard[GLFW_KEY_Q])
                camera->translate(glm::vec3(0.0f, 0.0f, 0.1f));
            if (keyboard[GLFW_KEY_E])
                camera->translate(glm::vec3(0.0f, 0.0f, -0.1f));
        }
        // input
        processInput(window);
        glfwSetKeyCallback(window, key_callback);
        camera->update(*shader);

        // render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
              
        // render container
        glBindVertexArray(VAO);
        scene->draw(shader);
        /*
        glm::mat4 model = glm::mat4(1.0f);
        shader->setMat4("model", model);
        shader->setVec3("col", glm::vec3(1.0f, 0.0f, 1.0f));
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        */
        // swap the buffers and poll events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
  
    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

MyEngine::~MyEngine()
{
    delete shader;
    delete camera;
    delete vertices;
    delete indices;
}


// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void MyEngine::processInput(GLFWwindow *window)
{

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void MyEngine::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

void MyEngine::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS)
        keyboard[key] = true;
    else if (action == GLFW_RELEASE)
        keyboard[key] = false;  
       
}