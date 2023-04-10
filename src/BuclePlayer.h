#pragma once
#include "Player.h"
#include "song.h"
#include "SongLibrary.h"
#include <iostream>

class BuclePlayer : public Player
{
private:
    song *first;
    song *last;
    int totalSongs;

public:
    BuclePlayer();
    ~BuclePlayer();
    song *getFirst() override;
    void addSong(std::string name, std::string path);
    void addSongsFromLibrary(const SongLibrary &songLibrary);
    void printUpcomingSongs(song *current) override;
    void clearPlayer() override;
};