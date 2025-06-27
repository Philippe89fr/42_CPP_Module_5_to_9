/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
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
# include <fstream>

class Bureaucrat;

class AForm
{
    public:
    AForm();
    AForm(std::string name, int toExecute, int toSigne);
    // Constructeur de copie (Deep Copy)
    AForm(const AForm& Copy);
    // Opérateur d'affectation (=) (Deep Copy)
    AForm& operator=(const AForm& Copy);
    void display(std::ostream &flux) const;
    int getToExecute() const;
    int getToSigne() const;
    bool getSigne() const;
    std::string getName() const;
    bool beSigned(Bureaucrat &Copy);
    virtual bool execute(Bureaucrat const &executor) const = 0;
    virtual ~AForm();

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

    class ExecutionException: public std::exception 
    {
        public:
        std::string getErrorMessage(AForm &Form) const throw();
    }; 
    
    private:
    const std::string m_name;
    bool m_signed;
    const int m_toSigne;
    const int m_toExecute;
};

std::ostream& operator<<(std::ostream &flux, AForm const &Copy);

