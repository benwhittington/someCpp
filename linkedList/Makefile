SOURCES := $(wildcard src/*.cpp)
OBJECTS := $(patsubst src/%.cpp,obj/%.o,$(SOURCES))
DEPENDS := $(patsubst src/%.cpp,obj/%.d,$(SOURCES))

WARNING := -Wall -Wextra

# .PHONY: all clean

all: main

run: main
	echo "" && ./main

clean:
	$(RM) $(OBJECTS) $(DEPENDS) main

main: $(OBJECTS)
	$(CXX) $(WARNING) $(CXXFLAGS) $^ -o $@

-include $(DEPENDS)

obj/%.o: src/%.cpp Makefile
	$(CXX) $(WARNING) $(CXXFLAGS) -MMD -MP -c $< -o $@
