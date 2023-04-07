#include "library.h"
#include "song.h"
#include <iostream>
#include <string>
using namespace std;

library::library()
{
    first = NULL;
    last = NULL;
    totalSongs = 0;
}

library::~library()
{
    song *actual = first;
    while (actual != NULL)
    {

        song *next = actual->song::getNext();
        delete actual;
        actual = next;
    }
}

void library::addSong(string name, string path)
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

void library::removeSong(int num)
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

void library::searchSongs(const string &searchTerm)
{
    song *current = first;
    bool found = false;
    cout << "Canciones encontradas:" << endl;
    while (current != NULL)
    {
        if (current->getName().find(searchTerm) != string::npos)
        {
            cout << current->getNum() << ") " << current->getName() << endl;
            found = true;
        }
        current = current->getNext();
    }
    if (!found)
    {
        cout << "No se encontraron canciones con el término de búsqueda \"" << searchTerm << "\"." << endl;
    }
    cout << endl;
}


void library::printSongs()
{
    song *actual = first;
    while (actual != NULL)
    {
        cout << actual->song::getNum() << ") "<<actual->song::getName() << " - " << actual->song::getPath() << endl;
        actual = actual->song::getNext();
    }
    cout << endl;
}
