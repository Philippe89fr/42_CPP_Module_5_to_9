/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:49:39 by prambaud          #+#    #+#             */
/*   Updated: 2025/04/18 14:29:59 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

void isPositiveInteger(const char* str) {
    int i(0);
    while(str[i])
    {
        if(!isdigit(str[i]))
            throw std::runtime_error("Error: Wrong input1");
        i++;
    }
    int nb = atoi(str);
    if(nb < 0)
        throw std::runtime_error("Error: Wrong input2");
}

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error: Wrong argument\n";
        return 1;
    }
    int i(1);
    try
    {
        while (av[i])
        {
            isPositiveInteger(av[i]);
            i++;
        }
        i = 1;
        std::cout << "Before: ";
        while (av[i])
        {
            std::cout << " " << av[i];
            i++;
        }
        std::cout << "\n";
        ft_PmergeMe_vec(ac, av);
        ft_PmergeMe_deque(ac, av);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
    return 0;
}

//./PmergeMe $(shuf -i 0-9999 -n 3000)