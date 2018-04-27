/*
  ________________________
 /\                       \
 \_|  CLASSE de POLINOMIS |
   |                      |
   |      Polinomi.cc     |
   |   ___________________|_
    \_/_____________________/
*/
#include "Polinomi.hh"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <complex>
#include <cmath>
using namespace std;
/*
========================================================================
FUNCIONS EXTERNES utilitzades en la implementació de la clase Polinomi
········································································
*/
// Retorna el nombre màxim dels enters 'a' i 'b'.
int max(int a, int b) {
  if (a >= b) return a;
  return b;
}

// Retorna la representació en string del nombre real 'n'.
string dou_a_str(double n) {
  ostringstream oss;
  string s;
  oss << n;
  s = oss.str();
  return s;
}

// Retorna la representació en string del polinomi P donat en
// forma de vector 'v'.
string vector_a_string(const vector<double>& v) {
  string s;
  if (v.size() >= 1) {
    for (int i = v.size() - 1; i >= 0; --i) {
      if (v[i] < 0)
      s += dou_a_str(v[i]) + "x^" + dou_a_str(i) + ' ';
      else if (v[i] > 0)
      s += '+' + dou_a_str(v[i]) + "x^" + dou_a_str(i) + ' ';
    }
    return s;
  }
  else return "0";
}

// Retorna el nombre real que correspon a la string 's'.
double str_a_dou(string s) {
  istringstream iss(s);
  double n;
  iss >> n;
  return n;
}

// Retorna el nombre enter que correspon a la string 's'.
int str_a_int(string s) {
  istringstream iss(s);
  int n;
  iss >> n;
  return n;
}

// Retorna el grau d'un polinomi P donat en forma de string 's'.
int grau(string s) {
  istringstream iss(s);
  string monomi;
  iss >> monomi;
  for (int i = 0; i < monomi.size(); ++i)
    if (monomi[i] == '^')
      return str_a_int(monomi.substr(i + 1, monomi.size()));
  return 0;
}

// Retorna el vector de coeficients reals del polinomi P donat
// en forma de string 's'.
vector<double> string_a_vector(string s) {
  istringstream iss(s);
  vector<double> v(grau(s) + 1, 0);
  string monomi;
  while (iss >> monomi) {
    int j = 0;
    for (int i = 0; i < monomi.size(); ++i)
      if (monomi[i] == '^') {
        double coef = str_a_dou(monomi.substr(j, i - 1));
        int expo = str_a_int(monomi.substr(i + 1, monomi.size()));
        v[expo] = coef;
        j = i;
      }
  }
  return v;
}
/*
========================================================================
*/
/*
========================================================================
FUNCIONS utilitzades en l'algorisme de la FFT (Fast Fourier Transform)
········································································
*/
// Per no haver de definir cada vegada un nombre complex amb
// 'complex<double>' utilitzem la paraula 'complexe'.
using complexe = complex<double>;

// Definim una constant ε (epsilon) amb un valor de 10^(-9)
// per corregir els errors de precisió que genera la FFT.
const double EPSILON = pow(10, -9);

// Retorna la potència de 2 més propera al nombre donat 'n'.
int potencia_2(int n) {
  int i = 2;
  while (i < n) i *= 2;
  return i;
}

// Retorna un vector de complexes 'v' amb els coeficients parells
// del vector 'A' donat.
vector<complexe> coef_parells(const vector<complexe>& A) {
  vector<complexe> v;
  for (int i = 0; i < A.size(); i += 2) v.push_back(A[i]);
  return v;
}

// Retorna un vector de complexes 'v' amb els coeficients senars
// del vector 'A' donat.
vector<complexe> coef_senars(const vector<complexe>& A) {
  vector<complexe> v;
  for (int i = 1; i < A.size(); i += 2) v.push_back(A[i]);
  return v;
}

// Retorna la multiplicació de l'escalar 'k' donat amb el vector
// de complexes 'v' donat.
vector<complexe> escalar_per_vector(double k, vector<complexe>& v) {
  for (auto& x : v) x *= k;
  return v;
}

// Ajusta la part real i imaginària a 0 segons la constant ε (epsilon)
// del nombre complex 'c' donat.
void ajusta_zeros(complexe& c) {
  if (-EPSILON <= c.real() and c.real() <= EPSILON) c = {0.0, c.imag()};
  if (-EPSILON <= c.imag() and c.imag() <= EPSILON) c = {c.real(), 0.0};
}

// Algorisme de la FFT (Fast Fourier Transform).
vector<complexe> FFT(const vector<complexe>& A, complexe w) {
  if (A.size() == 1) return A; // Cas base.
  else {
    // Dividim A en dos parts: els termes parells i els senars.
    vector<complexe> A_even = coef_parells(A);
    vector<complexe> A_odd = coef_senars(A);
    // Apliquem recursivament la FFT a cada part d'A (dividir i vèncer).
    vector<complexe> F_even = FFT(A_even, polar(1.0, 4*M_PI/A.size()));
    vector<complexe> F_odd = FFT(A_odd, polar(1.0, 4*M_PI/A.size()));
    // Creem el vector de complexes que donarà el resultat.
    vector<complexe> F(A.size());
    // Efectuem la convulsió de les dues parts de la solució
    // avaluant A(x) i A(-x) als 'n' punts emparellats.
    complexe x = 1;
    for (int i = 0; i < A.size()/2; ++i) {
      F[i] = F_even[i] + x*F_odd[i];
      F[i+A.size()/2] = F_even[i] - x*F_odd[i];
      x = x * w;
    }
    // Ajustem la part real i imaginària dels nombres complexes del
    // vector 'F' a 0 segons la constant ε (epsilon).
    for (auto& x : F) ajusta_zeros(x);
    return F;
  }
}

// Retorna la conversió d'un vector de reals 'v' donat a un vector
// de nombres complexes 'C'.
vector<complex<double>> double_a_complex(const vector<double>& v) {
  vector<complex<double>> C(v.size());
  for (int i = 0; i < v.size(); ++i)
    C[i] = complexe(v[i]);
  return C;
}

// Retorna la conversió d'un vector de nombres complexes 'C' donat
// a un vector de reals 'v'.
vector<double> complex_a_double(const vector<complexe>& C) {
  vector<double> v(C.size());
  for (int i = 0; i < C.size(); ++i) v[i] = C[i].real();
  return v;
}
/*
========================================================================
IMPLEMENTACIÓ de la classe Polinomi
········································································
*/
// CONSTRUCTOR #1: Assigna el polinomi P donat en forma de string 's',
// transformat en un vector de coeficients reals, a la part privada 'v'.
Polinomi::Polinomi (const string& s) {
  v = string_a_vector(s);
}

// CONSTRUCTOR #2: Assigna el polinomi P donat en forma de vector de
// coeficients reals 'vect' a la part privada 'v'.
Polinomi::Polinomi (const vector<double>& vect) {
  v = vect;
}

// Retorna la representació en string, amb el format corresponent,
// d'aquest polinomi.
string Polinomi::veure () const {
  return vector_a_string(v);
}

// Retorna aquest polinomi en forma de vector (les seves components).
vector<double> Polinomi::veure_vector () const {
  return v;
}

// Retorna el grau d'aquest polinomi.
int Polinomi::grau () const {
  return v.size() - 1;
}

// Avalua aquest polinomi en un punt donat 'x'.
// Implementació amb l'algorisme de Horner.
double Polinomi::avalua (const double x) const {
  double aval = 0;
  for (int i = v.size() - 1; i >= 0; --i)
    aval = aval * x + v[i];
  return aval;
}

// Retorna el coeficient del monomi de grau donat 'n' d'aquest polinomi.
double Polinomi::monomi (int n) const {
  return v[n];
}

// Modifica el monomi de grau 'n' d'aquest polinomi pel coeficient 'x'.
void Polinomi::modifica (int n, double x) {
  v[n] = x;
}

// Elimina els monomis nuls (iguals a 0) d'aquest polinomi.
void Polinomi::normalitza () {
  while (v.size() > 0 and v[v.size() - 1] == 0)
    v.pop_back();
}

// Retorna la suma d'aquest polinomi amb el polinomi donat 'Q'.
Polinomi Polinomi::operator+ (const Polinomi& Q) const {
  int midaMax = max(v.size(), Q.v.size());
  vector<double> R(midaMax);
  for (int i = 0; i < midaMax; ++i) {
    double s;
    if (i >= v.size()) s = Q.v[i];
    else if (i >= Q.v.size()) s = v[i];
    else s = v[i] + Q.v[i];
    R[i] = s;
  }
  Polinomi resultat(R);
  resultat.normalitza();
  return resultat;
}

// Retorna la diferència d'aquest polinomi amb el polinomi donat 'Q'.
Polinomi Polinomi::operator- (const Polinomi& Q) const {
  int midaMax = max(v.size(), Q.v.size());
  vector<double> R(midaMax);
  for (int i = 0; i < midaMax; ++i) {
    double s;
    if (i >= v.size()) s = -Q.v[i];
    else if (i >= Q.v.size()) s = v[i];
    else s = v[i] - Q.v[i];
    R[i] = s;
  }
  Polinomi resultat(R);
  resultat.normalitza();
  return resultat;
}

// Retorna el producte d'aquest polinomi amb el polinomi donat 'Q'.
// Implementació amb l'algorisme FFT (Fast Fourier Transform).
Polinomi Polinomi::operator* (const Polinomi& Q) const {
  if (v.size() * Q.v.size() == 0) return Polinomi(0);
  vector<double> R_rr(v.size() + Q.v.size() - 1, 0);
  // Definim els dos polinomis que volem multiplicar (amb reals).
  vector<double> a = v;
  vector<double> b = Q.v;
  // Definim el grau del polinomi resultant.
  int grau = a.size() + b.size() - 1;
  // Necessitem afegir zeros extra als vectors.
  while (a.size() < grau) a.push_back(0);
  while (b.size() < grau) b.push_back(0);
  // Convertim els vectors de reals a nombres complexes.
  vector<complexe> A = double_a_complex(a);
  vector<complexe> B = double_a_complex(b);
  // Per aplicar l'algorisme, 'n' ha de ser una potència de 2.
  int n = potencia_2(grau);
  // Definim l'arrel n-èsima de la unitat 'w' (nombre complex).
  complexe w = polar(1.0, 2*M_PI/n);
  // Efectuem l'algorisme utilitzant la FFT.
  vector<complexe> F_A = FFT(A, w);     // Temps: O(n*log(n))
  vector<complexe> F_B = FFT(B, w);     // Temps: O(n*log(n))
  vector<complexe> F_C(n);              // Temps: O(n)
  // Realitzem la convulsió d'ambdues parts.
  for (int i = 0; i < n; ++i) {
    F_C[i] = F_A[i] * F_B[i];
  }
  // Calculem els coeficients utilitzan la inversa de la FFT
  // i multiplicant per 1/n.
  vector<complexe> F_C_inversa = FFT(F_C, polar(1.0, -2*M_PI/n));
  vector<complexe> C = escalar_per_vector(1.0/n, F_C_inversa);
  // Convertim el vector de nombres complexos a reals.
  vector<double> R_r = complex_a_double(C);

  // Normalitzem el vector per evitar zeros innecessaris.
  for (int i = 0; i < v.size(); ++i)
    for (int j = 0; j < Q.v.size(); ++j)
      R_rr[i+j] += v[i] * Q.v[j];
  Polinomi resultat(R_rr);
  resultat.normalitza();
  return resultat;
}

// Realitza la divisó d'aquest polinomi amb el polinomi donat 'B' i
// emmagatzema el quocient en 'Q' i el residu en 'R'.
void Polinomi::divisio (const Polinomi& B, Polinomi& Q, Polinomi& R) const {
  if (v.size() < B.v.size()) { // Cas especial: grau(P) < grau(Q)
    Q = Polinomi(0); return;
  }
  R = *this;
  vector<double> q(v.size() - B.v.size() + 1, 0);
  Q = Polinomi (q);
  int iR = R.v.size() - 1; // Índex del coeficient dominant de R
  // Cada iteració executa un pas de la divisió
  for (int iQ = q.size() - 1; iQ >= 0; --iQ) {
    Q.v[iQ] = R.v[iR] / B.v[B.v.size() - 1]; // Nou coeficient de Q
    R.v[iR] = 0; // Garanteix un zero 'exacte' en el coeficient dominant
    for (int k = B.v.size() - 2; k >= 0; --k) {
      R.v[k+iQ] -= Q.v[iQ] * B.v[k];
    }
    --iR; // Índex del coeficient dominant de Q
  }
  R.normalitza();
}

// Retorna la divisó d'aquest polinomi amb el polinomi donat 'B'.
Polinomi Polinomi::operator/ (const Polinomi& B) const {
  Polinomi Q, R;
  divisio(B, Q, R);
  Q.normalitza();
  return Q;
}

// Retorna el màxim comú divisor d'aquest polinomi i el polinomi 'Y'.
Polinomi Polinomi::mcd (const Polinomi& Y) const {
  Polinomi A = *this;
  Polinomi B = Y;
  while (B.v.size() > 0) {
    Polinomi Q, R;
    divisio(B, Q, R);
    A = B;
    B = R;
  }
  // Converteix a polinomi mònic (ex. 3x-6 --> x-2)
  double c = A.v[A.v.size() - 1];
  for (int i = 0; i < A.v.size(); ++i) A.v[i] = A.v[i] / c;
  return A;
}
