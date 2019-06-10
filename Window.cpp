/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmil.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 12:53:46 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/10 14:38:58 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Window.hpp"
#include <ncurses.h>
#include <sys/time.h>
#include <cstdlib>
#include <iostream>

Window::Window() : _ship(SpaceShip()), _key(ERR), _prevInput(ERR), timeInterval(0), HEIGHT(WINHEIGHT), WIDTH(WINWIDTH), POS_X(WINDOW_STARTX), POS_Y(WINDOW_STARTY) {
    init();
}

Window::Window(Window const& src) : _ship(SpaceShip()), _key(ERR), _prevInput(ERR), HEIGHT(WINHEIGHT), WIDTH(WINWIDTH), POS_X(WINDOW_STARTX), POS_Y(WINDOW_STARTY) {
    init();
    *this = src;
}

Window::~Window() {
    destroyWindow();
    endwin();
    std::cout << "* GAME OVER *" << std::endl;
}

Window const& Window::operator=(Window const& rhs) {
    if (this != &rhs) {
        this->_key = rhs._key;
        this->_prevInput = rhs._prevInput;
        this->start = rhs.start;
        this->now = rhs.now;
    }
    return *this;
}

void Window::createWindow() {
    _win = newwin(HEIGHT, WIDTH, POS_Y, POS_X);
    box(_win, '*', '*');
    wrefresh(_win);
}

void Window::destroyWindow() {
    wborder(_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    wrefresh(_win);
    clear();
    refresh();
    delwin(_win);
}

void Window::shoot(int y) {
    int i;
    for (i = 0; i < 500; i++) {
        if (_bullets[i] == NULL) {
            _bullets[i] = new Bullet(POS_X + 6, y);
            return;
        }
    }
}

void Window::moveObjects(int const input) {
    _ship.move(input, timeInterval);
    if (input == 32) {
        shoot(_ship.getY());
    }
    for (int i = 0; i < 50; ++i) {
        if (_objects[i]) {
            if (!_objects[i]->move(timeInterval)) {
                delete _objects[i];
                _objects[i] = NULL;
            }
        }
    }
    for (int i = 0; i < 50; ++i) {
        if (_objects[i]) {
            if (_objects[i] != NULL) {
                if ((rand() % 125) == 1)
                    (_objects[i]->getX(), _objects[i]->getY());
            }
        }
    }
    for (int i = 0; i < 500; ++i) {
        if (_bullets[i]) {
            if (!_bullets[i]->move(timeInterval)) {
                delete _bullets[i];
                _bullets[i] = NULL;
            }
        }
    }
}

void Window::printScreen() {
    mvprintw(4, 5, "SCORE ");
    mvprintw(4, 12, "%d", _score);

    mvprintw(4, 20, "%d", _ship.life);
    mvprintw(4, 15, "LIVES");
    _ship.printObject();
    for (int i = 0; i < 50; ++i) {
        if (_objects[i])
            _objects[i]->printObject();
    }
    for (int i = 0; i < 500; ++i) {
        if (_bullets[i])
            _bullets[i]->printObject();
    }
}

void Window::initArray() {
    for (int i = 0; i < 50; ++i) {
        if (_objects[i])
            _objects[i] = NULL;
    }
}
void Window::initBullets() {
    for (int i = 0; i < 500; ++i)
        _objects[i] = new Bullet();
}

void Window::initAllBullets() {
    for (int i = 0; i < 500; ++i) {
        if (_bullets[i])
            _bullets[i] = NULL;
        // if (_enemyBullets[i])
        //     _enemyBullets[i] = NULL;
    }
}

void Window::init() {
    initArray();
    initscr();
    noecho();
    initAllBullets();
    curs_set(false);
    timeout(0);
    cbreak();
    keypad(stdscr, true);

    gettimeofday(&start, NULL);
    refresh();
    createWindow();
    printScreen();
}

unsigned int Window::timeDifference(timeval t1, timeval t2) {
    int startTime = (t1.tv_sec * 1000000 + t1.tv_usec);
    int endTime = (t2.tv_sec * 1000000 + t2.tv_usec);
    return (endTime - startTime);
}

void Window::play() {
    _score = 0;
    _key = getch();
    while (_key != 27) {
        _key = getch();
        if (_key != ERR)
            _prevInput = _key;
        gettimeofday(&now, NULL);
        if (timeDifference(start, now) >= (1000000 / 24)) {
            destroyWindow();
            createWindow();
            moveObjects(_prevInput);
            printScreen();
            _prevInput = ERR;
            start = now;
            timeInterval++;
        }
    }
}
