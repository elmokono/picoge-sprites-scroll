// maps and sprites
struct level
{
  const char *name;
  const unsigned short mapCellsWidth; //amount of cells
  const unsigned short mapCellsHeight; //amount of cells
  const unsigned short cellWidth; //in pixels
  const unsigned short cellHeight; //in pixels
  const unsigned short *cells[12*16]; // pointers to sprites 12x16
  const rect collisions[4]; // map of collisions
};


const point playerStartingPos = {64, 128};
const point npcStartingPos = {96, 96};
const unsigned short mapCellsWidth = 12;
const unsigned short mapCellsHeight = 16;
const unsigned short blockSize = 16;
const char* title = "Level 0 - Demo";

const level level0 = {
  title, 
  mapCellsWidth, 
  mapCellsHeight, 
  blockSize, 
  blockSize,
  {
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
    dirt, dirt, dirt, dirt, dirt, dirt, dirt, dirt, dirt, dirt, dirt, dirt
  },
  //x1,y1,x2,y2
  { 
    {{0, 0}, {blockSize * 1, blockSize * mapCellsHeight}}, //left
    {{0, 0}, {blockSize * 5, blockSize * 1}}, //top
    {{0, blockSize * (mapCellsHeight - 1)}, {blockSize * mapCellsWidth, blockSize * mapCellsHeight}}, //bottom
    {{blockSize * (mapCellsWidth-1), 0}, {blockSize * mapCellsWidth, blockSize * mapCellsHeight}} //right
  }
};
//const rect test_collisions[1] = {{{0,240}, {12*16, 16}}};
