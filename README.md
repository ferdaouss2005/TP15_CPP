# TP15_CPP

EXERCICE1

<img width="296" height="239" alt="image" src="https://github.com/user-attachments/assets/cf49d2b0-24f6-4066-b27f-9463d5e6abb6" />

Dans cet exercice, j'ai créé une liste chaînée personnalisée en C++. J'ai défini une classe Noeud contenant une valeur entière et un pointeur vers le nœud suivant. Ensuite, j'ai développé la classe ListeChainee avec les méthodes ajouterDebut(), ajouterFin(), supprimer(), afficher() et taille(). J'ai également implémenté un destructeur pour libérer la mémoire dynamique et éviter les fuites mémoire. Enfin, j'ai ajouté un itérateur personnalisé permettant de parcourir la liste avec une boucle range-based for.

EXERCICE2

<img width="270" height="338" alt="image" src="https://github.com/user-attachments/assets/0529eb16-e7ba-4ba7-813d-25a226d74992" />

<img width="308" height="343" alt="image" src="https://github.com/user-attachments/assets/31cd7e1b-a956-4fbc-bc65-8b01c22d892f" />



Dans cet exercice, j'ai créé une classe File permettant de gérer une file d'attente selon le principe FIFO (First In, First Out). J'ai utilisé un tableau dynamique circulaire pour stocker les éléments et optimiser l'utilisation de l'espace mémoire. J'ai implémenté les méthodes enfiler(), defiler(), estVide() et estPleine(), ainsi qu'une méthode afficher(). J'ai également ajouté une interface en mode texte permettant à l'utilisateur d'ajouter et de retirer des éléments. Enfin, j'ai utilisé une exception underflow_error pour gérer le cas où l'utilisateur tente de retirer un élément d'une file vide.

EXERCICE3

<img width="318" height="350" alt="image" src="https://github.com/user-attachments/assets/41db8d75-d5f1-49d8-a5df-06555df69576" />

<img width="499" height="326" alt="image" src="https://github.com/user-attachments/assets/33cd5ff6-2c30-4f17-b777-3b74363a6f6f" />



Dans cet exercice, j'ai développé une classe TableHachage permettant de stocker des données sous forme de paires clé-valeur. J'ai utilisé une fonction de hachage simple basée sur le modulo pour déterminer la position de chaque élément dans la table. Pour résoudre les collisions, j'ai utilisé le chaînage avec des listes. J'ai implémenté les méthodes inserer(), rechercher() et supprimer(), ainsi qu'une méthode afficher() pour visualiser le contenu de chaque case. Enfin, j'ai ajouté un mécanisme de redimensionnement dynamique lorsque le taux de remplissage dépasse 0,75.

EXERCICE 4

<img width="328" height="298" alt="image" src="https://github.com/user-attachments/assets/e78be00d-e4be-40e8-9371-8b5327fa8f1e" />


Dans cet exercice, j'ai créé une classe générique Pile<T> en utilisant les templates C++. J'ai utilisé un vector pour stocker dynamiquement les éléments de la pile. J'ai implémenté les méthodes empiler(), depiler(), sommet() et estVide() selon le principe LIFO (Last In, First Out). J'ai ajouté une gestion d'exception avec underflow_error pour empêcher le dépilement d'une pile vide. Enfin, j'ai implémenté la méthode inverser() et testé la pile avec les types int, string et double.
