#pragma once

#include "headers.h"

class Studentas {
private:

    std::string vardas, pavarde;
    int egzas;
    std::vector<int> n;

public:
    
    /**
     * Konstruktorius nuskaitantis viena studenta is srauto
     */
    Studentas(std::istream& is); 
    
    /**
     * Konstruktorius, kuris sukuria studentą su nurodytais duomenimis.
     */
    Studentas(const std::string& vardas, const std::string& pavarde, int egzas, const std::vector<int>& n) 
        : vardas(vardas), pavarde(pavarde), egzas(egzas), n(n) {}


    double vidurkis() const;
    double mediana() const;

    ~Studentas() {
        // Pilnai realizuotas destruktorius. Kadangi klasė nenaudoja dinaminės atminties,
        // čia nereikia nieko papildomai atlaisvinti. Visi nariai sunaikinami automatiškai.
    }

};
