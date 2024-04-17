#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int n;
	char str[20];
} S ;

int main() {
	S *new;
	new = (S *)malloc(sizeof(S));
	new->n = 100;
	strcpy(new->str, "just testing");
	free(new);
}
