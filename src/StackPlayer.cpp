#include "StackPlayer.h"
#include "song.h"
#include "SongLibrary.h"
#include <iostream>

StackPlayer::StackPlayer() : Player()
{
    top = NULL;
    totalSongs = 0;
}

StackPlayer::~StackPlayer()
{
    clearPlayer();
}

song *StackPlayer::getFirst()
{
    return top;
}

void StackPlayer::printUpcomingSongs(song *currentSong)
{
    if (currentSong == NULL)
    {
        std::cout << "No hay canciones en la pila." << std::endl;
        return;
    }

    song *nextSong = currentSong->getNext();
    if (nextSong == NULL)
    {
        std::cout << "No hay más canciones por reproducir en la pila." << std::endl;
    }
    else
    {
        std::cout << "Canciones siguientes en la pila:" << std::endl;
        while (nextSong != NULL)
        {
            std::cout << nextSong->getNum() << ") " << nextSong->getName() << std::endl;
            nextSong = nextSong->getNext();
        }
    }
    std::cout << std::endl;
}

void StackPlayer::clearPlayer()
{
    song *current = top;
    while (current != NULL)
    {
        song *next = current->getNext();
        delete current;
        current = next;
    }

    top = NULL;
    totalSongs = 0;
}


void StackPlayer::addSongsFromLibrary(const SongLibrary &songLibrary)
{
    for (int i = 0; i < songLibrary.getSongCount(); ++i)
    {
        pushSong(songLibrary.getSongName(i), songLibrary.getSongPath(i));
    }
}

void StackPlayer::pushSong(const std::string &name, const std::string &path)
{
    totalSongs++; // Incrementar el contador de canciones
    song *tmpSong = new song(name, path, totalSongs);
    tmpSong->song::setNext(top);
    tmpSong->song::setPrev(NULL);
    if (top != NULL)
    {
        top->song::setPrev(tmpSong);
    }
    top = tmpSong;
}
