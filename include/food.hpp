#ifndef __FOOD__HPP__
#define __FOOD__HPP__

#include <snake.hpp>

class Food{
    private:
        int size_x, size_y;
        int time_to_respawn;

    public:
        struct point position;
        Food();
        void set_random();
        void reset();
        bool is_eaten();
};

#endif
