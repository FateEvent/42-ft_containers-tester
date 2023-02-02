//
// Created by Stephane Walter on 2/1/23.
//
#include "timer.hpp"

#include <iostream>
#include <map>
#include <vector>
#include "includes/vector.hpp"
#include "includes/map.hpp"

int main() {



    std::cout << "------------- testing vector------------" << std::endl;

    std::vector<int> v;
    v.assign(10000, 1);
    timer test;
    test.reset();
    v.insert(v.end() - 50, 4200 * 10000 , 2);
    std::cout << "test speed vector insert : std : ";
    std::cout << test.get_time() ;

    ft::vector<int> v2;
    v2.assign(10000, 1);
    timer test1;
    test1.reset();
    v2.insert(v2.end() - 50, 4200 * 10000 , 2);
    std::cout << ": ft : " ;
    std::cout << test1.get_time() << " ms" << std::endl ;





    std::vector<int> v1;
    for (int i = 0; i < 9900 * 10000; ++i)
        v1.push_back(i);
    timer test3;
    test3.reset();
    v1.push_back(*(v1.erase(v1.begin() + 8 * 10000, v1.end() - 1500 * 10000)));
    std::cout << "test speed vector erase : std : ";
    std::cout << test3.get_time() ;

    ft::vector<int> v3;
    for (int i = 0; i < 9900 * 10000; ++i)
        v3.push_back(i);
    timer test2;
    test2.reset();
    v3.push_back(*(v3.erase(v3.begin() + 8 * 10000, v3.end() - 1500 * 10000)));
    std::cout << ": ft : " ;
    std::cout << test2.get_time() << " ms" << std::endl ;



    std::vector<int> v4;
    std::vector<int>::iterator it;
    for (int i = 0; i < 10000; ++i)
        v4.push_back(i);
    it = v4.begin();
    timer test4;
    test4.reset();
    v4.push_back(*(++it));
    v4.push_back(*(--it));
    v4.push_back(*(it + 1));
    it += 1;
    v4.push_back(*(it - 1));
    it -= 1;
    v4.push_back(*it);
    std::cout << "test speed vector  iterator : ";
    std::cout << test4.get_time() ;


    std::vector<int> v5;
    std::vector<int>::iterator it1;
    for (int i = 0; i < 10000; ++i)
        v5.push_back(i);
    it1 = v5.begin();
    timer test5;
    test5.reset();
    v5.push_back(*(++it1));
    v5.push_back(*(--it1));
    v5.push_back(*(it1 + 1));
    it1 += 1;
    v5.push_back(*(it1 - 1));
    it1 -= 1;
    v5.push_back(*it1);
    std::cout << ": ft : " ;
    std::cout << test5.get_time() << " ms" << std::endl ;

    {std::vector<int> vct(1000000);
    timer test6;
    test6.reset();
    for (unsigned long int i = 0; i < vct.size(); ++i)
    {
        vct.at(i) = (vct.size() - i) * 3;

    }
    std::cout << "test speed vector  at et [] : std :";
    std::cout << test6.get_time() ;}

    {
        ft::vector<int> vct(1000000);
        timer test6;
        test6.reset();
        for (unsigned long int i = 0; i < vct.size(); ++i)
        {
            vct.at(i) = (vct.size() - i) * 3;

        }
        std::cout << " : ft : ";
        std::cout << test6.get_time() << std::endl;
    }




    std::cout << "-------------testing map speed------------" << std::endl;


    {
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

        timer test4;
        test4.reset();
        std::map<int, int> mymap;
        for(int i = 0; i < myVec.size();i++)
        {
            mymap[myVec[i]] = myVec2[i];
        }

        std::cout << "test speed map int [] creation: std :";
        std::cout << test4.get_time() ;
    }

    {
        std::vector<int> Vec1;
        Vec1.reserve(1000000); // reserve space for 1 million integers
        srand(time(0)); // seed the random number generator
        for (int i = 0; i < 1000000; i++) {
            int randomNum = rand() % 1000000; // generate a random number between 0 and 999999
            Vec1.push_back(randomNum); // add the random number to the vector
        }

        std::vector<int> Vec2;
        Vec2.reserve(1000000); // reserve space for 1 million integers
        srand(time(0)); // seed the random number generator
        for (int i = 0; i < 1000000; i++) {
            int randomNum = rand() % 1000000; // generate a random number between 0 and 999999
            Vec2.push_back(randomNum); // add the random number to the vector
        }

        timer test5;
        test5.reset();
        ft::map<int, int> mymap1;
        for(int i = 0; i < Vec1.size();i++)
        {
            mymap1[Vec1[i]] = Vec2[i];
        }

        std::cout << " : ft";
        std::cout << test5.get_time() << std::endl ;}
}

