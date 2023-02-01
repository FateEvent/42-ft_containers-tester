
#include <iostream>
#include "stack.hpp"
#include "vector.hpp"
#include "map.hpp"
#include <stack>
#include <vector>
#include <map>

void	test_stack_with_ints(void)
{
    ft::stack<int> my_stack;
    ft::stack<int> my_stack2;
    std::stack<int> original_stack;
    std::stack<int> original_stack2;

    std::cout << "test           mine              stl" << std::endl;

    std::cout << "empty :        " << my_stack.empty() << "                 " << original_stack.empty() << std::endl;
    std::cout << "\033[33m- pushing '2' -\033[0m" << std::endl;
    my_stack.push(2);
    original_stack.push(2);
    std::cout << "empty :        " << my_stack.empty() << "                 " << original_stack.empty() << std::endl;
    std::cout << "size :         " << my_stack.size() << "                 " << original_stack.size() << std::endl;
    std::cout << "\033[33m- pushing '5' -\033[0m" << std::endl;
    my_stack.push(5);
    original_stack.push(5);
    std::cout << "size :         " << my_stack.size() << "                 " << original_stack.size() << std::endl;
    std::cout << "top :          " << my_stack.top() << "                 " << original_stack.top() << std::endl; std::cout << "\033[33m- pushing '6' -\033[0m" << std::endl;
    my_stack.push(6);
    original_stack.push(6);
    std::cout << "size :         " << my_stack.size() << "                 " << original_stack.size() << std::endl;
    std::cout << "top :          " << my_stack.top() << "                 " << original_stack.top() << std::endl;
    std::cout << "\033[33m- calling pop -\033[0m" << std::endl;
    my_stack.pop();
    original_stack.pop();
    std::cout << "size :         " << my_stack.size() << "                 " << original_stack.size() << std::endl;
    std::cout << "top :          " << my_stack.top() << "                 " << original_stack.top() << std::endl;
    std::cout << "\033[33m- calling pop -\033[0m" << std::endl;
    my_stack.pop();
    original_stack.pop();
    std::cout << "size :         " << my_stack.size() << "                 " << original_stack.size() << std::endl;
    std::cout << "top :          " << my_stack.top() << "                 " << original_stack.top() << std::endl;
    std::cout << "\033[33m- calling pop -\033[0m" << std::endl;
    my_stack.pop();
    original_stack.pop();
    std::cout << "size :         " << my_stack.size() << "                 " << original_stack.size() << std::endl;
    std::cout << "\033[33m- pushing '3' -\033[0m" << std::endl;
    my_stack.push(3);
    my_stack2.push(3);
    original_stack.push(3);
    original_stack2.push(3);
    std::cout << "== :           " << (int)(my_stack == my_stack2) << "                 " << (int)(original_stack == original_stack2) << std::endl;
    std::cout << "!= :           " << (int)(my_stack != my_stack2) << "                 " << (int)(original_stack != original_stack2) << std::endl;
    std::cout << "<= :           " << (int)(my_stack <= my_stack2) << "                 " << (int)(original_stack <= original_stack2) << std::endl;
    std::cout << ">= :           " << (int)(my_stack >= my_stack2) << "                 " << (int)(original_stack >= original_stack2) << std::endl;
    std::cout << "\033[33m- pushing '4' only to the first stack -\033[0m" << std::endl;
    my_stack.push(4);
    original_stack.push(4);
    std::cout << "== :           " << (int)(my_stack == my_stack2) << "                 " << (int)(original_stack == original_stack2) << std::endl;
    std::cout << "!= :           " << (int)(my_stack != my_stack2) << "                 " << (int)(original_stack != original_stack2) << std::endl;
    std::cout << "<= :           " << (int)(my_stack <= my_stack2) << "                 " << (int)(original_stack <= original_stack2) << std::endl;
    std::cout << ">= :           " << (int)(my_stack >= my_stack2) << "                 " << (int)(original_stack >= original_stack2) << std::endl;
    std::cout << ">= :           " << (int)(my_stack >= my_stack2) << "                 " << (int)(original_stack >= original_stack2) << std::endl;
    std::cout << ">  :           " << (int)(my_stack > my_stack2) << "                 " << (int)(original_stack > original_stack2) << std::endl;
    std::cout << "<  :           " << (int)(my_stack < my_stack2) << "                 " << (int)(original_stack < original_stack2) << std::endl;
    std::cout << "\033[33m- pushing '8' only to the second stack -\033[0m" << std::endl;
    my_stack2.push(8);
    original_stack2.push(8);
    std::cout << "== :           " << (int)(my_stack == my_stack2) << "                 " << (int)(original_stack == original_stack2) << std::endl;
    std::cout << "!= :           " << (int)(my_stack != my_stack2) << "                 " << (int)(original_stack != original_stack2) << std::endl;
    std::cout << "<= :           " << (int)(my_stack <= my_stack2) << "                 " << (int)(original_stack <= original_stack2) << std::endl;
    std::cout << ">= :           " << (int)(my_stack >= my_stack2) << "                 " << (int)(original_stack >= original_stack2) << std::endl;
    std::cout << ">= :           " << (int)(my_stack >= my_stack2) << "                 " << (int)(original_stack >= original_stack2) << std::endl;
    std::cout << ">  :           " << (int)(my_stack > my_stack2) << "                 " << (int)(original_stack > original_stack2) << std::endl;
    std::cout << "<  :           " << (int)(my_stack < my_stack2) << "                 " << (int)(original_stack < original_stack2) << std::endl;
}

void	test_stack_with_strings(void)
{
    ft::stack<std::string> my_stack;
    ft::stack<std::string> my_stack2;
    std::stack<std::string> original_stack;
    std::stack<std::string> original_stack2;

    std::cout << "test           mine              stl" << std::endl;

    std::cout << "empty :        " << my_stack.empty() << "                 " << original_stack.empty() << std::endl;
    std::cout << "\033[33m- pushing \"hello\" -\033[0m" << std::endl;
    my_stack.push("hello");
    original_stack.push("hello");
    std::cout << "empty :        " << my_stack.empty() << "                 " << original_stack.empty() << std::endl;
    std::cout << "size :         " << my_stack.size() << "                 " << original_stack.size() << std::endl;
    std::cout << "\033[33m- pushing \"world\" -\033[0m" << std::endl;
    my_stack.push("world");
    original_stack.push("world");
    std::cout << "size :         " << my_stack.size() << "                 " << original_stack.size() << std::endl;
    std::cout << "\033[33m- pushing \"bonjour\" -\033[0m" << std::endl;
    my_stack.push("bonjour");
    original_stack.push("bonjour");
    std::cout << "size :         " << my_stack.size() << "                 " << original_stack.size() << std::endl;
    std::cout << "top :          " << my_stack.top() << "           " << original_stack.top() << std::endl;
    std::cout << "\033[33m- calling pop -\033[0m" << std::endl;
    my_stack.pop();
    original_stack.pop();
    std::cout << "size :         " << my_stack.size() << "                 " << original_stack.size() << std::endl;
    std::cout << "top :          " << my_stack.top() << "             " << original_stack.top() << std::endl;
    std::cout << "\033[33m- calling pop -\033[0m" << std::endl;
    my_stack.pop();
    original_stack.pop();
    std::cout << "size :         " << my_stack.size() << "                 " << original_stack.size() << std::endl;
    std::cout << "top :          " << my_stack.top() << "             " << original_stack.top() << std::endl;
    std::cout << "\033[33m- calling pop -\033[0m" << std::endl;
    my_stack.pop();
    original_stack.pop();
    std::cout << "size :         " << my_stack.size() << "                 " << original_stack.size() << std::endl;
    std::cout << "\033[33m- pushing \"monde\" -\033[0m" << std::endl;
    my_stack.push("monde");
    my_stack2.push("monde");
    original_stack.push("monde");
    original_stack2.push("monde");
    std::cout << "== :           " << (int)(my_stack == my_stack2) << "                 " << (int)(original_stack == original_stack2) << std::endl;
    std::cout << "!= :           " << (int)(my_stack != my_stack2) << "                 " << (int)(original_stack != original_stack2) << std::endl;
    std::cout << "<= :           " << (int)(my_stack <= my_stack2) << "                 " << (int)(original_stack <= original_stack2) << std::endl;
    std::cout << ">= :           " << (int)(my_stack >= my_stack2) << "                 " << (int)(original_stack >= original_stack2) << std::endl;
    std::cout << "\033[33m- pushing \"hola\" only to the first stack -\033[0m" << std::endl;
    my_stack.push("hola");
    original_stack.push("hola");
    std::cout << "== :           " << (int)(my_stack == my_stack2) << "                 " << (int)(original_stack == original_stack2) << std::endl;
    std::cout << "!= :           " << (int)(my_stack != my_stack2) << "                 " << (int)(original_stack != original_stack2) << std::endl;
    std::cout << "<= :           " << (int)(my_stack <= my_stack2) << "                 " << (int)(original_stack <= original_stack2) << std::endl;
    std::cout << ">= :           " << (int)(my_stack >= my_stack2) << "                 " << (int)(original_stack >= original_stack2) << std::endl;
    std::cout << ">= :           " << (int)(my_stack >= my_stack2) << "                 " << (int)(original_stack >= original_stack2) << std::endl;
    std::cout << ">  :           " << (int)(my_stack > my_stack2) << "                 " << (int)(original_stack > original_stack2) << std::endl;
    std::cout << "<  :           " << (int)(my_stack < my_stack2) << "                 " << (int)(original_stack < original_stack2) << std::endl;
    std::cout << "\033[33m- pushing \"mondo\" only to the second stack -\033[0m" << std::endl;
    my_stack2.push("mondo");
    original_stack2.push("mondo");
    std::cout << "== :           " << (int)(my_stack == my_stack2) << "                 " << (int)(original_stack == original_stack2) << std::endl;
    std::cout << "!= :           " << (int)(my_stack != my_stack2) << "                 " << (int)(original_stack != original_stack2) << std::endl;
    std::cout << "<= :           " << (int)(my_stack <= my_stack2) << "                 " << (int)(original_stack <= original_stack2) << std::endl;
    std::cout << ">= :           " << (int)(my_stack >= my_stack2) << "                 " << (int)(original_stack >= original_stack2) << std::endl;
    std::cout << ">= :           " << (int)(my_stack >= my_stack2) << "                 " << (int)(original_stack >= original_stack2) << std::endl;
    std::cout << ">  :           " << (int)(my_stack > my_stack2) << "                 " << (int)(original_stack > original_stack2) << std::endl;
    std::cout << "<  :           " << (int)(my_stack < my_stack2) << "                 " << (int)(original_stack < original_stack2) << std::endl;
}

void	test_vector_with_strings(void)
{
    ft::vector<std::string> my_vector;
    ft::vector<std::string> my_vector2;
    std::vector<std::string> original_vector;
    std::vector<std::string> original_vector2;

    std::cout << "test\t\tmine\t\tstl" << std::endl;

    std::cout << "empty :\t\t" << my_vector.empty() << "\t\t" << original_vector.empty() << std::endl;

    std::cout << "\033[33m- pushing back \"hello\" -\033[0m" << std::endl;
    my_vector.push_back("hello");
    original_vector.push_back("hello");
    std::cout << "empty :\t\t" << my_vector.empty() << "\t\t" << original_vector.empty() << std::endl;
    std::cout << "size :\t\t" << my_vector.size() << "\t\t" << original_vector.size() << std::endl;
    std::cout << "full vector : " << std::endl;
    std::cout << "mine :" << std::endl << "\t";
    for (size_t i = 0; i < my_vector.size(); i++)
        std::cout << my_vector[i] << " ";
    std::cout << std::endl;
    std::cout << "original :" << std::endl << "\t";
    for (size_t i = 0; i < original_vector.size(); i++)
        std::cout << original_vector[i] << " ";
    std::cout << std::endl;

    std::cout << "\033[33m- pushing back  \"world\" -\033[0m" << std::endl;
    my_vector.push_back("world");
    original_vector.push_back("world");
    std::cout << "size :\t\t" << my_vector.size() << "\t\t" << original_vector.size() << std::endl;
    std::cout << "full vector : " << std::endl;
    std::cout << "mine :" << std::endl << "\t";
    for (size_t i = 0; i < my_vector.size(); i++)
        std::cout << my_vector[i] << " ";
    std::cout << std::endl;
    std::cout << "original :" << std::endl << "\t";
    for (size_t i = 0; i < original_vector.size(); i++)
        std::cout << original_vector[i] << " ";
    std::cout << std::endl;

    std::cout << "\033[33m- pushing back \"bonjour\" -\033[0m" << std::endl;
    my_vector.push_back("bonjour");
    original_vector.push_back("bonjour");
    std::cout << "size :\t\t" << my_vector.size() << "\t\t" << original_vector.size() << std::endl;
    std::cout << "front :\t\t" << my_vector.front() << "\t\t" << original_vector.front() << std::endl;
    std::cout << "back :\t\t" << my_vector.back() << "\t\t" << original_vector.back() << std::endl;
    std::cout << "full vector : " << std::endl;
    std::cout << "mine :" << std::endl << "\t";
    for (size_t i = 0; i < my_vector.size(); i++)
        std::cout << my_vector[i] << " ";
    std::cout << std::endl;
    std::cout << "original :" << std::endl << "\t";
    for (size_t i = 0; i < original_vector.size(); i++)
        std::cout << original_vector[i] << " ";
    std::cout << std::endl;

    std::cout << "\033[33m- insert at last position \"inserted\" -\033[0m" << std::endl;
    my_vector.insert(my_vector.end(), "inserted");
    original_vector.insert(original_vector.end(), "inserted");
    std::cout << "size :\t\t" << my_vector.size() << "\t\t" << original_vector.size() << std::endl;
    std::cout << "full vector : " << std::endl;
    std::cout << "mine :" << std::endl << "\t";
    for (size_t i = 0; i < my_vector.size(); i++)
        std::cout << my_vector[i] << " ";
    std::cout << std::endl;
    std::cout << "original :" << std::endl << "\t";
    for (size_t i = 0; i < original_vector.size(); i++)
        std::cout << original_vector[i] << " ";
    std::cout << std::endl;

    std::cout << "\033[33m- erase 2nd elem -\033[0m" << std::endl;
    my_vector.erase(my_vector.begin() + 1);
    original_vector.erase(original_vector.begin() + 1);
    std::cout << "size :\t\t" << my_vector.size() << "\t\t" << original_vector.size() << std::endl;
    std::cout << "full vector : " << std::endl;
    std::cout << "mine :" << std::endl << "\t";
    for (size_t i = 0; i < my_vector.size(); i++)
        std::cout << my_vector[i] << " ";
    std::cout << std::endl;
    std::cout << "original :" << std::endl << "\t";
    for (size_t i = 0; i < original_vector.size(); i++)
        std::cout << original_vector[i] << " ";
    std::cout << std::endl;

    std::cout << "\033[33m- calling pop_back -\033[0m" << std::endl;
    my_vector.pop_back();
    original_vector.pop_back();
    std::cout << "size :\t\t" << my_vector.size() << "\t\t" << original_vector.size() << std::endl;
    std::cout << "full vector : " << std::endl;
    std::cout << "mine :" << std::endl << "\t";
    for (size_t i = 0; i < my_vector.size(); i++)
        std::cout << my_vector[i] << " ";
    std::cout << std::endl;
    std::cout << "original :" << std::endl << "\t";
    for (size_t i = 0; i < original_vector.size(); i++)
        std::cout << original_vector[i] << " ";
    std::cout << std::endl;

    std::cout << "\033[33m- calling pop_back -\033[0m" << std::endl;
    my_vector.pop_back();
    original_vector.pop_back();
    std::cout << "size :\t\t" << my_vector.size() << "\t\t" << original_vector.size() << std::endl;
    std::cout << "full vector : " << std::endl;
    std::cout << "mine :" << std::endl << "\t";
    for (size_t i = 0; i < my_vector.size(); i++)
        std::cout << my_vector[i] << " ";
    std::cout << std::endl;
    std::cout << "original :" << std::endl << "\t";
    for (size_t i = 0; i < original_vector.size(); i++)
        std::cout << original_vector[i] << " ";
    std::cout << std::endl;

    std::cout << "\033[33m- calling pop_back -\033[0m" << std::endl;
    my_vector.pop_back();
    original_vector.pop_back();
    std::cout << "size :\t\t" << my_vector.size() << "\t\t" << original_vector.size() << std::endl;
    std::cout << "full vector : " << std::endl;
    std::cout << "mine :" << std::endl << "\t";
    for (size_t i = 0; i < my_vector.size(); i++)
        std::cout << my_vector[i] << " ";
    std::cout << std::endl;
    std::cout << "original :" << std::endl << "\t";
    for (size_t i = 0; i < original_vector.size(); i++)
        std::cout << original_vector[i] << " ";
    std::cout << std::endl;

    std::cout << "\033[33m- pushing back \"monde\" -\033[0m" << std::endl;
    my_vector.push_back("monde");
    my_vector2.push_back("monde");
    original_vector.push_back("monde");
    original_vector2.push_back("monde");
    std::cout << "full vector : " << std::endl;
    std::cout << "mine :" << std::endl << "\t";
    for (size_t i = 0; i < my_vector.size(); i++)
        std::cout << my_vector[i] << " ";
    std::cout << std::endl;
    std::cout << "original :" << std::endl << "\t";
    for (size_t i = 0; i < original_vector.size(); i++)
        std::cout << original_vector[i] << " ";
    std::cout << std::endl;
    std::cout << "== :           " << (int)(my_vector == my_vector2) << "                 " << (int)(original_vector == original_vector2) << std::endl;
    std::cout << "!= :           " << (int)(my_vector != my_vector2) << "                 " << (int)(original_vector != original_vector2) << std::endl;
    std::cout << "<= :           " << (int)(my_vector <= my_vector2) << "                 " << (int)(original_vector <= original_vector2) << std::endl;
    std::cout << ">= :           " << (int)(my_vector >= my_vector2) << "                 " << (int)(original_vector >= original_vector2) << std::endl;

    std::cout << "\033[33m- pushing back \"hola\" only to the first vector -\033[0m" << std::endl;
    my_vector.push_back("hola");
    original_vector.push_back("hola");
    std::cout << "full vector : " << std::endl;
    std::cout << "mine 1:" << std::endl << "\t";
    for (size_t i = 0; i < my_vector.size(); i++)
        std::cout << my_vector[i] << " ";
    std::cout << std::endl;
    std::cout << "mine 2:" << std::endl << "\t";
    for (size_t i = 0; i < my_vector2.size(); i++)
        std::cout << my_vector2[i] << " ";
    std::cout << std::endl;
    std::cout << "original 1:" << std::endl << "\t";
    for (size_t i = 0; i < original_vector.size(); i++)
        std::cout << original_vector[i] << " ";
    std::cout << std::endl;
    std::cout << "original 2:" << std::endl << "\t";
    for (size_t i = 0; i < original_vector2.size(); i++)
        std::cout << original_vector2[i] << " ";
    std::cout << std::endl;
    std::cout << "== :           " << (int)(my_vector == my_vector2) << "                 " << (int)(original_vector == original_vector2) << std::endl;
    std::cout << "!= :           " << (int)(my_vector != my_vector2) << "                 " << (int)(original_vector != original_vector2) << std::endl;
    std::cout << "<= :           " << (int)(my_vector <= my_vector2) << "                 " << (int)(original_vector <= original_vector2) << std::endl;
    std::cout << ">= :           " << (int)(my_vector >= my_vector2) << "                 " << (int)(original_vector >= original_vector2) << std::endl;
    std::cout << ">= :           " << (int)(my_vector >= my_vector2) << "                 " << (int)(original_vector >= original_vector2) << std::endl;
    std::cout << ">  :           " << (int)(my_vector > my_vector2) << "                 " << (int)(original_vector > original_vector2) << std::endl;
    std::cout << "<  :           " << (int)(my_vector < my_vector2) << "                 " << (int)(original_vector < original_vector2) << std::endl;

    std::cout << "\033[33m- pushing \"mondo\" only to the second vector -\033[0m" << std::endl;
    my_vector2.push_back("mondo");
    original_vector2.push_back("mondo");
    std::cout << "full vector : " << std::endl;
    std::cout << "mine 1:" << std::endl << "\t";
    for (size_t i = 0; i < my_vector.size(); i++)
        std::cout << my_vector[i] << " ";
    std::cout << std::endl;
    std::cout << "mine 2:" << std::endl << "\t";
    for (size_t i = 0; i < my_vector2.size(); i++)
        std::cout << my_vector2[i] << " ";
    std::cout << std::endl;
    std::cout << "original 1:" << std::endl << "\t";
    for (size_t i = 0; i < original_vector.size(); i++)
        std::cout << original_vector[i] << " ";
    std::cout << std::endl;
    std::cout << "original 2:" << std::endl << "\t";
    for (size_t i = 0; i < original_vector2.size(); i++)
        std::cout << original_vector2[i] << " ";
    std::cout << std::endl;
    std::cout << "== :           " << (int)(my_vector == my_vector2) << "                 " << (int)(original_vector == original_vector2) << std::endl;
    std::cout << "!= :           " << (int)(my_vector != my_vector2) << "                 " << (int)(original_vector != original_vector2) << std::endl;
    std::cout << "<= :           " << (int)(my_vector <= my_vector2) << "                 " << (int)(original_vector <= original_vector2) << std::endl;
    std::cout << ">= :           " << (int)(my_vector >= my_vector2) << "                 " << (int)(original_vector >= original_vector2) << std::endl;
    std::cout << ">= :           " << (int)(my_vector >= my_vector2) << "                 " << (int)(original_vector >= original_vector2) << std::endl;
    std::cout << ">  :           " << (int)(my_vector > my_vector2) << "                 " << (int)(original_vector > original_vector2) << std::endl;
    std::cout << "<  :           " << (int)(my_vector < my_vector2) << "                 " << (int)(original_vector < original_vector2) << std::endl;

}

void	print_maps(ft::map<std::string, int> *my_map, std::map<std::string, int> *original_map)
{
    ft::map<std::string, int>::iterator my_it = my_map->begin();
    std::map<std::string, int>::iterator original_it = original_map->begin();

    my_it = my_map->begin();
    original_it = original_map->begin();
    std::cout << std::endl << "full map : " << std::endl;
    std::cout << "mine:" << std::endl << "\t";
    while (my_it != my_map->end())
    {
        std::cout << "{" << (*my_it).first << ", " << (*my_it).second << "}" << " ";
        my_it++;
    }
    std::cout << std::endl;
    std::cout << "original:" << std::endl << "\t";
    while (original_it != original_map->end())
    {
        std::cout << "{" << (*original_it).first << ", " << (*original_it).second << "}" << " ";
        original_it++;
    }
    std::cout << std::endl << std::endl;
}

void	test_map_with_strings(void)
{



    std::string result;
    ft::map<std::string, int>	my_map;
    std::map<std::string, int>	original_map;

    std::cout << "test\t\tmine\t\tstl" << std::endl;
    std::cout << "empty :\t\t" << my_map.empty() << "\t\t" << original_map.empty() << std::endl;
    std::cout << "size :\t\t" << my_map.size() << "\t\t" << original_map.size() << std::endl;
    std::cout << "max_size :\t" << my_map.max_size() << "\t" << original_map.max_size() << std::endl;
    std::cout << "\033[33m- inserting \"hello\" = 1 -\033[0m" << std::endl;
    my_map.insert(ft::make_pair("hello", 1));
    original_map.insert(std::make_pair("hello", 1));
    std::cout << "empty :\t\t" << my_map.empty() << "\t\t" << original_map.empty() << std::endl;
    std::cout << "size :\t\t" << my_map.size() << "\t\t" << original_map.size() << std::endl;
    std::cout << "find  :\t\t" << (*(my_map.find("hello"))).first << "\t\t" << (*(original_map.find("hello"))).first << std::endl;
    if (my_map.find("hola") == my_map.end())
        result = "END";
    else
        result = (*my_map.find("hola")).first;
    std::cout << "find :\t\t" << result;
    if (original_map.find("hola") == original_map.end())
        result = "END";
    else
        result = (*original_map.find("hola")).first;
    std::cout << "\t\t" << result << std::endl;
    std::cout << "\033[33m- inserting \"hello\" = 2 -\033[0m" << std::endl;
    my_map.insert(ft::make_pair("hello", 2));
    original_map.insert(std::make_pair("hello", 2));
    std::cout << "size :\t\t" << my_map.size() << "\t\t" << original_map.size() << std::endl;
    std::cout << "\033[33m- inserting \"hola\" = 3 -\033[0m" << std::endl;
    my_map.insert(ft::make_pair("hola", 3));
    original_map.insert(std::make_pair("hola", 3));
    std::cout << "size :\t\t" << my_map.size() << "\t\t" << original_map.size() << std::endl;
    std::cout << "\033[33m- inserting \"toto\" = 4 -\033[0m" << std::endl;
    my_map.insert(ft::make_pair("toto", 4));
    original_map.insert(std::make_pair("toto", 4));
    std::cout << "size :\t\t" << my_map.size() << "\t\t" << original_map.size() << std::endl;

    print_maps(&my_map, &original_map);

    std::cout << "\033[33m- inserting \"eyyy\" with operator [] and assigning 42 -\033[0m" << std::endl;
    my_map["eyyy"] = 42;
    original_map["eyyy"] = 42;
    std::cout << "size :\t\t" << my_map.size() << "\t\t" << original_map.size() << std::endl;

    print_maps(&my_map, &original_map);

    std::cout << "\033[33m- calling operator [\"eyyy\"] and assigning 101 -\033[0m" << std::endl;
    my_map["eyyy"] = 101;
    original_map["eyyy"] = 101;
    std::cout << "size :\t\t" << my_map.size() << "\t\t" << original_map.size() << std::endl;

    print_maps(&my_map, &original_map);

    std::cout << "count :\t\t" << my_map.count("hello") << "\t\t" << original_map.count("hello") << std::endl;
    std::cout << "count :\t\t" << my_map.count("hllo") << "\t\t" << original_map.count("hllo") << std::endl;

    ft::map<std::string, int>::iterator		my_it = my_map.begin();
    std::map<std::string, int>::iterator	original_it = original_map.begin();

    std::cout << "\033[33m- erasing \"hola\" -\033[0m" << std::endl;
    ++++my_it;
    ++++original_it;
    my_map.erase(my_it);
    original_map.erase(original_it);

    print_maps(&my_map, &original_map);

    std::cout << "size :\t\t" << my_map.size() << "\t\t" << original_map.size() << std::endl;
    std::cout << "count :\t\t" << my_map.count("hello") << "\t\t" << original_map.count("hello") << std::endl;
    std::cout << "count :\t\t" << my_map.count("hola") << "\t\t" << original_map.count("hola") << std::endl;

    std::cout << "\033[33m- erasing begin() -\033[0m" << std::endl;
    my_map.erase(my_map.begin());
    original_map.erase(original_map.begin());

    print_maps(&my_map, &original_map);

    std::cout << "\033[33m- erasing begin() -\033[0m" << std::endl;
    my_map.erase(my_map.begin());
    original_map.erase(original_map.begin());

    print_maps(&my_map, &original_map);

    if (my_map.find("hello") == my_map.end())
        result = "END";
    else
        result = (*my_map.find("hello")).first;
    std::cout << "find :\t\t" << result;
    if (original_map.find("hello") == original_map.end())
        result = "END";
    else
        result = (*original_map.find("hello")).first;
    std::cout << "\t\t" << result << std::endl;

    if (my_map.find("toto") == my_map.end())
        result = "END";
    else
        result = (*my_map.find("toto")).first;
    std::cout << "find :\t\t" << result;
    if (original_map.find("toto") == original_map.end())
        result = "END";
    else
        result = (*original_map.find("toto")).first;
    std::cout << "\t\t" << result << std::endl;

    std::cout << "\033[33m- erasing end() - 1 -\033[0m" << std::endl;
    my_map.erase(--my_map.end());
    original_map.erase(--original_map.end());

    print_maps(&my_map, &original_map);

    if (my_map.find("toto") == my_map.end())
        result = "END";
    else
        result = (*my_map.find("toto")).first;
    std::cout << "find :\t\t" << result;
    if (original_map.find("toto") == original_map.end())
        result = "END";
    else
        result = (*original_map.find("toto")).first;
    std::cout << "\t\t" << result << std::endl;

    std::cout << "size :\t\t" << my_map.size() << "\t\t" << original_map.size() << std::endl;

    std::cout << "\033[33m- inserting \"bonjour\" = 42 (with iterator insert) -\033[0m" << std::endl;
    my_map.insert(my_map.begin(), ft::make_pair("bonjour", 42));
    original_map.insert(original_map.begin(), std::make_pair("bonjour", 42));

    print_maps(&my_map, &original_map);
}

int	main(void)
{
    std::cout << std::endl << "\033[32m### testing stack (with ints) ###\033[0m" << std::endl << std::endl;

    test_stack_with_ints();

    std::cout << std::endl << "\033[32m### testing stack (with strings) ###\033[0m" << std::endl << std::endl;

    test_stack_with_strings();

    //std::cout << std::endl << "\033[32m### testing vector (with ints) ###\033[0m" << std::endl << std::endl;

    //test_vector_with_ints();

    std::cout << std::endl << "\033[32m### testing vector (with strings) ###\033[0m" << std::endl << std::endl;

    test_vector_with_strings();

    std::cout << std::endl << "\033[32m### testing map (with strings) ###\033[0m" << std::endl << std::endl;

    test_map_with_strings();
}