#include <iostream>

class Building {
private:
    int m_id;
    int m_maxAge;
    int m_initialCost;
    int m_currentAge;

    void Destroy() {
        std::cout << "Building with id: " << m_id << " was destroyed." << std::endl;
    }

public:
    Building(int id, int maxAge, int initialCost)
        : m_id(id), m_maxAge(maxAge), m_initialCost(initialCost), m_currentAge(0) {}

    int GetCost() {
        if (m_currentAge >= m_maxAge)
        {
            return 0;
        }
        return m_initialCost * (m_maxAge - m_currentAge) / m_maxAge;
    }

    void ToAge(int years) {
        m_currentAge += years;
        if (m_currentAge >= m_maxAge) {
            Destroy();
        }
    }
};

int main() {

    int id = 1;
    int maxAge = 100;
    int initialCost = 100000;

    Building Building1(id, maxAge, initialCost);

    int ageToSet = 50;
    int ageToDestroy = 60;

    std::cout << "Initial cost: " << Building1.GetCost() << "$" << std::endl;

    Building1.ToAge(ageToSet);
    std::cout << "Cost in " << ageToSet << " years: " << Building1.GetCost() << "$" << std::endl;

    Building1.ToAge(ageToDestroy);

    return 0;
}