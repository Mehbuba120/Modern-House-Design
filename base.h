#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "cube.h"
#include "cylinder.h"
#include "texture.h"
#include "stb_image.h"



void base(Cube& cube,Cube&road,Cube&proad, Cube&roof, Cylinder&pillar,Cube& deck, Shader& lightingShader, glm::mat4 als)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;


    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0, 0.2, 15.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(40.0f, 2.0f, 51.0f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(19.0, 0.2, 66.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(10.0f, 0.67f, 3.0f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(19.0, 0.2+0.67, 66.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(10.0f, 0.67f, 1.5f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(20.0, 0.2, 66.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(8.0f, 0.05f,30.0f));
    model = als * translateMatrix * scaleMatrix;
    road.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.2, 66.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(20.0f, 0.05f, 5.0f));
    model = als * translateMatrix * scaleMatrix;
    road.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.2, 15.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(5.0f, 0.05f, 66.0-15.0f));
    model = als * translateMatrix * scaleMatrix;
    road.drawCubeWithTexture(lightingShader, model);

    //deck
    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 14.0 + 10.0, 2.2, 66.0 - 5.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(16.0f, 0.5f, 6.0));
    model = als * translateMatrix * scaleMatrix;
    deck.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 14.0 + 10.0, 0.2, 67.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(16.0f, 2.2f, 0.2));
    model = als * translateMatrix * scaleMatrix;
    deck.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(29.0, 1.3, 14.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(16.0f, 1.0f, 6.0f));
    model = als * translateMatrix * scaleMatrix;
   deck.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(29.0, 0.2, 11.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(16.0f, 0.4f, 4.0f));
    model = als * translateMatrix * scaleMatrix;
    deck.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(29.0,0.6, 12.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(16.0f,0.7f, 2.5f));
    model = als * translateMatrix * scaleMatrix;
    deck.drawCubeWithTexture(lightingShader, model);

    //parkign
    translateMatrix = glm::translate(identityMatrix, glm::vec3(2.0, 0.2, 80.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(13.0f, 0.05f, 13.0f));
    model = als * translateMatrix * scaleMatrix;
    proad.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(2.0, 8.2, 80.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(13.0f, 0.05f, 13.0f));
    model = als * translateMatrix * scaleMatrix;
    roof.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(3.0, 0.2+4.0, 81.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.25f, 4.0f, 0.25f));
    model = als * translateMatrix * scaleMatrix;
    pillar.drawCylinderWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(3.0, 0.2 + 4.0, 81.0+11.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.25f, 4.0f, 0.25f));
    model = als * translateMatrix * scaleMatrix;
    pillar.drawCylinderWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(3.0+11.0, 0.2 + 4.0, 81.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.25f, 4.0f, 0.25f));
    model = als * translateMatrix * scaleMatrix;
    pillar.drawCylinderWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(3.0+11.0, 0.2 + 4.0, 81.0+11.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.25f, 4.0f, 0.25f));
    model = als * translateMatrix * scaleMatrix;
    pillar.drawCylinderWithTexture(lightingShader, model);

}


#pragma once

#pragma once
#pragma once
