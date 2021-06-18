SOURCES := $(wildcard src/*.cpp)
OBJECTS := $(patsubst src/%.cpp,obj/%.o,$(SOURCES))
DEPENDS := $(patsubst src/%.cpp,obj/%.d,$(SOURCES))

# ADD MORE WARNINGS!
WARNING := -Wall -Wextra

# .PHONY means these rules get executed even if
# files of those names exist.
.PHONY: all clean

# The first rule is the default, ie. "make",
# "make all" and "make parking" mean the same

all: main

run: main
	echo "" && ./main

clean:
	$(RM) $(OBJECTS) $(DEPENDS) main

# Linking the executable from the object files
main: $(OBJECTS)
	$(CXX) $(WARNING) $(CXXFLAGS) $^ -o $@

-include $(DEPENDS)

obj/%.o: src/%.cpp Makefile
	$(CXX) $(WARNING) $(CXXFLAGS) -MMD -MP -c $< -o $@

# CXX=g++
# FLAGS=-Wall -g

# OBJS=obj/main.o obj/linkedList.o obj/node.o

# RM=rm

# all: main

# clean:
# 	$(RM) $(OBJS)

# main: $(OBJS)
# 	$(CXX) $(FLAGS) obj/main.o obj/linkedList.o obj/node.o -o main

# obj/main.o: src/main.cpp
# 	$(CXX) $(FLAGS) -c src/main.cpp -o obj/main.o

# obj/linkedList.o: src/linkedList.cpp src/linkedList.hpp
# 	$(CXX) $(FLAGS) -c src/linkedList.cpp -o obj/linkedList.o

# obj/node.o: src/node.cpp src/node.hpp
# 	$(CXX) $(FLAGS) -c src/node.cpp -o obj/node.o