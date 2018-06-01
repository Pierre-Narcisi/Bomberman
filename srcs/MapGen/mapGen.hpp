/*
** EPITECH PROJECT, 2017
** Client
** File description:
** mapGen.hpp
*/

#pragma once

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <Graphical/SystemCreate.hpp>
#include <Graphical/EventReceiver.hpp>
#include <Graphical/SystemCreate.hpp>

class mapGen {
public:
    mapGen(int x, int y, irr::scene::ISceneManager* smgr, irr::video::IVideoDriver* driver);
private:
    void generate2D();
    void choose_pos();
    int check_wall();
    void make_unperfect();
    void create_spawn();
    void createMap();
    void createBorder();
    int _xmap;
    int _ymap;
    int _xgen;
    int _ygen;
    std::vector<std::pair<int, int>> gen;
    std::vector<std::vector<char>> _2Dmap;
    irr::scene::ISceneManager* _smgr;
    irr::video::IVideoDriver* _driver;
};
