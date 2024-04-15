// maps and sprites
struct level
{
  const char *name;
  unsigned short mapWidthInBlocks; //in blocks
  unsigned short mapHeightInBlocks; //in blocks
  unsigned short blockWidth; //in pixels
  unsigned short blockHeight; //in pixels
  unsigned short *tiles[12*16]; // pointers to sprites 12x16
  bool collisions[256];       // map of collisions (false is no block)
};

const unsigned short blockSize = 16;
const char* title = "Level 0 - Demo";
const level level0 = {title, 12, 16, blockSize, blockSize,
                      {dirt, grass, dirt, grass, dirt, grass, dirt, grass, dirt, grass, dirt, grass,
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
                       grass, dirt, grass, dirt, grass, dirt, grass, dirt, grass, dirt, grass, dirt},
                      {true, true, true, true, true, true, true, true, true, true, true, true, true, true, true,
                       true, false, false, false, false, false, false, false, false, false, false, false, false, false, true,
                       true, false, false, false, false, false, false, false, false, false, false, false, false, false, true,
                       true, false, false, false, false, false, false, false, false, false, false, false, false, false, true,
                       true, false, false, false, false, false, false, false, false, false, false, false, false, false, true,
                       true, false, false, false, false, false, false, false, false, false, false, false, false, false, true,
                       true, false, false, false, false, false, false, false, false, false, false, false, false, false, true,
                       true, false, false, false, false, false, false, false, false, false, false, false, false, false, true,
                       true, false, false, false, false, false, false, false, false, false, false, false, false, false, true,
                       true, false, false, false, false, false, false, false, false, false, false, false, false, false, true,
                       true, false, false, false, false, false, false, false, false, false, false, false, false, false, true,
                       true, false, false, false, false, false, false, false, false, false, false, false, false, false, true,
                       true, false, false, false, false, false, false, false, false, false, false, false, false, false, true,
                       true, false, false, false, false, false, false, false, false, false, false, false, false, false, true,
                       true, true, true, true, true, true, true, true, true, true, true, true, true, true, true,
                       true, true, true, true, true, true, true, true, true, true, true, true, true, true, true}};