/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmil.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 18:02:30 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/10 11:41:19 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Screen.hpp"

#ifndef Bullet_HPP
 #define Bullet_HPP

class Bullet : public Screen
{
public:
	Bullet(void);
	Bullet(int x, int y);
	Bullet(Bullet const & src);
	~Bullet();
	using Screen::operator=;
	bool	move( int );
	bool colision(Screen const & elem);
};

#endif
