/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpaceShip.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmil.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:03:17 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/10 15:14:50 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpaceShip.hpp"
#include <ncurses.h>
#include "Window.hpp"

SpaceShip::SpaceShip(void) : Screen(), life(3) {
    _player = 'E';
}

SpaceShip::SpaceShip(int x, int y) : Screen(x, y), life(3) {
    _player = 'E';
}

SpaceShip::SpaceShip(SpaceShip const& copy) : Screen(copy.getX(), copy.getY()) {}

SpaceShip::~SpaceShip(void) {}

bool SpaceShip::move(int timeInterval) {
    if (timeInterval == 0)
        return 1;
    return 0;
}

void SpaceShip::move(int const key, int timeInterval) {
    if (timeInterval) {
        if (key == KEY_UP && _y > (WINDOW_STARTY + 1))
            _y--;
        else if (key == KEY_DOWN && _y < (WINDOW_STARTY + WINHEIGHT - 2))
            _y++;
    }
}