#pragma once

#include <include/core/Application.h>
#include <include/core/LayerManager.h>
#include <include/engine/Inputable.h>

namespace Core {
  class LayerManager;
  class ShaderManager;
  class Application;
}

namespace Graphics {
  class Layer;
}

namespace Graphics {
  class Scene : public Engine::Updatable, public Engine::Inputable {
    public:
      Core::LayerManager* layers;
      Core::ShaderManager* shaders;
      Core::Application* app;

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