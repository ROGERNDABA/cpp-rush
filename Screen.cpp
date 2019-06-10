/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Screen.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmil.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:03:02 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/10 13:03:03 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Screen.hpp"
#include <ncurses.h>
#include <iostream>

Screen::Screen(void) : _x(10), _y(10), _player(' ') {}

Screen::Screen(int x, int y) : _x(x), _y(y), _player(' ') {}

Screen::Screen(Screen const& src) : _x(src._x), _y(src._y), _player(src._player) {}

Screen::~Screen(void) {}

Screen const& Screen::operator=(Screen const& rhs) {
    if (this != &rhs) {
        _player = rhs._player;
        _x = rhs._x;
        _y = rhs._y;
    }
    return *this;
}

int Screen::getX(void) const {
    return this->_x;
}

int Screen::getY(void) const {
    return this->_y;
}

void Screen::printObject() {
    char form[2] = {_player, 0};
    mvprintw(this->_y, this->_x, form);
}

bool Screen::colision(Screen*& elem) {
    return (_x >= elem->getX() && _y == elem->getY());
}
