#pragma once
#include "Player.h"
#include "song.h"
#include "SongLibrary.h"
#include <iostream>

class NormalPlayer : public Player
{
private:
    song *first;
    song *last;
    int totalSongs;

public:
    NormalPlayer();
    ~NormalPlayer();
    song *getFirst() override;
    void addSongsFromLibrary(const SongLibrary &songLibrary);
    void addSong(string name, string path);
    void removeSong(int num);
    void printUpcomingSongs(song *current) override;
    void clearNormalPlayer();
};