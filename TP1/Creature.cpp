/*
* @fichier: Creature.cpp
* @auteurs:
* @date:
* @description: Les creatures sont des etres destines au combat
*/

#include "Creature.h"

// TODO: constructeur avec liste d'initialisation
Creature::Creature() {
	// code
}

// TODO: constructeur par parametre avec liste d'initialisation
Creature::Creature(const std::string& nom, unsigned int attaque,
	unsigned int defense, unsigned int pointDeVie, unsigned int energie, Pouvoir pouvoir) : Creature() {
	// code
}

// TODO: destructeur
Creature::~Creature() {
	// code
}

// TODO: Getters
std::string Creature::obtenirNom() const {
	// code
	return "";
}

unsigned int Creature::obtenirAttaque() const {
	// code
	return 0;
}

unsigned int Creature::obtenirDefense() const {
	// code
	return 0;
}

unsigned int Creature::obtenirPointDeVie() const {
	// code
	return 0;
}

unsigned int Creature::obtenirPointDeVieTotal() const {
	// code
	return 0;
}

unsigned int Creature::obtenirEnergie() const {
	// code
	return 0;
}

unsigned int Creature::obtenirEnergieTotale() const {
	// code
	return 0;
}

unsigned int Creature::obtenirExperience() const {
	// code
	return 0;
}

unsigned int Creature::obtenirExperienceNecessaire() const {
	// code
	return 0;
}

unsigned int Creature::obtenirNiveau() const {
	// code
	return 0;
}

Pouvoir Creature::obtenirPouvoir() const {
	// code
	return Pouvoir();
}

// TODO: Setters
void Creature::modifierAttaque(unsigned int attaque) {
	// code
}

void Creature::modifierDefense(unsigned int defense) {
	// code
}

void Creature::modifierPointDeVie(unsigned int pointDeVie) {
	// code
}

void Creature::modifierEnergie(unsigned int mana) {
	// code
}

void Creature::modifierExperience(unsigned int experience) {
	// code
}

void Creature::modifierNiveau(unsigned int niveau) {
	// code
}

void Creature::modifierPouvoir(Pouvoir pouvoir) {
	// code
}

void Creature::attaquer(Creature& creature) {
	/*
	if (energie_ >= pouvoir_.obtenirManaNecessaire()) {
		if (creature.obtenirPointDeVie() >= 0) {
			//Calcul du nombre de degat selon une formule
			unsigned int degat = (pouvoir_.obtenirNombreDeDegat()) * (attaque_ / 2 - creature.defense_);
			int tentative = rand() % 6;
			//l'attaque rate une fois sur 6
			if (tentative != 3) {
				std::cout << nom_ << " lance " << pouvoir_.obtenirNom() << " qui inflige " << degat << " degat a " << creature.obtenirNom() << endl;
				if (degat > creature.obtenirPointDeVie()) {
					creature.modifierPointDeVie(0);
					int xp = experienceGagnee(creature);
					cout << nom_ << " a gagné " << xp << " XP" << endl;
				}
				else
					creature.modifierPointDeVie(creature.obtenirPointDeVie() - degat);
				cout << creature.obtenirNom() << " a encore " << creature.obtenirPointDeVie() << " PV" << endl;
				energie_ -= pouvoir_.obtenirManaNecessaire();
			}
			else {
				std::cout << "Attaque " << pouvoir_.obtenirNom() << " a échouée" << endl;
			}
		}
		else
			std::cout << "Vous deja avez vaincu " << creature.obtenirNom() << endl;
	}
	*/
}

int Creature::experienceGagnee(const Creature& creature) {
	/*
	if (creature.obtenirPointDeVie() <= 0) {
		//Calcul de l'experience selon une formule mystérieuse
		int experience = (creature.obtenirNiveau() + 1 - niveau_) * ((creature.obtenirAttaque() + 5 - attaque_) * (creature.obtenirDefense() + 3 - defense_)) + (pointDeVie_ / 2);
		if (experience > (experienceNecessaire_ - experience_)) {
			//Cas ou la creature va monter d'un niveau
			int experienceRestante = experience - (experienceNecessaire_ - experience_);
			niveau_++;
			attaque_ += 1;
			defense_ += 1;
			pointDeVie_ += 5;
			energie_ += 5;
			energieTotal_ += 5;
			pointDeVieTotal_ += 5;
			experience_ = experienceRestante;
			experienceNecessaire_ = experienceNecessaire_ * 15 / 10;
		}
		else {
			//Sinon elle recupère juste de l'expérience
			experience_ += experience;
		}
		return experience;
	}
	*/
	return 0;
}

// TODO: fonction d'affichage
void Creature::information() const {
	// afficher les attributs de la creature
	// afficher le pouvoir
}
