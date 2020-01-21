#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct Tliste{
	struct Eliste* premier;
};

struct Eliste {
	int val;
	struct Eliste* suivant;
};

/* prototype */

struct Tliste creer_liste_v ();
struct Tliste creer_liste (int i);
bool liste_est_vide (struct Tliste l);
struct Tliste ajouter_debut (struct Tliste l, int i);
struct Eliste* suivant (struct Eliste e);
struct Tliste supprimer_debut (struct Tliste l);

/* fonction */

struct Tliste creer_liste_v () {
	struct Tliste tmp;
	tmp.premier = NULL;
	return tmp;
}

struct Tliste creer_liste (int i) {
	struct Tliste tmp;
	struct Eliste* PremierElement;
	(*PremierElement).val = i;
	(*PremierElement).suivant = NULL;
	tmp.premier = PremierElement;
	return tmp;
}

bool liste_est_vide (struct Tliste l) {
	return (l.premier == NULL);
}

struct Tliste ajouter_debut (struct Tliste l, int i) {
	struct Eliste newPremier;
	newPremier.val = i;
	newPremier.suivant = l.premier;
	l.premier = &newPremier;
	return l;
}

struct Eliste* suivant (struct Eliste e) {
	return (e.suivant);
}

struct Tliste supprimer_debut (struct Tliste l) {
	if (liste_est_vide(l))
	{
		printf("erreur\n");
	} else {
		l.premier = suivant(*(l.premier));
	}
	return l;
}

void parcours (struct Tliste l) {
	if (liste_est_vide(l)) {
		printf("liste vide\n");
	} else {
		struct Eliste elementActuel = (*l.premier);
		printf("%d\n", elementActuel.val);
		bool testBis = (elementActuel.suivant == NULL);
		printf("test Bis vaut %d\n", testBis);
		while (elementActuel.suivant != NULL)
		{
			printf("je rentre dans mon while\n");
			elementActuel = *(suivant(elementActuel));
			printf("%d\n", elementActuel.val);
		}
	}
	printf("je finis le parcours\n");
}

int main(int argc, char const *argv[])
{
	struct Tliste lv = creer_liste_v();
	lv = supprimer_debut(lv);
	bool test;
	test = liste_est_vide(lv);
	printf("lv est vide %d\n", test);
	parcours(lv);

	printf("\n");

	struct Tliste l = creer_liste(7);
	bool testBis = ((*l.premier).suivant == NULL);
	int pVal;
	pVal = (*(l.premier)).val;
	printf("%d\n", pVal);
	printf("%d\n", testBis);
	parcours(l);
	/*l = ajouter_debut(l,5);
	parcours(l);
	l = ajouter_debut(l,8);
	parcours(l);
	l = supprimer_debut(l);
	parcours(l);*/

	return 0;
}

