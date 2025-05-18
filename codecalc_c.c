#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//----Nos propres fonctions ---------

int Nomb_premier(int n)
{
    //teste des differents cas

    if(n <= 1)  // 0 et 1 sont des nombres non premier
    {
        return 0; // on renvoie 0 pour dire que ce n'est pas un nombre premier
    }
    if(n == 2)  // si le nombre est égale à un 2 c'est un nombre premier
    {
        return 1; // on renvoie 1 pour dire que c'est un nomb_premier
    }
    if(n % 2 == 0)  // pour eliminer tout nombre pair
    {
        return 0;   // renvoie 0
    }

    //verification des nombres impairs jusqu 'à la racine de n

    int Racine = sqrt(n)+1; //arrondissement superieur pour éviter les erreur
    for(int i = 3; i <= Racine; i+=2) // teste avec des nombres impairs
    {
        if(n % i == 0)
        {
            return 0; // s'il est divisible, on renvoie 0 pour dire que c'est pas un nombre premier
        }
    }
    return 1; // si aucun diviseur trouvé n'est trouvé on renvoie 1

}

//  Cette fonction calcule le PGCD de deux nombres a et b
int pgcd(int a, int b)
{
    while (b != 0)     // tant que b n'est pas nul
    {

        int temp = b; // on stocke b dans temp
        b = a % b;   // on remplace b par a%b et le reste de la division
        a = temp; //On remplace a par temp (l’ancien b).
    }
    return a; // Quand b devient 0, a contient le PGCD
}

// Cette fonction calcule le PPCM à partir du PGCD
int ppcm(int a, int b)
{
    return (a * b) / pgcd(a, b);
}

//-----La fonction principale (main)---------

int main()
{
    int nombre,confirm;
    int choix, a, b; // declarations des variables
    int choix0;
    do
    {
        printf("\n====== MENU APPLICATION C ======");
        printf("\n  1. Calculatrice Simple");
        printf("\n  2. Nombre Premier");
        printf("\n  3. PPCM / PGCD ");
        printf("\n  4. Factorielle");
        printf("\n  0. Quitter");
        printf("\nVotre choix : ");
        scanf("%d",&choix0);

        switch(choix0)
        {
        case 0:
            continue;
        case 1:

            break;
        case 2:
            do
            {
                printf("Entrez votre nombre : ");
                scanf("%d",&nombre);
                if(Nomb_premier(nombre) == 1)
                {
                    printf("le nombre %d est un nombre premier \n",nombre);
                }
                else
                {
                    printf("le nombre %d n'est pas un nombre premier \n",nombre);
                }
                    printf("Tapez : \n");
                    printf("1.Continuez\n");
                    printf("0.Quittez \n");
                    scanf("%d",&confirm);
                }
            while(confirm != 0);

            break;
        case 3:

            // choix : pour le menu, a et b : pour les deux entiers

            do     // ce bloc va s'executer au moins une fois , puis recommencer tant que l'utilisateurs ne choisi pas 0
            {
                // affichage du menu
                printf("\n MENU PGCD & PPCM\n");
                printf("1. Calculer le PGCD\n");
                printf("2. Calculer le PPCM\n");
                printf("0. Quitter\n");
                printf("Votre choix : ");
                scanf("%d", &choix);
                //Le menu est affiché à l’utilisateur, qui tape son choix
                switch (choix)
                {
                case 1:
                    printf("Entrez deux entiers : ");
                    scanf("%d %d", &a, &b);
                    printf("PGCD(%d, %d) = %d\n", a, b, pgcd(a, b));
                    break;
                // le cas 1 est pour le PGCD
                case 2:
                    printf("Entrez deux entiers : ");
                    scanf("%d %d", &a, &b);
                    printf("PPCM(%d, %d) = %d\n", a, b, ppcm(a, b));
                    break;
                // le cas 2 est pour le ppcm
                case 0:
                    printf("Au revoir !\n");
                    break;
                // le cas 0 est pour quitter le programme
                default:
                    printf("Choix invalide.\n");
                }
                // si l'utilisateur entre un choix invalide
            }
            while (choix != 0);


            break;
        case 4:

            break;
        default:
            printf("\nChoix invalide !\n");
            break;
        }

    }
    while( choix0 != 0);

    return 0;
}
