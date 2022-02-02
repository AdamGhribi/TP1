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
	dresseurs_= new Dresseur*[MAX_DRESSEURS];
	nombreDresseurs_=0;
	creatures_= new Creature*[MAX_CREATURES];
	nombreCreatures_=0;
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
	bool verifier = nombreDresseurs_ < MAX_DRESSEURS;
	bool existe = false;
	int i = 0;
	while ((existe == false)&&(i< nombreDresseurs_)) {
		if (dresseurs_[i]->obtenirNom() == dresseur->obtenirNom()) {
			existe = true;
		}
		else
			i++;
	}
	bool ajoute = existe && verifier;
	if (ajoute)
		dresseurs_[nombreDresseurs_] = dresseur;
	
	return ajoute;
}

// TODO: ajouter creature dans creatures_
// *verifier que nb creature < MAX_CREATURES
// *si ajoute, return true sinon false
//	ex: Pikachu a bien �t� ajout� !
bool PolyLand::ajouterCreature(const Creature& creature) {
	// code
	bool verifier = nombreCreatures_ < MAX_CREATURES;
	bool existe = false;
	int i = 0;
	while ((existe == false)&& (i < nombreCreatures_)) {
		if (creatures_[i]->obtenirNom() == creature.obtenirNom()) {
			existe = true;
		}
		else
			i++;
	}
	bool ajoute= existe && verifier;
	if (ajoute) 
		*creatures_[nombreCreatures_] = creature;

	return ajoute;
}

// TODO: retire dresseur dans dresseurs_
bool PolyLand::retirerDresseur(const std::string& nom) {
	// code
	bool existe = false;
	for (int i = 0; i < nombreDresseurs_; i++) {
		if (dresseurs_[i]->obtenirNom() == nom) {
			dresseurs_[i] = dresseurs_[nombreDresseurs_ - 1];
			existe = (dresseurs_[i]->obtenirNom() == nom);
			nombreDresseurs_--;
			break;
		}
	}
	return existe;
}

// TODO: retire creature dans creatures_
bool PolyLand::retirerCreature(const std::string& nom) {
	// code
	bool existe = false;
	for (int i = 0; i < nombreCreatures_; i++) {
		if (creatures_[i]->obtenirNom() == nom) {
			creatures_[i] = creatures_[nombreCreatures_ - 1];
			nombreCreatures_--;
			existe = (creatures_[i]->obtenirNom() == nom);
			break;
		}
	}
	return existe;
}

// TODO: generer un indice aleatoire et
// retourner le dresseur a cet indice
// *verifier le nb de dresseur
Dresseur* PolyLand::choisirDresseurAleatoire() {
	// code
	int i= rand() % nombreDresseurs_;

	return dresseurs_[i];
}

// TODO: generer un indice aleatoire et
// retourner la creature a cet indice
// *verifier le nb de creature
Creature* PolyLand::choisirCreatureAleatoire() {
	// code
	int i = rand() * nombreCreatures_;
	return creatures_[i];
}

// TODO: rechercher un dresseur par nom
Dresseur* PolyLand::choisirDresseur(const string& nom) {
	// code
	Dresseur dresseur = Dresseur();
	for (int i = 0; i < nombreDresseurs_; i++) {
		if (dresseurs_[i]->obtenirNom() == nom)
			return dresseurs_[i];
		break;
	}
	return &dresseur;
}

// TODO: rechercher une creature par nom
Creature* PolyLand::choisirCreature(const string& nom) {
	// code
	Creature creature = Creature();
	for (int i = 0; i < nombreCreatures_; i++) {
		if (creatures_[i]->obtenirNom() == nom)
			return creatures_[i];
			break;
	}
	return &creature;
}

// TODO: ajouter une creature a un dresseur
bool PolyLand::attraperCreature(Dresseur* dresseur, const Creature& creature) {
	dresseur->ajouterCreature(creature);
	return false;
}

// TODO: retirer une creature a un dresseur
bool PolyLand::relacherCreature(Dresseur* dresseur, const Creature& creature) {
	dresseur->retirerCreature(creature.obtenirNom());
	return false;
}

// TODO: completer le code d'affichage
void PolyLand::infoDresseur(const std::string& nom) const {
	// effectuer une recherche par nom du dresseur passe en parametre
	Dresseur* dresseur = nullptr;
	// code
	for (int i = 0; i < nombreDresseurs_; i++) {
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
