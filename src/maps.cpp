#include <Arduino.h>
#include <cstring> // Para usar memcpy
#include "structs.h"
#include "sprites.h"
#include "maps.h"

level initMap(unsigned short levelNumber)
{
    level lv;
    // begin hardcoded data
    if (levelNumber == 0)
    {
        lv.name = "Level 0 - Cave 12x16 (192x256)";
        lv.mapCellsWidth = 12;
        lv.mapCellsHeight = 16;
        lv.cellWidth = 16;
        lv.cellHeight = 16;
        lv.player = {64, -24};
        lv.bgImage = sprite_bgImage_cave;
        Serial.println("level init 1");

        lv.cells_count = lv.mapCellsWidth * lv.mapCellsHeight;
        unsigned short* tmpCells[lv.cells_count] = {
            dirt, dirt, dirt, dirt, dirt, dirt, dirt, dirt, dirt, dirt, dirt, dirt,
            dirt, dirt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, dirt, dirt, dirt, dirt,
            dirt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, dirt, dirt,
            dirt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, dirt,
            dirt, grass, grass, grass, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, dirt,
            dirt, dirt, dirt, dirt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, dirt,
            dirt, nullptr, dirt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, dirt,
            dirt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, dirt,
            dirt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, dirt,
            dirt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, grass, dirt,
            dirt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, grass, grass, dirt,
            dirt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, grass, dirt, nullptr, dirt,
            dirt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, grass, dirt, nullptr, nullptr, dirt,
            dirt, nullptr, nullptr, grass, nullptr, nullptr, grass, dirt, nullptr, nullptr, nullptr, dirt,
            dirt, grass, grass, dirt, grass, grass, dirt, dirt, grass, grass, grass, dirt,
            dirt, dirt, dirt, dirt, dirt, dirt, dirt, dirt, dirt, dirt, dirt, dirt};

        lv.collisions_count = 4;
        rect tmpCollisions[lv.collisions_count] = {
            {{0, 0}, {lv.cellWidth * 1, lv.cellWidth * lv.mapCellsHeight}},                                                       // left
            {{0, 0}, {lv.cellWidth * 5, lv.cellHeight * 1}},                                                                      // top
            {{0, lv.cellHeight * (lv.mapCellsHeight - 1)}, {lv.cellWidth * lv.mapCellsWidth, lv.cellHeight * lv.mapCellsHeight}}, // bottom
            {{lv.cellWidth * (lv.mapCellsWidth - 1), 0}, {lv.cellWidth * lv.mapCellsWidth, lv.cellHeight * lv.mapCellsHeight}}    // right
        };

        lv.npcs_count = 3;
        precisionPoint tmpNpcs[lv.npcs_count] = {
            {96, 128},
            {32, 128},
            {72, 128}};

        Serial.println("level init 2");

        lv.cells = new unsigned short*[lv.cells_count];
        memcpy(lv.cells, tmpCells, lv.cells_count * sizeof(unsigned short *));

        lv.collisions = new rect[lv.collisions_count];
        memcpy(lv.collisions, tmpCollisions, lv.collisions_count * sizeof(rect));

        lv.npcs = new precisionPoint[lv.npcs_count];
        memcpy(lv.npcs, tmpNpcs, lv.npcs_count * sizeof(precisionPoint));

        Serial.println("level init 3");
    }
    // end hardcoded data

    /*

      = {
          title,
          mapCellsWidth,
          mapCellsHeight,
          blockSize,
          blockSize,
          {dirt, dirt, dirt, dirt, dirt, dirt, dirt, dirt, dirt, dirt, dirt, dirt,
           dirt, dirt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, dirt, dirt, dirt, dirt,
           dirt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, dirt, dirt,
           dirt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, dirt,
           dirt, grass, grass, grass, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, dirt,
           dirt, dirt, dirt, dirt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, dirt,
           dirt, nullptr, dirt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, dirt,
           dirt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, dirt,
           dirt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, dirt,
           dirt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, grass, dirt,
           dirt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, grass, grass, dirt,
           dirt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, grass, dirt, nullptr, dirt,
           dirt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, grass, dirt, nullptr, nullptr, dirt,
           dirt, nullptr, nullptr, grass, nullptr, nullptr, grass, dirt, nullptr, nullptr, nullptr, dirt,
           dirt, grass, grass, dirt, grass, grass, dirt, dirt, grass, grass, grass, dirt,
           dirt, dirt, dirt, dirt, dirt, dirt, dirt, dirt, dirt, dirt, dirt, dirt},
          // x1,y1,x2,y2
          {
              {{0, 0}, {blockSize * 1, blockSize * mapCellsHeight}},                                            // left
              {{0, 0}, {blockSize * 5, blockSize * 1}},                                                         // top
              {{0, blockSize * (mapCellsHeight - 1)}, {blockSize * mapCellsWidth, blockSize * mapCellsHeight}}, // bottom
              {{blockSize * (mapCellsWidth - 1), 0}, {blockSize * mapCellsWidth, blockSize * mapCellsHeight}}   // right
          },
          4,
          // npcs
          {{96, 128}, {32, 128}, {72, 128}},
          3,
          // player
          {64, 128}};
      // const rect test_collisions[1] = {{{0,240}, {12*16, 16}}};
      */
    return lv;
}
