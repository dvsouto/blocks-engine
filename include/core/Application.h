#pragma once

namespace Core {
  class Window;
  class Renderer;
  class SceneManager;
}

namespace Core {
  class Application {
    static Application* instance;
    static Window* window;
    static Renderer* renderer;
    static SceneManager* sceneManager;

    Application();
    ~Application();

    public:
      static Application* getInstance();

      Window* getWindow() const;
      Renderer* getRenderer() const;
      SceneManager* getSceneManager() const;

      void setWindow(Window* windowInstance) const;
      void setRenderer(Renderer* rendererInstance) const;
      void setSceneManager(SceneManager* sceneManagerInstance) const;
  };
}