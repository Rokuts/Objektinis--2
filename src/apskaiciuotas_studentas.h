#pragma once

#include "headers.h"
#include "studentas.h"

struct ApskaiciuotasStudentas{
private:
    Studentas studentas_;
    double vidurkis_;
    double mediana_;

public:
    //Konstruktorius
    ApskaiciuotasStudentas(const Studentas& stud)
        : studentas(stud), vidurkis(stud.vidurkis()), mediana(stud.mediana()) {}

    inline Studentas getStudentas() const { return studentas; }
    inline double getVidurkis() const { return vidurkis; }
    inline double getMediana() const { return mediana; }

    inline string getVardas() const { return studentas.getVardas(); }
    inline string getPavarde() const { return studentas.getPavarde(); }
    inline int getEgzas() const { return studentas.getEgzas(); }
};



