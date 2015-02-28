#include "Studentas.h"

#include <sstream>

void Studentas::DidintiMasyva(int kiek){
	int *Snaujas = new int[kiek];
	for (int i = 0; i < n; i++)
		Snaujas[i] = Kr[i];
	delete[] Kr;
	Kr = Snaujas;
	nMax = kiek;
}

Studentas::Studentas() : Var(""), Pav(""), Gr(""), n(0), nMax(2), Kr(NULL)
{
	Kr = new int[2];
}


Studentas::Studentas(string Vardas, string Pavarde, string Grupe) : Var(Vardas), Pav(Pavarde), Gr(Grupe), n(0), nMax(2), Kr(NULL)
{
	Kr = new int[nMax];
}

Studentas::~Studentas()
{
	n = nMax = 0;
	if (Kr)
		delete[] Kr;
	Kr = NULL;
}


void Studentas::PridetiKredita(int Kreditas){
	if (n == nMax) DidintiMasyva(nMax + 5);
	Kr[n] = Kreditas;
	n++;
}