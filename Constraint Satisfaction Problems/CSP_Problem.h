#pragma once
#include "Variable.h"

#include <vector>
#include <memory>
#include <unordered_map>
#include <queue>

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

	virtual void reverse_erasing(std::shared_ptr<Variable> variable, std::shared_ptr<Label> value, std::shared_ptr<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>> assignment) = 0;

	virtual std::queue<std::pair<std::shared_ptr<Variable>, std::shared_ptr<Variable>>> get_queue(std::shared_ptr<Variable> variable, std::shared_ptr<Label> value) =0;

	virtual bool check_consistency(std::shared_ptr<Label> value_1, std::shared_ptr<Variable> variable_1, std::shared_ptr<Variable> variable_2)=0;
};