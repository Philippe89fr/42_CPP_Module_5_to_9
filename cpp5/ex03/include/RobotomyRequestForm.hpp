/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                                           :+:      :+:    :+:   */
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

class RobotomyRequestForm: public AForm
{
    public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm& Copy);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& Copy);
    std::string getTarget() const;
    static AForm *creat(std::string target);
    bool execute(Bureaucrat const &executor) const;
    ~RobotomyRequestForm();
    
    private:
    std::string	m_target;
};
