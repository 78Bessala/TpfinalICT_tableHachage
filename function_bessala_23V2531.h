#ifndef FUNCTION_BESSALA_23V2531_H
#define FUNCTION_BESSALA_23V2531_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct produitBE {
    char IdentBE[8];
    float PriceBE;
    char NameBE[50]; // Correction : utiliser un tableau pour le nom
    struct produitBE *nextBE;
} ProduitBE_t;

typedef struct hashTable {
    unsigned int TailleBE;
    ProduitBE_t **ContenuBE;
} hashTableBE_t;

unsigned int hash_BE(char *idBE);
hashTableBE_t *creer_hashTable_BE(int lensBE);
hashTableBE_t *insertInHashTable_BE(ProduitBE_t prodBE, hashTableBE_t *hashTBE);
void findInHashTableB_BE(char *idBE, hashTableBE_t *hashTBE);
hashTableBE_t *removeInHashTable_BE(char *idBE, hashTableBE_t *hashTBE);
void afficher_hashTable_BE(hashTableBE_t *hashTBE);

#endif /* FUNCTION_BESSALA_23V2531_H */