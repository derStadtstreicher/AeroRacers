
#include <array>
#include <iostream>

#include "Race.hpp"
#include "util.hpp"
#include "settings.hpp"

using std::size_t;

Race::Race(std::vector<State*>* sv ,sf::RenderWindow* rw)
  :
  Game{sv,rw},
  next_state{(*go_to_states)[State::Type::playing]},
  clock(){
}

void setup_cars() {
}

State* Race::progress() {
  std::cout << "progress of Race called \n";
  next_state = (*go_to_states)[State::Type::playing];
  clock.restart();

  double t{0};
  double dt{0.01};
  double accu {0};
  double current_time {0};
  double frame_time {0};
  double new_time;
  std::array<double, 3> pos_prev {0,0,0};
  std::array<double, 3> pos_curr {0,0,0};
  std::array<double, 3> pos_rend {0,0,0};
  
  while (next_state == (*go_to_states)[State::Type::playing]) {
    new_time = clock.getElapsedTime().asSeconds();
    frame_time = new_time - current_time;
    current_time = new_time;
    accu += frame_time;
    while(accu >= dt) {
     next_state = processEvents();
      pos_prev = pos_curr;
      update_pos(pos_curr,t,dt);
      t += dt;
      accu -= dt;
    }
    double alpha = accu / dt;
    pos_rend =((pos_prev - pos_curr) * alpha) + pos_prev;
    car.map_pos(pos_rend);
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
      std::cout << "key pressed\n";
      state = handleInput(event.key.code, true);
      break;
    // case sf::Event::KeyReleased:
    //   state = handleInput(event.key.code, false);
    //   break;
    case sf::Event::Closed:
      return (*go_to_states)[State::Type::quitting];
      break;
    default:;
    }
  }
  return state;
}

State* Race::handleInput (sf::Keyboard::Key key, bool isPressed) {
  if( key == sf::Keyboard::Right) {
    std::cout << "right key pressed\n";
    car.v[0] += 1.0;
  }
  if( key == sf::Keyboard::Down) {
    car.v[1] += 1.0;
  }
  if( key == sf::Keyboard::Left) {
    car.v[0] -= 1.0;
  }
  if( key == sf::Keyboard::Up) {
    car.v[1] -= 1.0;
  }
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

void Race::update_pos(std::array<double,3>&  pos, double t, double dt) {
  for ( auto i = 0; i != 3; ++i) {
    pos[i]+= dt * car.v[i];
  }
}
  
void Race::render(const std::array<double, 3>& pos) {
  window->clear();
  window->draw(car.shape);
  window->display();
}
