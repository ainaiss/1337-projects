/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:17:23 by fel-boua          #+#    #+#             */
/*   Updated: 2022/03/25 01:26:24 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv)
{   
    if (argc == 1)
        return(std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n", 1);
    for (int i = 1; i < argc; i++)
    {
        std::string arg = argv[i];
        for (int j = 0; j < (int)arg.length(); j++)
        {
            char c = toupper(arg[j]);
            std::cout << c;
        }
    }
    std::cout << std::endl;
    return 0;
}