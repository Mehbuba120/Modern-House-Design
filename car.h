#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "cube.h"
#include "texture.h"
#include "stb_image.h"



void car(Cube& cube,Cube&wind, Cylinder & wheel2, Shader& lightingShader, glm::mat4 als)
{


    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;


    translateMatrix = glm::translate(identityMatrix, glm::vec3(20.0-15.0, 1.5, 75.0+10.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(8.0f, 2.0f, 4.0f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(21.0-15.0, 3.5, 75.0+10.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(5.0f, 1.5f, 4.0f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(23.0 - 15.0, 3.5+0.3, 75.0 + 9.95));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.7f, 0.9f, 0.05f));
    model = als * translateMatrix * scaleMatrix;
    wind.drawCubeWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(23.0 - 15.0, 3.5 + 0.3, 75.0 + 10.0+4.05));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.7f, 0.9f, 0.05f));
    model = als * translateMatrix * scaleMatrix;
    wind.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(21.0 - 10.0, 3.5 + 0.1, 75.0 + 10.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.05f, 1.2f, 3.0f));
    model = als * translateMatrix * scaleMatrix;
    wind.drawCubeWithTexture(lightingShader, model);


   

}

void carw1(Cube& cube, Sphere2& wheel, Cylinder& wheel2, Shader& lightingShader, glm::mat4 als)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(21.5 + 5.0 - 15.0, 1.0, 75.0 + 4.0 + 10.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.7f, 0.3f, 0.7f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    wheel2.drawCylinderWithTexture(lightingShader, model);

}
void carw2(Cube& cube, Sphere2& wheel, Cylinder& wheel2, Shader& lightingShader, glm::mat4 als)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(21.5 + 5.0 - 15.0, 1.0, 75.0 + 10.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.7f, 0.3f, 0.7f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    wheel2.drawCylinderWithTexture(lightingShader, model);

}

void carw3(Cube& cube, Sphere2& wheel, Cylinder& wheel2, Shader& lightingShader, glm::mat4 als)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(21.5 - 15.0, 1.0, 75.0 + 4.0 + 10.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.7f, 0.3f, 0.7f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    wheel2.drawCylinderWithTexture(lightingShader, model);


}
void carw4(Cube& cube, Sphere2& wheel, Cylinder& wheel2, Shader& lightingShader, glm::mat4 als)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(21.5 - 15.0, 1.0, 75.0 + 10.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.7f, 0.3f, 0.7f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    wheel2.drawCylinderWithTexture(lightingShader, model);


}

void washingmachine(Cube& cube,Cube&cube2, Shader& lightingShader, glm::mat4 als)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0- 15.5, 2.2,66.0-19.0-3.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.5f, 3.8f, 3.0f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);


    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0 - 15.6, 2.2, 66.0 - 19.0 - 3.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2f, 3.85f, 3.0f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    cube2.drawCubeWithTexture(lightingShader, model);


}


#pragma once
