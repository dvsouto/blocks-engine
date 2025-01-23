#pragma once

#include <unordered_map>
#include <string>

#include <SDL2/SDL_scancode.h>

namespace Core {
//  struct Key {
//    std::string code;
//    bool pressed;
//  };

  class Keyboard {
    static Keyboard* instance;

    Keyboard();
    ~Keyboard();

    const Uint8* keystate;

//      void resetKeyState();
//      void updateKeyState(std::string keycode, bool pressed);

//      std::unordered_map<std::string, Key> keymap;
    public:
      static Keyboard* getInstance();

      void handle(const Uint8* currentKeystate);
      void initialize();
      bool isKeyPressed(Uint8 keycode) const;
  };
}