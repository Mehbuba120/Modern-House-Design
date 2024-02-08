//
//  main.cpp
//  3D Object Drawing
//
//  Created by Nazirul Hasan on 4/9/23.
//

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "walls.h"
#include "shader.h"
#include "camera.h"
#include "basic_camera.h"
#include "pointLight.h"
#include "cube.h"
#include "cylinder.h"
#include "stb_image.h"
#include "directionalLight.h"
#include "SpotLight.h"
#include "texture.h"
#include "sphere2.h"
#include "surroundings.h"
#include "sofa.h"
#include "lamp.h"
#include "bed.h"
#include "lawn.h"
#include "base.h"
#include "swing.h"
#include "stairs.h"
#include "rack.h"
#include "main_door.h"
#include "main_gate2.h"
#include "car.h"
#include "main_gate.h"
#include "floor_2nd.h"
#include "room_g.h"
#include "office.h"
#include "roundTable.h"
#include <iostream>

using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow* window);
//unsigned int loadTexture(char const* path, GLenum textureWrappingModeS, GLenum textureWrappingModeT, GLenum textureFilteringModeMin, GLenum textureFilteringModeMax);
//void bed(Shader& lightingShader, glm::mat4 alTogether, Cube& cube);

//curves
void scsToWcs(float sx, float sy, float wcsv[3]);
long long nCr(int n, int r);
void BezierCurve(double t, float xy[2], GLfloat ctrlpoints[], int L);
unsigned int hollowBezier(GLfloat ctrlpoints[], int L);
void drawCurve(Shader ourShader, glm::mat4 moveMatrix, unsigned int VAO, vector<int> indices, glm::vec4 color, float rotateAngleTest_Y)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, scaleMatrix, model, rotateYMatrix;

    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngleTest_Y), glm::vec3(0.0f, 1.0f, 0.0f));

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, 1.0f, 1.0f));
    model = translateMatrix * rotateYMatrix * scaleMatrix;

    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", color);
    ourShader.setFloat("material.shininess", 32.0f);

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, (unsigned int)indices.size(), GL_UNSIGNED_INT, (void*)0);
    glBindVertexArray(0);
}


// settings
const unsigned int SCR_WIDTH = 1920;
const unsigned int SCR_HEIGHT = 1080;


// model, view & projection matrix
glm::mat4 model = glm::mat4(1.0f);
glm::mat4 view = glm::mat4(1.0f);
glm::mat4 projection = glm::mat4(1.0f);
// viewport
GLint viewport[4];

/////////////////////////////////////////////////////////////
float wcsClkDn[3], wcsClkUp[3];
vector <float> cntrlPoints;
vector <float> coordinates;
vector <float> normals;
vector <int> indices;
vector <float> vertices;


void updateSpotlight(const Shader& shader, const glm::vec3& direction)
{
    shader.setVec3("spotlight.direction", direction);

}

void readControlPointsFromFile(const char* filename, std::vector<float>& controlPoints) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        float x, y, z;
        if (!(iss >> x >> y >> z)) {
            std::cout << "Error reading control points from file." << std::endl;
            return;
        }
        cntrlPoints.push_back(x);
        cntrlPoints.push_back(y);
        cntrlPoints.push_back(z);
    }

    file.close();
}
class point
{
public:
    point()
    {
        x = 0;
        y = 0;
    }
    int x;
    int y;
} clkpt[2];
int mouseButtonFlag = 0;
FILE* fp;
const double pi = 3.14159265389;
const int nt = 40;
const int ntheta = 20;
bool showControlPoints = true;
bool loadBezierCurvePoints = false;
bool showHollowBezier = false;
bool lineMode = false;
unsigned int bezierVAO;



// modelling transform
float rotateAngle_X = 0.0;
float rotateAngle_Y = 0.0;
float rotateAngle_Z = 0.0;
float rotateAxis_X = 0.0;
float rotateAxis_Y = 0.0;
float rotateAxis_Z = 1.0;
float translate_X = 0.0;
float translate_Y = 0.0;
float translate_Z = 0.0;
float scale_X = 1.0;
float scale_Y = 1.0;
float scale_Z = 1.0;
bool door = false;
bool dolna = false;
bool winSlide = false;
bool car_strt = false;
bool scl = false;
bool trd = false;
bool windopn = false;
bool rdoor = false;
bool fanmv = false;
bool watr_tap = false;

bool n8view = false;
// camera
Camera camera(glm::vec3(25.0f, 5.0f,98.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

float eyeX = 0.0, eyeY = 1.0, eyeZ = 3.0;
float lookAtX = 0.0, lookAtY = 0.0, lookAtZ = 0.0;
glm::vec3 V = glm::vec3(0.0f, 1.0f, 0.0f);
BasicCamera basic_camera(eyeX, eyeY, eyeZ, lookAtX, lookAtY, lookAtZ, V);

// lights
// positions of the point lights
glm::vec3 pointLightPositions[] = {
     glm::vec3(15.0,  10.50f,  16.0),
     //glm::vec3(1.5f,  4.5f,  -6.5 + 0.25f),
     glm::vec3(25.5f,  18.5f,   20.0),
     //glm::vec3(-1.5f,  4.5f,  -6.5 + 0.25f),
    glm::vec3(20.5f,  20.5f,   20.0),
};
PointLight pointlight1(

    pointLightPositions[0].x, pointLightPositions[0].y, pointLightPositions[0].z,  // position
    0.05f, 0.05f, 0.05f,     // ambient
    0.8f, 0.8f, 0.8f,     // diffuse
    1.0f, 1.0f, 1.0f,        // specular
    1.0f,   //k_c
    0.14f,  //k_l
    0.07f, //k_q
    1       // light number
);

PointLight pointlight3(

    pointLightPositions[2].x, pointLightPositions[2].y, pointLightPositions[2].z,  // position
    0.05f, 0.05f, 0.05f,     // ambient
    0.8f, 0.8f, 0.8f,     // diffuse
    1.0f, 1.0f, 1.0f,        // specular
    1.0f,   //k_c
    0.14f,  //k_l
    0.07f, //k_q
    2      // light number
);

DirLight dirLight(
   
    -0.2f,-0.5f, -0.3f,
    0.6f, 0.6f, 0.6f,
    1.0f,1.0f,1.0f,     // diffuse
    0.2f, 0.2f, 0.2f
);
SpotLight spotLight(
    25.50f, 14.0f, 67.0f,
    0.6f, -1.0f, 0.5f,
    1.0f, 0.0f, 0.0f,
    1.0f, 0.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f,
    0.09f,
    0.032f,
    12.5f,
    15.0f
);



// light settings
bool dirLightOn = true;
bool pointLightOn = true;
bool spotLightOn = true;
bool ambientToggle = true;
bool diffuseToggle = true;
bool specularToggle = true;


// timing
float deltaTime = 0.0f;    // time between current frame and last frame
float lastFrame = 0.0f;

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "CSE 4208: Computer Graphics Laboratory", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    // tell GLFW to capture our mouse
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // configure global opengl state
    // -----------------------------
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


    // build and compile our shader zprogram
    // ------------------------------------
    Shader lightingShaderWithTexture("vertexShaderForPhongShadingWithTexture.vs", "fragmentShaderForPhongShadingWithTexture.fs");
    Shader lightingShader("vertexShaderForPhongShading.vs", "fragmentShaderForPhongShading.fs");
    Shader ourShader("vertexShader.vs", "fragmentShader.fs");

    string diffuseMapPath = "AC.jpg"; //loading image path for diffuse.
    string specularMapPath = "whiteBackground.png"; //loading image path for specular.
    string grass = "grass.jpg";
    string boundary = "boundary.jpg";
    string main_road = "main_road.jpg";
    string m_gate = "main_gate.jpg";
    string tiles = "floor_tl3.jpg";
    string roadl = "road.jpg";
    string park = "park_road.jpg";
    string ppillar = "pillar.jpg";
    string proof = "roof.jpg";
    string wallc = "wall2.png";
    string door1 = "door1.jpg";
    string doorrm = "door_r.png";
    string door_main = "door3.jpg";
    string ddeck = "deck.jpg";
    string tv = "tv.png";
    string swings = "swing.jpg";
    string rope = "rope.jpg";
    string stell = "carw.png";
    string wind = "window.jpg";
    string wind2 = "slide_wind2.png";
    string wind1 = "slide_w1.png";
    string rf = "roof2.png";
    string tr = "tree.png";
    string tw = "tree_w.jpg";
    string ss = "sofa_frame.jpg";
    string sf = "sofa_seat2.jpg";
    string s1 = "sofa1.jpg";
    string cus = "cusion.jpg";
    string matt = "mat.jpg";
    string bdf = "bed_frame2.jpg";
    string bdbo = "bed_body.jpg";
    string bdfm = "foam_bed.jpg";
    string blank = "blank.jpg";
    string gls = "glass.jpg";
    string al = "alm.jpg";
    string mir = "mirror.png";
    string cbn = "cabinate.jpg";
    string frdz = "frz.jpg";
    string ovn = "oven.jpg";
    string rail = "railing.png";
    string wd = "weardrb.jpg";
    string transpa = "transp.png";
    string pro = "projector.jpg";
    string mirg = "mirror2.png";
    string crt = "curtains.jpg";
    string fl = "files.png";
    string bk = "books.png";
    string toy = "toys.png";
    string toy2 = "machine.jpg";
    string bed_hd = "bed_head.png";
    string foam_hd = "foam_g.jpg";
    string blck = "black.jpg";
    string watr = "water.jpg";
    string tvwall = "tvwall.jpg";
    string paint = "paintings.png";
    string bcar = "carbody.jpg";
    string wcar = "carwind.jpg";
    string wtl = "wtiles.jpg";

    unsigned int wtls = loadTexture(wtl.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int wcard = loadTexture(wcar.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int wpaint = loadTexture(paint.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int tvv = loadTexture(tv.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int wltv = loadTexture(tvwall.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int blk = loadTexture(blck.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int rmdr = loadTexture(doorrm.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int fhd = loadTexture(foam_hd.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int bhd = loadTexture(bed_hd.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int tys2 = loadTexture(toy2.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int tys = loadTexture(toy.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int fsl = loadTexture(fl.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int bsk = loadTexture(bk.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int crtt = loadTexture(crt.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int gmir = loadTexture(mirg.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int wrd = loadTexture(wd.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int proj = loadTexture(pro.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int tra = loadTexture(transpa.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int cbnt = loadTexture(cbn.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int mirr = loadTexture(mir.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int gl = loadTexture(gls.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int fbd = loadTexture(bdf.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int bobd = loadTexture(bdbo.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int fmbd = loadTexture(bdfm.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int blan = loadTexture(blank.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int diffMap = loadTexture(diffuseMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int specMap = loadTexture(specularMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int grasses = loadTexture(grass.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int boundaryy = loadTexture(boundary.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int mroad = loadTexture(main_road.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int mgate = loadTexture(m_gate.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int f_tiles = loadTexture(tiles.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int lroad = loadTexture(roadl.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int parkr = loadTexture(park.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int pillar = loadTexture(ppillar.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int roof = loadTexture(proof.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int cwall = loadTexture(wallc.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int door_pan = loadTexture(door1.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int door_m = loadTexture(door_main.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int deck= loadTexture(ddeck.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int sswing = loadTexture(swings.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int rrope = loadTexture(rope.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int ssteel = loadTexture(stell.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int wwind = loadTexture(wind.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int wwind1 = loadTexture(wind1.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int wwind2 = loadTexture(wind2.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int rrf = loadTexture(rf.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int trr = loadTexture(tr.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int twood = loadTexture(tw.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int sframe = loadTexture(ss.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int sfoam = loadTexture(sf.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int sfoam2 = loadTexture(s1.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int c = loadTexture(cus.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int mt = loadTexture(matt.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int almm = loadTexture(al.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int frg = loadTexture(frdz.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int ov = loadTexture(ovn.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int rl = loadTexture(rail.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int wtr = loadTexture(watr.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int carb = loadTexture(bcar.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);


    Cube wtile = Cube(wtls, wtls, 32.0f, 0.0f, 0.0f, 3.0f, 3.0f);
    Cube carwind = Cube(wcard, wcard, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cube carbd = Cube(carb, carb, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cube paintw = Cube(wpaint, wpaint, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cube wdwall = Cube(wltv, wltv, 32.0f, 0.0f, 0.0f, 4.0f, 1.0f);
    Cube water = Cube(wtr, wtr, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cube blacktl = Cube(blk, blk, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cube rmdoor = Cube(rmdr, rmdr, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cube bdfoam_g = Cube(fhd, fhd, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cube file = Cube(fsl, fsl, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cube books = Cube(bsk, bsk, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cube curt = Cube(crtt, crtt, 32.0f, 0.0f, 0.0f, 5.0f, 1.0f);
    Cube mirr_g = Cube(gmir, gmir, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cube wdr = Cube(wrd, wrd, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cube projc = Cube(proj, proj, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cube transp = Cube(tra, tra, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cube railng = Cube(rl, rl, 32.0f, 0.0f, 0.0f, 3.0f, 1.0f);
    Cube oven = Cube(ov, ov, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cube frz = Cube(frg, frg, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cube cab = Cube(cbnt, cbnt, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cube alm = Cube(almm, almm, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cube vtv = Cube(tvv, tvv, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cube glass = Cube(gl, gl, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cube bdfram = Cube(fbd, fbd, 32.0f, 0.0f, 0.0f, 3.0f,1.0f);
    Cube bdfoam = Cube(fmbd, fmbd, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cube bdbody = Cube(bobd, bobd, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cube blankt = Cube(blan, blan, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cube cube = Cube(diffMap, diffMap, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cube lawn_cube = Cube(grasses, grasses, 32.0f, 0.0f, 0.0f, 20.0f, 30.0f);
    Cube bound = Cube(boundaryy, boundaryy, 32.0f, 0.0f, 0.0f, 20.0f, 30.0f);
    Cube road_m = Cube(mroad, mroad, 32.0f, 0.0f, 0.0f, 2.0f, 1.0f);
    Cube gate_m = Cube(mgate, mgate, 32.0f, 0.0f, 0.0f, 2.0f, 1.0f);
    Cube floor = Cube(f_tiles, f_tiles, 32.0f, 0.0f, 0.0f, 5.0f, 5.0f);
    Cube road = Cube(lroad, lroad, 32.0f, 0.0f, 0.0f, 1.0f, 3.0f);
    Cube rpark = Cube(parkr, parkr, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cube rroof = Cube(roof, roof, 32.0f, 0.0f, 0.0f, 2.0f,2.0f);
    Cube wall_cube = Cube(cwall, cwall, 32.0f, 0.0f, 0.0f, 2.0f, 2.0f);
    Cube door_p = Cube(door_pan,door_pan, 32.0f, 0.0f, 0.0f, 1.0f,1.0f);
    Cube m_door = Cube(door_m, door_m, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cube deck_c = Cube(deck,deck, 32.0f, 0.0f, 0.0f, 1.0f, 2.0f);
    Cube swing_c = Cube(sswing, sswing, 32.0f, 0.0f, 0.0f, 1.0f, 2.0f);
    Cube wind_c = Cube(wwind, wwind, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cube wind1_c = Cube(wwind1, wwind1, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cube wind2_c = Cube(wwind2, wwind2, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cube floor_stair = Cube(pillar, pillar, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cube roff = Cube(rrf, rrf, 32.0f, 0.0f, 0.0f, 2.0f, 3.0f);
    Cube sofa_f = Cube(sframe, sframe, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cube sofa_s = Cube(sfoam, sfoam, 32.0f, 0.0f, 0.0f, 3.0f,3.0f);
    Cube sofa1 = Cube(sfoam2, sfoam2, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cube cusion = Cube(c, c, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cube mat = Cube(mt, mt, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cube mirror = Cube(mirr, mirr, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cube toys = Cube(tys, tys, 32.0f, 0.0f, 0.0f, 3.0f, 1.0f);
    Cube toys2 = Cube(tys2, tys2, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cube bed_head = Cube(bhd, bhd, 32.0f, 0.0f, 0.0f, 3.0f, 1.0f);


    //Staircube stair_c = Staircube(f_tiles, f_tiles, 32.0f, 0.0f, 0.0f, 50.0f, 50.0f);
    Sphere2 stree = Sphere2 (1.5f,36,18,glm::vec3(0.4,0.4,0.4),glm::vec3(1.0,1.0,1.0),glm::vec3(0.3,0.3,0.3), 10.0f, trr, trr, 2.0f, 2.0f, 3.0f,3.0f);
    Staircube stair_c = Staircube(fbd,fbd, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cylinder pillar_c = Cylinder(pillar, pillar, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cylinder ch_f = Cylinder(sframe, sframe, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cylinder rope_c = Cylinder(rrope, rrope, 32.0f, 0.0f, 0.0f, 20.0f, 3.0f);
    Cylinder steel_c = Cylinder(ssteel, ssteel, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cylinder tree_w = Cylinder(twood,twood, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cylinder tab_gls = Cylinder(wtr, wtr, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cylinder cmd = Cylinder(fbd,fbd, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    float r = 0.0;
    float x = 0.0;
    float y = 0.0;
    float z = 0.0;
    float carmove = 0.0;
    float slide = 0.0;
    float scaling = 1.0;
    float scaling2 = 1.0;
    float trdml = 0.0;
    float w = 0.0;
    float drm = 0.0;
    float fan_mv = 0.0;
    float tap = 0.0;

    float time = 0.0f;
    float amplitude = 30.0f;
    float frequency = 0.1f;

    //curves
    const char* controlPointsFile = "G:/graphics Assignments/project2/33Lab4 - Copy (2)/Texture Mapping Student Version - Copy/basin_points.txt";
    const char* vasePointsFile = "G:/graphics Assignments/project2/33Lab4 - Copy (2)/Texture Mapping Student Version - Copy/basin_points.txt";
    // Read control points from file
    readControlPointsFromFile(controlPointsFile, cntrlPoints);

    loadBezierCurvePoints = true;
    showHollowBezier = true;


    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        
        // per-frame time logic
        // --------------------
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // input
        // -----
        processInput(window);

        // render
        // ------
        if (n8view) {
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        }
        else {
            glClearColor(0.82f, 0.925f, 0.969f, 1.0f);
        }
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // be sure to activate shader when setting uniforms/drawing objects
        lightingShaderWithTexture.use();
        lightingShaderWithTexture.setVec3("viewPos", camera.Position);

        // pass projection matrix to shader (note that in this case it could change every frame)
        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        //glm::mat4 projection = glm::ortho(-2.0f, +2.0f, -1.5f, +1.5f, 0.1f, 100.0f);
        lightingShaderWithTexture.setMat4("projection", projection);

        // camera/view transformation
        glm::mat4 view = camera.GetViewMatrix();
        //glm::mat4 view = basic_camera.createViewMatrix();
        lightingShaderWithTexture.setMat4("view", view);

        // Modelling Transformation
        glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
        glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;
        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X, translate_Y, translate_Z));
        rotateXMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_X), glm::vec3(1.0f, 0.0f, 0.0f));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
        rotateZMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Z), glm::vec3(0.0f, 0.0f, 1.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0, 1.0, 1.0));
        model = translateMatrix * rotateXMatrix * rotateYMatrix * rotateZMatrix * scaleMatrix;

        lightingShader.use();
        lightingShader.setVec3("viewPos", camera.Position);
        lightingShader.setMat4("projection", projection);
        lightingShader.setMat4("view", view);




        pointlight1.setUpPointLight(lightingShader);
        pointlight3.setUpPointLight(lightingShader);
        dirLight.setUpDirLight(lightingShader);
        spotLight.setUpSpotLight(lightingShader);
        //spotLight2.setUpSpotLight(lightingShader);

        //curve
        glm::mat4 model3;
        if (loadBezierCurvePoints)
        {
            bezierVAO = hollowBezier(cntrlPoints.data(), ((unsigned int)cntrlPoints.size() / 3) - 1);
            loadBezierCurvePoints = false;
            showHollowBezier = true;
            showControlPoints = false;
        }
        if (showHollowBezier)
        {
            cout << "true" << "\n";
            translateMatrix = glm::translate(identityMatrix, glm::vec3(8.0, 2.2+1.5, 47.0-2.7));
            scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.7, 1.5, 1.5));
            model3 = translateMatrix * scaleMatrix;

            ourShader.use();
            //  lightingShader.use();

            lightingShader.setMat4("model", model3);
            lightingShader.setVec3("material.ambient", glm::vec3(0.3f, 3.0f, 0.3f));
            lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
            lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
            lightingShader.setFloat("material.shininess", 0.5);

            glBindVertexArray(bezierVAO);
            glDrawElements(GL_TRIANGLES, (unsigned int)indices.size(), GL_UNSIGNED_INT, (void*)0);
            glBindVertexArray(0);
             //2nd
            translateMatrix = glm::translate(identityMatrix, glm::vec3(8.0, 1.5 , 52.0));
            scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.4, 1.8, 2.0));
            model3 = translateMatrix * scaleMatrix;

            ourShader.use();
            //  lightingShader.use();

            lightingShader.setMat4("model", model3);
            lightingShader.setVec3("material.ambient", glm::vec3(0.3f, 3.0f, 0.3f));
            lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
            lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
            lightingShader.setFloat("material.shininess", 0.5);

            glBindVertexArray(bezierVAO);
            glDrawElements(GL_TRIANGLES, (unsigned int)indices.size(), GL_UNSIGNED_INT, (void*)0);
            glBindVertexArray(0);
        }
        // cube.drawCube(ourShader, model, 0.8f, 0.8f, 0.8f);


        lightingShaderWithTexture.use();
        // point light 1
        pointlight1.setUpPointLight(lightingShaderWithTexture);
        // point light 2
        // point light 3
        pointlight3.setUpPointLight(lightingShaderWithTexture);
        // point light 4
        
        dirLight.setUpDirLight(lightingShaderWithTexture);
        spotLight.setUpSpotLight(lightingShaderWithTexture);
       
       

        //2nd floor
        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
        roof_2nd(roff, floor, lightingShaderWithTexture, translateMatrix);

        wall2(wall_cube,railng, lightingShaderWithTexture, translateMatrix);

        
        //left room
        
       
        //bed
        translateMatrix = glm::translate(identityMatrix, glm::vec3(13.0, 12.7, 60.0 - 19.5));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.2, 1.0f, 1.2f));
        bed(bdfram, bdbody, bdfoam, blankt, lightingShaderWithTexture, translateMatrix *rotateYMatrix*scaleMatrix);
        //almira
        translateMatrix = glm::translate(identityMatrix, glm::vec3(18.0, 12.7, 60.0 - 18.5));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        almira(bdbody, alm, lightingShaderWithTexture, translateMatrix*rotateYMatrix);
       
        //sidetable
        translateMatrix = glm::translate(identityMatrix, glm::vec3(5.5, 12.7, 60.0 - 11.0));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
       sidetable(cusion, pillar_c, lightingShaderWithTexture, translateMatrix * rotateYMatrix);


        //dressing table
        translateMatrix = glm::translate(identityMatrix, glm::vec3(6.0, 12.7, 60.0 - 1.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.2, 1.0f, 1.3f));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        dressing(blankt, glass, bdbody, mirror, lightingShaderWithTexture, translateMatrix*rotateYMatrix * scaleMatrix);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(19.5, 12.7, 53.5));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, -1.0f, 0.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.8, 1.0f, 0.6f));
        sofa(sofa_f, cusion, lightingShaderWithTexture, translateMatrix * rotateYMatrix * scaleMatrix);


        translateMatrix = glm::translate(identityMatrix, glm::vec3(14.0, 12.7, 56.5));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f), glm::vec3(0.0f, -1.0f, 0.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0, 1.0f, 1.0f));
        teatable(tab_gls, ch_f, lightingShaderWithTexture, translateMatrix * rotateYMatrix * scaleMatrix);


        //right room
       
        translateMatrix = glm::translate(identityMatrix, glm::vec3(40.0-19.0, 12.7, 57.0));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.2, 1.0f, 1.2f));
        bed(bdfram, bdbody, bdfoam, blankt, lightingShaderWithTexture, translateMatrix * rotateYMatrix * scaleMatrix);
        //almira
        translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0-20, 12.7, 66.0));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        almira(bdbody, alm, lightingShaderWithTexture, translateMatrix * rotateYMatrix);

        //sidetable
        translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0-17, 12.7, 66.0 ));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.2, 0.8f, 1.0f));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        sidetable(cusion, pillar_c, lightingShaderWithTexture, translateMatrix * rotateYMatrix *scaleMatrix);


        //dressing table
        translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0-19.0, 12.7, 66.0 - 12.5));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.2, 1.0f, 1.3f));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        dressing(blankt, glass, bdbody, mirror, lightingShaderWithTexture, translateMatrix * rotateYMatrix * scaleMatrix);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0-8.0, 12.7, 57.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.85, 1.0f, 0.6f));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        sofa3(bdfram, cusion, lightingShaderWithTexture, translateMatrix* rotateYMatrix* scaleMatrix);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0-12.5, 12.7, 59.5));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f), glm::vec3(0.0f, -1.0f, 0.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0, 0.8f, 1.0f));
        teatable(tab_gls, ch_f, lightingShaderWithTexture, translateMatrix* rotateYMatrix* scaleMatrix);


        //theater room
        translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0+14.0, 12.7, 16.0+9.0));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0, 1.0f, 0.8f));
        sofa2(cusion, sofa1,mat, lightingShaderWithTexture, translateMatrix* rotateYMatrix* scaleMatrix);


        translateMatrix = glm::translate(identityMatrix, glm::vec3(5.2+22.0, 12.7, 15+13.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.7, 1.1f, 0.7f));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        sidetable(cusion, pillar_c, lightingShaderWithTexture, translateMatrix* rotateYMatrix*scaleMatrix);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
        projector(mat, pillar_c, lightingShaderWithTexture, translateMatrix);
        
        //curt
        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
        //curtainsr1(curt, lightingShaderWithTexture, translateMatrix);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
       // curtains2r1(curt, lightingShaderWithTexture, translateMatrix);
        if (watr_tap) {
            if (tap < -4.0) {
                tap = -4.0;
            }
            tap -= 0.1;
            translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 3.0, 2.2 + 3.0 + 1.2, 47.0 - 3.4));
            scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.15, 0.5*tap, 0.08f));
            tapwater(water, lightingShaderWithTexture,translateMatrix*scaleMatrix);
           
        }
        else {
            if (tap > 1.0) {
                tap = 1.0;
            }
            tap += .1;     
            translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 +3.0, 2.2 + 3.0 + 1.2, 47.0 - 3.4));
            scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.15, 0.05 , 0.08f));
            tapwater(water, lightingShaderWithTexture, translateMatrix * scaleMatrix);
        }

        if (scl) {
            if (scaling < 0.2) {
                scaling = 0.2;
            }
            scaling -= 0.01;
            translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
            scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0, scaling, 0.7f));
            projectorslide(projc, lightingShaderWithTexture, glm::translate(identityMatrix, glm::vec3(5.0 + 25.15, 20.7, 18.1)) * scaleMatrix * glm::translate(identityMatrix, glm::vec3(-5.0 - 25.15, -20.7, -18.1)));


            //back
            translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
            scaleMatrix = glm::scale(identityMatrix, glm::vec3(scaling,1.0, 1.0f));
            model = glm::translate(identityMatrix, glm::vec3(5.0 + 2.4, 13.7, 15.65))*scaleMatrix* glm::translate(identityMatrix, glm::vec3(-5.0 - 2.4, -13.7, -15.65));
            curtains(curt, lightingShaderWithTexture, model);

            translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
            scaleMatrix = glm::scale(identityMatrix, glm::vec3(scaling, 1.0, 1.0f));
            model = glm::translate(identityMatrix, glm::vec3(5.0 + 2.4, 13.0, 59.8)) * scaleMatrix * glm::translate(identityMatrix, glm::vec3(-5.0 - 2.4, -13.0, -59.8));
            curtainsr1(curt, lightingShaderWithTexture, model);

            translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
            scaleMatrix = glm::scale(identityMatrix, glm::vec3(scaling, 1.0, 1.0f));
            model = glm::translate(identityMatrix, glm::vec3(45.0 - 11.1, 13.0, 15.0 + 6.0)) * scaleMatrix * glm::translate(identityMatrix, glm::vec3(-45.0 + 11.1, -13.0, -15.0 - 6.0));
            curtainsr3(curt, lightingShaderWithTexture, model);

            if (scaling2 < 0.2) {
                scaling2 = 0.2;
            }
            scaling2 -= 0.01;
            translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
            //rotateYMatrix = glm::rotate(identityMatrix, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            scaleMatrix = glm::scale(identityMatrix, glm::vec3(scaling2, 1.0, 1.0f));
            model = glm::translate(identityMatrix, glm::vec3(5.0 + 2.4+8.1, 13.7, 15.65)) * scaleMatrix * glm::translate(identityMatrix, glm::vec3(-5.0 - 2.4-8.1, -13.7, -15.65));
            curtains2(curt, lightingShaderWithTexture, model);
            translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
            //rotateYMatrix = glm::rotate(identityMatrix, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            scaleMatrix = glm::scale(identityMatrix, glm::vec3(scaling2, 1.0, 1.0f));
            model = glm::translate(identityMatrix, glm::vec3(5.0 + 2.4 + 10.2, 13.0, 59.8)) * scaleMatrix * glm::translate(identityMatrix, glm::vec3(-5.0 - 2.4 - 10.2, -13.0, -59.8));
            curtains2r1(curt, lightingShaderWithTexture, model);
             translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
            //rotateYMatrix = glm::rotate(identityMatrix, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            scaleMatrix = glm::scale(identityMatrix, glm::vec3(scaling2, 1.0, 1.0f));
            model = glm::translate(identityMatrix, glm::vec3(45.0 - 11.1 + 8.2, 13.0, 15.0 + 6.0)) * scaleMatrix * glm::translate(identityMatrix, glm::vec3(-45.0 + 11.1 - 8.2, -13.0, -15.0 - 6.0));
            curtains2r3(curt, lightingShaderWithTexture, model);


        }
        else {
            if (scaling > 1.0) {
                scaling = 1.0;
            }
            scaling += 0.01;
            translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
            scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0, scaling, 0.7f));
            projectorslide(projc, lightingShaderWithTexture, glm::translate(identityMatrix, glm::vec3(5.0 + 25.15, 20.7, 18.1))* scaleMatrix* glm::translate(identityMatrix, glm::vec3(-5.0 - 25.15, -20.7, -18.1)));


            translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
            scaleMatrix = glm::scale(identityMatrix, glm::vec3(scaling, 1.0, 1.0f));
            model = glm::translate(identityMatrix, glm::vec3(5.0 + 2.4, 13.7, 15.65)) * scaleMatrix * glm::translate(identityMatrix, glm::vec3(-5.0 - 2.4, -13.7, -15.65));
            curtains(curt, lightingShaderWithTexture, model);

            translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
            scaleMatrix = glm::scale(identityMatrix, glm::vec3(scaling, 1.0, 1.0f));
            model = glm::translate(identityMatrix, glm::vec3(5.0 + 2.4, 13.0, 59.8)) * scaleMatrix * glm::translate(identityMatrix, glm::vec3(-5.0 - 2.4, -13.0, -59.8));
            curtainsr1(curt, lightingShaderWithTexture, model);

             translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
            scaleMatrix = glm::scale(identityMatrix, glm::vec3(scaling, 1.0, 1.0f));
            model = glm::translate(identityMatrix, glm::vec3(45.0 - 11.1, 13.0, 15.0 + 6.0)) * scaleMatrix * glm::translate(identityMatrix, glm::vec3(-45.0 + 11.1, -13.0, -15.0 - 6.0));
            curtainsr3(curt, lightingShaderWithTexture, model);

            if (scaling2>1.0) {
                scaling2 = 1.0;
            }
            scaling2 += 0.01;
            translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
            scaleMatrix = glm::scale(identityMatrix, glm::vec3(scaling2, 1.0, 1.0f));
            model = glm::translate(identityMatrix, glm::vec3(5.0 + 2.4+8.2, 13.7, 15.65)) * scaleMatrix * glm::translate(identityMatrix, glm::vec3(-5.0 - 2.4-8.2, -13.7, -15.65));
            curtains2(curt, lightingShaderWithTexture, model);
            translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
            //rotateYMatrix = glm::rotate(identityMatrix, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            scaleMatrix = glm::scale(identityMatrix, glm::vec3(scaling2, 1.0, 1.0f));
            model = glm::translate(identityMatrix, glm::vec3(5.0 + 2.4 + 10.2, 13.0, 59.8)) * scaleMatrix * glm::translate(identityMatrix, glm::vec3(-5.0 - 2.4 - 10.2, -13.0, -59.8));
            curtains2r1(curt, lightingShaderWithTexture, model);

            translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
            //rotateYMatrix = glm::rotate(identityMatrix, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            scaleMatrix = glm::scale(identityMatrix, glm::vec3(scaling2, 1.0, 1.0f));
            model = glm::translate(identityMatrix, glm::vec3(45.0 - 11.1 + 8.2, 13.0, 15.0 + 6.0)) * scaleMatrix * glm::translate(identityMatrix, glm::vec3(-45.0 + 11.1 - 8.2, -13.0, -15.0 - 6.0));
            curtains2r3(curt, lightingShaderWithTexture, model);

        }
      
         //back rooms
        translateMatrix = glm::translate(identityMatrix, glm::vec3(5.5, 12.7, 25.5));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.2, 1.0f, 1.2f));
        bed(bed_head, bdbody, bdfoam_g, sofa_s, lightingShaderWithTexture, translateMatrix * rotateYMatrix * scaleMatrix);
        
        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
        rg(wdr, bdbody,cab, lightingShaderWithTexture, translateMatrix);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(1.0, 2.5, 4.5));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.8, 0.8f, 0.8f));
        g_tab(bdfram,bdfoam_g,cusion,sofa_s, lightingShaderWithTexture, translateMatrix* scaleMatrix);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(5.5, 12.7, 36.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.6, 0.8f, 0.5f));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        sofa3(bed_head, bed_head, lightingShaderWithTexture, translateMatrix * rotateYMatrix * scaleMatrix);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0+12.9, 12.7+4.0, 25.0));
        rgg(mirr_g, bdfram,toys, toys, lightingShaderWithTexture, translateMatrix);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 13.0, 12.7, 29.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0, 1.0f, 1.0f));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        sidetable(bdfoam_g, pillar_c, lightingShaderWithTexture, translateMatrix * scaleMatrix * rotateYMatrix);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(9.5, 12.7, 32.5));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0, 1.0f, 1.0f));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, -1.0f, 0.0f));
        sqtable(bdfram, bdfoam_g, lightingShaderWithTexture, translateMatrix * rotateYMatrix * scaleMatrix);


        //backright
        translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0-0.3, 12.7, 15.0+18.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.7, 1.0f, 1.0f));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        rack(cab, file, books, lightingShaderWithTexture, translateMatrix*rotateYMatrix*scaleMatrix);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0 - 10.0, 12.7, 15.0 + 19.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.7, 1.0f, 1.5f));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        rack(cab, file, books, lightingShaderWithTexture, translateMatrix * rotateYMatrix * scaleMatrix);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0-6.0, 12.7, 22.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.4, 1.0f, 0.5f));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(27.0f), glm::vec3(0.0f, -1.0f, 0.0f));
        sofa3(bdfram, cusion, lightingShaderWithTexture, translateMatrix * rotateYMatrix * scaleMatrix);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0 - 2.5, 12.7, 24.5));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.4, 1.0f, 0.5f));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(75.0f), glm::vec3(0.0f, -1.0f, 0.0f));
        sofa3(bdfram, cusion, lightingShaderWithTexture, translateMatrix * rotateYMatrix * scaleMatrix);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0, 1.0f, 1.0f));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(0.0f), glm::vec3(0.0f, -1.0f, 0.0f));
        gym(blacktl, pillar_c, lightingShaderWithTexture, translateMatrix* rotateYMatrix* scaleMatrix);

       

        if (trd) {

            trdml = trdml + 0.005;
            if (trdml>=0.2) {
                trdml = 0.0;
            }

           
            treadmill(cube, pillar_c, lightingShaderWithTexture,trdml);

        }
        else {
            translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
            scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0, 1.0f, 1.0f));
            //rotateYMatrix = glm::rotate(identityMatrix, glm::radians(trdml), glm::vec3(0.0f, 1.0f, 0.0f));
           // model = glm::translate(identityMatrix, glm::vec3(45.0 - 13.0 + 1.25, 14.7 + 0.3, 22.0 + 2.0)) *rotateYMatrix* glm::translate(identityMatrix, glm::vec3(-45.0 + 13.0 -1.25, -14.7 - 0.3, -22.0 - 2.0));
            treadmill(cube, pillar_c, lightingShaderWithTexture,trdml);
        }
        
    
        if (windopn) {
            if (w > 90.0f) {
                w = 90.0f;
            }
            w += 0.1;

      
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(w), glm::vec3(0.0f, 1.0f, 0.0f));
            model = glm::translate(identityMatrix, glm::vec3(5.0 + 2.25, 12.7, 15.0)) *rotateYMatrix* glm::translate(identityMatrix, glm::vec3(-5.0 - 2.25, -12.7, -15.0));
            window_2nd(wind_c, lightingShaderWithTexture, model);
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(w), glm::vec3(0.0f, -1.0f, 0.0f));
            model = glm::translate(identityMatrix, glm::vec3(5.0 + 2.25 + 8.0, 12.7 + 3.0, 15.0)) * rotateYMatrix * glm::translate(identityMatrix, glm::vec3(-5.0 - 2.25 - 8.0, -12.7 - 3.0, -15.0));
            window_2nd2(wind_c, lightingShaderWithTexture, model);

            //kit
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(w), glm::vec3(0.0f, 1.0f, 0.0f));
            model = glm::translate(identityMatrix, glm::vec3(5.0 + 11.0, 2.2 + 3.0, 15.0)) * rotateYMatrix * glm::translate(identityMatrix, glm::vec3(-5.0 - 11.0, -2.2 - 3.0, -15.0));
            window_2ndg(wind_c, lightingShaderWithTexture, model);
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(w), glm::vec3(0.0f, -1.0f, 0.0f));
            model = glm::translate(identityMatrix, glm::vec3(5.0 + 11.0 + 8.0, 2.2 + 3.0, 15.0)) * rotateYMatrix * glm::translate(identityMatrix, glm::vec3(-5.0 - 11.0 - 8.0, -2.2 - 3.0, -15.0));
            window_2ndg2(wind_c, lightingShaderWithTexture, model);

            //front
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(w), glm::vec3(0.0f, -1.0f, 0.0f));
            model = glm::translate(identityMatrix, glm::vec3(45.0 - 6.0 - 13.0, 12.7 + 3.0, 66.0)) * rotateYMatrix * glm::translate(identityMatrix, glm::vec3(-45.0 + 6.0 + 13.0, -12.7 - 3.0, -66.0));
            window_2ndf(wind_c, lightingShaderWithTexture, model);
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(w), glm::vec3(0.0f, 1.0f, 0.0f));
            model = glm::translate(identityMatrix, glm::vec3(45.0 - 6.0 - 5.0, 12.7 + 3.0, 66.0)) * rotateYMatrix * glm::translate(identityMatrix, glm::vec3(-45.0 + 6.0 + 5.0, -12.7 - 3.0, -66.0));
            window_2ndf2(wind_c, lightingShaderWithTexture, model);


        }
        else {
            if (w < 0.0) {
                w = 0.0f;
            }
            w -= 0.1;

           
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(w), glm::vec3(0.0f, 1.0f, 0.0f));
            model = glm::translate(identityMatrix, glm::vec3(5.0 + 2.25, 12.7, 15.0)) * rotateYMatrix * glm::translate(identityMatrix, glm::vec3(-5.0 - 2.25, -12.7, -15.0));
            window_2nd(wind_c, lightingShaderWithTexture, model);
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(w), glm::vec3(0.0f, -1.0f, 0.0f));
            model = glm::translate(identityMatrix, glm::vec3(5.0 + 2.25 + 8.0, 12.7 + 3.0, 15.0)) * rotateYMatrix * glm::translate(identityMatrix, glm::vec3(-5.0 - 2.25 - 8.0, -12.7 - 3.0, -15.0));
            window_2nd2(wind_c, lightingShaderWithTexture, model);

            //kit
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(w), glm::vec3(0.0f, 1.0f, 0.0f));
            model = glm::translate(identityMatrix, glm::vec3(5.0 + 11.0, 2.2 + 3.0, 15.0)) * rotateYMatrix * glm::translate(identityMatrix, glm::vec3(-5.0 - 11.0, -2.2 - 3.0, -15.0));
            window_2ndg(wind_c, lightingShaderWithTexture, model);
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(w), glm::vec3(0.0f, -1.0f, 0.0f));
            model = glm::translate(identityMatrix, glm::vec3(5.0 + 11.0+8.0, 2.2 + 3.0, 15.0)) * rotateYMatrix * glm::translate(identityMatrix, glm::vec3(-5.0 - 11.0-8.0, -2.2 - 3.0, -15.0));
            window_2ndg2(wind_c, lightingShaderWithTexture, model);

            //
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(w), glm::vec3(0.0f, -1.0f, 0.0f));
            model = glm::translate(identityMatrix, glm::vec3(45.0 - 6.0 - 13.0, 12.7 + 3.0, 66.0)) * rotateYMatrix * glm::translate(identityMatrix, glm::vec3(-45.0 + 6.0 + 13.0, -12.7 - 3.0, -66.0));
            window_2ndf(wind_c, lightingShaderWithTexture, model);
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(w), glm::vec3(0.0f, 1.0f, 0.0f));
            model = glm::translate(identityMatrix, glm::vec3(45.0 - 6.0 - 5.0, 12.7 + 3.0, 66.0)) * rotateYMatrix * glm::translate(identityMatrix, glm::vec3(-45.0 + 6.0 + 5.0, -12.7 - 3.0, -66.0));
            window_2ndf2(wind_c, lightingShaderWithTexture, model);
        }

        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
        wall(wall_cube, door_p,wdwall, lightingShaderWithTexture, translateMatrix);
        
      
        //railing
        translateMatrix = glm::translate(identityMatrix, glm::vec3(26.6, 12.7, 35.0));
        railing(sofa_f, ch_f, lightingShaderWithTexture, translateMatrix);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0 - 8.5, 2.2, 54.5));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f), glm::vec3(0.0f, -1.0f, 0.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0, 0.8f, 1.0f));
        teatable(tab_gls, ch_f, lightingShaderWithTexture, translateMatrix * rotateYMatrix * scaleMatrix);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0 - 5.5, 2.2, 48.0));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, -1.0f, 0.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0, 1.25f, 1.4f));
        sidetable(cusion, ch_f, lightingShaderWithTexture, translateMatrix * rotateYMatrix * scaleMatrix);

        //1st floor
        //office
        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
        office(bdfram,bdfoam,lightingShaderWithTexture, translateMatrix);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(11.5, 2.2, 29.0));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        offchair(sofa1, pillar_c, lightingShaderWithTexture, translateMatrix * rotateYMatrix);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(13.0, 2.2, 41.5));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.7, 0.8f, 0.6f));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        sofa3(bdfram, cusion, lightingShaderWithTexture, translateMatrix * rotateYMatrix * scaleMatrix);

        //rack
        translateMatrix = glm::translate(identityMatrix, glm::vec3(5.5, 2.2, 36.0));
        rack(cab,file, books, lightingShaderWithTexture, translateMatrix);
        

        //sofa
        translateMatrix = glm::translate(identityMatrix, glm::vec3(44.0, 2.2, 61.0-10.5));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, -1.0f, 0.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0, 1.0f, 0.8f));
        sofa(sofa_f,sofa1,lightingShaderWithTexture,translateMatrix * rotateYMatrix* scaleMatrix);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(33.5, 0.0, 60.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0, 1.0f, 0.7f));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        sofa5(sofa_f, sofa1, mat, lightingShaderWithTexture, translateMatrix* rotateYMatrix * scaleMatrix);


        translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0 - 1.0, 2.2, 24.0));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, -1.0f, 0.0f));
        model = translateMatrix * rotateYMatrix;
        sofa2(cusion, sofa1,mat, lightingShaderWithTexture, model);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
        sofa4(sofa_f, sofa1,mat, lightingShaderWithTexture, translateMatrix);

        //doors
        if (rdoor) {
            drm += 0.5;
            if (drm > 90.0f) {
                drm = 90.0;
            }
            //main_door
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(drm), glm::vec3(0.0f, -1.0f, 0.0f));
            model = glm::translate(identityMatrix, glm::vec3(5.0 + 14.0 + 3.0 + 4.0, 2.2, 61.0)) * rotateYMatrix * glm::translate(identityMatrix, glm::vec3(-5.0 - 14.0 - 3.0 - 4.0, -2.2, -61.0));
            main_door(m_door, lightingShaderWithTexture, model);

            //r1
            translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(drm), glm::vec3(0.0f, 1.0f, 0.0f));
            model = glm::translate(identityMatrix, glm::vec3(5.0 + 10.3+3.67, 2.2, 47.0 + 6.0)) * rotateYMatrix* glm::translate(identityMatrix, glm::vec3(-5.0 - 10.3-3.67, -2.2, -47.0 - 6.0));
            doors1(rmdoor, lightingShaderWithTexture, model);
            //washrm
            translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(drm), glm::vec3(0.0f, -1.0f, 0.0f));
            model = glm::translate(identityMatrix, glm::vec3(5.0 + 10.0, 2.2, 47.0-4.5)) * rotateYMatrix * glm::translate(identityMatrix, glm::vec3(-5.0 - 10.0, -2.2, -47.0+4.5));
            doors2(rmdoor, lightingShaderWithTexture, model);
            
            translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(drm), glm::vec3(0.0f, 1.0f, 0.0f));
            model = glm::translate(identityMatrix, glm::vec3(45.0 - 8.7, 12.7, 66.0 - 13.0)) * rotateYMatrix * glm::translate(identityMatrix, glm::vec3(-45.0 + 8.7, -12.7, -66.0 + 13.0));
            doors6(rmdoor, lightingShaderWithTexture, model);

            //2nd1
            translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(drm), glm::vec3(0.0f, -1.0f, 0.0f));
            model = glm::translate(identityMatrix, glm::vec3(45.0 - 14.0, 12.7, 66.0 - 13.0)) * rotateYMatrix * glm::translate(identityMatrix, glm::vec3(-45.0 + 14.0, -12.7, -66.0 + 13.0));
            doors4(rmdoor, lightingShaderWithTexture, model);
            //2
            translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(drm), glm::vec3(0.0f, -1.0f, 0.0f));
            model = glm::translate(identityMatrix, glm::vec3(5.0 + 13.0, 12.7, 66.0 - 18.0)) * rotateYMatrix * glm::translate(identityMatrix, glm::vec3(-5.0 - 13.0, -12.7, -66.0 + 18.0));
            doors3(rmdoor, lightingShaderWithTexture, model);
            //3
            //2
            translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(drm), glm::vec3(0.0f, -1.0f, 0.0f));
            model = glm::translate(identityMatrix, glm::vec3(5.0 + 13.0, 12.7, 15.0 + 18.0)) * rotateYMatrix * glm::translate(identityMatrix, glm::vec3(-5.0 - 13.0, -12.7, -15.0 - 18.0));
            doors5(rmdoor, lightingShaderWithTexture, model);
        }
        else {
            drm -= 0.5;
            if (drm <  0.0f) {
                drm = 0.0;
            }
            //main_door
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(drm), glm::vec3(0.0f, -1.0f, 0.0f));
            model = glm::translate(identityMatrix, glm::vec3(5.0 + 14.0 + 3.0 + 4.0, 2.2, 61.0)) * rotateYMatrix * glm::translate(identityMatrix, glm::vec3(-5.0 - 14.0 - 3.0 - 4.0, -2.2, -61.0));
            main_door(m_door, lightingShaderWithTexture, model);

            //r1
            translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(drm), glm::vec3(0.0f, 1.0f, 0.0f));
            model = glm::translate(identityMatrix, glm::vec3(5.0 + 10.3 + 3.67, 2.2, 47.0 + 6.0)) * rotateYMatrix * glm::translate(identityMatrix, glm::vec3(-5.0 - 10.3 - 3.67, -2.2, -47.0 - 6.0));
            doors1(rmdoor, lightingShaderWithTexture, model);
            //washrm
            translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(drm), glm::vec3(0.0f, -1.0f, 0.0f));
            model = glm::translate(identityMatrix, glm::vec3(5.0 + 10.0, 2.2, 47.0 - 4.5)) * rotateYMatrix * glm::translate(identityMatrix, glm::vec3(-5.0 - 10.0, -2.2, -47.0 + 4.5));
            doors2(rmdoor, lightingShaderWithTexture, model);
            translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(drm), glm::vec3(0.0f, 1.0f, 0.0f));
            model = glm::translate(identityMatrix, glm::vec3(45.0 - 8.7, 12.7, 66.0 - 13.0)) * rotateYMatrix * glm::translate(identityMatrix, glm::vec3(-45.0 + 8.7, -12.7, -66.0 + 13.0));
            doors6(rmdoor, lightingShaderWithTexture, model);

            //2nd1
            translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(drm), glm::vec3(0.0f, -1.0f, 0.0f));
            model = glm::translate(identityMatrix, glm::vec3(45.0 - 14.0, 12.7, 66.0 - 13.0)) * rotateYMatrix * glm::translate(identityMatrix, glm::vec3(-45.0 + 14.0, -12.7, -66.0 + 13.0));
            doors4(rmdoor, lightingShaderWithTexture, model);
            //2
            translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(drm), glm::vec3(0.0f, -1.0f, 0.0f));
            model = glm::translate(identityMatrix, glm::vec3(5.0 + 13.0, 12.7, 66.0 - 18.0)) * rotateYMatrix * glm::translate(identityMatrix, glm::vec3(-5.0 - 13.0, -12.7, -66.0 + 18.0));
            doors3(rmdoor, lightingShaderWithTexture, model);
            //3
            translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(drm), glm::vec3(0.0f, -1.0f, 0.0f));
            model = glm::translate(identityMatrix, glm::vec3(5.0 + 13.0, 12.7, 15.0 +18.0)) * rotateYMatrix * glm::translate(identityMatrix, glm::vec3(-5.0 - 13.0, -12.7, -15.0 - 18.0));
            doors5(rmdoor, lightingShaderWithTexture, model);
        }

        //2nd
        
        //dinning+kitchen
        //table
        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0 ));
        table(sofa_f, ch_f, lightingShaderWithTexture, translateMatrix);
        //chair
        translateMatrix = glm::translate(identityMatrix, glm::vec3(20.5, 2.2 , 29.0));
        chair(sofa_f,ch_f, lightingShaderWithTexture, translateMatrix);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(20.5+2.3, 2.2, 29.0));
        chair(sofa_f, ch_f, lightingShaderWithTexture, translateMatrix);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(20.5 + 2.3, 2.2, 26.0));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        chair(sofa_f, ch_f, lightingShaderWithTexture, translateMatrix* rotateYMatrix);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(20.5 + 2.3+2.3, 2.2, 26.0));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        chair(sofa_f, ch_f, lightingShaderWithTexture, translateMatrix * rotateYMatrix);

        //cabinet
        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0,0.0,0.0));
        cabinet(cab,frz,oven, pillar_c, lightingShaderWithTexture, translateMatrix);
         
        
        //bed
        translateMatrix = glm::translate(identityMatrix, glm::vec3(6.0, 2.2, 66.0 - 8.0));
        bed(bdfram, bdbody, bdfoam, blankt, lightingShaderWithTexture, translateMatrix);
        //almira
        translateMatrix = glm::translate(identityMatrix, glm::vec3(10.0, 2.2, 66.0 - 12.5));
        almira(bdbody, alm,lightingShaderWithTexture, translateMatrix);
         
        //dressing table
        translateMatrix = glm::translate(identityMatrix, glm::vec3(18.7, 2.2, 66.0 - 3.7));
        dressing(blankt, glass, bdbody,mirror, lightingShaderWithTexture, translateMatrix);

        //tvtable
        
        translateMatrix = glm::translate(identityMatrix, glm::vec3(18.0, 2.2, 66.0-8.5));
        tvtable(blankt, bdbody,lightingShaderWithTexture, translateMatrix);

        //pool
        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
        pool(floor, water,sofa_f, lightingShaderWithTexture, translateMatrix);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0-11.5, 2.2+4.0, 47.65));
        fmat(vtv, lightingShaderWithTexture, translateMatrix);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0 - 0.6, 2.2 + 4.5, 47.0 + 6.0));
       paintings(paintw, lightingShaderWithTexture, translateMatrix);

        //lawn
        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
        lawn(lawn_cube,bound,road_m,lightingShaderWithTexture, translateMatrix);

        tree(stree,tree_w, lightingShaderWithTexture, translateMatrix);
     
         translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
         tree(stree, tree_w, lightingShaderWithTexture, translateMatrix);
         tree2(stree, tree_w, lightingShaderWithTexture, translateMatrix);
         //garden(carwind,toys2,lightingShaderWithTexture, translateMatrix);
        //car
        if (car_strt) {
            carmove += 0.05;
            z = z - 1.3;
            if (carmove> 20.0) {
                carmove = 20.0;
                z = 0.0;
            }
            translateMatrix = glm::translate(identityMatrix, glm::vec3(carmove, 0.0, 0.0));
            car(carbd, water, steel_c, lightingShaderWithTexture, translateMatrix);

            translateMatrix = glm::translate(identityMatrix, glm::vec3(carmove, 0.0, 0.0));
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(z), glm::vec3(0.0f, 0.0f, 1.0f));
            model = translateMatrix*glm::translate(identityMatrix, glm::vec3(21.5 + 5.0 - 15.0, 1.0, 75.0 + 4.0 + 10.0)) *rotateYMatrix*glm::translate(identityMatrix, glm::vec3(-21.5 - 5.0 + 15.0, -1.0, -75.0 - 4.0 - 10.0));
            carw1(floor, stree, steel_c, lightingShaderWithTexture, model);
           
            translateMatrix = glm::translate(identityMatrix, glm::vec3(carmove, 0.0, 0.0));
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(z), glm::vec3(0.0f, 0.0f, 1.0f));
            model = translateMatrix * glm::translate(identityMatrix, glm::vec3(21.5 + 5.0 - 15.0, 1.0, 75.0 + 10.0)) * rotateYMatrix * glm::translate(identityMatrix, glm::vec3(-21.5 - 5.0 + 15.0, -1.0, -75.0 - 10.0));
            carw2(floor, stree, steel_c, lightingShaderWithTexture, model);

            translateMatrix = glm::translate(identityMatrix, glm::vec3(carmove, 0.0, 0.0));
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(z), glm::vec3(0.0f, 0.0f, 1.0f));
            model = translateMatrix * glm::translate(identityMatrix, glm::vec3(21.5 - 15.0, 1.0, 75.0 + 4.0 + 10.0)) * rotateYMatrix * glm::translate(identityMatrix, glm::vec3(-21.5 + 15.0, -1.0, -75.0 - 4.0 - 10.0));
            carw3(floor, stree, steel_c, lightingShaderWithTexture, model);

            translateMatrix = glm::translate(identityMatrix, glm::vec3(carmove, 0.0, 0.0));
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(z), glm::vec3(0.0f, 0.0f, 1.0f));
            model = translateMatrix * glm::translate(identityMatrix, glm::vec3(21.5 - 15.0, 1.0, 75.0 + 10.0)) * rotateYMatrix * glm::translate(identityMatrix, glm::vec3(-21.5 + 15.0, -1.0, -75.0 - 10.0));
            carw4(floor, stree, steel_c, lightingShaderWithTexture, model);


            

        }
        else {
            z = z + 1.3;
            carmove -= 0.05;
            if (carmove < 0.0) {
                carmove = 0.0;
                z = 0.0;
            }
            translateMatrix = glm::translate(identityMatrix, glm::vec3(carmove, 0.0, 0.0));
            car(carbd, water, pillar_c, lightingShaderWithTexture, translateMatrix);

            translateMatrix = glm::translate(identityMatrix, glm::vec3(carmove, 0.0, 0.0));
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(z), glm::vec3(0.0f, 0.0f, 1.0f));
            model = translateMatrix * glm::translate(identityMatrix, glm::vec3(21.5 + 5.0 - 15.0, 1.0, 75.0 + 4.0 + 10.0)) * rotateYMatrix * glm::translate(identityMatrix, glm::vec3(-21.5 - 5.0 + 15.0, -1.0, -75.0 - 4.0 - 10.0));
            carw1(floor, stree, steel_c, lightingShaderWithTexture, model);
            translateMatrix = glm::translate(identityMatrix, glm::vec3(carmove, 0.0, 0.0));
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(z), glm::vec3(0.0f, 0.0f, 1.0f));
            model = translateMatrix * glm::translate(identityMatrix, glm::vec3(21.5 + 5.0 - 15.0, 1.0, 75.0 + 10.0)) * rotateYMatrix * glm::translate(identityMatrix, glm::vec3(-21.5 - 5.0 + 15.0, -1.0, -75.0 - 10.0));
            carw2(floor, stree, steel_c, lightingShaderWithTexture, model);

            translateMatrix = glm::translate(identityMatrix, glm::vec3(carmove, 0.0, 0.0));
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(z), glm::vec3(0.0f, 0.0f, 1.0f));
            model = translateMatrix * glm::translate(identityMatrix, glm::vec3(21.5 - 15.0, 1.0, 75.0 + 4.0 + 10.0)) * rotateYMatrix * glm::translate(identityMatrix, glm::vec3(-21.5 + 15.0, -1.0, -75.0 - 4.0 - 10.0));
            carw3(floor, stree, steel_c, lightingShaderWithTexture, model);

            translateMatrix = glm::translate(identityMatrix, glm::vec3(carmove, 0.0, 0.0));
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(z), glm::vec3(0.0f, 0.0f, 1.0f));
            model = translateMatrix * glm::translate(identityMatrix, glm::vec3(21.5 - 15.0, 1.0, 75.0 + 10.0)) * rotateYMatrix * glm::translate(identityMatrix, glm::vec3(-21.5 + 15.0, -1.0, -75.0 - 10.0));
            carw4(floor, stree, steel_c, lightingShaderWithTexture, model);

        }
       
        //fan
        if (fanmv) {
            fan_mv += 6.0;
            translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(fan_mv), glm::vec3(0.0f, 1.0f, 0.0f));
            model = glm::translate(identityMatrix, glm::vec3(25.0, 2.2 + 9.4, 25.5))*rotateYMatrix* glm::translate(identityMatrix, glm::vec3(-25.0, -2.2 - 9.4, -25.5));
            fan(floor, pillar_c, lightingShaderWithTexture,model);

        }
        else {
            translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
            fan(floor, pillar_c, lightingShaderWithTexture, translateMatrix);

        }
        

        //floor
        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
        base(floor,road,rpark,rroof, pillar_c,deck_c,lightingShaderWithTexture, translateMatrix);

   

        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
        washroom(blacktl, wtile,cmd,bdbody,lightingShaderWithTexture, translateMatrix);
       
        washingmachine(blacktl, toys2, lightingShaderWithTexture, translateMatrix);


        //stair
        translateMatrix = glm::translate(identityMatrix, glm::vec3(70.5, 5.5, 17.1));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        model =  translateMatrix * rotateYMatrix;
        stair(lightingShaderWithTexture, model, railng , stair_c);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(2.1, 0.0, 0.0));
        stair(lightingShaderWithTexture, translateMatrix,railng, stair_c);

        //roof
        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
        roof_f(bdbody,railng,lightingShaderWithTexture, translateMatrix);


        //window
        translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0 - 9.0, 2.2 + 10.0, 47.0 - 4.25));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.8, 0.875f, 1.0f));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        trans(sofa1, transp, lightingShaderWithTexture, translateMatrix * rotateYMatrix * scaleMatrix);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
        model = translateMatrix;
        r_window(wind_c, lightingShaderWithTexture, model);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
        model = translateMatrix;
        windows(wind1_c, lightingShaderWithTexture, model);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 2.5, 12.7, 66.0 - 6.0));
        trans(sofa1, transp, lightingShaderWithTexture, translateMatrix);
        //back
        translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 13.0 + 13.0 + 3.0, 12.7, 15.0 + 5.5));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.8, 1.0f, 1.0f));
        trans(sofa1, transp, lightingShaderWithTexture, translateMatrix* scaleMatrix);
        //ground
        translateMatrix = glm::translate(identityMatrix, glm::vec3(29.0 + 3.0, 2.2, 20.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0, 1.0f, 1.0f));
        trans(sofa1, transp, lightingShaderWithTexture, translateMatrix* scaleMatrix);
        //r2
        translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0 - 6.0, 12.7, 66.0 - 2.5-4.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.8, 1.0f, 1.0f));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        trans(sofa1, transp, lightingShaderWithTexture, translateMatrix* rotateYMatrix* scaleMatrix);
        
        //sliding
        if (winSlide) {
           
            x -= 0.01;
            if (x < -4) {
                x = -4;
            }
               
            
            translateMatrix = glm::translate(identityMatrix, glm::vec3(x, 0.0, 0.0));
            model = translateMatrix;
            window_slide(wind2_c,lightingShaderWithTexture, model);


            y -= 0.01;
            if (y < -4) {
                y = -4;
            }
            translateMatrix = glm::translate(identityMatrix, glm::vec3(y, 0.0, 0.0));
            model = translateMatrix;
            rs_window(wind_c, lightingShaderWithTexture, model);

            slide -= 0.01;
            if (slide < -5) {
                slide = -5;
            }
            //r1
            translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 2.5 + 5.0+slide, 12.7, 66.0 - 6.0));
            trans(sofa1, transp, lightingShaderWithTexture, translateMatrix);
            //r2
            translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0 - 6.0 , 12.7, 66.0 - 2.5+ y));
            scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.8, 1.0f, 1.0f));
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            trans(sofa1, transp, lightingShaderWithTexture, translateMatrix* rotateYMatrix*scaleMatrix);

            //back

            translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 13.0 + 13.0+7.0+y, 12.7, 15.0 + 5.5));
            scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.8, 1.0f, 1.0f));
            trans(sofa1, transp, lightingShaderWithTexture, translateMatrix*scaleMatrix);
        
            //ground
            translateMatrix = glm::translate(identityMatrix, glm::vec3(29.0+8.0+slide, 2.2, 20.0));
            scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0, 1.0f, 1.0f));
            trans(sofa1, transp, lightingShaderWithTexture, translateMatrix* scaleMatrix);

        }
        
        else {
            x += 0.01;
            if (x > 0.0) {
                x = 0.0;
            }
            
            translateMatrix = glm::translate(identityMatrix, glm::vec3(x, 0.0, 0.0));
            model = translateMatrix;
            window_slide(wind2_c, lightingShaderWithTexture, model);


            y += 0.01;
            if (y > 0.0) {
                y = 0.0;
            }

            translateMatrix = glm::translate(identityMatrix, glm::vec3(y, 0.0, 0.0));
            model = translateMatrix;
            rs_window(wind_c, lightingShaderWithTexture, model);

            slide += 0.01;
            if (slide > 0.0) {
                slide = 0.0;
            }

            translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 2.5 + 5.0 + slide, 12.7, 66.0 - 6.0));
            trans(sofa1, transp, lightingShaderWithTexture, translateMatrix);
            //back
            translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0 + 13.0 + 13.0 + 7.0 + y, 12.7, 15.0 + 5.5));
            scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.8, 1.0f, 1.0f));
            trans(sofa1, transp, lightingShaderWithTexture, translateMatrix * scaleMatrix);
            //ground
            translateMatrix = glm::translate(identityMatrix, glm::vec3(29.0 + 8.0+slide, 2.2, 20.0));
            scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0, 1.0f, 1.0f));
            trans(sofa1, transp, lightingShaderWithTexture, translateMatrix * scaleMatrix);
            //r2
            translateMatrix = glm::translate(identityMatrix, glm::vec3(45.0 - 6.0, 12.7, 66.0 - 2.5 + y));
            scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.8, 1.0f, 1.0f));
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            trans(sofa1, transp, lightingShaderWithTexture, translateMatrix * rotateYMatrix*scaleMatrix);


        }
  
        //swing
        //frame
        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
        frame(pillar_c, lightingShaderWithTexture, translateMatrix);

        if (dolna) {
            float angle = amplitude * sin(frequency * time);
            //swing(swing_c,lightingShaderWithTexture, translateMatrix);
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(angle), glm::vec3(0.0f, 0.0f, 1.0f));
            model = glm::translate(identityMatrix, glm::vec3(41.0, 8.0, 6.5)) * rotateYMatrix * glm::translate(identityMatrix, glm::vec3(-41.0, -8.0, -6.5));
            swing(swing_c, rope_c, lightingShaderWithTexture, model);
            time += 0.1;
        }
       
        else {
     
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
            model = glm::translate(identityMatrix, glm::vec3(41.0, 8.0, 6.5)) * rotateYMatrix * glm::translate(identityMatrix, glm::vec3(-41.0, -8.0,- 6.5));
            swing(swing_c, rope_c, lightingShaderWithTexture, model);
        }
        
       
        //main_gate
        if (door) {
            r += 0.2;
            if (r > 90.0f) {
                r = 90.0f;
           }
            //translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(r), glm::vec3(0.0f, 1.0f, 0.0f));
            model = glm::translate(identityMatrix, glm::vec3(20.0, 0.0, 96.0)) * rotateYMatrix * glm::translate(identityMatrix, glm::vec3(-20.0, -0.0, -96.0));
            main_gate(gate_m, lightingShaderWithTexture, model);
           
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(r), glm::vec3(0.0f, -1.0f, 0.0f));
            model = glm::translate(identityMatrix, glm::vec3(30.0, 0.0, 96.0)) * rotateYMatrix * glm::translate(identityMatrix, glm::vec3(-30.0, -0.0, -96.0));
            main_gate2(gate_m, lightingShaderWithTexture, model);

           

        }
        else if (!door)
        {
            r -= 0.2;
            if (r < 0.0f) {
                r = 0.0f;
            }
            translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(r), glm::vec3(0.0f, 1.0f, 0.0f));
            model = glm::translate(identityMatrix, glm::vec3(20.0, 0.0, 96.0)) * rotateYMatrix * glm::translate(identityMatrix, glm::vec3(-20.0, -0.0, -96.0));
            main_gate(gate_m, lightingShaderWithTexture, model);


            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(r), glm::vec3(0.0f, -1.0f, 0.0f));
            model = glm::translate(identityMatrix, glm::vec3(30.0, 0.0, 96.0)) * rotateYMatrix * glm::translate(identityMatrix, glm::vec3(-30.0, -0.0, -96.0));
            main_gate2(gate_m, lightingShaderWithTexture, model);

            //main_door
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(r), glm::vec3(0.0f, -1.0f, 0.0f));
            model = glm::translate(identityMatrix, glm::vec3(5.0 + 14.0 + 3.0 + 4.0, 2.2, 61.0)) * rotateYMatrix * glm::translate(identityMatrix, glm::vec3(-5.0 - 14.0 - 3.0 - 4.0, -2.2, -61.0));
           // main_door(m_door, lightingShaderWithTexture, model);
//
            
        }
      
        
        // also draw the lamp object(s)
        ourShader.use();
        ourShader.setMat4("projection", projection);
        ourShader.setMat4("view", view);

        // we now draw as many light bulbs as we have point lights.
        for (unsigned int i = 0; i < 2; i++)
        {
            model = glm::mat4(1.0f);
            model = glm::translate(model, pointLightPositions[i]);
            model = glm::scale(model, glm::vec3(0.2f)); // Make it a smaller cube
            cube.drawCube(ourShader, model, 0.8f, 0.8f, 0.8f);
        }

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------


    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        camera.ProcessKeyboard(FORWARD, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        camera.ProcessKeyboard(LEFT, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        camera.ProcessKeyboard(RIGHT, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {
        camera.ProcessKeyboard(UP, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {
        camera.ProcessKeyboard(DOWN, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS) {
        camera.ProcessKeyboard(P_UP, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS) {
        camera.ProcessKeyboard(P_DOWN, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS) {
        camera.ProcessKeyboard(Y_LEFT, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS) {
        camera.ProcessKeyboard(Y_RIGHT, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS) {
        camera.ProcessKeyboard(R_LEFT, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
        camera.ProcessKeyboard(R_RIGHT, deltaTime);
    }
    

}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
    {
        pointlight1.turnOn();
        pointlight3.turnOn();
    }
    if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
    {
        pointlight1.turnOff();
        pointlight3.turnOff();

    }
    if (glfwGetKey(window, GLFW_KEY_7) == GLFW_PRESS)
    {
        pointlight1.turnDiffuseOn();
        pointlight3.turnDiffuseOn();
        spotLight.turnDiffuseOn();
        dirLight.turnDiffuseOn();

    }
    if (glfwGetKey(window, GLFW_KEY_8) == GLFW_PRESS)
    {

        pointlight1.turnOff();
        pointlight3.turnOff();
        dirLight.turnOff();
        spotLight.turnOff();

    }

    if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS)
    {
        dirLight.turnOn();

    }
    if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS)
    {
        dirLight.turnOff();
    }
    if (glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS)
    {
        spotLight.turnOn();

    }
    if (glfwGetKey(window, GLFW_KEY_6) == GLFW_PRESS)
    {
        spotLight.turnOff();
    }
    if (glfwGetKey(window, GLFW_KEY_9) == GLFW_PRESS)
    {
        pointlight1.turnAmbientOn();
        pointlight3.turnAmbientOn();
        spotLight.turnAmbientOn();
        dirLight.turnAmbientOn();
    }
    if (glfwGetKey(window, GLFW_KEY_0) == GLFW_PRESS)
    {
        pointlight1.turnSpecularOn();
        pointlight3.turnSpecularOn();
        spotLight.turnSpecularOn();
        dirLight.turnSpecularOn();
    }


    if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS) {
        if (door) {
            door = false;
       }
        else {
            door = true;
        }
    }

    if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS) {
        if (dolna) {
            dolna = false;
        }
        else {
            dolna = true;
        }
    }

    if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS) {
        if (winSlide) {
            winSlide = false;
        }
        else {
            winSlide = true;
        }
    }
    if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS) {
        if (car_strt) {
            car_strt = false;
        }
        else {
           car_strt = true;
        }
    }

    if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS) {
        if (scl) {
            scl = false;
        }
        else {
            scl = true;
        }
    }


    if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS) {
        if (trd) {
            trd = false;
        }
        else {
            trd = true;
        }
    }

    if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS) {
        if (windopn) {
            windopn = false;
        }
        else {
            windopn = true;
        }
    }
    if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS) {
        if (rdoor) {
            rdoor = false;
        }
        else {
           rdoor = true;
        }
    }

    if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS) {
        if (fanmv) {
           fanmv = false;
        }
        else {
            fanmv = true;
        }
    }


    if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS) {
        if (watr_tap) {
            watr_tap = false;
        }
        else {
            watr_tap = true;
        }
    }

    if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS) {
        if (n8view) {
            n8view = false;
        }
        else {
            n8view = true;
        }
    }

}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}


// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);

    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(static_cast<float>(yoffset));
}


unsigned int loadTexture(char const* path, GLenum textureWrappingModeS, GLenum textureWrappingModeT, GLenum textureFilteringModeMin, GLenum textureFilteringModeMax)
{
    unsigned int textureID;
    glGenTextures(1, &textureID);

    int width, height, nrComponents;
    stbi_set_flip_vertically_on_load(true); //loading texture
    unsigned char* data = stbi_load(path, &width, &height, &nrComponents, 0); //call by referencing width, height, and then channels
    if (data)
    {
        GLenum format;
        if (nrComponents == 1)
            format = GL_RED;
        else if (nrComponents == 3)
            format = GL_RGB;
        else if (nrComponents == 4)
            format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data); //0->bitp level. if incresead the resolution will drop
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, textureWrappingModeS); //texturemapping and wrapping , along S axis
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, textureWrappingModeT); //for T axis
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, textureFilteringModeMin); //minification mode filter
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, textureFilteringModeMax);

        stbi_image_free(data);
    }
    else
    {
        std::cout << "Texture failed to load at path: " << path << std::endl;
        stbi_image_free(data);
    }

    //binding with texture id.

    return textureID;
}

// This function converts the screen coordinates to world coordinates
// ---------------------------------------------------------------------------------------------
void scsToWcs(float sx, float sy, float wcsv[3])
{

    glm::vec4 winCoordinateVector; //vector to hold screen x,y,z coordinates
    glm::vec4 worldCoordinateVector; //vector to hold world x,y,z coordinates

    glGetIntegerv(GL_VIEWPORT, viewport); //get the viewport info

    // setup screen coordinates values
    winCoordinateVector.x = sx;
    winCoordinateVector.y = (float)viewport[3] - (float)sy; // reversed since y-coordinates go from bottom to top
    winCoordinateVector.z = 0.0f;
    winCoordinateVector.w = 1.0f;

    // prepare viewport matrix
    float v_l = viewport[0], v_b = viewport[1], v_r = viewport[2], v_t = viewport[3];
    glm::mat4 viewportMat = glm::mat4(1.0f);
    viewportMat[0].x = (v_r - v_l) / 2.0f;  viewportMat[1].x = 0.0f; viewportMat[2].x = 0.0f;  viewportMat[3].x = (v_r + v_l) / 2.0f;
    viewportMat[0].y = 0.0f; viewportMat[1].y = (v_t - v_b) / 2.0f;  viewportMat[2].y = 0.0f;  viewportMat[3].y = (v_t + v_b) / 2.0f;
    viewportMat[0].z = 0.0f; viewportMat[1].z = 0.0f; viewportMat[2].z = 0.5f;  viewportMat[3].z = 0.5f;
    viewportMat[0].w = 0.0f; viewportMat[1].w = 0.0f; viewportMat[2].w = 0.0f;  viewportMat[3].w = 1.0f;

    //get the world coordinates from the screen coordinates
    worldCoordinateVector = glm::inverse(viewportMat * projection * view * model) * winCoordinateVector;
    wcsv[0] = worldCoordinateVector.x / worldCoordinateVector.w;
    wcsv[1] = worldCoordinateVector.y / worldCoordinateVector.w;
    wcsv[2] = worldCoordinateVector.z / worldCoordinateVector.w;
}

// glfw: whenever mouse button is pressed, this callback is called
// -------------------------------------------------------



long long nCr(int n, int r)
{
    if (r > n / 2)
        r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;

    for (i = 1; i <= r; i++)
    {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}

//polynomial interpretation for N points
void BezierCurve(double t, float xy[2], GLfloat ctrlpoints[], int L)
{
    double y = 0;
    double x = 0;
    t = t > 1.0 ? 1.0 : t;
    for (int i = 0; i < L + 1; i++)
    {
        long long ncr = nCr(L, i);
        double oneMinusTpow = pow(1 - t, double(L - i));
        double tPow = pow(t, double(i));
        double coef = oneMinusTpow * tPow * ncr;
        x += coef * ctrlpoints[i * 3];
        y += coef * ctrlpoints[(i * 3) + 1];

    }
    xy[0] = float(x);
    xy[1] = float(y);
}

unsigned int hollowBezier(GLfloat ctrlpoints[], int L)
{
    int i, j;
    float x, y, z, r;                //current coordinates
    float theta;
    float nx, ny, nz, lengthInv;    // vertex normal


    const float dtheta = 2 * pi / ntheta;        //angular step size

    float t = 0;
    float dt = 1.0 / nt;
    float xy[2];

    for (i = 0; i <= nt; ++i)              //step through y
    {
        BezierCurve(t, xy, ctrlpoints, L);
        r = xy[0];
        y = xy[1];
        theta = 0;
        t += dt;
        lengthInv = 1.0 / r;

        for (j = 0; j <= ntheta; ++j)
        {
            double cosa = cos(theta);
            double sina = sin(theta);
            z = r * cosa;
            x = r * sina;

            coordinates.push_back(x);
            coordinates.push_back(y);
            coordinates.push_back(z);

            // normalized vertex normal (nx, ny, nz)
            // center point of the circle (0,y,0)
            nx = (x - 0) * lengthInv;
            ny = (y - y) * lengthInv;
            nz = (z - 0) * lengthInv;

            normals.push_back(nx);
            normals.push_back(ny);
            normals.push_back(nz);

            theta += dtheta;
        }
    }

    // generate index list of triangles
    // k1--k1+1
    // |  / |
    // | /  |
    // k2--k2+1

    int k1, k2;
    for (int i = 0; i < nt; ++i)
    {
        k1 = i * (ntheta + 1);     // beginning of current stack
        k2 = k1 + ntheta + 1;      // beginning of next stack

        for (int j = 0; j < ntheta; ++j, ++k1, ++k2)
        {
            // k1 => k2 => k1+1
            indices.push_back(k1);
            indices.push_back(k2);
            indices.push_back(k1 + 1);

            // k1+1 => k2 => k2+1
            indices.push_back(k1 + 1);
            indices.push_back(k2);
            indices.push_back(k2 + 1);
        }
    }

    size_t count = coordinates.size();
    for (int i = 0; i < count; i += 3)
    {
        vertices.push_back(coordinates[i]);
        vertices.push_back(coordinates[i + 1]);
        vertices.push_back(coordinates[i + 2]);

        vertices.push_back(normals[i]);
        vertices.push_back(normals[i + 1]);
        vertices.push_back(normals[i + 2]);
    }

    unsigned int bezierVAO;
    glGenVertexArrays(1, &bezierVAO);
    glBindVertexArray(bezierVAO);

    // create VBO to copy vertex data to VBO
    unsigned int bezierVBO;
    glGenBuffers(1, &bezierVBO);
    glBindBuffer(GL_ARRAY_BUFFER, bezierVBO);           // for vertex data
    glBufferData(GL_ARRAY_BUFFER,                   // target
        (unsigned int)vertices.size() * sizeof(float), // data size, # of bytes
        vertices.data(),   // ptr to vertex data
        GL_STATIC_DRAW);                   // usage

    // create EBO to copy index data
    unsigned int bezierEBO;
    glGenBuffers(1, &bezierEBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bezierEBO);   // for index data
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,           // target
        (unsigned int)indices.size() * sizeof(unsigned int),             // data size, # of bytes
        indices.data(),               // ptr to index data
        GL_STATIC_DRAW);                   // usage

    // activate attrib arrays
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    // set attrib arrays with stride and offset
    int stride = 24;     // should be 24 bytes
    glVertexAttribPointer(0, 3, GL_FLOAT, false, stride, (void*)0);
    glVertexAttribPointer(1, 3, GL_FLOAT, false, stride, (void*)(sizeof(float) * 3));

    // unbind VAO, VBO and EBO
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    return bezierVAO;
}

