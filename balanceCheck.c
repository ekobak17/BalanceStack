/*
* Ellie Kobak
* usage: 
*/

#include <stdio.h>
#include <stdlib.h>
#include "ADTs/stack.h"
#include <string.h>

int main(int argc,char* argv[]) {
	int i;
	char line[BUFSIZ];
	int count;
	char *open = "([{<";
	char *close = ")]}>";

	if (argc != 2) {
		fprintf(stderr, "Only 1 file can be processed"); 
		return 1;
	}
	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL) {
		fprintf(stderr, "Unable to open file\n"); 
		return 1;
	}
	fgets(line, BUFSIZ, fp);
	sscanf(line, "%d\n", &count);
	const Stack *st = Stack_create(NULL);
	char *match;
	char *pops;
	//printf("%d\n", count);
	for (i=0; i < count; i++) {
		int true = 0;
		fgets(line, BUFSIZ, fp);
		int len;
		len = strlen(line) - 1;
		for (int j = 0; line[j] != '\0'; j++) {
			if ((len % 2) != 0) {
				true = 1;
				break;
			}
			int k = 0;
			if (strchr(open, line[j]))
				st->push(st, (void*)&line[j]);	
			match = (strchr(close, line[j]));
			if (match != NULL) {
				st->pop(st, (void**)&pops);
				for (; open[k] != '\0'; k++) {
					if (open[k] == *pops) {
						break;
					}
				}
				//printf("%c\n", (char)match);
				if (*match == close[k])
					continue;
				else {
					true = 1;
					st->clear(st); 
					break;
				}
			}
		}
		if (true) 
			printf("NO\n");
		else {
			printf("YES\n");
			st->clear(st);
		}
	}
	 st->destroy(st);
	 fclose(fp);	
	return 0;
}
