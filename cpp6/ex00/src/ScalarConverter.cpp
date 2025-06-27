/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:49:39 by prambaud          #+#    #+#             */
/*   Updated: 2025/03/27 12:19:51 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"
#include <iostream>
#include <sstream>  
#include <string>

// Constructor

ScalarConverter::ScalarConverter()
{ 
    std::cout << "Un ScalarConverter est construit." << std::endl;
    
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& Copy) 
{
    if (this != &Copy) 
    {  
        return *this;
    }
    return *this;
}

// Destructor
ScalarConverter::~ScalarConverter()
{
    std::cout << "Un ScalarConverter est detruit" << std::endl;
}
void ScalarConverter::convert(const std::string& str) {
    char value_char = 0;
    int value_int = 0;
    float value_float = 0.0f;
    double value_double = 0.0;
    bool flag = false;
    char* str2;

    //conversion
    // si un seul caractère et pas un chiffre >>> char.
    if (str.length() == 1 && !isdigit(str[0])) 
    {
        value_char = str[0];
        value_int = static_cast<int>(value_char);
        value_float = static_cast<float>(value_char);
        value_double = static_cast<double>(value_char);
    } 
    else if (str == "-inff" || str == "+inff" || str == "nanf") 
    {
        value_float = strtof(str.c_str(), NULL); //convert en float
        value_double = static_cast<double>(value_float);
        flag = true;
    } 
    else if (str == "-inf" || str == "+inf" || str == "nan") 
    {
        value_double = strtod(str.c_str(), NULL); //convert en double
        value_float = static_cast<float>(value_double);
        flag = true;
    } 
    else 
    {
        value_double = strtod(str.c_str(), &str2);
        // check si float ou double (end termine par f\0 ou \0) car strtod pointe sur premier caract invalide
        if ((*str2 == 'f' && *(str2 + 1) == '\0') || *str2 == '\0') 
        {
            value_float = static_cast<float>(value_double);
            value_int = static_cast<int>(value_double);
        } 
        else 
        {
            std::cout << "Invalid input" << std::endl;
            return;
        }
    }
    //affichage
    if (!flag) 
    {
        if (value_double < std::numeric_limits<char>::min() || value_double > std::numeric_limits<char>::max() || !isprint(value_int))
            std::cout << "char: Non displayable" << std::endl;
        else 
            std::cout << "char: '" << static_cast<char>(value_int) << "'" << std::endl;
        if (value_double < std::numeric_limits<int>::min() || value_double > std::numeric_limits<int>::max())
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << value_int << std::endl;
    } 
    else 
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    std::cout << "float: " << std::fixed << std::setprecision(1) << value_float << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << value_double << std::endl;
}

const char* ScalarConverter::GradeTooHighException::what(void) const throw()
{
    return ("ERREUR: la note est trop haute!\n");
}
