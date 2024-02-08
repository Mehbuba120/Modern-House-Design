#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "texture.h"
#include "cube.h"
#include "sphere.h"


void teatable(Cylinder& gls, Cylinder& ch, Shader& lightingShader, glm::mat4 als)
{


    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0 , 1.0 ,0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.8, 1.0f, 0.8f));
    model = als * translateMatrix * scaleMatrix;
    ch.drawCylinderWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 2.0, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.0, 0.1f, 2.0f));
    model = als * translateMatrix * scaleMatrix;
    gls.drawCylinderWithTexture(lightingShader, model);


}

void sqtable(Cube& glass, Cube&cube, Shader& lightingShader, glm::mat4 als)
{


    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1, 1.5f, 1.8f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0 + 3.5, 0.0, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1, 1.5f, 1.8f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.1, 1.4, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.4, 0.1f, 1.8f));
    model = als * translateMatrix * scaleMatrix;
    glass.drawCubeWithTexture(lightingShader, model);


}

void table(Cube& cube, Cylinder& ch, Shader& lightingShader, glm::mat4 als)
{


    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(19.0+3.5, 2.2+2.9, 25.0+2.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.5, 0.15f, 3.0f));
    model = als * translateMatrix * scaleMatrix;
    ch.drawCylinderWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(19.3, 2.2, 26.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.3,3.0f, 0.3f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(19.3, 2.2, 29.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.3, 3.0f, 0.3f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(19.3+6.2, 2.2, 26.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.3, 3.0f, 0.3f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(19.3 + 6.2, 2.2, 29.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.3, 3.0f, 0.3f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

  


}

void chair(Cube& cube, Cylinder&ch, Shader& lightingShader, glm::mat4 als)
{


    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.15 , 1.5, 0.15));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.7, 0.5f, 2.05f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 2.0, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.0, 0.1f, 2.2f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.15, 0.0, 0.15));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2, 1.5f, 0.2f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.15+1.5, 0.0, 0.15));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2, 1.5f, 0.2f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.15 + 1.5, 0.0, 2.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2, 1.5f, 0.2f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.15, 0.0,  2.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2, 1.5f, 0.2f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    //up
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.3, 2.9, 2.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.08, 0.9f, 0.08f));
    model = als * translateMatrix * scaleMatrix;
    ch.drawCylinderWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.15 + 1.55, 2.9, 2.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.08, 0.9f, 0.08f));
    model = als * translateMatrix * scaleMatrix;
    ch.drawCylinderWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.15 + 0.6, 2.9, 2.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.05, 0.9f, 0.05f));
    model = als * translateMatrix * scaleMatrix;
    ch.drawCylinderWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.15 + 1.03, 2.9, 2.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.05, 0.9f, 0.05f));
    model = als * translateMatrix * scaleMatrix;
    ch.drawCylinderWithTexture(lightingShader, model);


    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.0, 3.85, 2.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0, 0.1f, 0.1f));
    model = als * translateMatrix * scaleMatrix;
    ch.drawCylinderWithTexture(lightingShader, model);
   
}


void cabinet(Cube& cube, Cube& frz, Cube& oven, Cylinder&cyl, Shader& lightingShader, glm::mat4 als)
{


    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.5, 2.2, 20.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.0, 6.0f, 4.0f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.5+2.0, 2.2, 20.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1, 6.0f, 4.0f));
    model = als * translateMatrix * scaleMatrix;
    frz.drawCubeWithTexture(lightingShader, model);

    //cab
    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0, 2.2+2.8, 15.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(21.0, 0.2f, 3.0f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0+13, 2.2 + 3.0,15.5+0.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.0, 0.1f, 2.0f));
    model = als * translateMatrix * scaleMatrix;
    oven.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0, 2.2 , 15.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(10.0,2.8f, 2.7f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0+10.1, 2.2, 15.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.67, 2.8f, 2.7f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 10.1+3.7, 2.2, 15.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.67, 2.8f, 2.7f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 10.1 + 3.0, 2.2+1.4, 15.5+2.9));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.05, 0.5f, 0.05f));
    model = als * translateMatrix * scaleMatrix;
    cyl.drawCylinderWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 10.1 + 3.0+3.67, 2.2 + 1.4, 15.5 + 2.9));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.05, 0.5f, 0.05f));
    model = als * translateMatrix * scaleMatrix;
    cyl.drawCylinderWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 10.1 + 3.0 + 3.67+0.67+0.67, 2.2 + 1.4, 15.5 + 2.9));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.05, 0.5f, 0.05f));
    model = als * translateMatrix * scaleMatrix;
    cyl.drawCylinderWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 10.1 + 3.7+3.7, 2.2, 15.5+2.6));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.67, 2.8f, 0.1f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);


    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0+21.0, 2.2+2.8, 15.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.0, 0.2f, 5.0f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 21.2, 2.2, 15.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.8, 2.8f, 4.8f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

}

void railing(Cube& cube, Cylinder& ch, Shader& lightingShader, glm::mat4 als)
{


    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 3.0, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.4, 0.2f, 12.0f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.4, 3.0f, 0.2f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 3.0, 12.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(5.5, 0.2f, 0.5f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0+5.3, 0.0, 12.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2, 3.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    //

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.2, 1.5, 1.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.15, 1.5f, 0.15f));
    model = als * translateMatrix * scaleMatrix;
    ch.drawCylinderWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.2, 1.5, 2.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.15, 1.5f, 0.15f));
    model = als * translateMatrix * scaleMatrix;
    ch.drawCylinderWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.2, 1.5, 3.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.15, 1.5f, 0.15f));
    model = als * translateMatrix * scaleMatrix;
    ch.drawCylinderWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.2, 1.5, 4.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.15, 1.5f, 0.15f));
    model = als * translateMatrix * scaleMatrix;
    ch.drawCylinderWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.2, 1.5, 5.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.15, 1.5f, 0.15f));
    model = als * translateMatrix * scaleMatrix;
    ch.drawCylinderWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.2, 1.5, 6.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.15, 1.5f, 0.15f));
    model = als * translateMatrix * scaleMatrix;
    ch.drawCylinderWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.2, 1.5, 7.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.15, 1.5f, 0.15f));
    model = als * translateMatrix * scaleMatrix;
    ch.drawCylinderWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.2, 1.5, 8.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.15, 1.5f, 0.15f));
    model = als * translateMatrix * scaleMatrix;
    ch.drawCylinderWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.2, 1.5, 9.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.15, 1.5f, 0.15f));
    model = als * translateMatrix * scaleMatrix;
    ch.drawCylinderWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.2, 1.5, 10.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.15, 1.5f, 0.15f));
    model = als * translateMatrix * scaleMatrix;
    ch.drawCylinderWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.2, 1.5, 11.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.15, 1.5f, 0.15f));
    model = als * translateMatrix * scaleMatrix;
    ch.drawCylinderWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.2, 1.5, 12.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.15, 1.5f, 0.15f));
    model = als * translateMatrix * scaleMatrix;
    ch.drawCylinderWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.2, 1.5, 12.2));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.15, 1.5f, 0.15f));
    model = als * translateMatrix * scaleMatrix;
    ch.drawCylinderWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(2.2, 1.5, 12.2));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.15, 1.5f, 0.15f));
    model = als * translateMatrix * scaleMatrix;
    ch.drawCylinderWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(3.2, 1.5, 12.2));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.15, 1.5f, 0.15f));
    model = als * translateMatrix * scaleMatrix;
    ch.drawCylinderWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(4.2, 1.5, 12.2));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.15, 1.5f, 0.15f));
    model = als * translateMatrix * scaleMatrix;
    ch.drawCylinderWithTexture(lightingShader, model);

}

void projector(Cube& cube, Cylinder& ch, Shader& lightingShader, glm::mat4 als)
{


    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0+25, 20.7, 18.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2, 0.5f, 5.0f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);


}

void projectorslide(Cube& cube, Shader& lightingShader, glm::mat4 als)
{


    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 25.15, 14.7, 18.1));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1, 6.0f, 6.5f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);



}

void curtains(Cube& cube, Shader& lightingShader, glm::mat4 als)
{

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 2.4, 13.7, 15.65));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.0, 8.0f, 0.1f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);
}
void curtainsr1(Cube& cube, Shader& lightingShader, glm::mat4 als)
{

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 2.4, 13.0, 59.8));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(5.0, 8.0f, 0.1f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);
}

void curtains2(Cube& cube, Shader& lightingShader, glm::mat4 als)
{

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 2.4+8.2, 13.7, 15.65));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.0, 8.0f, 0.1f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);
}
void curtains2r1(Cube& cube, Shader& lightingShader, glm::mat4 als)
{

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 2.4 + 10.2, 13.0, 59.8));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(5.0, 8.0f, 0.1f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);
}

void curtainsr3(Cube& cube, Shader& lightingShader, glm::mat4 als)
{

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0 -11.1, 13.0, 15.0+6.0));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.0, 8.0f, 0.1f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);
}
void curtains2r3(Cube& cube, Shader& lightingShader, glm::mat4 als)
{

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0 - 11.1+8.2, 13.0, 15.0 + 6.0));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.0, 8.0f, 0.1f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);
}

#pragma once


#pragma once
