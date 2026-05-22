#include<iostream>

class player
{
public:
    int x, y;
    int speed;

    void Move(int xa, int ya)
    {
        x += xa * speed;
        y += ya; * speed;
    }
};


int main(){
    Player player;
    player.x = 5;
    player.Move(1, -1);
    
    std::cin.get();
}