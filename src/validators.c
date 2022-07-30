#include <string.h>

#include <stdio.h>
#include <stdlib.h>

#include "validators.h"

int is_valid_charact(const char charact) { 
    return strchr("+-<>[].,", charact) != NULL;
}

int are_brackets_valid(char code_string[]) {
	int opening = 0, closing = 0, i = 0;

	for(; i < strlen(code_string); i++) {
		char charact = code_string[i];
		opening += charact == '[';
		closing += charact == ']';
	}

	return opening == closing;
}

char* filter_input(char input_string[]) {
    int size = strlen(input_string), i = 0, j = 0;
    char* rtr = (char*) calloc(size, sizeof(char));

    while(i < size) {
        while(i + j < size - 1 && !is_valid_charact(input_string[i + j])) {
            j++;
        }

        strncat(rtr, &input_string[i + j], 1);
        i += j + 1;
        j = 0;
    }

    return rtr;
}
