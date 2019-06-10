/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmil.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 12:53:46 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/10 15:52:27 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Window.hpp"
#include <ncurses.h>
#include <sys/time.h>
#include <iostream>

Window::Window() : _ship(SpaceShip()), _key(ERR), _prevInput(ERR), timeInterval(0), HEIGHT(WINHEIGHT), WIDTH(WINWIDTH), POS_X(WINDOW_STARTX), POS_Y(WINDOW_STARTY) {
    initGame();
}

Window::Window(Window const& copy) : _ship(SpaceShip()), _key(ERR), _prevInput(ERR), HEIGHT(WINHEIGHT), WIDTH(WINWIDTH), POS_X(WINDOW_STARTX), POS_Y(WINDOW_STARTY) {
    initGame();
    *this = copy;
}

Window::~Window() {
    destroyWindow();
    endwin();
    std::cout << "<------------DOOD------------>" << std::endl;
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

int Window::collisionDetected() {
    for (int i = 0; i < 50; ++i) {
        if (_objects[i] && _ship.colision(_objects[i]))
            _ship.life--;
        if (_ship.life < 0)
            return (1);
    }
    for (int i = 0; i < 500; ++i) {
        if (_ship.life < 0)
            return (1);
    }

    for (int j = 0; j < 500; ++j) {
        for (int k = 0; (k < 50 && _bullets[j]); ++k) {
            if (_objects[k] && _bullets[j]->colision(_objects[k])) {
                delete _bullets[j];
                _bullets[j] = NULL;
                delete _objects[k];
                _objects[k] = NULL;
                _score += 5;
            }
        }
    }
    return (0);
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
    for (int i = 0; i < 500; ++i) {
        if (_bullets[i]) {
            if (!_bullets[i]->move(timeInterval)) {
                delete _bullets[i];
                _bullets[i] = NULL;
            }
        }
    }
}

void Window::display() {
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
    }
}
void Window::createEnemy(int timeInterval) {
    if (timeInterval % 20 == 0) {
        int y = (rand() % 18) + 6;
        for (int i = 0; i < 500; ++i) {
            if (!_objects[i]) {
                _objects[i] = new Enemy(WIDTH + WINDOW_STARTX - 1, y);
                return;
            }
        }
    }
}

void Window::initGame() {
    initscr();
    noecho();
    initArray();
    initAllBullets();
    curs_set(false);
    timeout(0);
    cbreak();
    keypad(stdscr, true);

    gettimeofday(&start, NULL);
    refresh();
    createWindow();
    display();
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
            createEnemy(timeInterval);
            moveObjects(_prevInput);
            display();
            if (collisionDetected())
                return;
            _prevInput = ERR;
            start = now;
            timeInterval++;
        }
    }
}
