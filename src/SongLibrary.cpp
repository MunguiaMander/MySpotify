#include "SongLibrary.h"
#include <string>
#include <iostream>

SongLibrary::SongLibrary()
{
}

SongLibrary::~SongLibrary()
{
    delete[] songs;
}

void SongLibrary::addSong(const std::string &name, const std::string &path, int index)
{
    if (index < 0 || index > songCount)
    {
        // Si el índice está fuera de los límites, agregar al final
        index = songCount;
    }

    SongInfo *newSongs = new SongInfo[songCount + 1];

    for (int i = 0; i < index; i++)
    {
        newSongs[i] = songs[i];
    }

    newSongs[index].name = name;
    newSongs[index].path = path;

    for (int i = index + 1; i <= songCount; i++)
    {
        newSongs[i] = songs[i - 1];
    }

    delete[] songs;
    songs = newSongs;
    songCount++;
}

void SongLibrary::printSongs() const
{
    for (int i = 0; i < songCount; i++)
    {
        std::cout << (i + 1) << ") " << songs[i].name << std::endl;
    }
}

void SongLibrary::searchAndPrint(const std::string &searchTerm) const
{
    bool found = false;
    std::cout << "Canciones encontradas:" << std::endl;
    for (int i = 0; i < songCount; i++)
    {
        if (songs[i].name.find(searchTerm) != std::string::npos)
        {
            std::cout << (i + 1) << ") " << songs[i].name << std::endl;
            found = true;
        }
    }
    if (!found)
    {
        std::cout << "No se encontraron canciones con el término de búsqueda \"" << searchTerm << "\"." << std::endl;
    }
    std::cout << std::endl;
}

void SongLibrary::removeSongByIndex(int index)
{
    if (index < 0 || index >= songCount)
    {
        return;
    }

    SongInfo *newSongs = new SongInfo[songCount - 1];

    for (int i = 0; i < index; i++)
    {
        newSongs[i] = songs[i];
    }

    for (int i = index + 1; i < songCount; i++)
    {
        newSongs[i - 1] = songs[i];
    }

    delete[] songs;
    songs = newSongs;
    songCount--;
}

void SongLibrary::removeSongByName(const std::string &name)
{
    int index = -1;

    for (int i = 0; i < songCount; i++)
    {
        if (songs[i].name == name)
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        removeSongByIndex(index);
    }
}

std::string SongLibrary::getSongName(int index) const
{
    if (index < 0 || index >= songCount)
    {
        return "";
    }
    return songs[index].name;
}

std::string SongLibrary::getSongPath(int index) const
{
    if (index < 0 || index >= songCount)
    {
        return "";
    }
    return songs[index].path;
}

int SongLibrary::getSongCount() const
{
    return songCount;
}
