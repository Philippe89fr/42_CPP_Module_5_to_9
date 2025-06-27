/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:49:39 by prambaud          #+#    #+#             */
/*   Updated: 2025/04/04 14:17:40 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <vector>

template <typename T>
typename T::iterator easyfind(T &a, int b)
{
   typename T::iterator it;
    it = a.begin();
    while(*it != b && it != a.end())
        it++;
    if (it == a.end())
        throw std::runtime_error("Value not found");
    return it;
}

