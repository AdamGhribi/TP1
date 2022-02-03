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
	nombreCreatures_= NULL;
    nombreCreaturesMax_=2;
	creatures_ = new Creature*[nombreCreaturesMax_]; // nullptr;
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
	return creatures_;
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
	for (unsigned int i = 0; i < nombreCreatures_; i++) {
		if (creatures_[i]->obtenirNom() == creature.obtenirNom()) {
			return  false;
		}
	}
	
	if (nombreCreatures_ < nombreCreaturesMax_) {
		// TODO ajouter la creature dans tab existant
		creatures_[nombreCreatures_++] = new Creature(creature);
		return true;
	}
	else {
		// TODO doubler le tab et ecirere un nv tab avec taille*2
		nombreCreaturesMax_ *= 2;
		Creature** ancien = creatures_;
		creatures_ = new Creature* [nombreCreaturesMax_];
		for (unsigned int i = 0; i < nombreCreatures_; i++) {
			creatures_[i] = ancien[i];
		}
//		delete[] ancien;

		creatures_[nombreCreatures_++] = new Creature(creature);
		return true;
	}
}

// TODO: retire creature dans creatures_
bool Dresseur::retirerCreature(const std::string& nom) {
	// code
	for (unsigned int i = 0; i < nombreCreatures_; i++) {
		if (creatures_[i]->obtenirNom() == nom) {
			creatures_[i] = creatures_[nombreCreatures_ - 1];
			nombreCreatures_--;
			return true;
		}
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
