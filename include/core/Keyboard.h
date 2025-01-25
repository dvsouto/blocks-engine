#pragma once

#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_scancode.h>

namespace Core {
  class Application;
}

namespace Core {
//  struct Key {
//    std::string code;
//    bool pressed;
//  };

  class Keyboard {
    static Keyboard* instance;
    Application* app = nullptr;


    Keyboard();
    ~Keyboard();

    const Uint8* keystate;

//      void resetKeyState();
//      void updateKeyState(std::string keycode, bool pressed);

//      std::unordered_map<std::string, Key> keymap;
    public:
      static Keyboard* getInstance();

      void handleKeyPress(const Uint8* currentKeystate);
      void handleKeyUp(SDL_Keycode key) const;
      void handleKeyDown(SDL_Keycode key) const;

      void initialize();
      bool isKeyPressed(Uint8 keycode) const;
  };
}