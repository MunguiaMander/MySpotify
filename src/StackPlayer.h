#pragma once
#include "Player.h"
#include "song.h"
#include "SongLibrary.h"
#include <string>

class StackPlayer : public Player
{
private:
    song *top;
    int totalSongs;

public:
    StackPlayer();
    ~StackPlayer();

    song *getFirst() override;
    void printUpcomingSongs(song *currentSong) override;
    void addSongsFromLibrary(const SongLibrary &songLibrary);
    void clearPlayer() override;
    void pushSong(const std::string &name, const std::string &path);
};
