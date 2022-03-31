/****************************************************************************
**
** Classe Category
** Author: p482457
** Date: 8-nov-2021
**
****************************************************************************/

#ifndef _Category_Header_
#define _Category_Header_

#include "AbsCatalogComponent.h"
#include "AbsProduct.h"

class Category : public AbsCatalogComponent
{
public:
	Category(std::string name);
	Category(const Category& mdd);
	virtual Category* clone(void) const;

	virtual AbsCatalogComponent& addCatalogComponent( const AbsCatalogComponent& member);
	virtual CatalogComponentIterator begin();
	virtual CatalogComponentIterator_const cbegin() const;
	virtual CatalogComponentIterator_const cend() const;
	virtual CatalogComponentIterator end();
	virtual void deleteCatalogComponent(CatalogComponentIterator_const child);
	virtual void deleteAllComponents(void);

	const AbsProduct* findProduct(std::string productName) const;

private:
	virtual std::ostream& printToStream(std::ostream& o) const;
	std::ostream& indent(std::ostream& o) const;

	CatalogComponentContainer m_products;
	static int m_indent;
};

#endif