///////////////////////////////////////////////////////////
//  AbsStep.h
//  Implementation of the Class AbsStep
//  Created on:      19-mars-2022 11:14:24
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(EA_B5DB37D5_5E36_4bc7_9215_DCA15BA647EC__INCLUDED_)
#define EA_B5DB37D5_5E36_4bc7_9215_DCA15BA647EC__INCLUDED_

#include "AbsRecipeComponent.h"

class AbsStep : public AbsRecipeComponent
{

public:
	AbsStep(std::string description, int duration);
	virtual ~AbsStep() = default;
};
#endif // !defined(EA_B5DB37D5_5E36_4bc7_9215_DCA15BA647EC__INCLUDED_)
