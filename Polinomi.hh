/*
  ________________________
 /\                       \
 \_|  CLASSE de POLINOMIS |
   |                      |
   |      Polinomi.hh     |
   |   ___________________|_
    \_/_____________________/
*/
#ifndef Polinomi_hh
#define Polinomi_hh

#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
========================================================================
La classe Polinomis emmagatzema un polinomi de grau n amb coeficients
reals i proporciona algunes operacions útils sobre ell.
········································································
  IMPLEMENTACIÓ:

  La creació d’un polinomi es realitza mitjançant una string amb el
  següent format:

    1.  Els monomis del polinomi s’han d’introduir en ordre decreixent
        segons el grau.

    2.  Tot monomi es compon d’un coeficient real seguit dels caràcters
        "x^" i un número enter.

    ex.   3x^4 -6x^3 +2x^2 +1x^1 -9x^0

    ATENCIÓ!

    1.  És imprescindible afegir els caràcters “x^” en els monomis
        de grau 1 i 0.

          ex.   -4x^1 +3x^0

    2.  És imprescindible afegir el coeficient ‘1’, si escau, en els
        monomis.

          ex.   1x^2 +1x^1 +1x^0

    3.  No és necessari introduir els monomis de coeficient nul.

========================================================================
*/
class Polinomi {

  public:

    // CONSTRUCTOR #1: Crea un polinomi a partir d'una string 's'
    // (ex. 2x^3 -3x^2 +5x^1 +8x^0).
    Polinomi (const string& s);

    // CONSTRUCTOR #2: Crea un polinomi a partir d'un vector 'vect'
    // (s'utilitza únicament per a realitzar operacions i càlculs).
    Polinomi (const vector<double>& vect = {0});

    // Retorna la representació en string, amb el format corresponent,
    // d'aquest polinomi.
    string veure () const;

    // Retorna aquest polinomi en forma de vector (les seves components).
    vector<double> veure_vector () const;

    // Retorna el grau d'aquest polinomi.
    int grau () const;

    // Avalua aquest polinomi en un punt donat 'x'.
    double avalua (const double x) const;

    // Retorna el coeficient del monomi de grau donat 'n' d'aquest polinomi.
    double monomi (int n = 0) const;

    // Modifica el monomi de grau 'n' d'aquest polinomi pel coeficient 'x'.
    void modifica (int n = 0, double x = 0);

    // Elimina els monomis nuls (iguals a 0) d'aquest polinomi.
    void normalitza();

    // Retorna la suma d'aquest polinomi amb el polinomi donat 'Q'.
    Polinomi operator+ (const Polinomi& Q) const;

    // Retorna la diferència d'aquest polinomi amb el polinomi donat 'Q'.
    Polinomi operator- (const Polinomi& Q) const;

    // Retorna el producte d'aquest polinomi amb el polinomi donat 'Q'.
    Polinomi operator* (const Polinomi& Q) const;

    // Retorna la divisó d'aquest polinomi amb el polinomi donat 'Q'.
    Polinomi operator/ (const Polinomi& Q) const;

    // Divideix aquest polinomi entre el polinomi 'B' i emmagatzema
    // el quocient en 'Q' i el residu en 'R'.
    void divisio (const Polinomi& B, Polinomi& Q, Polinomi& R) const;

    // Retorna el màxim comú divisor d'aquest polinomi i el polinomi 'Q'.
    Polinomi mcd (const Polinomi& Q) const;

  private:

    // El vector de coeficients reals del polinomi.
    vector<double> v;

};

#endif
