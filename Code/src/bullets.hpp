#ifndef __BULLET_HPP__
#define __BULLET_HPP__


#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "rsdl.hpp"
#include "map.hpp"

using namespace std;

struct GameConfig {
    int TANK_SIZE = 60;
    int TIME_UNIT = 1000;
    int GRID_SIZE = 80;
    int HALF_TANK_SIZE = 30;
    int QUARTER_TANK_SIZE = 15;
    int PICKUP_SIZE = 40;
    int BULLET_SIZE = 8;
    int HALF_BULLET_SIZE = 4;
    int BULLET_LIFETIME = 10000;
    int PICKUP_LIFETIME = 5000;
    int DOUBLEBARREL_LIFETIME = 5000;
    int SHOTGUN_LIFETIME = 1500;
    int SHIELD_LIFETIME = 6000;
    int ANGULAR_VELOCITY = 2;
    int TANK_VELOCITY = 3;
    int BULLET_VELOCITY = 4;
    int PICKUP_BULLET_VELOCITY = 6;
    int DELAY_PER_FRAME = 33;
    double PI = 3.14159265;
    double PIANGLE = 180.00;
    int RIGHTANGLE = 90;
    string NORMAL = "Normal";
    string SHIELD = "Shield";
    string DOUBLEBARREL = "DoubleBarrel";
    string SHOTGUN = "Shotgun";
    string LASER = "Laser";
    int TRUE = 0;
    int FALSE = 1;
    string SLASH = "/";
    string DASH = "-";
};

extern GameConfig config;

const string Assets_Dir = "Assets";
const string Generic_Tank = "Tank";
const string Generic_Pickup = "Pickup";
const string Tank_Shot = "TankShot";
const string Tank_Explosion = "TankExplosion";
const string Extension = ".png";
const string Wav = ".wav";

const vector<string> Tank_Types{ "Normal", "Shield", "DoubleBarrel", "Shotgun", "Laser" };

class Gift
{

public:

    Gift(Point _position, int t);
    Gift(string _type, int _count, int _time);

    Point position;

    int lifetime = config.PICKUP_LIFETIME;
    int shoot_count;
    bool tank_collision;

    string type;
    string filename;
};

class Bullet
{
public:

    Bullet(Point _position, int _v, double _rotation, int _lifetime);

    Point position;

    int lifetime;
    int v_x, v_y;

    bool has_shield;

};


class Bullets_Repository
{
public:

    Bullets_Repository(int tank_count, Map* _map, Window* _win);

    void add_to_bullets(int tank_id, Point _position, double _rotation);
    void add_to_pickup_bullets(Point _position, double _rotation, string gif);
    void provide_gifts();
    void move(Bullet* b);
    void draw();
    void draw_gifs();
    void draw_all_bullets();
    void check_gifs();
    void check_all_bullets();
    void check_bullet_wall_collision(Bullet* b);

    vector <Gift*> get_gifs();
    vector <Bullet*> get_pickup_bullets();
    vector <vector <Bullet*>> get_tank_bullets();

private:
    Map* map;
    Window* game_window;

    vector <Gift*> gifts;
    vector <Bullet*> pickup_bullets;
    vector <vector <Bullet*>> tank_bullets;
};

#endif
