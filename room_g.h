#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "cube.h"
#include "texture.h"
#include "stb_image.h"



void rg(Cube& cube, Cube& cube2,Cube&tab, Shader& lightingShader, glm::mat4 als)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.5+2.0, 12.7, 15.0+22.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2f, 7.0f, 2.0f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
   cube2.drawCubeWithTexture(lightingShader, model);

   translateMatrix = glm::translate(identityMatrix, glm::vec3(5.5 + 2.0, 12.7+6.9, 15.0 + 22.5));
   scaleMatrix = glm::scale(identityMatrix, glm::vec3(6.1f, 0.1f, 2.0f));
   rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f), glm::vec3(1.0f, 0.0f, 0.0f));
   model = als * translateMatrix * rotateYMatrix * scaleMatrix;
   cube2.drawCubeWithTexture(lightingShader, model);

   translateMatrix = glm::translate(identityMatrix, glm::vec3(5.5 + 2.0, 12.7, 15.0 + 22.5));
   scaleMatrix = glm::scale(identityMatrix, glm::vec3(6.1f, 0.2f, 2.0f));
   rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f), glm::vec3(1.0f, 0.0f, 0.0f));
   model = als * translateMatrix * rotateYMatrix * scaleMatrix;
   cube2.drawCubeWithTexture(lightingShader, model);

   translateMatrix = glm::translate(identityMatrix, glm::vec3(5.5 + 2.0+6.0, 12.7, 15.0 + 22.5));
   scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2f, 7.0f, 2.0f));
   rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f), glm::vec3(1.0f, 0.0f, 0.0f));
   model = als * translateMatrix * rotateYMatrix * scaleMatrix;
   cube2.drawCubeWithTexture(lightingShader, model);

   translateMatrix = glm::translate(identityMatrix, glm::vec3(5.5 + 2.0, 12.7, 15.0 + 24.5));
   scaleMatrix = glm::scale(identityMatrix, glm::vec3(6.0f, 7.0f, 0.2f));
   rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f), glm::vec3(1.0f, 0.0f, 0.0f));
   model = als * translateMatrix * rotateYMatrix * scaleMatrix;
   cube2.drawCubeWithTexture(lightingShader, model);

   translateMatrix = glm::translate(identityMatrix, glm::vec3(5.5 + 2.2, 12.9, 15.0 + 22.5));
   scaleMatrix = glm::scale(identityMatrix, glm::vec3(5.8f, 6.7f, 0.1f));
   rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f), glm::vec3(1.0f, 0.0f, 0.0f));
   model = als * translateMatrix * rotateYMatrix * scaleMatrix;
   cube.drawCubeWithTexture(lightingShader, model);


}

void rgg(Cube& cube, Cube& cube2, Cube&toy1, Cube&toy2, Shader& lightingShader, glm::mat4 als)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0,0.0, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, 3.0f, 3.0f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    //toys
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-12.5+0.6, 1.7, 6.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.05f, 0.8f, 5.0f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    toy1.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(-12.5 + 0.6, 2.7, 6.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.05f, 0.8f, 5.0f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    toy1.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(-12.5, 2.6, 6.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.8f, 0.1f, 5.0f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    cube2.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(-12.5, 1.6, 6.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.8f, 0.1f, 5.0f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    cube2.drawCubeWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-12.5, 3.5, 6.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.8f, 0.1f, 5.0f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    cube2.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(-12.5, 1.6, 6.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.8f, 2.0f, 0.1f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    cube2.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(-12.5, 1.6, 11.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.8f, 2.0f, 0.1f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    cube2.drawCubeWithTexture(lightingShader, model);

   

}


void g_tab(Cube& tab, Cube& cube2,Cube&cus, Cube&foam, Shader& lightingShader, glm::mat4 als)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;


    //table
    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.5, 12.7, 16.2));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.8f, 3.0f, 0.1f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    tab.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.5, 12.7, 16.0 + 4.6));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.8f, 3.0f, 0.1f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    tab.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.5, 12.7 + 3.0, 16.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.0f, 0.2f, 5.0f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    tab.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.5, 12.7 + 3.0, 16.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, 2.5f, 0.1f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    tab.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.5, 12.7 + 3.0, 16.0 + 4.9));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, 2.5f, 0.1f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    tab.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.5, 12.7 + 5.5, 16.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, 0.2f, 5.0f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    tab.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.5, 12.7 + 4.25, 16.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, 0.2f, 5.0f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    tab.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.5, 12.7 + 3.0, 16.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, 2.5f, 5.0f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    tab.drawCubeWithTexture(lightingShader, model);

    //chair
    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.5 - 3.0 + 5, 12.7 + 2.0, 17.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.0f, 0.3f, 1.8f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    tab.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.5 - 3.0 + 5.2, 12.7, 17.7));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2f, 2.0f, 0.2f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    tab.drawCubeWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.5 - 3.0 + 5.2, 12.7, 17.7 + 1.2));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2f, 2.0f, 0.2f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    tab.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.5 - 3.0 + 5.2 + 1.4, 12.7, 17.7));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2f, 4.5f, 0.2f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    tab.drawCubeWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.5 - 3.0 + 5.2 + 1.4, 12.7, 17.7 + 1.2));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2f, 4.5f, 0.2f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    tab.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.5 - 3.0 + 5.2 + 1.4, 12.7 + 4.5, 17.7));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2f, 0.1f, 1.6f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    tab.drawCubeWithTexture(lightingShader, model);

    //wind
    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 5.0, 12.7, 13.6));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(7.0f, 1.5f, 2.5f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    cube2.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 5.0, 12.7+1.5, 13.6));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(7.0f, 0.8f, 2.5f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    foam.drawCubeWithTexture(lightingShader, model);



}


#pragma once
