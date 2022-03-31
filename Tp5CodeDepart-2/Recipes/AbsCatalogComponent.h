/****************************************************************************
**
** Classe AbsCatalogComponent
** Author: p482457
** Date: 25-oct-2019
**
****************************************************************************/

#ifndef _AbsCatalogComponent_Header_
#define _AbsCatalogComponent_Header_

#include <iostream>

#include "CatalogComponentContainer.h"

class AbsCatalogComponent
{
public:
	AbsCatalogComponent(std::string name) : m_name(name) {};
	virtual AbsCatalogComponent* clone(void) const = 0;

	virtual std::string getName(void) const { return m_name; };
	virtual void setName(std::string name) { m_name = name; };
	
	virtual AbsCatalogComponent& addCatalogComponent(const AbsCatalogComponent& member) = 0;
	virtual CatalogComponentIterator begin() = 0;
	virtual CatalogComponentIterator_const cbegin() const = 0;
	virtual CatalogComponentIterator_const cend() const = 0;
	virtual CatalogComponentIterator end() = 0;
	virtual void deleteCatalogComponent( CatalogComponentIterator_const child ) = 0;

	virtual const class AbsProduct* findProduct(std::string productName) const = 0;


protected:
	friend std::ostream& operator<<(std::ostream & o, const AbsCatalogComponent & cc);
	virtual std::ostream& printToStream(std::ostream& o) const = 0;

	std::string m_name;
};

#endif
