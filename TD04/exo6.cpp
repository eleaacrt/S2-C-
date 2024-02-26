
// Écrire un programme qui, à partir d’un entier positif saisi par l’utilisateur, affiche le nombre de termes de la suite de Syracuse nécessaires pour atteindre 1 (on inclut le terme de départ dans le décompte).

// La suite de Syracuse est une suite d'entiers dans laquelle chaque terme est obtenu en appliquant une fonction à son terme précédent. Cette fonction est définie comme suit:

// si le terme est pair, le terme suivant est égal à la moitié du terme précédent. (x/2)
// si le terme est impair, le terme suivant est égal à 3 fois le terme précédent plus 1 (3x+1).
// Par exemple, si le terme de départ est 7, la suite est : 7, 22, 11, 34, 17, 52, 26, 13, 40, 20, 10, 5, 16, 8, 4, 2, 1, 4, 2, 1, 4, 2, 1, ...

// Ici, la suite atteint la valeur 1 au bout de 17 termes (incluant le terme de départ).

// Vous remarquez qu’à la fin, une fois qu’on est tombé sur 1, la suite finit par répéter indéfiniment le cycle 4, 2, 1.

// Il est conjecturé que cette suite atteint toujours la valeur 1 quelque soit le terme de départ. Cela a d'ailleurs déjà été vérifiée numériquement jusqu’à 10^20 (par Tomas Oliveira e Silva).


#include <iostream>

int main () {

    int n {};
    std::cout << "Entrez un entier positif: ";
    std::cin >> n;

    while (n != 1) {
        if (n%2 == 0) {
            n = n/2;
            std::cout << n << ", ";
        } else {
            n = 3*n+1;
            std::cout << n << ", ";
        }
    }

    return 0;
}