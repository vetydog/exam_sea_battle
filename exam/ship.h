#pragma once


struct ShipInfo {
    int size;
    int hits;
    bool destroyed;
    int cells[4][2];
};