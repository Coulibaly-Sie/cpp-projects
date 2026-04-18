#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Etudiant {
    string nom;
    vector<double> notes;
};

double calculMoyenne(const Etudiant& e) {
    if (e.notes.empty()) return 0.0;
    double somme = 0;
    for (double n : e.notes) somme += n;
    return somme / e.notes.size();
}

double calculMin(const Etudiant& e) {
    if (e.notes.empty()) return 0.0;
    return *min_element(e.notes.begin(), e.notes.end());
}

double calculMax(const Etudiant& e) {
    if (e.notes.empty()) return 0.0;
    return *max_element(e.notes.begin(), e.notes.end());
}

void afficherEtudiant(const Etudiant& e) {
    cout << "Nom: " << e.nom << endl;
    cout << "Notes: ";
    for (double n : e.notes) cout << n << " ";
    cout << endl;
    cout << fixed << setprecision(2);
    cout << "Moyenne: " << calculMoyenne(e) << " | Min: " << calculMin(e) << " | Max: " << calculMax(e) << endl;
    cout << "----------------------------" << endl;
}

void ajouterEtudiant(vector<Etudiant>& liste) {
    Etudiant e;
    cout << "Nom de l'etudiant: ";
    cin >> e.nom;
    int nb;
    cout << "Nombre de notes: ";
    cin >> nb;
    for (int i = 0; i < nb; i++) {
        double note;
        cout << "Note " << i + 1 << ": ";
        cin >> note;
        e.notes.push_back(note);
    }
    liste.push_back(e);
    cout << "Etudiant ajoute !" << endl;
}

void afficherTous(const vector<Etudiant>& liste) {
    if (liste.empty()) {
        cout << "Aucun etudiant enregistre." << endl;
        return;
    }
    for (const Etudiant& e : liste) {
        afficherEtudiant(e);
    }
}

void afficherClassement(vector<Etudiant> liste) {
    if (liste.empty()) {
        cout << "Aucun etudiant." << endl;
        return;
    }
    // tri par moyenne decroissante
    sort(liste.begin(), liste.end(), [](const Etudiant& a, const Etudiant& b) {
        return calculMoyenne(a) > calculMoyenne(b);
    });

    cout << "\n--- Classement ---" << endl;
    for (int i = 0; i < (int)liste.size(); i++) {
        cout << i + 1 << ". " << liste[i].nom << " - Moyenne: "
             << fixed << setprecision(2) << calculMoyenne(liste[i]) << endl;
    }
}

int main() {
    vector<Etudiant> etudiants;
    int choix;

    cout << "=== Gestion des notes etudiants ===" << endl;

    do {
        cout << "\n1. Ajouter un etudiant" << endl;
        cout << "2. Afficher tous les etudiants" << endl;
        cout << "3. Afficher le classement" << endl;
        cout << "0. Quitter" << endl;
        cout << "Choix: ";
        cin >> choix;

        switch (choix) {
            case 1:
                ajouterEtudiant(etudiants);
                break;
            case 2:
                afficherTous(etudiants);
                break;
            case 3:
                afficherClassement(etudiants);
                break;
            case 0:
                cout << "Au revoir !" << endl;
                break;
            default:
                cout << "Option invalide." << endl;
        }
    } while (choix != 0);

    return 0;
}
