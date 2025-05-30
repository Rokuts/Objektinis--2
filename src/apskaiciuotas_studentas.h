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
        : studentas_(stud), vidurkis_(stud.vidurkis()), mediana_(stud.mediana()) {}

    inline Studentas getStudentas() const { return studentas_; }
    inline double getVidurkis() const { return vidurkis_; }
    inline double getMediana() const { return mediana_; }

    inline string getVardas() const { return studentas_.getVardas(); }
    inline string getPavarde() const { return studentas_.getPavarde(); }
    inline int getEgzas() const { return studentas_.getEgzas(); }
};



