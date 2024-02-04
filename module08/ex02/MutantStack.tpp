#include "MutantStack.hpp"

template <typename T, typename container>
MutantStack<T, container>::MutantStack() {

}

template <typename T, typename container>
MutantStack<T, container>::MutantStack(const MutantStack &copy) {
    *this = copy;
}

template <typename T, typename container>
MutantStack<T, container> &MutantStack<T, container>::operator=(const MutantStack &copy) {
    std::stack<T, container>::operator=(copy);
    return *this;
}

template <typename T, typename container>
MutantStack<T, container>::~MutantStack() {

}

template <typename T, typename container>
typename MutantStack<T, container>::iterator MutantStack<T, container>::begin() {
    return this->c.begin();
}

template <typename T, typename container>
typename MutantStack<T, container>::iterator MutantStack<T, container>::end() {
    return this->c.end();
}