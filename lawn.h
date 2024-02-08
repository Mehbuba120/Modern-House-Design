#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "cube.h"
#include "texture.h"
#include "stb_image.h"



void lawn(Cube& cube, Cube& boundary, Cube& m_road, Shader& lightingShader, glm::mat4 als)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(50.0f, 0.2f, 96.0f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.8f, 6.0f, 96.0f));
    model = als * translateMatrix * scaleMatrix;
    boundary.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(50.0, 0.0, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.8f, 6.0f, 96.0f));
    model = als * translateMatrix * scaleMatrix;
    boundary.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(50.0f, 6.0f, 0.8f));
    model = als * translateMatrix * scaleMatrix;
    boundary.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 96.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(20.0f, 6.0f, 0.8f));
    model = als * translateMatrix * scaleMatrix;
    boundary.drawCubeWithTexture(lightingShader, model);
    
    translateMatrix = glm::translate(identityMatrix, glm::vec3(30.0, 0.0, 96.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(20.8f, 6.0f, 0.8f));
    model = als * translateMatrix * scaleMatrix;
    boundary.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(-10.0, 0.0, 96.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(70.0f, 0.1f, 6.0f));
    model = als * translateMatrix * scaleMatrix;
    m_road.drawCubeWithTexture(lightingShader, model);

    /*
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-10.0, -0.1, -10.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(70.0f, 0.1f, 126.0f));
    model = als * translateMatrix * scaleMatrix;
    boundary.drawCubeWithTexture(lightingShader, model);
    */
;
}


#pragma once

