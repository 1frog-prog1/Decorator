#include <iostream>
#include "Decorator.h"

int main() {
	dcr::Beverage* bev1 = new dcr::Expresso;
	std::cout << bev1->getDescrp() << '\n' << bev1->cost() << '\n';

	dcr::Beverage* bev2 = new dcr::HouseBlend;
	bev2 = new dcr::Mocha(bev2);
	bev2 = new dcr::Whip(bev2);
	std::cout << bev2->getDescrp() << '\n' << bev2->cost() << '\n';


	return 0;
}