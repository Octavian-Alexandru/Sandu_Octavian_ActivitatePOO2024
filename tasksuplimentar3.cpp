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
    static int numarStudenti;

public:
    Student(string nume = "", int varsta = 0) : nume(nume), varsta(varsta) {
        numarStudenti++;
    }

    Student(const Student& other) : nume(other.nume), varsta(other.varsta) {
        numarStudenti++;
    }

    ~Student() {
        numarStudenti--;
    }

    static int getNumarStudenti() {
        return numarStudenti;
    }

    string getNume() const { return nume; }
    int getVarsta() const { return varsta; }
    void setNume(const string& numeNou) { nume = numeNou; }
    void setVarsta(int varstaNoua) { varsta = varstaNoua; }

    void afisare() const override {
        cout << "Student: " << nume << ", Varsta: " << varsta << endl;
    }

    friend void procesareStudent(Student& student, int aniAdaugati);
    friend void afisareDetaliiStudent(const Student& student);
};

int Student::numarStudenti = 0;

void procesareStudent(Student& student, int aniAdaugati) {
    student.varsta += aniAdaugati;
}

void afisareDetaliiStudent(const Student& student) {
    cout << "Detalii student: Nume - " << student.nume << ", Varsta - " << student.varsta << endl;
}

class Carte : public Obiect {
private:
    string titlu;
    int pagini;

public:
    Carte(string titlu = "", int pagini = 0) : titlu(titlu), pagini(pagini) {}

    Carte(const Carte& other) : titlu(other.titlu), pagini(other.pagini) {}

    ~Carte() {}

    string getTitlu() const { return titlu; }
    int getPagini() const { return pagini; }
    void setTitlu(const string& titluNou) { titlu = titluNou; }
    void setPagini(int paginiNoi) { pagini = paginiNoi; }

    void afisare() const override {
        cout << "Carte: " << titlu << ", Pagini: " << pagini << endl;
    }

    friend void procesareCarte(Carte& carte, int paginiAdaugate);
    friend void afisareDetaliiCarte(const Carte& carte);
};

void procesareCarte(Carte& carte, int paginiAdaugate) {
    carte.pagini += paginiAdaugate;
}

void afisareDetaliiCarte(const Carte& carte) {
    cout << "Detalii carte: Titlu - " << carte.titlu << ", Pagini - " << carte.pagini << endl;
}

int main() {
    Student s1("Alice", 20);
    Student s2("Bob", 22);

    procesareStudent(s1, 5);
    afisareDetaliiStudent(s1);

    cout << "Numar total de studenti: " << Student::getNumarStudenti() << endl;

    Carte c1("Programare in C++", 500);
    procesareCarte(c1, 100);
    afisareDetaliiCarte(c1);

    cout << "Testare getter si setter:" << endl;
    s1.setNume("Charlie");
    s1.setVarsta(30);
    cout << "Nume: " << s1.getNume() << ", Varsta: " << s1.getVarsta() << endl;

    c1.setTitlu("Structuri de Date");
    c1.setPagini(600);
    cout << "Titlu: " << c1.getTitlu() << ", Pagini: " << c1.getPagini() << endl;

    return 0;
}
