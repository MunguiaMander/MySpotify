#include "Player.h"
#include "NormalPlayer.h"
#include "BuclePlayer.h"
#include "MusicPlayer.h"
#include "SongLibrary.h"
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

using namespace std;

void print_main_menu(int option);
void print_play_options(MusicPlayer &musicPlayer, NormalPlayer &normalPlayer, BuclePlayer &buclePlayer, SongLibrary &songLibrary);
void print_song_options(SongLibrary &songLibrary);

int option;

int main(int argc, char const *argv[])
{
    option = 0;
    print_main_menu(option);
    return 0;
}

void print_main_menu(int option)
{
    MusicPlayer musicPlayer = MusicPlayer();
    NormalPlayer normalPlayer;
    BuclePlayer buclePlayer;
    SongLibrary songLibrary = SongLibrary();
    songLibrary.addSong("50 Cent  Many Men.mp3", "../PrimerProyecto/Musica/50 Cent  Many Men.mp3");
    songLibrary.addSong("Matando - Gueros 97", "../PrimerProyecto/Musica/Matando - Gueros 97.mp3");
    songLibrary.addSong("Peso Pluma Raul Vega El Belicon", "../PrimerProyecto/Musica/Peso Pluma Raul Vega El Belicon .mp3");

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
        switch (option)
        {
        case 1:
            print_song_options(songLibrary);
            break;
        case 2:
            break;
        case 3:
            print_play_options(musicPlayer, normalPlayer, buclePlayer, songLibrary);
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

void print_song_options(SongLibrary &songLibrary)
{
    int option = 0;
    do
    {
        cout << "Ingrese la opcion que desea para la biblioteca de canciones" << endl;
        cout << "1) Ingresar canciones manualmente" << endl;
        cout << "2) Eliminar canciones por ID" << endl;
        cout << "3) Eliminar canciones por Nombre" << endl;
        cout << "4) Buscar canciones" << endl;
        cout << "5) Listar canciones" << endl;
        cout << "6) Regresar al menu" << endl;
        cin >> option;
        cin.ignore();
        string songName;
        string songPath;
        string tmpSearchRef;
        int songIndex;
        switch (option)
        {
        case 1:
            cout << "Ingrese el nombre de la cacion" << endl;
            getline(cin, songName);

            cout << "Ingrese el path relativo (a la carpeta raiz del archivo ejecutable) de la cancion" << endl;
            getline(cin, songPath);

            songLibrary.addSong(songName, songPath);
            break;
        case 2:
            songLibrary.printSongs();
            cout << "Ingrese el numero de cancion a eliminar de la biblioteca de canciones" << endl;
            cin >> songIndex;
            songLibrary.removeSongByIndex(songIndex - 1);
            break;
        case 3:
            songLibrary.printSongs();
            cout << "Ingrese el nombre de la cancion que desea eliminar (Debe ser Exacto)" << endl;
            getline(cin, tmpSearchRef);
            songLibrary.removeSongByName(tmpSearchRef);
            break;
        case 4:
            cout << "Ingrese el termino que desea buscar para buscar similitudes en la biblioteca de canciones" << endl;
            getline(cin, tmpSearchRef);
            songLibrary.searchAndPrint(tmpSearchRef);
            break;
        case 5:
            songLibrary.printSongs();
            break;
        case 6:
            break;

        default:
            break;
        }
    } while (option != 6);
}

void print_playlist_options()
{
}

void print_play_options(MusicPlayer &musicPlayer, NormalPlayer &normalPlayer, BuclePlayer &buclePlayer, SongLibrary &songLibrary)
{
    int option = 0;
    do
    {
        int playOption;
        cout << "Ingrese la opcion a Reproducir" << endl;
        cout << "1) Biblioteca General de Musica" << endl;
        cout << "2) Playlist Personalizada " << endl;
        cout << "3) Regresar al Menu Principal " << endl;
        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
        {
            normalPlayer = NormalPlayer();
            buclePlayer = BuclePlayer();
            cout << "Seleccione la reproduccion que desea" << endl;
            cout << "1) Normal" << endl;
            cout << "2) Repetir" << endl;
            cin >> playOption;
            cin.ignore();
            switch (playOption)
            {
            case 1:
                normalPlayer.addSongsFromLibrary(songLibrary);
                musicPlayer.playMusic(normalPlayer);
                normalPlayer.clearPlayer();
                break;
            case 2:
                buclePlayer.addSongsFromLibrary(songLibrary);
                musicPlayer.playMusic(buclePlayer);
                break;
            default:
                break;
            }
        }
        break;
        case 2:

            break;
        default:
            break;
        }

    } while (option != 3);
}

void massive_upload()
{
}
