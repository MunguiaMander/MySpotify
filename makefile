CXX = g++
CXXFLAGS = -Wall -g -O0 -I/usr/include/fmod
LDFLAGS = -L/usr/lib/x86_64
LIBS = -lfmod

OBJ_DIR = obj
SRC_DIR = src
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/song.o $(OBJ_DIR)/NormalPlayer.o $(OBJ_DIR)/BuclePlayer.o $(OBJ_DIR)/MusicPlayer.o $(OBJ_DIR)/SongLibrary.o

my_spotify: $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) $(LIBS) -o my_spotify

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) my_spotify