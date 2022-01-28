/*
* @fichier: Pouvoir.cpp
* @auteurs:
* @date:
* @description: La classe Pouvoir correspond aux differents attaques
*/

#include "Pouvoir.h"

// TODO: constructeur avec liste d'initialisation
Pouvoir::Pouvoir() {
	// code
}

// TODO: constructeur par parametre avec liste d'initialisation
Pouvoir::Pouvoir(const std::string& nom,
	unsigned int nombreDeDegat, unsigned int manaNecessaire) : Pouvoir() {
	// code
}

// TODO: destructeur
Pouvoir::~Pouvoir() {
	// code
}

// TODO: Getters
unsigned int Pouvoir::obtenirManaNecessaire() const {
	// code
	return 0;
}

std::string Pouvoir::obtenirNom() const {
	// code
	return "";
}

unsigned int Pouvoir::obtenirNombreDeDegat() const {
	// code
	return 0;
}

// TODO: Setters
void Pouvoir::modifierNombreDeDegat(unsigned int nombreDegat) {
	// code
}

void Pouvoir::modifierManaNecessarie(unsigned int manaNecessaire) {
	// code
}

void Pouvoir::modifierNom(const std::string& nom) {
	// code
}

// TODO: Affichage du pouvoir
// ex: Blaze necessite 5 mana et inflige 10 degats
void Pouvoir::description() const {
	// code
}
