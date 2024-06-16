#include "studentas.h"

studentas::studentas() : erez(0), gbalas(0.0) {}

studentas::studentas(const string& v, const string& p, const vector<int>& nd, int e, double g)
    : vardas(v), pavarde(p), ndrez(nd), erez(e), gbalas(g) {}