/*
* @fichier: Dresseur.cpp
* @auteurs: Adam Ghribi, Carole Keriaky
* @date: 28.01.2022
* @description: les dresseurs sont les etres capables d'attraper des creatures
*/

#include "Dresseur.h"

// TODO: constructeur avec liste d'initialisation
Dresseur::Dresseur() {
	// code
    nom_="";
	creatures_= new Creature*;
	nombreCreatures_=0;
    nombreCreaturesMax_=2;
}

// TODO: constructeur par parametre avec liste d'initialisation
Dresseur::Dresseur(const std::string& nom) : Dresseur() {
	// code
	nom_ = nom;
}

// TODO: destructeur
Dresseur::~Dresseur() {
	// code
}

// TODO: Getters
std::string Dresseur::obtenirNom() const {
	// code
	return nom_;
}

unsigned int Dresseur::obtenirNombreCreatures() const {
	// code
	return nombreCreatures_;
}

Creature** Dresseur::obtenirCreatures() const {
	// code
	Creature* c = new Creature();
	Creature** p = &c;
	return p;
}

// TODO: Setters
void Dresseur::modifierNom(const std::string& nom) {
	// code	
	nom_ = nom;
}

void Dresseur::modifierCreature(Creature** creatures) {
	// code
	creatures_ = creatures;
}

// TODO: ajouter creature dans creatures_
// *verifier que la creature n'est pas deja presente
// *verifier que nb creature < nombreCreaturesMax_
//	->	sinon doubler la taille de creatures_
bool Dresseur::ajouterCreature(const Creature& creature) {
	// code
	bool existe = false;
	int i = 0;
	while ((existe == false) && (i < nombreCreatures_)) {
		if (creatures_[i]->obtenirNom() == creature.obtenirNom()) {
			existe = true;
		}
		else
			i++;
	}
	bool nbC = (nombreCreatures_ < nombreCreaturesMax_);
	if (existe && nbC) {
		*creatures_[nombreCreatures_] =creature;
	}
	else {
		nombreCreaturesMax_ *= 2;
	}
	return false;
}

// TODO: retire creature dans creatures_
bool Dresseur::retirerCreature(const std::string& nom) {
	// code
	bool existe = false;
	int i = 0;
	while ((existe == false) && (i < nombreCreatures_)) {
		if (creatures_[i]->obtenirNom() == nom) {
			existe = true;
			delete creatures_[i]; //~
		}
		else
			i++;
	}
	return false;
}

// TODO: fonction d'affichage
void Dresseur::affichage() const {
	// afficher le nom et le nombre de creature
	cout << obtenirNom() << " possede " << obtenirNombreCreatures() << " creature(s)" << endl;
	// ex: Leon possede 1 creature(s)
	// boucler sur chaque creature et afficher ses informations
	for (unsigned int i = 0; i < nombreCreatures_; i++) {
		creatures_[i]->information();
	}
}
