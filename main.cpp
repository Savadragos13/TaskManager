#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "task.hpp"

using namespace std;

vector<Task> tasks;
int nextId = 1;

void loadTasks() {
    ifstream file("tasks.txt");
    if (!file.is_open()) return;

    tasks.clear();
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        int id;
        bool completed;
        string desc;

        ss >> id >> completed;
        getline(ss, desc);
        if (!desc.empty() && desc[0] == ' ') desc.erase(0, 1);

        tasks.emplace_back(id, desc, completed);

        if (id >= nextId) nextId = id + 1;
    }
    file.close();
}

void saveTasks() {
    ofstream file("tasks.txt");
    for (const auto& task : tasks) {
        file << task.getId() << " " << task.isCompleted() << " " << task.getDescription() << "\n";
    }
    file.close();
}

void addTask() {
    cout << "Descrie taskul: ";
    string desc;
    cin.ignore();
    getline(cin, desc);
    tasks.emplace_back(nextId++, desc);
    cout << "Task adaugat!\n";
}

void showTasks() {
    if (tasks.empty()) {
        cout << "Nu exista taskuri.\n";
        return;
    }
    cout << "Lista taskuri:\n";
    for (const auto& task : tasks) {
        cout << task.toString() << "\n";
    }
}

void completeTask() {
    cout << "Introdu ID-ul taskului de marcat completat: ";
    int id;
    cin >> id;

    for (auto& task : tasks) {
        if (task.getId() == id) {
            task.markCompleted();
            cout << "Task marcat completat!\n";
            return;
        }
    }
    cout << "Task cu ID-ul " << id << " nu a fost gasit.\n";
}

void deleteTask() {
    cout << "Introdu ID-ul taskului de sters: ";
    int id;
    cin >> id;

    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->getId() == id) {
            tasks.erase(it);
            cout << "Task sters!\n";
            return;
        }
    }
    cout << "Task cu ID-ul " << id << " nu a fost gasit.\n";
}

void menu() {
    cout << "\n=== Task Manager ===\n";
    cout << "1. Adauga task\n";
    cout << "2. Arata taskuri\n";
    cout << "3. Marcheaza task completat\n";
    cout << "4. Sterge task\n";
    cout << "5. Iesire\n";
    cout << "Alege o optiune: ";
}

int main() {
    loadTasks();

    while (true) {
        menu();
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: addTask(); break;
            case 2: showTasks(); break;
            case 3: completeTask(); break;
            case 4: deleteTask(); break;
            case 5:
                saveTasks();
                cout << "La revedere!\n";
                return 0;
            default:
                cout << "Optiune invalida. Incearca din nou.\n";
        }
    }
}
