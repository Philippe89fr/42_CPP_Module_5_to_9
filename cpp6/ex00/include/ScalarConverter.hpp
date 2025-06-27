/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:49:39 by prambaud          #+#    #+#             */
/*   Updated: 2025/03/27 10:46:27 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <sstream>
# include <iomanip>
# include <limits>
# include <cmath>

class ScalarConverter
{
    public:
    ScalarConverter();
    // Opérateur d'affectation (=) (Deep Copy)
    ScalarConverter& operator=(const ScalarConverter& Copy);
    static void convert(const std::string &str);
    ~ScalarConverter();

    class GradeTooHighException: public std::exception 
    {
        public:
        virtual const char* what(void) const throw();
    };

    protected:
    const std::string m_input;
    int m_type;
    char m_char;
    int m_int;
    float m_float;
    double m_double;

};

