#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "cube.h"
#include "texture.h"
#include "stb_image.h"



void wall2(Cube& cube,Cube&glass, Shader& lightingShader, glm::mat4 als)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    //room1
    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0-9.0, 12.7, 66.0-19.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(9.0f, 10.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);
    //balc
    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0, 12.7, 72.0 - 19.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, 3.0f, 13.1f));
    model = als * translateMatrix * scaleMatrix;
    glass.drawCubeWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0 - 6.0, 12.7, 66.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(6.0f, 3.0f, 0.1f));
    model = als * translateMatrix * scaleMatrix;
    glass.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0-6.0, 12.7, 72.0 - 19.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.4f, 10.0f, 2.5f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0 - 6.0, 12.7, 66.0-2.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.4f, 10.0f, 2.5f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0 - 6.0, 20.7, 66.0 - 13.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.4f, 2.0f, 13.0f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0, 12.7, 66.0 - 19.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.4f, 10.0f, 6.0f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0-6.0, 12.7, 66.0 - 13.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(6.0f, 10.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0-9.0, 12.7, 66.0 - 19.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.4f, 10.0f, 6.0f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0 - 6.0-13.0, 12.7, 66.0 - 19.0+6.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.4f, 10.0f, 13.0f));
    model = als * translateMatrix * scaleMatrix;
    //cube.drawCubeWithTexture(lightingShader, model);
   
    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0 - 6.0 - 13.0, 12.7, 66.0 - 19.0 + 6.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(5.0f, 10.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0 - 9.0 - 1.0, 12.7, 66.0 - 19.0 + 6.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, 10.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0 - 9.0 - 5.0, 12.7+7.0, 66.0 - 19.0 + 6.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(5.0f, 3.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0 - 9.0, 12.7 + 7.0, 66.0 - 19.0 + 6.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(5.0f, 3.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    //wind
    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0 - 6.0 - 13.0, 20.7, 66.0 ));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(13.4f, 2.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0 - 6.0 - 13.0, 12.7, 66.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(13.4f, 3.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0 - 6.0 -5.0, 12.7, 66.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(5.4f, 10.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    



    //room2

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0, 12.7, 66.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(15.4f, 3.0f, 0.1f));
    model = als * translateMatrix * scaleMatrix;
    glass.drawCubeWithTexture(lightingShader, model);


    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 , 20.7, 66.0 - 6.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(15.4f, 2.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0, 12.7, 66.0 - 6.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.5f, 10.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0+12.5, 12.7, 66.0 - 6.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.5f, 10.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);


    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0, 12.7, 66.0 - 20.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.4f, 10.0f, 20.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0+15.0, 12.7, 66.0 - 13.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.4f, 10.0f, 13.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 15.0, 12.7, 66.0 - 9.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(6.0f, 10.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
   // cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 15.0, 12.7, 66.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(6.0f, 10.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 13.0, 12.7, 66.0 - 13.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(8.0f, 10.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 13.0, 20.7, 66.0 - 18.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.4f, 2.0f, 5.0f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    //room 3
    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0, 12.7, 66.0 - 20.0-6.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(13.4f, 10.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0+13.0, 12.7, 66.0 - 20.0 - 8.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.4f, 10.0f, 10.0f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0, 12.7, 66.0 - 20.0 - 13.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.4f, 10.0f, 13.0f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    //room 4
    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 13.0, 12.7, 15.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.4f, 10.0f, 18.0f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0, 12.7, 15.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.4f, 10.0f, 18.0f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0, 12.7, 15.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(13.0f, 3.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0, 20.7, 15.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(13.0f, 2.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0, 12.7, 15.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.5f, 10.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0+2.5+8.0, 12.7, 15.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.5f, 10.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 13.0, 20.7, 15.0 + 18.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.4f, 2.0f, 5.0f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    //room 5
    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 13.0, 12.7, 15.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(13.0f, 10.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 13.0+13.0, 12.7, 15.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.4f, 10.0f, 13.0f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 13.0+9.0, 12.7, 15.0+13.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.0f, 10.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    //room 6

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 13.0 + 9.0, 12.7, 15.0+19.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(18.0f, 10.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0, 12.7, 15.0+5.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.4f, 10.0f, 14.0f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    //balc
    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 13.0 + 13.0, 20.7, 15.0 + 5.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(14.0f, 2.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 13.0 + 13.0, 12.7, 15.0 + 5.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.0f, 10.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 13.0 + 13.0+11.0, 12.7, 15.0 + 5.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.0f, 10.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 13.0 + 13.0, 12.7, 15.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(14.0f, 3.0f, 0.2f));
    model = als * translateMatrix * scaleMatrix;
    glass.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 13.0 + 13.0+14.0, 12.7, 15.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2f, 3.0f, 5.5f));
    model = als * translateMatrix * scaleMatrix;
    glass.drawCubeWithTexture(lightingShader, model);



}

void trans(Cube& cube, Cube& glass, Shader& lightingShader, glm::mat4 als)
{



    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(5.0f, 8.0f, 0.2f));
    model = als * translateMatrix * scaleMatrix;
    glass.drawCubeWithTexture(lightingShader, model);

}
//translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0+2.5+5.0, 12.7, 66.0 - 6.0));

void window_2nd(Cube& cube, Shader& lightingShader, glm::mat4 als)
{



    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 2.25, 12.7+3.0, 15.0));
    //translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0,3.0,0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.0f, 5.0f, 0.2f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

}

void window_2nd2(Cube& cube, Shader& lightingShader, glm::mat4 als)
{



    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 2.25+4.0, 12.7 + 3.0, 15.0));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.0f, 5.0f, 0.2f));
    model = als * translateMatrix *rotateYMatrix* scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

}

void window_2ndg(Cube& cube, Shader& lightingShader, glm::mat4 als)
{



    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0+11.0, 2.2 + 3.0, 15.0));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.0f, 5.0f, 0.2f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

}
void window_2ndg2(Cube& cube, Shader& lightingShader, glm::mat4 als)
{



    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 11.0+4.0, 2.2 + 3.0, 15.0));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.0f, 5.0f, 0.2f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

}

void window_2ndf(Cube& cube, Shader& lightingShader, glm::mat4 als)
{



    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0-6.0-13.0, 12.7 + 3.0, 66.0));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.0f, 5.0f, 0.2f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

}

void window_2ndf2(Cube& cube, Shader& lightingShader, glm::mat4 als)
{



    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0 - 6.0 - 9.0, 12.7 + 3.0, 66.0));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.0f, 5.0f, 0.2f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

}


#pragma once
#pragma once
