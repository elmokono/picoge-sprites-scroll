#ifndef MAPS_H
#define MAPS_H

// maps and sprites
struct level
{
  const char *name;
  unsigned short mapCellsWidth; //amount of cells
  unsigned short mapCellsHeight; //amount of cells
  unsigned short cellWidth; //in pixels
  unsigned short cellHeight; //in pixels
  
  unsigned short* bgImage; // pointer to sprite

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