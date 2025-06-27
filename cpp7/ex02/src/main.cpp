/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:49:39 by prambaud          #+#    #+#             */
/*   Updated: 2025/04/03 15:11:17 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Array.hpp"


int main( void ) 
{
	Array<int> a(4);
	unsigned int i(0);
	a[0] = 3;
	a[1] = 5;
	a[3] = -4;
	// a = {3, 4, 1, 10};
	while(i < a.size())
	{
		std::cout << a[i++] << " ";
	}
	std::cout << std::endl;

	Array<int> b(a);
	Array<int> c = a;
	i = 0;
	while(i < c.size())
	{
		std::cout << c[i++] << " ";;
	}
	std::cout << std::endl;
	try
	{
		c[5];
	}
	catch(Array<int>::OutofboundsException& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}