#include "game.h"
#include "SDL.h"
#include <iostream>
#include <fstream>
#include <sstream>

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1))
{
  ReadHighscoreFromFile();
  PlaceFood();
}

Game::~Game()
{
  if (player.GetScore() > GetHighscore())
  {
    std::cout << "Congratulations! New Highscore! \n";
    std::cout << "Your Score: " << player.GetScore() << "\n";
    UpdateHighscore();
  }
  else
  {
    std::cout << "Game has terminated successfully!\n";
    std::cout << "Your score was: " << player.GetScore() << "\n";
    std::cout << "The highscore is " << GetHighscore() << " of " << GetNameOfPlayerHoldingHighscore() << ".\n";
    std::cout << "Maybe it will be yours next time! :)";
  }
}

void Game::ReadHighscoreFromFile()
{
  std::string highscore, playerName;
  std::ifstream file;
  std::string line;
  file.open("highscore_data.txt");
  //if file doesn't exist, create it and save "0" as highscore ans "-" as player name
  if (!file)
  {
    std::ofstream createFile;
    createFile.open("highscore_data.txt");
    createFile << "0 -";
    createFile.close();
    file.open("highscore_data.txt");
  }
  std::getline(file, line);
  std::istringstream linestream(line);
  linestream >> highscore >> playerName;
  SetHighscore(std::stoi(highscore));
  SetNameOfPlayerHoldingHighscore(playerName);
}

void Game::UpdateHighscore()
{

  std::ofstream file;
  file.open("highscore_data.txt");
  file << player.GetScore() << " " << AskPlayerForName();
  file.close();
}

std::string Game::AskPlayerForName()
{
  std::string name;
  std::cout << "Pleas tell me your name, so it can be saved with your score: ";
  std::cin >> name;
  return name;
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration)
{
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running)
  {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();
    renderer.Render(snake, food);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000)
    {
      renderer.UpdateWindowTitle(player.GetScore(), frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration)
    {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood()
{
  int x, y;
  while (true)
  {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y))
    {
      food.x = x;
      food.y = y;
      return;
    }
  }
}

void Game::Update()
{
  if (!snake.alive)
    return;

  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's food over here
  if (food.x == new_x && food.y == new_y)
  {
    //score++;
    player.IncreaseScoreAfterFood();
    PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.02;
  }
}

int Game::GetHighscore() const { return _highscore; }
int Game::GetSize() const { return snake.size; }
std::string Game::GetNameOfPlayerHoldingHighscore() const { return _nameOfPlayerHoldingHighscore; }
void Game::SetHighscore(int score) { _highscore = score; }
void Game::SetNameOfPlayerHoldingHighscore(std::string name) { _nameOfPlayerHoldingHighscore = name; }