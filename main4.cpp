
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>
using namespace std;

template <typename T>
class Pile {
private:
    vector<T> elements;

public:
    // Empiler un element
    void empiler(T element) {
        elements.push_back(element);
    }

    // Depiler un element
    T depiler() {
        if (estVide()) {
            throw underflow_error("Erreur : la pile est vide !");
        }

        T element = elements.back();
        elements.pop_back();

        return element;
    }

    // Consulter le sommet
    T sommet() const {
        if (estVide()) {
            throw underflow_error("Erreur : la pile est vide !");
        }

        return elements.back();
    }

    // Verifier si la pile est vide
    bool estVide() const {
        return elements.empty();
    }

    // Inverser la pile
    void inverser() {
        reverse(elements.begin(), elements.end());
    }

    // Afficher la pile
    void afficher() const {
        if (estVide()) {
            cout << "Pile vide." << endl;
            return;
        }

        for (int i = static_cast<int>(elements.size()) - 1;
             i >= 0; i--) {
            cout << elements[i] << " ";
        }

        cout << endl;
    }
};

int main() {
    try {
        // Test avec int
        Pile<int> p1;

        p1.empiler(10);
        p1.empiler(20);
        p1.empiler(30);

        cout << "Pile d'entiers : ";
        p1.afficher();

        cout << "Sommet : " << p1.sommet() << endl;
        cout << "Element depile : " << p1.depiler() << endl;

        cout << "Apres depilement : ";
        p1.afficher();

        p1.inverser();

        cout << "Apres inversion : ";
        p1.afficher();

        // Test avec string
        Pile<string> p2;

        p2.empiler("Bonjour");
        p2.empiler("C++");
        p2.empiler("Templates");

        cout << "\nPile de chaines : ";
        p2.afficher();

        // Test avec double
        Pile<double> p3;

        p3.empiler(10.5);
        p3.empiler(20.75);
        p3.empiler(30.25);

        cout << "\nPile de reels : ";
        p3.afficher();

        cout << "Sommet : " << p3.sommet() << endl;

        // Test de l'exception
        Pile<int> p4;

        cout << "\nTest de pile vide :" << endl;
        p4.depiler();

    }
    catch (const underflow_error& e) {
        cout << e.what() << endl;
    }

    return 0;
}
