#include <snake.hpp>
#include <food.hpp>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>


#define DEFAULT_GRID_SIZE 10
#define DEFAULT_DIM_X 640
#define DEFAULT_DIM_Y 480
#define DEFAULT_SPEED 10

int grid_size;
int dimension_x, dimension_y;
int speed;

void run();

int main(int argc, char **argv){
    grid_size = DEFAULT_GRID_SIZE;
    dimension_x = DEFAULT_DIM_X;
    dimension_y = DEFAULT_DIM_Y;
    speed = DEFAULT_SPEED;

    for(int i = 0; i< argc; ++i){
        if(std::string(argv[i]) == "-b" || std::string(argv[i]) == "--blocksize"){
            if(i + 1 < argc){
                grid_size = atoi(argv[i+1]);
            }
        }
        if(std::string(argv[i]) == "-g" || std::string(argv[i]) == "--gridsize"){
            if(i+2 < argc){
                dimension_x = atoi(argv[i+1]);
                dimension_y = atoi(argv[i+2]);
            }
        }
        if(std::string(argv[i]) == "-s" || std::string(argv[i]) == "--speed"){
            if(i+1 < argc){
                speed = atoi(argv[i+1]);
            }
        }

    }

    run();
    return 0;
}

void run(){

    int eaten = 0;
    sf::RenderWindow window(sf::VideoMode(dimension_x, dimension_y), "Snake");
    Snake s = Snake(grid_size, dimension_x, dimension_y);
    sf::RectangleShape snek(sf::Vector2f(grid_size, grid_size));
    snek.setFillColor(sf::Color::Green);
    window.setFramerateLimit(15);
    
    sf::RectangleShape froot(sf::Vector2f(grid_size, grid_size));
    froot.setFillColor(sf::Color::Red);

    Food fruit = Food();
    fruit.set_random();

    int movement;
    movement = -1;
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
            if(event.type == sf::Event::KeyPressed){
                int key = event.key.code;
                switch(key){
                    case sf::Keyboard::Left:
                        movement=0;
                        break;
                    case sf::Keyboard::Up:
                        movement=1;
                        break;
                    case sf::Keyboard::Right:
                        movement=2;
                        break;
                    case sf::Keyboard::Down:
                        movement=4;
                        break;
                    case sf::Keyboard::Q:
                        window.close();
                        break;
                    default:
                        break;
                }
            }
        }

        if(fruit.is_eaten()){
            fruit.set_random();
        }

        if(movement != -1)
        s.move(movement);

        if(s.collide_with_self() || s.collide_with_wall()){
            window.close();
        }

        if(s.collide_with_food(fruit.position)){
            s.eat();
            fruit.reset();
            eaten++;
        }
// Draws the snake.
        window.clear();
        
        froot.setPosition(fruit.position.x, fruit.position.y);
        if(!fruit.is_eaten())
        window.draw(froot);

        snek.setPosition(s.head.x, s.head.y);
        window.draw(snek);
        for(std::list<struct point>::iterator it = s.tail.begin(); it != s.tail.end(); ++it){
            snek.setPosition(it->x, it->y);
            window.draw(snek);
        }


        window.display();
    }

    std::cout << "Ate " << eaten << " fruits." << std::endl;
}
