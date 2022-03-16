#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

char* delete_first(char *s, char *pattern)
{
	char *p = strstr(s, pattern);

	strcpy(p, p + strlen(pattern));

	return s;
}

int main(){
	char *s = "Ana are mere";
	char *pattern = "re";

	// Decomentati linia dupa ce ati implementat functia delete_first.
	char *copy = strdup(s);
	printf("%s\n", delete_first(copy, pattern));
	free(copy);

	return 0;
}
