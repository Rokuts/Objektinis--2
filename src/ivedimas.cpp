#include "ivedimas.h"
#include "pagalbines.h"

std::tuple<string, string> vardo_pavardes_ivedimas(Container(Studentas) &S, int &ilgiausias_vardas, int &ilgiausia_pavarde)
{
    string vardas, pavarde;
    
    cout << "Iveskite " << S.size() + 1 << "-o studento varda ir pavarde arba 'NE' jeigu nebera daugiau studentu." << endl;
    cin >> vardas;
    while (!ar_tik_raides(vardas))
    {
        cout << "!!!Rasta klaida!!! Bandykite ivesti varda dar karta." << endl;
        cin >> vardas;
    }

    if(vardas=="NE"){         //Nebeivedinejame vardu ir pavardziu kai bent vienas yra = NE;
        pavarde = "NE";
        return {vardas, pavarde};
    }

    cin >> pavarde;
    while (!ar_tik_raides(pavarde))
    {
        cout << "!!!Rasta klaida!!! Bandykite ivesti pavarde dar karta." << endl;
        cin >> pavarde;
    }

    ilgiausias_vardas = max(ilgiausias_vardas, (int)vardas.size());  // Vardo ilgis
    ilgiausia_pavarde = max(ilgiausia_pavarde, (int)pavarde.size()); // Pavardes ilgis

    return {vardas, pavarde};
}

void ivedimas_ranka(Container(Studentas) &S, int &ilgiausias_vardas, int &ilgiausia_pavarde)
{

    while(true){
        
        vector<int> n; // Namu darbu pazymiai
        int egzas; // Egzamino pazymys
        //---------------------------------------------------------------------------------------------------------------------------
        //Ivedinejame studentu vardus ir pavardes tol kol ivedamas NE.

        auto [vardas, pavarde] = vardo_pavardes_ivedimas(S, ilgiausias_vardas, ilgiausia_pavarde);
        if(vardas=="NE"||pavarde=="NE") break;

        //--------------------------------------------------------------------------------------------------------------------------
        //Ivedinejame pazymius
        cout<<"Iveskite studento namu darbu pazymius. Pabaigus juos vardyt, parasykit '-1'."<<endl;
        while (true) {
            int pazimys = gauti_skaiciu("", 1, 10, true);
            if (pazimys == -1) break;
            n.push_back(pazimys);
        }
        egzas = gauti_skaiciu("Iveskite studento egzamino pazymi:");
        S.push_back(Studentas(vardas, pavarde, egzas, n));     //viena studenta itrauke i studentus;
        }
    }

void generuojami_pazymiai(Container(Studentas) &S, int &ilgiausias_vardas, int &ilgiausia_pavarde)
{
    while(true){
        
        vector<int> n; // Namu darbu pazymiai
        int egzas; // Egzamino pazymys
        //---------------------------------------------------------------------------------------------------------------------------
        //Ivedinejame studentu vardus ir pavardes tol kol ivedamas NE.

        auto [vardas, pavarde] = vardo_pavardes_ivedimas(S, ilgiausias_vardas, ilgiausia_pavarde);
        if(vardas=="NE"||pavarde=="NE") break;

        //--------------------------------------------------------------------------------------------------------------------------
        //Sugeneruojame pazymius;
        int pazymiu_kiekis=gauti_skaiciu("Iveskite kiek pazymiu norite sugeneruoti.", 0, numeric_limits<int>::max());
        for(int i=0; i<pazymiu_kiekis;i++){
            n.push_back(atsitiktinis_skaicius(1,10));
        }
        egzas = atsitiktinis_skaicius(1,10);
        S.push_back(Studentas(vardas, pavarde, egzas, n));     //viena studenta itrauke i studentus;
    }
}

void generuojama_viskas(Container(Studentas) &S, int &ilgiausias_vardas, int &ilgiausia_pavarde)
{
    int studentu_kiekis=gauti_skaiciu("Iveskite kiek studentu norite sugeneruoti.", 0, numeric_limits<int>::max());
    int pazymiu_kiekis=gauti_skaiciu("Iveskite kiek pazymiu norite sugeneruoti.", 0, numeric_limits<int>::max());
    for(int i=0;i<studentu_kiekis;i++){

        vector<int> n; // Namu darbu pazymiai
        string vardas, pavarde; // Vardas ir pavarde
        int egzas; // Egzamino pazymys
        
        //---------------------------------------------------------------------------------------------------------------------------
        //Sugeneruojami vardai ir pavardes;
        
        vardas=atsitiktine_zodis(vardai);
        pavarde=atsitiktine_zodis(pavardes);

        ilgiausias_vardas = max(ilgiausias_vardas, (int)vardas.size());  // Vardo ilgis
        ilgiausia_pavarde = max(ilgiausia_pavarde, (int)pavarde.size()); // Pavardes ilgis

        //--------------------------------------------------------------------------------------------------------------------------
        //Sugeneruojame pazymius;
        for(int i=0; i<pazymiu_kiekis;i++){
            n.push_back(atsitiktinis_skaicius(1,10));
        }
        //Sugeneruojam egzo pazymi;
        egzas = atsitiktinis_skaicius(1,10);
        S.push_back(Studentas(vardas, pavarde, egzas, n));     //viena studenta itrauke i studentus;
    }
}

void skaitymas_is_failo(Container(Studentas) &S, int &ilgiausias_vardas, int &ilgiausia_pavarde){
    
    path failas = ivesti_failo_pavadinima("Iveskite failo pavadinima:", true);
    skaitymas_is_failo_logika(S, ilgiausias_vardas, ilgiausia_pavarde, failas);
    
}

void skaitymas_is_failo_logika(Container(Studentas) &S, int &ilgiausias_vardas, int &ilgiausia_pavarde, path &failas)
{
    ifstream ivestis;

    ivestis.exceptions(ifstream::failbit | ifstream::badbit); // Ijungia exceptions failo atidarymui
    try
    {
        ivestis.open(failas);
    }
    catch (const std::ifstream::failure &e)
    {
        cout << "Toksai failas nerastas!!!" << endl;
        return;
    }
    ivestis.exceptions(0); // Isjungia exceptions failo atidarymui

    string eilute;
    getline(ivestis, eilute);

    while (getline(ivestis, eilute))
    {
        if (eilute.empty()) continue; // praleidžiam tuščias eilutes
        stringstream iss(eilute);
        try {
            Studentas naujas;
            iss >> naujas;

            // Track longest name lengths
            ilgiausias_vardas = max(ilgiausias_vardas, (int)naujas.getVardas().length());
            ilgiausia_pavarde = max(ilgiausia_pavarde, (int)naujas.getPavarde().length());

            // Add student to the list
            S.push_back(naujas);
        } catch (const std::exception& e) {
            cout << "Netinkamas duomenų formatas eilutėje: " << eilute << endl;
            continue;
        }
    }

    ivestis.close();
    cout << "Duomenys sekmingai nuskaityti!" << endl;
    ;
}

