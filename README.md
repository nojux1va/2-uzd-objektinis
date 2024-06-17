# objektinis-programavimas
### Diegimas:
1. Atsisiųskite projekto zip failą.
2. Išskleiskite zip failą kompiuteryje.
3. Atidarykite ProgramInstallSetup aplanką.
4. Paleiskite ProgramInstallSetup.msi arba setup.exe failą.
5. Sekite diegimo instrukcijas.
6. Programos ikonėlė rasite ant darbalaukio (Desktop) ir prie „Start“ programėlių. Gero naudojimosi!
### Naudotojo sąveikos vadovas:

1. **Pasirinkimas Sugeneruoti arba Nuskaityti Failą su Studentais:**
   - `t`: Taip
   - `n`: Ne
   - **Pastaba:** Jei taip, įveskite studentų skaičių ir namų darbų pažymių skaičių.

2. **Pasirinkite Duomenų Įvedimo Metodą:**
   Naudotojai pasirenka vieną iš keturių variantų:
   - `1`: Rankiniu būdu įvesti arba nuskaityti duomenis iš failo.
   - `2`: Rankiniu būdu įvesti vardus, o pažymius sugeneruoti atsitiktinai.
   - `3`: Sugeneruoti vardus ir pažymius atsitiktinai.
   - `4`: Baigti programą.

3. **Pasirinkite Skaičiavimo Metodą:**
   Variantams 1, 2 ir 3, naudotojai turi pasirinkti galutinių rezultatų skaičiavimo metodą:
   - `v`: Namų darbų pažymių vidurkis.
   - `m`: Namų darbų pažymių mediana.

4. **Įveskite Studentų Duomenis:**
   - Variantams 1 ir 2: Pasirinkite įvedimo metodą (`r` rankiniu būdu, `f` iš failo). Jei pasirenkate rankinį įvedimą (`r`), įveskite studentų vardus ir pavardes. Norėdami sustabdyti, įveskite "11".
   - Variantui 3: Įveskite studentų skaičių.

5. **Įveskite arba Sugeneruokite Pažymius:**
   - Variantui 1: Jei pasirenkate rankinį įvedimą (`r`), įveskite kiekvieno studento namų darbų pažymius ir galutinį egzamino rezultatą. Norėdami sustabdyti įvedimą, įveskite "11".
   - Variantams 2 ir 3: Pažymiai sugeneruojami automatiškai.

6. **Pasirinkite Duomenų Rūšiavimo Tipą:**
   - `g`: Rūšiuoti pagal galutinius rezultatus.
   - `v`: Rūšiuoti pagal vardus.
   - `p`: Rūšiuoti pagal pavardes.

7. **Pasirinkite Padalinti Studentus į Dvi Grupes Pagal Galutinį Rezultatą:**
   - `t`: Taip
   - `n`: Ne

8. **Jei Naudotojas Pasirinko Neskirstyti Studentų:**
   Pasirinkite Studentų Duomenų Išvesties Metodą:
   - `e`: Išvesti ekrane.
   - `f`: Rašyti duomenis į failą.

### Instrukcijos naudoti Makefile:

1. **Atidarykite Terminalą:**
   Atidarykite terminalą arba komandinę eilutę savo sistemoje.

2. **Naršykite į Projekto Katalogą:**
   Naudodami `cd` komandą, naršykite į savo projekto katalogą, kuriame turite Makefile ir jūsų šaltinių failus.

3. **Sukompiliuokite Programą:**
   Įveskite `make` terminale ir spauskite Enter, kad sukompiliuotumėte programą. Ši komanda sukompiliuos visus `.cpp` ir `.h` failus į vykdomąjį failą, kuris bus pavadintas `main`.

4. **Paleiskite Programą:**
   Po kompiliavimo įveskite `./main` terminale ir spauskite Enter, kad sukompiliuotumėte ir paleistumėte programą. Ši komanda kompiliuos programą (jei dar nekompiliuota) ir tada ją paleis.

5. **Tvarkykite:**
   Jei norite pašalinti sukompiliuotą vykdomąjį failą, įveskite `make clean` terminale ir spauskite Enter. Ši komanda pašalins `main` vykdomąjį failą iš jūsų projekto katalogo.

Pastaba: Įsitikinkite, kad jūsų sistemoje įdiegta GNU Make paslauga, kad galėtumėte naudoti Makefile komandas. Taip pat atkreipkite dėmesį, kad Makefile, `.cpp` bei `.h` failai būtų viename (projekte) aplanke.

![image](https://github.com/RokGis/antra-uzd/assets/147180109/833d2f67-f0d1-4b6e-affe-46d7bfba3df9)

![image](https://github.com/RokGis/antra-uzd/assets/147180109/bf1db5bb-9c75-438b-afa8-e2e74fde9dfe)

![image](https://github.com/RokGis/antra-uzd/assets/147180109/28a4c4c1-2a30-4515-b291-972d9ec3e3e7)

![image](https://github.com/RokGis/antra-uzd/assets/147180109/1dfb0a65-3f4c-4dd4-a183-fcaf34827e60)

![image](https://github.com/RokGis/antra-uzd/assets/147180109/496c428d-85eb-44f8-bb2e-87f3257c970a)

<img width="837" alt="image" src="https://github.com/RokGis/antra-uzd/assets/147180109/6f98a71f-cabd-4091-a07f-426e74a93cc0">


# Duomenų Įvedimas ir Išvedimas

## Įvestis

Klasėje `studentas` naudojami perdengti įvesties operatoriai, leidžiantys įvesti duomenis įvairiais būdais:

1. **Rankiniu būdu**: Vartotojas gali įvesti studento duomenis rankiniu būdu, naudojant standartinį įvesties srautą (`std::istream`).
2. **Automatiniu būdu**: Automatizuotą įvestį galima atlikti per kodą, perduodant duomenis tiesiogiai į konstruktorių arba naudojant set'erio metodus.
3. **Iš failo**: Įvesties duomenys gali būti nuskaityti iš failo, skaitant failo turinį į `std::ifstream` ir naudojant tą patį perdengtą operatorių `>>`.

## Išvestis

Duomenys gali būti išvedami į skirtingus tikslus:

1. **Į ekraną**: Naudojant standartinį išvesties srautą (`std::ostream`), galima išvesti studento duomenis į konsolę.
2. **Į failą**: Naudojant `std::ofstream`, duomenys gali būti išvesti į failą, taikant tą patį perdengtą operatorių `<<`.

