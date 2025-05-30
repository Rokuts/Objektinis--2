#pragma once

#include "headers.h"
#include "studentas.h"

void vardo_pavardes_ivedimas(Container(Studentas) &S, Studentas &s, int &ilgiausias_vardas, int &ilgiausia_pavarde);
void ivedimas_ranka(Container(Studentas) &S, int &ilgiausias_vardas, int &ilgiausia_pavarde);
void generuojami_pazymiai(Container(Studentas) &S, int &ilgiausias_vardas, int &ilgiausia_pavarde);
void generuojama_viskas(Container(Studentas) &S, int &ilgiausias_vardas, int &ilgiausia_pavarde);
void skaitymas_is_failo(Container(Studentas) &S, int &ilgiausias_vardas, int &ilgiausia_pavarde);
void skaitymas_is_failo_logika(Container(Studentas) &S, int &ilgiausias_vardas, int &ilgiausia_pavarde, path &failas);
