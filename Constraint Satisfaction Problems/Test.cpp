#include "Region.h"
#include "MapColoring.h"
#include "Naive_Order_Domain_Values.h"
#include "Naive_Select_Unassigned_Variable.h"
#include "BacktrackingAlgo.h"
#include "EinsteinPuzzle.h"
#include "Forward_Checking.h"
#include "Least_Constraining_Value.h"
#include "Minimum_Remaining_Values.h"

#include <iostream>

void test_1() {
	std::shared_ptr<MapColoring> problem = std::make_shared<MapColoring>();
	std::shared_ptr<Forward_Checking> propagation_algo = std::make_shared<Forward_Checking>();
	auto v = problem->get_variables();
	for (auto iter = v.begin(); iter != v.end(); iter++) {
		std::cout << (*iter)->get_name()<< std::endl;
		auto region = std::dynamic_pointer_cast<Region>(*iter);
		std::cout << " neighbours: ";
		for (auto neighbour : region->get_neighbours())
			std::cout << neighbour->get_name()<<" ";
		std::cout << std::endl;

	}

	auto naive_order_domain_values = std::make_shared<Least_Constraining_Value>();
	auto naive_select = std::make_shared<Minimum_Remaining_Values>();
	BacktrackingAlgo b(problem, naive_select, naive_order_domain_values, propagation_algo);
	auto assignment = b.recursive_backtracking();

	std::cout << "_______________" << std::endl;
	for (auto iter = assignment->begin(); iter != assignment->end(); iter++) {
		std::cout << (iter->first->get_name()) << std::endl;
		for (auto label : iter->second) {
			std::cout << label->get_label_name() << ": " ;
			std::cout << label->get_value() << std::endl;
		}
	}


}


void test_2() {
	std::shared_ptr<Naive_Order_Domain_Values> naive_order_domain_values = std::make_shared<Naive_Order_Domain_Values>();
	auto naive_select = std::make_shared<Naive_Select_Unassigned_Variable>();
	std::shared_ptr<Forward_Checking> propagation_algo = std::make_shared<Forward_Checking>();

	std::shared_ptr<EinsteinPuzzle> e = std::make_shared<EinsteinPuzzle>();
	BacktrackingAlgo b2(e, naive_select, naive_order_domain_values, propagation_algo);
	
	auto res_2 = b2.recursive_backtracking();
}

int main(){
	for(int ii=0;ii<1;ii++)
		test_1();
	//test_2();
	return 0;
}