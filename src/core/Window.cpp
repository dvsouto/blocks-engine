#include "include/core/Window.h"
#include "include/core/Renderer.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_syswm.h>

#include <include/core/Application.h>
#include <include/engine/Game.h>
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

    while (! shouldClose) {
      while (SDL_PollEvent(&currentEvent) != 0) {
        if (currentEvent.type == SDL_QUIT) {
          shouldClose = true;
        }
      }

      // Call game update event
      game->update();

      // Call game render event
      game->render();

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

  SDL_SysWMinfo Window::getInfo() {
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
