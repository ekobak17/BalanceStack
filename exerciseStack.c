/*
* Ellie Kobak
* usage: ./exercise Stack [file]
*/

#include <stdio.h>
#include <stdlib.h>
#include "ADTs/stack.h"
#include <string.h>


void printStack(const Stack *st) {
	const Stack *tmp = Stack_create(NULL);
	long pops;
	//int i = 0;
	while (st->pop(st, (void**)&pops)) {
		printf("%ld%s", pops, (0 == st->size(st)) ? "" : " ");
		tmp->push(tmp, (void*)pops);
		
		}
	printf("\n");
	while (tmp->pop(tmp, (void**)&pops)) {
		st->push(st, (void*)pops);
	}	
	tmp->destroy(tmp);
} 


int main (int argc, char* argv[]) {
	char line[BUFSIZ];
	int count;
	
	if (argc != 2) {
		fprintf(stderr, "Only 1 file can be processed"); 
		return 1;
	}
	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL) {
		fprintf(stderr, "Unable to open file\n"); 
		return 1;
	}
	
	const Stack *st = Stack_create(NULL);
	if (st == NULL) {
		fprintf(stderr, "Stack not created"); 
		return 1;
	}

	fgets(line, BUFSIZ, fp);
	sscanf(line, "%d", &count);
	int i;
	for (i=0; i < count; i++) {
		fgets(line, BUFSIZ, fp);
		if (strcmp(line,"pop\n") == 0){
			long pops;
			if (st->size(st) != 0) {
				if (st->pop(st, (void**)&pops)) {
					printf("%ld\n", pops);
				}
			}
			else {
				fprintf(stdout, "StackError\n");
			}
		}
		else if (strcmp(line, "print\n") == 0) {
			if (st->size(st) == 0)
				printf("Empty\n");
			else
				printStack(st);
		}
		else if (strncmp(line, "push", 4) == 0) {
			long variable;
			sscanf(line + 5, "%ld", &variable);
			st->push(st, (void*)variable);
		}
		else {
			printf("unknown command\n");
			continue;
		}
	}
	st->destroy(st);
	fclose(fp);
	return 0;
}



	
