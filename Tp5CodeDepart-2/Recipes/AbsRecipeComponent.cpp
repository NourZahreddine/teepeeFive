///////////////////////////////////////////////////////////
//  AbsRecipeComponent.cpp
//  Implementation of the Class AbsRecipeComponent
//  Created on:      19-mars-2022 11:14:24
//  Original author: francois
///////////////////////////////////////////////////////////

#include "AbsRecipeComponent.h"

int AbsRecipeComponent::m_indent = 0;
RecipeComponentContainer AbsRecipeComponent::m_emptyContainer;

AbsRecipeComponent::AbsRecipeComponent(std::string description, int duration)
	: m_description(description), m_duration(duration)
{
}

std::ostream& AbsRecipeComponent::indent(std::ostream& o) const
{
	for (int i = 0; i < m_indent; ++i)
		o << '\t';
	return o;
}

std::ostream& operator<<(std::ostream& o, const AbsRecipeComponent& rc)
{
	return  rc.printToStream(o);
}

AbsRecipeComponent& AbsRecipeComponent::addRecipeComponent(const AbsRecipeComponent& member)
{
	return  *(*(m_emptyContainer.begin()));
}

RecipeComponentIterator AbsRecipeComponent::begin()
{
	return m_emptyContainer.begin();
}

RecipeComponentIterator_const AbsRecipeComponent::cbegin() const
{
	return m_emptyContainer.cbegin();
}

RecipeComponentIterator AbsRecipeComponent::end()
{
	return m_emptyContainer.end();
}

void AbsRecipeComponent::deleteRecipeComponent(RecipeComponentIterator_const child)
{
}

RecipeComponentIterator_const AbsRecipeComponent::cend() const
{
	return m_emptyContainer.cend();
}
