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

    // Rule of Five
    Zmogus(const Zmogus& other) = default;            // Copy constructor
    Zmogus(Zmogus&& other) noexcept = default;        // Move constructor
    Zmogus& operator=(const Zmogus& other) = default; // Copy assignment
    Zmogus& operator=(Zmogus&& other) noexcept = default; // Move assignment
    virtual ~Zmogus() = 0;  // Pure virtual destructor

    inline string getVardas() const { return vardas_; }
    inline string getPavarde() const { return pavarde_; }

};