#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char naslov[50];
    char autor[50];
    int godina;
} Knjiga;
Knjiga biblioteka[MAX];
int brojKnjiga = 0;
// 1. Dodaj knjigu
void dodaj_knjigu(char *naslov, char *autor, int godina) {
    if (brojKnjiga < MAX) {
        strcpy(biblioteka[brojKnjiga].naslov, naslov);
        strcpy(biblioteka[brojKnjiga].autor, autor);
        biblioteka[brojKnjiga].godina = godina;
        brojKnjiga++;
    } else {
        printf("Biblioteka je puna!\n");
    }
}
