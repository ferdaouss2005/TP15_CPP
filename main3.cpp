
#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;

class TableHachage {
private:
    vector<list<pair<int, string>>> table;
    int tailleTable;

    // Fonction de hachage
    int hachage(int cle) const {
        return cle % tailleTable;
    }

    // Redimensionner la table
    void redimensionner() {
        int nouvelleTaille = tailleTable * 2;

        vector<list<pair<int, string>>> nouvelleTable(nouvelleTaille);

        for (const auto& liste : table) {
            for (const auto& element : liste) {
                int indice = element.first % nouvelleTaille;
                nouvelleTable[indice].push_back(element);
            }
        }

        table = nouvelleTable;
        tailleTable = nouvelleTaille;
    }

public:
    TableHachage(int taille = 5) {
        tailleTable = taille;
        table.resize(tailleTable);
    }

    // Inserer une paire cle/valeur
    void inserer(int cle, string valeur) {
        int indice = hachage(cle);

        // Verifier si la cle existe deja
        for (auto& element : table[indice]) {
            if (element.first == cle) {
                element.second = valeur;
                cout << "Valeur mise a jour." << endl;
                return;
            }
        }

        table[indice].push_back({cle, valeur});
        cout << "Element insere." << endl;

        // Redimensionnement si le taux de remplissage depasse 0.75
        int nbElements = 0;

        for (const auto& liste : table)
            nbElements += liste.size();

        if (static_cast<double>(nbElements) / tailleTable > 0.75)
            redimensionner();
    }

    // Rechercher une cle
    string rechercher(int cle) const {
        int indice = hachage(cle);

        for (const auto& element : table[indice]) {
            if (element.first == cle)
                return element.second;
        }

        return "";
    }

    // Supprimer une cle
    void supprimer(int cle) {
        int indice = hachage(cle);

        for (auto it = table[indice].begin();
             it != table[indice].end(); ++it) {

            if (it->first == cle) {
                table[indice].erase(it);
                cout << "Element supprime." << endl;
                return;
            }
        }

        cout << "Cle introuvable." << endl;
    }

    // Afficher la table
    void afficher() const {
        cout << "\n===== TABLE DE HACHAGE =====" << endl;

        for (int i = 0; i < tailleTable; i++) {
            cout << "Case " << i << " : ";

            if (table[i].empty()) {
                cout << "Vide";
            } else {
                for (const auto& element : table[i]) {
                    cout << "[" << element.first
                         << " : " << element.second << "] -> ";
                }
                cout << "NULL";
            }

            cout << endl;
        }
    }
};

int main() {
    TableHachage table(5);
    int choix, cle;
    string valeur;

    do {
        cout << "\n===== MENU TABLE DE HACHAGE =====" << endl;
        cout << "1. Inserer" << endl;
        cout << "2. Rechercher" << endl;
        cout << "3. Supprimer" << endl;
        cout << "4. Afficher la table" << endl;
        cout << "0. Quitter" << endl;
        cout << "Votre choix : ";
        cin >> choix;

        switch (choix) {
        case 1:
            cout << "Donner la cle : ";
            cin >> cle;

            cout << "Donner la valeur : ";
            cin >> valeur;

            table.inserer(cle, valeur);
            break;

        case 2:
            cout << "Donner la cle a rechercher : ";
            cin >> cle;

            valeur = table.rechercher(cle);

            if (valeur != "")
                cout << "Valeur trouvee : " << valeur << endl;
            else
                cout << "Cle introuvable." << endl;
            break;

        case 3:
            cout << "Donner la cle a supprimer : ";
            cin >> cle;

            table.supprimer(cle);
            break;

        case 4:
            table.afficher();
            break;

        case 0:
            cout << "Fin du programme." << endl;
            break;

        default:
            cout << "Choix invalide." << endl;
        }

    } while (choix != 0);

    return 0;
}



