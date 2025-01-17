#include <iostream>
#include <string>
#include <vector>
#include <fstream>

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

    void salvareFisierBinar(const string& numeFisier) const {
        ofstream outFile(numeFisier, ios::binary);
        if (outFile.is_open()) {
            size_t lungimeNume = nume.size();
            outFile.write((char*)&lungimeNume, sizeof(lungimeNume));
            outFile.write(nume.c_str(), lungimeNume);
            outFile.write((char*)&varsta, sizeof(varsta));
            outFile.close();
        }
    }

    void citireFisierBinar(const string& numeFisier) {
        ifstream inFile(numeFisier, ios::binary);
        if (inFile.is_open()) {
            size_t lungimeNume;
            inFile.read((char*)&lungimeNume, sizeof(lungimeNume));
            nume.resize(lungimeNume);
            inFile.read(&nume[0], lungimeNume);
            inFile.read((char*)&varsta, sizeof(varsta));
            inFile.close();
        }
    }
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
    Student s1("Alice", 20);
    s1.salvareFisierText("student.txt");
    Student s2;
    s2.citireFisierText("student.txt");
    cout << s2 << endl;

    s1.salvareFisierBinar("student.bin");
    Student s3;
    s3.citireFisierBinar("student.bin");
    cout << s3 << endl;

    Carte c1("Programare in C++", 500);
    c1.salvareFisierText("carte.txt");
    Carte c2;
    c2.citireFisierText("carte.txt");
    cout << c2 << endl;

    return 0;
}
