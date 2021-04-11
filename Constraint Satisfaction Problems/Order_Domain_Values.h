#pragma once
#include <vector>
#include <memory>
#include <unordered_map>

class Order_Domain_Values {
private:

public:
	virtual ~Order_Domain_Values()
	{

	}

	virtual std::vector<std::shared_ptr<Label>> order_values(std::shared_ptr<Variable> variable, std::shared_ptr<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>> assignment) = 0;
};
