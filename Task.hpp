#ifndef TASK_HPP
#define TASK_HPP

#include <string>

class Task {
private:
    int id;
    std::string description;
    bool completed;

public:
    Task(int id, const std::string& desc, bool completed = false);
    int getId() const;
    std::string getDescription() const;
    bool isCompleted() const;
    void markCompleted();
    std::string toString() const;
};

#endif

