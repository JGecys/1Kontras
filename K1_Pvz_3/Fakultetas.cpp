#include "Fakultetas.h"
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

Fakultetas::Fakultetas(int n) : n(n), Stud(NULL)
{
	Stud = new Studentas[n];
}


Fakultetas::~Fakultetas()
{
	if (Stud)
		delete[] Stud;
	n = 0;
	Stud = NULL;
}

void Fakultetas::DetiDuomenis(string Pav, int Kred){
	Pavadinimas = Pav; Kreditai = Kred;
}


void Fakultetas::Spausdinti(ofstream & fr){
	fr << left << string(80, '-') << endl;
	fr << "|" << setw(5) << Kreditai << '|' << setw(80 - 3 - 5) << " " + Pavadinimas << "|" << endl;
	fr << string(80, '-') << endl;
	fr << "|" << setw(40) << " Vardas, Pavarde" << "|" << setw(10) << " Grupe" << "|" << setw(80 - 4 - 10 - 40) << " Kreditai" << "|" << endl;
	fr << string(80, '-') << endl;
	for (int i = 0; i < n; i++){
		Studentas & s = Stud[i];
		fr << left << "|" << setw(40) << s.ImtiVarPav() << "|" << setw(10) << s.ImtiGrupe() << "|";
		for (int j = 0; j < s.ImtiN(); j++){
			fr << " " << s.Imti(j);
		}
		fr << setw(80 - 4 - 40 - 10 - (2 * s.ImtiN())) << right << s.ImtiKredituSuma() << "|" << endl;
	}
	fr << string(80, '-') << endl;
	fr << endl << endl;
}


void Fakultetas::Surykiuoti(){
	for (int i = 0; i < n - 1; i++){
		int index = i;
		for (int j = i + 1; j < n; j++){
			if (Stud[index] < Stud[j]){
				index = j;
			}
		}
		if (index != -1){
			Studentas stud1(Stud[i]);
			Stud[i] = Stud[index];
			Stud[index] = stud1;
		}

	}
}