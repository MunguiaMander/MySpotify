#include "song.h"
#include <iostream>
#include <string>
using namespace std;

song::song(string name, string path, int num)
{   
    this->name = name;
    this->path = path;
    this->num = num;
    next = NULL;
    prev = NULL;
}

// Getters de los atributos del nodo "Song"
string song::getName()
{
    return name;
}

string song::getPath()
{
    return path;
}

song *song::getNext()
{
    return next;
}

song *song::getPrev()
{
    return prev;
}

int song::getNum()
{
    return num;
}

// Setters de los atributos del nodo "Song"
void song::setNum(int num)
{
    this->num = num;
}

void song::setName(string name)
{
    this->name = name;
}

void song::setPath(string path)
{
    this->path = path;
}

void song::setNext(song *next)
{
    this->next = next;
}

void song::setPrev(song *prev)
{
    this->prev = prev;
}
