#include <iostream>
using namespace std;

class SANTIER {
private:
    static int cost;
    const int anulInceperii;
    float suprafata;
    string zona;
    char* numeUtilaj;

public:
    SANTIER() : anulInceperii(2010) {
        this->suprafata = 799.5;
        this->zona = "Brasov";
        this->numeUtilaj = new char[strlen("Buldozer") + 1];
        strcpy_s(this->numeUtilaj, strlen("Buldozer") + 1, "Buldozer");
    }

    SANTIER(int anulInceperii, float suprafata, string zona, char* numeUtilaj) : anulInceperii(anulInceperii), suprafata(suprafata), zona(zona) {
        this->numeUtilaj = new char[strlen(numeUtilaj) + 1];
        strcpy_s(this->numeUtilaj, strlen(numeUtilaj) + 1, numeUtilaj);
    }

    SANTIER(int anulInceperii, float suprafata) : anulInceperii(anulInceperii), suprafata(suprafata) {
        this->zona = "Targoviste";
        this->numeUtilaj = new char[strlen("Tractor") + 1];
        strcpy_s(this->numeUtilaj, strlen("Tractor") + 1, "Tractor");
    }

    SANTIER(const SANTIER& s) : anulInceperii(s.anulInceperii), suprafata(s.suprafata), zona(s.zona) {
        this->numeUtilaj = new char[strlen(s.numeUtilaj) + 1];
        strcpy_s(this->numeUtilaj, strlen(s.numeUtilaj) + 1, s.numeUtilaj);
    }

    int getAnulInceperii() const { return anulInceperii; }
    float getSuprafata() const { return suprafata; }
    string getZona() const { return zona; }
    char* getNumeUtilaj() const { return numeUtilaj; }

    void setSuprafata(float suprafata) { this->suprafata = suprafata; }
    void setZona(const string& zona) { this->zona = zona; }
    void setNumeUtilaj(const char* numeUtilaj) {
        if (this->numeUtilaj) delete[] this->numeUtilaj;
        this->numeUtilaj = new char[strlen(numeUtilaj) + 1];
        strcpy_s(this->numeUtilaj, strlen(numeUtilaj) + 1, numeUtilaj);
    }

    friend ostream& operator<<(ostream& os, const SANTIER& santier);

    friend istream& operator>>(istream& is, SANTIER& santier) {
  
        cout << "Introduceti suprafata: ";
        is >> santier.suprafata;
        cout << "Introduceti zona: ";
        is >> santier.zona;
        if (santier.numeUtilaj != NULL) {
            delete[]santier.numeUtilaj;
        }
        cout << "Introduceti numele utilajului: ";
        santier.numeUtilaj = new char[100];
        is >> santier.numeUtilaj;
        

        return is;
    }

    ~SANTIER() {
        if (numeUtilaj != NULL) {
            delete[] numeUtilaj;
        }
    }

    static void schimbareCost(int costNou) {
        cost = costNou;
    }

    SANTIER& operator=(const SANTIER& s) {
        if (this == &s) {
            return *this;
        }

        suprafata = s.suprafata;
        zona = s.zona;

        delete[] numeUtilaj;
        numeUtilaj = new char[strlen(s.numeUtilaj) + 1];
        strcpy_s(numeUtilaj, strlen(s.numeUtilaj) + 1, s.numeUtilaj);

        return *this;
    }


    bool operator==(const SANTIER& s) const {
        return (anulInceperii == s.anulInceperii && suprafata == s.suprafata && zona == s.zona && strcmp(numeUtilaj, s.numeUtilaj) == 0);
    }


    bool operator!=(const SANTIER& s) const {
        return !(*this == s);
    }


    SANTIER operator+(const SANTIER& s) const {
        SANTIER sumaSantier = *this;
        sumaSantier.suprafata += s.suprafata;
        return sumaSantier;
    }
};

int SANTIER::cost = 100000;

class Muncitori {
private:
    const string profesie;
    static float salariuInceput;
    int nrAngajati;
    int* varste;

public:
    Muncitori() : profesie("Inginerii") {
        this->nrAngajati = 3;
        this->varste = new int[this->nrAngajati];
        this->varste[0] = 32;
        this->varste[1] = 29;
        this->varste[2] = 46;
    }

    Muncitori(string profesie, int nrAngajati, int* varste) : profesie(profesie), nrAngajati(nrAngajati) {
        this->varste = new int[nrAngajati];
        for (int i = 0; i < nrAngajati; i++) {
            this->varste[i] = varste[i];
        }
    }

    Muncitori(string profesie) : profesie(profesie), nrAngajati(0) {
        this->varste = new int[this->nrAngajati];
        for (int i = 0; i < this->nrAngajati; i++)
        {
            this->varste[i] = varste[i];
        }
    }

    Muncitori(const Muncitori& m) : profesie(m.profesie), nrAngajati(m.nrAngajati) {
        if (nrAngajati > 0) {
            varste = new int[nrAngajati];
            for (int i = 0; i < nrAngajati; i++) {
                varste[i] = m.varste[i];
            }
        }
        else {
            varste = NULL;
        }
    }

    string getProfesie() const { return profesie; }
    float getSalariuInceput() const { return salariuInceput; }
    int getNrAngajati() const { return nrAngajati; }
    int* getVarste() const { return varste; }

    void setNrAngajati(int nrAngajati) { this->nrAngajati = nrAngajati; }
    void setVarste(const int* varste) {
        if (this->varste) delete[] this->varste;
        this->varste = new int[nrAngajati];
        for (int i = 0; i < nrAngajati; i++) {
            this->varste[i] = varste[i];
        }
    }

    friend ostream& operator<<(ostream& os, const Muncitori& muncitori);

    friend istream& operator>>(istream& is, Muncitori& muncitori) {
       
        cout << "Introduceti numarul de angajati: ";
        is >> muncitori.nrAngajati;
        if (muncitori.varste != NULL) {
            delete[]muncitori.varste;
        }
        if (muncitori.nrAngajati > 0) {
            muncitori.varste = new int[muncitori.nrAngajati];
            cout << "Introduceti varstele angajatilor: ";
            for (int i = 0; i < muncitori.nrAngajati; i++) {
                is >> muncitori.varste[i];
            }
        }


        return is;
    }

    ~Muncitori() {
        delete[] varste;
    }

    static void marireSalariuInceput(float marire) {
        salariuInceput += marire;
    }


    Muncitori& operator=(const Muncitori& m) {
        if (this == &m) {
            return *this;
        }

        nrAngajati = m.nrAngajati;
        delete[] varste;
        varste = new int[nrAngajati];

        for (int i = 0; i < nrAngajati; i++) {
            varste[i] = m.varste[i];
        }

        return *this;
    }


    bool operator==(const Muncitori& m) const {
        if (profesie != m.profesie || nrAngajati != m.nrAngajati) {
            return false;
        }

        for (int i = 0; i < nrAngajati; i++) {
            if (varste[i] != m.varste[i]) {
                return false;
            }
        }

        return true;
    }


    bool operator!=(const Muncitori& m) const {
        return !(*this == m);
    }


    int operator[](int index) {
        if (index >= 0 && index < nrAngajati) {
            return varste[index];
        }
        return -1;
    }

    friend void AfiseazaMuncitoriSubVarsta(Muncitori& muncitori, int limitaVarsta);
};

float Muncitori::salariuInceput = 3000;

class Utilaje {
private:
    const string tipCombustibil;
    static int anMinimFabricatie;
    int nrUtilaje;
    string nume;
    string* marca;

public:

    Utilaje() : tipCombustibil("Motorina") {
        this->nrUtilaje = 2;
        this->nume = "Buldozer";
        this->marca = new string[this->nrUtilaje];
        this->marca[0] = "CAT";
        this->marca[1] = "Komatsu";
    }

    Utilaje(string tipCombustibil, int nrUtilaje, string nume, string* marca) : tipCombustibil(tipCombustibil), nrUtilaje(nrUtilaje), nume(nume) {
        this->marca = new string[nrUtilaje];
        for (int i = 0; i < nrUtilaje; i++) {
            this->marca[i] = marca[i];
        }
    }

    Utilaje(string nume) : tipCombustibil("Benzina"), nrUtilaje(0) {
        this->marca = NULL;
    }

    Utilaje(const Utilaje& u) : tipCombustibil(u.tipCombustibil), nrUtilaje(u.nrUtilaje), nume(u.nume) {
        if (nrUtilaje > 0) {
            marca = new string[nrUtilaje];
            for (int i = 0; i < nrUtilaje; i++) {
                marca[i] = u.marca[i];
            }
        }
        else {
            marca = NULL;
        }
    }

    string getTipCombustibil() const { return tipCombustibil; }
    int getAnMinimFabricatie() const { return anMinimFabricatie; }
    int getNrUtilaje() const { return nrUtilaje; }
    string getNume() const { return nume; }
    string* getMarca() const { return marca; }

    void setNrUtilaje(int nrUtilaje) { this->nrUtilaje = nrUtilaje; }
    void setNume(const string& nume) { this->nume = nume; }
    void setMarca(const string* marci, int nrMarci) {
        if (marca != NULL) {
            delete[] marca;
        }

        marca = new string[nrMarci];
        for (int i = 0; i < nrMarci; i++) {
            marca[i] = marci[i];
        }

        nrUtilaje = nrMarci;
    }

    friend ostream& operator<<(ostream& os, const Utilaje& utilaje);

    friend istream& operator>>(istream& is, Utilaje& utilaje) {
        cout << "Introduceti numarul de utilaje: ";
        is >> utilaje.nrUtilaje;
        if (utilaje.marca != NULL) {
            delete[]utilaje.marca;
        }
        if (utilaje.nrUtilaje > 0) {
            utilaje.marca = new string[utilaje.nrUtilaje];
            cout << "Introduceti marcile utilajelor: ";
            for (int i = 0; i < utilaje.nrUtilaje; i++) {
                is >> utilaje.marca[i];
            }
        }


        return is;
    }

    ~Utilaje() {
        delete[] marca;
    }

    static int returnareAn() {
        return anMinimFabricatie;
    }


    Utilaje& operator=(const Utilaje& u) {
        if (this == &u) {
            return *this;
        }

        nrUtilaje = u.nrUtilaje;
        nume = u.nume;

        delete[] marca;
        marca = new string[nrUtilaje];

        for (int i = 0; i < nrUtilaje; i++) {
            marca[i] = u.marca[i];
        }

        return *this;
    }


    bool operator==(const Utilaje& u) const {
        if (tipCombustibil != u.tipCombustibil || nrUtilaje != u.nrUtilaje || nume != u.nume) {
            return false;
        }

        for (int i = 0; i < nrUtilaje; i++) {
            if (marca[i] != u.marca[i]) {
                return false;
            }
        }

        return true;
    }


    bool operator!=(const Utilaje& u) const {
        return !(*this == u);
    }


    Utilaje operator+(const Utilaje& u) const {
        Utilaje sumaUtilaje = *this;
        sumaUtilaje.nrUtilaje += u.nrUtilaje;
        sumaUtilaje.nume += " si " + u.nume;
        string* newMarca = new string[sumaUtilaje.nrUtilaje];

        for (int i = 0; i < nrUtilaje; i++) {
            newMarca[i] = sumaUtilaje.marca[i];
        }

        for (int i = nrUtilaje; i < sumaUtilaje.nrUtilaje; i++) {
            newMarca[i] = u.marca[i - nrUtilaje];
        }

        delete[] sumaUtilaje.marca;
        sumaUtilaje.marca = newMarca;
        return sumaUtilaje;
    }

    friend void AdaugaMarcaUtilaj(Utilaje& utilaje, const string& marcaNoua);

};

int Utilaje::anMinimFabricatie = 2003;


void AfiseazaMuncitoriSubVarsta(Muncitori& muncitori, int limitaVarsta) {
    cout << "Muncitorii cu varsta sub " << limitaVarsta << " ani sunt: ";
    int* varste = muncitori.getVarste();
    int nrAngajati = muncitori.getNrAngajati();

    if (varste != NULL) {
        for (int i = 0; i < nrAngajati; i++) {
            if (varste[i] < limitaVarsta) {
                cout << varste[i] << " ";
            }
        }
    }

    cout << endl;
}


void AdaugaMarcaUtilaj(Utilaje& utilaje, const string& marcaNoua) {
    int nrUtilaje = utilaje.getNrUtilaje();
    string* marci = utilaje.getMarca();


    string* marciNoi = new string[nrUtilaje + 1];
    for (int i = 0; i < nrUtilaje; i++) {
        marciNoi[i] = marci[i];
    }
    marciNoi[nrUtilaje] = marcaNoua;

    utilaje.setMarca(marciNoi, nrUtilaje + 1);
    cout << "Marca " << marcaNoua << " a fost adaugata la lista de marci a utilajului.\n";
}

ostream& operator<<(ostream& os, const SANTIER& santier) {
    os << "Anul Inceperii: " << santier.getAnulInceperii() << "\n";
    os << "Suprafata: " << santier.getSuprafata() << "\n";
    os << "Zona: " << santier.getZona() << "\n";
    os << "Nume Utilaj: " << santier.getNumeUtilaj() << "\n";
    return os;
}

ostream& operator<<(ostream& os, const Muncitori& muncitori) {
    os << "Profesie: " << muncitori.getProfesie() << "\n";
    os << "Nr. Angajati: " << muncitori.getNrAngajati() << "\n";
    os << "Varste: ";
    int* varste = muncitori.getVarste();
    for (int i = 0; i < muncitori.getNrAngajati(); ++i) {
        os << varste[i] << " ";
    }
    os << "\n";
    return os;
}

ostream& operator<<(ostream& os, const Utilaje& utilaje) {
    os << "Tip Combustibil: " << utilaje.getTipCombustibil() << "\n";
    os << "Nr. Utilaje: " << utilaje.getNrUtilaje() << "\n";
    os << "Nume: " << utilaje.getNume() << "\n";
    os << "Marci: ";
    string* marci = utilaje.getMarca();
    for (int i = 0; i < utilaje.getNrUtilaje(); ++i) {
        os << marci[i] << " ";
    }
    os << "\n";
    return os;
}

void main() {
    SANTIER santier1;
    char* numeUtilaj = new char[strlen("Excavator") + 1];
    strcpy_s(numeUtilaj, strlen("Excavator") + 1, "Excavator");
    SANTIER santier2(2015, 1200, "Constanta", numeUtilaj);
    SANTIER santier3(2018, 900);
    SANTIER santier4 = santier1;

    cout << "Anul Inceperii santier1: " << santier1.getAnulInceperii() << endl;
    cout << "Suprafata santier2: " << santier2.getSuprafata() << endl;
    cout << "Zona santier3: " << santier3.getZona() << endl;
    cout << "Nume Utilaj santier4: " << santier4.getNumeUtilaj() << endl;

    santier1.setSuprafata(1000);
    santier2.setZona("Bucuresti");
    santier3.setNumeUtilaj("Macara");

    cout << "Santier 1:\n" << santier1 << endl;
    cout << "Santier 2:\n" << santier2 << endl;
    cout << "Santier 3:\n" << santier3 << endl;

    SANTIER santierSuma = santier1 + santier2;
    cout << "Suma Suprafetelor: " << santierSuma.getSuprafata() << endl;

    int* varsteMuncitori = new int[3]; 
    varsteMuncitori[0] = 28;
    varsteMuncitori[1] = 35;
    varsteMuncitori[2] = 42;
    Muncitori muncitori1;
    Muncitori muncitori2("Constructori", 4, varsteMuncitori);
    Muncitori muncitori3("Sudori");

    cout << "Muncitori 1:\n" << muncitori1 << endl;
    cout << "Muncitori 2:\n" << muncitori2 << endl;
    cout << "Muncitori 3:\n" << muncitori3 << endl;

    muncitori3 = muncitori2;
    cout << "Nr. Angajati Muncitori 3: " << muncitori3.getNrAngajati() << endl;

    string* marciUtilaje = new string[2]; 
    marciUtilaje[0] = "Liebherr";
    marciUtilaje[1] = "Volvo";
    Utilaje utilaje1;
    Utilaje utilaje2("Motorina", 2, "Buldozer", marciUtilaje);
    Utilaje utilaje3("Excavator");

    cout << "Utilaje 1:\n" << utilaje1 << endl;
    cout << "Utilaje 2:\n" << utilaje2 << endl;
    cout << "Utilaje 3:\n" << utilaje3 << endl;

    AdaugaMarcaUtilaj(utilaje1, "Caterpillar");
    cout << "Utilaje 1 dupa adaugare marca:\n" << utilaje1 << endl;

    SANTIER* vectorSantier=new SANTIER[2];
    for (int i = 0; i < 2; i++) {
        cout << "Introduceti datele pentru santier " << ":\n";
        cin >> vectorSantier[i];
    }

    for (int i = 0; i < 2; i++) {
        cout << "Obiectele citite din vector sunt:\n";
        cout << vectorSantier[i] << "\n";
    }

    Muncitori* vectorMuncitori = new Muncitori[2];
    for (int i = 0; i < 2; i++) {
        cout << "Introduceti datele pentru muncitori " << ":\n";
        cin >> vectorMuncitori[i];
    }

    for (int i = 0; i < 2; i++) {
        cout << "Obiectele citite din vector sunt:\n";
        cout << vectorMuncitori[i] << "\n";
    }

    Utilaje* vectorUtilaje = new Utilaje[2];
    for (int i = 0; i < 2; i++) {
        cout << "Introduceti datele pentru utilaje " << ":\n";
        cin >> vectorUtilaje[i];
    }

    for (int i = 0; i < 2; i++) {
        cout << "Obiectele citite din vector sunt:\n";
        cout << vectorUtilaje[i] << "\n";
    }

    const int numarSantiere = 2;
    const int numarObiectePerSantier = 2;
    SANTIER matriceSantiere[numarSantiere][numarObiectePerSantier];
    for (int i = 0; i < numarSantiere; i++) {
        for (int j = 0; j < numarObiectePerSantier; j++) {
            cout << "Introduceti datele pentru santierul " << i + 1 << ", obiectul " << j + 1 << ":\n";
            cin >> matriceSantiere[i][j];
        }
    }
    cout << "Obiectele citite din matrice sunt:\n";
    for (int i = 0; i < numarSantiere; i++) {
        for (int j = 0; j < numarObiectePerSantier; j++) {
            cout << matriceSantiere[i][j] << "\n";
        }
    }

}
