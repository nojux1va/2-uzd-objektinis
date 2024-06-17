#ifndef STUDENTAS_H
#define STUDENTAS_H

#include "zmogus.h"
#include "vector.h"
#include "errorfinder.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

class studentas : public zmogus {
private:
  Vector<int> ndrez;
  int erez;
  double gbalas;
  // interfeisas
  public:
    string line;
    char budas;
    studentas(); // default konstruktorius
    studentas(const string &v, const string &p, const Vector<int> &nd, int e, double g);

    ~studentas(); // destruktorius

    studentas(const studentas &kit); // copy konstruktorius

    studentas &operator=(const studentas &kit); // priskyrimo operatorius

    studentas(studentas &&kit) noexcept; // move konstruktorius

    studentas &operator=(studentas &&kit) noexcept;

friend std::istream &operator>>(std::istream &in, studentas &kit){
  kit.ndrez.clear();
  int sum = 0;

    if(kit.budas == 'f'){
      istringstream my_buffer(kit.line);

      my_buffer >> kit.vardas >> kit.pavarde;
      int pazymys;
      while (my_buffer >> pazymys)
      {
        kit.ndrez.push_back(pazymys); // prisikiriamas elSementas
        sum += pazymys;
      }

      if (!kit.ndrez.empty()) {
        kit.erez = kit.ndrez.back();
        kit.ndrez.pop_back();
        sum -= kit.erez;
    }
    kit.gbalas = sum;}
    if(kit.budas == 'r')
    {
      cout << "Iveskite studento varda ir pavarde arba „11“, jeigu norite uzbaigti studentu vedima: ";
      in >> kit.vardas;
      if (kit.vardas != "11")
      {
        in >> kit.pavarde;
      }
    }
    return in;
  }

    friend std::ostream &operator<<(std::ostream &out, const studentas &kit)
   {
        out << setw(25) << left << kit.vardas << setw(25) << left << kit.pavarde << setprecision(3) << left << kit.gbalas << '\n';
        return out;
  }

    string getVardas() const { return vardas; }   // get'eriai
    string getPavarde() const { return pavarde; } // get'eriai
    Vector<int> getNdrez() const { return ndrez; }
    int getErez() const { return erez; }
    double getGbalas() const { return gbalas; } // get'eriai

    void setVardas(const string &v) { vardas = v; }
    void setPavarde(const string &p) { pavarde = p; }
    void setNdrez(const Vector<int> &nd) { ndrez = nd; }
    void setErez(int e) { erez = e; }
    void setGbalas(double g) { gbalas = g; } // set'eriai

    void sortNdrez() { sort(ndrez.begin(), ndrez.end()); }

  
};

#endif // STUDENTAS_H