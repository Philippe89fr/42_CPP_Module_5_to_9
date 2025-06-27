/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:49:39 by prambaud          #+#    #+#             */
/*   Updated: 2025/03/27 14:26:31 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"


int main( void ) 
{
	Bureaucrat Lucas("lucas", 13);
	Bureaucrat Yo(Lucas);
	Bureaucrat Phil("Phil", 1);
	Form Topsecret("Topsecret", 12, 5);
	std::cout << Topsecret << std::endl; 
	std::cout << Lucas << std::endl; 
	try
	{
		Lucas.signForm(Topsecret);
	}
	catch(Form::GradeTooLowException & e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Lucas.incrementGrade();
		Lucas.incrementGrade();
	}
	catch(Bureaucrat::GradeTooLowException & e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		Phil.incrementGrade();
	}
	catch(Bureaucrat::GradeTooHighException & e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Lucas.signForm(Topsecret);
	}
	catch(Form::GradeTooLowException & e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << Lucas << " et " << Phil << " et " << Yo << std::endl; 
	return 0;
}