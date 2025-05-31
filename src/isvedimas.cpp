#include "isvedimas.h"
#include "rusiavimas.h"
#include "pagalbines.h"
#include "apskaiciuotas_studentas.h"

template <typename Container, typename Getter>
void lentele_universali(int ilgiausia_pavarde, int ilgiausias_vardas, const Container& S, ostream& isvestis, Getter get_ref, bool ar_rodyti_vidurki)
{
    if (ar_rodyti_vidurki)
        isvestis << left << setw(ilgiausia_pavarde + 3) << "Pavarde" << setw(ilgiausias_vardas + 3) << "Vardas" << setw(17) << "Galutinis (Vid.)" << endl;
    else
        isvestis << left << setw(ilgiausia_pavarde + 3) << "Pavarde" << setw(ilgiausias_vardas + 3) << "Vardas" << setw(17) << "Galutinis (med.)" << endl;

    for (int i = 0; i < (ilgiausia_pavarde + ilgiausias_vardas + 6 + 17); i++)
        isvestis << "-";
    isvestis << endl;

    for (const auto& studentas : S) {
        const auto& stud = get_ref(studentas);
        if (ar_rodyti_vidurki)
            isvestis << left << setw(ilgiausia_pavarde + 3) << stud.getPavarde() << setw(ilgiausias_vardas + 3) << stud.getVardas() << setw(17) << fixed << setprecision(2) << stud.getVidurkis() << endl;
        else
            isvestis << left << setw(ilgiausia_pavarde + 3) << stud.getPavarde() << setw(ilgiausias_vardas + 3) << stud.getVardas() << setw(17) << fixed << setprecision(2) << stud.getMediana() << endl;
    }
}

void lentele(int ilgiausia_pavarde, int ilgiausias_vardas, Container(ApskaiciuotasStudentas) &S, ostream &isvestis, bool ar_rodyti_vidurki)       //lentele kopijoms;
{
    lentele_universali(ilgiausia_pavarde, ilgiausias_vardas, S, isvestis, [](const auto& stud) { return stud; }, ar_rodyti_vidurki);
}

void lentele(int ilgiausia_pavarde, int ilgiausias_vardas, Container(const ApskaiciuotasStudentas*) &S, ostream &isvestis, bool ar_rodyti_vidurki)    //lentele rodyklėms;
{
    lentele_universali(ilgiausia_pavarde, ilgiausias_vardas, S, isvestis, [](const auto& stud) { return *stud; }, ar_rodyti_vidurki);
}

void isvedimas_i_ekrana(int ilgiausia_pavarde, int ilgiausias_vardas, Container(Studentas) &S){
    Container(ApskaiciuotasStudentas) A_S;
    Container_reserve(A_S, S.size());
    for(const auto &s: S){
        A_S.push_back(ApskaiciuotasStudentas(s));
    }
    kaip_rusiuojam_ir_rusiuojam(A_S);
    lentele(ilgiausia_pavarde, ilgiausias_vardas, A_S, cout, paklausiam_ar_rodyti_vidurki());
}

void isvedimas_i_faila(int ilgiausia_pavarde, int ilgiausias_vardas, Container(Studentas) &S){
    
    path failas;        //deklaruojame kintamaji;
    failas = ivesti_failo_pavadinima("Iveskite failo pavadinima:", false); //ivesti failo pavadinima;
    
    ofstream isvestis(failas);
    Container(ApskaiciuotasStudentas) A_S;
    Container_reserve(A_S, S.size());
    for(const auto &s: S){      //pereina per visus studentus s esancius studentu sarase S;
        A_S.push_back(ApskaiciuotasStudentas(s));
    }
    kaip_rusiuojam_ir_rusiuojam(A_S);
    lentele(ilgiausia_pavarde,ilgiausias_vardas,A_S,isvestis, paklausiam_ar_rodyti_vidurki());
    isvestis.close();

}

void skaidymas_ir_isvedimas_i_du_failus(Container(Studentas) &S, int ilgiausia_pavarde, int ilgiausias_vardas)
{
    path failas1 = ivesti_failo_pavadinima("Iveskite failo pavadinima vargsiukams:", false);
    path failas2 = ivesti_failo_pavadinima("Iveskite failo pavadinima kietiakams:", false);
    
    int pasirinkimas;
    pasirinkimas = gauti_skaiciu("Studentus skirstyti pagal vidurki ar mediana? (0 - vidurki, 1 - mediana)", 0, 1);

    skaidymas_ir_isvedimas_i_du_failus_logika(S, ilgiausia_pavarde, ilgiausias_vardas, pasirinkimas, failas1, failas2);
}

void skaidymas_ir_isvedimas_i_du_failus_logika(Container(Studentas) &S, int ilgiausia_pavarde, int ilgiausias_vardas, int pasirinkimas, path &failas1, path &failas2)
{
    Container(ApskaiciuotasStudentas) A_S;
    Container_reserve(A_S, S.size());
    for (const auto &s : S)
    {
        A_S.push_back(ApskaiciuotasStudentas(s));
    }

    Container(const ApskaiciuotasStudentas*) vargsiukai;
    Container(const ApskaiciuotasStudentas*) kietiakai;

    skaidyti_studentus(A_S, vargsiukai, kietiakai, !pasirinkimas);

    ofstream isvestis1(failas1);
    ofstream isvestis2(failas2);

    bool ar_rodyti_vidurki = paklausiam_ar_rodyti_vidurki();
    lentele(ilgiausia_pavarde, ilgiausias_vardas, vargsiukai, isvestis1, ar_rodyti_vidurki);
    lentele(ilgiausia_pavarde, ilgiausias_vardas, kietiakai, isvestis2, ar_rodyti_vidurki);

    isvestis1.close();
    isvestis2.close();
}
void atspauzdinti_studentus(Container(Studentas) &S, ostream &isvestis)
{
    for (const auto &studentas : S) {
        isvestis << studentas << endl;
    }
}
