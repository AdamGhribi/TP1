/*
* @fichier: PolyLand.h
* @auteurs:
* @date:
* @description: Polyland est la map de jeu que l'on va explorer, elle contient les differents elements de jeu
*/

#include "PolyLand.h"

// TODO: constructeur
PolyLand::PolyLand() {
	// code
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
	return false;
}

// TODO: ajouter creature dans creatures_
// *verifier que nb creature < MAX_CREATURES
// *si ajoute, return true sinon false
//	ex: Pikachu a bien �t� ajout� !
bool PolyLand::ajouterCreature(const Creature& creature) {
	// code
	return false;
}

// TODO: retire dresseur dans dresseurs_
bool PolyLand::retirerDresseur(const std::string& nom) {
	// code
	return false;
}

// TODO: retire creature dans creatures_
bool PolyLand::retirerCreature(const std::string& nom) {
	// code
	return false;
}

// TODO: generer un indice aleatoire et
// retourner le dresseur a cet indice
// *verifier le nb de dresseur
Dresseur* PolyLand::choisirDresseurAleatoire() {
	// code
	return nullptr;
}

// TODO: generer un indice aleatoire et
// retourner la creature a cet indice
// *verifier le nb de creature
Creature* PolyLand::choisirCreatureAleatoire() {
	// code
	return nullptr;
}

// TODO: rechercher un dresseur par nom
Dresseur* PolyLand::choisirDresseur(const string& nom) {
	// code
	return nullptr;
}

// TODO: rechercher une creature par nom
Creature* PolyLand::choisirCreature(const string& nom) {
	// code
	return nullptr;
}

// TODO: ajouter une creature a un dresseur
bool PolyLand::attraperCreature(Dresseur* dresseur, const Creature& creature) {
	return false;
}

// TODO: retirer une creature a un dresseur
bool PolyLand::relacherCreature(Dresseur* dresseur, const Creature& creature) {
	return false;
}

// TODO: completer le code d'affichage
void PolyLand::infoDresseur(const std::string& nom) const {
	// effectuer une recherche par nom du dresseur passe en parametre
	Dresseur* dresseur = nullptr;
	// code

	if (dresseur != nullptr) {
		cout << "\u001b[32;1mInformations sur le dresseur: \033[0m" << std::endl;
		// afficher le dresseur
		// code
	}
	else {
		// afficher que le dresseur est introuvable
		// code
	}
}
