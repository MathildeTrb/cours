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
    struct Eliste* PremierElement = malloc(sizeof(*PremierElement));
    (*PremierElement).val = i;
    (*PremierElement).suivant = NULL;
    tmp.premier = PremierElement;
    return tmp;
}

bool liste_est_vide (struct Tliste l) {
    return (l.premier == NULL);
}

struct Tliste ajouter_debut (struct Tliste l, int i) {
    struct Eliste* newPremier = malloc(sizeof(*newPremier));
    newPremier->val = i;
    newPremier->suivant = l.premier;
    l.premier = newPremier;
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

void map (struct Tliste* l, void (*fonction)(struct Eliste* element)){
    struct Eliste* courant = malloc(sizeof(*courant));
    courant = l->premier;
    while (courant != NULL) {
        fonction(courant);
        courant = suivant(*courant);
    }
}

void doubler (struct Eliste* element){
    element->val = (2*element->val);
}

void div2 (struct Eliste* element){
    element->val = (element->val)/2;
}

void parcours (struct Tliste l) {
    if (liste_est_vide(l)) {
        printf("liste vide\n");
    } else {
        struct Eliste* elementActuel = l.premier;
        while (elementActuel != NULL)
        {
            printf("%d\n", elementActuel->val);
            elementActuel = suivant(*(elementActuel));
        }
    }
    printf("je finis le parcours\n");
}

int main(int argc, char const *argv[])
{
    struct Tliste l = creer_liste(7);
    l = ajouter_debut(l,5);
    l = ajouter_debut(l,8);
    parcours(l);
    l = supprimer_debut(l);
    parcours(l);
    map(&l,doubler);
    parcours(l);
    map(&l,div2);
    parcours(l);
    return 0;
}

