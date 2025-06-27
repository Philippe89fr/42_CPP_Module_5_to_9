/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:49:39 by prambaud          #+#    #+#             */
/*   Updated: 2025/03/27 14:12:48 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
#include "../include/AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm: public AForm
{
    public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm& Copy);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& Copy);
    std::string getTarget() const;
    bool execute(Bureaucrat const &executor) const;
    ~ShrubberyCreationForm();

    
    private:
    std::string	m_target;
};

