///////////////////////////////////////////////////////////
//  Recipe.h
//  Implementation of the Class Recipe
//  Created on:      19-mars-2022 11:14:24
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(EA_A3850BC0_89CD_4093_A74A_55C94FF8F583__INCLUDED_)
#define EA_A3850BC0_89CD_4093_A74A_55C94FF8F583__INCLUDED_

#include "AbsIngredient.h"
#include "CompositeStep.h"

class Recipe : public AbsIngredient
{

public:
	Recipe(std::string title);
	Recipe(const Recipe& mdd);
	virtual ~Recipe() = default;
	virtual Recipe* clone(void) const override;

	// Ingredients iterators
	virtual RecipeComponentIterator begin() override;
	virtual RecipeComponentIterator_const cbegin() const override;
	virtual RecipeComponentIterator_const cend() const override;
	virtual RecipeComponentIterator end() override;

	// Steps iterators
	virtual RecipeComponentIterator begin_step();
	virtual RecipeComponentIterator_const cbegin_step() const;
	virtual RecipeComponentIterator_const cend_step() const;
	virtual RecipeComponentIterator end_step();

	// Add component to Recipe
	virtual AbsRecipeComponent& addRecipeComponent(const AbsRecipeComponent& member) override;
	virtual AbsRecipeComponent& addIngredient(const AbsRecipeComponent& member);
	virtual AbsRecipeComponent& addIngredient(const AbsIngredient& ingredient);
	virtual AbsRecipeComponent& addStep(const AbsStep& step);

	// Delete component from Recipe
	virtual void deleteRecipeComponent(RecipeComponentIterator_const child) override;
	virtual void deleteIngredient(RecipeComponentIterator_const child);
	virtual void deleteStep(RecipeComponentIterator_const step);
	virtual void deleteAllComponents();


private:
	RecipeComponentContainer m_ingredients;
	CompositeStep m_steps;

	virtual std::ostream& printToStream(std::ostream& o) const;

};
#endif // !defined(EA_A3850BC0_89CD_4093_A74A_55C94FF8F583__INCLUDED_)
