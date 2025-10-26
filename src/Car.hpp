#ifndef CAR_H
#define CAR_H

#include "settings.hpp"
#include <array>

struct Car {
  double mass;
  std::array<double,3> v;
  std::array<double, 3> r;
  sf::CircleShape shape;

  Car() : v{0,0,0},shape( sf::CircleShape(50.f)) {
    init_shape();
  }

  void init_shape() {
    shape.setFillColor(sf::Color(10,250,50));
  }
  
  void map_pos(const std::array<double, 3> phys_pos) {
    static const double full_X = 100.0;
    static const double full_Y = 100.0;
    
    shape.setPosition({X*phys_pos[0]/full_X, Y*phys_pos[1]/full_Y});
  }

};

#endif
