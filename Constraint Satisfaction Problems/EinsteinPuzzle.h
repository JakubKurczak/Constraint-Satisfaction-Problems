#pragma once
#include "CSP_Problem.h"
#include "Person.h"

class EinsteinPuzzle: public  CSP_Problem{
private:
	std::vector<std::shared_ptr<Person>> people;

	void init_people();
public:

	EinsteinPuzzle() {
		init_people();
	}


	~EinsteinPuzzle()
	{

	}

	 bool is_complete(std::shared_ptr<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>> assignment);

	 bool are_constraint_satisfied(std::shared_ptr<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>> assignment);

	 std::vector<std::shared_ptr<Variable>> get_variables();



	 bool is_linked(std::shared_ptr<Variable> variable, std::shared_ptr<Label> value, std::shared_ptr<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>> assignment);

	 // Inherited via CSP_Problem
	 virtual void erase_inconsistent(std::shared_ptr<Variable> variable, std::shared_ptr<Label> value, std::shared_ptr<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>> assignment) override;

	 virtual std::vector<std::shared_ptr<Variable>> get_linked(std::shared_ptr<Variable> variable, std::shared_ptr<Label> value, std::shared_ptr<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>> assignment) override;

};
