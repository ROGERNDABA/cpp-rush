/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmil.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 12:53:46 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/10 12:53:48 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Window.hpp"
#include <ncurses.h>
#include <sys/time.h>
#include <cstdlib>
#include <iostream>

Window::Window() : _ship(SpaceShip()), input(ERR), _prevInput(ERR), timeInterval(0), HEIGHT(WINHEIGHT), WIDTH(WINWIDTH), POS_X(WINDOW_STARTX), POS_Y(WINDOW_STARTY) {
    init();
}

Window::Window(Window const& src) : _ship(SpaceShip()), input(ERR), _prevInput(ERR), HEIGHT(WINHEIGHT), WIDTH(WINWIDTH), POS_X(WINDOW_STARTX), POS_Y(WINDOW_STARTY) {
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
        this->input = rhs.input;
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

void Window::printScreen() {
    mvprintw(4, 5, "SCORE ");
    mvprintw(4, 12, "%d", _score);

    mvprintw(4, 20, "%d", _ship.life);
    mvprintw(4, 15, "LIVES");
    _ship.printObject();
}

void Window::init() {
    noecho();
    curs_set(false);
    timeout(0);
    cbreak();
    keypad(stdscr, true);

    gettimeofday(&start, NULL);
    refresh();
    createWindow();
    printScreen();
}

unsigned int Window::timeDiff(timeval t1, timeval t2) {
    return ((t2.tv_sec * 1000000 + t2.tv_usec) - (t1.tv_sec * 1000000 + t1.tv_usec));
}

void Window::play() {
    _score = 0;
    input = getch();
    while (input != 27) {
        input = getch();
        if (input != ERR) {
            _prevInput = input;
        }
        gettimeofday(&now, NULL);
        if (timeDiff(start, now) >= (1000000 / 24)) {
            destroyWindow();
            createWindow();
            printScreen();
            _prevInput = ERR;
            start = now;
            timeInterval++;
        }
    }
}
