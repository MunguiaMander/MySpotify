#pragma once
#include "Player.h"
#include "NormalPlayer.h"
#include <unistd.h>

using namespace std;

class MusicPlayer
{
public:
    MusicPlayer();
    void playMusic(Player &player);
};
