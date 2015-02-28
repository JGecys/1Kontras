#include "Studentas.h"
#pragma once
class Fakultetas
{
private:
	string Pavadinimas;
	int Kreditai;
	Studentas* Stud;
	int n;
	Fakultetas & operator = (const Fakultetas & other);
	Fakultetas(const Fakultetas & other);
public:
	Fakultetas(int n = 0);
	~Fakultetas();
	int ImtiN(){ return n; }
	int ImtiKreditus(){ return Kreditai; }
	string ImtiPavadinima(){ return Pavadinimas; }
	Studentas & Imti(int i){ return Stud[i]; }
	void DetiDuomenis(string Pav, int Kred);

	bool operator > (const Fakultetas & other){ return n > other.n; }
	bool operator < (const Fakultetas & other){ return n < other.n; }

	void Spausdinti(ofstream & fr);

	void Surykiuoti();
};

