/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:49:39 by prambaud          #+#    #+#             */
/*   Updated: 2025/03/27 14:12:48 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class Form
{
    public:
    Form();
    Form(std::string name, int toExecute, int toSigne);
    // Constructeur de copie (Deep Copy)
    Form(const Form& Copy);
    // Opérateur d'affectation (=) (Deep Copy)
    Form& operator=(const Form& Copy);
    void display(std::ostream &flux) const;
    int getToExecute() const;
    int getToSigne() const;
    bool getSigne() const;
    std::string getName() const;
    bool beSigned(Bureaucrat &Copy);
    ~Form();

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
    
    private:
    const std::string m_name;
    bool m_signed;
    const int m_toSigne;
    const int m_toExecute;
};

std::ostream& operator<<(std::ostream &flux, Form const &Copy);

#endif
