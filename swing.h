#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "cube.h"
#include "texture.h"
#include "cylinder.h"
#include "stb_image.h"



void swing(Cube& seat, Cylinder& cyl, Shader& lightingShader, glm::mat4 als)
{


    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;


    translateMatrix = glm::translate(identityMatrix, glm::vec3(40.0, 2.5, 5.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.0f, 0.2f, 3.0f));
    model = als * translateMatrix * scaleMatrix;
    seat.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(41.1, 2.5+3.0, 5.1));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.07f, 3.0f, 0.07f));
    model = als * translateMatrix * scaleMatrix;
    cyl.drawCylinderWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(41.1, 2.5 + 3.0, 5.1+2.8));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.07f, 3.0f, 0.07f));
    model = als * translateMatrix * scaleMatrix;
    cyl.drawCylinderWithTexture(lightingShader, model);

}


void frame(Cylinder& cyl, Shader& lightingShader, glm::mat4 als)
{


    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;


    translateMatrix = glm::translate(identityMatrix, glm::vec3(40.0+1.0, 4.0, 4.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.17f, 4.5f, 0.17f));
    model = als * translateMatrix * scaleMatrix;
    cyl.drawCylinderWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(40.0 + 1.0, 4.0, 4.0+5.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.17f, 4.5f, 0.17f));
    model = als * translateMatrix * scaleMatrix;
    cyl.drawCylinderWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(40.0 + 1.01, 8.3, 6.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2f, 2.5f, 0.2f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(1.0f,0.0f, 0.0f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    cyl.drawCylinderWithTexture(lightingShader, model);


}

void fan(Cube&cube, Cylinder& cyl, Shader& lightingShader, glm::mat4 als)
{


    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(25.0, 2.2+9.6, 25.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.15f, 0.4f, 0.15f));  
    model = als * translateMatrix *scaleMatrix;
    cyl.drawCylinderWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(25.0, 2.2 + 9.4, 25.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.6f, 0.2f, 0.6f));
    model = als * translateMatrix * scaleMatrix;
    cyl.drawCylinderWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(22.0, 2.2 + 9.4, 25.1));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(6.0f, 0.08f, 0.8f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(24.6, 2.2 + 9.4, 22.4));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.8f, 0.08f, 6.0f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);
}

#pragma once


