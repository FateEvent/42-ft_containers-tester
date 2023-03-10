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
class MutantStack : public ft::stack<T>
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

    typedef typename ft::stack<T>::container_type::iterator			iterator;
    typedef typename ft::stack<T>::container_type::reverse_iterator	reverse_iterator;

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
    reverse_iterator rbegin() { return this->c.rbegin(); }
    reverse_iterator rend() { return this->c.rend(); }
};

int main(void) {

    std::cout << "// --> My tests <-- //" << std::endl << std::endl;

	std::cout << "// --> Stack <-- //" << std::endl << std::endl;

	MutantStack<char> iterable_stack;
	MutantStack<char> mStack_char;
	ft::stack<Awesome, ft::vector<Awesome> > stack_awesome;
	ft::stack<char>	stacker;

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
	std::cout << std::endl;

	std::cout << stacker.size() << std::endl;
	std::cout << stacker.empty() << std::endl;

    std::cout << " == :           " << (int)(mStack_char == stacker) << std::endl;
    std::cout << " != :           " << (int)(mStack_char != stacker) << std::endl;
    std::cout << " <= :           " << (int)(mStack_char <= stacker) << std::endl;
    std::cout << " >= :           " << (int)(mStack_char >= stacker) << std::endl;
	std::cout << "  > :           " << (int)(mStack_char > stacker) << std::endl;
    std::cout << "  < :           " << (int)(mStack_char < stacker) << std::endl;
    std::cout << "\033[33m- pushing '4' only to the first stack -\033[0m" << std::endl;
    mStack_char.push('4');
    std::cout << " == :           " << (int)(mStack_char == stacker) << std::endl;
    std::cout << " != :           " << (int)(mStack_char != stacker) << std::endl;
    std::cout << " <= :           " << (int)(mStack_char <= stacker) << std::endl;
    std::cout << " >= :           " << (int)(mStack_char >= stacker) << std::endl;
    std::cout << " >= :           " << (int)(mStack_char >= stacker) << std::endl;
    std::cout << "  > :           " << (int)(mStack_char > stacker) << std::endl;
    std::cout << "  < :           " << (int)(mStack_char < stacker) << std::endl;
    std::cout << "\033[33m- pushing '8' only to the second stack -\033[0m" << std::endl;
    stacker.push('8');
    std::cout << " == :           " << (int)(mStack_char == stacker) << std::endl;
    std::cout << " != :           " << (int)(mStack_char != stacker) << std::endl;
    std::cout << " <= :           " << (int)(mStack_char <= stacker) << std::endl;
    std::cout << " >= :           " << (int)(mStack_char >= stacker) << std::endl;
    std::cout << " >= :           " << (int)(mStack_char >= stacker) << std::endl;
    std::cout << "  > :           " << (int)(mStack_char > stacker) << std::endl;
    std::cout << "  < :           " << (int)(mStack_char < stacker) << std::endl;

	srand(time(0));

	for (int i = 0; i < 100000; i++)
	{
		int	aw = rand() % 100000;
		stack_awesome.push(Awesome(aw));
	}
	
	std::cout << stack_awesome.size() << std::endl;
	std::cout << stack_awesome.empty() << std::endl;
}
