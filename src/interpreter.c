#include "interpreter.h"
#include "operators.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int* allocate_memory(MemoryManager* mm) { 
    return (int*) calloc(
        (mm->memory_length += memory_extension),
        sizeof(int)
    );
}

MemoryManager* init_memory_manager() {
    MemoryManager* mm = (MemoryManager*) malloc(sizeof(MemoryManager));
    mm->memory = allocate_memory(mm);
    return mm;
}

void free_memory_manager(MemoryManager* mm) {
    free(mm->memory);
    free(mm);
}

Interpreter* init_interpreter(char* code_string) {
    Interpreter* i = (Interpreter*) malloc(sizeof(Interpreter));
    i->mm = init_memory_manager();
    i->code_string = "";
    i->last_bracket = -1;
    i->code_string = code_string;
    return i;
}

void free_interpreter(Interpreter* i) {
    free_memory_manager(i->mm);
    free(i);
}


void increase_memory(MemoryManager* mm) {
    int* tmp = allocate_memory(mm), i = 0;
    for(; i < mm->memory_length - memory_extension; i++) {
       tmp[i] = mm->memory[i];
    }

    free(mm->memory);
    mm->memory = tmp;
}

void execute(Interpreter* i) {
    const char command = i->code_string[i->current_command];

    switch(command) {
        case '+':
            incremente(i->mm);
            break;
        case '-':
            decremente(i->mm);
            break;
        case '>':
            next(i->mm);
            break;
        case '<':
            previous(i->mm);
            break;
        case '.':
            print_mem(i->mm);
        case ',':
            set_mem();
            break;
        case '[':
            set_index(i);
            break;
        case ']':
            goto_index(i);
            break;
        case ' ':
        case '\t':
        case '\n':;
    }
    i->current_command++;

    printf("%d %d %d \n", i->current_command, i->mm->current_memory, i->mm->memory[i->mm->current_memory]);
}

void process(Interpreter* i) {
    while(i->current_command != strlen(i->code_string)) {
        execute(i); 
    }
}

