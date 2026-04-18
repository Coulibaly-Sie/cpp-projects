#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct Tache {
    string description;
    int priorite; // 1=basse, 2=normale, 3=haute
    bool terminee;
};

string prioriteLabel(int p) {
    if (p == 1) return "Basse";
    if (p == 2) return "Normale";
    return "Haute";
}

void afficherTaches(const vector<Tache>& taches) {
    if (taches.empty()) {
        cout << "Aucune tache." << endl;
        return;
    }
    cout << "\n--- Liste des taches ---" << endl;
    for (int i = 0; i < (int)taches.size(); i++) {
        string statut = taches[i].terminee ? "[X]" : "[ ]";
        cout << i + 1 << ". " << statut << " [" << prioriteLabel(taches[i].priorite) << "] "
             << taches[i].description << endl;
    }
}

void ajouterTache(vector<Tache>& taches) {
    Tache t;
    cout << "Description: ";
    cin.ignore();
    getline(cin, t.description);
    cout << "Priorite (1=Basse, 2=Normale, 3=Haute): ";
    cin >> t.priorite;
    if (t.priorite < 1 || t.priorite > 3) t.priorite = 2;
    t.terminee = false;
    taches.push_back(t);
    cout << "Tache ajoutee !" << endl;
}

void marquerTerminee(vector<Tache>& taches) {
    afficherTaches(taches);
    if (taches.empty()) return;
    int idx;
    cout << "Numero de la tache a marquer terminee: ";
    cin >> idx;
    idx--;
    if (idx >= 0 && idx < (int)taches.size()) {
        taches[idx].terminee = true;
        cout << "Tache marquee comme terminee." << endl;
    } else {
        cout << "Numero invalide." << endl;
    }
}

void supprimerTache(vector<Tache>& taches) {
    afficherTaches(taches);
    if (taches.empty()) return;
    int idx;
    cout << "Numero de la tache a supprimer: ";
    cin >> idx;
    idx--;
    if (idx >= 0 && idx < (int)taches.size()) {
        taches.erase(taches.begin() + idx);
        cout << "Tache supprimee." << endl;
    } else {
        cout << "Numero invalide." << endl;
    }
}

void sauvegarder(const vector<Tache>& taches) {
    ofstream fichier("taches.txt");
    if (!fichier.is_open()) {
        cout << "Erreur : impossible d'ouvrir le fichier." << endl;
        return;
    }
    for (const Tache& t : taches) {
        fichier << t.description << "\n" << t.priorite << "\n" << t.terminee << "\n";
    }
    fichier.close();
    cout << "Sauvegarde effectuee dans taches.txt" << endl;
}

void charger(vector<Tache>& taches) {
    ifstream fichier("taches.txt");
    if (!fichier.is_open()) {
        cout << "Aucune sauvegarde trouvee." << endl;
        return;
    }
    taches.clear();
    Tache t;
    while (getline(fichier, t.description)) {
        fichier >> t.priorite;
        fichier >> t.terminee;
        fichier.ignore();
        taches.push_back(t);
    }
    fichier.close();
    cout << taches.size() << " tache(s) chargee(s)." << endl;
}

int main() {
    vector<Tache> taches;
    charger(taches);
    int choix;

    cout << "=== Todo List ===" << endl;

    do {
        cout << "\n1. Afficher les taches" << endl;
        cout << "2. Ajouter une tache" << endl;
        cout << "3. Marquer une tache terminee" << endl;
        cout << "4. Supprimer une tache" << endl;
        cout << "5. Sauvegarder" << endl;
        cout << "0. Quitter" << endl;
        cout << "Choix: ";
        cin >> choix;

        switch (choix) {
            case 1: afficherTaches(taches); break;
            case 2: ajouterTache(taches); break;
            case 3: marquerTerminee(taches); break;
            case 4: supprimerTache(taches); break;
            case 5: sauvegarder(taches); break;
            case 0:
                sauvegarder(taches);
                cout << "Au revoir !" << endl;
                break;
            default:
                cout << "Option invalide." << endl;
        }
    } while (choix != 0);

    return 0;
}
