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
