/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:29:21 by eorer             #+#    #+#             */
/*   Updated: 2023/12/08 12:27:26 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>
# include "color.h"

# define COUT(x) std::cout << x << std::endl

class ClapTrap{
  public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &clap);
	~ClapTrap();
	ClapTrap& operator=(const ClapTrap &clap);

	//accessors
	std::string _get_name();
	int	_get_hit_point();;
	int	_get_energy_point();
	int	_get_attack_damage();
	void _set_hit_point(int i);;
	void _set_energy_point(int i);
	void _set_attack_damage(int i);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

  protected:
	std::string _name;
	int	_hit_point;
	int	_energy_point;
	int	_attack_damage;
};

#endif
