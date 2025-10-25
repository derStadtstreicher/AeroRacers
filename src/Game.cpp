#include <cmath>
#include <iostream>
#include "Game.hpp"

Game::Game(std::vector<State*>* s, sf::RenderWindow* w) 
  :
  go_to_states(s),
  window(w){
}


