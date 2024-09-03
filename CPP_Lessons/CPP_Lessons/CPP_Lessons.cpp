#include <iostream>

int main()
{
    float health = 0;

    std::cout << "Write character health: " << std::endl;
    std::cin >> health;

    while (health > 0)
    {

        int item_distance = 0;
        int item_impact = 0;
        float result_impact;

        std::cout << "Write item distance: " << std::endl;
        std::cin >> item_distance;

        std::cout << "Write item impact (if the number is greater than zero, it is a treatment; if less - it's a damage) : " << std::endl;
        std::cin >> item_impact;

        if (item_distance > 100)
        {
            result_impact = 0;
            std::cout << "The distance is too great" << std::endl;
        }
        else
        {
            result_impact = item_impact * (1 - item_distance / static_cast<float>(100));
        }

        health += result_impact;

        if (health > 100)
        {
            health = 100;
        }

        health = std::ceil(health);

        if (health < 0)
        {
            health = 0;
        }

        std::cout << "Character health: " << health << std::endl;

    }

    std::cout << "Character dead. Game over" << std::endl;


}


