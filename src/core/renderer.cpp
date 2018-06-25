#include "renderer.h"

#include "statemanager.h"
#include "windowmanager.h"

extern WindowManager *windowM;
extern ShaderManager *shaderM;

Renderer::Renderer()
{
    model = glm::mat4(); // Identity
}

Renderer::~Renderer() {
}

void Renderer::init() {
}

// Renders with alpha delay
void Renderer::renderFrame(float alpha) {
    glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // Wireframe mode. To revert, set to GL_FILL

    shaderM->use();

    unsigned int modelLoc = glGetUniformLocation(shaderM->ID, "model");
    unsigned int viewLoc = glGetUniformLocation(shaderM->ID, "view");
    unsigned int projectionLoc = glGetUniformLocation(shaderM->ID, "projection");

    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(camera->getView()));
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(camera->getProjection()));
    //glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
    glDrawElements(GL_TRIANGLES, 192, GL_UNSIGNED_INT, 0);
    // glBindVertexArray(0); // no need to unbind it every time 

    windowM->swapBuffers();
    glfwPollEvents();
}
