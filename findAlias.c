#include "shakeup.h"

char *findAlias(char *b)
{
	char *hshAlias, *token, *slash = "/", *t = NULL;
	struct stat st;
	int count1;

	hshAlias = _getenv("alias");

	token = strtok(hshPath, "="); /*remove PATH text*/
	for(token = strtok(NULL, ":"); token != NULL; token = strtok(NULL, ":"))
	{
		count1 = _strlen(token) + _strlen(slash) + _strlen(b) + 1;

		t = malloc(count1 * sizeof(char));

		t = __strcat(t, token);

		if (stat(t, &st) == 0)
		{
			printf("FOUND:%s\n", t);
			return (t);
		}
	}
	return (t);
}


int main()
{
	findAlias("ll");

	return(0);
}
