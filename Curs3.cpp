#include<iostream>
//#include "Curs1.cpp"

using namespace std;

void f0(int a) {
	a = 90;
}

void f1(int& r) {
	r = 80;
}

void f2(int* p) {

}


class Marker {
public:
	string culoare;
	float greutate;
	int lungime;

	Marker() {
		this->culoare = "Albastru";
		this->greutate = 45;
		this->lungime = 12;
	}

	void afisare() {
		cout << "Culoare:" << (*this).culoare << endl;
		cout << "Greutate:" << this->greutate << endl;
		cout << "Lungime:" << this->lungime << endl;
	}

};




void main() {

	Marker marker1;
	marker1.afisare();

	Marker marker2;
	marker2.afisare();


	

	//int a = 10;
	//f0(a);
	//f1(a);
	//f2(&a);

	//int numar = 100;
	//int numar2 = numar;
	//numar2++;
	//cout << numar<<endl;//100

	//int* p = &numar;
	//p++;
	//cout << numar<<endl;//100; 

	//int& ref = numar;
	//ref++;
	//cout << numar<<endl;//100; 
}