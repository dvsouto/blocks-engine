#include "include/core/Keyboard.h"

#include <SDL2/SDL_scancode.h>

namespace Core {
  Keyboard* Keyboard::instance = nullptr;

  Keyboard::Keyboard() {}

  Keyboard* Keyboard::getInstance() {
    if (instance == nullptr) {
      instance = new Keyboard();
    }

    return instance;
  }

  Keyboard::~Keyboard() {}

  void Keyboard::initialize() {

  }

  void Keyboard::handle(const Uint8* currentKeystate) {
    this->keystate = currentKeystate;
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