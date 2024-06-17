#ifndef ZMOGUS_H
#define ZMOGUS_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class zmogus {
    protected:
      string vardas;
        string pavarde;
public:
    virtual ~zmogus(){};
    virtual string getVardas() const = 0;
    virtual void setVardas(string v) { vardas = v; }

    virtual string getPavarde() const = 0;
    virtual void setPavarde(string p) { pavarde = p; }
};

#endif // ZMOGUS_H