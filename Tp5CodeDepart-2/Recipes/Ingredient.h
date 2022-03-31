///////////////////////////////////////////////////////////
//  Ingredient.h
//  Implementation of the Class Ingredient
//  Created on:      19-mars-2022 11:23:22
//  Original author: François
///////////////////////////////////////////////////////////

#if !defined(EA_E18F6E2E_DCCF_48a7_A4E4_5006198DB785__INCLUDED_)
#define EA_E18F6E2E_DCCF_48a7_A4E4_5006198DB785__INCLUDED_

#include "AbsIngredient.h"
#include "AbsProduct.h"

class Ingredient : public AbsIngredient
{

public:
	Ingredient(std::string name, int duration, const AbsProduct& product);
	virtual ~Ingredient() = default;
	Ingredient* clone() const override;

	virtual const AbsProduct& getProduct() const;

protected:
	const AbsProduct& m_product;

	std::ostream& printToStream(std::ostream& o) const;

};
#endif // !defined(EA_E18F6E2E_DCCF_48a7_A4E4_5006198DB785__INCLUDED_)
