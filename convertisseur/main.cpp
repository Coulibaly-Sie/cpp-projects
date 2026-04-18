#include <iostream>
#include <iomanip>

using namespace std;

// --- Temperatures ---
void convertirTemperature() {
    int choix;
    double valeur, resultat;
    cout << "\n1. Celsius -> Fahrenheit" << endl;
    cout << "2. Fahrenheit -> Celsius" << endl;
    cout << "3. Celsius -> Kelvin" << endl;
    cout << "4. Kelvin -> Celsius" << endl;
    cout << "Choix: ";
    cin >> choix;
    cout << "Valeur: ";
    cin >> valeur;

    switch (choix) {
        case 1: resultat = valeur * 9.0 / 5.0 + 32; cout << valeur << " C = " << resultat << " F" << endl; break;
        case 2: resultat = (valeur - 32) * 5.0 / 9.0; cout << valeur << " F = " << resultat << " C" << endl; break;
        case 3: resultat = valeur + 273.15; cout << valeur << " C = " << resultat << " K" << endl; break;
        case 4: resultat = valeur - 273.15; cout << valeur << " K = " << resultat << " C" << endl; break;
        default: cout << "Option invalide." << endl;
    }
}

// --- Distances ---
void convertirDistance() {
    int choix;
    double valeur, resultat;
    cout << "\n1. Kilometres -> Miles" << endl;
    cout << "2. Miles -> Kilometres" << endl;
    cout << "3. Metres -> Kilometres" << endl;
    cout << "4. Kilometres -> Metres" << endl;
    cout << "Choix: ";
    cin >> choix;
    cout << "Valeur: ";
    cin >> valeur;

    switch (choix) {
        case 1: resultat = valeur * 0.621371; cout << valeur << " km = " << resultat << " miles" << endl; break;
        case 2: resultat = valeur / 0.621371; cout << valeur << " miles = " << resultat << " km" << endl; break;
        case 3: resultat = valeur / 1000.0; cout << valeur << " m = " << resultat << " km" << endl; break;
        case 4: resultat = valeur * 1000.0; cout << valeur << " km = " << resultat << " m" << endl; break;
        default: cout << "Option invalide." << endl;
    }
}

// --- Poids ---
void convertirPoids() {
    int choix;
    double valeur, resultat;
    cout << "\n1. Kilogrammes -> Livres (lb)" << endl;
    cout << "2. Livres -> Kilogrammes" << endl;
    cout << "3. Grammes -> Kilogrammes" << endl;
    cout << "4. Kilogrammes -> Grammes" << endl;
    cout << "Choix: ";
    cin >> choix;
    cout << "Valeur: ";
    cin >> valeur;

    switch (choix) {
        case 1: resultat = valeur * 2.20462; cout << valeur << " kg = " << resultat << " lb" << endl; break;
        case 2: resultat = valeur / 2.20462; cout << valeur << " lb = " << resultat << " kg" << endl; break;
        case 3: resultat = valeur / 1000.0; cout << valeur << " g = " << resultat << " kg" << endl; break;
        case 4: resultat = valeur * 1000.0; cout << valeur << " kg = " << resultat << " g" << endl; break;
        default: cout << "Option invalide." << endl;
    }
}

int main() {
    cout << fixed << setprecision(4);
    int choix;

    cout << "=== Convertisseur d'unites ===" << endl;

    do {
        cout << "\n1. Temperatures" << endl;
        cout << "2. Distances" << endl;
        cout << "3. Poids" << endl;
        cout << "0. Quitter" << endl;
        cout << "Categorie: ";
        cin >> choix;

        switch (choix) {
            case 1: convertirTemperature(); break;
            case 2: convertirDistance(); break;
            case 3: convertirPoids(); break;
            case 0: cout << "Au revoir !" << endl; break;
            default: cout << "Categorie invalide." << endl;
        }
    } while (choix != 0);

    return 0;
}
