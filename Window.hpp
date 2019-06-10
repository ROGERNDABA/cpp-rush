/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmil.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:03:34 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/10 14:37:01 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_HPP
#define WINDOW_HPP

#define WINHEIGHT 20
#define WINWIDTH 100

#define WINDOW_STARTX 5
#define WINDOW_STARTY 5

#include <ncurses.h>
#include <sys/time.h>
#include "Bullet.hpp"
#include "SpaceShip.hpp"
class Window {
   public:
    Window();
    Window(Window const&);
    Window const& operator=(Window const&);
    ~Window();

    void createWindow();
    void destroyWindow();
    void play();

   private:
    Screen* _objects[50];
    Screen* _bullets[500];
    SpaceShip _ship;
    int _key;
    int _prevInput;
    int _score;
    unsigned long timeInterval;
    struct timeval start;
    struct timeval now;
    WINDOW* _win;
    const int HEIGHT;
    const int WIDTH;
    const int POS_X;
    const int POS_Y;

    void init();
    void printScreen();
    void initArray();
    void initBullets();
    void initEnemy();
    void initAllBullets();
    void init_enemyBullets();
    void shoot(int);
    void shootEnemy(int, int);
    void createEnemy(int);
    void moveObjects(int const input);
    unsigned int timeDifference(timeval, timeval);
    int collide();
};

#endif
