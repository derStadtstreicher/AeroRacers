
#include <array>

#include "Race.hpp"
#include "util.hpp"

using std::size_t;

Race::Race(std::vector<State*>* sv ,sf::RenderWindow* rw)
  :
  Game{sv,rw},
  next_state{(*go_to_states)[State::Type::playing]},
  clock(){
}

State* Race::progress() {
  car = sf::CircleShape(50.f);
  car.setPosition(200,200);
  car.setFillColor(sf::Color(10,250,50));
  next_state = (*go_to_states)[State::Type::playing];
  clock.restart();

  size_t t{0}; // microseconds
  size_t dt{1000};
  size_t accu {0};
  size_t current_time {0};
  size_t frame_time {0};
  size_t new_time;
  std::array<size_t, 3> pos_prev;
  std::array<size_t, 3> pos_curr;
  std::array<size_t, 3> pos_rend;
  
  while (next_state == (*go_to_states)[State::Type::playing]) {
    next_state =  processEvents();

    new_time = clock.getElapsedTime().asMicroseconds();
    frame_time = new_time - current_time;
    current_time = new_time;
    accu += frame_time;

    while(accu >= dt) {
      pos_prev = pos_curr;
      update_pos(&pos_curr,t,dt);
      t += dt;
      accu -= dt;
    }
    double alpha = static_cast<double>(accu) / dt;
    pos_rend = (pos_prev - pos_curr) * alpha;
    render(pos_rend);
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

void Race::update_pos(std::array<size_t,3>* pos, size_t t, size_t dt) {
}
  
void Race::render(const std::array<size_t, 3>& pos) {
  window->clear();
  window->draw(car);
  window->display();
}
