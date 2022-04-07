///////////////////////////////////////////////////////////
//  Recipe.cpp
//  Implementation of the Class Recipe
//  Created on:      19-mars-2022 11:14:24
//  Original author: francois
///////////////////////////////////////////////////////////

#include "Recipe.h"

Recipe::Recipe(std::string title)
    : AbsIngredient(title,0), m_steps("Steps:")
{
}

Recipe::Recipe(const Recipe& mdd)
    : AbsIngredient(mdd), m_steps(mdd.m_steps)
{
	// À compléter pour copier tous les ingrédients contenus dans la recette

	for(auto&& ingredients : mdd.m_ingredients)
	{
		addRecipeComponent(*ingredients);
	}

}

Recipe* Recipe::clone() const
{
	// À compléter pour construire un nouvel objet Recipe en appelant le constructeur de copie
	return new Recipe(*this); // À remplacer
}

AbsRecipeComponent& Recipe::addRecipeComponent(const AbsRecipeComponent& member)
{
	const AbsIngredient& ingredient = dynamic_cast<const AbsIngredient&>(member);
	return addIngredient(ingredient);
}

AbsRecipeComponent& Recipe::addIngredient(const AbsRecipeComponent& member)
{
	const AbsIngredient& ingredient = dynamic_cast<const AbsIngredient&>(member);
	return addIngredient(ingredient);
}

AbsRecipeComponent& Recipe::addIngredient(const AbsIngredient& ingredient)
{
	// À compléter pour construire par clonage une copie de l'objet reçu en paramètre
	// et l'insérer dans le conteneur des ingrédients. On retourne une référence à l'objet
	// qui vient d'être inséré dans le conteneur.

	auto ingredientCopy = ingredient.clone();
	m_ingredients.push_back(std::unique_ptr<AbsRecipeComponent>(ingredientCopy)); // TODO: maybe a remplacer avec unique_ptr
	return *ingredientCopy; // À remplacer 

}

AbsRecipeComponent& Recipe::addStep(const AbsStep& step)
{
	// À compléter pour déléguer aux étapes la tâche d'insérer une copie de l'étape reçue en paramètre.
	// On retourne une référence à l'objet qui vient d'être inséré dans le conteneur.
	
	return m_steps.addRecipeComponent(step);; 
}

RecipeComponentIterator Recipe::begin(){

	return m_ingredients.begin();
}


RecipeComponentIterator_const Recipe::cbegin() const
{
	return m_ingredients.cbegin();
}


RecipeComponentIterator_const Recipe::cend() const
{
	return m_ingredients.cend();
}

RecipeComponentIterator Recipe::end()
{
	return m_ingredients.end();
}

RecipeComponentIterator Recipe::begin_step()
{
	return m_steps.begin();
}

RecipeComponentIterator_const Recipe::cbegin_step() const
{
	return m_steps.cbegin();
}

RecipeComponentIterator_const Recipe::cend_step() const
{
	return m_steps.cend();
}

RecipeComponentIterator Recipe::end_step()
{
	return m_steps.end();
}


void Recipe::deleteRecipeComponent(RecipeComponentIterator_const child)
{
	// À compléter pour éliminer de l'ingrédient auquel réfère l'itérateur

	m_ingredients.erase(child);
	
}

void Recipe::deleteIngredient(RecipeComponentIterator_const ingredient)
{
	// À compléter pour éliminer tous les ingrédients
	m_ingredients.clear();
}

void Recipe::deleteStep(RecipeComponentIterator_const step)
{
	// À compléter pour déléguer aux étapes la tâche d'effacer l'étape à laquelle réfère l'itérateur.

	m_steps.deleteRecipeComponent(step);

}

void Recipe::deleteAllComponents()
{
	// À compléter pour éliminer tous les ingrédients et déléguer aux étapes
	// la tâche d'effacer toutes les étapes.

	m_steps.deleteAllComponents();
}

std::ostream& Recipe::printToStream(std::ostream& o) const 
{
	// À compléter pour imprimer sur un stream une recette
	
	o << "Recipe: " << m_description << '\n';
	indent(o);
	o << "Ingredients: " <<'\n';
	
	for (auto&& ingredient : m_ingredients)
	{
		m_indent++;
		indent(o);
		o << *ingredient;
		m_indent--;
	}
	
	o << m_steps << "\n";

	return o;
}