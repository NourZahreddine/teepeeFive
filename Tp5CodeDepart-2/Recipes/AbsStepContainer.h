///////////////////////////////////////////////////////////
//  AbsStepContainer.h
//  Implementation of the Class AbsStepContainer
//  Created on:      26-oct.-2019
//  Original author: p482457
///////////////////////////////////////////////////////////

#if !defined(__ABSSTEPCONTAINER_HEADER_)
#define __ABSSTEPCONTAINER_HEADER_

#include <memory>
#include <vector>

// Configuration du stockage des enfants des objets composites
using AbsStepPtr = std::unique_ptr<class AbsStep>;
using AbsStepContainer = std::vector<AbsStepPtr>;
using AbsStepBaseIterator = AbsStepContainer::iterator;
using AbsStepBaseIterator_const = AbsStepContainer::const_iterator;

class AbsStepIterator : public AbsStepBaseIterator
{
public:
	AbsStepIterator(const AbsStepContainer::iterator& it) : AbsStepBaseIterator(it) {}

	// Operateurs simplifiant l'acces a l'objet 3D sur lequel pointe l'iterateur
	// pour AbsStepIterator it;
	//    *it est l'objet 3D
	//    it-> permet d'invoquer une methode sur l'objet 3D
	class AbsStep& operator*() { return *((*(AbsStepBaseIterator(*this))).get()); }
	class AbsStep* operator->() { return (*(AbsStepBaseIterator(*this))).get(); }
};

class AbsStepIterator_const : public AbsStepBaseIterator_const
{
public:
	AbsStepIterator_const(const AbsStepContainer::const_iterator& it) : AbsStepBaseIterator_const(it) {}

	// Operateurs simplifiant l'acces a l'objet 3D sur lequel pointe l'iterateur
	// pour AbsStepIterator_const it;
	//    *it est l'objet 3D constant
	//    it-> permet d'invoquer une methode const sur l'objet 3D
	const class AbsStep& operator*() { return *((*(AbsStepBaseIterator_const(*this))).get()); }
	const class AbsStep* operator->() { return (*(AbsStepBaseIterator_const(*this))).get(); }
};

#endif // !defined(__ABSSTEPCONTAINER_HEADER_)
