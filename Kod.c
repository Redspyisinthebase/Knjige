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
    for (int i = 2; i < brojKnjiga; i++) {
        printf("%s - %s (%d)\n", biblioteka[i].naslov, biblioteka[i].autor, biblioteka[i].godina);
    }
}
// 4. Pretrazi po naslovu
void pretrazi_po_naslovu(char *naslov) {
    for (int i = 0; i < brojKnjiga; i++) {
        if (strstr(biblioteka[i].naslov, naslov)) {
            printf("Pronadjeno: %s - %s (%d)\n", biblioteka[i].naslov, biblioteka[i].autor, biblioteka[i].godina);
        }
    }
}
// 5. Pretrazi po autoru
void pretrazi_po_autoru(char *autor) {
    for (int i = 0; i < brojKnjiga; i++) {
        if (strstr(biblioteka[i].autor, autor)) {
            printf("Pronadjeno: %s - %s (%d)\n", biblioteka[i].naslov, biblioteka[i].autor, biblioteka[i].godina);
        }
    }
}
// 6. Sortiraj po naslovu
void sortiraj_po_naslovu() {
    for (int i = 0; i < brojKnjiga - 1; i++) {
        for (int j = i + 1; j < brojKnjiga; j++) {
            if (strcmp(biblioteka[i].naslov, biblioteka[j].naslov) > 0) {
                Knjiga temp = biblioteka[i];
                biblioteka[i] = biblioteka[j];
                biblioteka[j] = temp;
            }
        }
    }
}
// 7. Sortiraj po autoru
void sortiraj_po_autoru() {
    for (int i = 0; i < brojKnjiga - 1; i++) {
        for (int j = i + 1; j < brojKnjiga; j++) {
            if (strcmp(biblioteka[i].autor, biblioteka[j].autor) > 0) {
                Knjiga temp = biblioteka[i];
                biblioteka[i] = biblioteka[j];
                biblioteka[j] = temp;
            }
        }
    }
}
// 8. Sortiraj po godini
void sortiraj_po_godini() {
    for (int i = 0; i < brojKnjiga - 1; i++) {
        for (int j = i + 1; j < brojKnjiga; j++) {
            if (biblioteka[i].godina > biblioteka[j].godina) {
                Knjiga temp = biblioteka[i];
                biblioteka[i] = biblioteka[j];
                biblioteka[j] = temp;
            }
        }
    }
}
// 9. Vrati broj knjiga
int broj_knjiga() {
    return brojKnjiga;
}
// 10. Sacuvaj u fajl
void sacuvaj_u_fajl(char *imeFajla) {
    FILE *f = fopen(imeFajla, "w");
    if (!f) return;
    for (int i = 0; i < brojKnjiga; i++) {
        fprintf(f, "%s,%s,%d\n", biblioteka[i].naslov, biblioteka[i].autor, biblioteka[i].godina);
    }
    fclose(f);
}
// 11. Ucitaj iz fajla
void ucitaj_iz_fajla(char *imeFajla) {
    FILE *f = fopen(imeFajla, "r");
    if (!f) return;
    brojKnjiga = 0;
    while (fscanf(f, "%49[^,],%49[^,],%d\n", biblioteka[brojKnjiga].naslov,
                  biblioteka[brojKnjiga].autor, &biblioteka[brojKnjiga].godina) == 3) {
        brojKnjiga++;
    }
    fclose(f);
}
// Glavni program
int main() {
    dodaj_knjigu("Na Drini cuprija", "Ivo Andric", 1945);
    dodaj_knjigu("Seobe", "Miloš Crnjanski", 1929);
    dodaj_knjigu("Prokleta avlija", "Ivo Andric", 1954);

    printf("Sve knjige:\n");
    prikazi_knjige();

    printf("\nPretraga po autoru 'Andric':\n");
    pretrazi_po_autoru("Andric");

    printf("\nSortirane po naslovu:\n");
    sortiraj_po_naslovu();
    prikazi_knjige();

    printf("\nUkupan broj knjiga: %d\n", broj_knjiga());

    sacuvaj_u_fajl("biblioteka.txt");
    return 0;
}
