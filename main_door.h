#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "cube.h"
#include "texture.h"
#include "stb_image.h"



void main_door(Cube& gate,Shader& lightingShader, glm::mat4 als)
{


    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;


    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 14.0+3.0, 2.2, 66.0 - 5.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.0f, 7.0f, 0.3f));
    model = als * translateMatrix * scaleMatrix;
    gate.drawCubeWithTexture(lightingShader, model);


}


void windows(Cube& glass, Shader& lightingShader, glm::mat4 als)
{

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;
    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 14.0 +10.0+4.0, 2.7, 66.0 - 5.05));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.0f, 6.5f, 0.2f));
    model = als * translateMatrix * scaleMatrix;
    glass.drawCubeWithTexture(lightingShader, model);


}

void window_slide(Cube& glass, Shader& lightingShader, glm::mat4 als)
{

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 14.0 + 10.0 + 8.0, 2.7, 66.0 - 4.95));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.0f, 6.5f, 0.2f));
    model = als * translateMatrix * scaleMatrix;
    glass.drawCubeWithTexture(lightingShader, model);

}

void r_window(Cube& glass, Shader& lightingShader, glm::mat4 als)
{

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 3.0, 2.2+2.5, 66.0 - 0.4));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.0f, 5.0f, 0.2f));
    model = als * translateMatrix * scaleMatrix;
    glass.drawCubeWithTexture(lightingShader, model);

}

void rs_window(Cube& glass, Shader& lightingShader, glm::mat4 als)
{

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 3.0+4.0, 2.2 + 2.5, 66.0 - 0.4));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.0f, 5.0f, 0.2f));
    model = als * translateMatrix * scaleMatrix;
    glass.drawCubeWithTexture(lightingShader, model);

}

void doors5(Cube& glass, Shader& lightingShader, glm::mat4 als)
{

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 13.0, 12.7, 15.0 + 18.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.15f, 8.0f, 5.0f));
    model = als * translateMatrix * scaleMatrix;
    glass.drawCubeWithTexture(lightingShader, model);

}
void doors1(Cube& glass, Shader& lightingShader, glm::mat4 als)
{

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 10.3, 2.2, 47.0+6.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.67f, 7.0f, 0.15f));
    model = als * translateMatrix * scaleMatrix;
    glass.drawCubeWithTexture(lightingShader, model);

}
void doors2(Cube& glass, Shader& lightingShader, glm::mat4 als)
{

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 10.0 , 2.2, 47.0-4.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.15f, 8.0f, 4.5f));
    model = als * translateMatrix * scaleMatrix;
    glass.drawCubeWithTexture(lightingShader, model);

}
void doors3(Cube& glass, Shader& lightingShader, glm::mat4 als)
{

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 13.0, 12.7, 66.0 - 18.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.15f, 8.0f, 5.0f));
    model = als * translateMatrix * scaleMatrix;
    glass.drawCubeWithTexture(lightingShader, model);

}
void doors4(Cube& glass, Shader& lightingShader, glm::mat4 als)
{

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0 - 14.0, 12.7, 66.0 - 13.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.0f, 7.0f, 0.15f));
    model = als * translateMatrix * scaleMatrix;
    glass.drawCubeWithTexture(lightingShader, model);

}

void doors6(Cube& glass, Shader& lightingShader, glm::mat4 als)
{

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0-8.6, 12.7 , 66.0 - 13.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.6f, 7.0f, 0.15f));
    model = als * translateMatrix * scaleMatrix;
    glass.drawCubeWithTexture(lightingShader, model);

}

void washroom(Cube& cube,Cube& cube2,  Cylinder&cyl, Cube& cube3, Shader& lightingShader, glm::mat4 als)
{

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 , 2.2, 47.0 - 4.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(5.4f, 3.0f, 2.5f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0+3.0, 2.2+3.0, 47.0 - 4.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2f, 1.5f, 0.1f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 3.0, 2.2 + 3.0+1.5, 47.0 - 4.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2f, 0.1f, 0.7f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 3.0, 2.2 + 3.0 + 1.2, 47.0 - 3.4));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2f, 0.3f, 0.1f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 3.0, 2.2+0.75, 52));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.5f, 0.75f, 0.5f));
    model = als * translateMatrix * scaleMatrix;
    cyl.drawCylinderWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 2.2, 2.2 +0.4+ 1.2, 52.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.8f, 1.2f, 0.5f));
    model = als * translateMatrix * scaleMatrix;
    //cube3.drawCubeWithTexture(lightingShader, model);



    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0+0.3, 2.2, 47.0 - 4.4));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.4f, 10.0f, 10.0f));
    model = als * translateMatrix * scaleMatrix;
    cube2.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0, 2.2, 47.0 - 4.4));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(10.0f, 10.0f, 0.1f));
    model = als * translateMatrix * scaleMatrix;
    cube2.drawCubeWithTexture(lightingShader, model);


    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.4, 2.2, 52.8 ));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(10.0f, 10.0f, 0.1f));
    model = als * translateMatrix * scaleMatrix;
    cube2.drawCubeWithTexture(lightingShader, model);

}
void tapwater(Cube& cube, Shader& lightingShader, glm::mat4 als)
{

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0,0.0,0.0));
    //scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, 0.05f, 0.1f));
   // rotateYMatrix = glm::rotate(identityMatrix, glm::radians(180.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    model = als * translateMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

}

#pragma once

