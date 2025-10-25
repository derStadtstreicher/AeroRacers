#ifndef APPHPP
#define APPHPP

#include <map>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

#include "State.hpp"
#include "Race.hpp"

class App {

public:
  App();
  void run();

  sf::RenderWindow window;
  std::vector<State*> states;

  Race race;
  Quitter quitter;
};
 
#endif
