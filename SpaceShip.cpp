/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpaceShip.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmil.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:03:17 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/10 13:15:34 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpaceShip.hpp"
#include <ncurses.h>
#include "Window.hpp"

SpaceShip::SpaceShip(void) : Screen() {
    _player = 'E';
    life = 3;
}

SpaceShip::SpaceShip(int x, int y) : Screen(x, y) {
    _player = 'E';
    life = 3;
}

SpaceShip::SpaceShip(SpaceShip const& src) : Screen(src.getX(), src.getY()) {
}

SpaceShip::~SpaceShip(void) {
}

bool SpaceShip::move(int timeInterval) {
    if (timeInterval == 0)
        return 1;
    return 0;
}

void SpaceShip::move(int const input, int timeInterval) {
    if (timeInterval) {
        if (input == KEY_UP && _y > (WINDOW_STARTY + 1))
            _y--;
        else if (input == KEY_DOWN && _y < (WINDOW_STARTY + WINHEIGHT - 2))
            _y++;
    }
}