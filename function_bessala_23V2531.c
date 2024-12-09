#include "function_bessala_23V2531.h"

unsigned int hash_BE(char *idBE) {
    unsigned int compteurBE = 0;
    for (int iBE = 0; iBE < strlen(idBE); iBE++) {
        compteurBE += idBE[iBE];
    }
    return compteurBE;
}

hashTableBE_t *creer_hashTable_BE(int lensBE) {
    hashTableBE_t *hashTBE = malloc(sizeof(hashTableBE_t));
    hashTBE->TailleBE = lensBE;
    hashTBE->ContenuBE = calloc(lensBE, sizeof(ProduitBE_t *));
    for (int jBE = 0; jBE < lensBE; jBE++) {
        hashTBE->ContenuBE[jBE] = NULL;
    }
    return hashTBE;
}

hashTableBE_t *insertInHashTable_BE(ProduitBE_t prodBE, hashTableBE_t *hashTBE) {
    unsigned int hBE = hash_BE(prodBE.IdentBE) % hashTBE->TailleBE;

    ProduitBE_t *newProduit = malloc(sizeof(ProduitBE_t));
    *newProduit = prodBE; // Copie du produit
    newProduit->nextBE = hashTBE->ContenuBE[hBE];
    hashTBE->ContenuBE[hBE] = newProduit;

    return hashTBE;
}

void findInHashTableB_BE(char *idBE, hashTableBE_t *hashTBE) {
    unsigned int hBE = hash_BE(idBE) % hashTBE->TailleBE;
    ProduitBE_t *courentBE = hashTBE->ContenuBE[hBE];

    while (courentBE != NULL) {
        if (strcmp(courentBE->IdentBE, idBE) == 0) {
            printf("Produit trouvé :\n");
            printf("Identifiant : %s\n", courentBE->IdentBE);
            printf("Prix : %.2f FCFA\n", courentBE->PriceBE);
            printf("Nom : %s\n", courentBE->NameBE);
            return;
        }
        courentBE = courentBE->nextBE;
    }
    printf("Produit ayant pour identifiant %s n'a pas été trouvé.\n", idBE);
}

hashTableBE_t *removeInHashTable_BE(char *idBE, hashTableBE_t *hashTBE) {
    unsigned int hBE = hash_BE(idBE) % hashTBE->TailleBE;
    ProduitBE_t *courentBE = hashTBE->ContenuBE[hBE];
    ProduitBE_t *precedentBE = NULL;

    while (courentBE != NULL) {
        if (strcmp(courentBE->IdentBE, idBE) == 0) {
            if (precedentBE == NULL) {
                hashTBE->ContenuBE[hBE] = courentBE->nextBE;
            } else {
                precedentBE->nextBE = courentBE->nextBE;
            }
            free(courentBE);
            return hashTBE;
        }
        precedentBE = courentBE;
        courentBE = courentBE->nextBE;
    }
    return hashTBE;
}

void afficher_hashTable_BE(hashTableBE_t *hashTBE) {
    if (hashTBE == NULL) {
        printf("Table de hachage vide.\n");
        return;
    }

    for (unsigned int iBE = 0; iBE < hashTBE->TailleBE; iBE++) {
        ProduitBE_t *courentBE = hashTBE->ContenuBE[iBE];
        if (courentBE != NULL) {
            printf("Index %u :\n", iBE);
            while (courentBE != NULL) {
                printf("  Identifiant : %s, Prix : %.2f FCFA, Nom : %s\n",
                       courentBE->IdentBE, courentBE->PriceBE, courentBE->NameBE);
                courentBE = courentBE->nextBE;
            }
        }
    }
}