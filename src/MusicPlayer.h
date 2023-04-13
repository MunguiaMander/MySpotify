#pragma once
#include "Player.h"
#include "NormalPlayer.h"
#include "SongLibrary.h"
#include <unistd.h>

using namespace std;

class MusicPlayer
{
public:
    MusicPlayer();
    void playMusic(Player &player, SongLibrary &songLibrary);
};
