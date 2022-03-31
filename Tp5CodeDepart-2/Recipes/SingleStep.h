///////////////////////////////////////////////////////////
//  SingleStep.h
//  Implementation of the Class SingleStep
//  Created on:      19-mars-2022 11:14:24
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(EA_15989034_DDB8_4002_9A7A_9AB006F15059__INCLUDED_)
#define EA_15989034_DDB8_4002_9A7A_9AB006F15059__INCLUDED_

#include "AbsStep.h"

class SingleStep : public AbsStep
{

public:
	SingleStep(std::string description, int duration);
	virtual ~SingleStep() = default;
	virtual SingleStep* clone() const;

protected:
	virtual std::ostream& printToStream(std::ostream& o) const;

};
#endif // !defined(EA_15989034_DDB8_4002_9A7A_9AB006F15059__INCLUDED_)
