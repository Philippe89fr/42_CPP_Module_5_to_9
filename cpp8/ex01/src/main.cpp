/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:49:39 by prambaud          #+#    #+#             */
/*   Updated: 2025/04/08 10:09:52 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

int main()
{
    srand(time(NULL));
try
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    sp.addNumber(6);
}
catch(const std::runtime_error& e)
{
    std::cerr << e.what() << '\n';
}
/// XX nombres. 
try
{
    int nb = 20;
    Span sp1 = Span(nb);
    int i(0);
    while(i < nb)
    {
        sp1.addNumber(rand() % 100);
        i++;
    }
    std::cout << sp1.shortestSpan() << std::endl;
    std::cout << sp1.longestSpan() << std::endl;\
    i = 0;
    std::cout << "Les nombres sont: " << sp1.getTableau()[0] <<  ", ";
    while(i < nb)
    {
        std::cout << sp1.getTableau()[i] <<  ", ";
        i++;
    }
    
}
catch(const std::runtime_error& e)
{
    std::cerr << e.what() << '\n';
}

return 0;
}