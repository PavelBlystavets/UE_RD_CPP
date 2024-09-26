#include "Character.h"
#include "Sword.h"
#include "Bow.h"
#include "Axe.h"
#include <iostream>

int main() {
    Character character;

    character.AddWeapon(make_unique<Sword>());
    character.AddWeapon(make_unique<Bow>());
    character.AddWeapon(make_unique<Axe>());

    character.ShowInventory();

    character.EquipWeapon(1);  // Bow
    if (character.GetWeapon()) {
        std::cout << "Selected weapon: " << character.GetWeapon()->GetName()
            << ", Damage: " << character.GetWeapon()->GetDamage() << std::endl;
    }

    character.EquipWeapon(0);  // Sword
    if (character.GetWeapon()) {
        std::cout << "Selected weapon: " << character.GetWeapon()->GetName()
            << ", Damage: " << character.GetWeapon()->GetDamage() << std::endl;
    }

    return 0;
}