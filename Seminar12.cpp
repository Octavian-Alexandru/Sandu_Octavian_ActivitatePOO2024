#include <iostream>
#include<map>
#include<list>
using namespace std;

//containerele au 2 elemente <key, value>
//cheile vor fi sortate crescator si unice
//si la containere SET val vor fi unice si cresc

class Aliment {
    string nume;
    float pret;
public:
    Aliment() {
        this->nume = "Aliment";
        this->pret = 0;
    }
    Aliment(string nume, float pret) {
        this->nume = nume;
        this->pret = pret;
    }

    void afisareDescriere() {
        cout << nume << "=>" << pret << endl;
    }
};


int main() {

    //ele se vor salva alfabetic
    map<string, float> preturi;
    preturi.insert(pair<string, float>("Lapte", 23));
    preturi.insert(pair<string, float>("Paine", 7));
    preturi.insert(pair<string, float>("Oua", 16));
    preturi.insert(pair<string, float>("Lapte", 35)); //nu-l suprascrie deci ignora linia, dar mai jos o sa il suprascriu

    preturi["Lapte"] = 67; //indexez dupa cheie si modif pretul din 23 in 67=> adica modific

    //parcurgem "dictionarul de prod" 
    //for-ul nu merge folosit, pt ca elem sunt imprastiate in memorie
    //iterator= pointerul cu care parcurg elem dintr-un map
    //initializez cu begin si end (begin ret adresa de inceput si end cea de sfarsit)

    map<string, float>::iterator it;
    it = preturi.begin();
    int suma = 0;
    while (it != preturi.end()) {
        suma += it->second; //first este cheia, second este value(pretul)
        it++; //trecem la poz urm
    }

    cout << "Preturi totale: " << suma << endl;

    it = preturi.begin();
    while (it != preturi.end()) {
        cout << it->first << "=>" << it->second << endl;
        it++;
    }

    //se fol push back si push front, la vectori nu avem front
    //la set am doar insert
    //la secvential am si insert
    list<Aliment> alimente; //este secventiala
    alimente.push_back(Aliment());
    alimente.push_back(Aliment("Lapte", 20));
    alimente.push_front(Aliment("Paine", 10));
    alimente.push_front(Aliment("Oua", 16));
    cout << endl << "Lista: " << endl;

    //declar iterator
    list<Aliment>::iterator iter = alimente.begin();
    while (iter != alimente.end()) {
        iter->afisareDescriere();
        iter++;
    }


    return 545;
}