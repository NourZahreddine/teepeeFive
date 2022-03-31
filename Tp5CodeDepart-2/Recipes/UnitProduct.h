/****************************************************************************
**
** Classe UnitProduct
** Author: p482457
** Date: 8-nov-2021
**
****************************************************************************/

#ifndef _UnitProduct_Header_
#define _UnitProduct_Header_

#include "AbsProduct.h"

class UnitProduct : public AbsProduct
{
public:
	UnitProduct(std::string name, std::string origin, int quantity, float price);
	virtual ~UnitProduct() {}
	virtual AbsCatalogComponent* clone(void) const;

	virtual void setQuantityPrice(int quantity, float price) override;

	virtual float getPrice() const override;
	virtual int getQuantity() const override;

protected:
	virtual std::ostream& printToStream(std::ostream& o) const;
	int m_quantity;
	float m_price;
};

#endif
