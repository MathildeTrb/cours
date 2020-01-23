#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void aff (const char* nomFichier)
{
	FILE* fichier;

	fichier = fopen(nomFichier, "r");

	int carActuel = 0;

	do
		{
			int tab[80];
			int i = 0;
			carActuel = fgetc(fichier);
			while (carActuel != 10 && carActuel!=EOF)
			{
				tab[i] = carActuel;
				i = i + 1;
				carActuel = fgetc(fichier);
			}
			if (i>10 && i<20) 
			{
				int j;
				for (j = i-1; j >= 0; j--)
				{
					printf("%c", tab[j]);
				}
				printf("\n");
			} 			
		} while (carActuel != EOF);

	fclose(fichier);
}

int main(int argc, char const *argv[])
{
	const char* nom = argv[1];
	aff(nom);
	return 0;
}