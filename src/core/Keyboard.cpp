#include "include/core/Keyboard.h"
#include "include/core/Application.h"
#include "include/core/SceneManager.h"

#include <SDL2/SDL_scancode.h>

namespace Core {
  Keyboard* Keyboard::instance = nullptr;

  Keyboard::Keyboard() : keystate(nullptr) {
    this->app = Application::getInstance();
  }

  Keyboard * Keyboard::getInstance() {
    if (instance == nullptr) {
      instance = new Keyboard();
    }

    return instance;
  }

  Keyboard::~Keyboard() {}

  void Keyboard::initialize() {

  }

  void Keyboard::handleKeyPress(const Uint8* currentKeystate) {
    this->keystate = currentKeystate;

    this->app->getSceneManager()->handleKeyPress(currentKeystate);
  }

  void Keyboard::handleKeyUp(SDL_Keycode key) const {
    this->app->getSceneManager()->handleKeyUp(key);
  }

  void Keyboard::handleKeyDown(SDL_Keycode key) const {
    this->app->getSceneManager()->handleKeyDown(key);
  }




  bool Keyboard::isKeyPressed(Uint8 keycode) const {
    return this->keystate[keycode];
  }

//  void Keyboard::resetKeyState() {
//    for (auto& keymapPair : this->keymap) {
//      auto& keyCode = keymapPair.first;
//      auto& keyState = keymapPair.second;
//
//      keyState.pressed = false;
//    }
//  }

//  void Keyboard::updateKeyState(std::string keycode, bool pressed) {
//
//  }
}