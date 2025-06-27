/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:49:39 by prambaud          #+#    #+#             */
/*   Updated: 2025/03/28 12:13:45 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include <cstdlib>

int main( void ) 
{
	srand(time(NULL));
	Bureaucrat *Lucas = new Bureaucrat("Lucas", 13);
	Bureaucrat *Phil = new Bureaucrat("Phil", 15);
	//AForm Topsecret("Topsecret", 12, 5);
	ShrubberyCreationForm *Shrub = new ShrubberyCreationForm("Maison");
	PresidentialPardonForm *Boss = new PresidentialPardonForm("The boss");
	RobotomyRequestForm *Robot = new RobotomyRequestForm("The AI");
	std::cout << *Lucas << std::endl; 
	// std::cout << Boss->getToSigne() << std::endl; 
	try
	{
		Lucas->incrementGrade();
		Lucas->incrementGrade();
	}
	catch(Bureaucrat::GradeTooLowException & e)
	{
		std::cerr << e.what() << std::endl;
	}
	// try
	// {
	// 	Shrub->beSigned(*Lucas);
	// }
	// catch(AForm::GradeTooLowException & e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	try
	{
		Lucas->executeForm(*Shrub);
	}
	catch(AForm::ExecutionException & e)
	{
		std::cerr << e.getErrorMessage(*Shrub) << std::endl;
	}
	try
	{
		Lucas->signAForm(*Boss);
	}
	catch(AForm::GradeTooLowException & e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		Lucas->executeForm(*Boss);
	}
	catch(AForm::ExecutionException & e)
	{
		std::cerr << e.getErrorMessage(*Boss) << std::endl;
	}
	
	try
	{
		Lucas->signAForm(*Robot);
	}
	catch(AForm::GradeTooLowException & e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Lucas->executeForm(*Robot);
	}
	catch(AForm::ExecutionException & e)
	{
		std::cerr << e.getErrorMessage(*Robot) << std::endl;
	}
	delete Lucas;
	delete Shrub;
	delete Robot;
	delete Boss;
	delete Phil;
	return 0;
}