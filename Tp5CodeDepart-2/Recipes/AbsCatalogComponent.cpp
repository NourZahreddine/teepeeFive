#include "AbsCatalogComponent.h"

std::ostream& operator<<(std::ostream & o, const AbsCatalogComponent & cc)
{
	return cc.printToStream(o);
}
