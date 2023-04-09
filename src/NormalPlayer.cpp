#include "Player.h"
#include "song.h"
#include "NormalPlayer.h"
#include "SongLibrary.h"
#include <iostream>
#include <string>
using namespace std;

NormalPlayer::NormalPlayer() : Player()
{
    first = NULL;
    last = NULL;
    totalSongs = 0;
}

NormalPlayer::~NormalPlayer()
{
    song *actual = first;
    while (actual != NULL)
    {

        song *next = actual->song::getNext();
        delete actual;
        actual = next;
    }
}

song *NormalPlayer::getFirst()
{
    return first;
}

void NormalPlayer::addSong(string name, string path)
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
}

void NormalPlayer::addSongsFromLibrary(const SongLibrary &songLibrary)
{
    for (int i = 0; i < songLibrary.getSongCount(); ++i)
    {
        addSong(songLibrary.getSongName(i), songLibrary.getSongPath(i));
    }
}

void NormalPlayer::removeSong(int num)
{
    song *current = first;
    while (current != NULL)
    {
        if (current->getNum() == num)
        {
            // Enlazar el nodo previo al siguiente
            if (current->getPrev() != NULL)
            {
                current->getPrev()->setNext(current->getNext());
            }
            else
            {
                first = current->getNext();
            }

            // Enlazar el nodo siguiente al previo
            if (current->getNext() != NULL)
            {
                current->getNext()->setPrev(current->getPrev());
            }
            else
            {
                last = current->getPrev();
            }

            // Actualizar los números de las canciones siguientes
            song *next = current->getNext();
            while (next != NULL)
            {
                next->setNum(next->getNum() - 1);
                next = next->getNext();
            }

            delete current;
            totalSongs--; // Decrementar el contador de canciones
            break;
        }
        current = current->getNext();
    }
}

void NormalPlayer::printUpcomingSongs(song *current)
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

void NormalPlayer::clearNormalPlayer()
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