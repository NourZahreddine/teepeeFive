/****************************************************************************
**
** Classe AbsProduct
** Author: p482457
** Date: 8-nov-2021
**
****************************************************************************/

#ifndef _AbsProduct_Header_
#define _AbsProduct_Header_

#include "AbsCatalogComponent.h"

class AbsProduct : public AbsCatalogComponent
{
public:
	AbsProduct(std::string name, std::string origin );

	std::string getOrigin() const { return m_origin; }
	void setOrigin( std::string origin ) { m_origin = origin;  }

	virtual void setQuantityPrice(int quantity, float price) = 0;
	virtual float getPrice() const = 0;
	virtual int getQuantity() const = 0;

	virtual AbsCatalogComponent& addCatalogComponent(const AbsCatalogComponent& member);
	virtual CatalogComponentIterator begin();
	virtual CatalogComponentIterator_const cbegin() const;
	virtual CatalogComponentIterator_const cend() const;
	virtual CatalogComponentIterator end();
	virtual void deleteCatalogComponent(CatalogComponentIterator_const child);

	virtual const class AbsProduct* findProduct(std::string productName) const override;

private:
	std::string m_origin;

	static CatalogComponentContainer m_emptyContainer;
};

#endif
