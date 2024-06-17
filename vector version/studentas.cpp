#include "studentas.h"
#include <utility>

studentas::studentas() : erez(0), gbalas(0.0) {}


studentas::studentas(const string& v, const string& p, const Vector<int>& nd, int e, double g)
    : zmogus(), ndrez(nd), erez(e), gbalas(g) {
    setVardas(v);
    setPavarde(p);
}

// destruktorius
studentas::~studentas() {
ndrez.clear();}

// copy konstruktorius
studentas::studentas(const studentas& kit) 
    : zmogus(kit), ndrez(kit.ndrez), erez(kit.erez), gbalas(kit.gbalas) {}

// priskyrimo operatorius
studentas& studentas::operator=(const studentas& kit) {
    if (this != &kit) {
        zmogus::operator=(kit);
        ndrez = kit.ndrez;
        erez = kit.erez;
        gbalas = kit.gbalas;
    }
    return *this;
}

// move konstruktorius
studentas::studentas(studentas&& kit) noexcept
    : zmogus(std::move(kit)), ndrez(std::move(kit.ndrez)), erez(kit.erez), gbalas(kit.gbalas) {         
        vardas = std::move(kit.vardas);
        pavarde = std::move(kit.pavarde);
        ndrez = std::move(kit.ndrez);
        kit.erez = 0;
        kit.gbalas = 0;}

// priskyrimo operatorius
studentas& studentas::operator=(studentas&& kit) noexcept {
    if (this != &kit) {
        vardas = std::move(kit.vardas);
        pavarde = std::move(kit.pavarde);
        ndrez = std::move(kit.ndrez);
        erez = kit.erez;
        gbalas = kit.gbalas;
        kit.erez = 0;
        kit.gbalas = 0;
    }
    return *this;
}
