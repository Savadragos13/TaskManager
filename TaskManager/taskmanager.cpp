#include "taskmanager.h"
#include <iostream>
using namespace std;

void adaugaTask(Task v[], int &n, string descriere){
    v[n].id = n + 1;
    v[n].descriere = descriere;
    v[n].completat = false;
    n++;
}

void afiseazaTaskuri(Task v[], int n){
    if(n == 0)
        cout<<"Nu exista taskuri."<<endl;
    for(int i = 0; i < n; i++){
        cout<<"["<<(v[i].completat ? "X" : " ")<<"] ";
        cout<<v[i].id<<". "<<v[i].descriere<<endl;
    }
}

void marcheazaCompletat(Task v[], int n, int id){
    for(int i = 0; i < n; i++)
        if(v[i].id == id){
            v[i].completat = true;
            cout<<"Taskul a fost marcat ca finalizat.\n";
            return;
        }
    cout<<"Taskul nu a fost gasit.\n";
}

void stergeTask(Task v[], int &n, int id){
    int poz = -1;
    for(int i = 0; i < n; i++)
        if(v[i].id == id)
            poz = i;
    if(poz == -1){
        cout<<"Taskul nu a fost gasit.\n";
        return;
    }
    for(int i = poz; i < n - 1; i++)
        v[i] = v[i + 1];
    n--;
    cout<<"Taskul a fost sters.\n";
}

