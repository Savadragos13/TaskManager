#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <string>
using namespace std;

struct Task {
    int id;
    string descriere;
    bool completat;
};

void adaugaTask(Task v[], int &n, string descriere);
void afiseazaTaskuri(Task v[], int n);
void marcheazaCompletat(Task v[], int n, int id);
void stergeTask(Task v[], int &n, int id);

#endif

