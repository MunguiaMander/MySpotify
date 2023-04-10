CXX = g++
CXXFLAGS = -Wall -g -O0 -I/usr/include/fmod -I/usr/local/include
LDFLAGS = -L/usr/lib/x86_64 -L/usr/local/lib
LIBS = -lfmod -lpugixml

OBJ_DIR = obj
SRC_DIR = src
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/song.o $(OBJ_DIR)/NormalPlayer.o $(OBJ_DIR)/BuclePlayer.o $(OBJ_DIR)/MusicPlayer.o $(OBJ_DIR)/SongLibrary.o $(OBJ_DIR)/MusicReader.o

my_spotify: $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) $(LIBS) -o my_spotify

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

.PHONY: clean
clean:
	rm -f $(OBJS) my_spotify

InitProyect:
	./InitProyect.sh