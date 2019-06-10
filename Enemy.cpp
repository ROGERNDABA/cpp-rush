/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmil.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:43:08 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/10 14:43:10 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"
#include <ncurses.h>

Enemy::Enemy(void) : Screen() {
    char form[2] = {'K', 'Q'};
    _player = form[rand() % 2];
}

Enemy::Enemy(int x, int y) : Screen(x, y) {
    char form[2] = {'K', 'Q'};
    _player = form[rand() % 2];
}

Enemy::Enemy(Enemy const& src) : Screen(src.getX(), src.getY()) {
}

Enemy::~Enemy(void) {
}

bool Enemy::move(int timeInterval) {
    if (_x >= 11) {
        if (timeInterval % 2 == 0) {
            _x--;
        }
        return TRUE;
    } else
        return FALSE;
}
