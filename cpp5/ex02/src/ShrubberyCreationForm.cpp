/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:30:48 by prambaud          #+#    #+#             */
/*   Updated: 2025/03/28 12:07:35 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Bureaucrat.hpp"
#include <iostream>
#include <string>

// Constructor

ShrubberyCreationForm::ShrubberyCreationForm(): AForm::AForm("ShrubberyCreationForm", 145, 137), m_target("default")
{
    std::cout << "Un ShrubberyCreationForm est construit. Sa target est " << m_target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm::AForm("ShrubberyCreationForm", 145, 137), m_target(target)
{
    std::cout << "Un ShrubberyCreationForm est construit. Sa target est " << m_target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& Copy)
{
    m_target = Copy.m_target;
    std::cout << "Un ShrubberyCreationForm avec une target  " << m_target << " est copie" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& Copy) 
{
    if (this != &Copy) 
    {  
        m_target = Copy.m_target;
    }
    return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Un ShrubberyCreationForm est detruit" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const
{
    return(m_target);
} 

std::ostream& operator<<(std::ostream &flux, ShrubberyCreationForm const &Copy)
{
    Copy.display(flux);
    return flux;
}


bool ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!this->getSigne() && (executor.getGrade() <= this->getToExecute()))
    {
       throw  AForm::ExecutionException();
       return false;
    }
    else
    {
        std::string name = m_target + "_shrubbery";
        std::ofstream fichier(name.c_str());  // Création un fichier 
        if (fichier) 
            fichier << "ASCII trees" << std::endl;
        else
            std::cerr << "Erreur lors de la création du fichier !" << std::endl;
        fichier.close();
        return true;
    }
}

