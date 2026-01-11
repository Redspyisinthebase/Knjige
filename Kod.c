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
// 2. Obrisi knjigu
void obrisi_knjigu(char *naslov) {
    for (int i = 0; i < brojKnjiga; i++) {
        if (strcmp(biblioteka[i].naslov, naslov) == 0) {
            for (int j = i; j < brojKnjiga - 1; j++) {
                biblioteka[j] = biblioteka[j + 1];
            }
            brojKnjiga--;
            printf("Knjiga '%s' obrisana.\n", naslov);
            return;
        }
    }
    printf("Knjiga nije pronadjena.\n");
}
// 3. Prikazi sve knjige
void prikazi_knjige() {
    for (int i = 0; i < brojKnjiga; i++) {
        printf("%s - %s (%d)\n", biblioteka[i].naslov, biblioteka[i].autor, biblioteka[i].godina);
    }
}
