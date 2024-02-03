#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK
#include <iostream>
#include <stack>
#include <deque>

template <typename T, typename container = std::deque <T>>
class MutantStack : public std::stack<T, container> {
    public :
        MutantStack();
        MutantStack(const MutantStack &copy);
        MutantStack &operator=(const MutantStack &copy);
        ~MutantStack();

        typedef typename container::iterator iterator;
        iterator begin();
        iterator end();
};
#include "MutantStack.tpp"
#endif