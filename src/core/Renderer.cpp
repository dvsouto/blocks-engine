#include "include/core/Renderer.h"
#include "include/core/SceneManager.h"
#include <include/core/Window.h>

#include <bgfx/bgfx.h>
#include <bgfx/platform.h>
#include <bx/math.h>

#include <iostream>
#include <ostream>

namespace Core {
  Renderer* Renderer::instance = nullptr;

  Renderer::Renderer() : rWidth(0), rHeight(0) {}

  Renderer * Renderer::getInstance() {
    if (instance == nullptr) {
      instance = new Renderer();
    }

    return instance;
  }

  void Renderer::initialize(Window* windowInstance) {
    rWidth = windowInstance->getWidth();
    rHeight = windowInstance->getHeight();

    bgfx::Init gfxInitialState;

    // Set GFX initial state
    gfxInitialState.type = bgfx::RendererType::Count;
    // gfxInitialState.type = bgfx::RendererType::OpenGL;
    gfxInitialState.resolution.width = rWidth;
    gfxInitialState.resolution.height = rHeight;
    gfxInitialState.resolution.reset = BGFX_RESET_VSYNC;
    gfxInitialState.platformData = retrievePlatformData(windowInstance);

    bgfx::renderFrame();

    // Init BGFX
    if (! bgfx::init(gfxInitialState)) {
      std::cerr << "Fail when trying to initialize bgfx" << std::endl;

      exit(EXIT_FAILURE);
    }


    // Reset window and enable debug
    bgfx::reset(rWidth, rHeight, BGFX_RESET_VSYNC);
    bgfx::setDebug(BGFX_DEBUG_TEXT);
    bgfx::setViewMode(0, bgfx::ViewMode::Sequential);

    this->sceneManager = SceneManager::getInstance();

    // bgfx::setDebug(BGFX_DEBUG_TEXT | BGFX_DEBUG_STATS);

    initialized = true;

    std::cout << "Current Renderer: " << getRendererName() << std::endl;
  }

  bool Renderer::isRunning() const {
    return initialized;
  }

  void Renderer::renderSky() {
    const unsigned int bgColor = 0x4FD1FFFF;

    // Add view rectangle
    bgfx::setViewRect(0, 0, 0, static_cast<uint16_t>(rWidth), static_cast<uint16_t>(rHeight));
    bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, bgColor, 1.0f, 0);
  }

  bgfx::PlatformData Renderer::retrievePlatformData(Window* windowInstance) {
    const auto wmi = windowInstance->getInfo();

    bgfx::PlatformData platformData;

    #ifdef __APPLE__
    platformData.ndt = nullptr;
    platformData.nwh = wmi.info.cocoa.window;
    #else
    platformData.ndt = nullptr;
    platformData.nwh = wmi.info.win.window;
    #endif
    platformData.context = nullptr;
    platformData.backBuffer = nullptr;
    platformData.backBufferDS = nullptr;

    return platformData;
  }

  bgfx::RendererType::Enum Renderer::getRendererType() const {
    return bgfx::getRendererType();
  }

  const char* Renderer::getRendererName() const {
    return bgfx::getRendererName(getRendererType());
  }

  void Renderer::render() {
    beginFrame();

    this->sceneManager->renderCurrentScene();

    endFrame();
  }

  void Renderer::beginFrame() {
    const bx::Vec3 at  = { 0.0f, 0.0f,   0.0f };
    const bx::Vec3 eye = { 0.0f, 0.0f, 5.0f };

    // Set view and projection matrix for view 0.
    float view[16];
    bx::mtxLookAt(view, eye, at);

    float proj[16];
    bx::mtxProj(proj,
                60.0f,
                float(rWidth)/float(rHeight),
                0.1f, 100.0f,
                bgfx::getCaps()->homogeneousDepth);

    bgfx::setViewTransform(0, view, proj);

    renderSky();
  }

  void Renderer::endFrame() {
    bgfx::touch(0);
    bgfx::frame();
  }

  Renderer::~Renderer() {
    std::cout << std::endl << "Renderer::~Renderer" << std::endl;

    initialized = false;

    bgfx::shutdown();

    delete instance;
    instance = nullptr;
  }
}
