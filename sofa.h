#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "texture.h"
#include "cube.h"

void sofa( Cube& frame,Cube& seat, Shader& lightingShader, glm::mat4 als)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    float x = 0.0;
    float y = 0.0;
    float z = 0.0;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0+x, 0.0+y, 0.0+z));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(8.0f, 3.5f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    frame.drawCubeWithTexture(lightingShader, model); 
    
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0+0.3+x, 0.3+y, 0.0+0.4+z));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(8.0-0.6f, 1.35f, 3.3f));
    model = als * translateMatrix * scaleMatrix;
    frame.drawCubeWithTexture(lightingShader, model);

    //handle
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0+x, 0.0+y, 0.0+0.4+z));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.4f, 2.45f, 3.3f));
    model = als * translateMatrix * scaleMatrix;
    frame.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0-0.1+x, 0.3+y, 0.0 + 0.4+z));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.6f, 2.1f, 3.4f));
    model = als * translateMatrix * scaleMatrix;
    seat.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0+7.5+x, 0.0+y, 0.0+0.5+z));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.4f, 2.45f, 3.3f));
    model = als * translateMatrix * scaleMatrix;
    frame.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0 + 7.5-0.1+x, 0.3+y, 0.0 + 0.5+z));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.6f, 2.1f, 3.4f));
    model = als * translateMatrix * scaleMatrix;
    seat.drawCubeWithTexture(lightingShader, model);

    //foam
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0 + x, 1.7 + y, 0.0 +0.4+ z));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(8.0f, 2.0f, 0.5f));
    model = als * translateMatrix * scaleMatrix;
    seat.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0 +x, 0.7+y, 0.0 + 0.4+z));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(8.0, 1.0f, 3.4f));
    model = als * translateMatrix * scaleMatrix;
    seat.drawCubeWithTexture(lightingShader, model);

    //this model is later sent to the vertex shader. //altogether is a matrix that is multiplied with every parts of the bed, so everything is part of Altogether. when rotated, everything is rotated AllTogether
}

void sofa2(Cube& cusion, Cube& seat,Cube&matt, Shader& lightingShader, glm::mat4 als) {
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0+1.0, 0.0, 5.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.5, 1.0f, 3.0f));
    model = als * translateMatrix * scaleMatrix;
    seat.drawCubeWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0 + 1.1, 1.0, 5.1));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.3, 0.5f, 2.8f));
    model = als * translateMatrix * scaleMatrix;
    seat.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(9.0, 1.0f, 3.4f));
    model = als * translateMatrix * scaleMatrix;
    seat.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(9.0-3.4, 0.0, 3.4));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.4, 1.0f, 3.5f));
    model = als * translateMatrix * scaleMatrix;
    seat.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.1, 1.1, 0.1));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(8.8, 0.5f, 3.4f));
    model = als * translateMatrix * scaleMatrix;
    seat.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(9.0 - 3.4, 1.1, 3.4));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.3, 0.5f, 3.5f));
    model = als * translateMatrix * scaleMatrix;
    seat.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0-0.5, 0.0, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.5, 2.5f, 3.4f));
    model = als * translateMatrix * scaleMatrix;
    seat.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(9.0, 0.0, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.5, 3.5f, 3.5+3.4f));
    model = als * translateMatrix * scaleMatrix;
    seat.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(9.0-3.4, 0.0, 0.0+3.4+3.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.9, 2.5f, 0.5));
    model = als * translateMatrix * scaleMatrix;
    //seat.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0-0.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(9.5, 3.5f, 0.5));
    model = als * translateMatrix * scaleMatrix;
    seat.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(2.0, 1.5, 0.0+0.1));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.5, 1.5f, 0.3));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(45.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    model = als * translateMatrix * rotateYMatrix* scaleMatrix;
    cusion.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(4.5, 1.5, 0.0 + 0.1));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.5, 1.5f, 0.3));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(45.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    cusion.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(7.0, 1.5, 0.0 + 0.1));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.5, 1.5f, 0.3));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(45.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    cusion.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(9.0-0.4, 1.5, 0.0 + 3.0+0.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.3, 1.5f, 1.5));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(45.0f), glm::vec3(-1.0f, 0.0f, 0.0f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    cusion.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(9.0 - 0.4, 1.5, 0.0 + 3.4 + 2.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.3, 1.5f, 1.5));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(45.0f), glm::vec3(-1.0f, 0.0f, 0.0f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    cusion.drawCubeWithTexture(lightingShader, model);

    
}

void sofa3(Cube& cusion, Cube& seat, Shader& lightingShader, glm::mat4 als) {

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(6.0, 1.0f, 3.4f));
    model = als * translateMatrix * scaleMatrix;
    seat.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.1, 1.1, 0.1));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(5.8, 0.5f, 3.4f));
    model = als * translateMatrix * scaleMatrix;
    seat.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0 - 0.5, 0.0, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.5, 2.5f, 3.4f));
    model = als * translateMatrix * scaleMatrix;
    seat.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(6.0, 0.0, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.5, 2.5f, 3.4f));
    model = als * translateMatrix * scaleMatrix;
    seat.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0 - 0.5, 0.0, 0.0 - 0.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(7.0, 3.5f, 0.5));
    model = als * translateMatrix * scaleMatrix;
    seat.drawCubeWithTexture(lightingShader, model);
}

void sofa4(Cube& wood, Cube& seat,Cube& matt, Shader& lightingShader, glm::mat4 als) {

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(31.0, 2.2+0.5, 24.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.5, 0.2f, 8.0f));
    model = als * translateMatrix * scaleMatrix;
    wood.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(31.0, 2.2 + 0.7, 24.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.5, 0.8f, 8.0f));
    model = als * translateMatrix * scaleMatrix;
    seat.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(31.0, 2.2 , 24.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.5, 0.7f, 0.2f));
    model = als * translateMatrix * scaleMatrix;
    wood.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(31.0, 2.2, 24.0+7.8));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.5, 0.7f, 0.2f));
    model = als * translateMatrix * scaleMatrix;
    wood.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(31.0, 2.2 + 0.7, 24.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.5, 1.7f, 0.5f));
    model = als * translateMatrix * scaleMatrix;
    seat.drawCubeWithTexture(lightingShader, model);
   
    translateMatrix = glm::translate(identityMatrix, glm::vec3(31.0, 2.2 + 0.7, 24.0+7.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.5, 1.7f, 0.5f));
    model = als * translateMatrix * scaleMatrix;
    seat.drawCubeWithTexture(lightingShader, model);

    //matt
    translateMatrix = glm::translate(identityMatrix, glm::vec3(33.0, 2.2, 23.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(7.0, 0.1f, 9.0));
   
    model = als * translateMatrix * scaleMatrix;
    matt.drawCubeWithTexture(lightingShader, model);
}


void sofa5(Cube& wood, Cube& seat, Cube& matt, Shader& lightingShader, glm::mat4 als) {

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 2.2 + 0.5, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.5, 0.2f, 8.0f));
    model = als * translateMatrix * scaleMatrix;
    wood.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 2.2 + 0.7, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.5, 0.8f, 8.0f));
    model = als * translateMatrix * scaleMatrix;
    seat.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 2.2, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.5, 0.7f, 0.2f));
    model = als * translateMatrix * scaleMatrix;
    wood.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 2.2, 0.0 + 7.8));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.5, 0.7f, 0.2f));
    model = als * translateMatrix * scaleMatrix;
    wood.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 2.2 + 0.7, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.5, 1.7f, 0.5f));
    model = als * translateMatrix * scaleMatrix;
    seat.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 2.2 + 0.7, 0.0 + 7.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.5, 1.7f, 0.5f));
    model = als * translateMatrix * scaleMatrix;
    seat.drawCubeWithTexture(lightingShader, model);

    //matt
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 2.2, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(7.0, 0.1f, 9.0));

    model = als * translateMatrix * scaleMatrix;
    matt.drawCubeWithTexture(lightingShader, model);
}
#pragma once

#pragma once
