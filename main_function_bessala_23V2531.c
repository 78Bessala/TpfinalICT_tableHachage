# include "function_bessala_23V2531.h"

int main(int argc,char *argv[])
{
    int tailleBE, choixBE;
    ProduitBE_t nouveauProduitBE;

    printf("Veuillez entrer la taille du tableau : ");
    scanf("%d", &tailleBE);

    hashTableBE_t *hashTableBE = creer_hashTable_BE(tailleBE);
    char idBE[8];

    do {
        
        printf("[***]------------------------------------------------------[***]\n");
        printf("[***] BIENVENUE DANS NOTRE MENU DE GESTION DE PRODUIT !! [***]\n");
        printf("[***]------------------------------------------------------[***]\n");
        sleep(2);

        printf("Que souhaitez-vous faire ? \n");
        sleep(2);
        printf("\t 0. Quitter le logiciel\n");
        printf("\t 1. Insérer un produit\n");
        printf("\t 2. Afficher le stock de produits\n");
        printf("\t 3. Rechercher un produit\n");
        printf("\t 4. Supprimer un produit\n");

        printf("Votre choix : ");
        scanf("%d", &choixBE);

        switch (choixBE) {
            case 0:
                system("clear");
                sleep(2);
                printf("MERCI POUR VOTRE VISITE !!\n");
                sleep(2);
                system("clear");
                break;

            case 1:
                printf("Entrez l'identifiant du produit (max 8 chars) sur le format (24LCCCC) : ");
                scanf("%s", nouveauProduitBE.IdentBE);
                printf("Entrez le prix du produit : ");
                scanf("%f", &nouveauProduitBE.PriceBE);
                printf("Entrez le nom du produit : ");
                scanf("%s", nouveauProduitBE.NameBE);
                
                insertInHashTable_BE(nouveauProduitBE, hashTableBE);
                printf("Produit ajouté avec succès.\n");
                sleep(2);
                break;

            case 2:
                printf("Stock de produits :\n");
                afficher_hashTable_BE(hashTableBE);
                sleep(2);
                break;

            case 3:
                printf("Veuillez entrer l'identifiant du produit à rechercher : ");
                scanf("%s", idBE);
                findInHashTableB_BE(idBE, hashTableBE);
                sleep(2);
                break;

            case 4:
                printf("Veuillez entrer l'identifiant du produit à supprimer : ");
                scanf("%s", idBE);
                hashTableBE = removeInHashTable_BE(idBE, hashTableBE);
                printf("Le produit ayant pour identifiant %s a été supprimé avec succès !\n", idBE);
                sleep(2);
                break;

            default:
                printf("Cette option n'est pas disponible ou en cours de développement ! Veuillez choisir une autre option. Merci pour votre coopération !!\n");
                sleep(2);
                break;
        }

    } while (choixBE != 0);

    // Libérer la mémoire allouée (ajoutez votre fonction de libération ici si nécessaire)
    return 0;
}