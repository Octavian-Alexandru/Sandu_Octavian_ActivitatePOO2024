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

void afisareStudentSiCarte(const Student& student, const Carte& carte) {
    cout << "[Functie Prietena] " << student.getNume() << " citeste '" << carte.getTitlu() << "' care are " << carte.getPagini() << " pagini." << endl;
}

class Biblioteca {
private:
    vector<Carte> carti;
    Student bibliotecar;
    string locatie;

public:
    Biblioteca(string locatie = "", Student bibliotecar = Student()) : locatie(locatie), bibliotecar(bibliotecar) {}

    void adaugaCarte(const Carte& carte) {
        carti.push_back(carte);
    }

    void stergeCarte(int index) {
        if (index >= 0 && index < carti.size()) {
            carti.erase(carti.begin() + index);
        }
    }

    Biblioteca& operator=(const Biblioteca& other) {
        if (this != &other) {
            carti = other.carti;
            bibliotecar = other.bibliotecar;
            locatie = other.locatie;
        }
        return *this;
    }

    bool operator==(const Biblioteca& other) const {
        return (carti == other.carti && bibliotecar == other.bibliotecar && locatie == other.locatie);
    }

    friend ostream& operator<<(ostream& out, const Biblioteca& biblioteca) {
        out << "Biblioteca din " << biblioteca.locatie << " gestionata de " << biblioteca.bibliotecar << ". Carti: \n";
        for (const auto& carte : biblioteca.carti) {
            out << carte << "\n";
        }
        return out;
    }

    string getLocatie() const { return locatie; }
    void setLocatie(const string& loc) { locatie = loc; }

    Student getBibliotecar() const { return bibliotecar; }
    void setBibliotecar(const Student& lib) { bibliotecar = lib; }

    vector<Carte> getCarti() const { return carti; }
};

class StudentMaster : public Student {
private:
    string temaCercetare;

public:
    StudentMaster(string nume = "", int varsta = 0, string temaCercetare = "") : Student(nume, varsta), temaCercetare(temaCercetare) {}

    string getTemaCercetare() const { return temaCercetare; }
    void setTemaCercetare(const string& tema) { temaCercetare = tema; }

    friend ostream& operator<<(ostream& out, const StudentMaster& master) {
        out << (Student)master << ", Tema Cercetare: " << master.temaCercetare;
        return out;
    }
};

class ECarte : public Carte {
private:
    string formatFisier;

public:
    ECarte(string titlu = "", int pagini = 0, string formatFisier = "PDF") : Carte(titlu, pagini), formatFisier(formatFisier) {}

    string getFormatFisier() const { return formatFisier; }
    void setFormatFisier(const string& format) { formatFisier = format; }

    friend ostream& operator<<(ostream& out, const ECarte& ecarte) {
        out << (Carte)ecarte << ", Format Fisier: " << ecarte.formatFisier;
        return out;
    }
};

int main() {
    Student s1("Alice", 20);
    StudentMaster sm1("Bob", 25, "Inteligenta Artificiala");
    Carte c1("Programare in C++", 500);
    ECarte ec1("C++ Avansat", 400, "EPUB");

    Biblioteca biblioteca("Biblioteca Centrala", s1);
    biblioteca.adaugaCarte(c1);
    biblioteca.adaugaCarte(ec1);

    cout << biblioteca << endl;

    Biblioteca biblioteca2 = biblioteca;
    cout << (biblioteca == biblioteca2 ? "Bibliotecile sunt egale" : "Bibliotecile nu sunt egale") << endl;

    biblioteca.setLocatie("Biblioteca Orasului");
    cout << biblioteca << endl;

    afisareStudentSiCarte(sm1, ec1);

    Student* studentUpcast = &sm1;
    cout << *studentUpcast << endl;

    Carte* carteUpcast = &ec1;
    cout << *carteUpcast << endl;

    return 0;
}
