#pragma once
#include <iostream>
using namespace std;

class song
{
private:
    string name;
    string path;
    int num;
    song *next;
    song *prev;

public:
    song(string name, string path, int num);
    string getName();
    string getPath();
    song *getNext();
    song *getPrev();
    int getNum();
    void setNum(int num);
    void setName(string name);
    void setPath(string path);
    void setNext(song *next);
    void setPrev(song *prev);
};
