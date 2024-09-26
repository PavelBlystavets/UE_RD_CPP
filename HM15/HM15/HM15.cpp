#include <iostream>
#include <vector>
#include <string>
//using namespace std;

struct Player {
    std::string name;
    int clan;
    int health;
    int damage;
};

void addPlayer(std::vector<Player>& clan0, std::vector<Player>& clan1)
{
    std::string name;
    int clan, health, damage;
    std::cout << "Enter player name, clan (0 or 1), health and damage:";
    std::cin >> name >> clan >> health >> damage;

    Player new_player = { name, clan, health, damage };
    if (clan == 0)
        clan0.push_back(new_player);
    else
        clan1.push_back(new_player);

    std::cout << "Player " << name << " added to clan " << clan << std::endl;
}

void removePlayer(std::vector<Player>& clan, const std::string& name)
{
    for (auto it = clan.begin(); it != clan.end(); ++it) 
    {
        if (it->name == name) 
        {
            clan.erase(it);
            std::cout << "Player " << name << " removed" << std::endl;
            return;
        }
    }
    std::cout << "Player " << name << " not found" << std::endl;
}

void battleSimulation(std::vector<Player>& clan0, std::vector<Player>& clan1)
{
    int turn = 0;

    while (!clan0.empty() && !clan1.empty()) 
    {
        Player& attacker = (turn % 2 == 0) ? clan0[0] : clan1[0];
        Player& defender = (turn % 2 == 0) ? clan1[0] : clan0[0];

        std::cout << attacker.name << " attacks " << defender.name << " and applies " << attacker.damage << " damage!" << std::endl;
        defender.health -= attacker.damage;
        std::cout << "Player " << defender.name << " has left " << defender.health << " health" << std::endl;

        if (defender.health <= 0) 
        {
            std::cout << defender.name << " died!" << std::endl;
            if (turn % 2 == 0)
                clan1.erase(clan1.begin());
            else
                clan0.erase(clan0.begin());
        }

        turn++;
    }

    if (clan0.empty()) {
        std::cout << "Clan 1 won!" << std::endl;
    }
    else if (clan1.empty()) {
        std::cout << "Clan 0 won!" << std::endl;
    }
}

int main() {
    std::vector<Player> clan0;
    std::vector<Player> clan1;
    int command;

    while (true) {
        std::cout << "Enter the command (0 - add a player, 1 - remove a player, 2 - start a battle):";
        std::cin >> command;

        if (command == 0) 
        {
            addPlayer(clan0, clan1);
        }
        else if (command == 1) 
        {
            std::string name;
            int clan;
            std::cout << "Enter player name and clan (0 or 1):";
            std::cin >> name >> clan;
            if (clan == 0) {
                removePlayer(clan0, name);
            }
            else 
            {
                removePlayer(clan1, name);
            }
        }
        else if (command == 2) 
        {
            battleSimulation(clan0, clan1);
            break;
        }
    }

    return 0;
}