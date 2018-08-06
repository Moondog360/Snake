/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 12:34:22 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/06 16:37:08 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <dlfcn.h>
#include "main.hpp"
#include "Error.hpp"

// throw error if dlhandle isn't working
void	dlerrorWrapper()
{
	std::cerr << "Error: " << dlerror() << std::endl;
	exit( EXIT_FAILURE );
}

// check if string is made of numbers only
bool	isDigits(const std::string & str)
{
    return (str.find_first_not_of("0123456789") == std::string::npos);
}

// get width size from user. default width set to 400
int		getWidth( void )
{
	int				width = 400;
	bool			exit = false;
	std::string		line;

	std::cout << "Width size: ";
	while (getline(std::cin, line) && exit != true) 
	{
		try
		{
			if (line == "")
			{
				std::cout << "setting default width to " << width << std::endl;
				return (width);
			}
			if (isDigits(line) == true)
			{
				if (std::stoi(line) < 400 || std::stoi(line) > 1920)
					throw Error::InvalidWidth(line);
				width = std::stoi(line);
				break;
			}
			else
				throw Error::NotDigit(line);
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	std::cout << "Width size: ";
	}
	return (width);
}

// get height size from user. default set to 400
int		getHeight( void )
{
	int				height = 400;
	bool			exit = false;
	std::string		line;

	std::cout << "Height size: ";
	while (getline(std::cin, line) && exit != true) 
	{
		try
		{
			if (line == "")
			{
				std::cout << "setting default height to " << height << std::endl;
				return (height);
			}
			if (isDigits(line) == true)
			{
				if (std::stoi(line) < 400 || std::stoi(line) > 1080)
					throw Error::InvalidHeight(line);
				height = std::stoi(line);
				break;
			}
			else
				throw Error::NotDigit(line);
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	std::cout << "Height size: ";
	}
	return (height);
	
}

// check if it's a valid library
bool	validLibrary(std::string input)
{
	bool	res = false;

	input == "sfml" ? res = true : (input == "sdl" ?  res = true : (input == "glfw" ? res = true : res = false ));
	return res;
}

// ask user what libary to start with. default set to sfml
std::string		startLibrary( void )
{
	std::string		line;	
	std::string		default_library = "sfml";
	bool			exit = false;
	
	std::cout << "Please select a library to use: sfml, sdl, glfw" << std::endl;
	std::cout << "Library: ";
	while (getline(std::cin, line) && exit != true)
	{
		try
		{
			if (isDigits(line) == false)
			{
				if (validLibrary(line) == true)
				{
					default_library = line;
					break ;
				}
				else
					throw Error::InvalidLibrary(line);
			}
			else
				throw Error::InvalidLibrary(line);
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << "Library: ";
	}
	return (default_library);
}

// run the settings before hand and return the selected library
std::string		windowSettings( struct settings & set )
{
	set.width = getWidth();
	set.height = getHeight();
	return (std::string("./bin/"+startLibrary()+".so"));
}

int	main( void )
{
	struct settings		set;
	void				*dl_handle;
	void				(*fn_pointer)(struct settings);

	const char *library = windowSettings(set).c_str();
	dl_handle = dlopen( library, RTLD_LAZY | RTLD_LOCAL );
	if ( !dl_handle )
		dlerrorWrapper();
	fn_pointer = (void(*)(struct settings)) dlsym(dl_handle, "test");
	if (!fn_pointer)
		dlerrorWrapper();
	fn_pointer(set);
	return (0);
}
