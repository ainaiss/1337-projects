/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 00:49:25 by fel-boua          #+#    #+#             */
/*   Updated: 2022/04/01 01:52:08 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
private:
    std::string _name;

public:
    Zombie();
    Zombie(std::string);
    ~Zombie();
    std::string get_zombie_name();
    void set_zombie_name(std::string name);
    void announce(void);
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif