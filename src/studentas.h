#pragma once

#include "headers.h"


class Studentas {
private:

    std::string vardas_, pavarde_;
    int egzas_;
    std::vector<int> n_;

public:
    
    Studentas() = default; // Default constructor

    /**
     * Konstruktorius nuskaitantis viena studenta is srauto
     */
    Studentas(std::istream& is); 
    
    /**
     * Konstruktorius, kuris sukuria studentą su nurodytais duomenimis.
     */
    Studentas(const std::string& vardas, const std::string& pavarde, int egzas, const std::vector<int>& n) 
        : vardas_(vardas), pavarde_(pavarde), egzas_(egzas), n_(n) {}

    // Copy constructor
    Studentas(const Studentas& other)
        : vardas_(other.vardas_), pavarde_(other.pavarde_), egzas_(other.egzas_), n_(other.n_) {}
    
    // Move constructor
    Studentas(Studentas&& other) noexcept
        : vardas_(std::move(other.vardas_)), pavarde_(std::move(other.pavarde_)),
          egzas_(other.egzas_), n_(std::move(other.n_)) {}


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

    // Įvesties/išvesties operatoriai
    friend std::ostream& operator<<(std::ostream& os, const Studentas& s);
    friend std::istream& operator>>(std::istream& is, Studentas& s);


    double vidurkis() const;
    double mediana() const;

    // Rule of Five

   // Copy assignment
    Studentas& operator=(const Studentas& other) {
        if (this != &other) {
            vardas_ = other.vardas_;
            pavarde_ = other.pavarde_;
            egzas_ = other.egzas_;
            n_ = other.n_;
        }
        return *this;
    }     

    // Move assignment
    Studentas& operator=(Studentas&& other) noexcept {
        if (this != &other) {
            vardas_ = std::move(other.vardas_);
            pavarde_ = std::move(other.pavarde_);
            egzas_ = other.egzas_;
            n_ = std::move(other.n_);
        }
        return *this; 
    }

    ~Studentas() {
        // Pilnai realizuotas destruktorius. Kadangi klasė nenaudoja dinaminės atminties,
        // čia nereikia nieko papildomai atlaisvinti. Visi nariai sunaikinami automatiškai.
    }

};
