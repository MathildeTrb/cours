#include <stdio.h>

void f() {
	int i = 1010;
	int nchiffre[20];

	printf("i=%d\n" ,nchiffre[-1]);
	for (i = 0; i < 25; ++i)
	{
		printf("nchiffre[%d]=%d\n",i,nchiffre[i]);
		nchiffre[i] = 0;
	}
}

int main(void)
{
	f();
	printf("	fini\n");
	return 0;
}