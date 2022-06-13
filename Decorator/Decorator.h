#include <string>

#ifndef _DECORATOR__
#define _DECORATOR__

namespace dcr {

	class Beverage {
	protected:
		std::string descrp;
		float b_cost;

	public:
		std::string getDescrp() {
			return descrp;
		}

		virtual float cost() = NULL;
	};

	class CondDecor : public Beverage {
	protected:
		Beverage* bev;

	public: 

		CondDecor() {}

		std::string getDescrp() {
			return descrp;
		}

		float cost() {
			return bev->cost() + b_cost;
		}

	};

	class HouseBlend : public Beverage {
	public:
		HouseBlend() {
			b_cost = 0.89;
			descrp = "House Blend Coffee";
		}

		float cost() override {
			return b_cost;
		}
	};

	class Expresso : public Beverage {
	public:
		Expresso() {
			b_cost = 1.99;
			descrp = "Expresso";
		}

		float cost() override {
			return b_cost;
		}
	};

	class Mocha : public CondDecor {
	public:
		Mocha(Beverage* bev) {
			this->bev = bev;
			descrp = this->bev->getDescrp() + ", Mocha";
			b_cost = 0.20;
		}
	};

	class Whip : public CondDecor {
	public:
		Whip(Beverage* bev) {
			this->bev = bev;
			descrp = this->bev->getDescrp() + ", Whip";
			b_cost = 0.10;
		}
	
	};

}


#endif // _DECORATOR__