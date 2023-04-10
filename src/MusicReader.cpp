#include "MusicReader.h"
#include "pugixml.hpp"
#include <iostream>
#include <string>
#include <sstream>

MusicReader::MusicReader()
{
}

void MusicReader::readXML(const std::string &filename, SongLibrary &library)
{
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(filename.c_str());

    if (!result)
    {
        std::cout << "Error al cargar el archivo XML: " << result.description() << std::endl;
        return;
    }

    for (pugi::xml_node command : doc.children())
    {
        if (std::string(command.name()) == "Insertar")
        {
            for (pugi::xml_node songNode : command.children("cancion"))
            {
                std::string songName = songNode.child("Nombre").text().as_string();
                std::string songPath = songNode.child("path").text().as_string();

                if (songNode.child("Pos"))
                {
                    int pos = songNode.child("Pos").text().as_int() - 1;
                    library.addSong(songName, songPath, pos);
                }
                else
                {
                    library.addSong(songName, songPath);
                }
            }
        }
        else if (std::string(command.name()) == "Eliminar")
        {
            for (pugi::xml_node songNode : command.children("cancion"))
            {
                if (songNode.child("id"))
                {
                    int id = songNode.child("id").text().as_int() - 1;
                    library.removeSongByIndex(id);
                }
                else if (songNode.child("Nombre"))
                {
                    std::string songName = songNode.child("Nombre").text().as_string();
                    library.removeSongByName(songName);
                }
            }
        }
    }
}
