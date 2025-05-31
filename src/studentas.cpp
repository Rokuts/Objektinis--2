#include "studentas.h"

Studentas::Studentas(std::istream &is)
{
    is >> *this; // Panaudojame operator>> studento duomenims nuskaityti
}

double Studentas::vidurkis() const
{
    if (n_.size() == 0) 
        return egzas_ * 0.6;  // Jei tarpiniu pazimiu nera, tai isvedamas balas su egzamino pazimiu;
    
    double vidurkis=0;
    for(int i=0; i<n_.size();i++){
        vidurkis += n_[i];
    }
    vidurkis = vidurkis/n_.size();
    
    return vidurkis * 0.4 + (egzas_ * 0.6);
}

double Studentas::mediana() const
{
    if (n_.size() == 0) 
        return egzas_*0.6;    //Jei tarpiniu pazimiu nera, tai isvedamas balas su egzamino pazimiu;
    
    double mediana;
    int x=n_.size();

    vector<int> temp(n_);
    sort(temp.begin(),temp.end());
    if(x%2==0)
        mediana = (temp[x/2]+temp[x/2-1])/2.0;
    else mediana = (temp[x/2]);
    return mediana * 0.4 + (egzas_ * 0.6);
}

std::ostream &operator<<(std::ostream &os, const Studentas &s)
{
    os << s.vardas_ << " " << s.pavarde_ << " ";
    for (const auto &paz : s.n_) {
        os << paz << " ";
    }
    os << s.egzas_;
    return os;
}

std::istream &operator>>(std::istream &is, Studentas &s)
{
    
    if (!(is >> s.vardas_ >> s.pavarde_)) {
        throw std::runtime_error("Klaida nuskaitant studento duomenis.");
    }
    s.n_.clear();
    int paz;
    vector<int> laikini;
    while (is >> paz) {
        laikini.push_back(paz);
    }

    if (!laikini.empty()) {
        s.egzas_ = laikini.back(); // Paskutinis skaicius yra egzamino pazymys
        laikini.pop_back();
        s.n_ = laikini; // Likusieji yra namų darbų pažymiai
    } 
    return is;
}
