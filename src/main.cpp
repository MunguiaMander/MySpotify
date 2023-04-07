#include <iostream>
#include <fstream>
#include <string>
#include "library.h"
#include <unistd.h>
#include "fmod.hpp"

using namespace std;

void print_main_menu(int option);
void playMusic();

int main(int argc, char const *argv[])
{

    int option = 0;
    print_main_menu(option);
    return 0;
}

void print_main_menu(int option)
{

    do
    {
        cout << " \n\n\n\n\n\n\n\n\n\n\n\n"
             << endl;
        cout << " ____  ____   ___ _____ ___ _______   __" << endl;
        cout << "/ ___||  _ \\ / _ \\_   _|_ _|  ___\\ \\ / /" << endl;
        cout << "\\___ \\| |_) | | | || |  | || |_   \\ V / " << endl;
        cout << " ___) |  __/| |_| || |  | ||  _|   | |  " << endl;
        cout << "|____/|_|    \\___/ |_| |___|_|     |_|  " << endl;
        cout << "" << endl;
        cout << "1. Operaciones de Canciones" << endl;
        cout << "2. Operaciones de Playlist" << endl;
        cout << "3. Reproduccion" << endl;
        cout << "4. Carga Masiva" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> option;
        library library_songs = library();
        switch (option)
        {
        case 1:
            library_songs.addSong("Sepultura - Arise", "path/to/song");
            library_songs.addSong("Sepultura - Desperate Cry", "path/to/song");
            library_songs.addSong("Sepultura - Roots Bloody Roots", "path/to/song");
            library_songs.addSong("Fuerza Regida X Edgardo - Billete Grande", "path/to/song");
            library_songs.addSong("Junior H - 1004 Kilometros", "path/to/song");
            library_songs.addSong("Natanael Cano X Junior H - El Drip", "path/to/song");
            library_songs.addSong("Slipknot - Before I Forget", "path/to/song");
            library_songs.addSong("Fuerza Regida X Grupo Frontera - Bebe Dame", "path/to/song");
            library_songs.printSongs();
            library_songs.removeSong(1);
            library_songs.printSongs();
            library_songs.searchSongs("Fuerza");
            playMusic();
            break;
        case 2:

            break;
        case 3:
            break;
        case 4:

            break;
        case 5:
            break;
        default:

            break;
        }
    } while (option != 5);
}

void print_song_options()
{
}

void print_playlist_options()
{
}

void print_play_options()
{
}

void massive_upload()
{
}

void playMusic()
{
    FMOD::System *system;
    FMOD::Sound *sound;
    FMOD::Channel *channel = 0;

    std::string audioPath = "../PrimerProyecto/Musica/MF DOOM - Doomsday.mp3";

    FMOD::System_Create(&system);
    system->init(32, FMOD_INIT_NORMAL, NULL);
    system->createSound(audioPath.c_str(), FMOD_CREATESTREAM, 0, &sound);

    std::cout << "Reproduciendo " << audioPath << std::endl;
    system->playSound(sound, 0, false, &channel);

    bool isPlaying = true;
    while (isPlaying)
    {
        system->update();
        channel->isPlaying(&isPlaying);
        usleep(1000);
    }

    sound->release();
    system->close();
    system->release();
}
