/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyBullet.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmil.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 15:06:45 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/10 15:06:46 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Screen.hpp"

#ifndef Enemy_Bullet_HPP
#define Enemy_Bullet_HPP

class EnemyBullet : public Screen {
   public:
    EnemyBullet(void);
    EnemyBullet(int x, int y);
    EnemyBullet(EnemyBullet const& src);
    ~EnemyBullet();
    using Screen::operator=;
    bool move(int);
    bool colision(Screen const& elem);
};

#endif
