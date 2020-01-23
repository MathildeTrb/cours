#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void aff (const char* nomFichier)
{
	FILE* fichier;

	fichier = fopen(nomFichier, "r");

	int carActuel = 0;
	int carActuelMemoire = 0;

	do
		{
			carActuel = fgetc(fichier);
			int i = 0;
			while (carActuel==9 || carActuel==32)
			{
				carActuelMemoire = carActuel;
				i = i+1;
				carActuel = fgetc(fichier);
			}
			if (i==1){
				printf("%c", carActuelMemoire);
			}
			if (i>1){
				printf("*");
			}
			printf("%c", carActuel);
			
		} while (carActuel != EOF);
	printf("\n");
	fclose(fichier);
}

int main(int argc, char const *argv[])
{
	const char* nom = argv[1];
	aff(nom);
	return 0;
}
