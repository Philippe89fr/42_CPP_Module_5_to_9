/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:49:39 by prambaud          #+#    #+#             */
/*   Updated: 2025/03/28 11:28:50 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"
#include <iostream>
#include <string>

// Constructor

AForm::AForm(): m_name("default"), m_signed(0), m_toSigne(1), m_toExecute(1)
{
    std::cout << "Un AForm est construit. Il s appelle " << m_name << std::endl;
}

AForm::AForm(std::string name, int toSigne, int toExecute): m_name(name), m_signed(0), m_toSigne(toSigne), m_toExecute(toExecute)
{
    if (this->getToExecute() <= 0 || this->getToSigne() <= 0)
        throw AForm::GradeTooHighException();
    if (this->getToExecute() >= 150 || this->getToSigne() >= 150)
        throw AForm::GradeTooLowException();
    std::cout << "Un AForm est construit. Il s appelle " << m_name << std::endl;
}

AForm::AForm(const AForm& Copy): m_name(Copy.m_name + "_copy"), m_toSigne(Copy.m_toSigne), m_toExecute(Copy.m_toExecute)
{
    m_signed = Copy.m_signed;
    std::cout << "Un AForm nomme " << m_name << " est copie" << std::endl;
}

AForm& AForm::operator=(const AForm& Copy) 
{
    if (this != &Copy) 
    {  
        m_signed = Copy.m_signed;
    }
    return *this;
}

// Destructor
AForm::~AForm()
{
    std::cout << "Un AForm est detruit" << std::endl;
}

int AForm::getToExecute() const
{
    return(m_toExecute);
} 

int AForm::getToSigne() const
{
    return(m_toSigne);
}

bool AForm::getSigne() const
{
    return(m_signed);
} 

std::string AForm::getName() const
{
    return(m_name);
}

std::ostream& operator<<(std::ostream &flux, AForm const &Copy)
{
    Copy.display(flux);
    return flux;
}

void AForm::display(std::ostream &flux) const
{
    flux << "The AForm called " << m_name << ", has a signed status of " << m_signed << ", grade required to sign it of " << m_toSigne << ", and grade required to execute it of " << m_toExecute << ".";
}

const char* AForm::GradeTooHighException::what(void) const throw()
{
    return ("ERREUR: AForm\\ la note est trop haute!\n");
}

const char* AForm::GradeTooLowException::what(void) const throw()
{
    return ("ERREUR: AForm\\la note est trop basse!\n");
}

std::string AForm::ExecutionException::getErrorMessage(AForm &Form) const throw()
{
    std::string name = "ERREUR: AForm\\les conditions d execution de " + Form.m_name + "ne sont pas remplies!\n"; 
    return (name.c_str());
}

bool AForm::beSigned(Bureaucrat& Copy)
{
    if (Copy.getGrade() <= this->m_toSigne)
    {
        this->m_signed = 1;
        std::cout << "Le form " << this->getName() << " est signe" << std::endl;
        return true;
    }
    else
        throw AForm::GradeTooLowException();
}
