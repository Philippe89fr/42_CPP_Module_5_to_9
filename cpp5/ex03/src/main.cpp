/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:49:39 by prambaud          #+#    #+#             */
/*   Updated: 2025/03/28 15:44:42 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include <cstdlib>

int main( void ) 
{
	srand(time(NULL));
	Bureaucrat *Lucas = new Bureaucrat("Lucas", 13);
	Intern *Phil = new Intern();
	//AForm Topsecret("Topsecret", 12, 5);
	ShrubberyCreationForm *Shrub = new ShrubberyCreationForm("Maison");
	PresidentialPardonForm *Boss = new PresidentialPardonForm("The boss");
	RobotomyRequestForm *Robot = new RobotomyRequestForm("The AI");
	std::cout << *Lucas << std::endl; 

	// cannot create
	AForm *DDD = Phil->makeForm("ddd", "Yololo"); 
	DDD++;

	// ShrubberyCreationForm
	AForm *YO = Phil->makeForm("ShrubberyCreationForm", "Yololo");
	std::cout << *YO << std::endl; 
	try
	{
		Lucas->signAForm(*YO);
	}
	catch(AForm::GradeTooLowException & e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Lucas->executeForm(*YO);
	}
	catch(AForm::ExecutionException & e)
	{
		std::cerr << e.getErrorMessage(*YO) << std::endl;
	}
	// PresidentialPardonForm
	AForm *PRES = Phil->makeForm("PresidentialPardonForm", "TEST");
	std::cout << *PRES << std::endl; 
	try
	{
		Lucas->signAForm(*PRES);
	}
	catch(AForm::GradeTooLowException & e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Lucas->executeForm(*PRES);
	}
	catch(AForm::ExecutionException & e)
	{
		std::cerr << e.getErrorMessage(*PRES) << std::endl;
	}
	delete YO;
	delete PRES;
	delete Lucas;
	delete Shrub;
	delete Robot;
	delete Boss;
	delete Phil;
	return 0;
}