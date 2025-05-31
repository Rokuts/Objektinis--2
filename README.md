# Objektinis programavimas

**Naudojimosi instrukcija**
-
Paleidus programą, jums bus pateiktas meniu su šiais pasirinkimais:

1. **Įvedimas ranka**  
   Vartotojas pats suveda studentų vardus, pavardes ir pažymius per terminalą.

2. **Generuoti pažymius**  
   Įvedus vardą ir pavardę, atsitiktinai sugeneruojami pažymiai.

3. **Generuoti pažymius, vardus, pavardes**  
   Visa informacija (vardas, pavardė, pažymiai) sugeneruojama automatiškai.

4. **Duomenys iš failo**  
   Įvedus failo pavadinimą, programa nuskaito studentų duomenis iš pateikto failo.

5. **Išvesti duomenis į ekraną ir baigti darbą**  
   Atvaizduoja studentų duomenis terminale ir užbaigia darbą.

6. **Išvesti duomenis į failą ir baigti darbą**  
   Išsaugo rezultatus į failą ir baigia programą.

7. **Sugeneruoti failą su studentais**  
   Sugeneruoja failą su pasirinktu studentų skaičiumi.

8. **Suskirstyti studentus į „vargšiukus“ ir „kietiakius“**  
   Pagal vidurkį ar medianą atskiria studentus į dvi grupes ir išveda į atskirus failus.

9. **Laiko tyrimas**  
   Paleidžia algoritmą su skirtingais duomenų dydžiais, matuoja veikimo laiką (nuskaitymą, rušiavimą, skirstymą, išvedimą, bendrą laiką).

10. **Tyrimas su strategijom**  
    Lygina 3 skirstymo strategijas, matuoja jų veikimo laiką su skirtingais duomenų kiekiais (nuskaitymą, rušiavimą ir skirstymą).

Pasirinkus bet kurį punktą, programa paprašys papildomos informacijos (pvz., failo pavadinimo, strategijos numerio, rūšiavimo būdo ir t. t.), o toliau veiks automatiškai pagal pasirinktą režimą.

Pries paleidžiant programa `header.h` faile pasirinkite kokį konteinerio tipą norite naudoti (nutrinkite // ): `#define USE_VECTOR`, `#define USE_LIST`, `#define USE_DEQUE`.

Pries ivedant failo pavadinima pries tai reikia parasyti " ..\ " pvz. ( ..\failas.txt ).

Prieš pasirenkant 8 punktą, įsitikinkite, kad turite jau įvestų arba nuskaitytų studentų duomenų, nes ši funkcija pati nepaprašo duomenų įvedimo.

**Releasai**
-
- **v0.1:** Įvedami ir generuojami studentų duomenys (vardas, pavardė, pažymiai). Taip pat apskaičiuojamas galutinis balas naudojant vidurkį arba medianą.
- **v0.2:** Pridėtas darbas su failais. Duomenys gali būti nuskaityti iš failo ir įrašyti į failą.
- **v0.3:** Įtrauktas išimčių valdymas programos saugumui ir stabilumui užtikrinti.
- **v0.4:** Pridėtas studentų skirstymas pagal galutinį balą ir atliktas pirmas ir antras tyrimas.
- **v1.0:** programos greičio testavimas su trimis skirtingais konteineriais (vector, list, deque). Įgyvendintos 2 duomenų skirstymo strategijos ir viena jų optimizuota.

**Testavimai atlikti kompiuteryje su šia konfigūracija:**
-
- Procesorius (CPU): Intel i5-11300H (3.1 GHz, 11th Gen);
- RAM: 8 GB
- SSD: Intel 660p
- OS: Windows 10
- Kompiliatorius: Clang++ (LLVM), C++20 standartas

Tyrimai atlikti naudojant šią aparatūrą ir programinę įrangą, kuri užtikrina pakankamą našumą duomenų apdorojimo užduotims. Naudojamas Clang++ kompiliatorius su C++20 standartu leidžia efektyviai išnaudoti modernias kalbos galimybes.

**1 tyrimas. Failų kūrimas ir jo uždarymas**
-

**Tikslas:** įvertinti, kiek laiko užtrunka sugeneruoti skirtingo dydžio duomenų failus.

**Tyrimo eiga:**
- Vartotojas įveda failo pavadinimą, studentų ir pažymių kiekį;
- Laiko matavimas prasideda po vartotojo įvesties;
- Programa sugeneruoja duomenų failą su atsitiktiniais vardais, pavardėmis ir pažymiais;
- Laiko matavimas baigiamas užbaigus failo generavimą;
- Išvedamas sugeneravimo laikas sekundėmis, reprezentuojantis programos spartą failo kūrimui pagal pasirinktus parametrus.

**Gauti rezultatai:**

1. Studentų: 1000, pazymių: 10;

![alt text](images/image-3.png)

2. Studentų: 10000, pazymių: 10;

![alt text](images/image-4.png)

3. Studentų: 100000, pazymių: 10;

![alt text](images/image-5.png)

4. Studentų: 1000000, pazymių: 10;

![alt text](images/image-6.png)

5. Studentų: 10000000, pazymių: 10;

![alt text](images/image-7.png)

**Lentele:**

![alt text](images/image-8.png)

**Išvada**: Failo generavimo trukmė didėja proporcingai duomenų kiekiui, o tai rodo gerą programos efektyvumą. Programa išlieka naši net ir su labai dideliais įrašų kiekiais – 10 milijonų įrašų sugeneruota per mažiau nei 3 minutes.

**2 tyrimas. Duomenų apdorojimo našumo tyrimas (std::vector)**
-

**Tikslas:** Įvertinti programos spartą atliekant pilną duomenų apdorojimo procesą: duomenų nuskaitymą iš jau sugeneruoto failo, studentų rūšiavimą į dvi kategorijas, duomenų išvedimą į atskirus failus.

**Tyrimo eiga:**
- Vartotojas įveda: failo pavadinimą, iš kurio bus nuskaitomi duomenys, dviejų rezultatinių failų pavadinimus (vargšiukams ir kietiakams), pasirinkimą, pagal kokį kriterijų skirstyti studentus;
- Laiko matavimas prasideda po vartotojo įvesties;
- Programa nuskaito studentų įrašus į atmintį;
- Studentai suskirstomi į dvi grupes (vargšiukus ir kietiakus);
- Kiekviena grupė išvedama į atskirą failą;
- Laiko matavimas baigiamas užbaigus įrašymą;
- Išvedami laiko rezultatai sekundėmis.

**Gauti rezultatai:**

1. Studentų: 1000, pažymių: 10;

![alt text](images/image-9.png)

2. Studentų: 10000, pažymių: 10;

![alt text](images/image-10.png)

3. Studentų: 100000, pažymių: 10;

![alt text](images/image-11.png)

4. Studentų: 1000000, pažymių: 10;

![alt text](images/image-12.png)

5. Studentų: 10000000, pažymių: 10;

![alt text](images/image-13.png)

**Lentele:**

![alt text](images/image-14.png)

**Išvada:**
Nuskaitymas ir išvedimas užima daugiausia laiko, ypač su dideliais duomenų kiekiais. Tai rodo, kad programos sparta ribojama ne algoritmo efektyvumo, o kietojo disko įvesties/išvesties greičio. Tuo tarpu rūšiavimo ir skirstymo operacijos vykdomos itin sparčiai, todėl galima teigti, kad pati algoritmo logika yra efektyvi.

**3 tyrimas. Duomenų apdorojimo našumo tyrimas su std::list ir std::deque**
-
**Tikslas:** Palyginti std::vector, std::list ir std::deque konteinerių našumą, atliekant duomenų nuskaitymą, rūšiavimą ir skirstymą į grupes.

**Tyrimo eiga:** Išlieka identiška kaip ir antrajame tyrime – duomenys į programą įkeliami iš tų pačių failų, atliekami tie patys veiksmai ta pačia seka: duomenų nuskaitymas, studentų rūšiavimas bei skirstymas į dvi grupes.

**Gauti rezultatai (std::list):**

1. Studentų: 1000, pažymių: 10;

![alt text](images/image-15.png)

2. Studentų: 10000, pažymių: 10;

![alt text](images/image-16.png)

3. Studentų: 100000, pažymių: 10;

![alt text](images/image-17.png)

4. Studentų: 1000000, pažymių: 10;

![alt text](images/image-18.png)

5. Studentų: 10000000, pažymių: 10;

![alt text](images/image-19.png)

**Lentele:**

![alt text](images/image-20.png)

**Gauti rezultatai (std::deque):**

1. Studentų: 1000, pažymių: 10;

![alt text](images/image-21.png)

2. Studentų: 10000, pažymių: 10;

![alt text](images/image-22.png)

3. Studentų: 100000, pažymių: 10;

![alt text](images/image-23.png)

4. Studentų: 1000000, pažymių: 10;

![alt text](images/image-24.png)

5. Studentų: 10000000, pažymių: 10;

![alt text](images/image-25.png)

**Lentele:**

![alt text](images/image-26.png)

**Išvada:**
Remiantis atliktais matavimais, std::deque konteineris buvo pastebimai greitesnis atliekant skirstymo operacijas, ypač esant dideliems duomenų kiekiams, o rūšiavimo ir nuskaitymo greičiai tarp std::list ir std::deque buvo panašūs.

**2 ir 3 tyrimų bendroji analizė**
-
**Nuskaitymas**

![alt text](images/image-27.png)

**Išvada:**
Nors teoriškai std::vector dažniausiai laikomas greičiausiu nuskaitymui, tyrimas parodė netikėtą rezultatą: su 10 milijonų elementų std::list veikė sparčiausiai. Kitais atvejais, std::vector ir std::deque demonstravo našumą.

**Rušiavimas**

![alt text](images/image-28.png)

**Išvada:**
Rūšiavimui mažesniais ir vidutiniais duomenų kiekiais (iki ~100 000) efektyvesnis yra std::list. Tačiau didėjant duomenų kiekiui (virš 1 000 000) dėl geresnės atminties lokalumo ir efektyvesnių algoritmų naudojimo, std::vector tampa žymiai greitesnis.

**Skirstymas**

![alt text](images/image-29.png)

**Išvada:**
Skirstymo operacijos rezultatai yra labai aiškūs: std::vector buvo greičiausias visais testuotais duomenų kiekiais, ir jo pranašumas ypač išryškėjo didėjant elementų skaičiui. Tai rodo, kad programa efektyviausiai išnaudojo std::vector savybes – tvarkingą studentų laikymą atmintyje (vieną šalia kito) ir galimybę greitai pasiekti bet kurį reikiamą studentą.

**4 tyrimas. Duomenų skaidymo strategijų efektyvumo tyrimas naudojant skirtingus STL konteinerius**
-

**Tikslas:**
Ištirti ir palyginti skirtingų C++ STL konteinerių (std::vector, std::list, std::deque) našumą atliekant studentų duomenų skaidymą pagal dvi skirtingas strategijas.

**Tyrimo eiga:**
- Vartotojas įveda: failo pavadinimą, iš kurio bus nuskaitomi duomenys, pagal ką rušiuoti duomenis ir kokia strategija atlikti;
- Laiko matavimas prasideda po vartotojo įvesties;
- Programa nuskaito studentų įrašus į atmintį;
- **1 strategija** - bendro studentai konteinerio skaidymas į du naujus to paties tipo konteinerius: "vargšiukų" ir "kietiakų". Tokiu būdu tas pats studentas yra dvejuose konteineriuose.
- **2 strategija** - bendro studentų konteinerio skaidymas panaudojant tik vieną naują konteinerį: "vargšiukai". Tokiu būdu, jei studentas yra vargšiukas, jį turime įkelti į naująjį "vargšiukų" konteinerį ir ištrinti iš bendro studentai konteinerio. Po šio žingsnio studentai konteineryje liks vien tik kietiakai.
- Laiko matavimas baigiamas užbaigus įrašymą;
- Išvedami laiko rezultatai sekundėmis.

**Gauti rezultatai:**

![alt text](images/image-30.png)


**Išvada:**

Atlikus studentų skaidymo į "vargšiukus" ir "kietiakus" tyrimą su skirtingais konteinerių tipais (std::vector, std::list, std::deque) ir dviem skaidymo strategijomis, paaiškėjo esminiai našumo ir atminties naudojimo efektyvumo skirtumai, ypač parodantys std::list pranašumą greitaveikos atžvilgiu.
Pirmojoje strategijoje, kur studentai buvo kopijuojami į du naujus konteinerius, std::list rodė geriausius greičio rezultatus su visais duomenų kiekiais. Šį pranašumą užtikrino O(1) sudėtingumo "push_back" operacija ir tai, kad šiam konteineriui nereikalingas atminties perskirstymas. Nors std::vector ir std::deque taip pat demonstravo priimtiną greitį, jų našumas šiek tiek svyravo dėl vidinių atminties valdymo ypatumų. Svarbu paminėti, kad ši strategija yra nepalanki atminties sąnaudų atžvilgiu, nes tie patys studentų duomenys saugomi keliose vietose.
Antrojoje strategijoje, kurioje "vargšiukai" buvo perkeliami į naują konteinerį, o iš pradinio – trinami, std::list pademonstravo absoliutų pranašumą greitaveikoje. Jo O(1) sudėtingumo "erase" operacija leido išlaikyti efektyvumą net ir su 100,000 studentų. Tuo tarpu std::vector ir std::deque konteineriai, dėl O(N) sudėtingumo "erase" operacijos, tapo nepraktiškai lėti didėjant duomenų kiekiui. Visgi, ši strategija pasižymi ženkliai efektyvesniu atminties naudojimu, nes studentų duomenys nėra dubliuojami, o tiesiog perskirstomi tarp pradinio ir naujo "vargšiukų" konteinerio.

**Optimizavus strategija 1 gauti rezultatai**

![alt text](images/image-31.png)

**Išvada:**

Atlikus studentų skirstymo našumo tyrimą su Vector konteineriu, paaiškėjo, kad strategija 1 (naudojant for ciklas) ir optimizuota strategija 1 (naudojant std::partition_point) veikė panašiu greičiu. Pagrindinė to priežastis – abiejose strategijose buvo operuojama su nuorodomis (arba rodyklėmis) į studentų objektus, o ne su jų kopijomis.

**5 tyrimas. Struktūros ir klasės palyginimas: našumo analizė su skirtingais optimizavimo lygiais**
-

**Tikslas:**

Ištirti programos našumo skirtumus, kai vietoj struktūrų (struct) naudojamos klasės (class), bei įvertinti kompiliatoriaus optimizavimo lygių (-O1, -O2, -O3) poveikį programos spartai dirbant su dideliais duomenų failais (100 000 ir 1 000 000 įrašų), naudojant vektoriaus (std::vector) konteinerį ir optimalią rūšiavimo/dalijimo strategiją.

**Gauti rezultatai:**

| Studentų skaičius | Flags | Struct (s) | Struct dydis (B) | Class (s) | Class dydis (B) |
|-------------------|-------|------------|------------------|-----------|-----------------|
| 100000            | O1    | 0.693444   | 131584           | 0.54581   | 142848          |
|                   | O2    | 0.580289   | 136192           | 0.658903  | 147968          |
|                   | O3    | 0.576069   | 145408           | 0.814887  | 165376          |
| 1000000           | O1    | 5.39164    | 131584           | 5.43563   | 142848          |
|                   | O2    | 6.11433    | 136192           | 7.74538   | 147968          |
|                   | O3    | 5.63477    | 145408           | 6.4951    | 165376          |

**Išvada:**

Eksperimentas parodė, kad class ir struct versijų veikimo laikas skiriasi nežymiai, o optimizavimo flag'ai (-O1, -O2, -O3) turi didesnę įtaką našumui nei pati objekto rūšis. Class realizacija generuoja šiek tiek didesnį vykdomąjį failą, tačiau dažnai veikia greičiau su mažesniu duomenų kiekiu. Todėl optimizacija svarbesnė už struct/class pasirinkimą, jei klasė efektyviai sukurta.

**Duomenų įvedimo ir išvedimo metodai (perdengti operatoriai)**

Šioje programoje duomenų įvedimas ir išvedimas realizuotas naudojant **perdengtus C++ operatorius** – tai leidžia patogiai ir universaliai dirbti tiek su rankiniu, tiek su automatiniu ar failiniu įvedimu/išvedimu.

### Įvesties operatorius `operator>>`

```cpp
friend std::istream& operator>>(std::istream& is, Studentas& s);
```

**Panaudojimas:**
- **Rankinis įvedimas:**  
  Vartotojas gali įvesti studento duomenis viena eilute (pvz., `Jonas Jonaitis 8 9 10 7`). Programa naudoja `std::getline` ir `std::stringstream`, kad perduotų visą eilutę į šį operatorių.  
  Taip pat veikia, jei kiekvienas laukas įvedamas atskirai (pvz., vardas, pavardė, pažymiai po vieną spaudžiant Enter), nes operatorius skaito po vieną žodį/skaičių iš srauto.

- **Automatinis generavimas:**  
  Sugeneruoti duomenys perduodami tiesiai į studento konstruktorių, todėl operatorius čia nenaudojamas, tačiau duomenų struktūra išlieka ta pati.

- **Įvedimas iš failo:**  
  Kiekviena failo eilutė (be antraštės) perduodama į `stringstream`, kuris perduodamas į `operator>>`. Taip užtikrinamas universalumas – nesvarbu, ar duomenys ateina iš failo, ar iš konsolės, jie apdorojami vienodai.

**Ką daro operatorius:**  
- Nuskaito vardą, pavardę, visus namų darbų pažymius ir egzamino pažymį.
- Tikrina, ar įvestis teisinga (pvz., ar nėra netinkamų simbolių pažymiuose).
- Jei įvestis neteisinga, meta išimtį, kurią programa pagauna ir išveda klaidos žinutę.

---

### Išvesties operatorius `operator<<`

```cpp
friend std::ostream& operator<<(std::ostream& os, const Studentas& s);
```

**Panaudojimas:**
- **Išvedimas į ekraną:**  
  Leidžia patogiai išvesti studento duomenis į terminalą, pvz.:
  ```cpp
  cout << studentas << endl;
  ```
- **Išvedimas į failą:**  
  Naudojamas rašant studentų duomenis į failą, pvz.:
  ```cpp
  ofstream out("rezultatai.txt");
  out << studentas << endl;
  ```

**Ką daro operatorius:**  
- Išveda vardą, pavardę, visus namų darbų pažymius ir egzamino pažymį vienoje eilutėje.
- Užtikrina, kad duomenų formatas būtų vienodas tiek ekrane, tiek faile.

---

### Apibendrinimas

- **Perdengti įvesties/išvesties operatoriai užtikrina universalumą:**  
  Viena logika veikia tiek su failais, tiek su konsolės įvedimu/išvedimu.
- **Rankinis įvedimas:**  
  Galima įvesti tiek viena eilute, tiek po vieną lauką – operatorius veikia abiem atvejais.
- **Automatinis generavimas:**  
  Duomenys perduodami tiesiai į konstruktorių, bet išvedimui naudojamas tas pats operatorius.
- **Failinis įvedimas/išvedimas:**  
  Kiekviena eilutė apdorojama per operatorių, todėl nereikia papildomų formatavimo funkcijų.

---

**Pavyzdys:**

```cpp
// Įvedimas iš failo
std::ifstream in("studentai.txt");
Studentas s;
while (in >> s) {
    // ...
}

// Rankinis įvedimas viena eilute
std::string eilute;
std::getline(std::cin, eilute);
std::stringstream ss(eilute);
ss >> s;

// Išvedimas į ekraną arba failą
std::cout << s << std::endl;
std::ofstream out("rez.txt");
out << s << std::endl;
```

---

**Išvada:**  
Naudojant perdengtus operatorius, programa tampa lanksti, lengvai prižiūrima ir universali – visi įvedimo/išvedimo būdai veikia vienodai, o duomenų formatas išlieka nuoseklus.

**Abstrakti klasė `Zmogus` ir paveldėjimas**
-

Sukurta **abstrakti bazinė klasė** `Zmogus`, kuri apibrėžia bendrus laukus ir metodus visiems žmonių tipams (pvz., vardas, pavardė). Ši klasė negali būti instancijuojama tiesiogiai – ji skirta tik paveldėjimui.

```cpp
class Zmogus {
protected:
    string vardas_;
    string pavarde_;
public:
    Zmogus() = default;
    Zmogus(const string& vardas, const string& pavarde);
    virtual ~Zmogus() = 0; // Abstraktus destruktorius
    string getVardas() const;
    string getPavarde() const;
};
```

Iš `Zmogus` klasės paveldima **studentų klasė** `Studentas`, kuri papildo bazinę informaciją studentui būdingais laukais (pvz., pažymiai, egzamino rezultatas) ir metodais (pvz., vidurkio/medianų skaičiavimas).

```cpp
class Studentas : public Zmogus {
private:
    int egzas_;
    std::vector<int> n_;
public:
    Studentas();
    Studentas(const std::string& vardas, const std::string& pavarde, int egzas, const std::vector<int>& n);
    // ... kiti metodai ...
};
```

**Nauda:**  
Toks objektinis dizainas leidžia lengvai plėsti programą – ateityje galima pridėti kitų žmonių tipų (pvz., dėstytojų) klases, paveldinčias iš `Zmogus`, ir užtikrinti bendrą sąsają visiems žmonėms.


> **Pastaba:**  
> Klasė `Zmogus` turi abstraktų destruktorių, todėl negalima sukurti `Zmogus` objekto tiesiogiai:
> 
> ```cpp
> // Zmogus z("Vardenis", "Pavardenis"); // Klaida: negalima instancijuoti abstrakčios klasės
> ```

---

## v3.0 vektoriaus konteineris

#### 1. `push_back(const T& value)`
Prideda naują elementą į vektoriaus galą. Jei reikia, automatiškai padidina talpą.
```cpp
Vektorius<int> v;
v.push_back(10);
v.push_back(20);
// vektorius: [10, 20]
```

#### 2. `pop_back()`
Pašalina paskutinį vektoriaus elementą. 
```cpp
Vektorius<int> v;
v.push_back(10);
v.push_back(20);
v.pop_back(); // Paskutinis elementas pašalinamas, vektorius tampa [10]
```

#### 3. `operator[](size_t idx)`
Leidžia pasiekti elementą pagal indeksą kaip masyve. Nenaudoja ribų tikrinimo.
```cpp
v[0] = 5; // Pakeičia pirmą elementą į 5
int x = v[1]; // x = 20
```

#### 4. `at(size_t idx)`
Grąžina nuorodą į elementą pagal indeksą, bet meta išimtį, jei indeksas neteisingas.
```cpp
try {
    int y = v.at(2); // Mėginant pasiekti neegzistuojantį elementą bus išmesta std::out_of_range
} catch (const std::out_of_range& e) {
    std::cout << "Klaida: " << e.what() << std::endl;
}
```

#### 5. `clear()`
Ištrina visus vektoriaus elementus ir atlaisvina atmintį.
```cpp
v.clear(); // vektorius tampa tuščias, size() == 0, capacity() == 0
```

#### 6. Kopijavimo operatorius `operator=`
Leidžia priskirti vieną vektorių kitam (deep copy).
```cpp
Vektorius<int> v1;
v1.push_back(1);
Vektorius<int> v2;
v2 = v1; // v2 tampa v1 kopija
```



### Autorius 
Rokas Venckus