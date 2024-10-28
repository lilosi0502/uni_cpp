// Zur Blatt 02 Aufgabe 04

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

// Druckt einen Text aus
void drucke_text(const std::string& text);

// Druckt eine Ganzzahl aus
void drucke_ganzzahl(int ganzzahl);

// Druckt eine Kommazahl aus
void drucke_kommazahl(double gleitkommazahl);

// Liest ein Wort von der Konsole ein
std::string lies_wort();

// Liest eine Ganzzahl von der Konsole ein
int lies_ganzzahl();

// Liest eine Gleitkommazahl von der Konsole ein
double lies_gleitkommazahl();


void alter_von_alan_turing_erraten() {
    //initialisierungen
    int aktuellesJahr = 2024;
    int geburtsjahr = 1912;
    int jahr = aktuellesJahr - geburtsjahr;
    int rateversuch = 0;
    //frage nach dem alter
    std::cout << "Rate wie alt Alan Turing heute waere." << std::endl;
    //eingabe des rateversuchs
    std::cin >> rateversuch;
    //solange rateversuch nicht dem alter entspricht wird nach einem neuen versuch gefragt
    while (rateversuch != jahr) {
        std::cout << "Falsch, neuer Versuch." << std::endl;
        std::cin >> rateversuch;
    }
    //andernfalls 
    std::cout << "Richtig!" << std::endl;

}


int main() {
    alter_von_alan_turing_erraten();
}


/************************************/
/*                                  */
/*   MAGIE   MAGIE   MAGIE  MAGIE   */
/*                                  */
/************************************/

void drucke_text(const std::string& text) {
    std::cout << text << std::endl;
}

void drucke_ganzzahl(int ganzzahl) {
    std::cout << std::to_string(ganzzahl) << std::endl;
}

void drucke_kommazahl(double gleitkommazahl) {
    std::cout << std::to_string(gleitkommazahl) << std::endl;
}

std::string lies_wort() {
    std::string wort;
    std::cin >> wort;
    return wort;
}

int lies_ganzzahl() {
    std::string wort;
    std::cin >> wort;
    int ganzzahl = 0;
    try {
        ganzzahl = std::stoi(wort);
    }
    catch (const std::invalid_argument& e) {
        ganzzahl = -1000;
    }
    return ganzzahl;
}

double lies_gleitkommazahl() {
    std::string wort;
    std::cin >> wort;
    double lies_gleitkommazahl = 0.0;
    try {
        lies_gleitkommazahl = std::stod(wort);
    }
    catch (const std::invalid_argument& e) {
        lies_gleitkommazahl = NAN; // See https://en.cppreference.com/w/cpp/numeric/math/NAN
    }
    return lies_gleitkommazahl;
}
