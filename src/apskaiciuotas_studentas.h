#pragma once

#include "headers.h"
#include "studentas.h"

struct ApskaiciuotasStudentas{
private:
    Studentas studentas;
    double vidurkis;
    double mediana;

public:
    //Konstruktorius
    ApskaiciuotasStudentas(const Studentas& stud)
        : studentas(stud), vidurkis(stud.vidurkis()), mediana(stud.mediana()) {}

    Studentas getStudentas() const { return studentas; }
    double getVidurkis() const { return vidurkis; }
    double getMediana() const { return mediana; }
};



