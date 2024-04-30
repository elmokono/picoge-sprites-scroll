#ifndef MAPS_H
#define MAPS_H

struct cell
{
  point position;
  unsigned short* sprite; //pointer to sprite
};

// maps and sprites
struct level
{
  const char *name;
  unsigned short mapCellsWidth; //amount of cells
  unsigned short mapCellsHeight; //amount of cells
  unsigned short cellWidth; //in pixels
  unsigned short cellHeight; //in pixels
  
  unsigned short* bgImage; // pointer to sprite

  cell* cells2; // pointers to cells
  unsigned short** cells; // pointers to sprites
  unsigned short cells_count; //mapCellsWidth*mapCellsHeight
  
  rect* collisions; // map of collisions
  unsigned short collisions_count; //count of collisions
  
  precisionPoint* npcs;
  unsigned short npcs_count;
  
  precisionPoint player;
};

level initMap(unsigned short levelNumber);

#endif