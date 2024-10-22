#include<iostream>

using namespace std;

void main() {
	int a = 10;
	int* pa = &a;
	cout << pa<<endl;
	pa++;
	cout << pa << endl;
	pa = pa - 1;
	cout << pa<<endl;
	int** ppa = &pa;

	double d = 20.4;
	double* pd = &d;
	cout <<ppa<<" - " << *ppa << " - " << *(*ppa);


	int* v1;
	int* v2;

	//v1 = (int*)malloc(sizeof(int));
	v1 = new int(8);
	v2 = new int[3] {2, 6, 8};


	delete v1;
	delete []v2;

}