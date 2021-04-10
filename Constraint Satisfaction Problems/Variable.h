#pragma once

#include "Label.h"
#include <vector>

class Variable {
private:
	std::vector<std::shared_ptr<Label>> domain_labels;
	std::vector<std::shared_ptr<Label>> value_labels;
	std::string variable_name;
public:


	Variable(std::string& variable_name, std::vector<std::shared_ptr<Label>>& domain_labels) : variable_name{ variable_name }{
		for (auto l : domain_labels) {
			this->domain_labels.push_back(std::make_shared<Label>(*l));
		}
	};

	std::vector<std::shared_ptr<Label>>& get_domain_labels() { return domain_labels; }


	bool operator==(const Variable& other) {
		return this->variable_name.compare(other.variable_name) == 0;
	}

	bool operator!=(const Variable& other) {
		return this->variable_name.compare(other.variable_name) != 0;
	}

	void exclude_from_domain(Label& label) {
		for (int ii = 0; ii < domain_labels.size(); ii++)
			if (domain_labels[ii]->get_label_name().compare(label.get_label_name()) == 0)
				for (int ij=0;ij< domain_labels[ii]->get_domain().size();ij++)
					if (domain_labels[ii]->get_domain()[ij]->get_value().compare(label.get_value()) == 0) {
						domain_labels[ii]->get_domain().erase(domain_labels[ii]->get_domain().begin() + ij);
					}						
	}

	bool is_in_domain(Label& label) {
		for (int ii = 0; ii < domain_labels.size(); ii++)
			if (domain_labels[ii]->get_label_name().compare(label.get_label_name()) == 0)
				for(auto domain_l: domain_labels[ii]->get_domain())
					if(domain_l->get_value().compare(label.get_value()) == 0)
						return true;			
		
		return false;
	}

	void add_value_label(std::shared_ptr<Label> l) {
		bool already_added = false;
		for (int ii = 0; ii < this->value_labels.size(); ii++ ) {
			if (value_labels[ii]->get_label_name() == l->get_label_name()) {
				value_labels[ii] = l;
				already_added = true;
				break;
			}				
		}
		if (!already_added)
			this->value_labels.push_back(l);
	}

	void clear_value_labels() {
		this->value_labels.clear();
	}

	bool is_value_label_set(const std::string& label_name) {
		for (auto l : value_labels)
			if (l->get_label_name() == label_name)
				return true;
		return false;
	}

	std::string get_label_value(const std::string& label_name) {
		for (auto l : value_labels)
			if (l->get_label_name() == label_name)
				return l->get_value();
		return "";
	}

	std::string get_name() {
		return variable_name;
	}


	//DO POPRAWY
	int get_available_values() {
		int available_values = 0;
		for (auto l : this->domain_labels) {
			available_values += l->get_domain().size();
		}
	}

	//DO POPRAWY
	int get_constraint_value(std::shared_ptr<Label> label) {
		return 0;
	}


	virtual ~Variable()
	{

	}

};
