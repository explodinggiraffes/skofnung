#include "ogre_meshes.h"

void OgreMeshes::CreateOgreMeshes(Ogre::SceneManager* scene_manager) {
  Ogre::Entity* ogre_entity1 = scene_manager->createEntity("ogrehead.mesh");
  Ogre::SceneNode* ogre_node1 = scene_manager->getRootSceneNode()->createChildSceneNode();
  ogre_node1->attachObject(ogre_entity1);

  Ogre::Entity* ogre_entity2 = scene_manager->createEntity("ogrehead.mesh");
  Ogre::SceneNode* ogre_node2 = scene_manager->getRootSceneNode()->createChildSceneNode(Ogre::Vector3(84, 48, 0));
  ogre_node2->attachObject(ogre_entity2);

  Ogre::Entity* ogre_entity3 = scene_manager->createEntity("ogrehead.mesh");
  Ogre::SceneNode* ogre_node3 = scene_manager->getRootSceneNode()->createChildSceneNode();
  ogre_node3->setPosition(0, 104, 0);
  ogre_node3->setScale(2, 1.2, 1);
  ogre_node3->attachObject(ogre_entity3);

  Ogre::Entity* ogre_entity4 = scene_manager->createEntity("ogrehead.mesh");
  Ogre::SceneNode* ogre_node4 = scene_manager->getRootSceneNode()->createChildSceneNode();
  ogre_node4->setPosition(-84, 48, 0);
  ogre_node4->roll(Ogre::Degree(-90));
  ogre_node4->attachObject(ogre_entity4);
}
