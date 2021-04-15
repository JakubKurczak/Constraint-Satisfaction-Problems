#include "Region.h"
#include "MapColoring.h"
#include "Naive_Order_Domain_Values.h"
#include "Naive_Select_Unassigned_Variable.h"
#include "BacktrackingAlgo.h"
#include "EinsteinPuzzle.h"
#include "Forward_Checking.h"
#include "Least_Constraining_Value.h"
#include "Minimum_Remaining_Values.h"
#include "AC3.h"
#include <iostream>

int test_1() {
	std::shared_ptr<MapColoring> problem = std::make_shared<MapColoring>(10,3);
	auto propagation_algo = std::make_shared<AC3>();
	auto v = problem->get_variables();

	

	auto naive_order_domain_values = std::make_shared<Least_Constraining_Value>();
	auto naive_select = std::make_shared<Minimum_Remaining_Values>();
	BacktrackingAlgo b(problem, naive_select, naive_order_domain_values, propagation_algo);
	b.backtracking_performance_tracking();

	return b.get_counter();
}

int test_3() {
	std::shared_ptr<MapColoring> problem = std::make_shared<MapColoring>(5,3);
	auto propagation_algo = std::make_shared<Forward_Checking>();
	auto v = problem->get_variables();

	/*for (auto iter = v.begin(); iter != v.end(); iter++) {
		std::cout << (*iter)->get_name() << std::endl;
		auto region = std::dynamic_pointer_cast<Region>(*iter);
		std::cout << " neighbours: ";
		for (auto neighbour : region->get_neighbours())
			std::cout << neighbour->get_name() << " ";
		std::cout << std::endl;

	}*/

	auto naive_order_domain_values = std::make_shared<Least_Constraining_Value>();
	auto naive_select = std::make_shared<Minimum_Remaining_Values>();
	BacktrackingAlgo b(problem, naive_select, naive_order_domain_values, propagation_algo);
	auto assignment = b.recursive_backtracking();

	/*std::cout << "_______________" << std::endl;
	for (auto iter = assignment->begin(); iter != assignment->end(); iter++) {
		std::cout << (iter->first->get_name()) << std::endl;
		for (auto label : iter->second) {
			std::cout << label->get_label_name() << ": ";
			std::cout << label->get_value() << std::endl;
		}
	}*/

	return b.get_counter();
}


void test_2() {
	std::shared_ptr<Naive_Order_Domain_Values> naive_order_domain_values = std::make_shared<Naive_Order_Domain_Values>();
	auto naive_select = std::make_shared<Naive_Select_Unassigned_Variable>();
	std::shared_ptr<Forward_Checking> propagation_algo = std::make_shared<Forward_Checking>();

	std::shared_ptr<EinsteinPuzzle> e = std::make_shared<EinsteinPuzzle>();
	BacktrackingAlgo b2(e, naive_select, naive_order_domain_values, propagation_algo);
	
	auto res_2 = b2.recursive_backtracking();
}

int test_4() {
	std::shared_ptr<MapColoring> problem = std::make_shared<MapColoring>(5,3);
	auto propagation_algo = std::make_shared<AC3>();
	auto v = problem->get_variables();

	/*for (auto iter = v.begin(); iter != v.end(); iter++) {
		std::cout << (*iter)->get_name()<< std::endl;
		auto region = std::dynamic_pointer_cast<Region>(*iter);
		std::cout << " neighbours: ";
		for (auto neighbour : region->get_neighbours())
			std::cout << neighbour->get_name()<<" ";
		std::cout << std::endl;

	}*/

	auto naive_order_domain_values = std::make_shared<Naive_Order_Domain_Values>();
	auto naive_select = std::make_shared<Naive_Select_Unassigned_Variable>();
	BacktrackingAlgo b(problem, naive_select, naive_order_domain_values, propagation_algo);
	auto assignment = b.recursive_backtracking();

	/*std::cout << "_______________" << std::endl;
	for (auto iter = assignment->begin(); iter != assignment->end(); iter++) {
		std::cout << (iter->first->get_name()) << std::endl;
		for (auto label : iter->second) {
			std::cout << label->get_label_name() << ": " ;
			std::cout << label->get_value() << std::endl;
		}
	}*/

	return b.get_counter();
}



int pretty_test() {
	std::shared_ptr<MapColoring> problem = std::make_shared<MapColoring>(5, 3);
	auto propagation_algo = std::make_shared<Forward_Checking>();
	auto v = problem->get_variables();

	for (auto iter = v.begin(); iter != v.end(); iter++) {
		std::cout << (*iter)->get_name() << std::endl;
		auto region = std::dynamic_pointer_cast<Region>(*iter);
		std::cout << " neighbours: ";
		for (auto neighbour : region->get_neighbours())
			std::cout << neighbour->get_name() << " ";
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
			std::cout << label->get_label_name() << ": ";
			std::cout << label->get_value() << std::endl;
		}
	}

	return b.get_counter();
}


void performance_test() {
	int average = 0;
	for (int ii = 0; ii < 100; ii++)
		average += test_1();

	std::cout << average << std::endl;

	average = 0;
	for (int ii = 0; ii < 100; ii++)
		average += test_3();

	std::cout << average << std::endl;

	average = 0;
	for (int ii = 0; ii < 100; ii++)
		average += test_4();

	std::cout << average << std::endl;
}

int main(){

	std::cout<<"Whole search: "<< test_1();

	return 0;
}