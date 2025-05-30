#include "headers.h"
#include "studentas.h"
#include "apskaiciuotas_studentas.h"
#include "pagalbines.h"
#include "ivedimas.h"
#include "isvedimas.h"
#include "rusiavimas.h"

int main(){
    srand (time(NULL));     //padaro jog generuojami atsitiktiniai skaiciai butu skirtingi kiekviena karta;
    
    Container(Studentas) S; // visi studentai

    int ilgiausias_vardas=6, ilgiausia_pavarde=7;       // vardas 6 pavarde 7, nes jeigu butu trumpesnis nei stulpelio pavadinimas kad nesusilietu;

    while(true){
        meniu();
        int pasirinkimas;
        pasirinkimas = gauti_skaiciu("Iveskite norima varianta.", 1, 11);
        switch(pasirinkimas){
            case 1:
                ivedimas_ranka(S, ilgiausias_vardas, ilgiausia_pavarde);
                break; 
            case 2:
                generuojami_pazymiai(S, ilgiausias_vardas, ilgiausia_pavarde);
                break;
            case 3:
                generuojama_viskas(S, ilgiausias_vardas, ilgiausia_pavarde);
                break;
            case 4: 
                skaitymas_is_failo(S, ilgiausias_vardas, ilgiausia_pavarde);
                break;
            case 5: //isvesti i ekrana
                isvedimas_i_ekrana(ilgiausia_pavarde, ilgiausias_vardas, S);
                return 0;
            case 6: //isvesti i faila
                isvedimas_i_faila(ilgiausia_pavarde,ilgiausias_vardas,S);
                return 0;
            case 7: //sugeneruoti faila su studentais
                generuoti_faila();
                break;
            case 8:
                skaidymas_ir_isvedimas_i_du_failus(S, ilgiausia_pavarde, ilgiausias_vardas);
                return 0;
            case 9:
                laiko_tyrimas();
                break; 
            case 10:
                tyrimas_su_strategijom();
                break;
            case 11:
                // Originalus objektas
                Studentas s1("Jonas", "Jonaitis", 9, {10, 9, 8});

                // Copy constructor
                Studentas s2(s1);
                assert(s2.getVardas() == "Jonas");
                assert(s2.getPavarde() == "Jonaitis");
                assert(s2.getEgzas() == 9);
                assert(s2.getNamuDarbai() == std::vector<int>({10, 9, 8}));

                // Move constructor
                Studentas s3 = std::move(s2);
                assert(s3.getVardas() == "Jonas");

                // Copy assignment
                Studentas s4("Petras", "Petraitis", 7, {7, 7, 7});
                s4 = s1;
                assert(s4.getVardas() == "Jonas");

                // Move assignment
                Studentas s5("Ona", "Onaitė", 6, {6, 6, 6});
                s5 = std::move(s4);
                assert(s5.getVardas() == "Jonas");

                // Patikriname operator<<
                std::stringstream ss;
                ss << s1;
                std::string out = ss.str();
                assert(out.find("Jonas") != std::string::npos);
                assert(out.find("Jonaitis") != std::string::npos);

                // Patikriname operator>>
                std::stringstream ss2("Vardenis Pavardenis 10 8 7 6");
                Studentas s6(ss2);
                // arba: ss2 >> s6;
                assert(s6.getVardas() == "Vardenis");
                assert(s6.getPavarde() == "Pavardenis");
                assert(s6.getEgzas() == 10);
                assert(s6.getNamuDarbai() == std::vector<int>({8, 7, 6}));

                std::cout << "Rule of Five testas pavyko!" << std::endl;
                return 0;
        }

    }
    
    return 0;
}


