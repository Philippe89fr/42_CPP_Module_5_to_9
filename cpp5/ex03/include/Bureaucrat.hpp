/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:49:39 by prambaud          #+#    #+#             */
/*   Updated: 2025/03/28 15:08:56 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include "../include/AForm.hpp"
# include "../include/ShrubberyCreationForm.hpp"
# include "../include/PresidentialPardonForm.hpp"
# include "../include/Intern.hpp"
# include "../include/RobotomyRequestForm.hpp"
# include <iostream>
# include <string>

class Bureaucrat
{
    public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    // Constructeur de copie (Deep Copy)
    Bureaucrat(const Bureaucrat& Copy);
    // Opérateur d'affectation (=) (Deep Copy)
    Bureaucrat& operator=(const Bureaucrat& Copy);
    void incrementGrade();
    void decrementGrade();
    void display(std::ostream &flux) const;
    int getGrade() const;
    std::string getName() const;
    void signAForm(AForm& Copy);
    void executeForm(AForm const & form); 
    ~Bureaucrat();

    class GradeTooHighException: public std::exception 
    {
        public:
        virtual const char* what(void) const throw();
    };

    class GradeTooLowException: public std::exception 
    {
        public:
        virtual const char* what(void) const throw();
    };  
    
    protected:
    const std::string m_name;
    int m_grade;
};

std::ostream& operator<<(std::ostream &flux, Bureaucrat const &Copy);

#endif
