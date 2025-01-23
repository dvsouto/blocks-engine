#pragma once

namespace Core {
  class Window;
  class Renderer;
  class SceneManager;
  class ShaderManager;
}

namespace Engine {
  class Game;
}

namespace Core {
  class Application {
    static Application* instance;
    static Window* window;
    static Renderer* renderer;
    static SceneManager* sceneManager;
    static ShaderManager* shaderManager;
    static Engine::Game* game;

    Application();
    ~Application();

    public:
      static Application* getInstance();

      Window* getWindow() const;
      Renderer* getRenderer() const;
      SceneManager* getSceneManager() const;
      ShaderManager* getShaderManager() const;
      Engine::Game* getGame() const;

      void setWindow(Window* windowInstance) const;
      void setRenderer(Renderer* rendererInstance) const;
      void setSceneManager(SceneManager* sceneManagerInstance) const;
      void setShaderManager(ShaderManager* shaderManagerInstance) const;
      void setGame(Engine::Game* gameInstance) const;
  };
}