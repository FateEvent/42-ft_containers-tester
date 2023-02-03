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
#include "map.hpp"
#include <stack>
#include "includes/stack.hpp"
#include <vector>
#include "vector.hpp"
#include "tester.hpp"
//#include <set>
//#include "set.hpp"




void    test_vector(){

    std::cout << "                    ______________________" << std::endl << std::endl;
    std::cout << "                    |       VECTOR         |" << std::endl;
    std::cout << "                    ______________________" << std::endl << std::endl;




    std::cout << " | Diff : ";
    print_diff("logs/ft_test_vector_ft.log", "logs/ft_test_vector_std.log");

}


void    test_map(){

    std::cout << "                    ______________________" << std::endl << std::endl;
    std::cout << "                    |       MAP           |" << std::endl;
    std::cout << "                    ______________________" << std::endl << std::endl;




    std::cout << " | Diff : ";
    print_diff("logs/ft_test_map_ft.log", "logs/ft_test_map_std.log");

}





int	main(void)
{

    test_vector();
    //test_stack(data);
    //test_set(data);
    test_map();

}