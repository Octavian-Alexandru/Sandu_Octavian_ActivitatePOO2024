#include <iostream>

using namespace std;

class Bloc {
public:
	string Strada;
	int Nr;
	int Apartamente;
	int Locatari;
	bool ApaCalda;

	Bloc() {
		this->Strada="";
		this->Nr = 0;
		this->Apartamente = 0;
		this->Locatari = 0;
		this->ApaCalda = 0;
	}

	Bloc(string strada, int nr, int apartamente, int locatari, bool apacalda) {

		this->Strada = strada;
		this->Nr = nr;
		this->Apartamente = apartamente;
		this->Locatari = locatari;
		this->ApaCalda = apacalda;

	}

	void citire() {
		cout << "Introduceti datele blocului dvs." << endl;
		cout << "Numele strazii:";
		cin >> Strada;
		cout << "Numarul de la adresa:";
		cin >> Nr;
		cout << "Numarul de apartamente:";
		cin >> Apartamente;
		cout << "Numarul de locatari:";
		cin >> Locatari;
		cout << "Are apa calda? (da/nu)";
		cin >> ApaCalda;
	}
	void afisare() {

		cout << "Strada:" << this->Strada << endl;
		cout << "Nr:" << this->Nr << endl;
		cout << "Apartamente:" << this->Apartamente << endl;
		cout << "Locatari:" << this->Locatari << endl;
		cout << "Are apa calda?" << (this->ApaCalda? "DA":"NU") << endl;
		
	}

	void AfisareInPropozitie() {
		cout << endl << "Blocul de pe strada " << this->Strada << " cu numarul " << this->Nr << ",si " << this->Apartamente << "apartamente,este locuit de " << this->Locatari << " persoane";
	}
};

int main() {

	int nrBlocuri = 10;
	Bloc* vector = new Bloc[nrBlocuri];
	for (int i = 0;i < nrBlocuri ;i++) {
		vector[i].citire();
	}
	/*for (int i = 0;i < nrBlocuri;i++) {
		vector[i].afisare();
	}
	*/
	for (int i = 0;i < nrBlocuri;i++) {
		vector[i].AfisareInPropozitie();
	}
	
}