CXX=g++
CXXFLAGS=-Wall -g -std=c++14
SOURCE=$(wildcard src/*.cpp)
OBJECTS=$(addprefix obj/,$(notdir $(SOURCE:.cpp=.o)))
TARGET=bin/shmup
LIBS=-lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio

$(TARGET): $(OBJECTS)
	mkdir -p bin
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS) 

obj/%.o: src/%.cpp
	mkdir -p obj
	$(CXX) $(CXXFLAGS) -c -o $@ $< $(LIBS)

clean:
	find . -name '*.gch' -type f -delete
	find . -name '*.o' -type f -delete
	rm -f core
	rm -f $(TARGET)
