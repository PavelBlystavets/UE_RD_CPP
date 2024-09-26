#pragma once
#include "Weapon.h"

class Axe : public Weapon {
public:
    float GetDamage() override { return 60.0f; }
    string GetName() override { return "Axe"; }
};