compile: main.c src/interpreter.c src/validators.c src/operators.c
	gcc -dead_strip -Wall -o interpreter.out main.c src/validators.c src/operators.c src/interpreter.c
