#include "include/engine/Updatable.h"
#include "include/engine/Timer.h"

namespace Engine {
   Updatable::Updatable() : timer(Timer::getInstance())  {}

}