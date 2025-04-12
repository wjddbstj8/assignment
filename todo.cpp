#include "todo.h"
#include <stdexcept>

void TodoList::init() {
    // TODO: set size to 0 and all task pointers to nullptr
    size = 0;
    for (int i=0;i<MAX_TASKS;i++){
        tasks[i] = nullptr;
    }

}

void TodoList::destroy() {
    // TODO: delete all tasks and reset pointers
    for (int i=0;i<MAX_TASKS;i++){
        delete[] tasks[i];
    }
    init();
}

int TodoList::string_length(const char* str) const {
    // TODO: return the number of characters before '\0'
    int len=0;
    while(str[len]!='\0'){
        ++len;
    }
    
    return len;
}

void TodoList::string_copy(char* dest, const char* src) const {
    // TODO: copy characters from src to dest
    int i=0;
    while(src[i]!='\0'){
        dest[i]=src[i];
        i++;
    }
    dest[i]='\0';
}

void TodoList::add_task(const char* task) {
    // TODO: if full, throw. otherwise allocate and copy new task
    if (size>=MAX_TASKS){
        throw std::overflow_error("Task list is full");
    }
    int len = string_length(task)+1;
    tasks[size] = new char[len];
    string_copy(tasks[size], task);
    size++;
}

void TodoList::remove_task(int index) {
    // TODO: check bounds, delete task, shift left
    if (index<0||index>=size){
        throw std::out_of_range("Invalid index");
    }

    delete[] tasks[index];
    for (int i=index;i<size-1;i++){
        tasks[i]=tasks[i+1];
    }

    tasks[size-1] = nullptr;
    size--;
}

const char** TodoList::get_pending_tasks(int& count) const {
    // TODO: set count and return task array
    count = size;
    const char** result = new const char*[size];
    for (int i=0;i<size;i++) {
        result[i] = tasks[i];
    }
    return result;
}