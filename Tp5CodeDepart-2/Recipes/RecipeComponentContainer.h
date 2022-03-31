///////////////////////////////////////////////////////////
//  RecipeComponentContainer.h
//  Implementation of the Class RecipeComponentContainer
//  Created on:      26-oct.-2019
//  Original author: p482457
///////////////////////////////////////////////////////////

#if !defined(__RecipeComponentCONTAINER_HEADER_)
#define __RecipeComponentCONTAINER_HEADER_

#include <memory>
#include <vector>

// Configuration du stockage des enfants des objets composites
using RecipeComponentPtr = std::unique_ptr<class AbsRecipeComponent>;
using RecipeComponentContainer = std::vector<RecipeComponentPtr>;
using RecipeComponentBaseIterator = RecipeComponentContainer::iterator;
using RecipeComponentBaseIterator_const = RecipeComponentContainer::const_iterator;

class RecipeComponentIterator : public RecipeComponentBaseIterator
{
public:
	RecipeComponentIterator(const RecipeComponentContainer::iterator& it) : RecipeComponentBaseIterator(it) {}

	// Operators to simplify access to RecipeComponents refered to by the iterator
	// for RecipeComponentIterator it;
	//    *it is the RecipeComponent
	//    it-> allows invoquing a method on the RecipeComponent
	class AbsRecipeComponent& operator*() { return *((*(RecipeComponentBaseIterator(*this))).get()); }
	class AbsRecipeComponent* operator->() { return (*(RecipeComponentBaseIterator(*this))).get(); }
};

class RecipeComponentIterator_const : public RecipeComponentBaseIterator_const
{
public:
	RecipeComponentIterator_const(const RecipeComponentContainer::const_iterator& it) : RecipeComponentBaseIterator_const(it) {}

	// Operators to simplify access to RecipeComponents refered to by the iterator
	// for RecipeComponentIterator it;
	//    *it is the RecipeComponent
	//    it-> allows invoquing a method on the RecipeComponent
	const class AbsRecipeComponent& operator*() { return *((*(RecipeComponentBaseIterator_const(*this))).get()); }
	const class AbsRecipeComponent* operator->() { return (*(RecipeComponentBaseIterator_const(*this))).get(); }
};

#endif // !defined(__RecipeComponentCONTAINER_HEADER_)
