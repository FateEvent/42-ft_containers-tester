//
// Created by Stephane Walter on 12/21/22.
//
//tets
#ifndef stack_HPP
#define stack_HPP

#include <iostream>
#include <vector>
#include "vector.hpp"

#include <stack>
namespace ft {
    template<class T, class Container = ft::vector<T> >
    class stack {


    public:
        typedef Container container_type;
        typedef typename Container::value_type value_type;
        typedef typename Container::reference reference;
        typedef typename Container::const_reference const_reference;
        typedef typename Container::size_type size_type;


    protected:
        container_type c;

    public:

        explicit stack(const Container &cont = container_type()) : c(cont) {}

        stack &operator=(const stack<T, Container> &other) {
            if (this != &other)
                this->c = other.c;
            return (*this);
        }

        virtual ~stack() {

        }


        bool empty() const {
            return (c.empty());
        }

        void pop() {
            c.pop_back();
        }

        void push(const T &value) {
            c.push_back(value);
        }

        size_type size() const {
            return (c.size());
        }

        reference top() {
            return (c.back());
        }

        const_reference top() const {
            return (c.back());
        }

        friend bool operator==(const stack<T, Container> &a, const stack<T, Container> &b) {
            return (a.c == b.c);
        }

        friend bool operator!=(const stack<T, Container> &a, const stack<T, Container> &b) {
            return (a.c != b.c);
        }

        friend bool operator>(const stack<T, Container> &a, const stack<T, Container> &b) {
            return (a.c > b.c);
        }


        friend bool operator<(const stack<T, Container> &a, const stack<T, Container> &b) {
            return (a.c < b.c);
        }


        friend bool operator>=(const stack<T, Container> &a, const stack<T, Container> &b) {
            return (a.c >= b.c);
        }


        friend bool operator<=(const stack<T, Container> &a, const stack<T, Container> &b) {
            return (a.c <= b.c);
        }


    };
}




#endif //stack_HPP
