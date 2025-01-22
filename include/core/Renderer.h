#pragma once

#include "SceneManager.h"

#include <bgfx/bgfx.h>

namespace Core {
  class Window;
  class SceneManager;
}

namespace Core {
  class Renderer {
    static Renderer* instance;

    bool initialized = false;
    int rWidth;
    int rHeight;

    void beginFrame();
    void endFrame();

    bgfx::PlatformData retrievePlatformData(Window* windowInstance);

    Renderer();
    ~Renderer();

    public:
      static Renderer* getInstance();

      void initialize(Window* windowInstance);

      bool isRunning() const;
      void render();
      void renderSky();

      bgfx::RendererType::Enum getRendererType() const;
      const char* getRendererName() const;

      SceneManager* sceneManager = nullptr;
  };
}
