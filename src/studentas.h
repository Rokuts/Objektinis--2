#pragma once

#include "headers.h"

class Studentas {
private:

    std::string vardas_, pavarde_;
    int egzas_;
    std::vector<int> n_;

public:
    
    /**
     * Konstruktorius nuskaitantis viena studenta is srauto
     */
    Studentas(std::istream& is); 
    
    /**
     * Konstruktorius, kuris sukuria studentą su nurodytais duomenimis.
     */
    Studentas(const std::string& vardas, const std::string& pavarde, int egzas, const std::vector<int>& n) 
        : vardas_(vardas), pavarde_(pavarde), egzas_(egzas), n_(n) {}

    inline string getVardas() const {
        return vardas_;
    }
    inline string getPavarde() const {
        return pavarde_;
    }
    inline int getEgzas() const {
        return egzas_;
    }
    inline const std::vector<int>& getNamuDarbai() const {
        return n_;
    }


    double vidurkis() const;
    double mediana() const;

    ~Studentas() {
        // Pilnai realizuotas destruktorius. Kadangi klasė nenaudoja dinaminės atminties,
        // čia nereikia nieko papildomai atlaisvinti. Visi nariai sunaikinami automatiškai.
    }

};
