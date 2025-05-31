#pragma once

#include "headers.h"

class Zmogus {
protected:
    string vardas_;
    string pavarde_;
public:
    Zmogus() = default;
    Zmogus(const string& vardas, const string& pavarde)
        : vardas_(vardas), pavarde_(pavarde) {}

    virtual ~Zmogus() = default;

    inline string getVardas() const { return vardas_; }
    inline string getPavarde() const { return pavarde_; }

};