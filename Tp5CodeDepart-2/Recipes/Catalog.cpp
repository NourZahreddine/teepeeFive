

#include "Catalog.h"
#include "Category.h"
#include "WeighedProduct.h"
#include "UnitProduct.h"

Catalog::Catalog()
	: m_catalogRoot("All products")
{
	AbsCatalogComponent& cuisson = m_catalogRoot.addCatalogComponent(Category("Produits de cuisson"));
	AbsCatalogComponent& farine = cuisson.addCatalogComponent(WeighedProduct("farine", "Quebec", 2000, 6.99f));
	AbsCatalogComponent& eau = cuisson.addCatalogComponent(WeighedProduct("eau", "Quebec", 1000, 0.99f));
	AbsCatalogComponent& levure = cuisson.addCatalogComponent(WeighedProduct("levure", "Quebec", 100, 4.99f));
	AbsCatalogComponent& sucre = cuisson.addCatalogComponent(WeighedProduct("sucre", "Quebec", 2000, 2.99f));
	AbsCatalogComponent& sel = cuisson.addCatalogComponent(WeighedProduct("sel", "Quebec", 1000, 1.79f));
	AbsCatalogComponent& huile = cuisson.addCatalogComponent(WeighedProduct("huile", "Italie", 1000, 8.99f));

	AbsCatalogComponent& legumes = m_catalogRoot.addCatalogComponent(Category("Legumes"));
	AbsCatalogComponent& tomates = legumes.addCatalogComponent(WeighedProduct("tomates", "Canada", 796, 1.33f));
	AbsCatalogComponent& oignons = legumes.addCatalogComponent(WeighedProduct("oignons", "Quebec", 1000, 1.99f));
	AbsCatalogComponent& ail = legumes.addCatalogComponent(UnitProduct("ail", "Quebec", 1, 0.79f));
	AbsCatalogComponent& olives = legumes.addCatalogComponent(WeighedProduct("olives", "USA", 398, 2.49f));

	AbsCatalogComponent& produitsLaitiers = m_catalogRoot.addCatalogComponent(Category("Produits Laitiers"));
	AbsCatalogComponent& lait = produitsLaitiers.addCatalogComponent(UnitProduct("lait", "Quebec", 1, 2.99f));
	AbsCatalogComponent& fromage = produitsLaitiers.addCatalogComponent(WeighedProduct("fromage", "Quebec", 320, 6.99f));
	AbsCatalogComponent& oeufs = produitsLaitiers.addCatalogComponent(UnitProduct("oeufs", "Quebec", 12, 3.59f));

	AbsCatalogComponent& epices = m_catalogRoot.addCatalogComponent(Category("Epices"));
	AbsCatalogComponent& basilic = epices.addCatalogComponent(WeighedProduct("basilic", "Quebec", 21, 2.00f));

	AbsCatalogComponent& fruits = m_catalogRoot.addCatalogComponent(Category("Fruits"));
	AbsCatalogComponent& bananes = fruits.addCatalogComponent(WeighedProduct("banane", "Guatemala", 1000, 1.96f));
	AbsCatalogComponent& poires = fruits.addCatalogComponent(WeighedProduct("poire", "USA", 1000, 1.99f));
	AbsCatalogComponent& orange = fruits.addCatalogComponent(UnitProduct("orange", "USA", 1, 1.49f));
	AbsCatalogComponent& pomme = fruits.addCatalogComponent(WeighedProduct("pomme", "Quebec", 1000, 5.49f));
	AbsCatalogComponent& bleuets = fruits.addCatalogComponent(UnitProduct("bleuet", "Mexique", 170, 1.99f));
}


Catalog::~Catalog()
{
}

const AbsProduct* Catalog::findProduct(std::string productName) const
{
	return m_catalogRoot.findProduct(productName);

}

std::ostream & operator<<(std::ostream & o, const Catalog & c)
{
	return o << c.m_catalogRoot;
}
