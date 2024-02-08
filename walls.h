#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "texture.h"
#include "cube.h"



void wall(Cube&cube,Cube& door, Cube& wdwall, Shader& lightingShader, glm::mat4 als)
{

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0 - 16.0, 2.2, 47.4));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(16.0f, 10.0f, 0.2f));
    model = als * translateMatrix * scaleMatrix;
    wdwall.drawCubeWithTexture(lightingShader, model);
   
    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 10.3, 9.2, 47.0 + 6.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.0f, 3.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 10.0, 10.2, 47.0 - 4.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.4f, 2.0f, 4.5f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0, 2.2, 15.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.4f,10.0f, 19.0f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    //kitchen
    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0, 2.2, 15.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(6.0+5.0f, 10.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(29.0, 2.2, 15.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.4f, 10.0f, 5.0f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0+11.0+8.0, 2.2, 15.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(5.0 , 10.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 11.0, 2.2, 15.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(8.0, 3.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 11.0, 2.2+8.0, 15.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(8.0, 2.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 +6.0, 2.2, 15.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.4, 10.0f, 7.0f));
    model = als * translateMatrix * scaleMatrix;
    //cube.drawCubeWithTexture(lightingShader, model);


    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0+14.0, 2.2, 47.0+6.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.4f, 10.0f, 13.0f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    //sect
    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 , 2.2, 47.0 -5.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(10.0f, 10.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0, 2.2, 47.0 - 5.0-10));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(10.0f, 10.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
   // cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0, 2.2, 47.0 - 5.0 - 10));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.4f, 10.0f, 34.0f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0, 2.2, 47.0 - 5.0 - 10-7.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(10.0f, 10.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0+10.0, 2.2, 47.0 - 5.0 - 10 - 7.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.4f, 10.0f, 11.0f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);


    //hall
    translateMatrix = glm::translate(identityMatrix, glm::vec3(29.0, 2.2, 20.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.0f, 10.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(29.0, 2.2+8.0, 20.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(16.0f, 2.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(29.0+13.0, 2.2, 20.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.0f, 10.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0-0.0, 2.2, 20.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.4f, 10.0f, 14.5f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    
    
    //first_room front
    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0, 2.2, 66.0-0.4));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(14.0f, 2.5f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0, 2.2+5.0+2.5, 66.0-0.4));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(14.0f, 2.5f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0, 2.2, 66.0-0.4));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.0f, 10.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(11.0+5.0, 2.2, 66.0-0.4));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.4f, 10.0f, 0.5f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);
    
    //back
    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0, 2.2, 47.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(10.0f, 10.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
   // cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0+10.0, 2.2, 47.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.4f, 10.0f, 6.0f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 , 2.2, 47.0+6.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(7.0 + 3.4f, 10.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);


    //drwaing

    //back
    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0+14.0+10.0, 2.2, 47.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(16.0f, 10.0f, 0.5f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 14.0 + 10.0, 2.2, 47.0+5.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.4f, 10.0f, 5.0f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 14.0 + 10.0+16.0-0.4, 2.2, 47.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.4f, 10.0f, 14.0f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    //front

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 14.0 + 10.0, 2.2, 66.0-5.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(16.f, 0.5f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 14.0 + 10.0, 2.2+7.0, 66.0 - 5.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(16.f, 3.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 14.0 + 10.0, 2.2, 66.0 - 5.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.0f, 10.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 14.0 + 10.0+8.0+4.0, 2.2, 66.0 - 5.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.0f, 10.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);


    //door panel

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 14.0, 2.2+7.0, 66.0 - 5.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(10.0f, 3.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 14.2, 2.2, 66.0 - 5.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.8f, 7.0f, 0.3f));
    model = als * translateMatrix * scaleMatrix;
    door.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 14.0+7.0, 2.2, 66.0 - 5.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.0f, 7.0f, 0.3f));
    model = als * translateMatrix * scaleMatrix;
    door.drawCubeWithTexture(lightingShader, model);

    //stair area
    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0-0.4, 2.2, 47.0- 5.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.4f, 10.0f, 5.0f));
    model = als * translateMatrix * scaleMatrix;
   // cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0-9.0, 2.2, 47.0 - 5.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(9.0f, 10.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    //cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0 - 9.0, 2.2, 47.0 -12.9));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(9.0f, 10.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(30.5, 2.2, 47.0 - 12.9));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(6.0f, 10.0f, 0.4f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(27.0, 2.2, 34.1));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.0f, 4.0f, 0.4f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);


    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0 - 9.0, 2.2, 47.0 - 12.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.4f, 10.0f, 12.5f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0 - 9.0, 2.2, 47.0 - 12.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.4f, 20.5f, 4.25f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0 - 9.0, 2.2, 47.0 - 4.25));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.4f, 20.5f, 4.25f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0 - 9.0, 2.2+10.0+7.0, 47.0 - 12.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.4f, 3.5f, 12.5f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);
}

void roof_f(Cube& cube,Cube&rail, Shader& lightingShader, glm::mat4 als) {
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(24.9+7.1, 2.2+5.0, 47.0 - 12.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.0f, 0.5f, 8.1f));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

   

    //stair railing
    float m = 0.0;
    float n = 0.0;
    for (int i = 0; i < 7; i++) {
    translateMatrix = glm::translate(identityMatrix, glm::vec3(24.9+7.1, 7.7 + m, 38.5+n));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.15, 2.0, 0.3));
    model = als * translateMatrix * scaleMatrix;
    rail.drawCubeWithTexture(lightingShader, model);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(24.9 + 6.95, 9.7 + m, 38.5 + n));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.5, 0.07, 0.3));
    model = als * translateMatrix * scaleMatrix;
    rail.drawCubeWithTexture(lightingShader, model);
    n += 0.5;
    }
    


    translateMatrix = glm::translate(identityMatrix, glm::vec3(24.9 + 7.1, 2.2 + 5.4, 34.5+7.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.02f,7.1f, 0.6f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(44.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    model = als * translateMatrix * rotateYMatrix* scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(24.9 + 7.1, 2.2 + 5.1, 34.5 + 8.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.0f, 7.0f, 0.2f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(44.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    //1
    translateMatrix = glm::translate(identityMatrix, glm::vec3(27.0, 2.2, 34.5+4.0-0.02 ));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.7f, 7.7f, 0.02f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(-45.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(27.0, 2.2, 34.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.7f, 7.7f, 0.02f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(-45.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

}
//2nd floor


void roof_2nd(Cube& cube, Cube& floor, Shader& lightingShader, glm::mat4 als) {
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(4.0f, 2.2 + 10.0f, 14.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(42.0,0.5,20.5));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);


    translateMatrix = glm::translate(identityMatrix, glm::vec3(4.0f, 2.2 + 10.0+0.5f, 14.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(42.0, 0.2, 20.5));
    model = als * translateMatrix * scaleMatrix;
    floor.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(4.0f, 2.2 + 10.0f, 14.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(23.0, 0.5, 50.5));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(4.0f, 2.2 + 10.0+0.5f, 14.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(23.0, 0.2, 50.5));
    model = als * translateMatrix * scaleMatrix;
    floor.drawCubeWithTexture(lightingShader, model);


    translateMatrix = glm::translate(identityMatrix, glm::vec3(4.0f, 2.2 + 10.0f, 47.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(42.0, 0.2, 19.33));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(4.0f, 2.2 + 10.0+0.2f, 47.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(42.0, 0.2, 19.67));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(4.0f, 2.2 + 10.0+0.45f, 47.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(42.0, 0.2, 20.0));
    model = als * translateMatrix * scaleMatrix;
    floor.drawCubeWithTexture(lightingShader, model);
    //stair railing
   
    translateMatrix = glm::translate(identityMatrix, glm::vec3(4.0f, 2.7 + 10.0 + 10.0f, 14.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(42.0, 0.3, 53.0));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

}


void pool(Cube& cube, Cube& water,Cube&stair, Shader& lightingShader, glm::mat4 als) {
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0-8.8f, 2.2, 47-12.5f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.8, 2.5, 12.5));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);    

    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0 - 1.0f, 0.2, 47.0 - 12.5f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.1, 4.5, 12.5));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0 - 8.0f, 2.2, 47 - 12.5f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(7.0, 2.5, 1.0));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0 - 8.0f, 2.2, 47 - 1.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(7.0, 2.5, 1.0));
    model = als * translateMatrix * scaleMatrix;
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0 - 8.0f, 2.2+2.0, 47 - 11.5f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(7.0, 0.1, 10.5));
    model = als * translateMatrix * scaleMatrix;
   water.drawCubeWithTexture(lightingShader, model);

   translateMatrix = glm::translate(identityMatrix, glm::vec3(48.0, 0.0, 47 - 5.0f));
   rotateYMatrix = glm::rotate(identityMatrix, glm::radians(47.0f), glm::vec3(0.0f, 0.0f, 1.0f));
   scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.1, 5.7, 0.05));
   model = als * translateMatrix *rotateYMatrix *scaleMatrix;
  stair.drawCubeWithTexture(lightingShader, model);

   translateMatrix = glm::translate(identityMatrix, glm::vec3(48.0, 0.0, 47 - 7.5f));
   rotateYMatrix = glm::rotate(identityMatrix, glm::radians(47.0f), glm::vec3(0.0f, 0.0f, 1.0f));
   scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.1, 5.7, 0.05));
   model = als * translateMatrix * rotateYMatrix * scaleMatrix;
   stair.drawCubeWithTexture(lightingShader, model);

   translateMatrix = glm::translate(identityMatrix, glm::vec3(47.0, 1.0, 47 - 7.5f));
   rotateYMatrix = glm::rotate(identityMatrix, glm::radians(0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
   scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.7, 0.2, 2.5));
   model = als * translateMatrix * rotateYMatrix * scaleMatrix;
   stair.drawCubeWithTexture(lightingShader, model);

   translateMatrix = glm::translate(identityMatrix, glm::vec3(46.3, 1.8, 47 - 7.5f));
   rotateYMatrix = glm::rotate(identityMatrix, glm::radians(0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
   scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.7, 0.2, 2.5));
   model = als * translateMatrix * rotateYMatrix * scaleMatrix;
   stair.drawCubeWithTexture(lightingShader, model);

   translateMatrix = glm::translate(identityMatrix, glm::vec3(45.8, 2.6, 47 - 7.5f));
   rotateYMatrix = glm::rotate(identityMatrix, glm::radians(0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
   scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.7, 0.2, 2.5));
   model = als * translateMatrix * rotateYMatrix * scaleMatrix;
   stair.drawCubeWithTexture(lightingShader, model);

   translateMatrix = glm::translate(identityMatrix, glm::vec3(45.2, 3.2, 47 - 7.5f));
   rotateYMatrix = glm::rotate(identityMatrix, glm::radians(0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
   scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.7, 0.2, 2.5));
   model = als * translateMatrix * rotateYMatrix * scaleMatrix;
   stair.drawCubeWithTexture(lightingShader, model);
}

#pragma once

#pragma once
