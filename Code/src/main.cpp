#include "handler.hpp"

void prompt_for_config(GameConfig& config) {
    string input;

    cout << "Enter TANK_SIZE (" << config.TANK_SIZE << "): ";
    getline(cin, input);
    if (!input.empty()) config.TANK_SIZE = stoi(input);

    cout << "Enter GRID_SIZE (" << config.GRID_SIZE << "): ";
    getline(cin, input);
    if (!input.empty()) config.GRID_SIZE = stoi(input);

    cout << "Enter BULLET_LIFETIME (" << config.BULLET_LIFETIME << "): ";
    getline(cin, input);
    if (!input.empty()) config.BULLET_LIFETIME = stoi(input);

    cout << "Enter PICKUP_LIFETIME (" << config.PICKUP_LIFETIME << "): ";
    getline(cin, input);
    if (!input.empty()) config.PICKUP_LIFETIME = stoi(input);

    cout << "Enter DOUBLEBARREL_LIFETIME (" << config.DOUBLEBARREL_LIFETIME << "): ";
    getline(cin, input);
    if (!input.empty()) config.DOUBLEBARREL_LIFETIME = stoi(input);

    cout << "Enter SHOTGUN_LIFETIME (" << config.SHOTGUN_LIFETIME << "): ";
    getline(cin, input);
    if (!input.empty()) config.SHOTGUN_LIFETIME = stoi(input);

    cout << "Enter SHIELD_LIFETIME (" << config.SHIELD_LIFETIME << "): ";
    getline(cin, input);
    if (!input.empty()) config.SHIELD_LIFETIME = stoi(input);

    cout << "Enter ANGULAR_VELOCITY (" << config.ANGULAR_VELOCITY << "): ";
    getline(cin, input);
    if (!input.empty()) config.ANGULAR_VELOCITY = stoi(input);

    cout << "Enter TANK_VELOCITY (" << config.TANK_VELOCITY << "): ";
    getline(cin, input);
    if (!input.empty()) config.TANK_VELOCITY = stoi(input);

    cout << "Enter BULLET_VELOCITY (" << config.BULLET_VELOCITY << "): ";
    getline(cin, input);
    if (!input.empty()) config.BULLET_VELOCITY = stoi(input);

    cout << "Enter PICKUP_BULLET_VELOCITY (" << config.PICKUP_BULLET_VELOCITY << "): ";
    getline(cin, input);
    if (!input.empty()) config.PICKUP_BULLET_VELOCITY = stoi(input);

    cout << "Enter DELAY_PER_FRAME (" << config.DELAY_PER_FRAME << "): ";
    getline(cin, input);
    if (!input.empty()) config.DELAY_PER_FRAME = stoi(input);

    cout << "Configuration complete. Starting the game..." << endl;
}

int main(int argc, char* argv[])
{
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <map_file>" << endl;
        return 1;
    }

    string map_address = argv[1];

    prompt_for_config(config);  // 提示用户输入每个配置项

    Game game(map_address);
    return 0;
}