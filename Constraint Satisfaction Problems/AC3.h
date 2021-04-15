#pragma once
#include <queue>

#include "Propagation_Algo.h"

class AC3 : public Propagation_Algo {
private:

public:

	bool remove_inconsistent(std::shared_ptr<Variable> variable_1, std::shared_ptr<Variable> variable_2, std::shared_ptr<CSP_Problem> problem);
	bool add_inconsistent(std::shared_ptr<Label> value, std::shared_ptr<Variable> variable_1, std::shared_ptr<Variable> variable_2, std::shared_ptr<CSP_Problem> problem);

	// Inherited via Propagation_Algo
	virtual void propagate(std::shared_ptr<Variable> variable, std::shared_ptr<Label> value, std::shared_ptr<CSP_Problem> problem, std::shared_ptr<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>> assignment) override;
	virtual void reverse_propagation(std::shared_ptr<Variable> variable, std::shared_ptr<Label> value, std::shared_ptr<CSP_Problem> problem, std::shared_ptr<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>> assignment) override;
	
	

};
