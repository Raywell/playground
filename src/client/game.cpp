#include <core/assets/mesh.h>
#include <vector>
#include "game.h"

Engine *E = NULL;

Game::Game() {
    E = new Engine(); // Creating Engine
}

Game::~Game() {
    E->release();
}

void Game::run() {

    WindowManager *windowM = E->getWindowManager();

    windowM->createRenderingWindow("Playground",800,600); // Create Window
    windowM->bindCloseWindowKeyAction(GLFW_KEY_ESCAPE, GLFW_PRESS); // Close button binding

    Camera *camera = new Camera(45.0f); // Creating Camera // TODO avoid new in client code

    Renderer *R = E->getRenderer();
    R->registerCamera(camera); // Registering Camera // TODO put inside the scenegraph ?

    SceneGraph *sGraph = E->getSceneGraph();
    SceneNode *root = sGraph->getRoot();

    // Building scenegraph
    root->addChild(camera); // Adding camera to root
    addDonut(root);
    sGraph->load();

    ShaderManager *shaderM = E->getShaderManager();
    shaderM->createProgram();
    std::map<ShaderType, std::vector<std::string>> shaders {
       { ShaderType::V, { VertexShader::getSource() } },
       { ShaderType::F, { FragmentShader::getSource() } }
    };
    shaderM->compileShaders(shaders);

    E->run();

    // DEBUG : Printing names of objects in graph
    sGraph->debug_printGraphObjects();

    // Cleanup
    camera->release();
}

void Game::addDonut(SceneNode *node) {
    auto assetM = E->getAssetManager();

    // Assets should go on heap
    Mesh *m_donut = assetM->registerAsset<Mesh>("m_donut", "");
    m_donut->setMeshType(MeshType::STATIC);

    // Test data
    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    float z = 0.0f;
    float sB = 0.6f;
    float sS = 0.2f;
    float dB = 0.424f;
    float dS = 0.141f;
    float d = 0.2f;
    std::vector<float> verticesChrys = {
        -sB,    z,      d,
        -sS,    z,      d,
        -dB,    dB,     d,
        -dS,    dS,     d,
        z,      sB,     d,
        z,      sS,     d,
        dB,     dB,     d,
        dS,     dS,     d,
        sB,     z,      d,
        sS,     z,      d,
        dB,     -dB,    d,
        dS,     -dS,    d,
        z,      -sB,    d,
        z,      -sS,    d,
        -dB,    -dB,    d,
        -dS,    -dS,    d,

        -sB,    z,      -d,
        -sS,    z,      -d,
        -dB,    dB,     -d,
        -dS,    dS,     -d,
        z,      sB,     -d,
        z,      sS,     -d,
        dB,     dB,     -d,
        dS,     dS,     -d,
        sB,     z,      -d,
        sS,     z,      -d,
        dB,     -dB,    -d,
        dS,     -dS,    -d,
        z,      -sB,    -d,
        z,      -sS,    -d,
        -dB,    -dB,    -d,
        -dS,    -dS,    -d
    };

/*
    verticesChrys.push_back(glm::vec3(-sB,    z,      d));
    verticesChrys.push_back(glm::vec3(-sS,    z,      d));
    verticesChrys.push_back(glm::vec3(-dB,    dB,     d));
    verticesChrys.push_back(glm::vec3(-dS,    dS,     d));
    verticesChrys.push_back(glm::vec3(z,      sB,     d));
    verticesChrys.push_back(glm::vec3(z,      sS,     d));
    verticesChrys.push_back(glm::vec3(dB,     dB,     d));
    verticesChrys.push_back(glm::vec3(dS,     dS,     d));
    verticesChrys.push_back(glm::vec3(sB,     z,      d));
    verticesChrys.push_back(glm::vec3(sS,     z,      d));
    verticesChrys.push_back(glm::vec3(dB,     -dB,    d));
    verticesChrys.push_back(glm::vec3(dS,     -dS,    d));
    verticesChrys.push_back(glm::vec3(z,      -sB,    d));
    verticesChrys.push_back(glm::vec3(z,      -sS,    d));
    verticesChrys.push_back(glm::vec3(-dB,    -dB,    d));
    verticesChrys.push_back(glm::vec3(-dS,    -dS,    d));

    verticesChrys.push_back(glm::vec3(-sB,    z,      -d));
    verticesChrys.push_back(glm::vec3(-sS,    z,      -d));
    verticesChrys.push_back(glm::vec3(-dB,    dB,     -d));
    verticesChrys.push_back(glm::vec3(-dS,    dS,     -d));
    verticesChrys.push_back(glm::vec3(z,      sB,     -d));
    verticesChrys.push_back(glm::vec3(z,      sS,     -d));
    verticesChrys.push_back(glm::vec3(dB,     dB,     -d));
    verticesChrys.push_back(glm::vec3(dS,     dS,     -d));
    verticesChrys.push_back(glm::vec3(sB,     z,      -d));
    verticesChrys.push_back(glm::vec3(sS,     z,      -d));
    verticesChrys.push_back(glm::vec3(dB,     -dB,    -d));
    verticesChrys.push_back(glm::vec3(dS,     -dS,    -d));
    verticesChrys.push_back(glm::vec3(z,      -sB,    -d));
    verticesChrys.push_back(glm::vec3(z,      -sS,    -d));
    verticesChrys.push_back(glm::vec3(-dB,    -dB,    -d));
    verticesChrys.push_back(glm::vec3(-dS,    -dS,    -d));
*/

    const unsigned int nTr = 16*4; // 2 faces and outer&inner fill
    const unsigned int nInd = nTr * 3;
    std::vector<GLuint> indicesChrys(nInd);
    GLuint v_offset;
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

    m_donut->setVertices(verticesChrys);
    m_donut->setIndices(indicesChrys);

    Geometry *g_donut = assetM->registerAsset<Geometry>("g_donut");
    g_donut->setMesh(m_donut);

    SceneNodeGeometry *n_donut = new SceneNodeGeometry("n_donut"); // TODO avoid new in client code
    n_donut->setGeometry(g_donut);
    node->addChild(n_donut);
}
