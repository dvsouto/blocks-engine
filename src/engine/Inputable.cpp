#include "include/engine/Inputable.h"

#include "include/core/Keyboard.h"
#include "include/core/Mouse.h"

using namespace Core;

namespace Engine {
  Inputable::Inputable() : keyboard(Keyboard::getInstance()), mouse(Mouse::getInstance()) {};

//  Inputable::~Inputable() {
//    this->keyboard = nullptr;
//    this->mouse = nullptr;
//  };
}