///////////////////////////////////////////////////////////
//  Ingredient.cpp
//  Implementation of the Class Ingredient
//  Created on:      19-mars-2022 11:23:22
//  Original author: François
///////////////////////////////////////////////////////////

#include "Ingredient.h"




Ingredient::Ingredient(std::string name, int duration, const AbsProduct& product)
	: AbsIngredient(name, duration), m_product(product)
{
}

Ingredient* Ingredient::clone() const
{
	// À compléter pour construire un nouvel objet Ingredient en appelant le constructeur de copie
	return nullptr; // À remplacer
}

const AbsProduct& Ingredient::getProduct() const
{
	return m_product;
}

std::ostream& Ingredient::printToStream(std::ostream& o) const 
{
	// À compléter pour imprimer sur un stream une catégorie et ses produits
	return o;
}

