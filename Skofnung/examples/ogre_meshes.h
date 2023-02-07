#pragma once

#include <Ogre.h>

/* ------------------------------------------------------------------------------------------------------------------
 * Demonstrates loading a mesh from the Media/models directory.
 *
 * The location of the Media/models directory is defined in Ogre's resources.cfg located at:
 * extern/ogre/bin/resources.cfg
 *-----------------------------------------------------------------------------------------------------------------*/
class OgreMeshes
{
public:
  OgreMeshes() = delete;
  OgreMeshes(const OgreMeshes&) = delete;
  OgreMeshes& operator=(const OgreMeshes&) = delete;
  OgreMeshes(OgreMeshes&&) = delete;
  OgreMeshes& operator=(OgreMeshes&&) = delete;

  static void CreateOgreMeshes(Ogre::SceneManager* scene_manager);
};
