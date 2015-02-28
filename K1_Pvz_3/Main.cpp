#include "Studentas.h"
#include "Fakultetas.h"

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

const string CDuom = "Duomenys.txt";
const string CDuom2 = "Duomenys2.txt";

int KiekStudentuFaile(const string & CD);
int KiekStudentuVirsijo(Fakultetas & F);

void Nuskaityti(const string & CD, Fakultetas & F);
void PridetiJeiVirsijo(Fakultetas& FakNew, Fakultetas &FakOld);

int main(){
	setlocale(LC_ALL, "Lithuanian");

	//---------------------------------------------------------------------------
	Fakultetas *Fak;
	int n = KiekStudentuFaile(CDuom);
	Fak = new Fakultetas(n);

	Nuskaityti(CDuom, *Fak);

	n = KiekStudentuVirsijo(*Fak);

	Fakultetas *FakNaujas;
	FakNaujas = new Fakultetas(n);
	FakNaujas->DetiDuomenis(Fak->ImtiPavadinima(), Fak->ImtiKreditus());

	PridetiJeiVirsijo(*FakNaujas, *Fak);
	//---------------------------------------------------------------------------
	Fakultetas *Fak2;
	n = KiekStudentuFaile(CDuom2);
	Fak2 = new Fakultetas(n);

	Nuskaityti(CDuom2, *Fak2);

	n = KiekStudentuVirsijo(*Fak2);

	Fakultetas *FakNaujas2;
	FakNaujas2 = new Fakultetas(n);
	FakNaujas2->DetiDuomenis(Fak2->ImtiPavadinima(), Fak2->ImtiKreditus());

	PridetiJeiVirsijo(*FakNaujas2, *Fak2);
	//---------------------------------------------------------------------------

	ofstream fo("Rezultatai.txt");

	Fak->Surykiuoti();
	FakNaujas->Surykiuoti();

	Fak->Spausdinti(fo);
	FakNaujas->Spausdinti(fo);


	Fak2->Surykiuoti();
	FakNaujas2->Surykiuoti();

	Fak2->Spausdinti(fo);
	FakNaujas2->Spausdinti(fo);

	bool kuris = *FakNaujas > *FakNaujas2;

	if (kuris){
		fo << FakNaujas->ImtiPavadinima() << " Turi daugiau studentø virðijanèiø nurodytà kreditø kieká. " << FakNaujas->ImtiN();
	}
	else{
		fo << FakNaujas2->ImtiPavadinima() << " Turi daugiau studentø virðijanèiø nurodytà kreditø kieká. " << FakNaujas2->ImtiN();
	}

	fo.close();


	delete Fak;
	delete FakNaujas;

	delete Fak2;
	delete FakNaujas2;

	return 0;
}

int KiekStudentuFaile(const string & CD){
	int kiek = 0;
	ifstream fi(CD);
	string eil;
	while (!fi.eof()){
		getline(fi, eil);
		kiek++;
	}
	return kiek - 1;
}

void Nuskaityti(const string & CD, Fakultetas & F){
	ifstream fi(CD);
	string pavadinimas; int kreditas;
	getline(fi, pavadinimas, ',');
	fi >> kreditas;

	F.DetiDuomenis(pavadinimas, kreditas);

	fi.ignore(80, '\n');
	string pavarde, vardas, grupe;

	for (int i = 0; i < F.ImtiN(); i++){
		fi >> pavarde >> vardas >> grupe;
		
		Studentas & stud = F.Imti(i);

		stud.DetiDuomenis(vardas, pavarde, grupe);

		while (fi.peek() != '\n' && !fi.eof()){
			int kr;
			fi >> kr;
			stud.PridetiKredita(kr);
		}
	}
	fi.close();
}


int KiekStudentuVirsijo(Fakultetas & F){
	int kiek = 0;
	for (int i = 0; i < F.ImtiN(); i++){
		if (F.Imti(i).ImtiKredituSuma() > F.ImtiKreditus()){
			kiek++;
		}
	}
	return kiek;
}


void PridetiJeiVirsijo(Fakultetas& FakNew, Fakultetas &FakOld){
	int n = 0;
	for (int i = 0; i < FakOld.ImtiN(); i++){
		if (FakOld.Imti(i).ImtiKredituSuma() > FakOld.ImtiKreditus()){
			Studentas & old = FakOld.Imti(i);
			Studentas & naujas = FakNew.Imti(n);
			naujas = old;
			n++;
		}
	}
}