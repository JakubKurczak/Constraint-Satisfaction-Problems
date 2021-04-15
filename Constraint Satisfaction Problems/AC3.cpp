#include "AC3.h"

bool AC3::remove_inconsistent(std::shared_ptr<Variable> variable_1, std::shared_ptr<Variable> variable_2, std::shared_ptr<CSP_Problem> problem)
{
	bool removed = false;
	for (auto domain : variable_1->get_domain_labels()) {
		bool is_consistent = false;
		for (auto value : domain->get_domain()) {
			if (!problem->check_consistency(value, variable_1, variable_2)) {
				removed = true;
				variable_1->exclude_from_domain(*value);
			}
		}
	}

	return removed;
}

bool AC3::add_inconsistent(std::shared_ptr<Label> value, std::shared_ptr<Variable> variable_1, std::shared_ptr<Variable> variable_2, std::shared_ptr<CSP_Problem> problem)
{
	bool added = false;
	
	if (!problem->check_consistency(value, variable_1, variable_2)) {
		added = true;
		variable_1->add_to_domain(value);
	}
		
	

	return added;
}

void AC3::propagate(std::shared_ptr<Variable> variable, std::shared_ptr<Label> value, std::shared_ptr<CSP_Problem> problem, std::shared_ptr<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>> assignment)
{
	std::queue<std::pair<std::shared_ptr<Variable>, std::shared_ptr<Variable>>> queue = problem->get_queue(variable, value);

	while (!queue.empty()) {
		auto v_pair = queue.front();
		queue.pop();

		if (remove_inconsistent(v_pair.first, v_pair.second, problem)) {
			for (auto n : v_pair.first->get_neighbours())
				queue.push(std::make_pair(n, v_pair.first));

		}
	}
}

void AC3::reverse_propagation(std::shared_ptr<Variable> variable, std::shared_ptr<Label> value, std::shared_ptr<CSP_Problem> problem, std::shared_ptr<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>> assignment)
{
	std::queue<std::pair<std::shared_ptr<Variable>, std::shared_ptr<Variable>>> queue = problem->get_queue(variable, value);

	while (!queue.empty()) {
		auto v_pair = queue.front();
		queue.pop();

		if (add_inconsistent(value,v_pair.first, v_pair.second, problem)) {
			for (auto n : v_pair.first->get_neighbours())
				queue.push(std::make_pair(n, v_pair.first));

		}
	}
}
