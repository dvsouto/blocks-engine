#pragma once

namespace Core {
  class Window;
  class Renderer;
  class SceneManager;
  class ShaderManager;
  class Keyboard;
  class Mouse;
}

namespace Engine {
  class Game;
  class Timer;
}

using namespace Engine;

namespace Core {
  class Application {
    static Application* instance;
    static Window* window;
    static Renderer* renderer;
    static SceneManager* sceneManager;
    static ShaderManager* shaderManager;
    static Game* game;
    static Keyboard* keyboard;
    static Mouse* mouse;
    static Timer* timer;

    Application();
    ~Application();

    public:
      static Application* getInstance();

      Window* getWindow() const;
      Renderer* getRenderer() const;
      SceneManager* getSceneManager() const;
      ShaderManager* getShaderManager() const;
      Game* getGame() const;
      Keyboard* getKeyboard() const;
      Mouse* getMouse() const;
      Timer* getTimer() const;

      void setWindow(Window* windowInstance) const;
      void setRenderer(Renderer* rendererInstance) const;
      void setSceneManager(SceneManager* sceneManagerInstance) const;
      void setShaderManager(ShaderManager* shaderManagerInstance) const;
      void setGame(Game* gameInstance) const;
      void setKeyboard(Keyboard* keyboardInstance) const;
      void setMouse(Mouse* mouseInstance) const;
      void setTimer(Timer* timerInstance) const;
  };
}