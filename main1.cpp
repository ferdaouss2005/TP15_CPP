
#include <iostream>
using namespace std;

class Noeud {
public:
    int valeur;
    Noeud* suivant;

    Noeud(int v) {
        valeur = v;
        suivant = nullptr;
    }
};

class ListeChainee {
private:
    Noeud* tete;
    int nbElements;

public:
    ListeChainee() {
        tete = nullptr;
        nbElements = 0;
    }

    // Ajouter au debut
    void ajouterDebut(int valeur) {
        Noeud* nouveau = new Noeud(valeur);

        nouveau->suivant = tete;
        tete = nouveau;

        nbElements++;
    }

    // Ajouter a la fin
    void ajouterFin(int valeur) {
        Noeud* nouveau = new Noeud(valeur);

        if (tete == nullptr) {
            tete = nouveau;
        } else {
            Noeud* courant = tete;

            while (courant->suivant != nullptr) {
                courant = courant->suivant;
            }

            courant->suivant = nouveau;
        }

        nbElements++;
    }

    // Supprimer une valeur
    void supprimer(int valeur) {
        if (tete == nullptr)
            return;

        if (tete->valeur == valeur) {
            Noeud* temp = tete;
            tete = tete->suivant;
            delete temp;
            nbElements--;
            return;
        }

        Noeud* courant = tete;

        while (courant->suivant != nullptr &&
               courant->suivant->valeur != valeur) {
            courant = courant->suivant;
        }

        if (courant->suivant != nullptr) {
            Noeud* temp = courant->suivant;
            courant->suivant = temp->suivant;
            delete temp;
            nbElements--;
        }
    }

    // Afficher la liste
    void afficher() const {
        Noeud* courant = tete;

        while (courant != nullptr) {
            cout << courant->valeur << " -> ";
            courant = courant->suivant;
        }

        cout << "NULL" << endl;
    }

    // Retourner la taille
    int taille() const {
        return nbElements;
    }

    // Iterateur personnalise
    class Iterator {
    private:
        Noeud* courant;

    public:
        Iterator(Noeud* n) {
            courant = n;
        }

        int& operator*() const {
            return courant->valeur;
        }

        Iterator& operator++() {
            courant = courant->suivant;
            return *this;
        }

        bool operator!=(const Iterator& autre) const {
            return courant != autre.courant;
        }
    };

    Iterator begin() {
        return Iterator(tete);
    }

    Iterator end() {
        return Iterator(nullptr);
    }

    // Destructeur
    ~ListeChainee() {
        Noeud* courant = tete;

        while (courant != nullptr) {
            Noeud* temp = courant;
            courant = courant->suivant;
            delete temp;
        }

        tete = nullptr;
        nbElements = 0;
    }
};

int main() {
    ListeChainee liste;

    liste.ajouterDebut(20);
    liste.ajouterDebut(10);
    liste.ajouterFin(30);
    liste.ajouterFin(40);

    cout << "Liste initiale :" << endl;
    liste.afficher();

    cout << "Taille : " << liste.taille() << endl;

    liste.supprimer(20);

    cout << "\nApres suppression de 20 :" << endl;
    liste.afficher();

    cout << "Nouvelle taille : " << liste.taille() << endl;

    cout << "\nParcours avec l'iterateur :" << endl;

    for (auto& e : liste) {
        cout << e << " ";
    }

    cout << endl;

    return 0;
}




