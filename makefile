#wie wird SFML richtig eingebunden?
#Flags für Compiler
CXXFLAGS := -std=c++17 -Wall -Iinclude
SFMLLIB := -lsfml-graphics -lsfml-window -lsfml-system 

#alle Ziele definieren
all: gear_sim
.PHONY: clean

#Programm fertig verlinken
gear_sim: obj/main.o obj/Gear.o include/Gear.hpp
	@mkdir -p bin
	g++ $(CXXFLAGS) obj/main.o obj/Gear.o include/Gear.hpp $(SFMLLIB) -o bin/gear_sim

#Objektdateien für Programm kompilieren
obj/main.o: src/main.cpp
	@mkdir -p obj
	g++ $(CXXFLAGS) -c src/main.cpp -o obj/main.o

obj/Gear.o: src/Gear.cpp
	@mkdir -p obj
	g++ $(CXXFLAGS) -c src/Gear.cpp -o obj/Gear.o

#Befehl um Verzeichnis zu reinigen
clean: 
	rm -rf obj bin
