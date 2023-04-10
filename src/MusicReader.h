#pragma once
#include "SongLibrary.h"
#include <string>

class MusicReader
{
public:
    MusicReader();
    void readXML(const std::string &filename, SongLibrary &library);
};
