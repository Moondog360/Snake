/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 12:34:22 by mafernan          #+#    #+#             */
/*   Updated: 2018/07/30 15:47:21 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <dlfcn.h>

void	dlerror_wrapper()
{
	std::cerr << "Error: " << dlerror() << std::endl;
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	void		*dl_handle;
	void		(*fn_pointer)(void);

	if (ac > 1)
	{
		if (strcmp(av[1],"1") == 0)
		{
			dl_handle = dlopen("./bin/sfml.so", RTLD_LAZY | RTLD_LOCAL);

			if (!dl_handle)
				dlerror_wrapper();
			fn_pointer = (void(*)(void)) dlsym(dl_handle, "test");
			if (!fn_pointer)
				dlerror_wrapper();

			fn_pointer();
		}
		else if (strcmp(av[1],"2") == 0)
		{
			dl_handle = dlopen("./bin/sdl.so", RTLD_LAZY | RTLD_LOCAL);

			if (!dl_handle)
				dlerror_wrapper();
			fn_pointer = (void(*)(void)) dlsym(dl_handle, "test");
			if (!fn_pointer)
				dlerror_wrapper();

			fn_pointer();
		}
		else
			std::cout << "invalid argument" << std::endl;
	}
	else
		std::cout << "No aurguments given" << std::endl;
	return (0);
}
