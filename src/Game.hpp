#ifndef GAMEHPP
#define GAMEHPP 1

#include <vector>

#include <SFML/Graphics.hpp>

#include "State.hpp"


class Game {
public:
  Game(std::vector<State*>*,sf::RenderWindow*);

protected:

  std::vector<State*>* go_to_states;
  sf::RenderWindow* window;

};

#endif
