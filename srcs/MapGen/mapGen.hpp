/*
** EPITECH PROJECT, 2017
** Client
** File description:
** mapGen.hpp
*/

#include <vector>
#include <iostream>
#include <stdlib.h>


class mapGen {
public:
    mapGen(int x, int y);
private:
    void generate2D();
    void choose_pos();
    int check_wall();
    void make_unperfect();
    void create_spawn();
    void createMap();
    int _xmap;
    int _ymap;
    int _xgen;
    int _ygen;
    std::vector<std::pair<int, int>> gen;
    std::vector<std::vector<char>> _2Dmap;
};