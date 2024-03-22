#ifndef CAMERA_HPP
#define CAMERA_HPP

#include<glm/glm.hpp>
#include<glm/geometric.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include"Shader.hpp"


class Camera
{
private:

glm::vec3 _position;
glm::vec3 _up;
float _rotation;
glm::mat4 _projection;
glm::mat4 _view;

void updateView();


public:
    Camera(uint WIDTH, uint HEIGHT);
    ~Camera();
    void update(Shader &shader);
    void rotate(float angle);
    void translate(glm::vec3 v);

};

#endif