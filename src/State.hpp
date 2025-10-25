#ifndef STATEHPP
#define STATEHPP 1

class State {
public:
    enum Type {
    playing,
    quitting,
    count,
  };
  
  virtual State* progress() = 0;
  virtual ~State() = default;
};

class Quitter : public State {
  State* progress() {return nullptr;}
};

#endif
