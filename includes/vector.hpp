//
// Created by Stephane Walter on 1/5/23.
//

#ifndef VECTOR_HPP
#define VECTOR_HPP




#include "m_iterator.hpp"
#include "iterator.hpp"
#include "utils.hpp"

namespace ft {
    template<class T, class Alloc = std::allocator<T> >
    class vector
    {
    public:
        typedef T value_type;
        typedef Alloc allocator_type;

        typedef typename std::size_t size_type;


        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;


        typedef ft::m_iterator<value_type>  iterator;
        typedef ft::m_iterator<const value_type> const_iterator;


//        typedef typename std::vector<value_type>::container_type::iterator iterator;
//        typedef typename std::vector<const value_type>::container_type::const_iterator const_iterator;

//        typedef typename std::vector<value_type>::container_type::reverse_iterator reverse_iterator;
//        typedef typename std::vector<const value_type>::container_type::const_reverse_iterator const_reverse_iterator;
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;


        typedef	typename iterator_traits<iterator>::difference_type	difference_type;


    private:
        allocator_type  _alloc;
        pointer         _start;
        size_type       _size;
        size_type       _capacity;

    public:
        explicit vector(const allocator_type &alloc = allocator_type()) :
            _alloc(alloc),
            _start(0),
            _size(0),
            _capacity(0) {}

        explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) :
            _alloc(alloc),
            _start(0),
            _size(n),
            _capacity(n)
        {
            _start = _alloc.allocate(n);
            for(size_type i = 0; i < n; i++)
                _alloc.construct(&_start[i], val);

        }

        template<class InputIterator>
        vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type()) :
            _alloc(alloc),
            _start(0),
            _size(0),
            _capacity(0)
        {
            this->assign(first, last);
        }


        vector (const vector &x) :
                _alloc(x._alloc),
                _start(0),
                _size(x._size),
                _capacity(x._size)
        {
            _start = _alloc.allocate(x._size);
            for (size_t i = 0; i < _size; i++)
                _alloc.construct(&_start[i], x._start[i]);
        }



        ~vector(void){
            this->clear();
            _alloc.deallocate(_start, _capacity);
        }

        vector &operator = (const vector &other)
        {
            if (*this == other)
                return *this;
            this->clear();
            _alloc.deallocate(_start, _capacity);
            _capacity = other._capacity;
            _size = other._size;
            _start = _alloc.allocate(_capacity);
            for (size_t i = 0; i < _size; ++i) {
                _alloc.construct(&_start[i], other._start[i]);
            }
            return *this;
        }




        template <class InputIterator>
        typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type
        assign(InputIterator first, InputIterator last)
        {
            int range_size;
            InputIterator tmp;

            tmp = first;
            range_size = 0;
            while (tmp != last)
            {
                tmp++;
                range_size++;
            }

            if (range_size < 0)
                throw std::length_error("Vector::assign");
            this->clear();
            this->reserve(range_size);
            for (; first != last; ++first)
                this->push_back(*first);
        }

        void	assign(size_type n, const value_type &val)
        {
            this->clear();
            if (_capacity < n)
                this->reserve(n);
            for (size_type i = 0; i < n; i++)
                _alloc.construct(&_start[i], val);
            _size = n;
        }

    // element access
    //at
    //front
    //back
    //operator[]
    //data
    //              allocator
        allocator_type get_allocator() const{
            return _alloc;
        }

        reference operator[](size_type n)
        {
            return _start[n];
        }
        const_reference operator[](size_type n) const
        {
            return _start[n];
        }
        reference at(size_type n)
        {
            if (n >= _size)
                throw std::out_of_range("vector");
            return _start[n];
        }
        const_reference at(size_type n) const
        {
            if (n >= _size)
                throw std::out_of_range("vector");
            return _start[n];
        }
        reference front(void)
        {
            return _start[0];
        }
        const_reference front(void) const
        {
            return _start[0];
        }
        reference back(void)
        {
            return _start[_size - 1];
        }
        const_reference back(void) const
        {
            return _start[_size - 1];
        }


    // capacity

        size_type size() const{
            return _size;
        }

        size_type max_size() const{
           return std::min<size_type>(_alloc.max_size(),std::numeric_limits<difference_type>::max());
        }


        size_type capacity() const{
         return _capacity;
        }

        bool empty() const{
            if(_size == 0)
                return true;
            else
                return false;
        }

        void reserve(size_type n)
        {
            if(n > this->max_size())
                throw std::length_error("vector::reserve");
            if(n != 0 && n > _capacity)
            {
                value_type *tmp = _alloc.allocate(n);
                for(size_type i = 0; i < _size; i++)
                    _alloc.construct(&tmp[i], _start[i]);
                for(size_type i = 0; i < _size; i++)
                    _alloc.destroy(&_start[i]);
                _alloc.deallocate(_start, _capacity);
                _capacity = n;
                _start =  tmp;

            }
        }




    //  modifiers


        void clear(void)
        {
            for (size_type i = 0; i < _size; i++)
                _alloc.destroy(&_start[i]);
            _size = 0;
        }

        void insert(iterator pos, size_type n, const value_type &val)
        {
            size_type index;
            iterator dest;
            iterator srcs;
            size_type ncapa;

            if(n == 0)
                return ;
            index= pos - this->begin();
            if(_size + n >= _capacity)
            {
                if(_size == 0 )
                    ncapa =1;
                else
                    ncapa = _size * 2;
                if(ncapa < _size + n)
                    ncapa = _size + n;
                this->reserve(ncapa);
            }
            srcs = this->end() - 1;
            dest = srcs + n;
            while(srcs >= this->begin() + index)
            {
                _alloc.construct(&(*(dest)), *srcs);
                _alloc.destroy(&(*(srcs)));
                srcs--;
                dest--;
            }
            srcs++;
            for(size_type i = 0; i < n; i++)
            {
                _alloc.construct(&(*(srcs)), val);
                srcs++;
            }
            _size += n;
        }


        iterator insert(iterator pos, const value_type &val)
        {
            //iterator it;
            size_type index;

            index = pos - this->begin();
            this->insert(pos, 1, val);
            return iterator(this->begin() + index);
        }

        template <class InputIterator>
        typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type
        insert(iterator position, InputIterator first, InputIterator last)
        {
            //iterator		tmp;
            InputIterator	tmp_input_iterator;
            iterator		mv_dest;
            iterator		mv_source;
            size_type		nb_items;
            size_type		position_len;

            tmp_input_iterator = first;
            nb_items = 0;
            while (tmp_input_iterator != last)
            {
                tmp_input_iterator++;
                nb_items++;
            }
            //tmp = iterator(&(*first));
            position_len = &(*position) - _start;
            if (_size + nb_items > _capacity)
                this->reserve(_size + nb_items);
            mv_source = this->end() - 1;
            mv_dest = mv_source + nb_items;
            while (mv_source >= iterator(_start + position_len))
            {
                _alloc.construct(&(*(mv_dest)), *mv_source);
                _alloc.destroy(&(*(mv_source)));
                mv_source--;
                mv_dest--;
            }
            mv_source++;
            while (first != last)
            {
                _alloc.construct(&(*(mv_source)), *first);
                mv_source++;
                first++;
            }
            _size += nb_items;
        }



        iterator erase(iterator pos)
        {
           return this->erase(pos, pos + 1);
        }

        iterator erase(iterator first, iterator last)
        {
            iterator tmp;
            size_type i;

            if(first == last)
                return first;
            tmp = first;
            while(tmp != last)
            {
                _alloc.destroy(&(*tmp));
                tmp++;
                _size--;
            }
            tmp = first;
            i = 0;
            while(tmp != this->end())
            {
                _alloc.construct(&(*tmp), *(last + i));
                _alloc.destroy(&(*(last + i)));
                tmp++;
                i++;

            }
            return (first);

        }

        void push_back(const value_type &val)
        {
            if(_capacity < _size + 1) {
                if (_size == 0)
                    this->reserve(1);
                else
                    this->reserve(_size * 2 );
            }
            _alloc.construct(&_start[_size], val);
            _size++;
        }

        void pop_back()
        {
            _alloc.destroy(&_start[_size - 1]);
            _size--;
        }

        void resize(size_type n, value_type val = value_type())
        {
            size_type	new_capacity;

            if (n < _size)
                while (_size != n)
                    this->pop_back();
            else if (n > _size)
            {
                if (n > _capacity)
                {
                    if (_capacity == 0)
                        new_capacity = 1;
                    else
                        new_capacity = _capacity * 2;
                    if (new_capacity < n)
                        new_capacity = n;
                    this->reserve(new_capacity);
                }
                while (_size != n)
                {
                    _alloc.construct(&_start[_size], val);
                    _size++;
                }
            }
        }



        void swap (vector &x)
        {
            value_type		*tmp_start = this->_start;
            size_type		tmp_size = this->_size;
            size_type		tmp_capacity = this->_capacity;
            allocator_type	tmp_alloc = this->_alloc;

            this->_start = x._start;
            this->_size = x._size;
            this->_capacity = x._capacity;
            this->_alloc = x._alloc;

            x._start = tmp_start;
            x._size = tmp_size;
            x._capacity = tmp_capacity;
            x._alloc = tmp_alloc;
        }

   // iterators

       iterator begin()
       {
            return iterator(_start);
       }

       const_iterator begin() const{
            return const_iterator(_start);
        }

       iterator end()
       {
            return iterator(_start +_size);
       }

       const_iterator end() const{
            return const_iterator(_start + _size);
        }

       reverse_iterator rbegin(){
            return reverse_iterator(this->end());
        }

       const_reverse_iterator rbegin() const{
            return const_reverse_iterator (this->end());
        }

       reverse_iterator rend(){
            return reverse_iterator(this->begin());
        }

       const_reverse_iterator rend() const{
            return const_reverse_iterator(this->begin());
        }




    };

    // non member fonctions

    template<class T, class Alloc>
    bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs){
        return(lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }

    template<class T, class Alloc>
    bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs){
        return(ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }

    template<class T, class Alloc>
    bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs){
        return !(lhs == rhs);
    }

    template<class T, class Alloc>
    bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs){
        return rhs < lhs;
    }

    template<class T, class Alloc>
    bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs){
        return !(rhs < lhs);
    }

    template<class T, class Alloc>
    bool operator>=(const vector<T, Alloc> & lhs, const vector<T, Alloc> &rhs){
        return !(lhs < rhs);
    }

    template<class T, class Alloc>
    inline void swap(vector<T, Alloc> &lhs, vector<T, Alloc> &rhs){
        lhs.swap(rhs);
    }



}






#endif //FT_CONTENAIR_VECTOR2_HPP
