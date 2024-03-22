#include "myEngine/MyEngine.cpp"
#include "myEngine/Scene.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "myEngine/Entity.hpp"

// settings
const unsigned int SCR_WIDTH = 1000;
const unsigned int SCR_HEIGHT = 600;

/*
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
*/

int main()
{
    Player player;
    Enemy enemy;

    
    Scene scene;

    scene.addEntity(&enemy);
    scene.addEntity(&player);

    MyEngine me(SCR_WIDTH, SCR_HEIGHT, 0);
    me.setScene(&scene);
    me.init();
    me.startMainLoop();
}


void myupdate(){
    
}