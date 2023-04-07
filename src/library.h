#pragma once
#include <iostream>
using namespace std;
#include "song.h"

class library
{
private:
    song *first;
    song *last;
    int totalSongs;

public:
    library();
    ~library();
    void addSong(string name, string path);
    void removeSong(int num);
    void searchSongs(const string &searchTerm);
    void printSongs();
};