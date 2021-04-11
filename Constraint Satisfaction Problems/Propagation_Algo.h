#pragma once
#include "Label.h"
#include "Variable.h"
#include "CSP_Problem.h"

class Propagation_Algo {
private:
public:
	virtual ~Propagation_Algo()
	{

	}

	virtual void propagate(std::shared_ptr<Variable> variable, std::shared_ptr<Label> value,std::shared_ptr<CSP_Problem> problem, std::shared_ptr<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>> assignment)=0;

	virtual void reverse_propagation(std::shared_ptr<Variable> variable, std::shared_ptr<Label> value, std::shared_ptr<CSP_Problem> problem, std::shared_ptr<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>> assignment) = 0;
};
