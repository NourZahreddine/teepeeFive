///////////////////////////////////////////////////////////
//  AbsIngredient.h
//  Implementation of the Class AbsIngredient
//  Created on:      19-mars-2022 11:23:22
//  Original author: François
///////////////////////////////////////////////////////////

#if !defined(EA_25324567_C773_47c6_8365_3CEF3C82489D__INCLUDED_)
#define EA_25324567_C773_47c6_8365_3CEF3C82489D__INCLUDED_

#include "AbsRecipeComponent.h"

//#include "AbsIngredientContainer.h"

class AbsIngredient : public AbsRecipeComponent
{

public:

	AbsIngredient(std::string description, int duration);
	virtual ~AbsIngredient() = default;
};
#endif // !defined(EA_25324567_C773_47c6_8365_3CEF3C82489D__INCLUDED_)
