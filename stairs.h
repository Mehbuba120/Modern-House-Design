#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "texture.h"
#include "staircube.h"
#include "cylinder.h"

void stair(Shader& lightingShader, glm::mat4 alTogether, Cube&cube , Staircube& cube1)
{

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    
    //midpoints of stairs; left side staircases
    float j = 0.0;
    float k = 0.0;
    for (int i = 0; i < 10; i++) {
        translateMatrix = glm::translate(identityMatrix, glm::vec3(24.9+k, 2.2 + j, 34.5 ));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.5, 0.5, 4.0));
        model = alTogether * translateMatrix * scaleMatrix;
        cube1.drawStaircubeWithTexture(lightingShader, model);

       
        j += .5;
        k += .5;
    }

    float m = 0.0;
    float n = 0.0;

    for (int i = 0; i < 10; i++) {
        translateMatrix = glm::translate(identityMatrix, glm::vec3(24.9 + n, 2.2 + m, 38.5));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.5, 2.0, 0.1));
        model = alTogether * translateMatrix * scaleMatrix;
        cube.drawCubeWithTexture(lightingShader, model);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(24.9 + n, 4.2 + m, 38.35));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.5, 0.07, 0.3));
        model = alTogether * translateMatrix * scaleMatrix;
        cube.drawCubeWithTexture(lightingShader, model);

        m += .5;
        n += .5;
    }
    

}

void stair2(Shader& lightingShader, glm::mat4 alTogether, Cube&cube, Staircube& cube1)
{

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    float j = 0.0;
    float k = 0.0;
    float rotateAngle_Y = 180.0f;
    for (int i = 0; i < 10; i++) {
        translateMatrix = glm::translate(identityMatrix, glm::vec3(k,  j, 0.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.5, 0.5, 4.0));
        // rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 0.0f, 1.0f));
        model = alTogether * translateMatrix * scaleMatrix;
        cube1.drawStaircubeWithTexture(lightingShader, model);



        j += .5;
        k += .5;
    }

    float m = 0.0;
    float n = 0.0;
   // float rotateAngle_Y = 180.0f;
    for (int i = 0; i < 10; i++) {
        translateMatrix = glm::translate(identityMatrix, glm::vec3(n, m, 0.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.5, 2.0, 0.1));
        // rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 0.0f, 1.0f));
        model = alTogether * translateMatrix * scaleMatrix;
        cube1.drawStaircubeWithTexture(lightingShader, model);



        m += .5;
        n += .5;
    }

}


#pragma once

#pragma once
