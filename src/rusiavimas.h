#pragma once

#include "headers.h"
#include "apskaiciuotas_studentas.h"

bool compareByVidurkis(ApskaiciuotasStudentas &a, ApskaiciuotasStudentas &b);
bool compareByMediana(ApskaiciuotasStudentas &a, ApskaiciuotasStudentas &b);
bool compareByVardas(ApskaiciuotasStudentas &a, ApskaiciuotasStudentas &b);
bool compareByPavarde(ApskaiciuotasStudentas &a, ApskaiciuotasStudentas &b);

void kaip_rusiuojam_ir_rusiuojam(Container(ApskaiciuotasStudentas) &S);
void sort_pagal_pasirinkima(int pasirinkimas, Container(ApskaiciuotasStudentas) &S);
void skaidyti_studentus(Container(ApskaiciuotasStudentas) &S, Container(const ApskaiciuotasStudentas*) &vargsiukai, Container(const ApskaiciuotasStudentas*) &kietiakiai, bool naudoti_vidurki);
void skaidyti_strategija2(Container(ApskaiciuotasStudentas) &S, Container(ApskaiciuotasStudentas) &vargsiukai, bool naudoti_vidurki);
void skaidyti_strategija3_vector(const Container(ApskaiciuotasStudentas)& A_S, Container(const ApskaiciuotasStudentas*)& vargsiukai, Container(const ApskaiciuotasStudentas*)& kietiakiai, bool naudoti_vidurki);