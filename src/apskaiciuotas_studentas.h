#pragma once

#include "headers.h"
#include "studentas.h"

class ApskaiciuotasStudentas: public Studentas{
private:
    double vidurkis_;
    double mediana_;

public:
    //Konstruktorius
    ApskaiciuotasStudentas(const Studentas& stud)
        : Studentas(stud), vidurkis_(stud.vidurkis()), mediana_(stud.mediana()) {}

    inline double getVidurkis() const { return vidurkis_; }
    inline double getMediana() const { return mediana_; }

};



