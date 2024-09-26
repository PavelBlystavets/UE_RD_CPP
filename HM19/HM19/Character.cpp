#include "Character.h"
#include <iostream>

Character::Character() : equippedWeapon(nullptr) {}

void Character::AddWeapon(unique_ptr<Weapon> weapon) 
{
    weapons.push_back(move(weapon));
}

void Character::EquipWeapon(int index) 
{
    if (index >= 0 && index < weapons.size()) 
    {
        equippedWeapon = weapons[index].get();
        std::cout << "Equipped: " << equippedWeapon->GetName() << std::endl;
    }
    else 
    {
        equippedWeapon = nullptr;
    }
}

Weapon* Character::GetWeapon() const 
{
    return equippedWeapon;
}

void Character::ShowInventory() const 
{
    for (int i = 0; i < weapons.size(); ++i) 
    {
        std::cout << i << ": " << weapons[i]->GetName() << std::endl;
    }
}