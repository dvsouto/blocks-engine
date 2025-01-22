#pragma once

#include <vector>

namespace Graphics {
  struct Renderable;
}

namespace Graphics {
  class Layer {
    protected:
      unsigned int viewId;
      bool visible = true;

      Layer(unsigned int viewId);

      std::vector<std::shared_ptr<Renderable>> renderables;

    public:

      virtual ~Layer() = default;

      void add(const std::shared_ptr<Renderable>& renderable);
      void remove(std::shared_ptr<Renderable>& renderable);
      int size();

      virtual void render();

      bool isVisible() const;
  };
}