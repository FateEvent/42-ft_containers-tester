//
// Created by Stephane Walter on 2/3/23.
//

// Created by Stephane Walter on 2/3/23.
//
#include <iostream>
#include <string>
#include <list>
#include <stdlib.h>
#include <stack>
#include <vector>
#include "includes/stack.hpp"
#include "includes/vector.hpp"

class Awesome
{
public:
    Awesome(void) : _n(0) {}
    Awesome(int n) : _n(n) {}
    Awesome &operator=(Awesome &a)
    {
        _n = a._n;
        return *this;
    }
    bool operator==(Awesome const &rhs) const { return (this->_n == rhs._n); }
    bool operator!=(Awesome const &rhs) const { return (this->_n != rhs._n); }
    bool operator>(Awesome const &rhs) const { return (this->_n > rhs._n); }
    bool operator<(Awesome const &rhs) const { return (this -> _n < rhs._n); }
    bool operator>=(Awesome const &rhs) const { return (this->_n >= rhs._n); }
    bool operator<=(Awesome const &rhs) const { return (this->_n <= rhs._n); }
    int get_n() const { return _n; }

private:
    int _n;
};

std::ostream &operator<<(std::ostream &o, const Awesome &a) { return (o << a.get_n()); }

template <typename T>
void print( T const & x ) { std::cout << x << std::endl; return; }

template<typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack() {}
    MutantStack(const MutantStack<T>& src) { *this = src; }
    MutantStack<T>& operator=(const MutantStack<T>& rhs)
    {
        this->c = rhs.c;
        return *this;
    }
    ~MutantStack() {}

    typedef typename std::stack<T>::container_type::iterator			iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator	reverse_iterator;

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
    reverse_iterator rbegin() { return this->c.rbegin(); }
    reverse_iterator rend() { return this->c.rend(); }
};

int main(void) {

    MutantStack<char> iterable_stack;
    MutantStack<char> mStack_char;
    std::stack<Awesome, std::vector<Awesome> > stack_deq_buffer;
    std::stack<char>	stacker;

    int	i = 0;
    while (i < 26)
    {
        iterable_stack.push('a' + i);
        mStack_char.push('z' - i);
        i++;
    }

    for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
        std::cout << *it;
    std::cout << std::endl;

    for (MutantStack<char>::reverse_iterator it = mStack_char.rbegin(); it != mStack_char.rend(); it++)
    {
        std::cout << *it;
        stacker.push(*it);
    }



}