#ifndef tower_h
#define tower_h

struct tower
{
    char type;
    int x;
    int y;
    int (*shootFunc)(int, int);
};

int shoot(int x, int y);

#endif
