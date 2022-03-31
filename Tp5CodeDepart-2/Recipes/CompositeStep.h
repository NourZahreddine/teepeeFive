///////////////////////////////////////////////////////////
//  CompositeStep.h
//  Implementation of the Class CompositeStep
//  Created on:      19-mars-2022 11:23:22
//  Original author: François
///////////////////////////////////////////////////////////

#if !defined(EA_18A3D912_AFB1_44eb_87B0_E9A94CE907F3__INCLUDED_)
#define EA_18A3D912_AFB1_44eb_87B0_E9A94CE907F3__INCLUDED_

#include "AbsStep.h"

class CompositeStep : public AbsStep
{

public:
	CompositeStep(std::string title);
	CompositeStep(const CompositeStep& mdd);
	virtual ~CompositeStep() = default;
	virtual CompositeStep* clone() const;

	virtual RecipeComponentIterator begin() override;
	virtual RecipeComponentIterator_const cbegin() const override;
	virtual RecipeComponentIterator_const cend() const override;
	virtual RecipeComponentIterator end() override;

	virtual AbsRecipeComponent& addRecipeComponent(const AbsRecipeComponent& member) override;
	virtual AbsRecipeComponent& addRecipeComponent(const AbsStep& member);
	virtual void deleteRecipeComponent(RecipeComponentIterator_const child) override;
	virtual void deleteAllComponents(void);
	virtual int getDuration(void) const override;

protected:
	std::ostream& printToStream(std::ostream& o) const override;

	RecipeComponentContainer m_stepsContainer;
};
#endif // !defined(EA_18A3D912_AFB1_44eb_87B0_E9A94CE907F3__INCLUDED_)
