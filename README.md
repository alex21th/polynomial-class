# Classe Polinomis

La classe Polinomis emmagatzema un polinomi de grau n​ amb coeficients reals i proporciona algunes operacions útils sobre ell.

### Implementació

La creació d’un polinomi es realitza mitjançant una string amb el següent format:

1. Els monomis del polinomi s’han d’introduir en ordre decreixent segons el grau

2. Tot monomi es compon d’un coeficient real seguit dels caràcters "x^" i un número enter

   > ex.   3x^4 -6x^3 +2x^2 +1x^1 -9x^0

**ATENCIÓ!**

1. És imprescindible afegir els caràcters “x^” en els monomis de grau 1 i 0

   >ex.   -4x^1 +3x^0

2. És imprescindible afegir el coeficient ‘1’, si escau, en els monomis

   > ex.   1x^2 +1x^1 +1x^0

3. No és necessari introduir els monomis de coeficient nul

### Funcions sobre la classe Polinomis

- `def [nom] [polinomi]` crea un polinomi P a partir d'una string

  > ex.   def P 1x^4 -2x^3 -11.51x^2 +30x^1 -20x^0
  >
  > ex.   def Q 1x^2 +3x^1 -2x^0

- `veure [nom]` retorna la representació, amb el format corresponent, del polinomi P

  > ex.   veure P

- `vect [nom]` retorna el polinomi P en forma de vector (les seves components)

  > ex.   vect P

- `grau [nom]` retorna el grau del polinomi P

  > ex.   grau P

- `aval [nom] [punt]` avalua el polinomi P en un punt donat x

  > ex.   aval P -1.5

- `modif [nom] [grau] [coef]` modifica el monomi de grau n del polinomi P pel coeficient x

  > ex.   modif P 2 -11

- `monomi [nom] [grau]` retorna el coeficient del monomi de grau donat n del polinomi P

  > ex.   monomi P 2

- `suma [nom] [nom] [nom]` emmagatzema en R la suma del polinomi P i el polinomi Q

  > ex.   suma R P Q

- `resta [nom] [nom] [nom]` emmagatzema en R la resta del polinomi P i el polinomi Q

  > ex.   resta R P Q

- `prod [nom] [nom] [nom]` emmagatzema en R el producte del polinomi P i el polinomi Q

  > ex.   prod R P Q

- `divi [nom] [nom] [nom]` emmagatzema en R la divisió del polinomi P i el polinomi Q

  > ex.   divi R P Q

- `mcd [nom] [nom] [nom]` emmagatzema en R el màxim como divisor del polinomi P i el polinomi Q

  > ex.   mcd R P Q

### Fitxers i llibreries

#### Estructura dels fitxers

- `main.cc`
  - Joc de proves i demostració interactiva de l'ús de la classe Polinomis

- `Polinomi.cc`
  - Funcions externes utilitzades en la implementació de la clase Polinomi
  - Funcions utilitzades en l'algorisme de la FFT (Fast Fourier Transform)
  - Implementació de la classe Polinomi

- `Polinomi.hh`
  - Header file amb els constructors i les declaracions de les funcions

#### Llibreries i dependències

`<iostream>` , `<sstream>` , `<string>` , `<vector>` , `<complex>` , `<cmath>` , `<map>`