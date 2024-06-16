#include "functions.h"
#include "errorfinder.h"
#include"filegenerator.h"
#include "studentas.h"

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
    std::cout << "Original (after move): " << original << std::endl; // Should be in unspecified state
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
    std::cout << "Original (after move): " << original << std::endl; // Should be in unspecified state
    std::cout << "Moved (after assignment): " << moved << std::endl;
}

int main()
{
    testCopyConstruction();
    testMoveConstruction();
    testCopyAssignment();
    testMoveAssignment();
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

        vector<studentas> A; //sudaromas vektorius
        vector<studentas> K; 
        vector<studentas> V; 

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
                cout << "Iveskite studento varda ir pavarde arba „11“, jeigu norite uzbaigti studentu vedima: ";
                cin >> vardas;
                if (vardas == "11"){
                    break;}
                new_studentas.setVardas(vardas);
                cin >> pavarde;
                new_studentas.setPavarde(pavarde);
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