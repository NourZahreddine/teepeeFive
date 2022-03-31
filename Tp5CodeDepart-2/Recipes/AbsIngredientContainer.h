///////////////////////////////////////////////////////////
//  AbsIngredientContainer.h
//  Implementation of the Class AbsIngredientContainer
//  Created on:      26-oct.-2019
//  Original author: p482457
///////////////////////////////////////////////////////////

#if !defined(__ABSINGREDIENTCONTAINER_HEADER_)
#define __ABSINGREDIENTCONTAINER_HEADER_

#if 0
#include "RecipeComponentContainer.h"

using AbsIngredientPtr = std::unique_ptr<class AbsIngredient>;
using AbsIngredientContainer = std::vector<AbsIngredientPtr>;
using AbsIngredientBaseIterator = AbsIngredientContainer::iterator;
using AbsIngredientBaseIterator_const = AbsIngredientContainer::const_iterator;
#endif

#include <memory>
#include <vector>

// Configuration du stockage des enfants des objets composites
using AbsIngredientPtr = std::unique_ptr<class AbsIngredient>;
using AbsIngredientContainer = std::vector<AbsIngredientPtr>;
using AbsIngredientBaseIterator = AbsIngredientContainer::iterator;
using AbsIngredientBaseIterator_const = AbsIngredientContainer::const_iterator;

class AbsIngredientIterator : public AbsIngredientBaseIterator
{
public:
	AbsIngredientIterator(const AbsIngredientContainer::iterator& it) : AbsIngredientBaseIterator(it) {}

	// Operateurs simplifiant l'acces a l'objet 3D sur lequel pointe l'iterateur
	// pour AbsIngredientIterator it;
	//    *it est l'objet 3D
	//    it-> permet d'invoquer une methode sur l'objet 3D
	class AbsIngredient& operator*() { return *((*(AbsIngredientBaseIterator(*this))).get()); }
	class AbsIngredient* operator->() { return (*(AbsIngredientBaseIterator(*this))).get(); }
};

class AbsIngredientIterator_const : public AbsIngredientBaseIterator_const
{
public:
	AbsIngredientIterator_const(const AbsIngredientContainer::const_iterator& it) : AbsIngredientBaseIterator_const(it) {}

	// Operateurs simplifiant l'acces a l'objet 3D sur lequel pointe l'iterateur
	// pour AbsIngredientIterator_const it;
	//    *it est l'objet 3D constant
	//    it-> permet d'invoquer une methode const sur l'objet 3D
	const class AbsIngredient& operator*() { return *((*(AbsIngredientBaseIterator_const(*this))).get()); }
	const class AbsIngredient* operator->() { return (*(AbsIngredientBaseIterator_const(*this))).get(); }
};

#endif // !defined(__ABSINGREDIENTCONTAINER_HEADER_)
