/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:49:39 by prambaud          #+#    #+#             */
/*   Updated: 2025/03/27 14:12:48 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <fstream>
#include <cstddef>

template<typename T>
class Array
{
    public:
    Array() {
        m_array(NULL);
        m_size = 0;
        std::cout << "Array basic constructor called" << std::endl;
    };
    Array(unsigned int n): m_size(n) {
        m_array = new T[m_size];
        std::cout << "Array constructor with size called" << std::endl;
    };
    // Constructeur de copie (Deep Copy)
    Array(const Array& Copy){
        m_size = Copy.m_size;
        m_array = new T[m_size];
        unsigned int i(0);
        while(i < m_size)
            {
                m_array[i] = Copy.m_array[i];
                i++;
            }
        std::cout << "Array has been copied" << std::endl;
    };

    // Opérateur d'affectation (=) (Deep Copy)
    Array& operator=(const Array& Copy){
        if(this != &Copy)
        {
            if(this-> m_array)
                delete[] this-> m_array;
            m_size = Copy.size();
            m_array = new T[m_size];
            int i(0);
            while(i < m_size)
            {
                m_array[i] = Copy.m_array[i];
                i++;
            }
        }
        return *this;
    };

    unsigned int size() const{
        return m_size;
    };

    // operateur []
    T &operator[](unsigned int index) {
        if(index >= this->m_size)
            throw OutofboundsException();
        return this->m_array[index];
    };

    const T &operator[](unsigned int index) const {
        if(index >= this->m_size)
            throw OutofboundsException();
        return this->m_array[index];
    };

    ~Array(){
        if(this-> m_array) {
            delete[] m_array;
        }
        std::cout << "Array destructor called" << std::endl;
    };

    class OutofboundsException: public std::exception {
        public:
        virtual const char* what(void) const throw() {
            return ("Index out of bounds\n");
        };
    };

    private:
    unsigned int m_size;
    T *m_array;
};
