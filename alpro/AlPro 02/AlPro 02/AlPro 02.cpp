// Zur Blatt 02 Aufgabe 03

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


void ablauf_diagram_1() {
    //initialisiere x
    int x; 
    //eingabe von x
    std::cin >> x;
    //berechne x² und ueberschreibe den wert in die variable x
    x = x * x;
    //gebe 'neues' x aus
    std::cout << x << std::endl;

}

void ablauf_diagram_2() {
    //initialisiere x
    int x;
    //eingabe von x
    std::cin >> x;
    //solange x kleiner als 0 ist wird ein 'Error' ausgegeben und ein neues x eingegeben, bis x groesser 0 ist
    if (x < 0) {
        std::cout << "Ungueltige Eingabe" << std::endl;
        std::cin >> x;
    }
    //solange x groesser 1 ist wird x - 2 gerechnet und das ergebnis als 'neues' x gespeichert
    while (x > 1) {
        x = x - 2;
    }
    //gebe x aus
    std::cout << x << std::endl;
}

void programm_1() {
    //initialisiere x und y
    int x;
    int y;
    //eingabe von x
    std::cin >> x;
    //ueberschreibe wert von x auf y
    y = x;
    //rechne y + 17, ergebnis in y
    y = y + 17;
    //rechne y * 3, ergebnis in y
    y = y * 3;
    //rechne y modulo 2, ergebnis in y
    y = y % 2;
    //gebe y aus
    std::cout << y << std::endl;

}


void programm_2() {
    std::string text = "Das Modul Algorithmen und Programmierung ist so konzipert, dass die Konzepte und Methodiken\
der objektorientierten Programmierung im Vordergrund stehen. Die hier vorgestellte\
Programmiersprache C++ nimmt die Rolle einer Beispielprogrammiersprache ein, in der die\
diskutierten Konzepte (meist mehr, selten weniger) nachvollziehbar und effizient umgesetzt\
sind. Das Modul soll so verstanden werden, dass es den Teilnehmer:innen im Anschluss an\
dieses Modul leicht fällt andere, objektorientierte Programmiersprachen zu erlernen. Hier soll\
man sich nur noch die Frage stellen: Wie setzten andere Programmiersprachen die wesentlichen\
Konzepte um und was gibt es bei der Sprachsyntax zu beachten?";

    //initialisiere s
    int s = 0;
    //fuer i kleiner als die laenge des textes wird der for loop ausgefuehrt, i ist mit 0 initialisiert
    for (int i = 0; i < text.length(); i++) {
        //wenn der text an stelle i ein Textzeichen beinhaltet wird s und i plus 1 gerechnet
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            s = s + 1;
            i = i + 1;
        }
    }
    //gebe s aus
    std::cout << s << std::endl;
}

//lenght only for arrays
void programm_3() {
    std::vector<int> zahlen = { 42, 69, 420, 99, -444, 9014 };
    //initialisiere s
    int s = 0;
    //initialisiere n mit der laenge des vektors minus 1, da der vektor index 0 bis 5 hat und i = 6 somit 
    //ungueltig ist
    int n = zahlen.size() - 1;
    //fuer i kleiner gleich n wird s plus dem wert des vekotrs an stelle i gerechnet und das ergebnis in s gespeichert,
    //i ist mit 0 initialisiert
    for (int i = 0; i <= n; i++) {
        s = s + zahlen[i];
    }
    //gebe den durchschnitt aus, n+1 da das minus mit welchem wir n initialisiert haben rueckgaengig gemacht
    //werden muss, da der vektor zwar bis index 5 geht jedoch trotzdem 6 elemente hat
    std::cout << (s/(n+1)) << std::endl;
}


void programm_4() {
    //initialisiere x 
    int x;
    //eingabe von x
    std::cin >> x;
    //initialisiere t und ueberschreibe x in t
    int t = x;
    //berechnungen nach pseudocode
    t = t * t;
    t = x * t;
    t = t * t;
    t = t * t;
    t = x * t;
    t = t * t;
    t = x * t;
    t = t * t;
    t = t * t;
    t = x * t;
    t = t * t;
    //gebe t aus
    std::cout << t << std::endl;
    //gibt fuer x = 1 ergebnis 1 aus, sonst 0, da overflow
}

int main() {
    ablauf_diagram_1();
    ablauf_diagram_2();
    programm_1();
    programm_2();
    programm_3();
    programm_4();
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
