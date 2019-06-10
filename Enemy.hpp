/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmil.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:43:18 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/10 14:43:30 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Screen.hpp"

#ifndef ENEMY_HPP
#define ENEMY_HPP

class Enemy : public Screen {
   public:
    Enemy(void);
    Enemy(int, int);
    Enemy(Enemy const& src);
    ~Enemy();
    using Screen::operator=;
    bool move(int);
};

#endif
