#ifndef RACE_HPP
#define RACE_HPP

#include "Game.hpp"
#include "State.hpp"

class Race : public Game, public State {

public:

  State* progress();
  
  Race(std::vector<State*>*,sf::RenderWindow*);
  
private:

  State* next_state;

  sf::Clock clock;
  sf::CircleShape car;
  
  State* processEvents();
  void update();
  void render();
  void handleInput();
  State* handleOffTextInput (sf::Keyboard::Key key, bool isPressed);

};

#endif

