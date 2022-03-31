///////////////////////////////////////////////////////////
//  AbsIngredient.cpp
//  Implementation of the Class AbsIngredient
//  Created on:      19-mars-2022 11:23:22
//  Original author: François
///////////////////////////////////////////////////////////

#include "AbsIngredient.h"

AbsIngredient::AbsIngredient(std::string description, int duration)
	: AbsRecipeComponent(description, duration)
{
}
