#include "MapColoring.h"


//its get new random neighbour from regions that are not neighbour to region
std::shared_ptr<Region> MapColoring::get_neighbour(std::shared_ptr<Region> region)
{
	std::vector<std::shared_ptr<Region>> v_regions;
	for (auto r_region : this->regions) {
		if (r_region != region && !region->is_already_neighbour(*region))
			v_regions.push_back(r_region);
	}

	std::uniform_int_distribution<int> r_index(0, v_regions.size() - 1);

	return v_regions[r_index(this->r_eng)];
}

void MapColoring::init_properly(int region_num,int color_num)
{

	std::vector<std::shared_ptr<Label>> domain_labels;

	domain_labels.push_back(std::make_shared<Label>("color", "red"));
	domain_labels.push_back(std::make_shared<Label>("color", "green"));
	domain_labels.push_back(std::make_shared<Label>("color", "blue"));

	std::shared_ptr<Label> domain_label = std::make_shared<Label>("color", domain_labels);
	std::vector<std::shared_ptr<Label>> v_labels;
	v_labels.push_back(domain_label);
	for (int ii = 0; ii < region_num; ii++) {
		std::string s("region_" + std::to_string(ii));
		std::shared_ptr<Region> region_pointer = std::make_shared<Region>(s, v_labels);
		
		if (!this->regions.empty()) {
			std::uniform_int_distribution<int> random_neighbour(0, this->regions.size()-1);
			int region_index = random_neighbour(this->r_eng);
			
			//can i make it one operation within add_neighour function?
			region_pointer->add_neighbour(this->regions[region_index]);
			this->regions[region_index]->add_neighbour(region_pointer);

		}

		this->regions.push_back(region_pointer);
		
		if (this->regions.size() > 2) {
			std::uniform_int_distribution<int> extra_binding(1, 100 / CHANCE_FOR_EXTRA_NEIGHBOUR);
			if (extra_binding(this->r_eng) == 1) {
				std::shared_ptr<Region> region = get_neighbour(region_pointer);

				region->add_neighbour(region_pointer);
				region_pointer->add_neighbour(region);
			}
		}
	}
}

bool MapColoring::is_complete(std::shared_ptr<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>> assignment)
{	
	return assignment->size() == regions.size();
}

bool MapColoring::are_constraint_satisfied(std::shared_ptr<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>> assignment)
{
	for (auto r : regions)
		r->clear_value_labels();

	for (auto iter = assignment->begin(); iter != assignment->end(); iter++) {
		for (auto l : iter->second) {
			iter->first->add_value_label(l);
		}
	}

	for (auto r : regions)
		if (!r->are_constraint_satisfied())
			return false;
	return true;
}


std::vector<std::shared_ptr<Variable>> MapColoring::get_variables()
{
	std::vector<std::shared_ptr<Variable>> v;
	
	for (auto r : regions) {
		v.push_back(r);
	}

	return v;
}

void MapColoring::erase_inconsistent(std::shared_ptr<Variable> variable, std::shared_ptr<Label> value, std::shared_ptr<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>> assignment)
{
	for (auto domain : variable->get_domain_labels())
		if (domain->get_label_name() == value->get_label_name()) {
			auto iter = std::find(domain->get_domain().begin(), domain->get_domain().end(), value);
			if (iter != domain->get_domain().end())
				domain->get_domain().erase(iter);
		}
}

std::vector<std::shared_ptr<Variable>> MapColoring::get_linked(std::shared_ptr<Variable> variable, std::shared_ptr<Label> value, std::shared_ptr<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>> assignment)
{
	std::vector<std::shared_ptr<Variable>> v_array;
	std::shared_ptr<Region> region = std::dynamic_pointer_cast<Region>(variable);
	for (auto r : region->get_neighbours())
		v_array.push_back(r);

	return v_array;
}
