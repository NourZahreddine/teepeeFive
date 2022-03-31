///////////////////////////////////////////////////////////
//  AbsRecipeComponent.h
//  Implementation of the Class AbsRecipeComponent
//  Created on:      19-mars-2022 11:14:24
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(EA_8FD28C28_332A_4f8b_B5EA_6517EC179227__INCLUDED_)
#define EA_8FD28C28_332A_4f8b_B5EA_6517EC179227__INCLUDED_

#include <iostream>
#include <string>

#include "RecipeComponentContainer.h"

class AbsRecipeComponent
{

public:

	AbsRecipeComponent(std::string description, int duration);
	virtual ~AbsRecipeComponent() = default;
	virtual AbsRecipeComponent* clone() const = 0;

	virtual AbsRecipeComponent& addRecipeComponent(const AbsRecipeComponent& member);
	virtual RecipeComponentIterator begin();
	virtual RecipeComponentIterator_const cbegin() const;
	virtual RecipeComponentIterator_const cend() const;
	virtual RecipeComponentIterator end();
	virtual void deleteRecipeComponent(RecipeComponentIterator_const child);

	virtual std::string getDescription() const { return m_description; }
	virtual int getDuration() const { return m_duration; }
	virtual void setDescription(std::string description){ m_description = description; }
	virtual void setDuration(int duration) { m_duration = duration; }

protected:
	int m_duration;
	std::string m_description;

	static int m_indent;
	std::ostream& indent(std::ostream& o) const;

	friend std::ostream& operator<<(std::ostream& o, const AbsRecipeComponent& rc);
	virtual std::ostream& printToStream(std::ostream& o) const =0;

private:
	static RecipeComponentContainer m_emptyContainer;
};
#endif // !defined(EA_8FD28C28_332A_4f8b_B5EA_6517EC179227__INCLUDED_)
