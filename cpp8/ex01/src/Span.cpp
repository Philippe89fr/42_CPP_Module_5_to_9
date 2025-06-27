/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:49:39 by prambaud          #+#    #+#             */
/*   Updated: 2025/04/04 16:50:51 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

    Span::Span() {
        _size = 0;
    };
    
    Span::Span(unsigned int N) {
        _size = N;
    };
    
    Span::Span(const Span &copy) {
        _size = copy._size;
        _tableau = copy._tableau;
    };

    Span& Span::operator=(const Span &copy) {
        if(this != &copy)
        {
            _size = copy._size;
            _tableau = copy._tableau;
        }
        return *this;
    }; 
    
    void  Span::addNumber(int num) {
        if(_tableau.size() < _size)
        {
            _tableau.push_back(num);
        }
        else 
            throw std::runtime_error("Span is full");
    };

    unsigned int   Span::shortestSpan() {
        std::sort(_tableau.begin(), _tableau.end());
        int distance(0);
        int temp(0);
        std::vector<int>::iterator it;
        it = _tableau.begin();
        if (_tableau.size() < 2)
            throw std::runtime_error("Not enough elements to calculate span");
        temp = *it;
        it++;
        distance = abs(*it - temp);
        while(it != _tableau.end())
        {
            temp = *it;
            it++;
            distance = std::min(distance, abs(*it - temp));
        }
        return distance;
    };

    unsigned int  Span::longestSpan() {
        std::sort(_tableau.begin(), _tableau.end());
        int distance(0);
        int temp(0);
        std::vector<int>::iterator it;
        it = _tableau.begin();
        if (_tableau.size() < 2)
            throw std::runtime_error("Not enough elements to calculate span");
        temp = _tableau.back();
        distance = abs(temp - *it);
        return distance;
    };

    Span::~Span() {};

    std::vector<int> Span::getTableau() { 
        return _tableau;
    };
    

    
