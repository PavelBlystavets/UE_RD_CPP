#pragma once
#include "Weapon.h"

class Bow : public Weapon {
public:
    float GetDamage() override { return 30.0f; }
    string GetName() override { return "Bow"; }
};