/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpaceShip.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmil.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:03:22 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/10 13:03:25 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Screen.hpp"

#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP

class SpaceShip : public Screen {
   public:
    SpaceShip(void);
    SpaceShip(int x, int y);
    SpaceShip(SpaceShip const& src);
    ~SpaceShip();
    bool move(int);
    void move(int const, int const);
    char getForm();
    int life;

   private:
};

#endif
