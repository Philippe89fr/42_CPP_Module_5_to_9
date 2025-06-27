/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:21:13 by prambaud          #+#    #+#             */
/*   Updated: 2025/04/09 16:16:19 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

std::string remove_blank(const std::string &str) {
    size_t start = str.find_first_not_of(" ");
	size_t end = str.find_last_not_of(" ");
	if(start == std::string::npos || end == std::string::npos)
		return "";
	return str.substr(start, end - start + 1); 
}

bool isValid_date(const std::string &date) {
    if (date.length() != 10) {
		std::cout << "Error: bad input => " << date << std::endl;
		return false;
	}
	int i(0);
	while (i < 10)
	{
		if (i == 4 || i == 7) {
            if (date[i] != '-') {
				std::cout << "Error: bad input => " << date << std::endl;
				return false;
			}
        } 
		else {
            if (!std::isdigit(date[i])) {
				std::cout << "Error: bad input => " << date << std::endl;
				return false;
			}
		}
		i++;
	}
	int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12) {
		std::cout << "Error: bad input => " << date << std::endl;
		return false;
	}
    if (day < 1 || day > 31) {
		std::cout << "Error: bad input => " << date << std::endl;
		return false;
	}
	return true;
}

int count_dot(const std::string &price) {
	int i(0);
	int j(0);
	while (i < 10)
	{
        if (price[i] == '.') 
			j++;
		i++;
	}
	return j;
} 

bool isValid_num(const std::string &price_str) {
    int i(0);
	while (i < 10)
	{
        if (!std::isdigit(price_str[i]) && price_str[i] != '.' && count_dot(price_str) > 1) {
			std::cout << "Error: Price issue\n";
			return false;
		}
		i++;
	}
	float price = std::atof(price_str.c_str());
	if (price > 1000 ) {
		std::cout << "Error: too large a number.\n";
		return false;
	}
	if (price < 0) {
		std::cout << "Error: not a positive number.\n";
		return false;
	}
	return true;
}

void print_output(const std::string &date, const std::string &price_str, std::map<std::string,float>  &data) {
	float price = std::atof(price_str.c_str());
	float total(0);
	std::map<std::string, float>::iterator it = data.find(date);
	if (it == data.end()) {
        it = data.lower_bound(date);
		if(it == data.begin()) {
			std::cerr << "Error: no suitable date found." << std::endl;
			return;
		}
	}
	float rate = it->second;
    total = price * rate;
	std::cout << date << " => " << price_str << " = " << total << std::endl;
}

std::map<std::string,float> get_data_maping(std::ifstream &data) {
	std::string line;
	std::map<std::string,float> maping;
	while(std::getline(data, line)) {
		std::string date = line.substr(0, 10);
		std::string  price_str = line.substr(11);
		float price = std::atof(price_str.c_str());
		maping[date] = price;
	}
	return maping;
}

void file_parsing(std::ifstream &file, std::map<std::string,float>  &data) {
    std::string line;
	while(std::getline(file, line)) {
		if (line.empty()) { std::cout << "Error: Empty line\n";
			continue;
		}
        size_t delim = line.find("|");
		if (delim == std::string::npos) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
        std::string date = remove_blank(line.substr(0, delim));
		if(date == "date")
			continue;
		std::string  price_str = remove_blank(line.substr(delim + 1));
		if(isValid_date(date)) {
			if(isValid_num(price_str)) {
				print_output(date, price_str, data);
			}
		}
	}
}
