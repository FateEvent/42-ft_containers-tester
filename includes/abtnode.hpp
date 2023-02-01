//
// Created by Stephane Walter on 1/12/23.
//

#ifndef FT_CONTENAIR_ABTNODE_HPP
#define FT_CONTENAIR_ABTNODE_HPP

#include <iostream>

namespace ft {
    template<class Pair>
    struct abtnode
    {
        abtnode* parent;
        abtnode* left;
        abtnode* right;
        Pair value;

        explicit abtnode() : parent(NULL), left(NULL), right(NULL), value() {

        }

        explicit abtnode(const Pair &data) : parent(NULL), left(NULL), right(NULL), value(data) {

        }

        ~abtnode() {}

        abtnode(const abtnode &x) : parent(x.parent), left(x.left), right(x.right), value(x.value) {

        }

        abtnode &operator=(const abtnode &x) {
            if (this != &x) {
                parent = x.parent;
                left = x.left;
                right = x.right;
                value = x.value;
            }
            return *this;
        }

        //    min est a left
        //    max est a right

        abtnode *findmin(abtnode *node) {
            if (!node)
                return NULL;
            while (node->left)
                node = node->left;
            return node;
        }

        abtnode *findmax(abtnode *node) {
            if (!node)
                return NULL;
            while (node->right)
                node = node->right;
            return node;
        }

        abtnode *next() {
            abtnode *tmp = this;
            if (tmp->right)
                return findmin(tmp->right);

            abtnode *tmpparent = tmp->parent;

            while (tmpparent && tmp == tmpparent->right) {
                tmp = tmpparent;
                tmpparent = tmpparent->parent;
            }
            return tmpparent;
        }

        abtnode *prev() {
            abtnode *tmp = this;
            if (tmp->left)
                return findmax(tmp->left);
            abtnode *prevp = tmp->parent;
            while (prevp && tmp == prevp->left) {
                tmp = prevp;
                prevp = prevp->parent;
            }
            return prevp;
        }

    };

}










#endif //FT_CONTENAIR_ABTNODE_HPP
