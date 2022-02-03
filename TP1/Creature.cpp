/*
* @fichier: Creature.cpp
* @auteurs:Adam Ghribi, Carole Keriaky
* @date: 03.02.2002
* @description: Les creatures sont des etres destines au combat
*/

#include "Creature.h"

// TODO: constructeur avec liste d'initialisation
Creature::Creature() {
	// code
	nom_ = "";
	attaque_ = NULL;
	defense_ = NULL;
	pointDeVie_ = NULL;
	energie_ = NULL;
	pouvoir_ = Pouvoir();
}

// TODO: constructeur par parametre avec liste d'initialisation
Creature::Creature(const std::string& nom, unsigned int attaque,
	unsigned int defense, unsigned int pointDeVie, unsigned int energie, Pouvoir pouvoir) : Creature() {
	// code
	nom_ = nom;
	attaque_ = attaque;
	defense_ = defense;
	pointDeVie_ = pointDeVie;
	energie_ = energie;
	pouvoir_ = pouvoir;
}

// TODO: destructeur
Creature::~Creature() {
	// code
}

// TODO: Getters
std::string Creature::obtenirNom() const {
	// code
	return nom_;
}

unsigned int Creature::obtenirAttaque() const {
	// code
	return attaque_;
}

unsigned int Creature::obtenirDefense() const {
	// code
	return defense_;
}

unsigned int Creature::obtenirPointDeVie() const {
	// code
	return pointDeVie_;
}

unsigned int Creature::obtenirPointDeVieTotal() const {
	// code
	return pointDeVieTotal_;
}

unsigned int Creature::obtenirEnergie() const {
	// code
	return energie_;
}

unsigned int Creature::obtenirEnergieTotale() const {
	// code
	return energieTotal_;
}

unsigned int Creature::obtenirExperience() const {
	// code
	return experience_;
}

unsigned int Creature::obtenirExperienceNecessaire() const {
	// code
	return experienceNecessaire_;
}

unsigned int Creature::obtenirNiveau() const {
	// code
	return niveau_;
}

Pouvoir Creature::obtenirPouvoir() const {
	// code
	return pouvoir_;
}

// TODO: Setters
void Creature::modifierAttaque(unsigned int attaque) {
	// code
	attaque_ = attaque;
}

void Creature::modifierDefense(unsigned int defense) {
	// code
	defense_ = defense;
}

void Creature::modifierPointDeVie(unsigned int pointDeVie) {
	// code
	pointDeVie_ = pointDeVie;
}

void Creature::modifierEnergie(unsigned int mana) {
	// code
	energie_ = mana;
}

void Creature::modifierExperience(unsigned int experience) {
	// code
	experience_ = experience;
}

void Creature::modifierNiveau(unsigned int niveau) {
	// code
}

void Creature::modifierPouvoir(Pouvoir pouvoir) {
	// code
	pouvoir_ = pouvoir;
}

void Creature::attaquer(Creature& creature) {
	
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
	
}

int Creature::experienceGagnee(const Creature& creature) {
	
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
	
	return 0;
}

// TODO: fonction d'affichage
void Creature::information() const {
	// afficher les attributs de la creature
	cout << nom_ << endl;
	cout << "attaque: " << attaque_ <<endl;
	cout << "defense: "<< defense_ <<endl;
	cout << "point de vie: " <<pointDeVie_ << endl;
	cout << "point de vie total: " << pointDeVieTotal_<< endl;
	cout << "energie: " << energie_ << endl;
	cout << "energie total: " << energieTotal_ << endl;
	cout << "experience: "<< experience_ <<endl;
	cout << "experience necessaire: " << experienceNecessaire_ <<endl;
	cout <<"niveau: "<< niveau_ <<endl;
	// afficher le pouvoir
	pouvoir_.description();
}
