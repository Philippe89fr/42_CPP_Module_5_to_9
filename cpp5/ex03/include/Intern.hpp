/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:49:39 by prambaud          #+#    #+#             */
/*   Updated: 2025/03/28 15:20:44 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "../include/AForm.hpp"
# include "../include/ShrubberyCreationForm.hpp"
# include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
# include <iostream>
# include <string>

class Intern
{
    public:
    Intern();
    Intern& operator=(const Intern& Copy);
    AForm* makeForm(std::string name, std::string target);
    ~Intern();

    protected:
   
};


