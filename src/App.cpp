#include "App.hpp"
#include "settings.hpp"

App::App() 
  :
  window(sf::VideoMode({X,Y}),"Typerion",sf::Style::Fullscreen),
  states(State::Type::count),
  race(&states, &window),
  quitter()
{
  window.setFramerateLimit(120);
  states[State::Type::playing] = &race;
  states[State::Type::quitting] = &quitter;
}

void App::run() {
  State* state_ptr = states[State::Type::playing];
  while (state_ptr != states[State::Type::quitting] ) {
    state_ptr = state_ptr->progress();
  }
  window.close();
}
