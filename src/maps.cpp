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
        lv.player = {64, 64};
        lv.bgImage = sprite_bgImage_cave;
        Serial.println("level init 1");

        // lv.cells_count = lv.mapCellsWidth * lv.mapCellsHeight;
        /*unsigned short* tmpCells[lv.cells_count] = {
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
            dirt, dirt, dirt, dirt, dirt, dirt, dirt, dirt, dirt, dirt, dirt, dirt};*/
#pragma region cells
        lv.cells_count = 249;
        lv.cells2 = new cell[lv.cells_count];
        lv.cells2[0] = {{0, 0}, dirt};
        lv.cells2[1] = {{16, 0}, dirt};
        lv.cells2[2] = {{32, 0}, dirt};
        lv.cells2[3] = {{48, 0}, dirt};
        lv.cells2[4] = {{64, 0}, dirt};
        lv.cells2[5] = {{80, 0}, dirt};
        lv.cells2[6] = {{96, 0}, dirt};
        lv.cells2[7] = {{112, 0}, dirt};
        lv.cells2[8] = {{128, 0}, dirt};
        lv.cells2[9] = {{144, 0}, dirt};
        lv.cells2[10] = {{160, 0}, dirt};
        lv.cells2[11] = {{176, 0}, dirt};
        lv.cells2[12] = {{192, 0}, dirt};
        lv.cells2[13] = {{208, 0}, dirt};
        lv.cells2[14] = {{224, 0}, dirt};
        lv.cells2[15] = {{240, 0}, dirt};
        lv.cells2[16] = {{256, 0}, dirt};
        lv.cells2[17] = {{272, 0}, dirt};
        lv.cells2[18] = {{288, 0}, dirt};
        lv.cells2[19] = {{304, 0}, dirt};
        lv.cells2[20] = {{320, 0}, dirt};
        lv.cells2[21] = {{336, 0}, dirt};
        lv.cells2[22] = {{352, 0}, dirt};
        lv.cells2[23] = {{368, 0}, dirt};
        lv.cells2[24] = {{384, 0}, dirt};
        lv.cells2[25] = {{400, 0}, dirt};
        lv.cells2[26] = {{416, 0}, dirt};
        lv.cells2[27] = {{432, 0}, dirt};
        lv.cells2[28] = {{448, 0}, dirt};
        lv.cells2[29] = {{464, 0}, dirt};
        lv.cells2[30] = {{480, 0}, dirt};
        lv.cells2[31] = {{496, 0}, dirt};
        lv.cells2[32] = {{512, 0}, dirt};
        lv.cells2[33] = {{528, 0}, dirt};
        lv.cells2[34] = {{544, 0}, dirt};
        lv.cells2[35] = {{560, 0}, dirt};
        lv.cells2[36] = {{576, 0}, dirt};
        lv.cells2[37] = {{592, 0}, dirt};
        lv.cells2[38] = {{608, 0}, dirt};
        lv.cells2[39] = {{624, 0}, dirt};
        lv.cells2[40] = {{0, 16}, dirt};
        lv.cells2[41] = {{16, 16}, dirt};
        lv.cells2[42] = {{32, 16}, dirt};
        lv.cells2[43] = {{48, 16}, dirt};
        lv.cells2[44] = {{64, 16}, dirt};
        lv.cells2[45] = {{80, 16}, dirt};
        lv.cells2[46] = {{176, 16}, dirt};
        lv.cells2[47] = {{192, 16}, dirt};
        lv.cells2[48] = {{208, 16}, dirt};
        lv.cells2[49] = {{224, 16}, dirt};
        lv.cells2[50] = {{240, 16}, dirt};
        lv.cells2[51] = {{256, 16}, dirt};
        lv.cells2[52] = {{304, 16}, dirt};
        lv.cells2[53] = {{320, 16}, dirt};
        lv.cells2[54] = {{336, 16}, dirt};
        lv.cells2[55] = {{352, 16}, dirt};
        lv.cells2[56] = {{368, 16}, dirt};
        lv.cells2[57] = {{448, 16}, dirt};
        lv.cells2[58] = {{464, 16}, dirt};
        lv.cells2[59] = {{480, 16}, dirt};
        lv.cells2[60] = {{496, 16}, dirt};
        lv.cells2[61] = {{512, 16}, dirt};
        lv.cells2[62] = {{592, 16}, dirt};
        lv.cells2[63] = {{608, 16}, dirt};
        lv.cells2[64] = {{624, 16}, dirt};
        lv.cells2[65] = {{0, 32}, dirt};
        lv.cells2[66] = {{16, 32}, dirt};
        lv.cells2[67] = {{32, 32}, dirt};
        lv.cells2[68] = {{192, 32}, dirt};
        lv.cells2[69] = {{208, 32}, dirt};
        lv.cells2[70] = {{224, 32}, dirt};
        lv.cells2[71] = {{240, 32}, dirt};
        lv.cells2[72] = {{336, 32}, dirt};
        lv.cells2[73] = {{352, 32}, dirt};
        lv.cells2[74] = {{480, 32}, dirt};
        lv.cells2[75] = {{496, 32}, dirt};
        lv.cells2[76] = {{592, 32}, dirt};
        lv.cells2[77] = {{608, 32}, dirt};
        lv.cells2[78] = {{624, 32}, dirt};
        lv.cells2[79] = {{0, 48}, dirt};
        lv.cells2[80] = {{16, 48}, dirt};
        lv.cells2[81] = {{208, 48}, dirt};
        lv.cells2[82] = {{224, 48}, dirt};
        lv.cells2[83] = {{480, 48}, dirt};
        lv.cells2[84] = {{496, 48}, dirt};
        lv.cells2[85] = {{624, 48}, dirt};
        lv.cells2[86] = {{0, 64}, dirt};
        lv.cells2[87] = {{624, 64}, dirt};
        lv.cells2[88] = {{0, 80}, dirt};
        lv.cells2[89] = {{624, 80}, dirt};
        lv.cells2[90] = {{0, 96}, dirt};
        lv.cells2[91] = {{352, 96}, dirt};
        lv.cells2[92] = {{368, 96}, dirt};
        lv.cells2[93] = {{416, 96}, dirt};
        lv.cells2[94] = {{432, 96}, dirt};
        lv.cells2[95] = {{448, 96}, dirt};
        lv.cells2[96] = {{464, 96}, dirt};
        lv.cells2[97] = {{480, 96}, dirt};
        lv.cells2[98] = {{496, 96}, dirt};
        lv.cells2[99] = {{512, 96}, dirt};
        lv.cells2[100] = {{528, 96}, dirt};
        lv.cells2[101] = {{544, 96}, dirt};
        lv.cells2[102] = {{560, 96}, dirt};
        lv.cells2[103] = {{576, 96}, dirt};
        lv.cells2[104] = {{592, 96}, dirt};
        lv.cells2[105] = {{608, 96}, dirt};
        lv.cells2[106] = {{624, 96}, dirt};
        lv.cells2[107] = {{0, 112}, dirt};
        lv.cells2[108] = {{16, 112}, dirt};
        lv.cells2[109] = {{32, 112}, dirt};
        lv.cells2[110] = {{48, 112}, dirt};
        lv.cells2[111] = {{64, 112}, dirt};
        lv.cells2[112] = {{80, 112}, dirt};
        lv.cells2[113] = {{96, 112}, dirt};
        lv.cells2[114] = {{112, 112}, dirt};
        lv.cells2[115] = {{128, 112}, dirt};
        lv.cells2[116] = {{144, 112}, dirt};
        lv.cells2[117] = {{160, 112}, dirt};
        lv.cells2[118] = {{176, 112}, dirt};
        lv.cells2[119] = {{224, 112}, dirt};
        lv.cells2[120] = {{240, 112}, dirt};
        lv.cells2[121] = {{256, 112}, dirt};
        lv.cells2[122] = {{272, 112}, dirt};
        lv.cells2[123] = {{288, 112}, dirt};
        lv.cells2[124] = {{352, 112}, dirt};
        lv.cells2[125] = {{560, 112}, dirt};
        lv.cells2[126] = {{576, 112}, dirt};
        lv.cells2[127] = {{592, 112}, dirt};
        lv.cells2[128] = {{608, 112}, dirt};
        lv.cells2[129] = {{624, 112}, dirt};
        lv.cells2[130] = {{0, 128}, dirt};
        lv.cells2[131] = {{16, 128}, dirt};
        lv.cells2[132] = {{32, 128}, dirt};
        lv.cells2[133] = {{48, 128}, dirt};
        lv.cells2[134] = {{64, 128}, dirt};
        lv.cells2[135] = {{80, 128}, dirt};
        lv.cells2[136] = {{96, 128}, dirt};
        lv.cells2[137] = {{288, 128}, dirt};
        lv.cells2[138] = {{352, 128}, dirt};
        lv.cells2[139] = {{608, 128}, dirt};
        lv.cells2[140] = {{624, 128}, dirt};
        lv.cells2[141] = {{0, 144}, dirt};
        lv.cells2[142] = {{16, 144}, dirt};
        lv.cells2[143] = {{288, 144}, dirt};
        lv.cells2[144] = {{304, 144}, dirt};
        lv.cells2[145] = {{608, 144}, dirt};
        lv.cells2[146] = {{624, 144}, dirt};
        lv.cells2[147] = {{0, 160}, dirt};
        lv.cells2[148] = {{16, 160}, dirt};
        lv.cells2[149] = {{288, 160}, dirt};
        lv.cells2[150] = {{304, 160}, dirt};
        lv.cells2[151] = {{624, 160}, dirt};
        lv.cells2[152] = {{0, 176}, dirt};
        lv.cells2[153] = {{144, 176}, dirt};
        lv.cells2[154] = {{288, 176}, dirt};
        lv.cells2[155] = {{304, 176}, dirt};
        lv.cells2[156] = {{352, 176}, dirt};
        lv.cells2[157] = {{464, 176}, dirt};
        lv.cells2[158] = {{624, 176}, dirt};
        lv.cells2[159] = {{0, 192}, dirt};
        lv.cells2[160] = {{144, 192}, dirt};
        lv.cells2[161] = {{288, 192}, dirt};
        lv.cells2[162] = {{304, 192}, dirt};
        lv.cells2[163] = {{352, 192}, dirt};
        lv.cells2[164] = {{464, 192}, dirt};
        lv.cells2[165] = {{544, 192}, dirt};
        lv.cells2[166] = {{624, 192}, dirt};
        lv.cells2[167] = {{0, 208}, dirt};
        lv.cells2[168] = {{144, 208}, dirt};
        lv.cells2[169] = {{160, 208}, dirt};
        lv.cells2[170] = {{208, 208}, dirt};
        lv.cells2[171] = {{272, 208}, dirt};
        lv.cells2[172] = {{288, 208}, dirt};
        lv.cells2[173] = {{304, 208}, dirt};
        lv.cells2[174] = {{352, 208}, dirt};
        lv.cells2[175] = {{368, 208}, dirt};
        lv.cells2[176] = {{432, 208}, dirt};
        lv.cells2[177] = {{448, 208}, dirt};
        lv.cells2[178] = {{464, 208}, dirt};
        lv.cells2[179] = {{544, 208}, dirt};
        lv.cells2[180] = {{608, 208}, dirt};
        lv.cells2[181] = {{624, 208}, dirt};
        lv.cells2[182] = {{0, 224}, dirt};
        lv.cells2[183] = {{16, 224}, dirt};
        lv.cells2[184] = {{32, 224}, dirt};
        lv.cells2[185] = {{48, 224}, dirt};
        lv.cells2[186] = {{64, 224}, dirt};
        lv.cells2[187] = {{80, 224}, dirt};
        lv.cells2[188] = {{144, 224}, dirt};
        lv.cells2[189] = {{160, 224}, dirt};
        lv.cells2[190] = {{176, 224}, dirt};
        lv.cells2[191] = {{192, 224}, dirt};
        lv.cells2[192] = {{208, 224}, dirt};
        lv.cells2[193] = {{256, 224}, dirt};
        lv.cells2[194] = {{272, 224}, dirt};
        lv.cells2[195] = {{288, 224}, dirt};
        lv.cells2[196] = {{304, 224}, dirt};
        lv.cells2[197] = {{352, 224}, dirt};
        lv.cells2[198] = {{368, 224}, dirt};
        lv.cells2[199] = {{416, 224}, dirt};
        lv.cells2[200] = {{432, 224}, dirt};
        lv.cells2[201] = {{448, 224}, dirt};
        lv.cells2[202] = {{464, 224}, dirt};
        lv.cells2[203] = {{480, 224}, dirt};
        lv.cells2[204] = {{528, 224}, dirt};
        lv.cells2[205] = {{544, 224}, dirt};
        lv.cells2[206] = {{560, 224}, dirt};
        lv.cells2[207] = {{576, 224}, dirt};
        lv.cells2[208] = {{592, 224}, dirt};
        lv.cells2[209] = {{608, 224}, dirt};
        lv.cells2[210] = {{624, 224}, dirt};
        lv.cells2[211] = {{0, 240}, dirt};
        lv.cells2[212] = {{16, 240}, dirt};
        lv.cells2[213] = {{32, 240}, dirt};
        lv.cells2[214] = {{48, 240}, dirt};
        lv.cells2[215] = {{64, 240}, dirt};
        lv.cells2[216] = {{80, 240}, dirt};
        lv.cells2[217] = {{96, 240}, dirt};
        lv.cells2[218] = {{112, 240}, dirt};
        lv.cells2[219] = {{128, 240}, dirt};
        lv.cells2[220] = {{144, 240}, dirt};
        lv.cells2[221] = {{160, 240}, dirt};
        lv.cells2[222] = {{176, 240}, dirt};
        lv.cells2[223] = {{192, 240}, dirt};
        lv.cells2[224] = {{208, 240}, dirt};
        lv.cells2[225] = {{224, 240}, dirt};
        lv.cells2[226] = {{240, 240}, dirt};
        lv.cells2[227] = {{256, 240}, dirt};
        lv.cells2[228] = {{272, 240}, dirt};
        lv.cells2[229] = {{288, 240}, dirt};
        lv.cells2[230] = {{304, 240}, dirt};
        lv.cells2[231] = {{352, 240}, dirt};
        lv.cells2[232] = {{368, 240}, dirt};
        lv.cells2[233] = {{384, 240}, dirt};
        lv.cells2[234] = {{400, 240}, dirt};
        lv.cells2[235] = {{416, 240}, dirt};
        lv.cells2[236] = {{432, 240}, dirt};
        lv.cells2[237] = {{448, 240}, dirt};
        lv.cells2[238] = {{464, 240}, dirt};
        lv.cells2[239] = {{480, 240}, dirt};
        lv.cells2[240] = {{496, 240}, dirt};
        lv.cells2[241] = {{512, 240}, dirt};
        lv.cells2[242] = {{528, 240}, dirt};
        lv.cells2[243] = {{544, 240}, dirt};
        lv.cells2[244] = {{560, 240}, dirt};
        lv.cells2[245] = {{576, 240}, dirt};
        lv.cells2[246] = {{592, 240}, dirt};
        lv.cells2[247] = {{608, 240}, dirt};
        lv.cells2[248] = {{624, 240}, dirt};
#pragma endregion

#pragma region collisions
        lv.collisions_count = 237;
        lv.collisions = new rect[lv.collisions_count];
        lv.collisions[0] = {{0, 0}, {16, 16}};
        lv.collisions[1] = {{16, 0}, {32, 16}};
        lv.collisions[2] = {{32, 0}, {48, 16}};
        lv.collisions[3] = {{48, 0}, {64, 16}};
        lv.collisions[4] = {{64, 0}, {80, 16}};
        lv.collisions[5] = {{80, 0}, {96, 16}};
        lv.collisions[6] = {{96, 0}, {112, 16}};
        lv.collisions[7] = {{112, 0}, {128, 16}};
        lv.collisions[8] = {{128, 0}, {144, 16}};
        lv.collisions[9] = {{144, 0}, {160, 16}};
        lv.collisions[10] = {{160, 0}, {176, 16}};
        lv.collisions[11] = {{176, 0}, {192, 16}};
        lv.collisions[12] = {{192, 0}, {208, 16}};
        lv.collisions[13] = {{208, 0}, {224, 16}};
        lv.collisions[14] = {{224, 0}, {240, 16}};
        lv.collisions[15] = {{240, 0}, {256, 16}};
        lv.collisions[16] = {{256, 0}, {272, 16}};
        lv.collisions[17] = {{272, 0}, {288, 16}};
        lv.collisions[18] = {{288, 0}, {304, 16}};
        lv.collisions[19] = {{304, 0}, {320, 16}};
        lv.collisions[20] = {{320, 0}, {336, 16}};
        lv.collisions[21] = {{336, 0}, {352, 16}};
        lv.collisions[22] = {{352, 0}, {368, 16}};
        lv.collisions[23] = {{368, 0}, {384, 16}};
        lv.collisions[24] = {{384, 0}, {400, 16}};
        lv.collisions[25] = {{400, 0}, {416, 16}};
        lv.collisions[26] = {{416, 0}, {432, 16}};
        lv.collisions[27] = {{432, 0}, {448, 16}};
        lv.collisions[28] = {{448, 0}, {464, 16}};
        lv.collisions[29] = {{464, 0}, {480, 16}};
        lv.collisions[30] = {{480, 0}, {496, 16}};
        lv.collisions[31] = {{496, 0}, {512, 16}};
        lv.collisions[32] = {{512, 0}, {528, 16}};
        lv.collisions[33] = {{528, 0}, {544, 16}};
        lv.collisions[34] = {{544, 0}, {560, 16}};
        lv.collisions[35] = {{560, 0}, {576, 16}};
        lv.collisions[36] = {{576, 0}, {592, 16}};
        lv.collisions[37] = {{592, 0}, {608, 16}};
        lv.collisions[38] = {{608, 0}, {624, 16}};
        lv.collisions[39] = {{624, 0}, {640, 16}};
        lv.collisions[40] = {{0, 16}, {16, 32}};
        lv.collisions[41] = {{16, 16}, {32, 32}};
        lv.collisions[42] = {{32, 16}, {48, 32}};
        lv.collisions[43] = {{48, 16}, {64, 32}};
        lv.collisions[44] = {{64, 16}, {80, 32}};
        lv.collisions[45] = {{80, 16}, {96, 32}};
        lv.collisions[46] = {{176, 16}, {192, 32}};
        lv.collisions[47] = {{192, 16}, {208, 32}};
        lv.collisions[48] = {{208, 16}, {224, 32}};
        lv.collisions[49] = {{224, 16}, {240, 32}};
        lv.collisions[50] = {{240, 16}, {256, 32}};
        lv.collisions[51] = {{256, 16}, {272, 32}};
        lv.collisions[52] = {{304, 16}, {320, 32}};
        lv.collisions[53] = {{320, 16}, {336, 32}};
        lv.collisions[54] = {{336, 16}, {352, 32}};
        lv.collisions[55] = {{352, 16}, {368, 32}};
        lv.collisions[56] = {{368, 16}, {384, 32}};
        lv.collisions[57] = {{448, 16}, {464, 32}};
        lv.collisions[58] = {{464, 16}, {480, 32}};
        lv.collisions[59] = {{480, 16}, {496, 32}};
        lv.collisions[60] = {{496, 16}, {512, 32}};
        lv.collisions[61] = {{512, 16}, {528, 32}};
        lv.collisions[62] = {{592, 16}, {608, 32}};
        lv.collisions[63] = {{608, 16}, {624, 32}};
        lv.collisions[64] = {{624, 16}, {640, 32}};
        lv.collisions[65] = {{0, 32}, {16, 48}};
        lv.collisions[66] = {{16, 32}, {32, 48}};
        lv.collisions[67] = {{32, 32}, {48, 48}};
        lv.collisions[68] = {{192, 32}, {208, 48}};
        lv.collisions[69] = {{208, 32}, {224, 48}};
        lv.collisions[70] = {{224, 32}, {240, 48}};
        lv.collisions[71] = {{240, 32}, {256, 48}};
        lv.collisions[72] = {{336, 32}, {352, 48}};
        lv.collisions[73] = {{352, 32}, {368, 48}};
        lv.collisions[74] = {{480, 32}, {496, 48}};
        lv.collisions[75] = {{496, 32}, {512, 48}};
        lv.collisions[76] = {{592, 32}, {608, 48}};
        lv.collisions[77] = {{608, 32}, {624, 48}};
        lv.collisions[78] = {{624, 32}, {640, 48}};
        lv.collisions[79] = {{0, 48}, {16, 64}};
        lv.collisions[80] = {{16, 48}, {32, 64}};
        lv.collisions[81] = {{208, 48}, {224, 64}};
        lv.collisions[82] = {{224, 48}, {240, 64}};
        lv.collisions[83] = {{480, 48}, {496, 64}};
        lv.collisions[84] = {{496, 48}, {512, 64}};
        lv.collisions[85] = {{624, 48}, {640, 64}};
        lv.collisions[86] = {{0, 64}, {16, 80}};
        lv.collisions[87] = {{624, 64}, {640, 80}};
        lv.collisions[88] = {{0, 80}, {16, 96}};
        lv.collisions[89] = {{624, 80}, {640, 96}};
        lv.collisions[90] = {{0, 96}, {16, 112}};
        lv.collisions[91] = {{352, 96}, {368, 112}};
        lv.collisions[92] = {{368, 96}, {384, 112}};
        lv.collisions[93] = {{416, 96}, {432, 112}};
        lv.collisions[94] = {{432, 96}, {448, 112}};
        lv.collisions[95] = {{448, 96}, {464, 112}};
        lv.collisions[96] = {{464, 96}, {480, 112}};
        lv.collisions[97] = {{480, 96}, {496, 112}};
        lv.collisions[98] = {{496, 96}, {512, 112}};
        lv.collisions[99] = {{512, 96}, {528, 112}};
        lv.collisions[100] = {{528, 96}, {544, 112}};
        lv.collisions[101] = {{544, 96}, {560, 112}};
        lv.collisions[102] = {{560, 96}, {576, 112}};
        lv.collisions[103] = {{576, 96}, {592, 112}};
        lv.collisions[104] = {{592, 96}, {608, 112}};
        lv.collisions[105] = {{608, 96}, {624, 112}};
        lv.collisions[106] = {{624, 96}, {640, 112}};
        lv.collisions[107] = {{0, 112}, {16, 128}};
        lv.collisions[108] = {{16, 112}, {32, 128}};
        lv.collisions[109] = {{32, 112}, {48, 128}};
        lv.collisions[110] = {{48, 112}, {64, 128}};
        lv.collisions[111] = {{64, 112}, {80, 128}};
        lv.collisions[112] = {{80, 112}, {96, 128}};
        lv.collisions[113] = {{96, 112}, {112, 128}};
        lv.collisions[114] = {{112, 112}, {128, 128}};
        lv.collisions[115] = {{128, 112}, {144, 128}};
        lv.collisions[116] = {{144, 112}, {160, 128}};
        lv.collisions[117] = {{160, 112}, {176, 128}};
        lv.collisions[118] = {{176, 112}, {192, 128}};
        lv.collisions[119] = {{224, 112}, {240, 128}};
        lv.collisions[120] = {{240, 112}, {256, 128}};
        lv.collisions[121] = {{256, 112}, {272, 128}};
        lv.collisions[122] = {{272, 112}, {288, 128}};
        lv.collisions[123] = {{288, 112}, {304, 128}};
        lv.collisions[124] = {{352, 112}, {368, 128}};
        lv.collisions[125] = {{560, 112}, {576, 128}};
        lv.collisions[126] = {{576, 112}, {592, 128}};
        lv.collisions[127] = {{592, 112}, {608, 128}};
        lv.collisions[128] = {{608, 112}, {624, 128}};
        lv.collisions[129] = {{624, 112}, {640, 128}};
        lv.collisions[130] = {{0, 128}, {16, 144}};
        lv.collisions[131] = {{16, 128}, {32, 144}};
        lv.collisions[132] = {{32, 128}, {48, 144}};
        lv.collisions[133] = {{48, 128}, {64, 144}};
        lv.collisions[134] = {{64, 128}, {80, 144}};
        lv.collisions[135] = {{80, 128}, {96, 144}};
        lv.collisions[136] = {{96, 128}, {112, 144}};
        lv.collisions[137] = {{288, 128}, {304, 144}};
        lv.collisions[138] = {{352, 128}, {368, 144}};
        lv.collisions[139] = {{608, 128}, {624, 144}};
        lv.collisions[140] = {{624, 128}, {640, 144}};
        lv.collisions[141] = {{0, 144}, {16, 160}};
        lv.collisions[142] = {{16, 144}, {32, 160}};
        lv.collisions[143] = {{288, 144}, {304, 160}};
        lv.collisions[144] = {{304, 144}, {320, 160}};
        lv.collisions[145] = {{608, 144}, {624, 160}};
        lv.collisions[146] = {{624, 144}, {640, 160}};
        lv.collisions[147] = {{0, 160}, {16, 176}};
        lv.collisions[148] = {{16, 160}, {32, 176}};
        lv.collisions[149] = {{288, 160}, {304, 176}};
        lv.collisions[150] = {{304, 160}, {320, 176}};
        lv.collisions[151] = {{624, 160}, {640, 176}};
        lv.collisions[152] = {{0, 176}, {16, 192}};
        lv.collisions[153] = {{144, 176}, {160, 192}};
        lv.collisions[154] = {{288, 176}, {304, 192}};
        lv.collisions[155] = {{304, 176}, {320, 192}};
        lv.collisions[156] = {{352, 176}, {368, 192}};
        lv.collisions[157] = {{464, 176}, {480, 192}};
        lv.collisions[158] = {{624, 176}, {640, 192}};
        lv.collisions[159] = {{0, 192}, {16, 208}};
        lv.collisions[160] = {{144, 192}, {160, 208}};
        lv.collisions[161] = {{288, 192}, {304, 208}};
        lv.collisions[162] = {{304, 192}, {320, 208}};
        lv.collisions[163] = {{352, 192}, {368, 208}};
        lv.collisions[164] = {{464, 192}, {480, 208}};
        lv.collisions[165] = {{544, 192}, {560, 208}};
        lv.collisions[166] = {{624, 192}, {640, 208}};
        lv.collisions[167] = {{0, 208}, {16, 224}};
        lv.collisions[168] = {{144, 208}, {160, 224}};
        lv.collisions[169] = {{160, 208}, {176, 224}};
        lv.collisions[170] = {{208, 208}, {224, 224}};
        lv.collisions[171] = {{272, 208}, {288, 224}};
        lv.collisions[172] = {{288, 208}, {304, 224}};
        lv.collisions[173] = {{304, 208}, {320, 224}};
        lv.collisions[174] = {{352, 208}, {368, 224}};
        lv.collisions[175] = {{368, 208}, {384, 224}};
        lv.collisions[176] = {{432, 208}, {448, 224}};
        lv.collisions[177] = {{448, 208}, {464, 224}};
        lv.collisions[178] = {{464, 208}, {480, 224}};
        lv.collisions[179] = {{544, 208}, {560, 224}};
        lv.collisions[180] = {{608, 208}, {624, 224}};
        lv.collisions[181] = {{624, 208}, {640, 224}};
        lv.collisions[182] = {{0, 224}, {16, 240}};
        lv.collisions[183] = {{64, 224}, {80, 240}};
        lv.collisions[184] = {{80, 224}, {96, 240}};
        lv.collisions[185] = {{144, 224}, {160, 240}};
        lv.collisions[186] = {{160, 224}, {176, 240}};
        lv.collisions[187] = {{176, 224}, {192, 240}};
        lv.collisions[188] = {{192, 224}, {208, 240}};
        lv.collisions[189] = {{208, 224}, {224, 240}};
        lv.collisions[190] = {{256, 224}, {272, 240}};
        lv.collisions[191] = {{272, 224}, {288, 240}};
        lv.collisions[192] = {{288, 224}, {304, 240}};
        lv.collisions[193] = {{304, 224}, {320, 240}};
        lv.collisions[194] = {{352, 224}, {368, 240}};
        lv.collisions[195] = {{368, 224}, {384, 240}};
        lv.collisions[196] = {{416, 224}, {432, 240}};
        lv.collisions[197] = {{432, 224}, {448, 240}};
        lv.collisions[198] = {{448, 224}, {464, 240}};
        lv.collisions[199] = {{464, 224}, {480, 240}};
        lv.collisions[200] = {{480, 224}, {496, 240}};
        lv.collisions[201] = {{528, 224}, {544, 240}};
        lv.collisions[202] = {{544, 224}, {560, 240}};
        lv.collisions[203] = {{560, 224}, {576, 240}};
        lv.collisions[204] = {{576, 224}, {592, 240}};
        lv.collisions[205] = {{592, 224}, {608, 240}};
        lv.collisions[206] = {{608, 224}, {624, 240}};
        lv.collisions[207] = {{624, 224}, {640, 240}};
        lv.collisions[208] = {{0, 240}, {16, 256}};
        lv.collisions[209] = {{16, 240}, {32, 256}};
        lv.collisions[210] = {{32, 240}, {48, 256}};
        lv.collisions[211] = {{48, 240}, {64, 256}};
        lv.collisions[212] = {{64, 240}, {80, 256}};
        lv.collisions[213] = {{80, 240}, {96, 256}};
        lv.collisions[214] = {{144, 240}, {160, 256}};
        lv.collisions[215] = {{160, 240}, {176, 256}};
        lv.collisions[216] = {{176, 240}, {192, 256}};
        lv.collisions[217] = {{192, 240}, {208, 256}};
        lv.collisions[218] = {{208, 240}, {224, 256}};
        lv.collisions[219] = {{256, 240}, {272, 256}};
        lv.collisions[220] = {{272, 240}, {288, 256}};
        lv.collisions[221] = {{288, 240}, {304, 256}};
        lv.collisions[222] = {{304, 240}, {320, 256}};
        lv.collisions[223] = {{352, 240}, {368, 256}};
        lv.collisions[224] = {{368, 240}, {384, 256}};
        lv.collisions[225] = {{416, 240}, {432, 256}};
        lv.collisions[226] = {{432, 240}, {448, 256}};
        lv.collisions[227] = {{448, 240}, {464, 256}};
        lv.collisions[228] = {{464, 240}, {480, 256}};
        lv.collisions[229] = {{480, 240}, {496, 256}};
        lv.collisions[230] = {{528, 240}, {544, 256}};
        lv.collisions[231] = {{544, 240}, {560, 256}};
        lv.collisions[232] = {{560, 240}, {576, 256}};
        lv.collisions[233] = {{576, 240}, {592, 256}};
        lv.collisions[234] = {{592, 240}, {608, 256}};
        lv.collisions[235] = {{608, 240}, {624, 256}};
        lv.collisions[236] = {{624, 240}, {640, 256}};
#pragma endregion

        // lv.collisions_count = 4;
        /*rect tmpCollisions[lv.collisions_count] = {
            {{0, 0}, {lv.cellWidth * 1, lv.cellWidth * lv.mapCellsHeight}},                                                       // left
            {{0, 0}, {lv.cellWidth * 5, lv.cellHeight * 1}},                                                                      // top
            {{0, lv.cellHeight * (lv.mapCellsHeight - 1)}, {lv.cellWidth * lv.mapCellsWidth, lv.cellHeight * lv.mapCellsHeight}}, // bottom
            {{lv.cellWidth * (lv.mapCellsWidth - 1), 0}, {lv.cellWidth * lv.mapCellsWidth, lv.cellHeight * lv.mapCellsHeight}}    // right
        };*/

        lv.npcs_count = 3;
        precisionPoint tmpNpcs[lv.npcs_count] = {
            {96, 128},
            {32, 128},
            {72, 128}};

        Serial.println("level init 2");

        // lv.cells = new unsigned short*[lv.cells_count];
        // memcpy(lv.cells, tmpCells, lv.cells_count * sizeof(unsigned short *));

        // lv.collisions = new rect[lv.collisions_count];
        // memcpy(lv.collisions, tmpCollisions, lv.collisions_count * sizeof(rect));

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
