#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) (a < b ? b : a)

int* memory;
int memory_length = 0;
int current_memory = 0;
const int memory_extension = 10;
char* code_string = "";
int last_bracket = -1;
int current_command = 0;

void debug() {
	int i = 0;
	printf("\n[DEBUGGING]\n");
	for(; i < memory_length; i++) printf("%d ", memory[i]);
	printf("\n[END DEBUGGING]\n");
}

int* allocate_memory() { return (int*) calloc((memory_length += memory_extension), sizeof(int)); }
void init() { memory = allocate_memory(); }
void increase_memory() { int* temp = memcpy(allocate_memory(), memory, memory_length - memory_extension); memory = temp; }
int is_valid_charact(const char charact) { return strchr("+-<>[].,", charact) != NULL; }

// operators
void incremente() { memory[current_memory]++; }
void decremente() { memory[current_memory]--; }
void next() { if(++current_memory >= memory_length) increase_memory(); }
void previous() { current_memory = MAX(0, current_memory - 1); }
void print_mem() { printf("%c", memory[current_memory]); }
void set_men() {}
void set_index() { last_bracket = current_command; }
void goto_index() { if(!memory[current_memory]) last_bracket = -1; else current_command = last_bracket -1; }

void execute(const char command) {
	switch(command) {
		case '+':
			incremente();
			break;
		case '-':
			decremente();
			break;
		case '>':
			next();
			break;
		case '<':
			previous();
			break;
		case '.':
			print_mem();
		case ',':
			set_men();
			break;
		case '[':
			set_index();
			break;
		case ']':
			goto_index();
	}
	current_command++;
}
void process() { while(current_command != strlen(code_string)) execute(code_string[current_command]); }

int main() {
	init();
	code_string = "+++++[>+<-]";
	process();
	debug();
	return EXIT_SUCCESS;
}

/*
TODO:
	- Implement `,`
	- Check memory increase
	- Add logs in file ?
	- Check characters' validity
	- Add space to improve lisibility
	- Check opening braket exists when encounter closing one
*/