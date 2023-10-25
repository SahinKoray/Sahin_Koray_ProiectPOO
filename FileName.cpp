#include<iostream>

using namespace std;

class SANTIER {
public:
	static int cost;
	const int anulInceperii;
	float suprafata;
	string zona;
	char* numeUtilaj;

	SANTIER():anulInceperii(2010) {
		this->suprafata = 799.5;
		this->zona = "Brasov";
		this->numeUtilaj = new char[strlen("Buldozer") + 1];
		strcpy_s(this->numeUtilaj, strlen("Buldozer") + 1, "Buldozer");
	}

	SANTIER(int anulInceperii,float suprafata, string zona, char* numeUtilaj) :anulInceperii(anulInceperii),suprafata(suprafata),zona(zona) {

		this->numeUtilaj = new char[strlen(numeUtilaj) + 1];
		strcpy_s(this->numeUtilaj, strlen(numeUtilaj) + 1, numeUtilaj);
	}

	SANTIER(int anulInceperii, float suprafata) :anulInceperii(anulInceperii), suprafata(suprafata) {

		this->zona = "Targoviste";
		this->numeUtilaj = new char[strlen("Tractor") + 1];
		strcpy_s(this->numeUtilaj, strlen("Tractor") + 1, "Tractor");
	}

	void afisare() {
		cout << "Santierul cu un cost de " << cost << " euro,inceput in anul " << anulInceperii << " ,are o suprafata de " << suprafata << " metri patrati, in zona " << zona << " unde utilajul cel mai folosit este "<<numeUtilaj<<".\n";
	}

	~SANTIER() {
		if (this->numeUtilaj != NULL) {
			delete[]this->numeUtilaj;
		}
	}

	static void schimbareCost(int costNou) {
		cost = costNou;
	}
};
int SANTIER::cost = 100000;

class Muncitori {
public:
	const string profesie;
	static float salariuInceput;
	int nrAngajati;
	int* varste;

	Muncitori() :profesie("Inginerii") {
		this->nrAngajati=3;
		this->varste = new int[this->nrAngajati];
		this->varste[0] = 32;
		this->varste[1] = 29;
		this->varste[2] = 46;
	}

	Muncitori(string profesie, int nrAngajati, int* varste) :profesie(profesie), nrAngajati(nrAngajati) {
		this->varste = new int[this->nrAngajati];
		for (int i = 0; i < this->nrAngajati; i++)
		{
			this->varste[i] = varste[i];
		}
	}

	Muncitori(string profesie) :profesie(profesie),nrAngajati(0) {
		this->varste = new int[this->nrAngajati];
		for (int i = 0; i < this->nrAngajati; i++)
		{
			this->varste[i] = varste[i];
		}
	}

	void afisare() {
		cout << profesie << " au un salariu de inceput de " << salariuInceput << ". Ei sunt in numar de " << nrAngajati << " cu varste de ";
		if (nrAngajati != NULL) {
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
		if (this->varste != NULL) {
			delete[]this->varste;

		}
	}
	static void marireSalariuInceput(float marire) {
		salariuInceput += marire;
	}
};
float Muncitori::salariuInceput = 3000;

class Utilaje {
public:
	const string tipCombustibil;
	static int anMinimFabricatie;
	int nrUtilaje;
	string nume;
	string* marca;

	Utilaje() :tipCombustibil("Motorina") {
		this->nrUtilaje = 2;
		this->nume = "Buldozer";
		this->marca = new string[this->nrUtilaje];
		this->marca[0] = "CAT";
		this->marca[1] = "Komatsu";
	}

	Utilaje(string tipCombustibil, int nrUtilaje, string nume, string* marca) :tipCombustibil(tipCombustibil), nrUtilaje(nrUtilaje), nume(nume) {
		this->marca = new string[this->nrUtilaje];
		for (int i = 0; i < this->nrUtilaje; i++)
		{
			this->marca[i] = marca[i];
		}
	}

	Utilaje(string nume) :tipCombustibil("Benzina"), nrUtilaje(0) {
		this->marca = NULL;
	}

	void afisare() {
		cout << "Fiind dat anul minim al utilajelor de " << anMinimFabricatie << " ,utilajul " << nume << " consuma " << tipCombustibil << " ,este in numar de " << nrUtilaje << " avand marcile : ";
		if (nrUtilaje != NULL) {
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
		if (this->marca != NULL) {
			delete[]this->marca;

		}
	}

	static int returnareAn() {
		return anMinimFabricatie;
	}

};
int Utilaje::anMinimFabricatie = 2003;

void main(){
	SANTIER santier1;
    santier1.afisare();
	
	char* numeUtilaj = new char[strlen("Excavator") + 1];
	strcpy_s(numeUtilaj, strlen("Excavator") + 1, "Excavator");
	SANTIER santier2(2015,901.7,"Baia Mare",numeUtilaj);
	SANTIER::schimbareCost(12000);
	santier2.afisare();
	
	SANTIER santier3(2008, 498.6);
	santier3.afisare();

	Muncitori muncitori1;
	muncitori1.afisare();

	int* varste;
	varste = new int[2];
	varste[0] = 50;
	varste[1] = 48;
	Muncitori muncitori2("Manegerii",2,varste);
	muncitori2.afisare();

	Muncitori muncitori3("Asistentele");
	Muncitori::marireSalariuInceput(500);
	muncitori3.afisare();

	Utilaje utilaje1;
	utilaje1.afisare();

	string* marca;
	marca = new string[3];
	marca[0] = "Hitachi";
	marca[1] = "Volvo";
	marca[2] = "Hyundai";
	Utilaje utilaje2("Motorina", 3, "Excavator", marca);
	utilaje2.afisare();

	Utilaje utilaje3("Motocultor");
	utilaje3.afisare();
	cout<<Utilaje::returnareAn();
}