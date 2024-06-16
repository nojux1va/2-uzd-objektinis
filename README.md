# objektinis-programavimas
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

![image](https://github.com/RokGis/antra-uzd/assets/147180109/f07d41b6-ba3d-48e7-924b-5c2bf3519270)

![att -JquttUXDyGpHpel21yB5OPPZXtgGpfVgU0DJ4P36d0](https://github.com/RokGis/antra-uzd/assets/147180109/20d710f2-1e66-4bf0-8293-3bc21d2095b7)

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

