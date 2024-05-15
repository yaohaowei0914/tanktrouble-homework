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
    // ʹ�� bool ���������ƺ�ʱ���¿�ʼѭ����������ֱ���޸����� i
    bool restart = false;

    for (int i = 0; i < horizontal.size(); i++) {
        if (restart) {
            // �����Ҫ���¿�ʼѭ������ i ����Ϊ -1���Ա���һ��ѭ����ʼʱ i Ϊ 0
            i = -1;
            restart = false;
            continue;
        }

        for (int j = i + 1; j < horizontal.size(); j++) {
            if (horizontal[i].dest.x == horizontal[j].src.x &&
                horizontal[i].dest.y == horizontal[j].src.y) {
                // ���µ�ǰǽ���յ� x ����
                horizontal[i].dest.x = horizontal[j].dest.x;
                // �Ƴ� j ָ���ǽ����Ϊ���Ѿ����ϲ�
                horizontal.erase(horizontal.begin() + j);
                // ���� j Ϊ i����һ��ѭ���� i + 1 ��ʼ
                j = i;
                // �������¿�ʼѭ���ı�־
                restart = true;
                break; // �����ڲ�ѭ��
            }
        }
    }
}


void Map::vertic_walls_integration(vector<Wall>& vertical) {
    // ʹ�� bool ���������ƺ�ʱ���¿�ʼѭ����������ֱ���޸����� i
    bool restart = false;

    for (int i = 0; i < vertical.size(); i++) {
        if (restart) {
            // �����Ҫ���¿�ʼѭ������ i ����Ϊ -1���Ա���һ��ѭ����ʼʱ i Ϊ 0
            i = -1;
            restart = false;
            continue;
        }

        for (int j = i + 1; j < vertical.size(); j++) {
            if (vertical[i].dest.x == vertical[j].src.x &&
                vertical[i].dest.y == vertical[j].src.y) {
                // ���µ�ǰǽ���յ� y ����
                vertical[i].dest.y = vertical[j].dest.y;
                // �Ƴ� j ָ���ǽ����Ϊ���Ѿ����ϲ�
                vertical.erase(vertical.begin() + j);
                // ���� j Ϊ i����һ��ѭ���� i + 1 ��ʼ
                j = i;
                // �������¿�ʼѭ���ı�־
                restart = true;
                break; // �����ڲ�ѭ��
            }
        }
    }
}