#include "Race.hpp"

Race::Race(std::vector<State*>* sv ,sf::RenderWindow* rw)
  :
  Game{sv,rw},
  next_state{(*go_to_states)[State::Type::playing]},
  clock(){
}

State* Race::progress() {
  next_state = (*go_to_states)[State::Type::playing];
  clock.restart();
  while (next_state == (*go_to_states)[State::Type::playing]) {
    next_state =  processEvents();
    
    update();//may change next_state in practice mode
    render();
  }
  return next_state;
}

State* Race::processEvents() {
  sf::Event event;
  State* state = (*go_to_states)[State::Type::playing];

  while (window->pollEvent(event)) {
    switch (event.type) {
    case sf::Event::KeyPressed:
      state = handleOffTextInput(event.key.code, true);
      break;
    case sf::Event::KeyReleased:
      state = handleOffTextInput(event.key.code, false);
      break;
    case sf::Event::Closed:
      return (*go_to_states)[State::Type::quitting];
      break;
    default:;
    }
  }
  return state;
}

State* Race::handleOffTextInput (sf::Keyboard::Key key, bool isPressed) {
  if (key == sf::Keyboard::W) {
    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::RControl) ) {
      return (*go_to_states)[State::Type::quitting];
    }
  }
  if (key == sf::Keyboard::Escape) {
    return (*go_to_states)[State::Type::quitting];
  }
  return (*go_to_states)[State::Type::playing];
}

void Race::update() {
}
  
void Race::render() {
  window->clear();
  //window->drow(...);
  window->display();
}
