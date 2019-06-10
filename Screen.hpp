/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Screen.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmil.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 11:47:23 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/10 12:35:27 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>

#ifndef Screen_HPP
#define Screen_HPP

class Screen {
   public:
    Screen(void);
    Screen(int x, int y);
    Screen(Screen const& src);
    virtual ~Screen();

    Screen const& operator=(Screen const& rdh);
    virtual bool move(int) = 0;

    bool colision(Screen*&);
    virtual void printObject();
    int getX(void) const;
    int getY(void) const;

    int _x;
    int _y;
    char _player;
};

#endif
