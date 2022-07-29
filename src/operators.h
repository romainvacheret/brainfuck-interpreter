#ifndef OPERATOR_H
#define OPERATOR_H

#define MAX(a, b) (a < b ? b : a)

void incremente(MemoryManager* mm);
void decremente(MemoryManager* mm);
void next(MemoryManager* mm);
void previous(MemoryManager* mm);
void print_mem(MemoryManager* mm);
void set_mem();
void set_index(Interpreter* i);
void goto_index(Interpreter* i);

#endif