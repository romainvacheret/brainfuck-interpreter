#ifndef INTERPRETER_H
#define INTERPRETER_H

const int memory_extension = 10;

typedef struct MemoryManager {
    int* memory;
    int memory_length;
    int current_memory;
} MemoryManager;

typedef struct Interpreter {
    MemoryManager* mm;
    int last_bracket;
    int current_command;
    char* code_string;
} Interpreter;

MemoryManager* init_memory_manager();
void free_memory_manager(MemoryManager* mm);

Interpreter* init_interpreter(char* code_string);
void free_interpreter(Interpreter* i);

void allocate_memmory(MemoryManager* mm);
void increase_memory(MemoryManager* mm);

void execute(Interpreter* i);
void process(Interpreter* i);

#endif