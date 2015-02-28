#pragma once
#include <string>

using namespace std;

class Studentas
{
private:
	string Var, Pav, Gr;
	int *Kr;
	int n, nMax;
	void DidintiMasyva(int kiek);
public:
	Studentas();
	Studentas(string Vardas, string Pavarde, string Grupe);
	~Studentas();
	void PridetiKredita(int Kreditas);
	string ImtiVarda() const { return Var; }
	string ImtiPavarde() const { return Pav; }
	string ImtiVarPav() const { return Var + ' ' + Pav; }
	string ImtiPavVar() const { return Pav + ' ' + Var; }
	string ImtiGrupe() const { return Gr; }
	int Imti(int i){ return Kr[i]; }
	int ImtiN(){ return n; }
	void DetiDuomenis(string Vardas, string Pavarde, string Grupe){
		Var = Vardas; Pav = Pavarde; Gr = Grupe;
	}

	int ImtiKredituSuma() const{
		int suma = 0;
		for (int i = 0; i < n; i++){
			suma += Kr[i];
		}
		return suma;
	}

	Studentas & operator = (const Studentas & other){
		Var = other.Var;
		Pav = other.Pav;
		Gr = other.Gr;
		n = other.n;
		delete[] Kr;
		Kr = new int[n];
		for (int i = 0; i < n; i++){
			Kr[i] = other.Kr[i];
		}
		return *this;
	}
	Studentas(const Studentas & other){
		Var = other.Var;
		Pav = other.Pav;
		Gr = other.Gr;
		n = other.n;
		Kr = new int[n];
		for (int i = 0; i < n; i++){
			Kr[i] = other.Kr[i];
		}
	}

	bool operator > (const Studentas & other){
		return ImtiKredituSuma() > other.ImtiKredituSuma() || ImtiKredituSuma() == other.ImtiKredituSuma() && ImtiVarPav() > other.ImtiVarPav();
	}

	bool operator < (const Studentas & other){
		return ImtiKredituSuma() < other.ImtiKredituSuma() || ImtiKredituSuma() == other.ImtiKredituSuma() && ImtiVarPav() > other.ImtiVarPav();
	}

};

