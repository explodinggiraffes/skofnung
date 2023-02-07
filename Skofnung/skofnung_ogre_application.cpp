#include "skofnung_ogre_application.h"

#include <iostream>

#include "examples/mesh_ptr_factory.h"
#include "examples/ogre_meshes.h"

SkofnungOgreApplication::SkofnungOgreApplication() :
  OgreBites::ApplicationContext("Skofnung"),
  scene_manager_(nullptr) {
  std::cout << "Creating Skofnung....\n";
}

void SkofnungOgreApplication::setup() {
  // Set up the Ogre context and make this object an input listener.
  // Also get a pointer to the Ogre Root, which is how the application gains access to the fundamentals of the system
  // (e.g., the rendering system, logging, etc.).
  OgreBites::ApplicationContext::setup();
  addInputListener(this);
  Ogre::Root* root = getRoot();

  std::cout << "Setting up Skofnung....\n";

  // Create the scene manager, which manages and renders the "scene" -- a collection of objects and world geometries.
  scene_manager_ = root->createSceneManager();

  // Create the shader generator for our scene.
  Ogre::RTShader::ShaderGenerator* shader_generator = Ogre::RTShader::ShaderGenerator::getSingletonPtr();
  shader_generator->addSceneManager(scene_manager_);

  SetupLighting();
  SetupCamera();

  CreateEntities();
}

void SkofnungOgreApplication::SetupLighting() {
  scene_manager_->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));

  Ogre::Light* light = scene_manager_->createLight("MainLight - Skofnung");

  Ogre::SceneNode* light_node = scene_manager_->getRootSceneNode()->createChildSceneNode();
  light_node->attachObject(light);
  light_node->setPosition(20, 80, 50);
}

void SkofnungOgreApplication::SetupCamera() {
  Ogre::Camera* camera = scene_manager_->createCamera("Camera - Skofnung");
  camera->setNearClipDistance(5);  // specific to this sample
  camera->setAutoAspectRatio(true);

  Ogre::SceneNode* camera_node = scene_manager_->getRootSceneNode()->createChildSceneNode();
  camera_node->attachObject(camera);
  camera_node->setPosition(0, 47, 222);

  getRenderWindow()->addViewport(camera);
}

bool SkofnungOgreApplication::keyPressed(const OgreBites::KeyboardEvent& evt) {
  std::cout << "Handling key press....\n";

  if (evt.keysym.sym == OgreBites::SDLK_ESCAPE) {
    getRoot()->queueEndRendering();
  }

  return true;
}

void SkofnungOgreApplication::CreateEntities() {
  OgreMeshes::CreateOgreMeshes(scene_manager_);

  auto spherical_mesh = MeshPtrFactory::CreateSphere(scene_manager_, "sphere", 24, 20, 20);
  Ogre::Entity* sphere_entity = scene_manager_->createEntity(spherical_mesh->getName());
  Ogre::SceneNode* sphere_node = scene_manager_->getRootSceneNode()->createChildSceneNode();
  sphere_node->setPosition(-42, 48, 0);
  sphere_node->attachObject(sphere_entity);

  Ogre::Entity* cube_entity = scene_manager_->createEntity("cube.mesh");
  Ogre::SceneNode* cube_node = scene_manager_->getRootSceneNode()->createChildSceneNode();
  cube_node->setPosition(42, 48, 0);
  cube_node->setScale(.45, .45, .45);
  cube_node->roll(Ogre::Degree(-45));
  cube_node->pitch(Ogre::Degree(22.5));
  cube_node->attachObject(cube_entity);
}
