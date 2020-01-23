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
			do
				{
					carActuel = fgetc(fichier);
				}
			if ( carActuel == 10 || carActuel == 32 || carActuel == 9 )
			{
				printf("\n");
			} else {
				printf("%c", carActuel);
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
