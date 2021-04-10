#pragma once
#include <string>
#include <vector>
#include <memory>

class Label {
private:
	std::vector<std::shared_ptr<Label>> domain;

	std::string value;

	std::string label_name;
public:

	Label(std::string label_name, std::string value) : label_name{ label_name }, value{ value }{};

	Label(std::string label_name, std::vector<std::shared_ptr<Label>>& domain) : label_name{ label_name }, domain(domain){}

	Label(const Label& label) : label_name{ label.label_name }, value{label.value}{
		for (auto l : label.domain)
			this->domain.push_back(l);
	}

	std::string& get_label_name() { return label_name; }

	std::string& get_value() { return value; }

	bool operator==(const Label& other) {
		if (this->label_name == other.label_name) {
			if (value == value)
				if (domain.size() == domain.size())
					return true;

			return false;

		}
		else
			return false;
	}

	std::vector<std::shared_ptr<Label>>& get_domain() { return domain; }

	~Label()
	{

	}


};
