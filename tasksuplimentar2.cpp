#include <iostream>

using namespace std;

class Monitor {
public:
	const int id;
	static string brand;
	string nume;
	float diagonala;
	float pret;


	Monitor() :id(0) {

		nume = "v0";
		diagonala = 14.0;
		pret = 425.99;

	};
	Monitor(string nume, float diagonala, float pret) :id(1) {

		this->nume = nume;
		this->diagonala = diagonala;
		this->pret = pret;

	};
	Monitor(const Monitor& old) :id(2) {
		this->nume = old.nume;
		this->diagonala = old.diagonala;
		this->pret = old.pret;

	};

	void AfisareMonitor() {
		cout << "id:" << this->id << endl;
		cout << "brand:" << this->brand << endl;
		cout << "nume:" << this->nume << endl;
		cout << "diagonala:" << this->diagonala << endl;
		cout << "pret:" << this->pret << endl;

	};

	float getPret() {
		return pret;
	}

	static float CrestereaPreturilor(float pret) {
		float noulpret;
		noulpret = pret + pret / 2;
		cout << "Pretul dupa marire al obiectului " << "este:" << noulpret << endl;
		return noulpret;
	};
	float setPret(float noulpret) {
		this->pret = noulpret;
		return pret;
	}
};

class Tastatura {

public:
	const int id;
	static string brand;
	string nume;
	float diagonala;
	float pret;


	Tastatura() :id(0) {

		nume = "v0";
		diagonala = 14.0;
		pret = 425.99;

	};
	Tastatura(string nume, float diagonala, float pret) :id(1) {

		this->nume = nume;
		this->diagonala = diagonala;
		this->pret = pret;

	};
	Tastatura(const Monitor& old) :id(2) {
		this->nume = old.nume;
		this->diagonala = old.diagonala;
		this->pret = old.pret;

	};

	void AfisareTastatura() {
		cout << "id:" << this->id << endl;
		cout << "brand:" << this->brand << endl;
		cout << "nume:" << this->nume << endl;
		cout << "diagonala:" << this->diagonala << endl;
		cout << "pret:" << this->pret << endl;

	};

	float getPret() {
		return pret;
	}

	static float CrestereaPreturilor(float pret) {
		float noulpret;
		noulpret = pret + pret / 2;
		cout << "Pretul dupa marire al obiectului " << "este:" << noulpret << endl;
		return noulpret;
	};
	float setPret(float noulpret) {
		this->pret = noulpret;
		return pret;
	}
};


class Calculator {

public:
	const int id;
	static string brand;
	string nume;
	float diagonala;
	float pret;


	Calculator() :id(0) {

		nume = "v0";
		diagonala = 14.0;
		pret = 425.99;

	};
	Calculator(string nume, float diagonala, float pret) :id(1) {

		this->nume = nume;
		this->diagonala = diagonala;
		this->pret = pret;

	};
	Calculator(const Monitor& old) :id(2) {
		this->nume = old.nume;
		this->diagonala = old.diagonala;
		this->pret = old.pret;

	};

	void AfisareCalculator() {
		cout << "id:" << this->id << endl;
		cout << "brand:" << this->brand << endl;
		cout << "nume:" << this->nume << endl;
		cout << "diagonala:" << this->diagonala << endl;
		cout << "pret:" << this->pret << endl;

	};

	float getPret() {
		return pret;
	}

	static float CrestereaPreturilor(float pret) {
		float noulpret;
		noulpret = pret + pret / 2;
		cout << "Pretul dupa marire al obiectului " << "este:" << noulpret << endl;
		return noulpret;
	};
	float setPret(float noulpret) {
		this->pret = noulpret;
		return pret;
	}
};

string Calculator::brand = "Acer";
string Tastatura::brand = "Myria";
string Monitor::brand = "Samsung";

int main() {

	//monitoare


	Monitor m1;
	Monitor m2("v2", 4.3, 564.3);
	Monitor m3 = m2;

	m1.AfisareMonitor();
	m2.AfisareMonitor();
	m3.AfisareMonitor();

	//marire preturi
	m1.setPret(Monitor::CrestereaPreturilor(m1.getPret()));
	m2.setPret(Monitor::CrestereaPreturilor(m2.getPret()));
	m3.setPret(Monitor::CrestereaPreturilor(m3.getPret()));

	//tastaturi

	Tastatura t1;
	Tastatura t2("v2", 4.3, 564.3);
	Tastatura t3 = t2;

	t1.AfisareTastatura();
	t2.AfisareTastatura();
	t3.AfisareTastatura();

	t1.setPret(Monitor::CrestereaPreturilor(t1.getPret()));
	t2.setPret(Monitor::CrestereaPreturilor(t2.getPret()));
	t3.setPret(Monitor::CrestereaPreturilor(t3.getPret()));


	//Calculatoare
	Calculator c1;
	Calculator c2("v2", 4.3, 564.3);
	Calculator c3 = c2;

	c1.AfisareCalculator();
	c2.AfisareCalculator();
	c3.AfisareCalculator();

	c1.setPret(Monitor::CrestereaPreturilor(c1.getPret()));
	c2.setPret(Monitor::CrestereaPreturilor(c2.getPret()));
	c3.setPret(Monitor::CrestereaPreturilor(c3.getPret()));


};