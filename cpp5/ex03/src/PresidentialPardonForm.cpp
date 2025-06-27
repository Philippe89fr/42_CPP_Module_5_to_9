/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:30:48 by prambaud          #+#    #+#             */
/*   Updated: 2025/03/28 14:48:53 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/Bureaucrat.hpp"
#include <iostream>
#include <string>

// Constructor

PresidentialPardonForm::PresidentialPardonForm(): AForm::AForm("PresidentialPardonForm", 25, 5), m_target("default")
{
    std::cout << "Un PresidentialPardonForm est construit. Sa target est " << m_target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm::AForm("PresidentialPardonForm", 25, 5), m_target(target)
{
    std::cout << "Un PresidentialPardonForm est construit. Sa target est " << m_target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& Copy)
{
    m_target = Copy.m_target;
    std::cout << "Un PresidentialPardonForm avec une target  " << m_target << " est copie" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& Copy) 
{
    if (this != &Copy) 
    {  
        m_target = Copy.m_target;
    }
    return *this;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Un PresidentialPardonForm est detruit" << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
    return(m_target);
} 

std::ostream& operator<<(std::ostream &flux, PresidentialPardonForm const &Copy)
{
    Copy.display(flux);
    return flux;
}


bool PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (!this->getSigne() && (executor.getGrade() <= this->getToExecute()))
    {
        throw  PresidentialPardonForm::ExecutionException();
        return false;
    }
    else
    {
        std::cout << m_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
        return true;
    }
}

AForm* PresidentialPardonForm::creat(std::string target)
{
    PresidentialPardonForm *TheForm = new PresidentialPardonForm(target);
    return TheForm;
}


