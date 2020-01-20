#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{	
	/* utilisation d'une variable */
	char a;
	a = CHAR_MIN;
	printf ("CharMin = %c \n",a);
	char b;
	b = CHAR_MAX;
	printf ("CharMax = %c \n",b);
	int c;
	c = INT_MIN;
	printf ("IntMin = %d \n",c);
	int d;
	d = INT_MAX;
	printf ("IntMax = %d \n",d);

	/* utilisation d'aucune variable */ 
	printf ("%ld \n", LONG_MAX);

	return 0;
}
