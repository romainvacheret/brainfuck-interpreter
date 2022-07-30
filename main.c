#include <stdlib.h>
#include <stdio.h>

#include "src/interpreter.h"
#include "src/validators.h"

#include <string.h>

void debug(MemoryManager* mm) {
	int i = 0;
	printf("\n[DEBUGGING]\n");
    
	for(; i < mm->memory_length; i++) {
        printf("%d ", mm->memory[i]);
    }
	printf("\n[END DEBUGGING]\n");
}

void print_array(char* arr) {
    int i = 0;
    for(;i < strlen(arr); i++) {
        printf("%c", arr[i]);
    }
    printf("\n");
}

int main() {
    // char* code_string = "[-]";
    // char* code_string = "+> +>+ >+> +>+>+>+>\n+>+>+>+ >+>+>+>+>+>  +>+>+ >+>+>+>+";
    char* code_string = "++>+++++ [<+>-] ++++++++ [<++++++>-]<.";
    char* filtered_input = filter_input(code_string);
    Interpreter* itp = init_interpreter(filtered_input);

    print_array(code_string);
    print_array(filtered_input);

    if(!are_brackets_valid(itp->code_string)) {
        return EXIT_FAILURE;
    }

    process(itp);
    debug(itp->mm);

    return EXIT_SUCCESS;
}

/*
TODO:
    - Implement `,`
    - Add logs in file ?
    - Read files
*/
