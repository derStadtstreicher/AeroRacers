SHELL=/bin/bash
CXX := g++
CXXFLAGS := -Wall -Wpedantic -O3 #-fsanitize=address
LDFLAGS := -lsfml-graphics -lsfml-window -lsfml-system #-fsanitize=address

srcd := ./src

buildd := ./build
cpps := $(shell find  $(srcd) -name '*.cpp')
objs := $(patsubst $(srcd)/%.cpp,$(buildd)/%.o,$(cpps))

all: builddir AeroRacers

builddir:
	mkdir -p $(buildd)

AeroRacers: $(objs)
	$(CXX) $^ $(LDFLAGS) -o $@

$(objs): $(buildd)/%.o: $(srcd)/%.cpp
	$(CXX) -c $^ -o $@ $(CXXFLAGS)


.PHONY: clean
clean:
	rm -f $(buildd)/*.o
	rm -f $(srcd)/*~







