#include <food.hpp>
#include <cstdlib>
#include <ctime>
#include <cmath>

#define TIME_TO_RESPAWN 10

Food::Food(){
    // removes from screen, but not deleting
    position.x = position.y = -2;
    srand(time(NULL));
    size_x = 640;
    size_y = 480;
    time_to_respawn = 1;
}

void Food::set_random(){
    if(time_to_respawn > 0){
        time_to_respawn--;
        return;
    }


    int x = (floor(rand()%size_x/10)) * 10;
    int y = (floor(rand()%size_y/10)) * 10;

    position.x = x;
    position.y = y;
}

void Food::reset(){
    position.x = position.y = -1;
    time_to_respawn = TIME_TO_RESPAWN;
}

bool Food::is_eaten(){
    return(position.x < 0);
}

