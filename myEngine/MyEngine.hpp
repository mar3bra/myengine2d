#ifndef MYENGINE_HPP
#define MYENGINE_HPP

#include "../glad.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/geometric.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/normal.hpp>
#include<chrono> 
#include<string>
#include<iostream>

#include<string>
#include "Camera.hpp"
#include "Shader.hpp"
#include "Scene.hpp"


#define STB_IMAGE_IMPLEMENTATION
#include "../stb_image.h"

bool keyboard[255]; 
class MyEngine
{
private:

       
    Shader* shader;
    Camera* camera;
    Scene* scene;


    float* vertices;
    uint* indices;
    unsigned int VBO, VAO, EBO;
    unsigned int texture;

    
    /***PARAMETERS***/
    uint SCR_WIDTH;
    uint SCR_HEIGHT;
    int vsync;
    /****************/
    

    /******GLFW******/
    GLFWwindow* window;
    //CALLS
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    static void processInput(GLFWwindow *window);
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    /****************/

public:
    MyEngine(uint scrWidth, uint scrHeight, int vsync);
    ~MyEngine();
    
    void setScene(Scene *s);
    //Init
    int init();

    int startMainLoop();

};


#endif