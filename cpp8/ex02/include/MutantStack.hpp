/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:28:28 by prambaud          #+#    #+#             */
/*   Updated: 2025/04/08 10:56:12 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <stack>
#include <iostream>

template <typename T>
class MutantStack: public std::stack<T> 
{
    public:
	typedef std::stack<T> stack;
    typedef typename stack::container_type container;
	typedef typename container::iterator iterator;
	MutantStack() : stack() { }
	MutantStack(const stack &src) : stack(src) {}
	~MutantStack() {}
	stack &operator=(const stack &src) {
		if (*this != src)
			*this = src;
		return (*this);
	}
	iterator begin() {
		return (stack::c.begin());
	}
	iterator end() {
		return (stack::c.end());
	}
};