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

	std::vector < std::shared_ptr<Region>> get_neighbours() {
		return neighbours;
	}
};
