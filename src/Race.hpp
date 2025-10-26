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
  void update_pos(std::array<size_t,3>* pos, size_t t, size_t dt);
  void render(const std::array<size_t, 3>& pos);
  void handleInput();
  State* handleOffTextInput (sf::Keyboard::Key key, bool isPressed);

};

#endif

