#include <iostream>
#include <memory>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "player.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};
  
  std::unique_ptr<Game> game(new Game(kGridWidth,kGridHeight));
  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  game->Run(controller, renderer, kMsPerFrame);
  return 0;
}