#include "studentas.h"

double Studentas::vidurkis() const
{
    if (n.size() == 0) 
        return egzas * 0.6;  // Jei tarpiniu pazimiu nera, tai isvedamas balas su egzamino pazimiu;
    
    double vidurkis=0;
    for(int i=0; i<n.size();i++){
        vidurkis += n[i];
    }
    vidurkis = vidurkis/n.size();
    
    return vidurkis * 0.4 + (egzas * 0.6);
}

double Studentas::mediana() const
{
    if (n.size() == 0) 
        return egzas*0.6;    //Jei tarpiniu pazimiu nera, tai isvedamas balas su egzamino pazimiu;
    
    double mediana;
    int x=n.size();
    sort(n.begin(),n.end());
    if(x%2==0)
        mediana = (n[x/2]+n[x/2-1])/2;
    else mediana = (n[x/2]);
    return mediana * 0.4 + (egzas * 0.6);
}
