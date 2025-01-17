#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>

using namespace std;

class Persoana {
public:
    virtual void afisare() const = 0;
    virtual ~Persoana() = default;
};

class Obiect {
public:
    virtual void afisare() const = 0;
    virtual ~Obiect() = default;
};

class Student : public Persoana {
private:
    string nume;
    int varsta;

public:
    Student(string nume = "", int varsta = 0) : nume(nume), varsta(varsta) {}

    void afisare() const override {
        cout << "Student: " << nume << ", Varsta: " << varsta << endl;
    }

    void salvareFisierText(const string& numeFisier) const {
        ofstream outFile(numeFisier);
        if (outFile.is_open()) {
            outFile << nume << "\n" << varsta << "\n";
            outFile.close();
        }
    }

    void citireFisierText(const string& numeFisier) {
        ifstream inFile(numeFisier);
        if (inFile.is_open()) {
            getline(inFile, nume);
            inFile >> varsta;
            inFile.close();
        }
    }

    virtual ~Student() {}
};

class Carte : public Obiect {
private:
    string titlu;
    int pagini;

public:
    Carte(string titlu = "", int pagini = 0) : titlu(titlu), pagini(pagini) {}

    void afisare() const override {
        cout << "Carte: " << titlu << ", Pagini: " << pagini << endl;
    }

    void salvareFisierText(const string& numeFisier) const {
        ofstream outFile(numeFisier);
        if (outFile.is_open()) {
            outFile << titlu << "\n" << pagini << "\n";
            outFile.close();
        }
    }

    void citireFisierText(const string& numeFisier) {
        ifstream inFile(numeFisier);
        if (inFile.is_open()) {
            getline(inFile, titlu);
            inFile >> pagini;
            inFile.close();
        }
    }

    virtual ~Carte() {}
};

class Sectiune {
private:
    vector<shared_ptr<Obiect>> obiecte;
    string numeSectiune;
    int numarRafturi;

public:
    Sectiune(string numeSectiune = "", int numarRafturi = 0) : numeSectiune(numeSectiune), numarRafturi(numarRafturi) {}

    void adaugaObiect(const shared_ptr<Obiect>& obiect) {
        obiecte.push_back(obiect);
    }

    void afisare() const {
        cout << "Sectiune: " << numeSectiune << ", Rafturi: " << numarRafturi << "\nObiecte:\n";
        for (const auto& obiect : obiecte) {
            obiect->afisare();
        }
    }

    virtual ~Sectiune() {}
};

int main() {
    vector<shared_ptr<Persoana>> persoane;
    persoane.push_back(make_shared<Student>("Alice", 20));
    persoane.push_back(make_shared<Student>("Bob", 22));

    for (int i = 2; i < 10; ++i) {
        persoane.push_back(make_shared<Student>("Student" + to_string(i), 20 + i));
    }

    cout << "Afisare persoane:\n";
    for (const auto& persoana : persoane) {
        persoana->afisare();
    }

    vector<shared_ptr<Obiect>> obiecte;
    obiecte.push_back(make_shared<Carte>("Programare in C++", 500));
    obiecte.push_back(make_shared<Carte>("Structuri de Date", 300));

    cout << "\nAfisare obiecte:\n";
    for (const auto& obiect : obiecte) {
        obiect->afisare();
    }

    Sectiune sectiune1("Informatica", 5);
    sectiune1.adaugaObiect(obiecte[0]);
    sectiune1.adaugaObiect(obiecte[1]);
    sectiune1.afisare();

    return 0;
}
