#include <stdlib.h>
#include <stdio.h>

#include "src/interpreter.h"
#include "src/validators.h"

void debug(MemoryManager* mm) {
	int i = 0;
	printf("\n[DEBUGGING]\n");
    
	for(; i < mm->memory_length; i++) {
        printf("%d ", mm->memory[i]);
    }
	printf("\n[END DEBUGGING]\n");
}

int main() {
    // char* code_string = "[-]";
    char* code_string = "+> +>+ >+> +>+>+>+>\n+>+>+>+ >+>+>+>+>+>  +>+>+ >+>+>+>+";
    Interpreter* i = init_interpreter(code_string);

    if(!is_valid_code(i->code_string)) {
        return EXIT_FAILURE;
    }

    process(i);
    debug(i->mm);

    return EXIT_SUCCESS;
}

/*
TODO:
    - Implement `,`
    - Add logs in file ?
    - Read files
*/
