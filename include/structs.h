#ifndef STRUCTS_H
#define STRUCTS_H
//#ifndef ARRAY_SIZE
//#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
//#endif
struct precisionPoint
{
    float x, y;
};
struct point
{
    int x, y;
};
struct rect
{
    point p1, p2;
};
#endif