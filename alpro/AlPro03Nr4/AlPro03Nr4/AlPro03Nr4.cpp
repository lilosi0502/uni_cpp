#include <cmath>
#include <iostream>



void berechneSin(double toleranz) {
	//initialisiere winkelGrad dessen sin berechnet werden soll
	double winkelGrad;

	//frage nach winkelGrad 
	std::cout << "Nenne mir eine Kommazahl, ich nenne dir den Sinus davon." << std::endl;
	//eingabe von winkelGrad
	std::cin >> winkelGrad;

	//initialisiere eine sehr kleine zahl um die konvergenz der taylor-reihe zu steuern, wie in der VL gegeben
	//double klein = 1e-8;
	//erster summand der reihe
	double summand = winkelGrad;
	//variable zur speicherung des sinuswerts
	double sinus = 0;
	//hilfsvariable für die berechnung
	double zaehler_helfer = 1;

	//berechnung der sinusfunktion mit einer schleife
	while (summand > toleranz || -summand > toleranz) {
		//addiere den aktuellen summanden zur summe
		sinus += summand;
		//berechne den naechsten summanden der taylor-reihe
		summand = -(summand * winkelGrad * winkelGrad) / ((zaehler_helfer + 1) * (zaehler_helfer + 2));
		//erhoehe die hilfsvariable 
		zaehler_helfer += 2;
	}

	//gebe sinus aus
	std::cout << sinus << std::endl;
}
//ueberladene funktion mit standard toleranzwert
void berechneSin() {
	berechneSin(1e-8);
}

void berechneCos(double toleranz) {
	//initialisiere winkelGrad dessen cos berechnet werden soll
	double winkelGrad;

	//frage nach winkelGrad 
	std::cout << "Nenne mir eine Kommazahl, ich nenne dir den Kosinus davon." << std::endl;
	//eingabe von winkelGrad
	std::cin >> winkelGrad;

	//initialisiere eine sehr kleine zahl um die konvergenz der taylor-reihe zu steuern, wie in der VL gegeben
	//double klein = 1e-8;
	//erster summand der reihe
	double summand = 1;
	//variable zur speicherung des cosinuswerts
	double cosinus = 0;
	//hilfsvariable für die berechnung
	double zaehler_helfer = 0;

	//berechnung der cosinusfunktion mit einer schleife
	while (summand > toleranz || -summand > toleranz) {
		//addiere den aktuellen summanden zur summe
		cosinus += summand;
		//berechne den naechsten summanden der taylor-reihe
		summand = -(summand * winkelGrad * winkelGrad) / ((zaehler_helfer + 1) * (zaehler_helfer + 2));
		//erhoehe die hilfsvariable
		zaehler_helfer += 2;
	}

	//gebe cosinus aus
	std::cout << cosinus << std::endl;
}
//ueberladene funktion mit standard toleranzwert
void berechneCos() {
	berechneCos(1e-8);
}
void berechneTan() {
	//initialisiere winkelGrad dessen tan berechnet werden soll
	double winkelGrad;

	//frage nach winkelGrad 
	std::cout << "Nenne mir eine Kommazahl, ich nenne dir den Tangens davon." << std::endl;
	//eingabe von winkelGrad
	std::cin >> winkelGrad;

	//versucht: sinusfunktion aufrufen -> dafür winkelGrad in main initialisiert, double kann nicht durch funktion initialisiert werden 
	
	//berechnung von sin und cos
	double sinus = sin(winkelGrad); 
	double cosinus = cos(winkelGrad);
	
	//falls cosinus nicht null -> verhindert division durch null
	if (cosinus != 0) {
		//berechnet tangens aus sinus und cosinus
		double tangens = sinus / cosinus;
		//gibt tangens aus
		std::cout << tangens << std::endl;
	}
	//falls cosinus null ist, wird dies ausgegeben
	else {
		std::cout << "Tangens ist undefiniert, da der Kosinus 0 ist." << std::endl;
	}
}
void berechneCot() {
	//initialisiere winkelGrad dessen cot berechnet werden soll
	double winkelGrad;

	//frage nach winkelGrad 
	std::cout << "Nenne mir eine Kommazahl, ich nenne dir den Kotangens davon." << std::endl;
	//eingabe von winkelGrad
	std::cin >> winkelGrad;

	//berechnung von sin und cos
	double sinus = sin(winkelGrad);
	double cosinus = cos(winkelGrad);

	//falls sinus nicht null -> verhindert division durch null
	if (sinus != 0) {
		//berechnet kotangens aus sinus und cosinus
		double kotangens = cosinus / sinus;
		//gibt kotangens aus
		std::cout << kotangens << std::endl;
	}
	//falls sinus null ist, wird dies ausgegeben
	else {
		std::cout << "Kotangens ist undefiniert, da der Sinus 0 ist." << std::endl;
	}
}

void berechneWurzel(double toleranz) {
	//initialisiert x als eingabe
	double x;
	//kleine zahl die die genauigkeit der berechnung bestimmt
	//double klein = 1e-8;
	//initialisiere toleranzwert
	//fragt nach eingabe x
	std::cout << "Gebe mir eine Zahl, deren Wurzel berechnet werden soll." << std::endl;
	//eingabe von x
	std::cin >> x;
	//setzt t gleich x, damit der wert von x veraendert werden kann ohne den urspruenglichen wert von x zu verlieren
	double t = x;
	//falls x negativ ist, fragt nach neuer eingabe
	if (x < 0) {
		std::cout << "Ungueltig, gebe neue Zahl >= 0 an." << std::endl;
		std::cin >> x;
	}
	//ansonsten fuehre naeherungsweise berechnung der wurzel aus
	else {
		//idee: berechne ein t und quadriere es, vergleich mir urspruenglichem x bis die werte nur noch die distanz von 'klein' haben, also sehr nah beieinander
		//liegen - der quadrierte wert der quadratwurzel von x ist x
		// 
		//solange t²-x, also die distanz zwischen der aktuellen naeherung der quadratwurzel hoch 2 und x, kleiner als der toleranzwert ist, lauft die while schleife
		while ((t * t - x) > toleranz) {
			//neue naeherung wird berechnet, indem die haelfte von der naeherung plus x durch t gerechnet wird
			t = 0.5 * (t + x / t);
		}
		//drucke die naeherung
		std::cout << t << std::endl;
	}
}
//ueberladene funktion mit standard toleranzwert
void berechneWurzel() {
	berechneWurzel(1e-8);
}
int main() {
	//initialisiere selbstbestimmbaren toleranzwert
	std::cout << "Moechtest du einen selbstbestimmten Toleranzwert? (1 = Ja, 0 = Nein.)" << std::endl;
	int t = 0;
	std::cin >> t;
	double toleranz = NULL;
	if (t == 1) {
		std::cout << "Gebe einen Toleranzwert fuer die naechsten Berechnungen an." << std::endl;
		std::cin >> toleranz;

	}
	
	berechneSin(toleranz);
	berechneCos(toleranz);
	berechneTan();
	berechneCot();
	berechneWurzel(toleranz);
}


