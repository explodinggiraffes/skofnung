#include <iostream>

#include "skofnung_ogre_application.h"

/* ------------------------------------------------------------------------------------------------------------------
 * Skofnung uses Ogre as its rendering engine.
 * It demonstrates:
 * - Loading meshes
 * - Creating MeshPtr objects
 * - Cameras and lighting
 *
 * The code in the examples directory is based upon the Ogre "Your First Scene" tutorial:
 * https://ogrecave.github.io/ogre/api/latest/tut__first_scene.html
 *-----------------------------------------------------------------------------------------------------------------*/
int main() {
  std::cout << "Hello Skofnung!\n";

  try {
    SkofnungOgreApplication application;
    application.initApp();
    application.getRoot()->startRendering();
    application.closeApp();
  } catch (const std::exception& e) {
    std::cerr << "Error occurred during execution: " << e.what() << '\n';
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
