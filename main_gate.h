#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "cube.h"
#include "texture.h"
#include "stb_image.h"



void main_gate(Cube& cube, Shader& lightingShader, glm::mat4 als)
{


    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;


    translateMatrix = glm::translate(identityMatrix, glm::vec3(20.0, 0.0, 96.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(5.0f, 6.0f, 0.05f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

   // translateMatrix = glm::translate(identityMatrix, glm::vec3(30.0, 0.0, 96.0));
   // scaleMatrix = glm::scale(identityMatrix, glm::vec3(-5.0f, 6.0f, 0.05f));
   // model = als * translateMatrix * scaleMatrix;
   // cube.drawCubeWithTexture(lightingShader, model);

   

  


}


#pragma once

#pragma once
