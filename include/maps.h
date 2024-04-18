// maps and sprites
struct level
{
  const char *name;
  const unsigned short mapCellsWidth; //amount of cells
  const unsigned short mapCellsHeight; //amount of cells
  const unsigned short cellWidth; //in pixels
  const unsigned short cellHeight; //in pixels
  const unsigned short *cells[12*16]; // pointers to sprites 12x16
  const rect collisions[1]; // map of collisions
};


const point playerStartingPos = {64, 128};
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
    dirt, grass, dirt, grass, dirt, grass, dirt, grass, dirt, grass, dirt, grass,
    grass, dirt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, dirt, dirt, dirt, dirt,
    dirt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, dirt, dirt,
    grass, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, dirt,
    dirt, grass, grass, grass, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, dirt,
    grass, dirt, dirt, dirt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, dirt,
    dirt, nullptr, dirt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, dirt,
    grass, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, dirt,
    dirt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, dirt,
    grass, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, dirt, dirt, dirt,
    dirt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, dirt, dirt,
    grass, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, dirt, dirt,
    dirt, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, dirt, dirt,
    grass, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, dirt, dirt,
    dirt, grass, grass, grass, grass, grass, grass, grass, grass, grass, grass, dirt,
    grass, dirt, grass, dirt, grass, dirt, grass, dirt, grass, dirt, grass, dirt
  },
  { 
    {{0, 0}, {blockSize * mapCellsWidth, blockSize * 1}}
  }
};