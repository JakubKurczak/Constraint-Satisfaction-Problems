#pragma once
#include "Select_Unassigned_Variable.h"
#include "Variable.h"
#include "CSP_Problem.h"
#include <algorithm>

class Minimum_Remaining_Values : public Select_Unassigned_Variable {
private:

public:

	std::shared_ptr<Variable> select_variable(std::shared_ptr<CSP_Problem> csp_problem, std::shared_ptr<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>> assignment) {
		std::vector<std::shared_ptr<Variable>> contestants;
		
		for (auto variable : csp_problem->get_variables())
			if (assignment->find(variable) == assignment->end())
				contestants.push_back(variable);
			else if (assignment->find(variable)->second.size() < variable->get_domain_labels().size())
				contestants.push_back(variable);
		std::sort(contestants.begin(), contestants.end(), [](std::shared_ptr<Variable> a, std::shared_ptr<Variable> b) {return a->get_available_values() > b->get_available_values(); });

		return *contestants.begin();
	}

	~Minimum_Remaining_Values()
	{

	}
};
