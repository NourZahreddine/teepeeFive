/****************************************************************************
**
** Classe WeighedProduct
** Author: p482457
** Date: 8-nov-2021
**
****************************************************************************/

#ifndef _WeighedProduct_Header_
#define _WeighedProduct_Header_

#include "AbsProduct.h"

class WeighedProduct : public AbsProduct
{
public:
	WeighedProduct(std::string name, std::string origin, int weight, float price);
	virtual ~WeighedProduct() {}
	virtual AbsCatalogComponent* clone(void) const;

	void setQuantityPrice(int quantity, float price);

	float getPrice() const override;
	int getQuantity() const override;

protected:
	virtual std::ostream& printToStream(std::ostream& o) const;
	int m_weight;
	float m_price;
};

#endif
