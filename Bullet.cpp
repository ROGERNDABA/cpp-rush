/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmil.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:26:38 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/10 14:26:39 by Roger Ndaba      ###   ########.fr       */
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
