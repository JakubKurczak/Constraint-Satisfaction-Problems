#pragma once
#include <memory>
#include <unordered_map>

class Select_Unassigned_Variable {
private:

public:

	virtual ~Select_Unassigned_Variable()
	{

	}

	virtual std::shared_ptr<Variable> select_variable(std::shared_ptr<CSP_Problem> csp_problem, std::shared_ptr<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>> assignment)=0;
};
