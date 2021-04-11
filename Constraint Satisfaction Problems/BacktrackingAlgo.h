#pragma once

#include <memory>
#include <unordered_map>

#include "Label.h"
#include "Variable.h"
#include "CSP_Problem.h"
#include "Order_Domain_Values.h"
#include "Select_Unassigned_Variable.h"
#include "Propagation_Algo.h"
class BacktrackingAlgo {
private:
	std::shared_ptr<CSP_Problem> csp_problem;
	std::shared_ptr<Select_Unassigned_Variable> select_unassigned_variable;
	std::shared_ptr<Order_Domain_Values> order_domain_value;
	std::shared_ptr<Propagation_Algo> propagation_algo;

	std::shared_ptr<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>> rec_backtracking(std::shared_ptr<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>> assignment);

public:

	//really ugly indents, check how it should look
	BacktrackingAlgo(std::shared_ptr<CSP_Problem> csp_problem,
		std::shared_ptr<Select_Unassigned_Variable> select_unassigned_variable,
		std::shared_ptr<Order_Domain_Values> order_domain_value,
		std::shared_ptr<Propagation_Algo> propagation_algo
	) : csp_problem{ csp_problem },
		select_unassigned_variable{ select_unassigned_variable },
		order_domain_value{ order_domain_value },
		propagation_algo{propagation_algo}
		{}

	~BacktrackingAlgo()
	{

	}

		std::shared_ptr<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>> recursive_backtracking() {
			std::shared_ptr<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>> assigment = std::make_shared<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>>();
			auto rec = rec_backtracking(assigment);
		return rec;
	}
};
