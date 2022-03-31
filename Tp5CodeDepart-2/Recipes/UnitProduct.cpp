#include <string>

#include "UnitProduct.h"

UnitProduct::UnitProduct(std::string name, std::string origin, int quantity, float price)
	: AbsProduct(name, origin), m_quantity(quantity), m_price(price)
{
}

AbsCatalogComponent * UnitProduct::clone(void) const 
{ 
	// À compléter pour construire un nouvel objet UnitProduct en appelant le constructeur de copie
	return nullptr; // À remplacer
}

void UnitProduct::setQuantityPrice(int quantity, float price)
{
	m_quantity = quantity;
	m_price = price;
}

float UnitProduct::getPrice() const
{ 
	return m_price; 
}

int UnitProduct::getQuantity() const 
{ 
	return m_quantity; 
}

std::ostream & UnitProduct::printToStream(std::ostream & o) const
{
	// À compléter pour imprimer sur un stream un produit vendu à l'unité
	return o;
}
