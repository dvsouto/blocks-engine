#pragma once

#include <include/core/LayerManager.h>

namespace Core {
  class LayerManager;
  class ShaderManager;
}

namespace Graphics {
  class Layer;
}

namespace Graphics {
  class Scene : public Engine::Updatable {
    public:
      Core::LayerManager layers;
      Core::ShaderManager* shaders;

      Scene();

      ~Scene() override = default;
      virtual void init() = 0;

      void render() const;

      virtual void load() = 0;
      void unload();
      bool isLoaded() const;

    protected:
      bool loaded = false;
  };
}