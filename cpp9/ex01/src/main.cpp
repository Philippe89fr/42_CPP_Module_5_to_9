/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:49:39 by prambaud          #+#    #+#             */
/*   Updated: 2025/04/11 11:42:57 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

bool isSign(char c) {
    std::string signs = "-+*/";
    return std::find(signs.begin(), signs.end(), c) != signs.end();
}

bool ft_splited_check(char *str)
{
    int i(0);
    while(str[i] && str[i + 1])
    {
        if(str[i] != ' ' && str[i + 1] != ' ')
            return false;
        i++;
    }
    return true;
}

bool ft_signDigiCheck(char *str)
{
    int i(0);
    while(str[i])
    {
        if(str[i] != ' ' && !isSign(str[i]) && !isdigit(str[i]))
            return false;
        i++;
    }
    return true;
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: Wrong argument\n";
        return 1;
    }
    if(!ft_splited_check(av[1]))
    {
        std::cerr << "Error: Input not splited\n";
        return 1;
    }
    if(!ft_signDigiCheck(av[1]))
    {
        std::cerr << "Error: Not signs or digits\n";
        return 1;
    }
    try
    {
        ft_rnp(av[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
    return 0;
}