///////////////////////////////////////////////////////////
//  CatalogComponentContainer.h
//  Implementation of the Class CatalogComponentContainer
//  Created on:      26-oct.-2019
//  Original author: p482457
///////////////////////////////////////////////////////////

#if !defined(EA_1A8475D5_4734_484c_8758_A92F295DDED0__INCLUDED_)
#define EA_1A8475D5_4734_484c_8758_A92F295DDED0__INCLUDED_

#include <memory>
#include <list>

// Configuration du stockage des enfants des objets composites
using CatalogComponentPtr = std::unique_ptr<class AbsCatalogComponent>;
using CatalogComponentContainer = std::list<CatalogComponentPtr>;
using CatalogComponentBaseIterator = CatalogComponentContainer::iterator;
using CatalogComponentBaseIterator_const = CatalogComponentContainer::const_iterator;

class CatalogComponentIterator : public CatalogComponentBaseIterator
{
public:
	CatalogComponentIterator(const CatalogComponentContainer::iterator& it) : CatalogComponentBaseIterator(it) {}

	// Operateurs simplifiant l'acces a l'objet 3D sur lequel pointe l'iterateur
	// pour CatalogComponentIterator it;
	//    *it est l'objet 3D
	//    it-> permet d'invoquer une methode sur l'objet 3D
	class AbsCatalogComponent& operator*() { return *((*(CatalogComponentBaseIterator(*this))).get()); }
	class AbsCatalogComponent* operator->() { return (*(CatalogComponentBaseIterator(*this))).get(); }
};

class CatalogComponentIterator_const : public CatalogComponentBaseIterator_const
{
public:
	CatalogComponentIterator_const(const CatalogComponentContainer::const_iterator& it) : CatalogComponentBaseIterator_const(it) {}

	// Operateurs simplifiant l'acces a l'objet 3D sur lequel pointe l'iterateur
	// pour CatalogComponentIterator_const it;
	//    *it est l'objet 3D constant
	//    it-> permet d'invoquer une methode const sur l'objet 3D
	const class AbsCatalogComponent& operator*() { return *((*(CatalogComponentBaseIterator_const(*this))).get()); }
	const class AbsCatalogComponent* operator->() { return (*(CatalogComponentBaseIterator_const(*this))).get(); }
};

#endif // !defined(EA_1A8475D5_4734_484c_8758_A92F295DDED0__INCLUDED_)
