#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shaders/vertexshader.h"
#include "shaders/fragmentshader.h"
#include "scene.h"

Scene::Scene() {
    glfwInit();

    WM = new WindowManager();
    WM->init();

    // Init shader program
    const char *vShaderSrc, *fShaderSrc;
    vShaderSrc = VertexShader::getSource();
    fShaderSrc = FragmentShader::getSource();

    SM = new ShaderManager(vShaderSrc, fShaderSrc, NULL);

    camera = new Camera();

    IM = new InputManager(WM);
    IM->registerCamera(camera);

    model = glm::mat4(); // Identity
    projection = glm::perspective(glm::radians(45.0f), (float)800/(float)600, 0.1f, 100.0f);
}

Scene::~Scene() {
    delete IM;
    delete camera;
    delete SM;
    delete WM;
    glfwTerminate();
}

void Scene::run() {
    this->beforeRun();
    while(!WM->windowShouldClose())
    {
        this->handleInput();

        this->render();

        WM->swapBuffers();
        glfwPollEvents();    
    }
}

void Scene::beforeRun() {
    glEnable(GL_DEPTH_TEST);

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    float z = 0.0f;
    float sB = 0.6f;
    float sS = 0.2f;
    float dB = 0.424f;
    float dS = 0.141f;
    float d = 0.2f;
    float verticesChrys[] = {
        -sB,    z,  	d,
        -sS,    z,  	d,
        -dB,    dB, 	d,
        -dS,    dS, 	d,
        z,      sB, 	d,
        z,      sS, 	d,
        dB,     dB, 	d,
        dS,     dS, 	d,
        sB,     z,  	d,
        sS,     z,  	d,
        dB,     -dB, 	d,
        dS,     -dS, 	d,
        z,      -sB, 	d,
        z,      -sS, 	d,
        -dB,    -dB, 	d,
        -dS,    -dS,    d,

        -sB,    z,  	-d,
        -sS,    z,  	-d,
        -dB,    dB, 	-d,
        -dS,    dS, 	-d,
        z,      sB, 	-d,
        z,      sS, 	-d,
        dB,     dB, 	-d,
        dS,     dS, 	-d,
        sB,     z,  	-d,
        sS,     z,  	-d,
        dB,     -dB, 	-d,
        dS,     -dS, 	-d,
        z,      -sB, 	-d,
        z,      -sS, 	-d,
        -dB,    -dB, 	-d,
        -dS,    -dS,    -d
    };
    const unsigned int nTr = 16*4; // 2 faces and outer&inner fill
    const unsigned int nVert = 16*2;
    const unsigned int nInd = nTr * 3;
    unsigned int indicesChrys[nInd] = { };
    unsigned int v_offset;
    for (unsigned int i=0; i<nTr; i++) {
        if (i/16 == 0 || i/16 == 1) {
            // For the front & back faces, the only thing that changes is the vertexes used (first or last 16)
            // Front face : 0,2,1, 1,2,3, 2,4,3, 3,4,5, 4,6,5, 5,6,7 ...
            if (i/16 == 0) {
                // Drawing front face
                v_offset = 0;
            } else {
                // Drawing back face
                v_offset = 16;
            }
            if ((i % 2) == 0) {
                indicesChrys[3*i] = i%16 + v_offset;
                indicesChrys[3*i+1] = (i+2)%16 + v_offset;
                indicesChrys[3*i+2] = (i+1)%16 + v_offset;
            } else {
                indicesChrys[3*i] = i%16 + v_offset;
                indicesChrys[3*i+1] = (i+1)%16 + v_offset;
                indicesChrys[3*i+2] = (i+2)%16 + v_offset;
            }
        } else {
            // Drawing outer and inner faces
            // Outer : 0,16,2, 2,16,18, 2,18,4, 4,18,20 ... 14,30,0, 0,30,16
            // Inner : 1,17,3, 3,17,19, 3,19,5, 5,19,21 ... 15,31,1, 1,31,17
            if (i/16 == 2) {
                // Drawing outer face
                v_offset = 0;
            } else {
                // Drawing inner face
                v_offset = 1;
            }
            if ((i % 2) == 0) {
                indicesChrys[3*i] = i%16+v_offset;
                indicesChrys[3*i+1] = i%16+16+v_offset;
                indicesChrys[3*i+2] = (i+2)%16+v_offset;
            } else {
                indicesChrys[3*i] = (i+1)%16+v_offset;
                indicesChrys[3*i+1] = (i-1)%16+16+v_offset;
                indicesChrys[3*i+2] = (i+2-1)%16+16+v_offset;
            }
        }
    }

    unsigned int VBO, EBO = 0;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, nVert*3*sizeof(float), verticesChrys, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, nInd*sizeof(unsigned int), indicesChrys, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    // remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0); 
}

void Scene::render() {
    glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // Wireframe mode. To revert, set to GL_FILL

    SM->use();

    unsigned int modelLoc = glGetUniformLocation(SM->ID, "model");
    unsigned int viewLoc = glGetUniformLocation(SM->ID, "view");
    unsigned int projectionLoc = glGetUniformLocation(SM->ID, "projection");

    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(camera->lookAt()));
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

    glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
    glDrawElements(GL_TRIANGLES, 192, GL_UNSIGNED_INT, 0);
    // glBindVertexArray(0); // no need to unbind it every time 
}

void Scene::handleInput() {
    IM->handle();
}
