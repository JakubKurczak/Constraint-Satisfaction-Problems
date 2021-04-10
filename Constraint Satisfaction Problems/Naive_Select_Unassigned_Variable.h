#pragma once
#include "Select_Unassigned_Variable.h"
#include "Variable.h"
#include "CSP_Problem.h"

class Naive_Select_Unassigned_Variable : public Select_Unassigned_Variable {
private:

public:

	std::shared_ptr<Variable> select_variable(std::shared_ptr<CSP_Problem> csp_problem, std::shared_ptr<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>> assignment) {
		for (auto variable : csp_problem->get_variables())
			if (assignment->find(variable) == assignment->end())
				return variable;
			else if (assignment->find(variable)->second.size() < variable->get_domain_labels().size())
				return variable;
	}

};
