#include"Camera.hpp"
#include<iostream>
using namespace std;

Camera::Camera(uint WIDTH, uint HEIGHT) : _position(glm::vec3(0.0, 0.0, 1.0)), _up(glm::vec3(0.0, 1.0, 0.0)), _rotation(0.0f){
    

    _projection = //glm::ortho(-1.0f, 1.0f, -relation, relation, 0.1f, 100.0f); 
    glm::perspective(glm::radians(45.0f),float(WIDTH)/float(HEIGHT), 0.1f, 100.0f);
    _view = glm::mat4(1.0f);
    _view = glm::lookAt(glm::vec3(_position), 
  	       glm::vec3(_position) - glm::vec3(0.0f, 0.0f, 1.0f), 
  	       _up);
     
    
}

Camera::~Camera()
{
}


void Camera::update(Shader &shader){
    updateView();
    shader.setMat4("view", _view);
    shader.setMat4("projection", _projection);
}


void Camera::rotate(float angle){
    _rotation += angle;
    _up = glm::vec3(glm::sin(glm::radians(_rotation)), glm::cos(glm::radians(_rotation)), 0.0f);
}

void Camera::translate(glm::vec3 v){
    _position += v;
}

void Camera::updateView(){
    _view = glm::lookAt(
        _position, 
  	    _position - glm::vec3(0.0f, 0.0f, 1.0f), 
  	    _up
    );
}