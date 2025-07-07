#include "task.hpp"
#include <sstream>
Task::Task(int id, const std::string& desc, bool completed)
    : id(id), description(desc), completed(completed) {}

int Task::getId() const {
    return id;
}

std::string Task::getDescription() const {
    return description;
}

bool Task::isCompleted() const {
    return completed;
}

void Task::markCompleted() {
    completed = true;
}

   std::string Task::toString() const {
    std::stringstream ss;
    ss << "[" << (completed ? "X" : " ") << "] " << id << ": " << description;
    return ss.str();
}


