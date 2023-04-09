#pragma once
#include "song.h"
#include <string>

class Player
{
public:
    // Destructor virtual
    virtual ~Player() {}
    // Funciones virtuales puras que se sobreescriben
    virtual song *getFirst() = 0;
    virtual void printUpcomingSongs(song *currentSong) = 0;
};
