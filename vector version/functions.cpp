#include "functions.h"
#include "errorfinder.h"
#include "studentas.h"

int tlaikas = 0;

void skaitymasisfailo(vector<studentas> &A, char budas, char ivedbudas) {
    int tlaikas = 0;
    auto start = high_resolution_clock::now();
    
    try {
        ifstream in("studentai10000000.txt");
        if (!in.is_open()) {
            throw runtime_error("Nepavyko atidaryti failo.");
        }

        string eil;
        getline(in, eil); // Skip the header line

        while (getline(in, eil)) {
            studentas new_studentas;
            int sum = 0;
            int egzas = 0;
            string var;
            string pav;
            istringstream my_buffer(eil);

            if (ivedbudas == 1) {

                my_buffer >> var >> pav;
                new_studentas.setVardas(var);
                new_studentas.setPavarde(pav);
                int pazymys;
                vector<int> pazymysVector;
                while (my_buffer >> pazymys)
                {
                pazymysVector.push_back(pazymys); // prisikiriamas elSementas
                sum += pazymys;
                }

                new_studentas.setErez(pazymysVector.back());
                pazymysVector.pop_back();
                new_studentas.setNdrez(pazymysVector);
                skaiciavimas(new_studentas, sum, budas);
                
            } else if (ivedbudas == 2) {
                pazymiuived(new_studentas, budas, ivedbudas);
            }

            A.push_back(new_studentas);
        }

        in.close();
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);

        cout << "Reading from file took: " << duration.count() << " milliseconds" << endl;
        tlaikas += duration.count();
    } catch (const runtime_error &e) {
        cerr << e.what() << endl;
        exit(EXIT_FAILURE);
    }
}

void irasymasifaila(vector<studentas> &A, char budas)
{
    auto start = high_resolution_clock::now(); 
    ofstream out("kursiokai.txt");
    ostringstream buffer;
    if (budas == 'v')
    {
        buffer << setw(25) << left << "Vardas" << setw(25) << left << "Pavarde" << setw(25) << left << "Galutinis (Vid.)" << endl;
    }
    else if (budas=='m'){
         buffer << setw(25) << left << "Vardas" << setw(25) << left << "Pavarde" << setw(25) << left << "Galutinis (Med.)" << endl;}
    buffer << "---------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < A.size(); i++)
    {
        buffer << setw(25) << left << A[i].getVardas() << setw(25) << left << A[i].getPavarde() << setw(25) << left << fixed << setprecision(2) << A[i].getGbalas() << endl;
    }
    out << buffer.str(); 
    out.close();
    auto stop = high_resolution_clock::now(); // Stop measuring time
    auto duration = duration_cast<milliseconds>(stop - start); 
    cout << "Writing to file took: " << duration.count() << " milliseconds" << endl;
    tlaikas += duration.count();
}

void isvedimas(vector<studentas> &A, char budas)
{
    char isvedbud;
    isvedbud = isvedbudpatikra();
    if (isvedbud == 'e')
    {
        if (budas == 'v')
        {
            cout << setw(25) << left << "Vardas" << setw(25) << left << "Pavarde" << setw(25) << left << "Galutinis (Vid.)" << endl;
        }
        else if (budas == 'm')
        {
            cout << setw(25) << left << "Vardas" << setw(25) << left << "Pavarde" << setw(25) << left << "Galutinis (Med.)" << endl;
        }
        cout << "---------------------------------------------------------------------------------------------------" << endl;
        for (int i = 0; i < A.size(); i++)
        {
            cout << setw(25) << left << A[i].getVardas() << setw(25) << left << A[i].getPavarde() << setw(25) << left << fixed << setprecision(2) << A[i].getGbalas() << endl;
        }
    }
    else if (isvedbud == 'f')
    {
        irasymasifaila(A, budas);
    }
}

void pazymiuived(studentas &new_studentas, char budas, int ivedbudas)
{
    int sum = 0;
    vector<int> pazymysVector;
    int pazymys;
    if (ivedbudas == 1){
        cout << "Iveskite studento namu darbu rezultata arba „11“, jeigu norite uzbaigti rezultatu vedima: " << endl;}
    
    while (true)
    {
        if (ivedbudas == 1)
        {
            pazymys = pazymiopatikra();
            if (pazymys == 11)
            {
                break;
            }                
        }

        if (ivedbudas == 2 || ivedbudas == 3)
        {
            pazymys = rand() % 12;
            if (pazymys == 11) {
                break;}
        }
        pazymysVector.push_back(pazymys); // pridedamas elementas i gala
        sum += pazymys;
    }
    if (ivedbudas == 1)
    {
        new_studentas.setErez(erezpatikra());
    }

    if (ivedbudas == 2 || ivedbudas == 3)
    {
        new_studentas.setErez(rand() % 11);
    }
    new_studentas.setNdrez(pazymysVector);
    skaiciavimas(new_studentas, sum, budas);
}

void skaiciavimas(studentas &new_studentas, int sum, char budas)
{
    auto start = high_resolution_clock::now(); 
    double vid, mediana;
    double galrez = 0;
    int tempsize = new_studentas.getNdrez().size();
    if (tempsize == 0)
    {
        vid = 0;
        mediana = 0;
    }
    else 
    {
        vid = sum / ((double)tempsize);
            
        new_studentas.sortNdrez();
        if (tempsize % 2 == 0) {
            mediana = (new_studentas.getNdrez().at(tempsize / 2 - 1) + new_studentas.getNdrez().at(tempsize / 2)) / 2.0;}
        else {
            mediana = new_studentas.getNdrez().at(tempsize / 2);}
    }

    if (budas == 'v')
    {
        galrez = 0.4 * vid + 0.6 * new_studentas.getErez();
    }
    else if (budas == 'm')
    {
        galrez = 0.4 * mediana + 0.6 * new_studentas.getErez();
    }
    sum = 0;
    new_studentas.setGbalas(galrez);
    auto stop = high_resolution_clock::now(); // Stop measuring time
    auto duration = duration_cast<milliseconds>(stop - start); 
    tlaikas += duration.count();
}

bool rikiavimasgbalas(const studentas &a, const studentas &b)
{
    return a.getGbalas() > b.getGbalas();
}

bool rikiavimasvardas(const studentas &a, const studentas &b)
{
    return a.getVardas() < b.getVardas();
}

bool rikiavimaspavarde(const studentas &a, const studentas &b)
{
    return a.getPavarde() < b.getPavarde();
}

void rikiavimas(vector<studentas> &A)
{
    char rikbudas;
    rikbudas = rikbudpatikra();
    auto start = high_resolution_clock::now(); 
    if (rikbudas == 'b')
    {
        sort(A.begin(), A.end(), rikiavimasgbalas);
    }
    else if (rikbudas == 'v') {sort(A.begin(), A.end(), rikiavimasvardas);}
    else if (rikbudas == 'p') {sort(A.begin(), A.end(), rikiavimaspavarde);}
    auto stop = high_resolution_clock::now(); // Stop measuring time
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Rūšiavimas (sort) truko: " << duration.count() << " miliseconds" << endl;
    tlaikas += duration.count();
}

//1 strategija
void skirstymas1(vector<studentas> &A, vector<studentas> &K, vector<studentas> &V)
{
    auto start = high_resolution_clock::now();
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i].getGbalas() >= 5.0)
        {
            K.push_back(A[i]);
        }
        if (A[i].getGbalas() < 5.0)
        {
            V.push_back(A[i]);
        }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "Studentų skirstymas užtruko: " << duration.count() << " milliseconds" << endl;
    tlaikas += duration.count();
}

//2 strategija
void skirstymas2(vector<studentas> &A, vector<studentas> &V)
{
    sort(A.begin(), A.end(), rikiavimasgbalas);
    auto start = high_resolution_clock::now();
    for (int i = A.size()-1; i >= 0; i--)
    {
        if (A[i].getGbalas() < 5.0)
        {
            V.push_back(A[i]);
            A.pop_back();
        }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "Studentų skirstymas užtruko: " << duration.count() << " milliseconds" << endl;
    tlaikas += duration.count();
}

//3 strategija
void skirstymas3(vector<studentas> &A, vector<studentas> &K, vector<studentas> &V)
{
    auto start = high_resolution_clock::now();

    auto partition_point = partition(A.begin(), A.end(), [](const studentas& s) {
        return s.getGbalas() >= 5.0;
    });

    transform(A.begin(), partition_point, back_inserter(K), [](const studentas& s) {
        return s;
    });

    transform(partition_point, A.end(), back_inserter(V), [](const studentas& s) {
        return s;
    });

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "Studentų skirstymas užtruko: " << duration.count() << " milliseconds" << endl;
    tlaikas += duration.count();
}

void irasymasifailaK(vector<studentas> &A, vector<studentas> &K, vector<studentas> &V, char budas, int skistr)
{
    auto start = high_resolution_clock::now(); 
    ofstream outK("kietiakai.txt");
    ostringstream bufferK;
    if (budas == 'v')
    {
        bufferK << setw(25) << left << "Vardas" << setw(25) << left << "Pavarde" << setw(25) << left << "Galutinis (Vid.)" << endl;
    }
    else if (budas=='m'){
         bufferK << setw(25) << left << "Vardas" << setw(25) << left << "Pavarde" << setw(25) << left << "Galutinis (Med.)" << endl;}
    bufferK << "---------------------------------------------------------------------------------------------------" << endl;
    //1 strategija
    if (skistr == 1 || skistr == 3)
    {
        for (int i = 0; i < K.size(); i++)
        {
            bufferK << setw(25) << left << K[i].getVardas() << setw(25) << left << K[i].getPavarde() << setw(25) << left << fixed << setprecision(2) << K[i].getGbalas() << endl;
        }
    }
    //2 strategija
    if (skistr == 2)
    {
        for (int i = 0; i < A.size(); i++)
        {
            bufferK << setw(25) << left << A[i].getVardas() << setw(25) << left << A[i].getPavarde() << setw(25) << left << fixed << setprecision(2) << A[i].getGbalas() << endl;
        }
    }
    outK << bufferK.str();
    outK.close();
    bufferK.clear();
    ofstream outV("vargsiukai.txt");
    ostringstream bufferV;
    if (budas == 'v')
    {
        bufferV << setw(25) << left << "Vardas" << setw(25) << left << "Pavarde" << setw(25) << left << "Galutinis (Vid.)" << endl;
    }
    else if (budas=='m'){
         bufferV << setw(25) << left << "Vardas" << setw(25) << left << "Pavarde" << setw(25) << left << "Galutinis (Med.)" << endl;}
    bufferV << "---------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < V.size(); i++)
    {
        bufferV << setw(25) << left << V[i].getVardas() << setw(25) << left << V[i].getPavarde() << setw(25) << left << fixed << setprecision(2) << V[i].getGbalas() << endl;
    }
    outV << bufferV.str();
    outV.close();
    bufferV.clear();
    auto stop = high_resolution_clock::now(); // Stop measuring time
    auto duration = duration_cast<milliseconds>(stop - start); 
    cout << "Writing to file took: " << duration.count() << " milliseconds" << endl;
    tlaikas += duration.count();
    cout << "Programos vykdymo laikas: " << tlaikas << " milliseconds" << endl;
}