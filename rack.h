#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "texture.h"
#include "cube.h"
#include "staircube.h"

void rack(Cube&cube,Cube&files, Cube&books, Shader& lightingShader, glm::mat4 als)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.3, 6.5f, 5.5f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);
    //books

    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.7, 3.4+1.9, 0.3));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1, 1.4f, 1.5f));
    model = als * translateMatrix * scaleMatrix;
    books.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.7, 3.4, 2.2));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1, 1.4f, 1.5f));
    model = als * translateMatrix * scaleMatrix;
    books.drawCubeWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.7, 3.4, 0.2));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1, 1.4f, 1.5f));
    model = als * translateMatrix * scaleMatrix;
    books.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.7, 0.2, 2.2));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1, 1.5f, 1.5f));
    model = als * translateMatrix * scaleMatrix;
    files.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.7, 3.4+1.9, 2.2));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1, 1.5f, 1.5f));
    model = als * translateMatrix * scaleMatrix;
    files.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.7, 1.7, 0.3));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1, 1.5f, 1.5f));
    model = als * translateMatrix * scaleMatrix;
    files.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.7, 1.7, 2.2+1.8));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1, 1.5f, 1.5f));
    model = als * translateMatrix * scaleMatrix;
    files.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0+5.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.0, 6.5f, 0.3f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0 +1.83));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.0, 6.5f, 0.2f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0 + 1.83+1.83));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.0, 6.5f, 0.2f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.0, 6.5f, 0.3f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.0, 0.3f, 5.5f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 1.7, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.0, 0.2f, 5.5f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 3.4, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.0, 0.2f, 5.5f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 3.4+1.7, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.0, 0.2f, 5.8f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 6.5, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.0, 0.3f, 5.8f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 6.5, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.0, 0.3f, 5.8f));
    model = als * translateMatrix * scaleMatrix;
   // cube.drawCubeWithTexture(lightingShader, model);


}
void gym(Cube& cube, Cylinder& ch, Shader& lightingShader, glm::mat4 als)
{


    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0-13.15, 12.7, 22.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.15, 4.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0 - 10.5, 12.7, 22.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.15, 4.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0 - 13.1, 13.0, 22.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.7, 0.15f, 5.5f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0 - 13.1, 13.0, 22.0+5.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.7, 0.35f, 0.7f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0 - 13.1, 13.0, 22.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.7, 0.35f, 0.5f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0 - 13.0+1.25, 12.7+4.0, 22.1));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.45, 0.15f, 0.3f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    model = als * translateMatrix * scaleMatrix * rotateYMatrix;
    ch.drawCylinderWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0 - 13.0+0.833, 12.7 + 4.5, 22.0-0.4));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.83, 0.05f, 0.7f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(30.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    model = als * translateMatrix * rotateYMatrix* scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);


}
void treadmill(Cube& cube, Cylinder& ch, Shader& lightingShader, float trd)
{


    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    float z = 0.0;
    for (int i = 0; i <= 20; i++) {
        if (z + trd >= 26.2) {
            z = 0.0;
        }
        translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0 -13.0, 13.15, 22.0+z+trd));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.5, 0.15f, 0.2f));
        model = translateMatrix * scaleMatrix;
        cube.drawCubeWithTexture(lightingShader, model);
        z += 0.25;


    }
    
}

void fmat(Cube& cube, Shader& lightingShader, glm::mat4 als)
{


    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.5, 3.0f, 0.1f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);
}

void paintings(Cube& cube, Shader& lightingShader, glm::mat4 als)
{


    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1, 4.5f, 4.5f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);
}