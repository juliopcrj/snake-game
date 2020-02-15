#ifndef __SNAKE__HPP__
#define __SNAKE__HPP__

#include <list>

struct point{
    int x, y;
};

class Snake{
    private:
        bool ate = false;
    public:
        struct point head;
        std::list<point> tail;
        int speed;
        int screen_x, screen_y;


        /*
         * @params:
         * direction: 0,1,2,4, as left up right down
         */
        void move(int);

        /*
         * increases snake by given fixed ammount
         */
        void eat();

        bool collide_with_self();
        bool collide_with_wall();
        bool collide_with_food(struct point);

        Snake(int, int, int);


};

#endif
