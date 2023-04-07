CXX = g++
CXXFLAGS = -Wall -g -I/usr/include/fmod
LDFLAGS = -L/usr/lib/x86_64
LIBS = -lfmod

OBJ_DIR = obj
SRC_DIR = src
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/song.o $(OBJ_DIR)/library.o

my_spotify: $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) $(LIBS) -o my_spotify

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) my_spotify