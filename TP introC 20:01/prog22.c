#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int nbCar (const char* nomFichier) {

	FILE* fichier;

	fichier = fopen(nomFichier, "r");

	int  carActuel = 0;
	int cpt = 0;

	if (fichier != NULL)
	{
		do
		{
			carActuel = fgetc(fichier);
			cpt = cpt + 1;
		} while (carActuel != EOF);
	} else {

		printf("mon fichier ne s'est pas ouvert \n");
	}
	fclose(fichier);

return cpt;
}

int nbEsp (const char* nomFichier) {
	FILE* fichier;

	fichier = fopen(nomFichier, "r");

	int  carActuel = 0;
	int cpt = 0;

	if (fichier != NULL)
	{
		do
		{
			carActuel = fgetc(fichier);
			if (carActuel == 32) 
			{
				cpt = cpt + 1;
			}
		} while (carActuel != EOF);
	} else {

		printf("mon fichier ne s'est pas ouvert \n");
	}
	fclose(fichier);

return cpt;

}

int nbEol (const char* nomFichier) {
	FILE* fichier;

	fichier = fopen(nomFichier, "r");

	int  carActuel = 0;
	int cpt = 0;

	if (fichier != NULL)
	{
		do
		{
			carActuel = fgetc(fichier);
			if (carActuel == 10) 
			{
				cpt = cpt + 1;
			}
		} while (carActuel != EOF);
	} else {

		printf("mon fichier ne s'est pas ouvert \n");
	}
	fclose(fichier);

return cpt;

}

int main(int argc, char ** argv)
{
	int cptC = 0;
	const char* nom = argv[1];
	cptC = nbCar(nom);
	printf("le nombre de caractere est %d \n", cptC);

	int cptE = 0;
	cptE = nbEsp(nom);
	printf("le nombre d'espace est %d \n", cptE);

	int cptF = 0;
	cptF = nbEol(nom);
	printf("le nombre de fin de ligne est %d \n", cptF);	

	return 0;
}