# Defineix els 'flags' per compilar amb C++.
CXXFLAGS = -Wall -std=c++11 -O2

# Regla per compilar tot (make all).
# Com és la primera regla, és també la regla per defecte (make).
all: main.exe

# Regla per netejar els fitxers objectes i executables (make clean).
clean:
	rm -f main.exe *.o

# Regla per vincular (link) l'executable als fitxers objectes.

# S'utilitzen les següents variables per defecte:
# 		$^ és el nom de tots els requisits previs.
#			$@ és el nom de l'objectiu (target) de la regla.
# 		$(CXX) és el nom del compilador de C++.
main.exe: main.o Polinomi.o
	$(CXX) $^ -o $@

# Dependències entre fitxers.
main.cc: Polinomi.hh

Polinomi.cc: Polinomi.hh
