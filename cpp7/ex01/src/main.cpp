/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:49:39 by prambaud          #+#    #+#             */
/*   Updated: 2025/04/03 11:43:04 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Iter.hpp"

int main( void ) 
{
	int a[3] = {2, 4, 6};
	
	iter(a, 3, print<int>);
	int i(0);
	iter(a, 3, mult2<int>);
	while(i < 3)
	{
		std::cout << a[i] << " ";
		i++;
	}
	std::cout << std::endl;
	
	return 0;
}