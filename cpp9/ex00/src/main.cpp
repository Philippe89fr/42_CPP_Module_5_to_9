/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:49:39 by prambaud          #+#    #+#             */
/*   Updated: 2025/04/08 12:44:43 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"



int main(int ac, char **av) 
{
	if (ac != 2) {
		std::cout << "Wrong input\n";
		return 1;
	}
	std::ifstream file(av[1]);
	if (!file.is_open()) {
		std::cout << "Cannot open file\n";
		return 1;
	}
	std::map<std::string,float> maping;
	std::ifstream data("data.csv");
	if (!data.is_open()) {
		std::cout << "Cannot open data file\n";
		return 1;
	}
	maping = get_data_maping(data);
	file_parsing(file, maping);
	// std::map<std::string,float>::iterator it;
	// it = maping.begin();
	// while(it != maping.end()) {
	// 	std::cout << "Date: " << it->first << " | Value: " << it->second << std::endl;
	// 	it++;
	// }
	return 0;
}