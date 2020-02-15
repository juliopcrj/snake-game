#include <list>
#include <snake.hpp>
#include <cmath>

Snake::Snake(int grid_size, int dimension_x, int dimension_y){
    this->speed=grid_size;

    this->screen_x = dimension_x;
    this->screen_y = dimension_y;
    
    int posx = floor(dimension_x/2);
    int posy = floor(dimension_y/2);
    head.x = posx;
    head.y = posy;


    tail.clear();
    struct point pos;
    for(int i = 1; i<8; ++i){

    pos.x = head.x;
    pos.y = head.y + i*grid_size;
    tail.push_back(pos);
    }
}

void Snake::move(int direction){
    struct point curr = head;
    struct point aux;
    switch(direction){
        case 0:
            if(tail.front().x < head.x)
                head.x += speed; 
            else
                head.x -= speed;
            break;
        case 1:
            if(tail.front().y < head.y)
                head.y += speed; 
            else
                head.y -= speed;
            break;
        case 2:
            if(tail.front().x > head.x)
                head.x -= speed; 
            else
                head.x += speed;
            break;
        case 4:
            if(tail.front().y > head.y)
                head.y -= speed; 
            else
                head.y += speed;
            break;
        default:
            break;
    }
    // now on to move the rest;
    for(std::list<struct point>::iterator it = tail.begin();it != tail.end(); ++it){
        aux.x = it->x;
        aux.y = it->y;
        it->x = curr.x;
        it->y = curr.y;
        curr.x = aux.x;
        curr.y = aux.y; 
    }
    if(ate){
        struct point new_tail;
        new_tail.x = curr.x;
        new_tail.y = curr.y;
        tail.push_back(new_tail);
        ate = false;
    }
}

bool Snake::collide_with_self(){
    for(std::list<struct point>::iterator it = tail.begin();
            it != tail.end();
            ++it){
        if(head.x == it->x && head.y == it->y)
            return true;
    
    }
    return false;
}

bool Snake::collide_with_wall(){
    return(head.x < 0 ||
       head.y < 0 ||
       head.x > screen_x ||
       head.y > screen_y);
}

bool Snake::collide_with_food(struct point pos){
    return(head.x == pos.x && head.y == pos.y);
}

void Snake::eat(){
    ate = true;
}
