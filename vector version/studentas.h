#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class studentas {
// realizacija
private:
  string vardas;
  string pavarde;
  vector<int> ndrez;
  int erez;
  double gbalas;
  // interfeisas
  public:
      studentas(); // default konstruktorius
      studentas(const string& v, const string& p, const vector<int>& nd, int e, double g);

      string getVardas() const { return vardas; }                   // get'eriai
      string getPavarde() const { return pavarde; }                 // get'eriai
      vector<int> getNdrez() const { return ndrez; }
      int getErez() const { return erez; }
      double getGbalas() const { return gbalas; } // get'eriai
      
      void setVardas(const string& v) { vardas = v; }
      void setPavarde(const string& p) { pavarde = p; }
      void setNdrez(const vector<int>& nd) { ndrez = nd; }
      void setErez(int e) { erez = e; }
      void setGbalas(double g) { gbalas = g; }                     // set'eriai

      void sortNdrez() {
    sort(ndrez.begin(), ndrez.end());
}
      ~studentas() { ndrez.clear(); }
      
};
#endif // STUDENTAS_H
