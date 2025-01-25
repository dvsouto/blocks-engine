#pragma once

#include <Eigen/Dense>
#include <chrono>

namespace Core {
    class Application;
}

namespace Core {
  class Mouse {
    static Mouse* instance;
    Application* app = nullptr;

    Mouse();
    ~Mouse();

    int axisX = 0;
    int axisY = 0;
    std::chrono::high_resolution_clock::time_point lastUpdate;

    bool visible;
  public:
    static Mouse* getInstance();

    void handleMouseMove(int x, int y);
    void initialize();
    void reset();

    void show();
    void hide();
    void toggleVisibility();

    int getAxisX() const;
    int getAxisY() const;
    Eigen::Vector2<int> getAxis() const;
  };
}