///////////////////////////////////////////////////////////
//  RecipeBook.cpp
//  Implementation of the Class RecipeBook
//  Created on:      19-mars-2022 11:14:24
//  Original author: francois
///////////////////////////////////////////////////////////

#include "AbsRecipeComponent.h"
#include "RecipeBook.h"
#include "Ingredient.h"
#include "CompositeStep.h"
#include "SingleStep.h"

RecipeBook::RecipeBook(std::string title)
	: m_recipes(title)
{
	initialize();
}

const AbsProduct& RecipeBook::findProduct(std::string productName) const
{
	const AbsProduct* product = m_catalog.findProduct(productName);
	if (product == nullptr)
	{
		std::string product_not_found("Product not found: ");
		product_not_found += productName;
		throw(std::domain_error(product_not_found));
	}
	return *product;
}

void RecipeBook::addRecipe(const Recipe& rc)
{
	m_recipes.addIngredient(rc);
}

const Recipe* RecipeBook::findRecipe(std::string keyword) const
{
	const Recipe* foundRecipe = nullptr;
	for (auto it = m_recipes.cbegin(); it != m_recipes.cend(); ++it)
	{
		if (it->getDescription() == keyword)
		{
			foundRecipe = dynamic_cast<const Recipe*>(&(*it));
			break;
		}
	}

	return foundRecipe;
}

void RecipeBook::initialize()
{
	std::cout << "Creating Product Catalog\n";
	Catalog m_catalog;
	std::cout << "The catalog of products:\n" << m_catalog << std::endl;

	Recipe croute("croute");
	Ingredient farine("tamisee", 30, findProduct("farine"));
	croute.addIngredient(farine);
	Ingredient eau("tiede", 30, findProduct("eau"));
	croute.addIngredient(eau);
	Ingredient levure("", 30, findProduct("levure"));
	croute.addIngredient(levure);
	Ingredient sucre("", 30, findProduct("sucre"));
	croute.addIngredient(sucre);
	Ingredient sel("", 15, findProduct("sel"));
	croute.addIngredient(sel);
	Ingredient huile("", 30, findProduct("huile"));
	croute.addIngredient(huile);

	CompositeStep preparation_levain("Preparer le levain.");
	SingleStep levain_etape1("Melanger l'eau tiede, la levure et le sucre.", 30);
	preparation_levain.addRecipeComponent(levain_etape1);
	SingleStep levain_etape2("Laisser reposer 5 minutes.", 300);
	preparation_levain.addRecipeComponent(levain_etape2);
	croute.addStep(preparation_levain);
	SingleStep croute_etape2("Melanger la farine et le sel dans un robot culinaire.", 30);
	croute.addStep(croute_etape2);
	SingleStep croute_etape3("Ajouter le melange d'eau et de levure dans le robot culinaire et petrir pendant 5 minutes.", 330);
	croute.addStep(croute_etape3);
	SingleStep croute_etape4("Huiler un grand bol et deposer la pate petrie en boule dans le bol.", 60);
	croute.addStep(croute_etape4);
	SingleStep croute_etape5("Recouvrir le bol d'un linge et laisser gonfler la pate au moins 2 heures.", 7200);
	croute.addStep(croute_etape5);

	addRecipe(croute);

	Recipe sauceTomate("sauce tomate");
	Ingredient tomates("broyees", 15, findProduct("tomates"));
	sauceTomate.addIngredient(tomates);
	Ingredient oignons("tranches", 120, findProduct("oignons"));
	sauceTomate.addIngredient(oignons);
	Ingredient ail("ecrase", 120, findProduct("ail"));
	sauceTomate.addIngredient(ail);
	sauceTomate.addIngredient(huile);
	Ingredient basilic("cisele", 90, findProduct("basilic"));
	sauceTomate.addIngredient(basilic);

	SingleStep sauce_etape1("Hacher finement les oignons et l'ail", 180);
	sauceTomate.addStep(sauce_etape1);
	SingleStep sauce_etape2("Faire revenir les oignons et l'ail dans l'huile pendant 4 minutes", 240);
	sauceTomate.addStep(sauce_etape2);
	SingleStep sauce_etape3("Ajouter les tomates broyees et le basilic.", 30);
	sauceTomate.addStep(sauce_etape3);
	SingleStep sauce_etape4("Porter a petite ebullition.", 120);
	sauceTomate.addStep(sauce_etape4);
	SingleStep sauce_etape5("Faire mijoter doucement pendant une heure en brassant regulierement.", 3600);
	sauceTomate.addStep(sauce_etape5);

	addRecipe(sauceTomate);

	Recipe pizza("pizza");
	pizza.addIngredient(croute);
	pizza.addIngredient(sauceTomate);
	pizza.addIngredient(oignons);
	Ingredient olives("tranchees", 120, findProduct("olives"));
	pizza.addIngredient(olives);
	Ingredient fromage("rape", 120, findProduct("fromage"));
	pizza.addIngredient(fromage);

	SingleStep pizza_etape1("Rouler la pate en un cercle de 45cm de diametre.", 120);
	pizza.addStep(pizza_etape1);
	SingleStep pizza_etape2("Precuire la pate dans un four tres chaud (425F/220C) pendant 7 minutes.", 420);
	pizza.addStep(pizza_etape2);
	SingleStep pizza_etape3("Etendre uniformement la sauce tomate sur la croute precuite.", 30);
	pizza.addStep(pizza_etape3);
	SingleStep pizza_etape4("Repartir uniformement les oignons et olives.", 60);
	pizza.addStep(pizza_etape4);
	SingleStep pizza_etape5("Recouvrir du fromage rape.", 30);
	pizza.addStep(pizza_etape5);
	SingleStep pizza_etape6("Remettre au four pour 10 a 12 minutes.", 600);
	pizza.addStep(pizza_etape6);

	addRecipe(pizza);
}

std::ostream& operator<<(std::ostream& o, const RecipeBook& b)
{
	return o << b.m_recipes;
}