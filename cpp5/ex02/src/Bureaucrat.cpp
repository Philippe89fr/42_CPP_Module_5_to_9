/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:49:39 by prambaud          #+#    #+#             */
/*   Updated: 2025/03/28 12:07:23 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

// Constructor

Bureaucrat::Bureaucrat(): m_name("default"), m_grade(150)
{
    std::cout << "Un Bureaucrat est construit. Il s appelle " << m_name << std::endl;
    
}

Bureaucrat::Bureaucrat(std::string name, int grade) : m_name(name), m_grade(grade)
{
    if (m_grade <= 0 )
        throw Bureaucrat::GradeTooHighException();
    if (m_grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    std::cout << "Un Bureaucrat est construit. Il s appelle " << m_name << std::endl;
}


Bureaucrat::Bureaucrat(const Bureaucrat& Copy): m_name(Copy.getName() + "_copy")
{
    m_grade = Copy.m_grade;
    std::cout << "Un Bureaucrat nomme " << m_name << " est copie" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& Copy) 
{
    if (this != &Copy) 
    {  
        m_grade = Copy.m_grade;
    }
    return *this;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
    std::cout << "Un Bureaucrat est detruit" << std::endl;
}

int Bureaucrat::getGrade() const
{
    return(m_grade);
} 

std::string Bureaucrat::getName() const
{
    return(m_name);
}

void Bureaucrat::incrementGrade() 
{
    if (m_grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    else
        m_grade--;
}

void Bureaucrat::decrementGrade() 
{
    if (m_grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    else
        m_grade++;
}

std::ostream& operator<<(std::ostream &flux, Bureaucrat const &Copy)
{
    Copy.display(flux);
    return flux;
}

void Bureaucrat::display(std::ostream &flux) const
{
    flux << m_name << ", bureaucrat grade " << m_grade;
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return ("ERREUR: la note est trop haute!\n");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return ("ERREUR: la note est trop basse!\n");
}

void Bureaucrat::signAForm(AForm& Copy)
{
    if(Copy.beSigned(*this))
        std::cout << this->m_name << " signed " << Copy.getName() << std::endl;
    else
        std::cout << this->m_name << " couldn't sign " << Copy.getName() << " because grade too low" << std::endl;
}

void Bureaucrat::executeForm(AForm const &form)
{
    if(form.execute(*this))
        std::cout << m_name << " executed " << form.getName() << std::endl;
    else
        std::cout << m_name << " can t execute :( the " << form.getName() << std::endl;
} 
