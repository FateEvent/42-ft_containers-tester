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
        container_type C;

    public:

        explicit stack(const Container &cont = container_type()) : C(cont) {}

        stack &operator=(const stack<T, Container> &other) {
            if (this != &other)
                this->C = other.C;
            return (*this);
        }

        virtual ~stack() {

        }


        bool empty() const {
            return (C.empty());
        }

        void pop() {
            C.pop_back();
        }

        void push(const T &value) {
            C.push_back(value);
        }

        size_type size() const {
            return (C.size());
        }

        reference top() {
            return (C.back());
        }

        const_reference top() const {
            return (C.back());
        }

        friend bool operator==(const stack<T, Container> &a, const stack<T, Container> &b) {
            return (a.C == b.C);
        }

        friend bool operator!=(const stack<T, Container> &a, const stack<T, Container> &b) {
            return (a.C != b.C);
        }

        friend bool operator>(const stack<T, Container> &a, const stack<T, Container> &b) {
            return (a.C > b.C);
        }


        friend bool operator<(const stack<T, Container> &a, const stack<T, Container> &b) {
            return (a.C < b.C);
        }


        friend bool operator>=(const stack<T, Container> &a, const stack<T, Container> &b) {
            return (a.C >= b.C);
        }


        friend bool operator<=(const stack<T, Container> &a, const stack<T, Container> &b) {
            return (a.C <= b.C);
        }


    };
}




#endif //stack_HPP
