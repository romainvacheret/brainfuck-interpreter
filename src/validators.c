#include <string.h>

#include "validators.h"

int is_valid_charact(const char charact) { 
    return strchr("+-<>[]., \t\n", charact) != NULL;
}

int is_valid_string(char* code_string) {
	int i = 0;

	for(; i <strlen(code_string); i++) {
        if(!is_valid_charact(code_string[i])) {
            return 0;
        }
    }

	return 1;
}

int is_valid_code(char* code_string) {
    return is_valid_string(code_string) && are_brackets_valid(code_string);
}

int are_brackets_valid(char* code_string) {
	int opening = 0, closing = 0, i = 0;

	for(; i < strlen(code_string); i++) {
		char charact = code_string[i];
		opening += charact == '[';
		closing += charact == ']';
	}

	return opening == closing;
}
