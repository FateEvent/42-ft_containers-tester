//
// Created by Stephane Walter on 2/3/23.
//
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <string>
#include <deque>
#include <list>
#include <map>
#include "includes/map.hpp"
#include <stack>
#include "includes/stack.hpp"
#include <vector>
#include "includes/vector.hpp"
#include "tester.hpp"
#include "timer.hpp"
#include <set>
#include "includes/set.hpp"


void    test_vector() {

	std::cout << "                    ______________________" << std::endl << std::endl;
	std::cout << "                    |       VECTOR       |" << std::endl;
	std::cout << "                    ______________________" << std::endl << std::endl;




	std::cout << " | Diff : ";
	print_diff("logs/ft_test_vector_ft.log", "logs/ft_test_vector_std.log");

}


void    test_map() {

	std::cout << "                    ______________________" << std::endl << std::endl;
	std::cout << "                    |         MAP        |" << std::endl;
	std::cout << "                    ______________________" << std::endl << std::endl;




	std::cout << " | Diff : ";
	print_diff("logs/ft_test_map_ft.log", "logs/ft_test_map_std.log");

}

void    test_stack() {

	std::cout << "                    ______________________" << std::endl << std::endl;
	std::cout << "                    |        STACK       |" << std::endl;
	std::cout << "                    ______________________" << std::endl << std::endl;




	std::cout << " | Diff : ";
	print_diff("logs/ft_test_stack_ft.log", "logs/ft_test_stack_std.log");

}

void    test_set() {

    std::cout << "                    ______________________" << std::endl << std::endl;
    std::cout << "                    |         SET        |" << std::endl;
    std::cout << "                    ______________________" << std::endl << std::endl;




    std::cout << " | Diff : ";
    print_diff("logs/ft_test_set_ft.log", "logs/ft_test_set_std.log");

}

int	main(void)
{
	test_stack();
	test_vector();

	//test_set();
	test_map();




	std::cout << "                    ______________________" << std::endl << std::endl;
	std::cout << "                    |     SPEED TESTS    |" << std::endl;
	std::cout << "                    ______________________" << std::endl << std::endl;



	std::cout << "------------- testing vector------------" << std::endl;

	std::vector<int> v;
	v.assign(10000, 1);
	timer test;
	test.reset();
	v.insert(v.end() - 50, 4200 * 10000, 2);
	std::cout << "test speed vector insert : std : ";
	std::cout << test.get_time();

	ft::vector<int> v2;
	v2.assign(10000, 1);
	timer test2;
	test2.reset();
	v2.insert(v2.end() - 50, 4200 * 10000, 2);
	std::cout << ": ft : ";
	std::cout << test2.get_time() << " ms" << std::endl;


	std::vector<int> v1;
	for (int i = 0; i < 9900 * 10000; ++i)
		v1.push_back(i);
	timer test3;
	test3.reset();
	v1.push_back(*(v1.erase(v1.begin() + 8 * 10000, v1.end() - 1500 * 10000)));
	std::cout << "test speed vector erase : std : ";
	std::cout << test3.get_time();

	ft::vector<int> v3;
	for (int i = 0; i < 9900 * 10000; ++i)
		v3.push_back(i);
	timer test4;
	test4.reset();
	v3.push_back(*(v3.erase(v3.begin() + 8 * 10000, v3.end() - 1500 * 10000)));
	std::cout << ": ft : ";
	std::cout << test4.get_time() << " ms" << std::endl;


	std::vector<int> v4;
	std::vector<int>::iterator it;
	for (int i = 0; i < 10000; ++i)
		v4.push_back(i);
	it = v4.begin();
	timer test5;
	test5.reset();
	v4.push_back(*(++it));
	v4.push_back(*(--it));
	v4.push_back(*(it + 1));
	it += 1;
	v4.push_back(*(it - 1));
	it -= 1;
	v4.push_back(*it);
	std::cout << "test speed vector  iterator : ";
	std::cout << test5.get_time();


	std::vector<int> v5;
	std::vector<int>::iterator it1;
	for (int i = 0; i < 10000; ++i)
		v5.push_back(i);
	it1 = v5.begin();
	timer test6;
	test6.reset();
	v5.push_back(*(++it1));
	v5.push_back(*(--it1));
	v5.push_back(*(it1 + 1));
	it1 += 1;
	v5.push_back(*(it1 - 1));
	it1 -= 1;
	v5.push_back(*it1);
	std::cout << ": ft : ";
	std::cout << test6.get_time() << " ms" << std::endl;

	{
		std::vector<int> vct(1000000);
		timer test7;
		test7.reset();
		for (unsigned long int i = 0; i < vct.size(); ++i) {
			vct.at(i) = (vct.size() - i) * 3;

		}
		std::cout << "test speed vector at and [] : std :";
		std::cout << test7.get_time();
	}

	{
		ft::vector<int> vct(1000000);
		timer test8;
		test8.reset();
		for (unsigned long int i = 0; i < vct.size(); ++i) {
			vct.at(i) = (vct.size() - i) * 3;

		}
		std::cout << " : ft : ";
		std::cout << test8.get_time() << std::endl;
	}


	std::cout << "-------------testing map speed------------" << std::endl;

	std::vector<int> myVec;
	myVec.reserve(1000000); // reserve space for 1 million integers
	srand(time(0)); // seed the random number generator
	for (int i = 0; i < 1000000; i++) {
		int randomNum = rand() % 1000000; // generate a random number between 0 and 999999
		myVec.push_back(randomNum); // add the random number to the vector
	}

	std::vector<int> myVec2;
	myVec2.reserve(1000000); // reserve space for 1 million integers
	srand(time(0)); // seed the random number generator
	for (int i = 0; i < 1000000; i++) {
		int randomNum = rand() % 1000000; // generate a random number between 0 and 999999
		myVec2.push_back(randomNum); // add the random number to the vector
	}

	timer test9;
	test9.reset();
	std::map<int, int> mymap;
	for (int i = 0; i < myVec.size(); i++)
		mymap.insert(std::pair<int, int>(myVec[i], myVec2[i]));;

	std::cout << "test speed map insert: std :";
	std::cout << test9.get_time();


	ft::vector<int> Vec1;
	Vec1.reserve(1000000); // reserve space for 1 million integers
	srand(time(0)); // seed the random number generator
	for (int i = 0; i < 1000000; i++) {
		int randomNum = rand() % 1000000; // generate a random number between 0 and 999999
		Vec1.push_back(randomNum); // add the random number to the vector
	}

	ft::vector<int> Vec2;
	Vec2.reserve(1000000); // reserve space for 1 million integers
	srand(time(0)); // seed the random number generator
	for (int i = 0; i < 1000000; i++) {
		int randomNum = rand() % 1000000; // generate a random number between 0 and 999999
		Vec2.push_back(randomNum); // add the random number to the vector
	}

	timer test10;
	test10.reset();
	ft::map<int, int> mymap1;
	for (int i = 0; i < Vec1.size(); i++)
		mymap1.insert(ft::pair<int, int>(Vec1[i], Vec2[i]));

	std::cout << " : ft: ";
	std::cout << test10.get_time() << std::endl;




	timer test10b;
	test10b.reset();
	std::map<int, int>::iterator p = mymap.begin();
	for (unsigned long int i = 0; p != mymap.end(); ++i, ++p) {
		try {
			mymap.at((*p).first) = i;
		}
		catch (std::out_of_range& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "test speed map at and [] : std :";
	std::cout << test10b.get_time();


	timer test10c;
	test10c.reset();
	ft::map<int, int>::iterator q = mymap1.begin();
	for (unsigned long int i = 0; p != mymap.end(); ++i, ++p) {
		try {
			mymap1.at((*p).first) = i;
		}
		catch (std::out_of_range& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << " : ft : ";
	std::cout << test10c.get_time() << std::endl;




	std::cout << "erase test";

	timer test11;
	test11.reset();
	srand(time(0));
	int i = 0;
	while(i < 80 )
	{
		for (int i = 0; i < 1000000; i++) {
			int randomNum = rand() % 1000000;

			mymap1.erase(randomNum);}
		i++;
	}
	std::cout << " : std :";
	std::cout << test11.get_time() ;




	timer test12;
	test12.reset();
	srand(time(0));
	int j = 0;
	while(j < 80 )
	{
		for (int i = 0; i < 1000000; i++) {
			int randomNum = rand() % 1000000;

			mymap1.erase(randomNum);}
		j++;
	}
	std::cout << " : ft :";
	std::cout << test12.get_time() << std::endl;





	std::cout << "-------------testing set speed------------" << std::endl;

	{
		std::vector<int> myVec;
		myVec.reserve(1000000); // reserve space for 1 million integers
		srand(time(0)); // seed the random number generator
		for (int i = 0; i < 1000000; i++) {
			int randomNum = rand() % 1000000; // generate a random number between 0 and 999999
			myVec.push_back(randomNum); // add the random number to the vector
		}

		timer test13;
		test13.reset();
		std::set<int> myset;
		for (int i = 0; i < myVec.size(); i++) {
			myset.insert(myVec[i]);;
		}

		std::cout << "test speed set insert: std :";
		std::cout << test13.get_time();
	}

	timer test14;
	test14.reset();
	ft::set<int> myset1;
	for (int i = 0; i < Vec1.size(); i++) {
		myset1.insert(Vec1[i]);
	}

	std::cout << " : ft: ";
	std::cout << test14.get_time() << std::endl;


	{
		std::cout << "erase test";

		timer test15;
		test15.reset();
		srand(time(0));
		int i = 0;
		while(i < 80 )
		{
			for (int i = 0; i < 1000000; i++) {
				int randomNum = rand() % 1000000;

				myset1.erase(randomNum);}
			i++;
		}
		std::cout << " : std :";
		std::cout << test15.get_time() ;




		timer test16;
		test16.reset();
		srand(time(0));
		int j = 0;
		while(j < 80 )
		{
			for (int i = 0; i < 1000000; i++) {
				int randomNum = rand() % 1000000;

				myset1.erase(randomNum);}
			j++;
		}
		std::cout << " : ft :";
		std::cout << test16.get_time() << std::endl;
	}



	
	std::cout << "-------------testing  stack------------" << std::endl;

	timer   test17;
	test17.reset();
	std::stack<int> st1;

	srand(time(0));
	for (int i = 0; i < 1000000; i++) {
		int randomNum = rand() % 1000000;
		st1.push(randomNum);
	}
	std::cout << "test speed push : std :";
	std::cout << test17.get_time();

	timer   test18;
	test18.reset();
	ft::stack<int> st4;

	srand(time(0));
	for (int i = 0; i < 1000000; i++) {
		int randomNum = rand() % 1000000;
		st4.push(randomNum);
	}
	std::cout << " : ft :";
	std::cout << test18.get_time() << std::endl;


	//test pop

	timer   test19;
	test19.reset();
	std::stack<int> st2;

	srand(time(0));
	for (int i = 0; i < 1000000; i++) {
		int randomNum = rand() % 1000000;
		st2.push(randomNum);
	}
	for (int i = 0; i < 1000000; i++) {
		st2.pop();
	}
	std::cout << "test speed pop : std :";
	std::cout << test19.get_time();

	timer   test20;
	test20.reset();
	ft::stack<int> st3;

	srand(time(0));
	for (int i = 0; i < 1000000; i++) {
		int randomNum = rand() % 1000;
		st3.push(randomNum);
	}
	for (int i = 0; i < 1000000; i++) {
		st3.pop();
	}
	std::cout << " : ft :";
	std::cout << test20.get_time() << std::endl;

	return (0);
}