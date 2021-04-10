#include "EinsteinPuzzle.h"
#include <iostream>
void EinsteinPuzzle::init_people()
{
	
	std::vector<std::shared_ptr<Label>> nationality_domain_values;
	
	nationality_domain_values.push_back(std::make_shared<Label>("nationality","Norwegian"));
	nationality_domain_values.push_back(std::make_shared<Label>("nationality", "Englishman"));
	nationality_domain_values.push_back(std::make_shared<Label>("nationality", "Dane"));
	nationality_domain_values.push_back(std::make_shared<Label>("nationality", "German"));
	nationality_domain_values.push_back(std::make_shared<Label>("nationality", "Swede"));
	
	std::vector<std::shared_ptr<Label>> house_color_domain_values;

	house_color_domain_values.push_back(std::make_shared<Label>("house_color", "yellow"));
	house_color_domain_values.push_back(std::make_shared<Label>("house_color", "white"));
	house_color_domain_values.push_back(std::make_shared<Label>("house_color", "red"));
	house_color_domain_values.push_back(std::make_shared<Label>("house_color", "green"));
	house_color_domain_values.push_back(std::make_shared<Label>("house_color", "blue"));

	std::vector<std::shared_ptr<Label>> house_num_domain_values;

	house_num_domain_values.push_back(std::make_shared<Label>("house_num", "1"));
	house_num_domain_values.push_back(std::make_shared<Label>("house_num", "2"));
	house_num_domain_values.push_back(std::make_shared<Label>("house_num", "3"));
	house_num_domain_values.push_back(std::make_shared<Label>("house_num", "4"));
	house_num_domain_values.push_back(std::make_shared<Label>("house_num", "5"));

	std::vector<std::shared_ptr<Label>> beverage_domain_values;

	beverage_domain_values.push_back(std::make_shared<Label>("beverage", "tea"));
	beverage_domain_values.push_back(std::make_shared<Label>("beverage", "milk"));
	beverage_domain_values.push_back(std::make_shared<Label>("beverage", "water"));
	beverage_domain_values.push_back(std::make_shared<Label>("beverage", "beer"));
	beverage_domain_values.push_back(std::make_shared<Label>("beverage", "coffe"));

	std::vector<std::shared_ptr<Label>> pet_domain_values;

	pet_domain_values.push_back(std::make_shared<Label>("pet", "cat"));
	pet_domain_values.push_back(std::make_shared<Label>("pet", "bird"));
	pet_domain_values.push_back(std::make_shared<Label>("pet", "dog"));
	pet_domain_values.push_back(std::make_shared<Label>("pet", "horse"));
	pet_domain_values.push_back(std::make_shared<Label>("pet", "fish"));

	std::vector<std::shared_ptr<Label>> tabaco_domain_values;

	tabaco_domain_values.push_back(std::make_shared<Label>("tabaco", "mentol"));
	tabaco_domain_values.push_back(std::make_shared<Label>("tabaco", "no_filter"));
	tabaco_domain_values.push_back(std::make_shared<Label>("tabaco", "light"));
	tabaco_domain_values.push_back(std::make_shared<Label>("tabaco", "pipe"));
	tabaco_domain_values.push_back(std::make_shared<Label>("tabaco", "cigar"));

	std::vector<std::shared_ptr<Label>> whole_domain;

	whole_domain.push_back(std::make_shared<Label>("nationality", nationality_domain_values));
	whole_domain.push_back(std::make_shared<Label>("house_color", house_color_domain_values));
	whole_domain.push_back(std::make_shared<Label>("house_num", house_num_domain_values));
	whole_domain.push_back(std::make_shared<Label>("beverage", beverage_domain_values));
	whole_domain.push_back(std::make_shared<Label>("tabaco", tabaco_domain_values));
	whole_domain.push_back(std::make_shared<Label>("pet", pet_domain_values));

	for (int ii = 0; ii < 5; ii++) {
		auto s = std::to_string(ii + 1);
		auto person = std::make_shared<Person>(s, whole_domain);
		people.push_back(person);
		if (people.size() > 1) {
			people[ii - 1]->add_right_neighbour(person);
			person->add_left_neighbour(people[ii - 1]);
		}
	}
}

bool EinsteinPuzzle::is_complete(std::shared_ptr<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>> assignment)
{
	for (auto p : people)
		if (assignment->find(p) == assignment->end())
			return false;
		else if (assignment->find(p)->second.size() < p->get_domain_labels().size())
			return false;
	return true;
}

bool EinsteinPuzzle::are_constraint_satisfied(std::shared_ptr<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>> assignment)
{
	for (auto p : people)
		p->clear_value_labels();

	for (auto iter = assignment->begin(); iter != assignment->end(); iter++) {
		for (auto l : iter->second) {
			iter->first->add_value_label(l);
		}
	}

	for (auto iter = assignment->begin(); iter != assignment->end(); iter++) {
		for (auto l1 : iter->second) {
			for (auto ite_wew = assignment->begin(); ite_wew != assignment->end(); ite_wew++) {
				if (iter != ite_wew)
					for (auto l2 : ite_wew->second) {
						if (l1 == l2)
							return false;
					}
			}
		}
	}

	for (auto p : people)
		if (!p->are_constraint_not_voided())
			return false;
	return true;
}

std::vector<std::shared_ptr<Variable>> EinsteinPuzzle::get_variables()
{
	std::vector<std::shared_ptr<Variable>> v;

	for (auto p : people) {
		v.push_back(p);
	}

	return v;
}
