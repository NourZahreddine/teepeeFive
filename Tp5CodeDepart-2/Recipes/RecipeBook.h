///////////////////////////////////////////////////////////
//  RecipeBook.h
//  Implementation of the Class RecipeBook
//  Created on:      19-mars-2022 11:14:24
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(EA_8D6BD6C0_DA27_41d0_A8F8_FAFC4E2FB93D__INCLUDED_)
#define EA_8D6BD6C0_DA27_41d0_A8F8_FAFC4E2FB93D__INCLUDED_

#include "Recipe.h"
#include "Catalog.h"

class RecipeBook
{

public:
	RecipeBook(std::string title);
	virtual ~RecipeBook() = default;

	const AbsProduct& findProduct(std::string productName) const;

	virtual void addRecipe(const Recipe& rc);
	const Recipe* findRecipe(std::string keyword) const;

private:
	void initialize();

	Catalog m_catalog;
	Recipe m_recipes;

	friend std::ostream& operator<<(std::ostream& o, const RecipeBook& b);
};
#endif // !defined(EA_8D6BD6C0_DA27_41d0_A8F8_FAFC4E2FB93D__INCLUDED_)
