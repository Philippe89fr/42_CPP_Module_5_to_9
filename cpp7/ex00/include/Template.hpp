/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:49:39 by prambaud          #+#    #+#             */
/*   Updated: 2025/04/02 11:30:56 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>

template <typename T>

T max(const T &a, const T &b)
{
    return (a > b) ? a : b;
}

template <typename T>

T min(const T &a, const T &b)
{
    return (a < b) ? a : b;
}

template <typename T>

void swap(T &a, T &b)
{
    T c;
    c = a;
    a = b;
    b = c;
}
