/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:49:39 by prambaud          #+#    #+#             */
/*   Updated: 2025/04/01 12:46:37 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
#include <stdint.h>

struct Data {
    int id;
};

class Serializer
{
    public:
    Serializer();
    Serializer(const Serializer&);
    Serializer& operator=(const Serializer&);
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
    ~Serializer();
    
    protected:
    
};
