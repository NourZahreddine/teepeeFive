///////////////////////////////////////////////////////////
//  CompositeStep.cpp
//  Implementation of the Class CompositeStep
//  Created on:      19-mars-2022 11:23:22
//  Original author: François
///////////////////////////////////////////////////////////

#include "CompositeStep.h"

CompositeStep::CompositeStep(std::string title)
	: AbsStep(title, 0)
{
}

CompositeStep::CompositeStep(const CompositeStep& mdd)
	: AbsStep(mdd)
{
	// À compléter pour copier toutes les sous-étapes contenues dans l'étape
}

CompositeStep* CompositeStep::clone() const
{
	// À compléter pour construire un nouvel objet CompositeStep en appelant le constructeur de copie
	return nullptr; // À remplacer
}

RecipeComponentIterator CompositeStep::begin() {

	return m_stepsContainer.begin();
}


RecipeComponentIterator_const CompositeStep::cbegin() const {

	return m_stepsContainer.cbegin();
}


RecipeComponentIterator_const CompositeStep::cend() const 
{
	return m_stepsContainer.cend();
}

RecipeComponentIterator CompositeStep::end() 
{
	return  m_stepsContainer.end();
}

AbsRecipeComponent& CompositeStep::addRecipeComponent(const AbsRecipeComponent& member)
{
	const AbsStep& step = dynamic_cast<const AbsStep&>(member);
	return addRecipeComponent(step);
}

AbsRecipeComponent& CompositeStep::addRecipeComponent(const AbsStep& member)
{
	// À compléter pour construire par clonage une copie de l'objet reçu en paramètre
	// et l'insérer dans le conteneur des étapes. On retourne une référence à l'objet
	// qui vient d'être inséré dans le conteneur.

	return *this; // À remplacer 
}

void CompositeStep::deleteRecipeComponent(RecipeComponentIterator_const child)
{
	// À compléter pour éliminer des étapes l'élément auquel réfère l'itérateur
}

void CompositeStep::deleteAllComponents(void)
{
	// À compléter pour éliminer tous les éléments de l'étape
}

int CompositeStep::getDuration() const
{
	// À compléter pour calculer le temps total en sommant la durée de toutes les sous-étapes
	return 0; // À remplacer
}

std::ostream& CompositeStep::printToStream(std::ostream& o) const 
{
	// À compléter pour imprimer sur un stream une étape et ses sous-étapes
	return o;
}
