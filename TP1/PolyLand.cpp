/*
* @fichier: PolyLand.h
* @auteurs: Adam Ghribi, Carole Keriaky
* @date: 03.02.2022
* @description: Polyland est la map de jeu que l'on va explorer, elle contient les differents elements de jeu
*/

#include "PolyLand.h"

// TODO: constructeur
PolyLand::PolyLand() {
	// code
	dresseurs_= new Dresseur * [MAX_DRESSEURS];
	nombreDresseurs_= NULL;
	creatures_= new Creature*[MAX_CREATURES];
	nombreCreatures_= NULL;
}

// TODO: destructeur
PolyLand::~PolyLand() {
	// code

}

// TODO: ajouter dresseur dans dresseurs_
// *verifier que nb dresseur < MAX_DRESSEURS
// *verifier que le dresseur n'est pas deja dans dresseurs_
// *si ajoute,  return true sion false
//	ex: Leon a bien �t� ajout� !
bool PolyLand::ajouterDresseur(Dresseur* dresseur) {
	// code
	if (nombreDresseurs_ < MAX_DRESSEURS) {
		for (unsigned int i = 0; i < nombreDresseurs_; i++) {
			if (dresseurs_[i]->obtenirNom() == dresseur->obtenirNom()) {
				return false;
			}
		}
		dresseurs_[nombreDresseurs_++] = new Dresseur(*dresseur);
		return true;
	}
	else {
		return false;
	}
}

// TODO: ajouter creature dans creatures_
// *verifier que nb creature < MAX_CREATURES
// *si ajoute, return true sinon false
//	ex: Pikachu a bien �t� ajout� !
bool PolyLand::ajouterCreature(const Creature& creature) {
	// code
	if (nombreCreatures_ < MAX_CREATURES) {
		creatures_[nombreCreatures_++] = new Creature(creature);
		return true;
	}
	else {
		return false;
	}
}

// TODO: retire dresseur dans dresseurs_
bool PolyLand::retirerDresseur(const std::string& nom) {
	// code
	for (unsigned int i = 0; i < nombreDresseurs_; i++) {
		if (dresseurs_[i]->obtenirNom() == nom) {
			dresseurs_[i] = dresseurs_[nombreDresseurs_ - 1];
			nombreDresseurs_--;
			return true;
		}
	}
	return false;
}

// TODO: retire creature dans creatures_
bool PolyLand::retirerCreature(const std::string& nom) {
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

// TODO: generer un indice aleatoire et
// retourner le dresseur a cet indice
// *verifier le nb de dresseur
Dresseur* PolyLand::choisirDresseurAleatoire() {
	// code
	int i= rand() % nombreDresseurs_;

	return dresseurs_[i];
}

Creature* PolyLand::choisirCreatureAleatoire() {
	// code
	int i = rand() % nombreCreatures_;

	return creatures_[i];
}

// TODO: rechercher un dresseur par nom
Dresseur* PolyLand::choisirDresseur(const string& nom) {
	// code
	Dresseur dresseur = Dresseur();
	for (unsigned int i = 0; i < nombreDresseurs_; i++) {
		if (dresseurs_[i]->obtenirNom() == nom)
			return dresseurs_[i];
		else
			return &dresseur;
	}
}

// TODO: rechercher une creature par nom
Creature* PolyLand::choisirCreature(const string& nom) {
	// code
	Creature creature = Creature();
	for (unsigned int i = 0; i < nombreCreatures_; i++) {
		if (creatures_[i]->obtenirNom() == nom)
			return creatures_[i];
		else
			return &creature;
	}
}

// TODO: ajouter une creature a un dresseur
bool PolyLand::attraperCreature(Dresseur* dresseur, const Creature& creature) {
	return dresseur->ajouterCreature(creature);
}

// TODO: retirer une creature a un dresseur
bool PolyLand::relacherCreature(Dresseur* dresseur, const Creature& creature) {
	return dresseur->retirerCreature(creature.obtenirNom());
}

// TODO: completer le code d'affichage
void PolyLand::infoDresseur(const std::string& nom) const {
	// effectuer une recherche par nom du dresseur passe en parametre
	Dresseur* dresseur = nullptr;
	// code
	for (unsigned int i = 0; i < nombreDresseurs_; i++) {
		if (dresseurs_[i]->obtenirNom() == nom)
			dresseur=dresseurs_[i];
		   break;
	}
	if (dresseur != nullptr) {
		cout << "\u001b[32;1mInformations sur le dresseur: \033[0m" << std::endl;
		// afficher le dresseur
		// code
		dresseur->affichage();
	}
	else {
		// afficher que le dresseur est introuvable
		// code
		cout << nom << " est introuvable " << endl;
	}
}
