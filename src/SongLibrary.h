#pragma once
#include <string>
#include <vector>

class SongLibrary
{

private:
    struct SongInfo
    {
        std::string name;
        std::string path;
    };
    SongInfo *songs = nullptr;
    int songCount = 0;

public:
    SongLibrary();
    ~SongLibrary();

    void addSong(const std::string &name, const std::string &path, int index = -1);
    void printSongs() const;
    void searchAndPrint(const std::string &searchTerm) const;
    void removeSongByIndex(int index);
    void removeSongByName(const std::string &name);
    std::string getSongName(int index) const;
    std::string getSongPath(int index) const;
    int getSongCount() const;
};