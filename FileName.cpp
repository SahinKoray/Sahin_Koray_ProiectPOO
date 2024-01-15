#include <iostream>
#include <fstream>
using namespace std;
class Colectiv { //Reprezintă o clasă de bază abstractă pentru colective.
private:
    char* nationalitate; // Membrul privat pentru stocarea nationalitatii
public:
    // Constructor implicit - initializeaza nationalitatea cu "Romana"
    Colectiv() {
        this->nationalitate = new char[strlen("Romana") + 1];
        strcpy_s(this->nationalitate, strlen("Romana") + 1, "Romana");
    }
    // Constructor cu parametri - initializeaza nationalitatea cu valoarea furnizata
    Colectiv(char* nationalitate) {
        this->nationalitate = new char[strlen(nationalitate) + 1];
        strcpy_s(this->nationalitate, strlen(nationalitate) + 1, nationalitate);
    }
    // Constructor de copiere - creeaza o copie a obiectului furnizat
    Colectiv(const Colectiv& c) {
        this->nationalitate = new char[strlen(c.nationalitate) + 1];
        strcpy_s(this->nationalitate, strlen(c.nationalitate) + 1, c.nationalitate);
    }
    // Metodă pentru a obține valoarea membrului nationalitate
    const char* getNationalitate() const {
        return nationalitate;
    }
    // Destructor virtual - este marcat cu "virtual" pentru a permite polimorfismul
    virtual ~Colectiv() {
        cout << "Apel destructor COLECTIV" << endl;
        if (this->nationalitate != NULL) {
            delete[]this->nationalitate;
        }
    }
    // Metoda virtuala pura pentru calculul salariului total
    virtual void calculeazaSalariulTotal() = 0;
};
//Reprezintă un plan de lucru, fiind tot o clasă de bază abstractă
class PlanDeLucru { //planul de a incepe un santier(nu am avut alte idei)
private:
    char* firma;//firma care a venit cu acest plan (Membrul privat pentru stocarea numelui firmei)
public:
    // Constructor implicit - initializează firma cu "Obayashi"
    PlanDeLucru() {
        this->firma = new char[strlen("Obayashi") + 1];
        strcpy_s(this->firma, strlen("Obayashi") + 1, "Obayashi");
    }
    // Constructor cu parametri - initializează firma cu valoarea furnizată
    PlanDeLucru(char* firma) {
        this->firma = new char[strlen(firma) + 1];
        strcpy_s(this->firma, strlen(firma) + 1, firma);
    }
    // Constructor de copiere - creează o copie a obiectului furnizat
    PlanDeLucru(const PlanDeLucru& c) {
        this->firma = new char[strlen(c.firma) + 1];
        strcpy_s(this->firma, strlen(c.firma) + 1, c.firma);
    }
    // Metodă pentru a obține valoarea membrului firma
    const char* getFirma() const {
        return firma;
    }
    // Destructor virtual - este marcat cu "virtual" pentru a permite polimorfismul
    virtual ~PlanDeLucru() {
        cout << "Apel destructor PlanDeLucru" << endl;
        if (this->firma != NULL) {
            delete[]this->firma;
        }
    }
    // Metodă virtuală pură pentru afișarea detaliilor planului de lucru
    virtual void afisareDetalii() = 0;
};
//Derivează din clasa PlanDeLucru și adaugă informații specifice unui șantier, cum ar fi costul, anul începerii, suprafața, zonă, nume de utilaj
class SANTIER : public PlanDeLucru {
private:
    static int cost; // Membru static pentru cost, comun pentru toate instanțele clasei
    const int anulInceperii; // Membru constant pentru anul de începere
    float suprafata; // Suprafața șantierului
    string zona; // Zona în care se află șantierul
    char* numeUtilaj; // Numele utilajului principal
    PlanDeLucru* plan; // Un plan asociat șantierului
public:
    // Metodă pentru afișarea detaliilor șantierului
    void afisareDetalii() {
        cout << "Santier inceput in anul: " << this->getAnulInceperii() << " cu suprafata de " << this->getSuprafata() << " in zona " << this->getZona() << " cu utilajul principal de lucru " << this->getNumeUtilaj();
    }
    // Constructor implicit
    SANTIER() : PlanDeLucru(), plan(NULL), anulInceperii(2010) {
        this->suprafata = 799.5;
        this->zona = "Brasov";
        this->numeUtilaj = new char[strlen("Buldozer") + 1];
        strcpy_s(this->numeUtilaj, strlen("Buldozer") + 1, "Buldozer");
    }
    // Constructor cu parametri
    SANTIER(int anulInceperii, float suprafata, string zona, char* numeUtilaj, char* firma) : PlanDeLucru(firma), plan(NULL), anulInceperii(anulInceperii), suprafata(suprafata), zona(zona) {
        this->numeUtilaj = new char[strlen(numeUtilaj) + 1];
        strcpy_s(this->numeUtilaj, strlen(numeUtilaj) + 1, numeUtilaj);
    }
    // Alt constructor cu parametri
    SANTIER(int anulInceperii, float suprafata, char* firma) : PlanDeLucru(firma), plan(NULL), anulInceperii(anulInceperii), suprafata(suprafata) {
        this->zona = "Targoviste";
        this->numeUtilaj = new char[strlen("Tractor") + 1];
        strcpy_s(this->numeUtilaj, strlen("Tractor") + 1, "Tractor");
    }
    // Constructor de copiere
    SANTIER(const SANTIER& s) : anulInceperii(s.anulInceperii), suprafata(s.suprafata), zona(s.zona), plan(NULL) {
        this->numeUtilaj = new char[strlen(s.numeUtilaj) + 1];
        strcpy_s(this->numeUtilaj, strlen(s.numeUtilaj) + 1, s.numeUtilaj);
    }
    // Metodă pentru obținerea planului de lucru asociat șantierului
    PlanDeLucru* getPlan() const {
        return plan;
    }
    // Metodă pentru obținerea anului de începere
    int getAnulInceperii() const { return anulInceperii; }
    // Metodă pentru obținerea suprafeței
    float getSuprafata() const { return suprafata; }
    // Metodă pentru obținerea zonei
    string getZona() const { return zona; }
    // Metodă pentru obținerea numelui utilajului
    char* getNumeUtilaj() const { return numeUtilaj; }
    // Metodă pentru setarea planului de lucru
    void setPlan(PlanDeLucru* p) {
        plan = p;
    }
    // Metodă pentru setarea suprafeței
    void setSuprafata(float suprafata) { this->suprafata = suprafata; }
    // Metodă pentru setarea zonei
    void setZona(const string& zona) { this->zona = zona; }
    // Metodă pentru setarea numelui utilajului
    void setNumeUtilaj(const char* numeUtilaj) {
        if (this->numeUtilaj) delete[] this->numeUtilaj;
        this->numeUtilaj = new char[strlen(numeUtilaj) + 1];
        strcpy_s(this->numeUtilaj, strlen(numeUtilaj) + 1, numeUtilaj);
    }
    // Suprascrierea operatorului de ieșire pentru afișarea șantierului
    friend ostream& operator<<(ostream& os, const SANTIER& santier);
    // Suprascrierea operatorului de intrare pentru citirea șantierului dintr-un fișier
    friend istream& operator>>(istream& fisier, SANTIER& santier) {
        int a, b;
        cout << "Costul: ";
        fisier >> a;
        cout << "Anul inceperii: ";
        fisier >> b;
        cout << "Suprafata: ";
        fisier >> santier.suprafata;
        cout << "Zona: ";
        fisier >> santier.zona;
        if (santier.numeUtilaj != NULL) {
            delete[]santier.numeUtilaj;
        }
        santier.numeUtilaj = new char[100];
        cout << "Numele utilajului: ";
        fisier >> santier.numeUtilaj;

        return fisier;
    }
    // Destructor pentru eliberareabmemoriei
    ~SANTIER() {
        if (numeUtilaj != NULL) {
            delete[] numeUtilaj;
        }
    }
    // Metodă statică pentru schimbarea costului
    static void schimbareCost(int costNou) {
        cost = costNou;
    }
    // Suprascrierea operatorului de atribuire (=)
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

    // Suprascrierea operatorului de egalitate (==)
    bool operator==(const SANTIER& s) const {
        return (anulInceperii == s.anulInceperii && suprafata == s.suprafata && zona == s.zona && strcmp(numeUtilaj, s.numeUtilaj) == 0);
    }

    // Suprascrierea operatorului de inegalitate (!=)
    bool operator!=(const SANTIER& s) const {
        return !(*this == s);
    }

    // Suprascrierea operatorului de adunare (+)
    SANTIER operator+(const SANTIER& s) const {
        SANTIER sumaSantier = *this;
        sumaSantier.suprafata += s.suprafata;
        return sumaSantier;
    }

    // Metodă pentru scrierea într-un fișier binar
    void scrieInFisierBinar(fstream& f) const {
        f.write(reinterpret_cast<const char*>(&cost), sizeof(int));
        f.write(reinterpret_cast<const char*>(&anulInceperii), sizeof(int));

        int zonaSize = zona.size();
        f.write(reinterpret_cast<const char*>(&zonaSize), sizeof(int));
        f.write(zona.c_str(), zonaSize);

        int numeUtilajSize = strlen(numeUtilaj) + 1;
        f.write(reinterpret_cast<const char*>(&numeUtilajSize), sizeof(int));
        f.write(numeUtilaj, numeUtilajSize);
    }

};

int SANTIER::cost = 100000;
//Derivează din clasa Colectiv și adaugă informații specifice muncitorilor, cum ar fi profesia, salariul de început, numărul de angajați și varstele acestora.
class Muncitori : public Colectiv {
private:
    const string profesie; // Membru constant pentru profesie
    static float salariuInceput; // Membru static pentru salariul de început
    int nrAngajati; // Numărul de angajați
    int* varste; // Un vector de vârste ale angajaților
    Colectiv* colectiv; // Un colectiv asociat muncitorilor

public:
    // Metodă pentru calcularea salariului total
    void calculeazaSalariulTotal() {
        cout << salariuInceput * nrAngajati;
    }
    // Constructor implicit
    Muncitori() :Colectiv(), colectiv(NULL), profesie("Electricieni") {
        this->nrAngajati = 0;
        this->varste = NULL;
        
    }
    // Constructor cu parametri
    Muncitori(string profesie, int nrAngajati, int* varste, char* nationalitate) : Colectiv(nationalitate), profesie(profesie), colectiv(NULL) {
        this->nrAngajati = nrAngajati;
        this->varste = new int[nrAngajati];
        for (int i = 0; i < nrAngajati; i++) {
            this->varste[i] = varste[i];
        }
    }
    // Constructor cu parametri suplimentari
    Muncitori(string profesie, char* nationalitate) : Colectiv(nationalitate), profesie(profesie), nrAngajati(nrAngajati), colectiv(NULL) {
        this->varste = new int[this->nrAngajati];
        for (int i = 0; i < this->nrAngajati; i++)
        {
            this->varste[i] = varste[i];
        }
    }
    // Constructor de copiere
    Muncitori(const Muncitori& m) : profesie(m.profesie), nrAngajati(m.nrAngajati), colectiv(NULL) {
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
    // Metodă pentru obținerea colectivului asociat
    Colectiv* getColectiv() const {
        return colectiv;
    }
    // Metodă pentru obținerea profesiei
    string getProfesie() const { return profesie; }
    // Metodă pentru obținerea salariului de început
    float getSalariuInceput() const { return salariuInceput; }
    // Metodă pentru obținerea numărului de angajați
    int getNrAngajati() const { return nrAngajati; }
    // Metodă pentru obținerea vârstelor angajaților
    int* getVarste() const { return varste; }
    // Metodă pentru setarea colectivului asociat
    void setColectiv(Colectiv* c) {
        colectiv = c;
    }
    // Metodă pentru setarea numărului de angajați
    void setNrAngajati(int nrAngajati) { this->nrAngajati = nrAngajati; }
    // Metodă pentru setarea vârstelor angajaților
    void setVarste(const int* varste) {
        if (this->varste) delete[] this->varste;
        this->varste = new int[nrAngajati];
        for (int i = 0; i < nrAngajati; i++) {
            this->varste[i] = varste[i];
        }
    }
    // Suprascrierea operatorului de ieșire pentru afișarea obiectului
    friend ostream& operator<<(ostream& os, const Muncitori& muncitori);
    // Suprascrierea operatorului de intrare pentru citirea obiectului din fișier
    friend istream& operator>>(istream& fisier, Muncitori& muncitori) {
        string a;
        cout << "Profesie: ";
        fisier >> a;
        cout << "Numarul de angajati: ";
        fisier >> muncitori.nrAngajati;
        if (muncitori.varste != NULL) {
            delete[]muncitori.varste;
        }
        if (muncitori.nrAngajati > 0) {
            muncitori.varste = new int[muncitori.nrAngajati];
            cout << "Varstele angajatilor: ";
            for (int i = 0; i < muncitori.nrAngajati; i++) {
                fisier >> muncitori.varste[i];
            }
        }
        return fisier;
    }
    // Destructor pentru eliberarea resurselor (memorie)
    ~Muncitori() {
        if (varste != NULL)
            delete[] varste;
    }
    // Metodă statică pentru mărirea salariului de început
    static void marireSalariuInceput(float marire) {
        salariuInceput += marire;
    }

    // Suprascrierea operatorului de atribuire (=)
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

    // Suprascrierea operatorului de egalitate (==)
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

    // Suprascrierea operatorului de inegalitate (!=)
    bool operator!=(const Muncitori& m) const {
        return !(*this == m);
    }

    // Operator pentru obținerea vârstei angajatului cu un anumit index
    int operator[](int index) {
        if (index >= 0 && index < nrAngajati) {
            return varste[index];
        }
        return -1;
    }
    // Funcție prietenă pentru afișarea muncitorilor sub o anumită vârstă
    friend void AfiseazaMuncitoriSubVarsta(Muncitori& muncitori, int limitaVarsta);
    // Metodă pentru scrierea într-un fișier binar
    void scrieInFisierBinar(fstream& f) const {
        int profesieSize = profesie.size();
        f.write(reinterpret_cast<const char*>(&profesieSize), sizeof(int));
        f.write(profesie.c_str(), profesieSize);

        f.write(reinterpret_cast<const char*>(&nrAngajati), sizeof(int));
        f.write(reinterpret_cast<const char*>(varste), sizeof(int) * nrAngajati);
    }
};

float Muncitori::salariuInceput = 3000; // Inițializarea membrului static `salariuInceput`
//Reprezintă informații despre utilaje, cum ar fi tipul de combustibil, numărul, numele și mărcile.
class Utilaje {
private:
    const string tipCombustibil; // Membru constant pentru tipul de combustibil
    static int anMinimFabricatie; // Membru static pentru anul minim de fabricație
    int nrUtilaje; // Numărul de utilaje
    string nume; // Numele utilajului
    string* marca; // Un vector de mărci ale utilajului

public:
    // Constructor implicit
    Utilaje() : tipCombustibil("Motorina") {
        this->nrUtilaje = 2;
        this->nume = "Buldozer";
        this->marca = new string[this->nrUtilaje];
        this->marca[0] = "CAT";
        this->marca[1] = "Komatsu";
    }
    // Constructor cu parametri
    Utilaje(string tipCombustibil, int nrUtilaje, string nume, string* marca) : tipCombustibil(tipCombustibil), nrUtilaje(nrUtilaje), nume(nume) {
        this->marca = new string[nrUtilaje];
        for (int i = 0; i < nrUtilaje; i++) {
            this->marca[i] = marca[i];
        }
    }
    // Constructor suplimentar
    Utilaje(string nume) : tipCombustibil("Benzina"), nrUtilaje(0) {
        this->marca = NULL;
    }
    // Constructor de copiere
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
    // Metodă pentru obținerea tipului de combustibil
    string getTipCombustibil() const { return tipCombustibil; }
    // Metodă pentru obținerea anului minim de fabricație
    int getAnMinimFabricatie() const { return anMinimFabricatie; }
    // Metodă pentru obținerea numărului de utilaje
    int getNrUtilaje() const { return nrUtilaje; }
    // Metodă pentru obținerea numelui utilajului
    string getNume() const { return nume; }
    // Metodă pentru obținerea vectorului de mărci ale utilajului
    string* getMarca() const { return marca; }
    // Metodă pentru setarea numărului de utilaje
    void setNrUtilaje(int nrUtilaje) { this->nrUtilaje = nrUtilaje; }
    // Metodă pentru setarea numelui utilajului
    void setNume(const string& nume) { this->nume = nume; }
    // Metodă pentru setarea mărcilor de utilaje
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
    // Suprascrierea operatorului de ieșire pentru afișarea obiectului
    friend ostream& operator<<(ostream& os, const Utilaje& utilaje);
    // Suprascrierea operatorului de intrare pentru citirea obiectului din fișier
    friend istream& operator>>(istream& fisier, Utilaje& utilaje) {
        string a;
        string b;
        cout << "Tipul Combustibilului: ";
        fisier >> a;
        cout << "Numarul de utilaje: ";
        fisier >> utilaje.nrUtilaje;
        cout << "Numele utilajului: ";
        fisier >> b;
        if (utilaje.marca != NULL) {
            delete[]utilaje.marca;
        }
        if (utilaje.nrUtilaje > 0) {
            utilaje.marca = new string[utilaje.nrUtilaje];
            cout << "Marcile utilajelor: ";
            for (int i = 0; i < utilaje.nrUtilaje; i++) {
                fisier >> utilaje.marca[i];
            }
        }


        return fisier;
    }
    // Destructor pentru eliberarea resurselor (memorie)
    ~Utilaje() {
        if (marca != NULL) {
            delete[] marca;
        }
    }
    // Metodă statică pentru obținerea anului minim de fabricație
    static int returnareAn() {
        return anMinimFabricatie;
    }

    // Suprascrierea operatorului de atribuire (=)
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

    // Suprascrierea operatorului de egalitate (==)
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

    // Suprascrierea operatorului de inegalitate (!=)
    bool operator!=(const Utilaje& u) const {
        return !(*this == u);
    }

    // Suprascrierea operatorului de adunare (+)
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
    // Funcție prietenă pentru adăugarea unei mărci noi de utilaj
    friend void AdaugaMarcaUtilaj(Utilaje& utilaje, const string& marcaNoua);
    // Metodă pentru scrierea într-un fișier binar
    void scrieInFisierBinar(fstream& f) const {
        int tipCombustibilSize = tipCombustibil.size();
        f.write(reinterpret_cast<const char*>(&tipCombustibilSize), sizeof(int));
        f.write(tipCombustibil.c_str(), tipCombustibilSize);

        f.write(reinterpret_cast<const char*>(&anMinimFabricatie), sizeof(int));
        f.write(reinterpret_cast<const char*>(&nrUtilaje), sizeof(int));

        int numeSize = nume.size();
        f.write(reinterpret_cast<const char*>(&numeSize), sizeof(int));
        f.write(nume.c_str(), numeSize);

        for (int i = 0; i < nrUtilaje; ++i) {
            int marcaSize = marca[i].size();
            f.write(reinterpret_cast<const char*>(&marcaSize), sizeof(int));
            f.write(marca[i].c_str(), marcaSize);
        }
    }
};
// Inițializarea membrului static `anMinimFabricatie`
int Utilaje::anMinimFabricatie = 2003;


// Functie pentru afisarea muncitorilor cu varsta sub o anumita limita
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

// Functie pentru adaugarea unei noi marci la lista de marci a utilajului
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
// Suprascrierea operatorului de iesire pentru clasa SANTIER
ostream& operator<<(ostream& os, const SANTIER& santier) {
    os << santier.cost << " ";
    os << santier.anulInceperii << " ";
    os << santier.getSuprafata() << " ";
    os << santier.getZona() << " ";
    os << santier.getNumeUtilaj() << " ";
    os << santier.getFirma() << " ";
    return os;
}
// Suprascrierea operatorului de iesire pentru clasa Muncitori
ostream& operator<<(ostream& os, const Muncitori& muncitori) {
    os << muncitori.getProfesie() << " ";
    os << muncitori.getNrAngajati() << " ";
    int* varste = muncitori.getVarste();
    for (int i = 0; i < muncitori.getNrAngajati(); ++i) {
        os << varste[i] << " ";
    }
    os << muncitori.getNationalitate() << " ";
    return os;
}
// Suprascrierea operatorului de iesire pentru clasa Utilaje
ostream& operator<<(ostream& os, const Utilaje& utilaje) {
    os << utilaje.getTipCombustibil() << " ";
    os << utilaje.getNrUtilaje() << " ";
    os << utilaje.getNume() << " ";
    string* marci = utilaje.getMarca();
    for (int i = 0; i < utilaje.getNrUtilaje(); ++i) {
        os << marci[i] << " ";
    }
    return os;
}
//Reprezintă un echipament cu informații precum anul de fabricație, utilajul asociat, costul de achiziție și starea funcțională.
class Echipament {
private:
    int anFabricatie; // Anul de fabricație al echipamentului
    Utilaje* utilaj; // Pointer către un obiect de tip Utilaje asociat echipamentului
    float costAchizitie; // Costul de achiziție al echipamentului
    bool functional; // Indicatorul de funcționalitate al echipamentului

public:
    // Constructorul implicit inițializează anul de fabricație, costul de achiziție,
    // și funcționalitatea echipamentului cu valori implicite, iar utilajul cu un obiect Utilaje implicit.
    Echipament() : anFabricatie(2020), costAchizitie(50000.0), functional(true), utilaj(new Utilaje()) {

    }
    // Constructorul cu parametri permite inițializarea echipamentului cu valori specificate.
    // Se utilizează o listă de inițializare pentru a asigna valorile parametrilor membrilor.
    Echipament(int anFabricatie, const Utilaje& utilaj, float costAchizitie, bool functional) : anFabricatie(anFabricatie), costAchizitie(costAchizitie), functional(functional), utilaj(new Utilaje(utilaj)) {

    }
    // Getter pentru anul de fabricație
    int getAnFabricatie() const { return anFabricatie; }
    // Getter pentru obiectul Utilaje asociat echipamentului
    Utilaje* getUtilaj() const { return utilaj; }
    // Getter pentru costul de achiziție
    float getCostAchizitie() const { return costAchizitie; }
    // Getter pentru indicatorul de funcționalitate
    bool isFunctional() const { return functional; }
    // Setter pentru anul de fabricație
    void setAnFabricatie(int anFabricatie) { this->anFabricatie = anFabricatie; }
    // Setter pentru obiectul Utilaje asociat echipamentului
    void setUtilaj(const Utilaje& utilaj) { *(this->utilaj) = utilaj; }
    // Setter pentru costul de achiziție
    void setCostAchizitie(float costAchizitie) { this->costAchizitie = costAchizitie; }
    // Setter pentru indicatorul de funcționalitate
    void setFunctional(bool functional) { this->functional = functional; }

    // Suprascrierea operatorului de afișare pentru clasa Echipament
    friend ostream& operator<<(ostream& os, const Echipament& echipament);
    // Suprascrierea operatorului de atribuire pentru clasa Echipament
    Echipament& operator=(const Echipament& echipament);
    // Suprascrierea operatorului de egalitate pentru clasa Echipament
    bool operator==(const Echipament& echipament) const;
    // Suprascrierea operatorului de citire din fisier pentru clasa Echipament
    friend istream& operator>>(istream& fisier, Echipament& echipament) {
        fisier >> echipament.anFabricatie;

        fisier >> *(echipament.utilaj);

        fisier >> echipament.costAchizitie;

        fisier >> echipament.functional;

        return fisier;
    }
    // Destructorul eliberează memoria alocată pentru obiectul de tip Utilaje
    ~Echipament() {
        delete utilaj;
    }
    // Metodă pentru scrierea informațiilor despre echipament într-un fișier binar
    void scrieInFisierBinar(fstream& f) const {
        f.write(reinterpret_cast<const char*>(&anFabricatie), sizeof(int));
        utilaj->scrieInFisierBinar(f);
        f.write(reinterpret_cast<const char*>(&costAchizitie), sizeof(float));
        f.write(reinterpret_cast<const char*>(&functional), sizeof(bool));
    }

};
//Derivează din clasa SANTIER și adaugă informații specifice unui proiect, precum tipul de proiect.
class Proiect : public SANTIER { //un santier desfasoara un proiect
private:
    string tipProiect; // Tipul de proiect asociat santierului

public:
    // Constructorul implicit inițializează membrul tipProiect cu o valoare implicită și apelează constructorul implicit al clasei de bază SANTIER.
    Proiect() : SANTIER(), tipProiect("Constructie cladirii") {}
    // Constructorul cu parametri permite inițializarea membrilor clasei Proiect și clasei de bază SANTIER.
    Proiect(int anulInceperii, float suprafata, string zona, char* numeUtilaj, char* firma, string tipProiect)
        : SANTIER(anulInceperii, suprafata, zona, numeUtilaj, firma), tipProiect(tipProiect) {}
    // Constructorul de copiere utilizează constructorul de copiere al clasei de bază SANTIER și adaugă inițializarea membrului tipProiect.
    Proiect(const Proiect& p) : SANTIER(p), tipProiect(p.tipProiect) {}
    // Constructorul de conversie construiește un obiect de tip Proiect dintr-un obiect de tip SANTIER.
    Proiect(const SANTIER& s) :SANTIER(s) {
        this->tipProiect = "Constructie teren";
    }
    // Getter pentru tipul de proiect
    string getTipProiect() const { return tipProiect; }
    // Setter pentru tipul de proiect
    void setTipProiect(const string& tipProiect) { this->tipProiect = tipProiect; }
    // Suprascrierea operatorului de afișare pentru clasa Proiect
    friend ostream& operator<<(ostream& os, const Proiect& proiect);
    // Destructorul (este implicit, deoarece nu există resurse gestionate manual)
    ~Proiect() {}
};
// Suprascrierea operatorului de afișare pentru clasa Proiect
ostream& operator<<(ostream& os, const Proiect& proiect) {
    os << static_cast<const SANTIER&>(proiect) << " " << proiect.tipProiect << " ";
    return os;
}
//Derivează din clasa Muncitori și adaugă informații specifice angajaților, cum ar fi numele angajatului.
class Angajat : public Muncitori {
private:
    string numeAngajat; // Numele angajatului

public:
    // Constructorul implicit inițializează membrul numeAngajat cu o valoare implicită și apelează constructorul implicit al clasei de bază Muncitori.
    Angajat() : Muncitori(), numeAngajat("Alex Popescu") {}
    // Constructorul cu parametri permite inițializarea membrilor clasei Angajat și clasei de bază Muncitori.
    Angajat(string profesie, int nrAngajati, int* varste, char* nationalitate, string numeAngajat)
        : Muncitori(profesie, nrAngajati, varste, nationalitate), numeAngajat(numeAngajat) {}
    // Constructorul de copiere utilizează constructorul de copiere al clasei de bază Muncitori și adaugă inițializarea membrului numeAngajat.
    Angajat(const Angajat& a) : Muncitori(a), numeAngajat(a.numeAngajat) {}
    // Getter pentru numele angajatului
    string getNumeAngajat() const { return numeAngajat; }
    // Setter pentru numele angajatului
    void setNumeAngajat(const string& numeAngajat) { this->numeAngajat = numeAngajat; }
    // Suprascrierea operatorului de afișare pentru clasa Angajat
    friend ostream& operator<<(ostream& os, const Angajat& angajat);
    // Destructorul (este implicit, deoarece nu există resurse gestionate manual)
    ~Angajat() {}
};
// Suprascrierea operatorului de afișare pentru clasa Angajat
ostream& operator<<(ostream& os, const Angajat& angajat) {
    os << static_cast<const Muncitori&>(angajat) <<" "<<angajat.numeAngajat << " ";
    return os;
}
// Suprascrierea operatorului de afișare pentru clasa Echipament
ostream& operator<<(ostream& os, const Echipament& echipament) {
    os << echipament.getAnFabricatie() << " ";
    os << *(echipament.getUtilaj());
    os << echipament.getCostAchizitie() << " ";
    os << (echipament.isFunctional() ? "Da" : "Nu") << " ";
    return os;
}
// Suprascrierea operatorului de atribuire pentru clasa Echipament
Echipament& Echipament::operator=(const Echipament& echipament) {
    if (this == &echipament) {
        return *this;
    }

    anFabricatie = echipament.anFabricatie;
    *(utilaj) = *(echipament.utilaj);
    costAchizitie = echipament.costAchizitie;
    functional = echipament.functional;

    return *this;
}
// Suprascrierea operatorului de egalitate pentru clasa Echipament
bool Echipament::operator==(const Echipament& echipament) const {
    return (anFabricatie == echipament.anFabricatie &&
        *(utilaj) == *(echipament.utilaj) &&
        costAchizitie == echipament.costAchizitie &&
        functional == echipament.functional);
}

void main() {
    //Codul exemplifică crearea, inițializarea și afișarea informațiilor despre 
    //obiecte de tip SANTIER.Se folosesc constructorii, metodele și operatorii clasei.

    /*SANTIER santier1;
    char* numeUtilaj = new char[strlen("Excavator") + 1];
    strcpy_s(numeUtilaj, strlen("Excavator") + 1, "Excavator");
    char* firma = new char[strlen("Aktor") + 1];
    strcpy_s(firma, strlen("Aktor") + 1, "Aktor");
    SANTIER santier2(2015, 1200, "Constanta", numeUtilaj,firma);
    SANTIER santier3(2018, 900,firma);
    SANTIER santier4 = santier1;*/

    /*cout << "Anul Inceperii santier1: " << santier1.getAnulInceperii() << endl;
    cout << "Suprafata santier2: " << santier2.getSuprafata() << endl;
    cout << "Zona santier3: " << santier3.getZona() << endl;
    cout << "Nume Utilaj santier4: " << santier4.getNumeUtilaj() << endl;*/

    //se afișează informațiile actualizate pentru fiecare santier

    /*santier1.setSuprafata(1000);
    santier2.setZona("Bucuresti");
    santier3.setNumeUtilaj("Macara");

    cout << "Santier 1:\n" << santier1 << endl;
    cout << "Santier 2:\n" << santier2 << endl;
    cout << "Santier 3:\n" << santier3 << endl;*/

    //se calculează suma suprafețelor celor două șantiere și se afișează rezultatul

    /*SANTIER santierSuma = santier1 + santier2;
    cout << "Suma Suprafetelor: " << santierSuma.getSuprafata() << endl;*/

    //Codul creează trei obiecte de tipul Muncitori și le inițializează 
    //cu diferite informații despre muncitori (varste, profesie, și nationalitate). Apoi, afișează detaliile despre fiecare obiect Muncitori.

    /*int* varsteMuncitori = new int[3];
    varsteMuncitori[0] = 28;
    varsteMuncitori[1] = 35;
    varsteMuncitori[2] = 42;
    char* nationalitate = new char[strlen("Germana") + 1];
    strcpy_s(nationalitate, strlen("Germana") + 1, "Germana");
    Muncitori muncitori1;
    Muncitori muncitori2("Constructori", 4, varsteMuncitori,nationalitate);
    Muncitori muncitori3("Sudori",nationalitate);

    cout << "Muncitori 1:\n" << muncitori1 << endl;
    cout << "Muncitori 2:\n" << muncitori2 << endl;
    cout << "Muncitori 3:\n" << muncitori3 << endl;*/

    //Codul atribuie valorile obiectului `muncitori2` obiectului `muncitori3` și afișează numărul de angajați al obiectului `muncitori3`.

   /* muncitori3 = muncitori2;
    cout << "Nr. Angajati Muncitori 3: " << muncitori3.getNrAngajati() << endl;*/

    //Codul creează trei obiecte Utilaje cu diferite atribute și afișează informațiile despre acestea

    /*string* marciUtilaje = new string[2];
    marciUtilaje[0] = "Liebherr";
    marciUtilaje[1] = "Volvo";
    Utilaje utilaje1;
    Utilaje utilaje2("Motorina", 2, "Buldozer", marciUtilaje);
    Utilaje utilaje3("Excavator");

    cout << "Utilaje 1:\n" << utilaje1 << endl;
    cout << "Utilaje 2:\n" << utilaje2 << endl;
    cout << "Utilaje 3:\n" << utilaje3 << endl;*/

    //Adaugă marca "Caterpillar" la lista de mărci a obiectului utilaje1 și afișează informațiile actualizate despre acesta.

    /*AdaugaMarcaUtilaj(utilaje1, "Caterpillar");
    cout << "Utilaje 1 dupa adaugare marca:\n" << utilaje1 << endl;*/

    //Codul citeste datele pentru doua obiecte SANTIER, Muncitori si Utilaje, le afiseaza 
    //si apoi face acelasi lucru pentru un vector de doua obiecte de fiecare tip.

    /*SANTIER* vectorSantier = new SANTIER[2];
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
    }*/

    //Codul definește o matrice bidimensională de obiecte de tip SANTIER, 
    //citeste datele pentru fiecare obiect  și apoi afișează obiectele citite din matrice.

    /*const int numarSantiere = 2;
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
    }*/

   //Se creează două obiecte de tip Echipament, echipament1 și echipament2, cu date inițiale. Se afișează informații despre acestea, 
   // apoi se atribuie valorile obiectului echipament2 obiectului echipament1. 
   // Se verifică dacă cele două obiecte sunt identice și se afișează un mesaj corespunzător.

    /*Utilaje utilaje4("Motorina", 1, "Buldozer", new string[1]{ "CAT" });

    Echipament echipament1;
    Echipament echipament2(2018, utilaje4, 75000.0, true);

    cout << "ECHIPAMENT 1:\n" << echipament1 << "\n";
    cout << "ECHIPAMENT 2:\n" << echipament2 << "\n";

    echipament1 = echipament2;
    cout << "Dupa atribuire, ECHIPAMENT 1:\n" << echipament1 << "\n";

    if (echipament1 == echipament2) {
        cout << "ECHIPAMENT 1 si ECHIPAMENT 2 sunt identice.\n";
    }
    else {
        cout << "ECHIPAMENT 1 si ECHIPAMENT 2 nu sunt identice.\n";
    }*/

    //codul scrie informații despre un obiect SANTIER într-un fișier și apoi citește aceste informații din fișier pentru a le afișa pe consolă

    /*SANTIER santier1;
    ofstream a("SANTIER.txt", ios::app);
    a << santier1;
    a.close();
    ifstream b("SANTIER.txt", ios::in);
    b >> santier1;
    cout << santier1;*/

    //codul scrie informații despre un obiect Muncitori într-un fișier și apoi citește aceste informații din fișier pentru a le afișa pe consolă

    /*Muncitori muncitori1;
    ofstream c("Muncitori.txt", ios::app);
    c << muncitori1;
    c.close();
    ifstream d("Muncitori.txt", ios::in);
    d >> muncitori1;
    cout << muncitori1 << endl;*/

    //codul scrie informații despre un obiect Utilaje într-un fișier și apoi citește aceste informații din fișier pentru a le afișa pe consolă

    /*Utilaje utilaje1;
    ofstream g("Utilaje.txt", ios::app);
    g << utilaje1;
    g.close();
    ifstream f("Utilaje.txt", ios::in);
    f >> utilaje1;
    cout << utilaje1 << endl;*/

    //codul scrie informații despre un obiect Echipament într-un fișier și apoi citește aceste informații din fișier pentru a le afișa pe consolă

   /* Utilaje utilaje2;
    Echipament echipament1(2018, utilaje2, 75000.0, true);
    ofstream g("Echipament.txt", ios::app);
    g << echipament1;
    g.close();
    ifstream f("Echipament.txt", ios::in);
    f >> echipament1;
    cout << echipament1 << endl;*/

  //codul salvează datele obiectelor de tip SANTIER, Muncitori, Utilaje și Echipament într-un fișier binar numit "output.bin"

        /*SANTIER santier1;
        Muncitori muncitori1;
        Utilaje utilaje1;
        Echipament echipament1;

        fstream binaryFile("output.bin", ios::out | ios::binary);

        if (binaryFile.is_open()) {
            santier1.scrieInFisierBinar(binaryFile);
            muncitori1.scrieInFisierBinar(binaryFile);
            utilaje1.scrieInFisierBinar(binaryFile);
            echipament1.scrieInFisierBinar(binaryFile);
        }*/

      //codul demonstrează crearea și afișarea unor obiecte de tip Proiect și Angajat, precum și utilizarea constructorilor acestor clase.

        /*SANTIER s;

        Proiect proiect1;
        Proiect proiect2(s);

        int varste[] = { 25, 30, 28 };
        char* nationalitate = new char[strlen("Franceza") + 1];
        strcpy_s(nationalitate, strlen("Franceza") + 1, "Franceza");
        Angajat angajat1;
        Angajat angajat2("Constructor", 3, varste,nationalitate, "Ion Ionescu");

        cout << "Proiect 1: " << proiect1 << endl;
        cout << "Proiect 2: " << proiect2 << endl;

        cout << "Angajat 1: " << angajat1 << endl;
        cout << "Angajat 2: " << angajat2 << endl;*/

        // codul creează două obiecte polimorfice și apelează metode virtuale asupra lor folosind pointeri la clase de bază

        /*Colectiv* c = new Muncitori();
        c->calculeazaSalariulTotal();
        
        PlanDeLucru* j = new SANTIER();
        j->afisareDetalii();*/

        //Se creează un vector de pointeri la `Colectiv`, care sunt apoi inițializați alternativ cu obiecte de tip `Muncitori`. 
        //Pentru fiecare obiect, se calculează salariul total și apoi se eliberează memoria alocată.

        /*const int numarElemente = 10;
        Colectiv* vectorColectiv[numarElemente];
        
        char* nationalitate = new char[strlen("Turca") + 1];
        strcpy_s(nationalitate, strlen("Turca") + 1, "Turca");
        int* varste = new int[3];
        varste[0] = 23;
        varste[1] = 41;
        varste[2] = 29;
        
        for (int i = 0; i < numarElemente; i+=2) {
            vectorColectiv[i] = new Muncitori();
            vectorColectiv[i + 1] = new Muncitori("Constructori", 3, varste, nationalitate);
        }
        
        
        for (int i = 0; i < numarElemente; i++) {
            vectorColectiv[i]->calculeazaSalariulTotal();  
            cout << endl;
        }
        
        for (int i = 0; i < numarElemente; i++) {
            delete vectorColectiv[i];
        }
        
        delete[] nationalitate;
        delete[] varste;*/

    //Se creează un vector de pointeri la PlanDeLucru care conține obiecte SANTIER și se afișează detalii pentru fiecare obiect,
    //apoi se eliberează memoria alocată

    /*const int numarElemente = 10;
    PlanDeLucru* vectorPlan[numarElemente];

    char* numeUtilaj = new char[strlen("Buldozer") + 1];
    strcpy_s(numeUtilaj, strlen("Buldozer") + 1, "Turca");
    char* firma = new char[strlen("Construct SRL") + 1];
    strcpy_s(firma, strlen("Construct SRL") + 1, "Construct SRL");

    for (int i = 0; i < numarElemente; i += 2) {
        vectorPlan[i] = new SANTIER();
        vectorPlan[i + 1] = new SANTIER(2020, 930, "Pitesti", numeUtilaj, firma);
    }


    for (int i = 0; i < numarElemente; i++) {
        vectorPlan[i]->afisareDetalii();
        cout << endl;
    }

    for (int i = 0; i < numarElemente; i++) {
        delete vectorPlan[i];
    }

    delete[] numeUtilaj;
    delete[] firma;*/

}
