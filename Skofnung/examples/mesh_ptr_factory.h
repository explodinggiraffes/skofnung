#pragma once

#include <string>

#include <Ogre.h>

/* ------------------------------------------------------------------------------------------------------------------
 * Factory for creating Ogre::MeshPtr objects.
 *-----------------------------------------------------------------------------------------------------------------*/
class MeshPtrFactory {
public:
  MeshPtrFactory() = delete;
  MeshPtrFactory(const MeshPtrFactory&) = delete;
  MeshPtrFactory& operator=(const MeshPtrFactory&) = delete;
  MeshPtrFactory(MeshPtrFactory&&) = delete;
  MeshPtrFactory& operator=(MeshPtrFactory&&) = delete;

  // Creates a spherical MeshPtr based on the "Creating a sphere with ManualObject" example:
  // https://wiki.ogre3d.org/ManualSphereMeshes
  static Ogre::MeshPtr CreateSphere(
    Ogre::SceneManager* scene_manager, const std::string& name, float radius, int horizontal_circles, int arcs);
};
