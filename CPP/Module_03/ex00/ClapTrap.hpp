/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:29:21 by eorer             #+#    #+#             */
/*   Updated: 2023/12/08 12:22:52 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

# define COUT(x) std::cout << x << std::endl

class ClapTrap{
  public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &clap);
	~ClapTrap();
	ClapTrap& operator=(const ClapTrap &clap);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

  private:
	std::string _name;
	int	_hit_point;
	int	_energy_point;
	int	_attack_damage;
};

#endif
