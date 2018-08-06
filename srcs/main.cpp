/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 12:34:22 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/06 10:22:13 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <dlfcn.h>
#include "main.hpp"

void	dlerror_wrapper()
{
	std::cerr << "Error: " << dlerror() << std::endl;
	exit( EXIT_FAILURE );
}

int	main(int ac, char **av)
{
	struct settings		set;
	void				*dl_handle;
	void				(*fn_pointer)(struct settings);
	const char			*sfml = std::string( "./bin/sfml.so" ).c_str();
	const char			*sdl = std::string( "./bin/sdl.so" ).c_str();
	const char			*glfw = std::string( "./bin/glfw.so" ).c_str();

	set.width = 400;
	set.height = 400;
	if (ac > 1)
	{
		if (strcmp(av[1], "1") == 0)
		{
			dl_handle = dlopen( sfml, RTLD_LAZY | RTLD_LOCAL );
			if ( !dl_handle )
				dlerror_wrapper();
			fn_pointer = (void(*)(struct settings)) dlsym(dl_handle, "test");
			if (!fn_pointer)
				dlerror_wrapper();
			fn_pointer(set);
		}
		else
			std::cout << "invalid argument" << std::endl;
	}
	else
		std::cout << "No aurguments given" << std::endl;
	return (0);
}
