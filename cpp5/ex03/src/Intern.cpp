/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:49:39 by prambaud          #+#    #+#             */
/*   Updated: 2025/03/28 12:07:23 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"
#include "../include/AForm.hpp"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

// Constructor

Intern::Intern()
{
    std::cout << "Un Intern est construit. Il a pas de nom" << std::endl;
    
}


Intern& Intern::operator=(const Intern& Copy)
{
    std::cout << "Intern Assignation operator called" << std::endl;
    if (this == &Copy)
        return *this;
    return *this;
}


// Destructor
Intern::~Intern()
{
    std::cout << "Un Intern est detruit" << std::endl;
}

AForm* Intern::makeForm(std::string name, std::string target)
{
    AForm* (*ptr_complain[3])(std::string) = {&PresidentialPardonForm::creat, &RobotomyRequestForm::creat, &ShrubberyCreationForm::creat};
	std::string	form[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
    int i = 0;
    AForm *The_form;

    while (i < 3)
	{
		if (form[i] == name)
		{
			The_form = ptr_complain[i](target);
			return The_form;
		}
		i++;
	}
    std::cout << "Intern cannot create this type of form, he is stupid.." << std::endl;
    return (0);
}


