#include<iostream>
using namespace std;

class Marker {
public:
	static int numarObiecte;
	const int id;
	string culoare;
	float greutate;
	int lungime;
	char* producator;
public:

	Marker():id(++numarObiecte),greutate(45) {
		this->culoare = "Albastru";
		//this->greutate = 45;
		this->lungime = 12;
		this->producator = NULL;
	}

	Marker(string culoare, float greutate, int lungime): id(++numarObiecte) {
		this->culoare = culoare;
		this->greutate = greutate;
		this->lungime = lungime;
		this->producator = new char[strlen("B4U") + 1];
		strcpy_s(this->producator, strlen("B4U") + 1, "B4U");
	}

	Marker(const Marker &m) : id(++numarObiecte) {
		this->culoare = m.culoare;
		this->greutate = m.greutate;
		this->lungime = m.lungime;
		this->producator = new char[strlen(m.producator) + 1];
		strcpy_s(this->producator, strlen(m.producator) + 1, m.producator);
	}

	string getCuloare() {
		return this->culoare;
	}

	void setCuloare(string nouaCuloare) {
		if (nouaCuloare.length() > 2) {
			this->culoare = nouaCuloare;
		}
	}

	void afisare() {
		cout << "ID:" << this->id << endl;
		cout << "Culoare:" << (*this).culoare << endl;
		cout << "Greutate:" << this->greutate << endl;
		cout << "Lungime:" << this->lungime << endl<<endl;
	}

	~Marker() {
		if (this->producator != NULL) {
			delete[]this->producator;
		}
	}

	static int getNumarObiecte() {
		return numarObiecte;
	}
};
int Marker::numarObiecte = 0;

void f(Marker a) {

}

void f(int* a) {

}
void f(int& a) {

}

void main() {
	cout << Marker::getNumarObiecte()<<endl;

	Marker marker1;
	//marker1.afisare();
	//cout << marker1.getCuloare() << endl;
	marker1.setCuloare("Verde");
	//cout << marker1.getCuloare() << endl;

	
		Marker marker2("Rosu", 53, 10);
		//marker2.afisare();
	
	Marker* pMarker = new Marker();
	delete pMarker;

	Marker marker3 = marker2;
	/*strcpy_s(marker3.producator, 4, "qwe");
	cout << marker2.producator << endl;*/

	Marker marker4(marker1);




	Marker marker5;
	//marker5 = marker2;









	//shallow copy - copierea de adrese ci nu de continut;
	// 
	// 


	//Marker* vector = new Marker[10];
}