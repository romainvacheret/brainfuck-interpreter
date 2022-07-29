#include <stdio.h>

#include "interpreter.h"
#include "operators.h"

void incremente(MemoryManager* mm) {
    mm->memory[mm->current_memory]++;
}

void decremente(MemoryManager* mm) {
    mm->memory[mm->current_memory] = MAX(0, mm->memory[mm->current_memory] - 1);
}
void next(MemoryManager* mm) {
    if(++(mm->current_memory) >= mm->memory_length) {
        increase_memory(mm); 
    }
}
void previous(MemoryManager* mm) {
    mm->current_memory = MAX(0, mm->current_memory - 1); 
}

void print_mem(MemoryManager* mm) {
    printf("%c", mm->memory[mm->current_memory]);
}

// TODO
void set_mem() {}

void set_index(Interpreter* i) { 
    i->last_bracket = i->current_command;
}

void goto_index(Interpreter* i) { 
    if(!i->mm->memory[i->mm->current_memory]) {
        i->last_bracket = -1;
    } else {
        i->current_command = i->last_bracket -1;
    }
}
