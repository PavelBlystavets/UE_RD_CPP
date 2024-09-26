#pragma once
#include <vector>
#include <memory>
#include "Weapon.h"

class Character {
private:
    std::vector<std::unique_ptr<Weapon>> weapons;
    Weapon* equippedWeapon;

public:
    Character();
    void AddWeapon(std::unique_ptr<Weapon> weapon);
    Weapon* GetWeapon() const;
    void ShowInventory() const;
    void EquipWeapon(int index);
};