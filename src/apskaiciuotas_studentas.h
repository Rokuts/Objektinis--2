#pragma once

#include "headers.h"
#include "studentas.h"

struct apskaiciuotas_studentas{
    Studentas studentas;
    double vidurkis;
    double mediana;
};

apskaiciuotas_studentas apskaiciuoti_stud(Studentas stud);


