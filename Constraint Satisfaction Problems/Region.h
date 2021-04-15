#pragma once
#include <vector>
#include <memory>
#include <unordered_set>
#include <stdexcept>

#include "Variable.h"

class Region: public Variable{
private:

	std::vector<std::shared_ptr<Region>> neighbours;
	
public:

	Region(std::string& region_name, std::vector<std::shared_ptr<Label>>& domain_labels) :
		Variable(region_name,domain_labels)
	{
				
	}

	~Region()
	{

	}

	void add_neighbour(std::shared_ptr<Region> other_region) {
		if (!is_already_neighbour(*other_region)) {
			neighbours.push_back(other_region);
		}
	}


	bool are_constraint_satisfied() {
		if (this->is_value_label_set("color")) {
			std::string label_value = this->get_label_value("color");
			for (auto n : this->neighbours)
				if (n->is_value_label_set("color"))
					if (n->get_label_value("color") == label_value)
						return false;
		}	
	return true;
	}

	int neighbours_number() {
		return this->neighbours.size();
	}

	bool is_already_neighbour(Region& other_region) {
		for (auto neighbour : this->neighbours)
			if (other_region == *neighbour)
				return true;

		return false;
	}

	std::vector < std::shared_ptr<Variable>> get_neighbours() override {
		std::vector < std::shared_ptr<Variable>> v;
		for (auto iter = neighbours.begin(); iter != neighbours.end(); iter++)
			v.push_back(*iter);
		return v;
	}

	int get_constraint_value(std::shared_ptr<Label> label) override {
		int constraints = 0;
		for (auto n : this->neighbours)
			if (std::find(n->get_domain_labels()[0]->get_domain().begin(), n->get_domain_labels()[0]->get_domain().end(), label) != n->get_domain_labels()[0]->get_domain().end())
				constraints += 1;
		return constraints;
	}
	
	int get_available_values() override {
		return this->get_domain_labels()[0]->get_domain().size();
	}

};
