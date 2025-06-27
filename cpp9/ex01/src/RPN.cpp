/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:49:39 by prambaud          #+#    #+#             */
/*   Updated: 2025/04/04 16:50:51 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

void ft_calculation(std::stack<int> &stack, char sign)
{
    if(stack.empty())
        throw std::runtime_error("Error: Not a correct RPN format");
    int temp(stack.top());
    stack.pop();
    if(stack.empty())
        throw std::runtime_error("Error: Not a correct RPN format");
    int temp2(stack.top());
    stack.pop();
    if(sign == '+')
        temp = temp2 + temp;
    else if(sign == '-')
        temp = temp2 - temp;
    else if(sign == '*')
        temp = temp2 * temp;
    else if(sign == '/') {
        if(temp == 0)
            throw std::runtime_error("Error: Cannot divid by 0");
        temp = temp2 / temp;   
    }
    stack.push(temp);
        
}

void ft_rnp(char *str)
{
    std::stack<int> stack;
    int i(0);
    int res(0);
    while (str[i])
    {
        if(isdigit(str[i])) {
            stack.push(str[i] - '0');
        }
            
        else if(isSign(str[i]))
            ft_calculation(stack, str[i]);
        i++; 
    }
    res = stack.top();
    std::cout << res; 
}

    
