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

    void afisare() {
        cout << "Santierul cu un cost de " << cost << " euro, inceput in anul " << anulInceperii << " ,are o suprafata de " << suprafata
            << " metri patrati, in zona " << zona << " unde utilajul cel mai folosit este " << numeUtilaj << ".\n";
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

    void afisare() {
        cout << profesie << " au un salariu de inceput de " << salariuInceput << ". Ei sunt in numar de " << nrAngajati << " cu varste de ";
        if (nrAngajati != 0 && varste != NULL) {
            for (int i = 0; i < nrAngajati; i++) {
                cout << varste[i] << " ";
            }
        }
        else {
            cout << "-";
        }
        cout << endl;
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

    void afisare() {
        cout << "Fiind dat anul minim al utilajelor de " << anMinimFabricatie << " ,utilajul " << nume << " consuma "
            << tipCombustibil << " ,este in numar de " << nrUtilaje << " avand marcile : ";
        if (nrUtilaje != 0 && marca != NULL) {
            for (int i = 0; i < nrUtilaje; i++) {
                cout << marca[i] << " ";
            }
        }
        else {
            cout << "-";
        }
        cout << endl;
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

int main() {
    SANTIER santier1;
    santier1.afisare();

    char* numeUtilaj = new char[strlen("Excavator") + 1];
    strcpy_s(numeUtilaj, strlen("Excavator") + 1, "Excavator");
    SANTIER santier2(2015, 901.7, "Baia Mare", numeUtilaj);
    SANTIER::schimbareCost(12000);
    santier2.afisare();

    SANTIER santier3(2008, 498.6);
    santier3.afisare();

    Muncitori muncitori1;
    muncitori1.afisare();

    int varste[2] = { 50, 48 };
    Muncitori muncitori2("Manegerii", 2, varste);
    Muncitori::marireSalariuInceput(500);
    muncitori2.afisare();

    Muncitori muncitori3("Asistentele");
    muncitori3.afisare();

    AfiseazaMuncitoriSubVarsta(muncitori1, 45); 

    Utilaje utilaje1;
    utilaje1.afisare();

    string marca[3] = { "Hitachi", "Volvo", "Hyundai" };
    Utilaje utilaje2("Motorina", 3, "Excavator", marca);
    utilaje2.afisare();

    Utilaje utilaje3("Motocultor");
    utilaje3.afisare();

    AdaugaMarcaUtilaj(utilaje2, "CAT"); 

    SANTIER santier4;
    SANTIER santier5;
    SANTIER santier6;

    santier6 = santier4 + santier5;
    santier6.afisare();

    if (santier1 == santier2) {
        cout << "Santier1 este egal cu Santier2.\n";
    }
    else {
        cout << "Santier1 nu este egal cu Santier2.\n";
    }

    if (santier1 != santier3) {
        cout << "Santier1 este diferit de Santier3.\n";
    }
    else {
        cout << "Santier1 nu este diferit de Santier3.\n";
    }

    Muncitori muncitori4;
    Muncitori muncitori5;

    muncitori4 = muncitori2;
    muncitori4.afisare();

    if (muncitori4 == muncitori5) {
        cout << "Muncitori4 este egal cu Muncitori5.\n";
    }
    else {
        cout << "Muncitori4 nu este egal cu Muncitori5.\n";
    }

    if (muncitori2 != muncitori3) {
        cout << "Muncitori2 este diferit de Muncitori3.\n";
    }
    else {
        cout << "Muncitori2 nu este diferit de Muncitori3.\n";
    }

    int varstaMuncitor2 = muncitori2[0];
    cout << "Varsta primului muncitor din Muncitori2 este: " << varstaMuncitor2 << " ani.\n";

    Utilaje utilaje4;
    Utilaje utilaje5;
    Utilaje utilaje6;

    utilaje6 = utilaje4 + utilaje5;
    utilaje6.afisare();

    if (utilaje1 == utilaje2) {
        cout << "Utilaje1 este egal cu Utilaje2.\n";
    }
    else {
        cout << "Utilaje1 nu este egal cu Utilaje2.\n";
    }

    if (utilaje1 != utilaje3) {
        cout << "Utilaje1 este diferit de Utilaje3.\n";
    }
    else {
        cout << "Utilaje1 nu este diferit de Utilaje3.\n";
    }

    return 0;
}
