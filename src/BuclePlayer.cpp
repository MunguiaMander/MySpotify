#include "BuclePlayer.h"
#include "song.h"
#include <iostream>
#include <string>

BuclePlayer::BuclePlayer() : Player()
{
    first = NULL;
    last = NULL;
    totalSongs = 0;
}

BuclePlayer::~BuclePlayer()
{
    if (first != NULL)
    {
        last->song::setNext(NULL); // romper el ciclo antes de eliminar
    }

    song *actual = first;
    while (actual != NULL)
    {
        song *next = actual->song::getNext();
        delete actual;
        actual = next;
    }
}

song *BuclePlayer::getFirst()
{
    return first;
}

void BuclePlayer::addSong(std::string name, std::string path)
{
    totalSongs++; // Incrementar el contador de canciones
    song *tmpSong = new song(name, path, totalSongs);
    tmpSong->song::setNext(NULL);
    tmpSong->song::setPrev(last);

    if (last != NULL)
    {
        last->song::setNext(tmpSong);
    }
    else
    {
        first = tmpSong;
    }
    last = tmpSong;

    // Crear el ciclo en la lista doblemente enlazada
    first->song::setPrev(last);
    last->song::setNext(first);
}

void BuclePlayer::addSongsFromLibrary(const SongLibrary &songLibrary)
{
    for (int i = 0; i < songLibrary.getSongCount(); ++i)
    {
        addSong(songLibrary.getSongName(i), songLibrary.getSongPath(i));
    }
}

void BuclePlayer::printUpcomingSongs(song *current)
{
    if (current == NULL)
    {
        std::cout << "No hay canciones en la lista." << std::endl;
        return;
    }

    song *nextSong = current->getNext();
    if (nextSong == NULL)
    {
        std::cout << "No hay más canciones por reproducir." << std::endl;
    }
    else
    {
        std::cout << "Canciones siguientes:" << std::endl;
        while (nextSong != NULL)
        {
            std::cout << nextSong->getNum() << ") " << nextSong->getName() << std::endl;
            nextSong = nextSong->getNext();
        }
    }
    std::cout << std::endl;
}

void BuclePlayer::clearBuclePlayer()
{
    song *current = first;
    while (current != NULL)
    {
        song *next = current->getNext();
        delete current;
        current = next;
    }

    first = NULL;
    last = NULL;
    totalSongs = 0;
}