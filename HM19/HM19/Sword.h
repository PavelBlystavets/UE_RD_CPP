#pragma once
#include "Weapon.h"

class Sword : public Weapon {
public:
    float GetDamage() override { return 50.0f; }
    string GetName() override { return "Sword"; }
};