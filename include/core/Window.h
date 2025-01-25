#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_syswm.h>

#include <iostream>

namespace Core {
  class Window {
    static Window* instance;

    SDL_Window* window;
    bool initialized = false;
    bool shouldClose = false;

    int wWidth = 1280;
    int wHeight = 720;
    std::string wTitle = "Blocks";

    Window();
    Window(int width, int height, const std::string &title);
    ~Window();
    // auto* renderFunction = nullptr;

    public:
      static Window* getInstance();

      void initialize();
      void run();
      void close();
      bool isRunning() const;

      int getWidth() const;
      int getHeight() const;
      float getAspectRatio() const;

      void setCursorVisibility(bool visible) const;

      SDL_SysWMinfo getInfo() const;

      // void poolEvents();
      // void swapBuffers();
      // bool shouldClose();

      // void setRenderFunction(std::function<void>* fn);

      SDL_Window* getWindow() const;
  };
}
