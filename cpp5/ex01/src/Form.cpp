/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:49:39 by prambaud          #+#    #+#             */
/*   Updated: 2025/03/27 14:27:08 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"
#include <iostream>
#include <string>

// Constructor

Form::Form(): m_name("default"), m_signed(0), m_toSigne(1), m_toExecute(1)
{
    std::cout << "Un Form est construit. Il s appelle " << m_name << std::endl;
}

Form::Form(std::string name, int toSigne, int toExecute): m_name(name), m_signed(0), m_toSigne(toSigne), m_toExecute(toExecute)
{
    if (this->getToExecute() <= 0 || this->getToSigne() <= 0)
        throw Form::GradeTooHighException();
    if (this->getToExecute() >= 150 || this->getToSigne() >= 150)
        throw Form::GradeTooLowException();
    std::cout << "Un Form est construit. Il s appelle " << m_name << std::endl;
}

Form::Form(const Form& Copy): m_name(Copy.m_name + "_copy"), m_toSigne(Copy.m_toSigne), m_toExecute(Copy.m_toExecute)
{
    m_signed = Copy.m_signed;
    std::cout << "Un Form nomme " << m_name << " est copie" << std::endl;
}

Form& Form::operator=(const Form& Copy) 
{
    if (this != &Copy) 
    {  
        m_signed = Copy.m_signed;
    }
    return *this;
}

// Destructor
Form::~Form()
{
    std::cout << "Un Form est detruit" << std::endl;
}

int Form::getToExecute() const
{
    return(m_toExecute);
} 

int Form::getToSigne() const
{
    return(m_toSigne);
}

bool Form::getSigne() const
{
    return(m_signed);
} 

std::string Form::getName() const
{
    return(m_name);
}

std::ostream& operator<<(std::ostream &flux, Form const &Copy)
{
    Copy.display(flux);
    return flux;
}

void Form::display(std::ostream &flux) const
{
    flux << "The Form called " << m_name << ", has a signed status of " << m_signed << ", grade required to sign it of " << m_toSigne << ", and grade required to execute it of " << m_toExecute << ".";
}

const char* Form::GradeTooHighException::what(void) const throw()
{
    return ("ERREUR: Form\\ la note est trop haute!\n");
}

const char* Form::GradeTooLowException::what(void) const throw()
{
    return ("ERREUR: Form\\la note est trop basse pour signer!\n");
}

bool Form::beSigned(Bureaucrat& Copy)
{
    if (Copy.getGrade() <= this->m_toSigne)
    {
        this->m_signed = 1;
        return true;
    }
    else
    {
        throw Form::GradeTooLowException();
        return false;
    }
}
