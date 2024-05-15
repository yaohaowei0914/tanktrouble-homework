#include "map.hpp"
#include <vector>
using namespace std;

Map::Map() 
{

}

Map::Map(Window* win)
{
    game_window = win;
}

vector <Wall> Map::get_walls() const
{
    return walls;
}

Point Map::get_dimensions()
{
    Point p(width, height);
    return p;
}

void Map::set_window(Window* win)
{
    game_window = win;
}

void Map::set_dimensions(int w, int h) 
{
    width = w;
    height = h;
}

void Map::add_to_walls(Wall w)
{
    walls.push_back(w);
}

void Map::walls_integration() 
{
    vector <Wall> horizontal, vertical;

    for(int i = 0; i < walls.size(); i++) 
    {
        Wall w = walls[i];

        if(w.src.x == w.dest.x)
            vertical.push_back(w);
        
        else if(w.src.y == w.dest.y)
            horizontal.push_back(w);
    }

    walls.clear();
    vertic_walls_integration(vertical);
    horizon_walls_integration(horizontal);

    for(int i = 0; i < max(horizontal.size(), vertical.size()); i++) 
    {
        if(i < vertical.size()) walls.push_back(vertical[i]);
        if(i < horizontal.size()) walls.push_back(horizontal[i]);
    }
}

void Map::draw()
{
    for(int i = 0; i < walls.size(); i++) {
        game_window->draw_line(walls[i].src, walls[i].dest, WHITE);
    }
}

void Map::horizon_walls_integration(vector<Wall>& horizontal) {
    // 使用 bool 变量来控制何时重新开始循环，而不是直接修改索引 i
    bool restart = false;

    for (int i = 0; i < horizontal.size(); i++) {
        if (restart) {
            // 如果需要重新开始循环，将 i 重置为 -1，以便下一次循环开始时 i 为 0
            i = -1;
            restart = false;
            continue;
        }

        for (int j = i + 1; j < horizontal.size(); j++) {
            if (horizontal[i].dest.x == horizontal[j].src.x &&
                horizontal[i].dest.y == horizontal[j].src.y) {
                // 更新当前墙的终点 x 坐标
                horizontal[i].dest.x = horizontal[j].dest.x;
                // 移除 j 指向的墙，因为它已经被合并
                horizontal.erase(horizontal.begin() + j);
                // 重置 j 为 i，下一次循环从 i + 1 开始
                j = i;
                // 设置重新开始循环的标志
                restart = true;
                break; // 跳出内层循环
            }
        }
    }
}


void Map::vertic_walls_integration(vector<Wall>& vertical) {
    // 使用 bool 变量来控制何时重新开始循环，而不是直接修改索引 i
    bool restart = false;

    for (int i = 0; i < vertical.size(); i++) {
        if (restart) {
            // 如果需要重新开始循环，将 i 重置为 -1，以便下一次循环开始时 i 为 0
            i = -1;
            restart = false;
            continue;
        }

        for (int j = i + 1; j < vertical.size(); j++) {
            if (vertical[i].dest.x == vertical[j].src.x &&
                vertical[i].dest.y == vertical[j].src.y) {
                // 更新当前墙的终点 y 坐标
                vertical[i].dest.y = vertical[j].dest.y;
                // 移除 j 指向的墙，因为它已经被合并
                vertical.erase(vertical.begin() + j);
                // 重置 j 为 i，下一次循环从 i + 1 开始
                j = i;
                // 设置重新开始循环的标志
                restart = true;
                break; // 跳出内层循环
            }
        }
    }
}