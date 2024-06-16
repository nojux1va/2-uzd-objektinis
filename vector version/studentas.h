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
    string line;
    studentas(); // default konstruktorius
    studentas(const string &v, const string &p, const vector<int> &nd, int e, double g);

    ~studentas(); // destruktorius

    studentas(const studentas &kit); // copy konstruktorius

    studentas &operator=(const studentas &kit); // priskyrimo operatorius

    studentas(studentas &&kit) noexcept; // move konstruktorius

    studentas &operator=(studentas &&kit) noexcept;

friend std::istream &operator>>(std::istream &in, studentas &kit){
  kit.ndrez.clear();
  int sum = 0;
  int egzas = 0;
  istringstream my_buffer(kit.line);

  my_buffer >> kit.vardas >> kit.pavarde;
  int pazymys;
  while (my_buffer >> pazymys)
  {
    kit.ndrez.push_back(pazymys); // prisikiriamas elSementas
    sum += pazymys;
                }

                kit.erez = kit.ndrez.back();
                kit.ndrez.pop_back();
                sum -= kit.erez;
                kit.gbalas = sum;
                return in;
}

    friend std::ostream &operator<<(std::ostream &out, const studentas &kit)
   {
        out << setw(21) << left << kit.vardas << setw(21) << left << kit.pavarde << setprecision(3) << left << kit.gbalas << '\n';
        return out;
  }

    string getVardas() const { return vardas; }   // get'eriai
    string getPavarde() const { return pavarde; } // get'eriai
    vector<int> getNdrez() const { return ndrez; }
    int getErez() const { return erez; }
    double getGbalas() const { return gbalas; } // get'eriai

    void setVardas(const string &v) { vardas = v; }
    void setPavarde(const string &p) { pavarde = p; }
    void setNdrez(const vector<int> &nd) { ndrez = nd; }
    void setErez(int e) { erez = e; }
    void setGbalas(double g) { gbalas = g; } // set'eriai

    void sortNdrez() { sort(ndrez.begin(), ndrez.end()); }

  
};

#endif // STUDENTAS_H