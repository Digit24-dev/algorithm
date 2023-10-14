#include <stdio.h>

int main ()
{
	char *string[20] = {"one", "two\n", "three\n"};
	//printf(string[1]);
	printf("%s", &string[1][2]);
	return 0;
}
