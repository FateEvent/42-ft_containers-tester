//
// Created by Stephane Walter on 12/21/22.
//

#ifndef ITERATOR_HPP
#define ITERATOR_HPP


#include <cstddef>
#include <iterator>
#include <memory>
#include "m_iterator.hpp"

namespace ft
{

/* -------------------------------------------------------------------------- */
/*                              reverse_iterator                              */
/* -------------------------------------------------------------------------- */

    template <typename T_Iterator>
    class reverse_iterator : public std::iterator<
        typename iterator_traits<T_Iterator>::iterator_category,
        typename iterator_traits<T_Iterator>::value_type ,
        typename iterator_traits<T_Iterator>::difference_type ,
        typename iterator_traits<T_Iterator>::pointer ,
        typename iterator_traits<T_Iterator>::reference> {



    protected:
        T_Iterator _cur;
        typedef iterator_traits<T_Iterator> traits_type;

    public:
        typedef T_Iterator iterator_type;
        typedef typename traits_type::difference_type difference_type;
        typedef typename traits_type::pointer pointer;
        typedef typename traits_type::reference reference;

        reverse_iterator() : _cur() {}

        explicit reverse_iterator(iterator_type x) : _cur(x) {}

        reverse_iterator(const reverse_iterator &x) : _cur(x._cur){}

        iterator_type base() const { return iterator_type(_cur); }

        template<class T_Ite>
        reverse_iterator(reverse_iterator<T_Ite> const &x) : _cur(x.base()) {}



        reference operator*() const {
            T_Iterator tmp = _cur;
            return *--tmp;
        }

        pointer operator->() const { return &(operator*()); }

        reverse_iterator &operator++() {
            --_cur;
            return (*this);
        }

        reverse_iterator operator++(int) {
            reverse_iterator tmp = *this;
            --_cur;
            return (tmp);
        }

        reverse_iterator operator--() {
            ++_cur;
            return *this;
        }

        reverse_iterator operator--(int) {
            reverse_iterator tmp = *this;
            ++_cur;
            return (tmp);
        }

        reverse_iterator operator+(difference_type n) const {
            return reverse_iterator(_cur - n);
        }

        reverse_iterator operator+=(difference_type n) {
            _cur -= n;
            return *this;
        }

        reverse_iterator operator-(difference_type n) const {
            return reverse_iterator(_cur + n);
        }

        reverse_iterator operator-=(difference_type n) {
            _cur += n;
            return *this;
        }

        reference operator[](difference_type n) const {
            return *(*this + n);
        }
    };

        template<typename T_Iterator>
        inline bool operator==(reverse_iterator<T_Iterator> const &a, reverse_iterator<T_Iterator> const &b){
            return a.base() == b.base();
        }

        template<typename T_Iterator>
        inline bool operator<(reverse_iterator<T_Iterator> const &a, reverse_iterator<T_Iterator> const &b){
            return b.base() < a.base();
        }

        template<typename T_Iterator>
        inline bool operator!=(reverse_iterator<T_Iterator> const &a, reverse_iterator<T_Iterator> const &b){
            return !(a == b);
        }

        template<typename T_Iterator>
        inline bool operator>(reverse_iterator<T_Iterator> const &a, reverse_iterator<T_Iterator> const &b){
            return b < a;
        }

        template<typename T_Iterator>
        inline bool operator>=(reverse_iterator<T_Iterator> &a, reverse_iterator<T_Iterator> &b){
            return !(a < b);
        }

        template<typename T_Iterator>
        inline bool operator<=(reverse_iterator<T_Iterator> &a, reverse_iterator<T_Iterator> &b){
            return !(b < a);
        }

        template<typename T_IteratorL, typename T_IteratorR>
        inline bool operator==(reverse_iterator<T_IteratorL> const &x, reverse_iterator<T_IteratorR> const &y ){
            return x.base() == y.base();
        }

        template<typename T_IteratorL, typename T_IteratorR>
        inline bool operator<(reverse_iterator<T_IteratorL> const &x, reverse_iterator<T_IteratorR> const &y ){
            return y.base() < x.base();
        }

        template<typename T_IteratorL, typename T_IteratorR>
        inline bool operator!=(reverse_iterator<T_IteratorL>  const &x, reverse_iterator<T_IteratorR> const &y ){
            return !(x == y);
        }

        template<typename T_IteratorL, typename T_IteratorR>
        inline bool operator>(reverse_iterator<T_IteratorL> const &x, reverse_iterator<T_IteratorR> const &y ){
            return y < x;
        }

        template<typename T_IteratorL, typename T_IteratorR>
        inline bool operator<=(reverse_iterator<T_IteratorL> const &x, reverse_iterator<T_IteratorR> const &y ){
            return !(y < x);
        }

        template<typename T_IteratorL, typename T_IteratorR>
        inline bool operator>=(reverse_iterator<T_IteratorL> const &x, reverse_iterator<T_IteratorR> const &y ){
            return !(x < y);
        }

       template<typename T_IteratorL, typename T_IteratorR>
       inline typename reverse_iterator<T_IteratorL>::difference_type
       operator-(reverse_iterator<T_IteratorL> const &x, reverse_iterator<T_IteratorR> const &y){
            return y.base() - x.base();
        }

        template<class T_Iterator>
        inline typename reverse_iterator<T_Iterator>::difference_type
        operator-(reverse_iterator<T_Iterator> const &x, reverse_iterator<T_Iterator> const &y){
            return (y.base() - x.base());

        }
        

       template<typename T_Iterator>
       inline  reverse_iterator<T_Iterator>
       operator+(typename reverse_iterator<T_Iterator>::difference_type n , reverse_iterator<T_Iterator> const &x){
            return reverse_iterator<T_Iterator>(x.base() - n);
        }



}
#endif //ITERATOR_HPP
