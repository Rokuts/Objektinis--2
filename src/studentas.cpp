#include "studentas.h"

Studentas::Studentas(std::istream &is)
{
    if(!(is >> vardas_ >> pavarde_)) {
        throw std::runtime_error("Klaida nuskaitant studento duomenis.");
    }
    int paz;
    while(is >> paz){
        n_.push_back(paz);
    }
    egzas_ = n_.back();   // Paskutinis skaicius yra egzamino pazymys
    n_.pop_back();  
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
