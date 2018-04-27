/*
  ________________________
 /\                       \
 \_|  CLASSE de POLINOMIS |
   |                      |
   |       main.cc        |
   |   ___________________|_
    \_/_____________________/
*/
#include "Polinomi.hh"

#include <iostream>
#include <string>
#include <map>
using namespace std;
/*
========================================================================
*/
// Defineix un nou polinom donat el seu 'nom' i la seva representació
// en string 'polinomi'. (ex. def P 2x^2 -1x^0)
void def (map<string, Polinomi>& polinomis) {
  string nom, polinomi;
  cin >> nom;
  getline(cin, polinomi);
  polinomis[nom] = Polinomi(polinomi);
}

// Mostra el polinomi de 'nom' donat emmagatzemat en el diccionari.
// (ex. veure P)
void veure (map<string, Polinomi>& polinomis) {
  string nom;
  cin >> nom;
  string r = polinomis[nom].veure();
  for (char c : r) cout << c;
  cout << endl;
}

// Mostra el grau del polinomi de 'nom' donat emmagatzemat en el
// diccionari. (ex. grau P)
void grau (map<string, Polinomi>& polinomis) {
  string nom;
  cin >> nom;
  cout << polinomis[nom].grau() << endl;
}

// Mostra el polinomi de 'nom' donat en forma de vector de coeficients
// reals (les seves components). (ex. vect P)
void vect (map<string, Polinomi>& polinomis) {
  string nom;
  cin >> nom;
  for (double x : polinomis[nom].veure_vector()) cout << x << ' ';
  cout << endl;
}

// Mostra el resultat d'avaluar en el punt donat 'x' el polinomi de
// 'nom' donat. (ex. aval P -5)
void avalua (map<string, Polinomi>& polinomis) {
  string nom;
  double x;
  cin >> nom >> x;
  cout << polinomis[nom].avalua(x) << endl;
}

// Modifica el monomi de grau 'n' pel coeficient 'x' del polinomi de
// 'nom' donat. (ex. modifica P 2 1)
void modif (map<string, Polinomi>& polinomis) {
  string nom;
  double x; int n;
  cin >> nom >> n >> x;
  polinomis[nom].modifica(n, x);
}

// Mostra el coeficient del monomi de grau donat 'n' del polinomi de
// 'nom' donat. (ex. monomi P 0)
void monomi (map<string, Polinomi>& polinomis) {
  string nom;
  int n;
  cin >> nom >> n;
  cout << polinomis[nom].monomi(n) << endl;
}

// Guarda en el polinomi de 'nom' donat la suma dels polinomis P i Q.
// (ex. suma R P Q)
void suma (map<string, Polinomi>& polinomis) {
  string nom, P, Q;
  cin >> nom >> P >> Q;
  polinomis[nom] = polinomis[P] + polinomis[Q];
}

// Guarda en el polinomi de 'nom' donat la diferència dels polinomis P i Q.
// (ex. resta R P Q)
void resta (map<string, Polinomi>& polinomis) {
  string nom, P, Q;
  cin >> nom >> P >> Q;
  polinomis[nom] = polinomis[P] - polinomis[Q];
}

// Guarda en el polinomi de 'nom' donat el producte dels polinomis P i Q.
// (ex. prod R P Q)
void prod (map<string, Polinomi>& polinomis) {
  string nom, P, Q;
  cin >> nom >> P >> Q;
  polinomis[nom] = polinomis[P] * polinomis[Q];
}

// Guarda en el polinomi de 'nom' donat la divisió dels polinomis P i Q.
// (ex. divi R P Q)
void divi (map<string, Polinomi>& polinomis) {
  string nom, P, Q;
  cin >> nom >> P >> Q;
  polinomis[nom] = polinomis[P] / polinomis[Q];
}

// Guarda en el polinomi de 'nom' donat el màxim comú divisor dels
// polinomis P i Q. (ex. mcd R P Q)
void mcd (map<string, Polinomi>& polinomis) {
  string nom, P, Q;
  cin >> nom >> P >> Q;
  polinomis[nom] = polinomis[P].mcd(polinomis[Q]);
}
/*
========================================================================
*/

void joc_de_proves(map<string, Polinomi>& polinomis, string accio) {
  if (accio == "def")           def(polinomis);       // def P 2x^2 -1x^0
  else if (accio == "veure")    veure(polinomis);     // veure P
  else if (accio == "grau")     grau(polinomis);      // grau P
  else if (accio == "vect")     vect(polinomis);      // vect P
  else if (accio == "aval")     avalua(polinomis);    // aval P -5
  else if (accio == "modif")    modif(polinomis);     // modif P 2 1
  else if (accio == "monomi")   monomi(polinomis);    // monomi P 0
  else if (accio == "suma")     suma(polinomis);      // suma R P Q
  else if (accio == "resta")    resta(polinomis);     // resta R P Q
  else if (accio == "prod")     prod(polinomis);      // prod R P Q
  else if (accio == "divi")     divi(polinomis);      // divi R P Q
  else if (accio == "mcd")      mcd(polinomis);       // mcd R P Q
  else cout << "Error. Torna-ho a intentar!" << endl; // EXEMPLES ↑
}

int main() {
  map<string, Polinomi> polinomis;
  string accio;
  cout << endl << "Ei, company/a! ☺ Benvolgut/da a la CLASSE POLINOMIS!" << endl << endl;
  cout << "  RECORDA:" << endl;
  cout << "  Per introduïr un nou polinomi, s'han d'escriure els monomis en ordre decreixent segons el grau." << endl;
  cout << "  Tot monomi es compon d’un coeficient real seguit dels caràcters 'x^' i un número enter." << endl << endl;
  cout << "  ATENCIÓ!" << endl;
  cout << "    - És imprescindible afegir els caràcters 'x^' en els monomis de grau 1 i 0." << endl;
  cout << "    - És imprescindible afegir el coeficient ‘1’, si escau, en els monomis." << endl;
  cout << "    - No és necessari introduir els monomis de coeficient nul." << endl << endl;
  cout << "Vols veure una demostració de com funciona?     ( S | N ) ";
  cin >> accio;
  cout << endl << "======================================================================================================" << endl << endl;
  if (accio == "S" or accio == "s") {
    cout << "D'acord, endavant! Vegem tot el que pots fer amb els polinomis." << endl << endl;
    cout << endl << "    1) Defineix un nou polinomi P de la següent manera:     def P 1x^4 -2x^3 -11.51x^2 +30x^1 -20x^0" << endl << endl;
    cout << "          ";
    cin >> accio;
    joc_de_proves(polinomis, accio);
    cout << endl << "    2) Per veure el polinomi que has creat escriu:          veure P" << endl << endl;
    cout << "          ";
    cin >> accio;
    cout << endl << "          ";
    joc_de_proves(polinomis, accio);
    cout << endl << "    3) També pots veure el polinomi com a vector:           vect P" << endl << endl;
    cout << "          ";
    cin >> accio;
    cout << endl << "          ";
    joc_de_proves(polinomis, accio);
    cout << endl << "    4) Vegem quin és el grau del polinomi. Escriu:          grau P" << endl << endl;
    cout << "          ";
    cin >> accio;
    cout << endl << "          ";
    joc_de_proves(polinomis, accio);
    cout << endl << "    5) Prova a avaluar el polinomi en el punt -1.5:         aval P -1.5" << endl << endl;
    cout << "          ";
    cin >> accio;
    cout << endl << "          ";
    joc_de_proves(polinomis, accio);
    cout << endl << "    6) Pots modificar el monomi de grau 2 així:             modif P 2 -11" << endl << endl;
    cout << "          ";
    cin >> accio;
    joc_de_proves(polinomis, accio);
    cout << endl << "    7) Ara pots veure el nou monomi de grau 2. Escriu:      monomi P 2" << endl << endl;
    cout << "          ";
    cin >> accio;
    cout << endl << "          ";
    joc_de_proves(polinomis, accio);
    cout << endl << "    8) Defineix un altre polinomi Q per fer operacions:     def Q 1x^2 +3x^1 -2x^0" << endl << endl;
    cout << "          ";
    cin >> accio;
    joc_de_proves(polinomis, accio);
    cout << endl << "    9) Prova a guardar en R la suma de P i Q:               suma R P Q" << endl << endl;
    cout << "          ";
    cin >> accio;
    joc_de_proves(polinomis, accio);
    cout << endl << "       - Mostra el resulat:                                 veure R" << endl << endl;
    cout << "          ";
    cin >> accio;
    cout << endl << "          ";
    joc_de_proves(polinomis, accio);
    cout << endl << "   10) Prova a guardar en R la resta de P i Q:              resta R P Q" << endl << endl;
    cout << "          ";
    cin >> accio;
    joc_de_proves(polinomis, accio);
    cout << endl << "       - Mostra el resulat:                                 veure R" << endl << endl;
    cout << "          ";
    cin >> accio;
    cout << endl << "          ";
    joc_de_proves(polinomis, accio);
    cout << endl << "   11) Prova a guardar en R el producte de P i Q:           prod R P Q" << endl << endl;
    cout << "          ";
    cin >> accio;
    joc_de_proves(polinomis, accio);
    cout << endl << "       - Mostra el resulat:                                 veure R" << endl << endl;
    cout << "          ";
    cin >> accio;
    cout << endl << "          ";
    joc_de_proves(polinomis, accio);
    cout << endl << "   12) Prova a guardar en R la divisó de P i Q:             divi R P Q" << endl << endl;
    cout << "          ";
    cin >> accio;
    joc_de_proves(polinomis, accio);
    cout << endl << "       - Mostra el resulat:                                 veure R" << endl << endl;
    cout << "          ";
    cin >> accio;
    cout << endl << "          ";
    joc_de_proves(polinomis, accio);
    cout << endl << "   13) Prova a guardar en R el mcd de P i Q:                mcd R P Q" << endl << endl;
    cout << "          ";
    cin >> accio;
    joc_de_proves(polinomis, accio);
    cout << endl << "       - Mostra el resulat:                                 veure R" << endl << endl;
    cout << "          ";
    cin >> accio;
    cout << endl << "          ";
    joc_de_proves(polinomis, accio);
    cout << endl << "  Hem acabat! Ja has vist com funciona la CLASSE POLINOMIS!" << endl;
   }
  cout << endl << "======================================================================================================" << endl;
  cout << endl << "Prova a utilitzar les funcions que vulguis." << endl << endl;
  cout << "Aquí tens la sintaxi de les funcions: " << endl << endl;
  cout << "def [nom] [polinomi]         veure [nom]                    grau [nom]                  vect [nom]" << endl;
  cout << "aval [nom] [punt]            modif [nom] [grau] [coef]      monomi [nom] [grau]         suma [nom] [nom] [nom]" << endl;
  cout << "resta [nom] [nom] [nom]      prod [nom] [nom] [nom]         divi [nom] [nom] [nom]      mcd [nom] [nom] [nom]" << endl << endl;
  cout << "Aquí tens alguns exemples per provar: " << endl << endl;
  cout << "def P 2x^2 -1x^0             veure P                        grau P                      vect P" << endl;
  cout << "aval P -5                    modif P 2 1                    monomi P 0                  suma R P Q" << endl;
  cout << "resta R P Q                  prod R P Q                     divi R P Q                  mcd R P Q" << endl << endl;
  while (cin >> accio) {
    joc_de_proves(polinomis, accio);
    cout << endl;
  }
  cout << endl;
}
