#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "texture.h"
#include "cube.h"
#include "sphere.h"

void office(Cube& cube,Cube&glass, Shader& lightingShader, glm::mat4 als)
{


    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 2.2, 2.2 + 2.5, 30.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(5.5, 0.3f, 3.0f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 2.2, 2.2 + 2.85, 30.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(5.5, 0.1f, 3.0f));
    model = als * translateMatrix * scaleMatrix;
    glass.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 1.0, 2.2, 28.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.0, 2.15f, 5.0f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);


    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 2.2+5.3, 2.2, 30.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2, 2.5f, 3.0f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 2.2, 2.2+1.0, 30.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(5.5, 1.5f, 2.2f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

}
void offchair(Cube& cube, Cylinder& ch, Shader& lightingShader, glm::mat4 als)
{


    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.15, 1.5, 0.15));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.7, 0.5f, 2.05f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 2.0, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.0, 0.1f, 2.2f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.15, 0.0, 0.15));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2, 1.5f, 0.2f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.15 + 1.5, 0.0, 0.15));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2, 1.5f, 0.2f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.15 + 1.5, 0.0, 2.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2, 1.5f, 0.2f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.15, 0.0, 2.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2, 1.5f, 0.2f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    //up
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.3, 2.9, 2.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.08, 0.9f, 0.08f));
    model = als * translateMatrix * scaleMatrix;
    ch.drawCylinderWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.15 + 1.55, 2.9, 2.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.08, 0.9f, 0.08f));
    model = als * translateMatrix * scaleMatrix;
    ch.drawCylinderWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.15 + 0.6, 2.9, 2.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.05, 0.9f, 0.05f));
    model = als * translateMatrix * scaleMatrix;
    ch.drawCylinderWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.15 + 1.03, 2.9, 2.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.05, 0.9f, 0.05f));
    model = als * translateMatrix * scaleMatrix;
    ch.drawCylinderWithTexture(lightingShader, model);


    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.0, 3.85, 2.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0, 0.1f, 0.1f));
    model = als * translateMatrix * scaleMatrix;
    ch.drawCylinderWithTexture(lightingShader, model);

}

#pragma once
