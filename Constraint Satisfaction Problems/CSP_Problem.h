#pragma once
#include "Variable.h"

#include <vector>
#include <memory>
#include <unordered_map>

class CSP_Problem {
private:

public:

	virtual ~CSP_Problem()
	{

	}


	virtual bool is_complete(std::shared_ptr<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>> assignment) = 0;

	virtual bool are_constraint_satisfied(std::shared_ptr<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>> assignment) = 0;

	virtual std::vector<std::shared_ptr<Variable>> get_variables()=0;

	virtual void erase_inconsistent(std::shared_ptr<Variable> variable,std::shared_ptr<Label> value, std::shared_ptr<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>> assignment) = 0;

	virtual std::vector<std::shared_ptr<Variable>> get_linked(std::shared_ptr<Variable> variable, std::shared_ptr<Label> value, std::shared_ptr<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>> assignment) = 0;
};