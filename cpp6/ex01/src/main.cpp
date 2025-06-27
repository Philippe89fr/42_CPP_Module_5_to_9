/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:49:39 by prambaud          #+#    #+#             */
/*   Updated: 2025/04/01 12:49:16 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"

int main() 
{
    Data data = {42};
    
    std::cout << "Data address: " << &data << std::endl;
    std::cout << "Data id = " << data.id  << std::endl;
    
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized Data (uintptr_t): " << raw << std::endl;
    
    Data* ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized Data address: " << ptr << std::endl;
    std::cout << "Deserialized Data: id = " << ptr->id  << std::endl;
    
    if (ptr == &data) 
        std::cout << "Serialization and deserialization successful!" << std::endl;
    else
        std::cout << "Something went wrong with serialization!" << std::endl;
    
    return 0;
}