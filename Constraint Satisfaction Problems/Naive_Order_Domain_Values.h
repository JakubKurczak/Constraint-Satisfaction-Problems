#pragma once

#include "Order_Domain_Values.h"
#include "Label.h"
#include "Variable.h"

class Naive_Order_Domain_Values : public Order_Domain_Values {
public:

	
	std::vector<std::shared_ptr<Label>> order_values(std::shared_ptr<Variable> variable, std::shared_ptr<std::unordered_map<std::shared_ptr<Variable>, std::vector<std::shared_ptr<Label>>>> assignment) {
		std::vector<std::shared_ptr<Label>> values;
		
		for (std::shared_ptr<Label> label : variable->get_domain_labels()) {
			
			bool add_value = assignment->find(variable) == assignment->end();
			//even if variable is already in 
			if (!add_value) {
				add_value = true;
				for (auto s : assignment->find(variable)->second)
					if (s->get_label_name() == label->get_label_name())
						add_value =  false;
			}

			if(add_value)
			for (auto l : label->get_domain()) {
				values.push_back(l);
			}
		}

		std::sort(values.begin(), values.end(), [variable](std::shared_ptr<Label> a, std::shared_ptr<Label>b) { return variable->get_constraint_value(a) > variable->get_constraint_value(b); });

		return values;
	}

	~Naive_Order_Domain_Values()
	{

	}
};
