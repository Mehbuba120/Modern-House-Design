#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "texture.h"
#include "cube.h"

void bed( Cube& frame, Cube& body, Cube& foam, Cube blank, Shader& lightingShader, glm::mat4 als)
{
    

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(6.5, 1.0f, 4.5f));
    model = als * translateMatrix * scaleMatrix;
    body.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 1.0, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.3, 2.0f, 4.5f));
    model = als * translateMatrix * scaleMatrix;
    frame.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.3, 1.0, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(6.2, 0.8f, 4.5f));
    model = als * translateMatrix * scaleMatrix;
    foam.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.4, 1.8, 0.3));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.2, 0.25f,1.7f));
    model = als * translateMatrix * scaleMatrix;
    foam.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.4, 1.8, 2.3));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.2, 0.25f, 1.7f));
    model = als * translateMatrix * scaleMatrix;
    foam.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0, 1.8, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.5, 0.1f, 4.5f));
    model = als * translateMatrix * scaleMatrix;
    blank.drawCubeWithTexture(lightingShader, model);

    //table
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.2, 0.0, 0.0-1.7));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0, 1.8f, 1.5f));
    model = als * translateMatrix * scaleMatrix;
    blank.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.2, 0.3, 0.0 - 1.6));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1, 0.6f, 1.3f));
    model = als * translateMatrix * scaleMatrix;
    frame.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.2, 1.1, 0.0 - 1.6));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1, 0.6f, 1.3f));
    model = als * translateMatrix * scaleMatrix;
   frame.drawCubeWithTexture(lightingShader, model);


}

void almira(Cube& frame, Cube& glass, Shader& lightingShader, glm::mat4 als)
{


    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.0, 6.0f, 1.5f));
    model = als * translateMatrix * scaleMatrix;
    frame.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 1.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.0, 6.0f, 0.1f));
    model = als * translateMatrix * scaleMatrix;
    glass.drawCubeWithTexture(lightingShader, model);

}

void dressing(Cube& frame, Cube& glass, Cube& blank,Cube&mirror, Shader& lightingShader, glm::mat4 als)
{


    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.2, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2, 5.8f, 2.0f));
    model = als * translateMatrix * scaleMatrix;
    glass.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0-0.05, 0.3, 0.1));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1, 5.6f, 1.8f));
    model = als * translateMatrix * scaleMatrix;
    //mirror.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0-1.0, 0.0, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0, 0.2f, 3.5f));
    model = als * translateMatrix * scaleMatrix;
    frame.drawCubeWithTexture(lightingShader, model);


    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 2.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2, 6.0f, 1.0f));
    model = als * translateMatrix * scaleMatrix;
    blank.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0 - 0.8, 3.0, 2.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.8, 3.0f, 0.1f));
    model = als * translateMatrix * scaleMatrix;
    frame.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0 - 0.8, 3.0, 3.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.8, 3.0f, 0.1f));
    model = als * translateMatrix * scaleMatrix;
    frame.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0 - 0.8, 5.9, 2.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.8, 0.1f, 1.0f));
    model = als * translateMatrix * scaleMatrix;
    frame.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0 - 0.8, 4.5, 2.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.8, 0.1f, 1.0f));
    model = als * translateMatrix * scaleMatrix;
    frame.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0 - 1.0, 0.0, 2.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0, 3.0f, 1.3f));
    model = als * translateMatrix * scaleMatrix;
    frame.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0 - 1.1, 0.3, 2.1));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1,0.8f, 1.0f));
    model = als * translateMatrix * scaleMatrix;
    blank.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0 - 1.1, 1.5, 2.1));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1, 0.8f, 1.0f));
    model = als * translateMatrix * scaleMatrix;
    blank.drawCubeWithTexture(lightingShader, model);
}

void tvtable(Cube& frame, Cube& blank, Shader& lightingShader, glm::mat4 als)
{

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.9, 0.0, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1, 3.0f, 4.25f));
    model = als * translateMatrix * scaleMatrix;
    blank.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.9, 3.0f, 0.2f));
    model = als * translateMatrix * scaleMatrix;
    blank.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0+4.24));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.9, 3.0f, 0.1f));
    model = als * translateMatrix * scaleMatrix;
    blank.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.9, 0.2f, 4.25f));
    model = als * translateMatrix * scaleMatrix;
    blank.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 2.8, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.9, 0.2f, 4.25f));
    model = als * translateMatrix * scaleMatrix;
    blank.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 1.4, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.9, 0.1f, 4.25f));
    model = als * translateMatrix * scaleMatrix;
    blank.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0 + 3.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.9, 3.0f, 0.1f));
    model = als * translateMatrix * scaleMatrix;
    blank.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0-0.1, 0.1, 0.0 + 3.1));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2, 1.3f, 1.23f));
    model = als * translateMatrix * scaleMatrix;
    frame.drawCubeWithTexture(lightingShader, model);

    //tv

}

void sidetable(Cube& frame, Cylinder&cyl, Shader& lightingShader, glm::mat4 als)
{

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 2.6, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.5, 0.15f, 5.2f));
    model = als * translateMatrix * scaleMatrix;
    frame.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.00, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.5, 0.15f, 5.2f));
    model = als * translateMatrix * scaleMatrix;
    frame.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 1.6, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.5, 0.15f, 5.2f));
    model = als * translateMatrix * scaleMatrix;
    frame.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1, 2.6f, 5.0f));
    model = als * translateMatrix * scaleMatrix;
    frame.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.5, 2.6f, 0.2f));
    model = als * translateMatrix * scaleMatrix;
    frame.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0+5.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.5, 2.6f, 0.2f));
    model = als * translateMatrix * scaleMatrix;
    frame.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0 + 2.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.5, 2.6f, 0.2f));
    model = als * translateMatrix * scaleMatrix;
    frame.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.0, 0.25, 0.0 + 0.25));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.6, 1.45f, 2.3f));
    model = als * translateMatrix * scaleMatrix;
    frame.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.6, 0.9, 0.0 + 2.25));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.05, 0.4f, 0.05f));
    model = als * translateMatrix * scaleMatrix;
    cyl.drawCylinderWithTexture(lightingShader, model);

}

#pragma once

#pragma once
