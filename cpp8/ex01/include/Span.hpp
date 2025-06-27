/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:37:45 by prambaud          #+#    #+#             */
/*   Updated: 2025/04/04 16:30:29 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <vector>
# include <algorithm>


class Span
{
    public:
    Span();
    Span(unsigned int N);
    Span(const Span &copy);
    Span& operator=(const Span &copy); 
    void addNumber(int num);
    unsigned int  shortestSpan();
    unsigned int longestSpan();
    std::vector<int> getTableau();
    ~Span();

    private:
    std::vector<int> _tableau;
    unsigned int _size;
};
