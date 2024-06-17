#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <iomanip>
#include <limits>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include "studentas.h"
#include "vector.h"

using namespace std;
using namespace std::chrono;

// struct studentas
// {
//     string vardas;
//     string pavarde;
//     vector<int> ndrez; //sudaromas vektorius
//     int erez;
//     double gbalas;
// };

extern int tlaikas;

void skaitymasisfailo(Vector<studentas> &A, char budas, char ivedbudas);
void isvedimas(Vector<studentas> &A, char budas);
void pazymiuived(studentas &new_studentas, char budas, int ivedbudas);
void skaiciavimas(studentas &new_studentas, char budas);
void irasymasifaila(Vector<studentas> &A, char budas);
bool rikiavimasgbalas(const studentas &a, const studentas &b);
bool rikiavimasvardas(const studentas &a, const studentas &b);
bool rikiavimaspavarde(const studentas &a, const studentas &b);
void rikiavimas(Vector<studentas> &A);
void skirstymas1(Vector<studentas> &A, Vector<studentas> &K, Vector<studentas> &V);
void skirstymas2(Vector<studentas> &A, Vector<studentas> &V);
void skirstymas3(Vector<studentas> &A, Vector<studentas> &K, Vector<studentas> &V);
void irasymasifailaK(Vector<studentas> &A, Vector<studentas> &K, Vector<studentas> &V, char budas, int skistr);

#endif // FUNCTIONS_H