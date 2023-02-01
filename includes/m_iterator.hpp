//
// Created by Stephane Walter on 1/6/23.
//

#ifndef M_ITERATOR_HPP
#define M_ITERATOR_HPP

# include <iterator>

namespace ft {
    /* -------------------------------------------------------------------------- */
/*                               iterator_traits                              */
/* -------------------------------------------------------------------------- */

    template <typename T_Iterator> struct iterator_traits {
        typedef typename T_Iterator::iterator_category  iterator_category;
        typedef typename T_Iterator::value_type value_type;
        typedef typename T_Iterator::difference_type difference_type;
        typedef typename T_Iterator::pointer pointer;
        typedef typename T_Iterator::reference reference;
    };

    template <typename T> struct iterator_traits<T *> {
        typedef std::random_access_iterator_tag iterator_category;
        typedef T value_type;
        typedef std::ptrdiff_t difference_type;
        typedef T *pointer;
        typedef T &reference;
    };

    template <typename T> struct iterator_traits<T const *> {
        typedef std::random_access_iterator_tag iterator_category;
        typedef T value_type;
        typedef  T const *pointer;
        typedef  T const &reference;
        typedef std::ptrdiff_t difference_type;
    };

    template<class T, class Category = std::random_access_iterator_tag, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
    class m_iterator
    {

    public:
        typedef T  value_type;
        typedef Pointer pointer;
        typedef Distance difference_type;
        typedef Reference reference;
        typedef Category iterator_category;
        //typedef typename std::ptrdiff_t difference_type;
    protected:
        pointer _ptr;

    public:

        m_iterator(){}

        m_iterator(const m_iterator &other)
        {
            _ptr = other.get_pointer();
        }

        m_iterator(pointer ptr)
        : _ptr(ptr)
        { }

        ~m_iterator(){}

        pointer get_pointer() const
        {
            return _ptr;
        }

        operator m_iterator<const T>(void) const {
            return m_iterator<const T>(this->_ptr);
        }

        m_iterator &operator=(const m_iterator<const T> &other)
        {
            if(this != &other)
                _ptr = other.get_pointer();
            return *this;
        }

        m_iterator &operator++()
        {
            _ptr++;
            return *this;
        }

        m_iterator &operator--()
        {
            _ptr--;
            return *this;
        }

        m_iterator operator++(int)
        {
            m_iterator tmp(*this);
            operator++();
            return tmp;
        }

        m_iterator operator--(int)
        {
            m_iterator tmp(*this);
            operator--();
            return tmp;
        }

        //template<class T>
//        bool operator ==(m_iterator const& b) const { return (_ptr == b._ptr); };
//        bool operator !=(m_iterator const& b) const { return (_ptr != b._ptr); };
//        bool operator >(m_iterator const& b) const { return (_ptr > b._ptr); };
//        bool operator <(m_iterator const& b) const { return (_ptr < b._ptr); };
//        bool operator >=(m_iterator const& b) const { return (_ptr >= b._ptr); };
//        bool operator <=(m_iterator const& b) const { return (_ptr <= b._ptr); };

        bool operator == (const m_iterator<const T> &other) const
        {
            return (_ptr == other.get_pointer());
        }

        bool operator != (const m_iterator<const T> &other) const
        {
            return (_ptr != other.get_pointer());
        }

        bool operator > (const m_iterator<const T> &other) const
        {
            return (_ptr > other.get_pointer());
        }

        bool operator >= (const m_iterator<const T> &other) const
        {
            return (_ptr >= other.get_pointer());
        }

        bool operator < (const m_iterator<const T> &other) const
        {
            return (_ptr < other.get_pointer());
        }

        bool operator <= (const m_iterator<const T> &other) const
        {
            return (_ptr <= other.get_pointer());
        }

        //m_iterator

        value_type &operator * (void)
        {
            return (*_ptr);
        }

        value_type *operator -> (void)
        {
            return (_ptr);
        }



        m_iterator operator+(int n) const
        {
            m_iterator tmp(*this);
            tmp += n;
            return (tmp);
        }

        m_iterator operator - (int n) const
        {
            m_iterator tmp(*this);
            tmp -= n;
            return (tmp);
        }

        friend m_iterator	operator+ (std::ptrdiff_t n, m_iterator it)
        {
            m_iterator tmp(it.get_pointer());
            tmp += n;
            return (tmp);
        }

        int		operator- (m_iterator<const T> const &other) const
        {
            return _ptr - other.get_pointer();
        }

        m_iterator &operator+= (int n)
        {
            _ptr += n;
            return *this;
        }

        m_iterator &operator-= (int n)
        {
            _ptr -= n;
            return *this;
        }

        value_type &operator[] (int n) const
        {
            return _ptr[n];
        }

    };




//        template<class T_Ite>
//        reverse_iterator(reverse_iterator<T_Ite> const &x) : _cur(x.base()) {}
//
//        iterator_type base() const { return _cur; };
//
//        reference operator*() const {
//            T_Iterator tmp = _cur;
//            return *--tmp;
//        }
//
//        pointer operator->() const { return &(operator*()); }
//
//        reverse_iterator &operator++() {
//            --_cur;
//            return (*this);
//        }
//
//        reverse_iterator operator++(int) {
//            reverse_iterator tmp = *this;
//            --_cur;
//            return (tmp);
//        }
//
//        reverse_iterator operator--() {
//            ++_cur;
//            return *this;
//        }
//
//        reverse_iterator operator--(int) {
//            reverse_iterator tmp = *this;
//            ++_cur;
//            return (tmp);
//        }
//
//        reverse_iterator operator+(difference_type n) const {
//            return reverse_iterator(_cur - n);
//        }
//
//        reverse_iterator operator+=(difference_type n) {
//            _cur -= n;
//            return *this;
//        }
//
//        reverse_iterator operator-(difference_type n) const {
//            return reverse_iterator(_cur + n);
//        }
//
//        reverse_iterator operator-=(difference_type n) {
//            _cur += n;
//            return *this;
//        }
//
//        reference operator[](difference_type n) const {
//            return *(*this + n);
//        }
//    };
//
//    template<typename T_Iterator>
//    inline bool operator==(reverse_iterator<T_Iterator> const &a, reverse_iterator<T_Iterator> const &b) {
//        return a.base() == b.base();
//    }
//
//    template<typename T_Iterator>
//    inline bool operator<(reverse_iterator<T_Iterator> const &a, reverse_iterator<T_Iterator> const &b) {
//        return b.base() < a.base();
//    }
//
//    template<typename T_Iterator>
//    inline bool operator!=(reverse_iterator<T_Iterator> const &a, reverse_iterator<T_Iterator> const &b) {
//        return !(a == b);
//    }
//
//    template<typename T_Iterator>
//    inline bool operator>(reverse_iterator<T_Iterator> const &a, reverse_iterator<T_Iterator> const &b) {
//        return b < a;
//    }
//
//    template<typename T_Iterator>
//    inline bool operator>=(reverse_iterator<T_Iterator> &a, reverse_iterator<T_Iterator> &b) {
//        return !(a < b);
//    }
//
//    template<typename T_Iterator>
//    inline bool operator<=(reverse_iterator<T_Iterator> &a, reverse_iterator<T_Iterator> &b) {
//        return !(b < a);
//    }
//
//    template<typename T_IteratorL, typename T_IteratorR>
//    inline bool operator==(reverse_iterator<T_IteratorL> const &x, reverse_iterator<T_IteratorR> const &y) {
//        return x.base() == y.base();
//    }
//
//    template<typename T_IteratorL, typename T_IteratorR>
//    inline bool operator<(reverse_iterator<T_IteratorL> const &x, reverse_iterator<T_IteratorR> const &y) {
//        return y.base() < x.base();
//    }
//
//    template<typename T_IteratorL, typename T_IteratorR>
//    inline bool operator!=(reverse_iterator<T_IteratorL> const &x, reverse_iterator<T_IteratorR> const &y) {
//        return !(x == y);
//    }
//
//    template<typename T_IteratorL, typename T_IteratorR>
//    inline bool operator>(reverse_iterator<T_IteratorL> const &x, reverse_iterator<T_IteratorR> const &y) {
//        return y < x;
//    }
//
//    template<typename T_IteratorL, typename T_IteratorR>
//    inline bool operator<=(reverse_iterator<T_IteratorL> const &x, reverse_iterator<T_IteratorR> const &y) {
//        return !(y < x);
//    }
//
//    template<typename T_IteratorL, typename T_IteratorR>
//    inline bool operator>=(reverse_iterator<T_IteratorL> const &x, reverse_iterator<T_IteratorR> const &y) {
//        return !(x < y);
//    }
//
//    template<typename T_IteratorL, typename T_IteratorR>
//    inline typename reverse_iterator<T_IteratorL>::difference_type
//    operator-(reverse_iterator<T_IteratorL> const &x, reverse_iterator<T_IteratorR> const &y) {
//        return y.base() - x.base();
//    }
//
//    template<class T_Iterator>
//    inline typename reverse_iterator<T_Iterator>::difference_type
//    operator-(reverse_iterator<T_Iterator> const &x, reverse_iterator<T_Iterator> const &y) {
//        return (y.base() - x.base());
//
//    }
//
//
//    template<typename T_Iterator>
//    inline reverse_iterator<T_Iterator>
//    operator+(typename reverse_iterator<T_Iterator>::difference_type n, reverse_iterator<T_Iterator> const &x) {
//        return reverse_iterator<T_Iterator>(x.base() - n);
//    }

}

#endif //FT_CONTENAIR_M_ITERATOR_H
