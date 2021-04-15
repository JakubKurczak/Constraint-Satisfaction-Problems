#include "BacktrackingAlgo.h"
#include <iostream>

std::shared_ptr<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>> BacktrackingAlgo::rec_backtracking(std::shared_ptr<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>> assignment)
{
	std::cout << "_______________" << std::endl;
	for (auto iter = assignment->begin(); iter != assignment->end(); iter++) {
		std::cout << (iter->first->get_name()) << std::endl;
		for (auto label : iter->second) {
			std::cout << label->get_label_name() << ": ";
			std::cout << label->get_value() << std::endl;
			
		}
	}

	if (this->csp_problem->is_complete(assignment))
		return assignment;
	std::shared_ptr<Variable> variable = this->select_unassigned_variable->select_variable(this->csp_problem, assignment);

	for (std::shared_ptr<Label> label : this->order_domain_value->order_values(variable, assignment)) {
		
		counter += 1;

		if (assignment->find(variable) == assignment->end()) {
			(*assignment)[variable] = std::vector<std::shared_ptr<Label>>();
		}
		(*assignment)[variable].push_back(label);
		if (csp_problem->are_constraint_satisfied(assignment)) {
			this->propagation_algo->propagate(variable, label, this->csp_problem, assignment);//nawrot jak pusta dziedzina
			auto result = rec_backtracking(assignment);
			if (result != nullptr)
				return result;

		}
		int index = 0;
		this->propagation_algo->reverse_propagation(variable, label, this->csp_problem, assignment);
		for (auto l: (*assignment)[variable]) {
			if (l == label)
				(*assignment)[variable].erase((*assignment)[variable].begin() + index);
			index++;
		}
	}

	return std::shared_ptr<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>>(nullptr);
}

std::shared_ptr<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>> BacktrackingAlgo::rec_backtracking_performance_tracking(std::shared_ptr<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>> assignment)
{

	if (this->csp_problem->is_complete(assignment)) {
		solution_counter += 1;
		std::cout << "Solution "<<this->solution_counter<<"Num of searches: "<<this->get_counter() << std::endl;
		return std::shared_ptr<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>>(nullptr);
	}		
	std::shared_ptr<Variable> variable = this->select_unassigned_variable->select_variable(this->csp_problem, assignment);

	for (std::shared_ptr<Label> label : this->order_domain_value->order_values(variable, assignment)) {

		counter += 1;

		if (assignment->find(variable) == assignment->end()) {
			(*assignment)[variable] = std::vector<std::shared_ptr<Label>>();
		}
		(*assignment)[variable].push_back(label);
		if (csp_problem->are_constraint_satisfied(assignment)) {
			this->propagation_algo->propagate(variable, label, this->csp_problem, assignment);//nawrot jak pusta dziedzina
			auto result = rec_backtracking_performance_tracking(assignment);
			if (result != nullptr)
				return result;

		}
		int index = 0;
		this->propagation_algo->reverse_propagation(variable, label, this->csp_problem, assignment);
		for (auto l : (*assignment)[variable]) {
			if (l == label)
				(*assignment)[variable].erase((*assignment)[variable].begin() + index);
			index++;
		}
	}

	return std::shared_ptr<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>>(nullptr);
}
