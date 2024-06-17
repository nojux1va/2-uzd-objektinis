#include "functions.h"
#include "errorfinder.h"
#include"filegenerator.h"
#include "studentas.h"
#include "vector.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

void testCopyConstruction() {
    studentas original("Rokas", "Gilys", {5, 6, 7}, 8, 5);
    studentas copy(original);
    std::cout << "Copy construction test:" << std::endl;
    std::cout << "Original: " << original << std::endl;
    std::cout << "Copy: " << copy << std::endl;
}

void testMoveConstruction() {
    studentas original("Liudas", "Vasaris", {5, 6, 7}, 8, 5);
    
    studentas moved(std::move(original));
    
    std::cout << "Move construction test:" << std::endl;
    std::cout << "Original (after move): " << original << std::endl;
    std::cout << "Moved: " << moved << std::endl;
}

void testCopyAssignment() {
    studentas original("Jonas", "Kazlauskas", {5, 6, 7}, 8, 5);
    studentas copy("Bronislovas", "Jonskis", {5, 6, 7}, 8, 4);

    copy = original;
    
    std::cout << "Copy assignment test:" << std::endl;
    std::cout << "Original: " << original << std::endl;
    std::cout << "Copy (after assignment): " << copy << std::endl;
}

void testMoveAssignment() {
    studentas original("Kazys", "Grinius", {5, 6, 7}, 8, 5);
    studentas moved("Antanas", "Smetona", {5, 6, 7}, 8, 5);
    
    moved = std::move(original);
    
    std::cout << "Move assignment test:" << std::endl;
    std::cout << "Original (after move): " << original << std::endl;
    std::cout << "Moved (after assignment): " << moved << std::endl;
}

int main()
{
    // testCopyConstruction();
    // testMoveConstruction();
    // testCopyAssignment();
    // testMoveAssignment();

        // size_t reallocations_v1 = 0;
    // auto start_v1 = high_resolution_clock::now(); // Pradėti v1 užpildymo laiko matavimą
    // unsigned int sz = 100000000;  // 100000, 1000000, 10000000, 100000000
    // vector<int> v1;
    // for (int i = 1; i <= sz; ++i){
    //     v1.push_back(i);
    //     if (v1.size() == v1.capacity()) {
    //         ++reallocations_v1;
    //     }
    //     }
    // auto stop_v1 = high_resolution_clock::now();
    // auto duration_v1 = duration_cast<microseconds>(stop_v1 - start_v1);
    // cout << "std::vector pildymas truko: " << duration_v1.count() << " microseconds" << endl;
    // cout << "std::vector atminties perskirstymai: " << reallocations_v1 << endl; // Baigti v1 užpildymo laiko matavimą
    
    // auto start_v2 = high_resolution_clock::now(); // Pradėti v2 užpildymo laiko matavimą
    // Vector<int> v2;
    // for (int i = 1; i <= sz; ++i)
    //     v2.push_back(i);
    // auto stop_v2 = high_resolution_clock::now();
    // auto duration_v2 = duration_cast<microseconds>(stop_v2 - start_v2);
    // cout << "Vector pildymas truko: " << duration_v2.count() << " microseconds" << endl;
    // cout << "Vector atminties perskirstymai: " << v2.getReallocationCount() << endl; // Baigti v2 užpildymo laiko matavimą 

    // studentas B;
    // B.budas = 'r';
    // cin >> B;
    // cout << B;


    vector<std::string> vardai = {"Jonas", "Vytautas", "Tomas", "Mindaugas", "Antanas", "Darius", "Rokas", "Matas", "Lukas"};

    vector<std::string> pavardes = {"Kazlauskas", "Jankauskas", "Petrauskas", "Stankevicius", "Vasiliauskas", "Vaigauskas", "Gilys", "Gavenas", "Gruodis"};

    srand(time(nullptr));

    string vardas;
    string pavarde;
    failugeneravimas();
    int ivedbudas;
    ivedbudas = ivedbudpatikra();

    if (ivedbudas != 4)
    {
        char budas;
        budas = budaspatikra();
        char duomskait;
        if (ivedbudas == 1 || ivedbudas == 2){
            duomskait = dskaitpatikra();
        }
        char ski;
        int skistr;

        Vector<studentas> A; //sudaromas vektorius
        Vector<studentas> K; 
        Vector<studentas> V; 

        if ((ivedbudas == 1 || ivedbudas == 2) && duomskait == 'f')
        {
            skaitymasisfailo(A, budas, ivedbudas);
            rikiavimas(A);
            ski = skirstymopatikra();
            if (ski == 't')
            {
                skistr = skirststratpat();
                if (skistr == 1) {skirstymas1(A, K, V);}
                if (skistr == 2) {skirstymas2(A, V);}
                if (skistr == 3) {skirstymas3(A, K, V);}
                irasymasifailaK(A, K, V, budas, skistr);
            }
            else if (ski == 'n')
            {
                isvedimas(A, budas);
            }
            
        }

        else if ((ivedbudas == 1 || ivedbudas == 2) && duomskait == 'r')
        {
            while (true)
            {
                studentas new_studentas;
                new_studentas.budas = duomskait;
                cin >> new_studentas;
                if (new_studentas.getVardas() == "11")
                {
                    break;
                }
                pazymiuived(new_studentas, budas, ivedbudas);
                A.push_back(new_studentas); // pridedamas elementas i gala 
            }
            rikiavimas(A);
            ski = skirstymopatikra();
            if (ski == 't')
            {
                skistr = skirststratpat();
                if (skistr == 1) {skirstymas1(A, K, V);}
                if (skistr == 2) {skirstymas2(A, V);}
                if (skistr == 3) {skirstymas3(A, K, V);}
                irasymasifailaK(A, K, V, budas, skistr);
            }
            else if (ski == 'n')
            {
                isvedimas(A, budas);
            }
        }
        
        if (ivedbudas == 3)
        {
            int m;
            cout << "Iveskite studentu skaiciu: ";
            m = studskpatikra();

            A.resize(m); // nustatyti vektoriaus dydi

            for (int i = 0; i < m; i++)
            {
                studentas new_studentas;
                new_studentas.setVardas(vardai[rand() % vardai.size()]);
                new_studentas.setPavarde(pavardes[rand() % pavardes.size()]);
                pazymiuived(new_studentas, budas, ivedbudas);
                A[i] = new_studentas;
            }
            rikiavimas(A);
            ski = skirstymopatikra();
            if (ski == 't')
            {
                skistr = skirststratpat();
                if (skistr == 1) {skirstymas1(A, K, V);}
                if (skistr == 2) {skirstymas2(A, V);}
                if (skistr == 3) {skirstymas3(A, K, V);}
                irasymasifailaK(A, K, V, budas, skistr);
            }
            else if (ski == 'n')
            {
                isvedimas(A, budas);
            }
        }
    }
    else {return 0;}
    return 0;
}