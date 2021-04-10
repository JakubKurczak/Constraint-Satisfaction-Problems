#pragma once
#include "Order_Domain_Values.h"
#include "Label.h"
#include "Variable.h"

class Least_Constraining_Value : public Order_Domain_Values {
private:

public:

	~Least_Constraining_Value()
	{

	}

	std::vector<std::shared_ptr<Label>> order_values(std::shared_ptr<Variable> variable, std::shared_ptr<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>> assignment) {

	}
};
