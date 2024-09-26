#pragma once
#include <string>
using namespace std;

class Weapon {
public:
    virtual float GetDamage() = 0;
    virtual string GetName() = 0;
    virtual ~Weapon() = default;
};