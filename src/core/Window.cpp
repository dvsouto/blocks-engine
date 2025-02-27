#include "include/core/Window.h"
#include <include/core/Keyboard.h>
#include <include/core/Mouse.h>
#include "include/core/Renderer.h"
#include <include/core/Application.h>

#include <include/engine/Game.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_syswm.h>

#include <iostream>

namespace Core {
  Window* Window::instance = nullptr;

  Window::Window() : window(nullptr) {}

  Window::Window(const int width, const int height, const std::string &title) : Window() {
    this->wWidth = width;
    this->wHeight = height;
    this->wTitle = title;
  }

  Window* Window::getInstance() {
    if (instance == nullptr) {
      instance = new Window();
    }

    return instance;
  }

  void Window::initialize() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
      std::cerr << "Fail when trying initialize SDL Window:" << std::endl << SDL_GetError() << std::endl;

      exit(EXIT_FAILURE);
    }

    // Create platform window
    window = SDL_CreateWindow("Block", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->wWidth, this->wHeight, SDL_WINDOW_SHOWN);

    if (! this->window) {
      std::cerr << "Error when trying create window" << std::endl << SDL_GetError() << std::endl;

      exit(EXIT_FAILURE);
    }

    initialized = true;
  }

  void Window::run() {
    SDL_Event currentEvent;
    auto* game = Application::getInstance()->getGame();
    auto* keyboard = Application::getInstance()->getKeyboard();
    auto* mouse = Application::getInstance()->getMouse();

    while (! shouldClose) {
      while (SDL_PollEvent(&currentEvent) != 0) {
        if (currentEvent.type == SDL_QUIT) {
          shouldClose = true;
        }

        // Get mouse event
        if (currentEvent.type == SDL_MOUSEMOTION) {
          mouse->handleMouseMove(currentEvent.motion.xrel, currentEvent.motion.yrel);
        }

        // Key down event
        if (currentEvent.type == SDL_KEYDOWN) {
          keyboard->handleKeyDown(currentEvent.key.keysym.sym);
        }

        // Key up event
        if (currentEvent.type == SDL_KEYUP) {
          keyboard->handleKeyUp(currentEvent.key.keysym.sym);
        }
      }

      const Uint8* keystates = SDL_GetKeyboardState(nullptr);

      // Call keyboard handle
      keyboard->handleKeyPress(keystates);

      // Call game update event
      game->update();

      // Call game render event
      game->render();

      // Reset mouse values
      mouse->reset();

      // Set framerate to ~60 FPS
      SDL_Delay(16);
    }
  }

  // void Window::poolEvents() {
  // }
  //
  // void Window::swapBuffers() {
  //
  // }

  int Window::getWidth() const {
    return wWidth;
  }

  int Window::getHeight() const {
    return wHeight;
  }

  float Window::getAspectRatio() const {
    return static_cast<float>(this->wWidth) / static_cast<float>(this->wHeight);
  }

  void Window::setCursorVisibility(bool visible) const {
    SDL_SetRelativeMouseMode(visible ? SDL_FALSE : SDL_TRUE);
    SDL_ShowCursor(visible ? SDL_ENABLE : SDL_DISABLE);
  }


  SDL_SysWMinfo Window::getInfo() const {
    SDL_SysWMinfo wmi;
    SDL_VERSION(&wmi.version);

    if (! SDL_GetWindowWMInfo(this->window, &wmi)) {
      std::cerr << "Fail at Window.getInfo()" << std::endl;

      exit(EXIT_FAILURE);
    }

    return wmi;
  }


  void Window::close() {
    if (this->window) {
      SDL_DestroyWindow(this->window);
    }

    SDL_Quit();

    initialized = false;
  }

  bool Window::isRunning() const {
    return this->initialized;
  }


  SDL_Window* Window::getWindow() const {
    return this->window;
  }

  Window::~Window() {
    std::cout << std::endl << "Window::~Window" << std::endl;

    close();

    delete instance;
    instance = nullptr;
  }
}
