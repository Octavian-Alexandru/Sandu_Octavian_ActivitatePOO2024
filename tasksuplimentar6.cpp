#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
private:
    string nume;
    int varsta;

public:
    Student(string nume = "", int varsta = 0) : nume(nume), varsta(varsta) {}

    Student& operator=(const Student& other) {
        if (this != &other) {
            nume = other.nume;
            varsta = other.varsta;
        }
        return *this;
    }

    Student operator+(int ani) const {
        return Student(nume, varsta + ani);
    }

    bool operator==(const Student& other) const {
        return (nume == other.nume && varsta == other.varsta);
    }

    friend ostream& operator<<(ostream& out, const Student& student) {
        out << "Student: " << student.nume << ", Varsta: " << student.varsta;
        return out;
    }

    string getNume() const { return nume; }
    int getVarsta() const { return varsta; }
};

class Carte {
private:
    string titlu;
    int pagini;

public:
    Carte(string titlu = "", int pagini = 0) : titlu(titlu), pagini(pagini) {}

    Carte& operator=(const Carte& other) {
        if (this != &other) {
            titlu = other.titlu;
            pagini = other.pagini;
        }
        return *this;
    }

    Carte operator-(int paginiScazute) const {
        return Carte(titlu, pagini - paginiScazute);
    }

    bool operator>(const Carte& other) const {
        return pagini > other.pagini;
    }

    friend ostream& operator<<(ostream& out, const Carte& carte) {
        out << "Carte: " << carte.titlu << ", Pagini: " << carte.pagini;
        return out;
    }

    string getTitlu() const { return titlu; }
    int getPagini() const { return pagini; }
};

class Sectiune {
private:
    vector<Carte> carti;
    string numeSectiune;
    int numarRafturi;

public:
    Sectiune(string numeSectiune = "", int numarRafturi = 0) : numeSectiune(numeSectiune), numarRafturi(numarRafturi) {}

    void adaugaCarte(const Carte& carte) {
        carti.push_back(carte);
    }

    void stergeCarte(int index) {
        if (index >= 0 && index < carti.size()) {
            carti.erase(carti.begin() + index);
        }
    }

    Sectiune& operator=(const Sectiune& other) {
        if (this != &other) {
            carti = other.carti;
            numeSectiune = other.numeSectiune;
            numarRafturi = other.numarRafturi;
        }
        return *this;
    }

    bool operator==(const Sectiune& other) const {
        return (numeSectiune == other.numeSectiune && numarRafturi == other.numarRafturi && carti == other.carti);
    }

    friend ostream& operator<<(ostream& out, const Sectiune& sectiune) {
        out << "Sectiune: " << sectiune.numeSectiune << ", Rafturi: " << sectiune.numarRafturi << "\nCarti:\n";
        for (const auto& carte : sectiune.carti) {
            out << carte << "\n";
        }
        return out;
    }

    string getNumeSectiune() const { return numeSectiune; }
    void setNumeSectiune(const string& nume) { numeSectiune = nume; }

    int getNumarRafturi() const { return numarRafturi; }
    void setNumarRafturi(int rafturi) { numarRafturi = rafturi; }

    vector<Carte> getCarti() const { return carti; }
};

int main() {
    Carte c1("Programare in C++", 500);
    Carte c2("Structuri de Date", 300);

    Sectiune sectiune1("Informatica", 5);
    sectiune1.adaugaCarte(c1);
    sectiune1.adaugaCarte(c2);

    cout << sectiune1 << endl;

    Sectiune sectiune2 = sectiune1;
    cout << (sectiune1 == sectiune2 ? "Sectiunile sunt identice" : "Sectiunile sunt diferite") << endl;

    sectiune2.setNumeSectiune("Matematica");
    sectiune2.setNumarRafturi(3);
    cout << sectiune2 << endl;

    return 0;
}
