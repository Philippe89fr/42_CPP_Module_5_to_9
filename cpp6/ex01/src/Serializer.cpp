/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:49:39 by prambaud          #+#    #+#             */
/*   Updated: 2025/04/01 11:42:03 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"
#include <iostream>
#include <string>

// Constructor

Serializer::Serializer()
{
    std::cout << "Un Serializer est construit. Il s appelle " << std::endl;
}


Serializer::Serializer(const Serializer&)
{
    std::cout << "Un Serializer  est copie" << std::endl;
}

Serializer& Serializer::operator=(const Serializer& Copy) 
{
    if (this != &Copy) 
        return *this;
    return *this;
}

// Destructor
Serializer::~Serializer()
{
    std::cout << "Un Serializer est detruit" << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr) 
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) 
{
    return reinterpret_cast<Data*>(raw);
}
