#pragma once

#include "include/core/Entity.h"
#include "include/primitive/Mesh.h"
//
//namespace Core {
//  class Entity;
//}

using namespace Core;

namespace Primitive {
  class MeshEntity : Entity {
    public:
      // MeshEntity() = default;
      ~MeshEntity() override;

      void update() override;
      void render() override;
    private:
      Mesh mesh;
  };
}