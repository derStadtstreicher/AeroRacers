#ifndef RACE_HPP
#define RACE_HPP

#include "Game.hpp"
#include "State.hpp"
#include "Car.hpp"

class Race : public Game, public State {

public:

  State* progress();
  
  Race(std::vector<State*>*,sf::RenderWindow*);
  
private:

  State* next_state;

  sf::Clock clock;
  Car car;
  
  State* processEvents();
  void update_pos(std::array<double,3>& pos, double t, double dt);
  void render(const std::array<double, 3>& pos);
  void handleInput();
  State* handleInput (sf::Keyboard::Key key, bool isPressed);
  void setup_cars();  

};

#endif

