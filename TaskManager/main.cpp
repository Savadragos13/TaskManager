#include <iostream>
#include "taskmanager.h"
using namespace std;

int main(){
    Task taskuri[100];
    int n = 0, optiune, id;
    string descriere;

    do {
        cout<<"\n===== Task Manager ====="<<endl;
        cout<<"1. Adauga task\n";
        cout<<"2. Afiseaza taskuri\n";
        cout<<"3. Marcheaza completat\n";
        cout<<"4. Sterge task\n";
        cout<<"0. Iesire\n";
        cout<<"Alege optiunea: ";
        cin>>optiune;
        cin.ignore();

        switch(optiune){
            case 1:
                cout<<"Descriere task: ";
                getline(cin, descriere);
                adaugaTask(taskuri, n, descriere);
                break;
            case 2:
                afiseazaTaskuri(taskuri, n);
                break;
            case 3:
                cout<<"ID-ul taskului: ";
                cin>>id;
                marcheazaCompletat(taskuri, n, id);
                break;
            case 4:
                cout<<"ID-ul taskului: ";
                cin>>id;
                stergeTask(taskuri, n, id);
                break;
            case 0:
                cout<<"La revedere!\n";
                break;
            default:
                cout<<"Optiune invalida!\n";
        }

    } while(optiune != 0);

    return 0;
}
