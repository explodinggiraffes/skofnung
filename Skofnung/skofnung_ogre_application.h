#pragma once

#include <Ogre.h>
#include <OgreApplicationContext.h>

/* ------------------------------------------------------------------------------------------------------------------
 * Creates an Ogre::SceneManager, which is then used to populate the world with ogres, geometric shapes, lights, and
 * a camera.
 *-----------------------------------------------------------------------------------------------------------------*/
class SkofnungOgreApplication final : public OgreBites::ApplicationContext, public OgreBites::InputListener {
public:
  SkofnungOgreApplication();

  void setup() override;

  bool keyPressed(const OgreBites::KeyboardEvent& evt) override;

private:
  void SetupLighting();
  void SetupCamera();

  void CreateEntities();

  Ogre::SceneManager* scene_manager_;
};
