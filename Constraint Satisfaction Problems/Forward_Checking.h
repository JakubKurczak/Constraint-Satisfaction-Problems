#pragma once
#include "Propagation_Algo.h"
class Forward_Checking : public Propagation_Algo {
private:

public:


	~Forward_Checking()
	{

	}

	void propagate(std::shared_ptr<Variable> variable, std::shared_ptr<Label> value, std::shared_ptr<CSP_Problem> problem, std::shared_ptr<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>> assignment) {
		std::vector<std::shared_ptr<Variable>> linked_variables = problem->get_linked(variable, value, assignment);
		for (auto v : linked_variables)
			problem->erase_inconsistent(v,value,assignment);
	}
};