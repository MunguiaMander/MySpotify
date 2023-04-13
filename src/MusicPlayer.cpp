#include "Player.h"
#include "NormalPlayer.h"
#include "MusicPlayer.h"
#include "StackPlayer.h"
#include "SongLibrary.h"
#include <unistd.h>
#include "fmod.hpp"
#include <fmod_errors.h>
#include <poll.h>
#include <fcntl.h>
#include <limits>

MusicPlayer::MusicPlayer()
{
}

void MusicPlayer::playMusic(Player &player, SongLibrary &songLibrary)
{
    FMOD::System *system;
    FMOD::Sound *sound;
    FMOD::Channel *channel = 0;

    FMOD::System_Create(&system);
    system->init(32, FMOD_INIT_NORMAL, NULL);

    song *current = player.getFirst();
    bool stopPlaying = false;

    // Establecer el descriptor de archivo en modo no bloqueante
    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);

    while (current != NULL && !stopPlaying)
    {
        std::string audioPath = current->getPath();

        system->createSound(audioPath.c_str(), FMOD_CREATESTREAM, 0, &sound);

        std::cout << "Reproduciendo " << current->getName() << std::endl;
        std::cout << "q = Para salir | r = Cancion anterior | s = Siguiente cancion | a = Agregar cancion/es a la Pila | m = Mostrar siguientes canciones" << std::endl;
        system->playSound(sound, 0, false, &channel);

        bool isPlaying = true;
        while (isPlaying && !stopPlaying)
        {
            system->update();
            channel->isPlaying(&isPlaying);
            usleep(1000);

            // Comprobar si hay entrada del usuario
            struct pollfd pfd;
            pfd.fd = STDIN_FILENO;
            pfd.events = POLLIN;

            int pollResult = poll(&pfd, 1, 0);
            if (pollResult > 0)
            {
                char inputChar;
                read(STDIN_FILENO, &inputChar, 1);
                switch (inputChar)
                {
                case 'a':
                {
                    fcntl(STDIN_FILENO, F_SETFL, flags);
                    SongLibrary stackTmp = SongLibrary();
                    int option = 0;
                    std::cin.ignore();

                    while (true)
                    {
                        std::cout << "0. Agregar una canción a la pila" << std::endl;
                        std::cout << "1. Salir" << std::endl;
                        std::cin >> option;
                        std::cin.ignore();

                        if (option == 0)
                        {
                            songLibrary.printSongs();
                            std::cout << "Ingrese el número de la canción que desea agregar a la pila: ";
                            int songIndex;
                            std::cin >> songIndex;
                            songIndex--;

                            if (songIndex >= 0 && songIndex < songLibrary.getSongCount())
                            {
                                stackTmp.addSong(songLibrary.getSongName(songIndex), songLibrary.getSongPath(songIndex));
                            }
                            else
                            {
                                std::cout << "Índice de canción inválido. Por favor, inténtelo de nuevo." << std::endl;
                            }
                        }
                        else if (option == 1)
                        {
                            break;
                        }
                        else
                        {
                            std::cout << "Opción inválida. Por favor, inténtelo de nuevo." << std::endl;
                        }
                    }
                    sound->release();
                    StackPlayer stackPlayer;
                    stackPlayer.addSongsFromLibrary(stackTmp);
                    playMusic(stackPlayer, songLibrary);
                }
                break;
                case 's':
                    // Pasar a la siguiente canción
                    isPlaying = false;
                    break;
                case 'r':
                    // Regresar a la canción anterior
                    if (current->getPrev() != NULL)
                    {
                        current = current->getPrev();
                        if (current->getPrev() != NULL)
                        {
                            current = current->getPrev();
                        }
                        else
                        {
                            // Si se encuentra en la segunda canción de la lista y se presiona 'r'
                            current = player.getFirst();
                        }
                        isPlaying = false;
                    }
                    break;
                case 'm':
                    // Mostrar las canciones que seguirán
                    player.printUpcomingSongs(current);
                    break;
                case 'q':
                    // Salir del modo de reproducción
                    stopPlaying = true;
                    break;
                }
            }
        }

        sound->release();
        if (!stopPlaying)
        {
            current = current->getNext();
        }
    }

    system->close();
    system->release();

    // Restaurar el modo de bloqueo en el descriptor de archivo
    fcntl(STDIN_FILENO, F_SETFL, flags);
}