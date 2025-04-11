#include <iostream>
#include "todo.h"
#include <stdexcept>

using namespace std;

void TodoList::init()
{
    // TODO: set size to 0 and all task pointers to nullptr
    size = 0;

    for (int i = 0; i < MAX_TASKS; i++)
    {
        tasks[i] = nullptr;
    }
}

void TodoList::destroy()
{
    // TODO: delete all tasks and reset pointers
    for (int i = 0; i < MAX_TASKS; i++)
    {
        delete tasks[i];
        tasks[i] = nullptr;
    }

    size = 0;
}

int TodoList::string_length(const char *str) const
{
    // TODO: return the number of characters before '\0'
    int i;
    for (i = 0; i < 10000000; i++)
    {
        if (str[i] == '\0')
            break;
    }

    return i;
}

void TodoList::string_copy(char *dest, const char *src) const
{
    // TODO: copy characters from src to dest
    int len = string_length(src);
    for (int i = 0; i < len; i++)
        dest[i] = src[i];

    dest[len] = '\0';
}

void TodoList::add_task(const char *task)
{
    // TODO: if full, throw. otherwise allocate and copy new task
    if (size == MAX_TASKS)
        throw std::overflow_error("TASK ARRAY IS FULL");

    int len = string_length(task);
    char *newTask = new char[len];
    string_copy(newTask, task);
    tasks[size++] = newTask;

    cout << "size: " << size << endl;
    cout << "newTask: " << newTask << endl;
    cout << "task[0]: " << tasks[0] << endl;
}

void TodoList::remove_task(int index)
{
    // TODO: check bounds, delete task, shift left
    if (index < 0)
        throw std::invalid_argument("Index can't be NEGATIVE");
    if (index > MAX_TASKS)
        throw std::invalid_argument("Index OUT OF BOUND");
    if (index >= size)
        throw std::invalid_argument("Index OUT OF BOUND");

    delete tasks[index];

    for (int i = index; i < size - 1; i++)
    {
        tasks[i] = tasks[i + 1];
    }

    tasks[size - 1] = nullptr;
    size--;
}

const char **TodoList::get_pending_tasks(int &count) const
{
    // TODO: set count and return task array
    count = size;

    static const char *result[MAX_TASKS];

    for (int i = 0; i < size; i++)
    {
        result[i] = tasks[i];
    }

    return result;
}