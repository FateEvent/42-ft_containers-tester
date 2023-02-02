//
// Created by Stephane Walter on 1/13/23.
//

#ifndef FT_CONTENAIR_MAP_ITERATOR_HPP
#define FT_CONTENAIR_MAP_ITERATOR_HPP

#include <iterator>
#include "abtnode.hpp"

namespace ft{
    template<class T, class U, class Category = std::bidirectional_iterator_tag, class Distance = std::ptrdiff_t , class Pointer = U*, class Reference = U&>
    class mapiterator
    {
    public:
        typedef T   value_type;
        typedef Distance    difference_type;
        typedef Pointer     pointer;
        typedef Reference   reference;
        typedef Category    iterator_category;

    protected:
        T *_ptr;
    public:
        mapiterator(): _ptr(NULL){}

        mapiterator(const mapiterator &other){
            *this = other;
        }

        mapiterator(T *ptr) : _ptr(ptr){

        }

        ~mapiterator(){}

        T *get_it() const{
            return _ptr;
        }

        mapiterator &operator=(const mapiterator &other){
            if(this != &other)
                _ptr = other._ptr;
            return *this;
        }

        mapiterator &operator++(){
            _ptr = _ptr->next();
            return *this;
        }

        mapiterator &operator--(){
            _ptr = _ptr->prev();
            return *this;
        }

        mapiterator operator++(int){
            mapiterator tmp = *this;
            _ptr = _ptr->next();
            return tmp;
        }

        mapiterator operator--(int){
            mapiterator tmp = *this;
            _ptr = _ptr->prev();
            return tmp;
        }

        bool operator==(const mapiterator &other) const{
            return _ptr == other._ptr;
        }

        bool operator!=(const mapiterator &other) const {
           return _ptr != other._ptr;

        }

        reference operator*() const{
            return _ptr->value;
        }

        pointer operator->() const {
            return &_ptr->value;
        }
    };

    template<class T, class U, class mapiterator, class Category = std::bidirectional_iterator_tag, class Distance = std::ptrdiff_t , class Pointer = U*, class Reference = U&>
    class const_mapiterator
    {
    public:
        typedef T   value_type;
        typedef Distance    difference_type;
        typedef Pointer     pointer;
        typedef Reference   reference;
        typedef Category    iterator_category;

    protected:
        T *_ptr;
    public:
        const_mapiterator(): _ptr(NULL){}

        const_mapiterator(const const_mapiterator &other){
            *this = other;
        }

        const_mapiterator(T* ptr) : _ptr(ptr){

        }

        const_mapiterator(const mapiterator &other){
            _ptr = other.get_it();
        }

        ~const_mapiterator(){}

        T *get_it() const{
            return _ptr;
        }

        const_mapiterator &operator=(const const_mapiterator &other){
            if(this != &other)
                _ptr = other._ptr;
            return *this;
        }

        const_mapiterator &operator++(){
            _ptr = _ptr->next();
            return *this;
        }

        const_mapiterator &operator--(){
            _ptr = _ptr->prev();
            return *this;
        }

        const_mapiterator operator++(int){
            const_mapiterator tmp = *this;
            _ptr = _ptr->next();
            return tmp;
        }

        const_mapiterator operator--(int){
            const_mapiterator tmp = *this;
            _ptr = _ptr->prev();
            return tmp;
        }

        bool operator==(const const_mapiterator &other) const{
            return _ptr == other._ptr;
        }

        bool operator!=(const const_mapiterator &other) const {
            return _ptr != other._ptr;

        }

        const reference operator*() const{
            return _ptr->value;
        }

        const pointer operator->() const {
            return &_ptr->value;
        }



    };



}

#endif //FT_CONTENAIR_MAP_ITERATOR_HPP
