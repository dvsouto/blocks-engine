#pragma once

#include <include/engine/Updatable.h>

#include <vector>

namespace Graphics {
  struct Renderable;
}

namespace Graphics {
  class Layer : public Engine::Updatable {
    protected:
      unsigned int viewId;
      bool visible = true;

      Layer(unsigned int viewId);

      std::vector<std::shared_ptr<Renderable>> renderables;

    public:
      ~Layer() override = default;

      void add(const std::shared_ptr<Renderable>& renderable);
      void remove(std::shared_ptr<Renderable>& renderable);
      int size();

      virtual void render();
      void update(float deltaTime) override;

      bool isVisible() const;
  };
}