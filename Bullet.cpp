/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmil.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 18:02:34 by hlecuyer          #+#    #+#             */
/*   Updated: 2019/06/10 12:43:00 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.hpp"
#include "Window.hpp"

Bullet::Bullet(void) : Screen() {
    _player = '-';
}

Bullet::Bullet(int x, int y) : Screen(x, y) {
    _player = '-';
}

Bullet::Bullet(Bullet const& src) : Screen(src.getX(), src.getY()) {
}

Bullet::~Bullet(void) {
}

bool Bullet::move(int timeInterval) {
    if (_x > WINWIDTH + WINDOW_STARTX - 3)
        return FALSE;
    if (timeInterval % 1 == 0) {
        _x++;
    }
    return TRUE;
}
