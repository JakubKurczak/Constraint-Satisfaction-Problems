#pragma once

#include "Variable.h"
#include <unordered_map>

class Person : public Variable {
private:
	std::unordered_map<std::string, std::shared_ptr<Person>> neighbours;

public:

	Person(std::string& person_name, std::vector<std::shared_ptr<Label>>& domain_labels) :
		Variable(person_name, domain_labels)
	{

	}

	~Person()
	{

	}

	void add_left_neighbour(std::shared_ptr<Person> other_person) {
		neighbours["left"] = other_person;
	}

	void add_right_neighbour(std::shared_ptr<Person> other_person) {
		neighbours["right"]= other_person;
	}

	//its much more are constraint  not voided
	bool are_constraint_not_voided() {
		bool constraint_1 = this->constraint_1();
		bool constraint_2 = this->constraint_2();
		bool constraint_3 = this->constraint_3();
		bool constraint_4 = this->constraint_4();
		bool constraint_5 = this->constraint_5();
		bool constraint_6 = this->constraint_6();
		bool constraint_7 = this->constraint_7();
		bool constraint_8 = this->constraint_8();
		bool constraint_9 = this->constraint_9();
		bool constraint_10 = this->constraint_10();
		bool constraint_11 = this->constraint_11();
		bool constraint_12 = this->constraint_12();
		bool constraint_13 = this->constraint_13();
		bool constraint_14 = this->constraint_14();
		bool constraint_15 = this->constraint_15();
		bool constraint_16 = this->constraint_16();

		return constraint_1 && constraint_2 && constraint_3 && constraint_4 && constraint_5 && constraint_6 && constraint_7 && constraint_8 && constraint_9 && constraint_10 && constraint_11 && constraint_12 && constraint_13 && constraint_14 && constraint_15 && constraint_16 ;
	}

	bool constraint_1() {
		if (this->is_value_label_set("nationality")){
			if (this->get_label_value("nationality") == "Norwegian") {
				if (this->get_name() != "1")
					return false;
			}
		}
		return true;
	}

	bool constraint_2() {
		if (this->is_value_label_set("house_color") && this->is_value_label_set("nationality")) {
			if (this->get_label_value("nationality") == "Englishman")
				if (this->get_label_value("house_color") != "red")
					return false;
		}
		return true;
	}

	bool constraint_3() {
		if (this->is_value_label_set("house_color") && this->neighbours.find("left") != this->neighbours.end() && this->neighbours["left"]->is_value_label_set("house_color")) {
			if (this->get_label_value("house_color") == "white")
				if (this->neighbours["left"]->get_label_value("house_color") != "green")
					return false;
		}
		return true;
	}

	bool constraint_4() {
		if (this->is_value_label_set("beverage") && this->is_value_label_set("nationality")) {
			if (this->get_label_value("nationality") == "Dane") {
				if (this->get_label_value("beverage") != "tea")
					return false;
			}
		}
		return true;
	}

	bool constraint_5() {
		if(this->is_value_label_set("tabaco") && this->get_label_value("tabaco") == "light")
			if (this->neighbours.find("right") != this->neighbours.end() && this->neighbours.find("left") != this->neighbours.end()) {
				if (this->neighbours["right"]->is_value_label_set("pet") && this->neighbours["left"]->is_value_label_set("pet")) {
					return this->neighbours["right"]->get_label_value("pet") == "cat" || this->neighbours["left"]->get_label_value("pet") == "cat";
				}
				else if (this->neighbours["right"]->is_value_label_set("pet")) {
					return this->neighbours["right"]->get_label_value("pet") == "cat";
				}
				else if (this->neighbours["left"]->is_value_label_set("pet")) {
					return this->neighbours["left"]->get_label_value("pet") == "cat";
				}
			}
			else if (this->neighbours.find("right") != this->neighbours.end()) {
				return this->neighbours["right"]->get_label_value("pet") == "cat";
			}
			else {
				return this->neighbours["left"]->get_label_value("pet") == "cat";
			}

		return true;
	}

	bool constraint_6() {
		if (this->is_value_label_set("house_color") && this->is_value_label_set("tabaco")) {
			if (this->get_label_value("house_color") == "yellow")
				return this->get_label_value("tabaco") == "cigar";
		}
		return true;
	}

	bool constraint_7() {
		if (this->is_value_label_set("tabaco") && this->is_value_label_set("nationality")) {
			if (this->get_label_value("nationality") == "German")
				return this->get_label_value("tabaco") == "pipe";		
		}
		return true;
	}

	bool constraint_8() {
		if (this->is_value_label_set("beverage")) {
			if (this->get_name() == "3")
				return this->get_label_value("beverage") == "milk";
		}
		return true;
	}

	bool constraint_9() {
		if (this->is_value_label_set("tabaco") && this->get_label_value("tabaco") =="light")
			if (this->neighbours.find("right") != this->neighbours.end() && this->neighbours.find("left") != this->neighbours.end()) {
				if (this->neighbours["right"]->is_value_label_set("beverage") && this->neighbours["left"]->is_value_label_set("beverage")) {
					return this->neighbours["right"]->get_label_value("beverage") == "water" || this->neighbours["left"]->get_label_value("beverage") == "water";
				}
				else if (this->neighbours["right"]->is_value_label_set("beverage")) {
					return this->neighbours["right"]->get_label_value("beverage") == "water";
				}
				else if (this->neighbours["left"]->is_value_label_set("beverage")) {
					return this->neighbours["left"]->get_label_value("beverage") == "water";
				}
			}
			else if (this->neighbours.find("right") != this->neighbours.end()) {
				return this->neighbours["right"]->get_label_value("beverage") == "water";
			}
			else {
				return this->neighbours["left"]->get_label_value("beverage") == "water";
			}

		return true;
	}

	bool constraint_10() {
		if (this->is_value_label_set("tabaco") && this->get_label_value("tabaco") == "no_filter")
			if (this->is_value_label_set("pet"))
				return this->get_label_value("pet") == "bird";

		return true;
	}

	bool constraint_11() {
		if (this->is_value_label_set("nationality") && this->get_label_value("nationality") == "Swede")
			if (this->is_value_label_set("pet"))
				return this->get_label_value("pet") == "dog";

		return true;
	}

	bool constraint_12() {
		if (this->is_value_label_set("nationality") && this->get_label_value("nationality") == "Norwegian")
			if (this->neighbours.find("right") != this->neighbours.end() && this->neighbours.find("left") != this->neighbours.end()) {
				if (this->neighbours["right"]->is_value_label_set("house_color") && this->neighbours["left"]->is_value_label_set("house_color")) {
					return this->neighbours["right"]->get_label_value("house_color") == "blue" || this->neighbours["left"]->get_label_value("house_color") == "blue";
				}
				else if (this->neighbours["right"]->is_value_label_set("house_color")) {
					return this->neighbours["right"]->get_label_value("house_color") == "blue";
				}
				else if (this->neighbours["left"]->is_value_label_set("house_color")) {
					return this->neighbours["left"]->get_label_value("house_color") == "blue";
				}
			}
			else if (this->neighbours.find("right") != this->neighbours.end() && this->neighbours["right"]->is_value_label_set("house_color")) {
				return this->neighbours["right"]->get_label_value("house_color") == "blue";
			}
			else if(this->neighbours.find("left") != this->neighbours.end() && this->neighbours["left"]->is_value_label_set("house_color")){
				return this->neighbours["left"]->get_label_value("house_color") == "blue";
			}

		return true;
	}

	bool constraint_13() {
		if (this->is_value_label_set("pet") && this->get_label_value("pet") == "horse")
			if (this->neighbours.find("right") != this->neighbours.end() && this->neighbours.find("left") != this->neighbours.end()) {
				if (this->neighbours["right"]->is_value_label_set("house_color") && this->neighbours["left"]->is_value_label_set("house_color")) {
					return this->neighbours["right"]->get_label_value("house_color") == "yellow" || this->neighbours["left"]->get_label_value("house_color") == "yellow";
				}
				else if (this->neighbours["right"]->is_value_label_set("house_color")) {
					return this->neighbours["right"]->get_label_value("house_color") == "yellow";
				}
				else if (this->neighbours["left"]->is_value_label_set("house_color")) {
					return this->neighbours["left"]->get_label_value("house_color") == "yellow";
				}
			}
			else if (this->neighbours.find("right") != this->neighbours.end() && this->neighbours["right"]->is_value_label_set("house_color")) {
				return this->neighbours["right"]->get_label_value("house_color") == "yellow";
			}
			else if(this->neighbours.find("left") != this->neighbours.end() && this->neighbours["left"]->is_value_label_set("house_color")){
				return this->neighbours["left"]->get_label_value("house_color") == "yellow";
			}

		return true;
	}

	bool constraint_14() {
		if (this->is_value_label_set("tabaco") && this->get_label_value("tabaco") == "mentol")
			if (this->is_value_label_set("beverage"))
				return this->get_label_value("beverage") == "beer";

		return true;
	}

	bool constraint_15() {
		if (this->is_value_label_set("house_color") && this->get_label_value("house_color") == "green")
			if (this->is_value_label_set("beverage"))
				return this->get_label_value("beverage") == "coffe";

		return true;
	}

	bool constraint_16() {
		if (this->get_name() == "1") {
			if (this->neighbours.find("left") != this->neighbours.end())
				return false;
			else if (this->neighbours.find("right") != this->neighbours.end() )
				return this->neighbours["right"]->get_name() == "2";
		}
		return true;
	}

};