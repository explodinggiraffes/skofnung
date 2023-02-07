#include "mesh_ptr_factory.h"

Ogre::MeshPtr MeshPtrFactory::CreateSphere(
  Ogre::SceneManager* scene_manager, const std::string& name, float radius, int horizontal_circles, int arcs) {
  const float circle_angle_delta = (Ogre::Math::PI / horizontal_circles);
  const float arc_angle_delta = (2 * Ogre::Math::PI / arcs);
  int vertex_index = 0;

  Ogre::ManualObject* manual_object = scene_manager->createManualObject(name);
  manual_object->estimateVertexCount(horizontal_circles * arcs);
  manual_object->estimateIndexCount(horizontal_circles * arcs * 6);
  manual_object->begin(name, Ogre::RenderOperation::OT_TRIANGLE_LIST);

  // Create each horizontal circle circumferencing the sphere.
  for (int circle = 0; circle <= horizontal_circles; ++circle) {
    float r = radius * sinf(circle * circle_angle_delta);
    float y = radius * cosf(circle * circle_angle_delta);

    // Create the arcs for each horizontal circle.
    for (int arc = 0; arc <= arcs; ++arc) {
      float x = r * sinf(arc * arc_angle_delta);
      float z = r * cosf(arc * arc_angle_delta);

      // Add one vertex to the strip which makes up the sphere.
      manual_object->position(x, y, z);
      manual_object->normal(Ogre::Vector3(x, y, z).normalisedCopy());
      manual_object->textureCoord((float)arc / (float)arcs, (float)circle / (float)horizontal_circles);

      // Each vertex (except the last) has six vertexes pointing to it.
      if (circle < horizontal_circles) {
        manual_object->index(vertex_index + arcs + 1);
        manual_object->index(vertex_index);
        manual_object->index(vertex_index + arcs);
        manual_object->index(vertex_index + arcs + 1);
        manual_object->index(vertex_index + 1);
        manual_object->index(vertex_index);
        ++vertex_index;
      }
    } // end arc
  } // end circle

  manual_object->end();

  Ogre::MeshPtr mesh = manual_object->convertToMesh(name + ".mesh");

  //mesh->_setBoundingSphereRadius(radius);
  //mesh->_setBounds(Ogre::AxisAlignedBox(Ogre::Vector3(-radius, -radius, -radius), Ogre::Vector3(radius, radius, radius)), false);

  return mesh;
}
