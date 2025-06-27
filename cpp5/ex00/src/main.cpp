/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:49:39 by prambaud          #+#    #+#             */
/*   Updated: 2025/03/27 11:00:00 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"


int main( void ) 
{
	Bureaucrat Lucas("lucas", 149);
	Bureaucrat Yo(Lucas);
	Bureaucrat Phil("Phil", 1);
	std::cout << Lucas << std::endl; 
	try
	{
		Lucas.decrementGrade();
		Lucas.decrementGrade();
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
	std::cout << Lucas << " et " << Phil << " et " << Yo << std::endl; 
	return 0;
}