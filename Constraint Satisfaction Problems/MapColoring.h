#pragma once
#include "Region.h"
#include "CSP_Problem.h"

#include <vector>
#include <random>
#include <string>
#include <math.h>

#define CHANCE_FOR_EXTRA_NEIGHBOUR 50

class MapColoring : public CSP_Problem{
private:
	
	std::vector<std::shared_ptr<Region>> regions;
	std::random_device r_dev;
	std::mt19937 r_eng;

	std::shared_ptr<Region> get_neighbour(std::shared_ptr<Region> region);

	void init_properly(int region_num, int color_num);

public:

	MapColoring(int region_num, int color_num) : r_eng(r_dev()) {
		
		this->init_properly(region_num, color_num);
	}

	MapColoring() : r_eng(r_dev()){
		this->init_properly(5, 3);

	}

	~MapColoring()
	{

	}

	// Inherited via CSP_Problem
	virtual bool is_complete(std::shared_ptr<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>> assignment);

	virtual bool are_constraint_satisfied(std::shared_ptr<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>> assignment);

	virtual std::vector<std::shared_ptr<Variable>> get_variables();


	// Inherited via CSP_Problem
	virtual void erase_inconsistent(std::shared_ptr<Variable> variable, std::shared_ptr<Label> value, std::shared_ptr<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>> assignment) override;

	virtual std::vector<std::shared_ptr<Variable>> get_linked(std::shared_ptr<Variable> variable, std::shared_ptr<Label> value, std::shared_ptr<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>> assignment) override;


	// Inherited via CSP_Problem
	virtual void reverse_erasing(std::shared_ptr<Variable> variable, std::shared_ptr<Label> value, std::shared_ptr<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>> assignment) override;

};
