#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "cube.h"
#include "texture.h"
#include "stb_image.h"



void tree(Sphere2& sphere, Cylinder&cyl, Shader& lightingShader, glm::mat4 als)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    float i = 0.0;
    for (int j = 0.0; j < 2; j++) {
        translateMatrix = glm::translate(identityMatrix, glm::vec3(3.0 + i, 3.0, 5.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, 0.7f, 1.0f));
        model = als * translateMatrix * scaleMatrix;
        sphere.drawSphereWithTexture(lightingShader, model);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(3.1 + i, 3.4, 5.1));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.8f, 0.7f, 0.8f));
        model = als * translateMatrix * scaleMatrix;
        sphere.drawSphereWithTexture(lightingShader, model);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(3.0 + i, 1.5, 5.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2f, 1.5f, 0.2f));
        model = als * translateMatrix * scaleMatrix;
        cyl.drawCylinderWithTexture(lightingShader, model);
        i = i + 5;
    }




}

void tree2(Sphere2& sphere, Cylinder& cyl, Shader& lightingShader, glm::mat4 als)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    float i = 0.0;
    for (int j = 0.0; j < 4; j++) {
        translateMatrix = glm::translate(identityMatrix, glm::vec3(3.0+i, 3.0, 71.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, 0.7f, 1.0f));
        model = als * translateMatrix * scaleMatrix;
        sphere.drawSphereWithTexture(lightingShader, model);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(3.1 + i, 3.4, 71.1));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.8f, 0.7f, 0.8f));
        model = als * translateMatrix * scaleMatrix;
        sphere.drawSphereWithTexture(lightingShader, model);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(3.0+i, 1.5, 71.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2f, 1.5f, 0.2f));
        model = als * translateMatrix * scaleMatrix;
        cyl.drawCylinderWithTexture(lightingShader, model);
        i = i + 5;
    }


}

void garden(Cube& cube, Cube& cube2, Shader& lightingShader, glm::mat4 als)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(35.0, 1.2, 71.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2f, 1.5f, 0.2f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);
    
    }


#pragma once
