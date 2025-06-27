/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:49:39 by prambaud          #+#    #+#             */
/*   Updated: 2025/04/04 14:18:12 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/easyfind.hpp"
#include <vector>

int main( void ) 
{
	std::vector<int> tableau(5,4);
	try
	{
		std::vector<int>::iterator find = easyfind(tableau, 4);
		std::cout << *find << std::endl;
		std::vector<int>::iterator find2;
		find2 = easyfind(tableau, 3);
	}
	catch(const std::runtime_error& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}