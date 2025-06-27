/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:37:45 by prambaud          #+#    #+#             */
/*   Updated: 2025/04/03 11:43:59 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

# include <iostream>
# include <string>

template <typename T>
void print(T a)
{
    std::cout << a << std::endl;
}

template <typename T>
void mult2(T &a)
{
    a = a*2;
}

template <typename T, typename U>
void iter(T *a,  int lenght, U func)
{
    int i(0);
    while(i < lenght)
    {
        func(a[i]);
        i++;
    }
}
