//
// Created by Stephane Walter on 1/11/23.
//

#ifndef FT_CONTENAIR_MAP_HPP
#define FT_CONTENAIR_MAP_HPP

#include "pair.hpp"
#include "abtnode.hpp"
#include <stdexcept>
#include "map_iterator.hpp"
#include "utils.hpp"
#include "iterator.hpp"

namespace ft{
    template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
    class map {

    public:
        typedef Key key_type;
        typedef T   mapped_type;
        typedef ft::pair<const Key, T>  value_type;
        typedef Compare key_compare;
        typedef Alloc allocator_type;

        typedef abtnode<value_type>  map_node;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;

        typedef ft::mapiterator<map_node, value_type>   iterator;
        typedef ft::const_mapiterator<map_node, const value_type, iterator> const_iterator;
        typedef ft::reverse_iterator<iterator>  reverse_iterator;
        typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

        typedef typename std::size_t size_type;
        typedef std::ptrdiff_t difference_type;
        typedef typename Alloc::template rebind<map_node>::other		    node_allocator_type;

    private:
        key_compare _compare;
        allocator_type _alloc;
        node_allocator_type _node_alloc;

        map_node *_root;
        map_node *_end;
        map_node *_rend;
        size_type  _size;

    public:
        class value_compare {
            friend class map;

    protected:

        Compare _comp;

        value_compare(Compare c) : _comp(c) {}


    public:
        bool operator()(const value_type &x, const value_type &y) const {
            return _comp(x.first, y.first);
        }
    };



    explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()):
        _compare(comp),
        _alloc(alloc),
        _node_alloc(std::allocator<map_node>()),
        _root(NULL),
        _end(NULL),
        _rend(NULL),
        _size(0)

    {
           _end = _node_alloc.allocate(1);
           _node_alloc.construct(_end, map_node());

           _rend = _node_alloc.allocate(1);
           _node_alloc.construct(_rend, map_node());
           _rend->parent = _end;
    }

    template<class InputIt>
    map(InputIt first, InputIt last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()){
        _compare = comp;
        _size = 0;
        _alloc = alloc;
        _node_alloc = std::allocator<map_node>();
        _root = NULL;

        _end = _node_alloc.allocate(1);
        _node_alloc.construct(_end, map_node());

        _rend = _node_alloc.allocate(1);
        _node_alloc.construct(_rend, map_node());
        _rend->parent = _end;

        this->insert(first, last);
    }


    map(const map &other){
        _end = _node_alloc.allocate(1);
        _node_alloc.construct(_end, map_node());
        _rend = _node_alloc.allocate(1);
        _node_alloc.construct(_rend, map_node());
        _rend->parent = _end;
        _root = NULL;
        *this = other;
    }

    map &operator=(const map &x)
    {
            this->clear();
            _compare = x._compare;
            _size = 0;
            _alloc = x._alloc;
            _node_alloc = x._node_alloc;
            this->insert(x.begin(), x.end());
            return *this;
    }



        ~map() {
        this->clear();
        _node_alloc.destroy(_end);
        _node_alloc.deallocate(_end, 1);
        _node_alloc.destroy(_rend);
        _node_alloc.deallocate(_rend, 1);
    }



// Element access

    mapped_type &at(const key_type &key){
        iterator it = lower_bound(key);
        if(it == end() || _compare(key, *it.first))
        throw std::out_of_range("out of range");
        return (*it).second;
    }

    const mapped_type &at(const key_type &key) const {
        const iterator it = lower_bound(key);
        if(it == end() || _compare(key, *it.first))
            throw std::out_of_range("out of range");
        return (*it).second;
    }

    mapped_type &operator[](const key_type &k){
        return (*(this->insert(value_type(k, mapped_type())).first)).second;
    }



//  iterator

    iterator begin() {
        return iterator(_rend->parent);
    }

    const_iterator begin() const {
        return const_iterator(_rend->parent);
    }


    iterator end() {
        return iterator(_end);
    }

    const_iterator end() const {
        return const_iterator(_end);
    }

    reverse_iterator rbegin() {
        return reverse_iterator(_end);
    }

    const_reverse_iterator rbegin() const {
        return const_reverse_iterator(_end);
    }

    reverse_iterator rend() {
        return reverse_iterator(_rend->parent);
    }

    const_reverse_iterator rend() const {
        return const_reverse_iterator(_rend->parent);
    }

// Capacity

    bool empty() const{
        if(_size == 0)
            return 1;
        return 0;
    }

    size_type size() const {
        return _size;
    }

    size_type max_size() const {
        //return std::min<size_type>(_node_alloc.max_size(), std::numeric_limits<difference_type>::max()) ;

       // return  (size_t(-1) / sizeof(value_type));

       return (_node_alloc.max_size()  );
    }

// Modifiers

    void clear(){
        this->erase(this->begin(), this->end());
    }

    pair<iterator, bool> insert(const value_type &val){
        iterator it;
        map_node *node;
        map_node *new_node;

        if(!_root)
        {
            _root = _node_alloc.allocate(1);
            _node_alloc.construct(_root, map_node(val));

            _root->left = _rend;
            _root->right = _end;
            _end->parent = _root;
            _rend->parent = _root;

            _size = 1;
            return ft::make_pair(iterator(_root), true);

        }
        it = this->find(val.first);
        if(it != this->end())
            return ft::make_pair(it, false);
        node = _root;
        while(node->right || node->left)
        {
            if(_compare(node->value.first, val.first))
            {
                if(node->right && node->right != _end)
                    node = node->right;
                else
                    break;

            }
            else
            {
                if(node->left && node->left != _rend)
                    node = node->left;
                else
                    break;
            }
        }
        new_node = _node_alloc.allocate(1);
        _node_alloc.construct(new_node, map_node(val));
        new_node->parent = node;


        if(_compare(node->value.first, val.first))
        {
            new_node->right = node->right;
            if(new_node->right)
                new_node->right->parent = new_node;
            new_node->left = NULL;
            node->right = new_node;
        }
        else
        {
            new_node->left = node->left;
            if(new_node->left)
                    new_node->left->parent = new_node;
            new_node->right = NULL;
            node->left = new_node;

        }
        _size++;
        return ft::make_pair(new_node, true);
}

    iterator insert(iterator pos, const value_type &val ){
        (void)pos;
        return (this->insert(val)).first;
    }

    template <class InputIt>
    void insert (InputIt first, InputIt last){
        while(first != last) {
            this->insert(*first);
            first++;
        }
    }

    void erase(iterator pos){
        map_node    *node;
        map_node    *right;
        map_node    *left;
        map_node    *parent;
        map_node    *next;

        node = pos.get_it();
        right = node->right;
        left = node->left;
        parent = node->parent;
        next = node->next();

        if(!right && !left)
        {
            if(parent->right == node)
                parent->right = NULL;
            else
                parent->left = NULL;
        }
        else if (!right && left)
        {
            if(parent->right == node)
                parent->right = left;
            else
                parent->left = left;
            left->parent = parent;
        }
        else if(right && !left)
        {
            if(parent->right == node)
                parent->right = right;
            else
                parent->left = right;
            right->parent = parent;
        }
        else
        {
            if(next != node->right)
            {
                if(next->right)
                {
                   next->parent->left = next->right;
                   next->right->parent = next->parent;
                }
                if(!parent)
                    _root = next;
                else if(parent->right == node)
                    parent->right = next;
                else
                    parent->left = next;

                if(next->parent->right ==next)
                    next->parent->right = NULL;
                else
                    next->parent->left = NULL;

                next->parent = parent;
                next->right = right;
                next->left = left;
                left->parent = next;
                right->parent = next;

            }
            else
            {
                if(!parent)
                    _root = next;
                else if(parent->right == node)
                    parent->right = next;
                else
                    parent->left = next;
                left->parent = next;
                next->parent = parent;
                next->left = left;

            }

        }
        _node_alloc.destroy(node);
        _node_alloc.deallocate(node, 1);
        _size--;
        if(_size == 0) {
            _root = NULL;
            _rend->right = NULL;
            _rend->left = NULL;
            _end->right = NULL;
            _end->left = NULL;
            _rend->parent = _end;
        }

    }


    void erase(iterator first, iterator last){
        iterator cible;
        if(first == last)
            return ;
        cible = first;
        erase(++first, last);
        erase(cible);
    }

    size_type erase(const key_type &key){
        iterator it;
        if((it = this->find(key)) == this->end())
            return 0;
        erase(it);
        return 1;
    }


    void swap(map &other){
        map_node *tmp;
        size_type size_tmp;
        if(other == *this)
            return;
        tmp = other._root;
        other._root = _root;
        _root = tmp;

        tmp = other._end;
        other._end = _end;
        _end = tmp;

        tmp = other._rend;
        other._rend = _rend;
        _rend = tmp;

        size_tmp = other._size;
        other._size = _size;
        _size = size_tmp;
    }

// lookup

    // Returns the number of elements with key that compares equivalent to the specified argument.

    size_type count(const key_type &k) const {
        if(this->find(k) == this->end())
            return 0;
        return 1;
    }

    // Finds an element with key equivalent to key

    iterator find(const key_type &k){
        map_node *node;

        node = _root;
        while(node && node!= _end && node != _rend && (_compare(node->value.first, k) || _compare(k, node->value.first))) {
            if (_compare(node->value.first, k))
                node = node->right;
            else
                node = node->left;
        }
        if (node && node != _end && node != _rend && !_compare(node->value.first, k) && !_compare(k, node->value.first))
            return iterator(node);
        else
            return iterator(_end);

        }




    const_iterator find(const key_type &k) const {
        map_node *node;

        node = _root;
        while(node && node!= _end && node != _rend && (_compare(node->value.first, k) || _compare(k, node->value.first))) {
            if (_compare(node->value.first, k))
                node = node->right;
            else
                node = node->left;
        }
        if (node && node != _end && node != _rend && !_compare(node->value.first, k) && !_compare(k, node->value.first))
            return const_iterator(node);
        else
            return const_iterator(_end);
    }

    pair<iterator, iterator> equal_range(const key_type &k){
        iterator lower = this->lower_bound(k);
        iterator upper = this->upper_bound(k);
        return ft::make_pair(lower, upper);
    }

    pair<const_iterator, const_iterator> equal_range(const key_type &k) const {
        const_iterator lower = this->lower_bound(k);
        const_iterator upper = this->upper_bound(k);
        return ft::make_pair(lower, upper);
    }

    // Returns an iterator pointing to the first element that is not less than (i.e. greater or equal to) key.

    iterator lower_bound(const key_type &k){
        iterator it = this->begin();
        while(it != this->end()) {
            if (!_compare(it->first, k))
                break;
            it++;
        }
        return it;
    }

    const_iterator lower_bound(const key_type &k) const{
        const_iterator it = this->begin();
        while(it != this->end()) {
            if (!_compare(it->first, k))
                break;
            it++;
        }
        return it;
    }

    // Returns an iterator pointing to the first element that is greater than key.

    iterator upper_bound(const key_type &k){
        reverse_iterator it = this->rbegin();
        while(it != this->rend())
        {
            if(!_compare(k, it->first))
                break;
            it++;
        }
        return it.base();
    }

    const_iterator upper_bound(const key_type &k) const {
        const_reverse_iterator it = this->rbegin();
        while(it != this->rend())
        {
            if(!_compare(k, it->first))
                break;
            it++;
        }
        return it.base();
    }

// observers

    key_compare key_comp() const{
        return key_compare();
    }

    value_compare value_comp() const {
        return value_compare(key_comp());
    }

    allocator_type get_allocator() const{
        return _alloc;
    }

  };

// non-member functions

    template<class Key, class T, class Compare, class Alloc>
    bool operator==(const ft::map<Key, T, Compare, Alloc> &a, const ft::map<Key, T, Compare, Alloc> &b){
        typename ft::map<Key, T>::const_iterator rit = b.begin();
        typename ft::map<Key, T>::const_iterator lit = a.begin();

        if (a.size() != b.size())
            return false;
        while (rit != b.end() && lit != a.end())
        {
            if (*rit != *lit)
                return false;
            rit++;
            lit++;
        }
        return true;
    }


    template<class Key, class T, class Compare, class Alloc>
    bool operator!=(const ft::map<Key, T, Compare, Alloc> &a, const ft::map<Key, T, Compare, Alloc> &b) {
        return !(b == a);
    }

    template<class Key, class T, class Compare, class Alloc>
    bool operator<(const ft::map<Key, T, Compare, Alloc> &a, const ft::map<Key, T, Compare, Alloc> &b) {
        return (ft::lexicographical_compare(a.begin(), a.end(), b.begin(), b.end()));
    }

    template<class Key, class T, class Compare, class Alloc>
    bool operator<=(const ft::map<Key, T, Compare, Alloc> &a, const ft::map<Key, T, Compare, Alloc> &b) {
        return !(b < a);
    }

    template<class Key, class T, class Compare, class Alloc>
    bool operator>(const ft::map<Key, T, Compare, Alloc> &a, const ft::map<Key, T, Compare, Alloc> &b) {
        return b < a;
    }

    template<class Key, class T, class Compare, class Alloc>
    bool operator>=(const ft::map<Key, T, Compare, Alloc> &a, const ft::map<Key, T, Compare, Alloc> &b) {
        return !(a < b);
    }


}

#endif //FT_CONTENAIR_MAP_HPP
