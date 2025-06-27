/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:30:48 by prambaud          #+#    #+#             */
/*   Updated: 2025/03/28 11:09:12 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

// Constructor

RobotomyRequestForm::RobotomyRequestForm(): AForm::AForm("RobotomyRequestForm", 72, 45), m_target("default")
{
    std::cout << "Un RobotomyRequestForm est construit. Sa target est " << m_target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm::AForm("RobotomyRequestForm", 72, 45), m_target(target)
{
    std::cout << "Un RobotomyRequestForm est construit. Sa target est " << m_target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& Copy)
{
    m_target = Copy.m_target;
    std::cout << "Un RobotomyRequestForm avec une target  " << m_target << " est copie" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& Copy) 
{
    if (this != &Copy) 
    {  
        m_target = Copy.m_target;
    }
    return *this;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Un RobotomyRequestForm est detruit" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
    return(m_target);
} 

std::ostream& operator<<(std::ostream &flux, RobotomyRequestForm const &Copy)
{
    Copy.display(flux);
    return flux;
}


bool RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!this->getSigne() && (executor.getGrade() <= this->getToExecute()))
    {
       throw  RobotomyRequestForm::ExecutionException();
       return false;
    }
    else
    {
        std::cout << "Drillliiing noises!!" << std::endl;
        if (rand() % 2 == 0)
            std::cout << m_target << " has been robotomized successfully!" << std::endl;
        return true;
    }
}

