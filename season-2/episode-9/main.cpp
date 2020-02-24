#include <iostream>

#include "ngon_random.h"

struct player
{
    int health;
    int max_health;

    int damage_min;
    int damage_max;

    int crit_chance;

    player(int aHealth, int aDamageMin, int aDamageMax, int aCritChance);
    int damage();
    bool is_critical_hit();
};

player::player(int aHealth, int aDamageMin, int aDamageMax, int aCritChance)
{
    health = aHealth;
    max_health = aHealth;
    damage_min = aDamageMin;
    damage_max = aDamageMax;
    crit_chance = aCritChance;
}

int player::damage()
{
    int damage_result = random_number(damage_min, damage_max);
    if (is_critical_hit())
    {
        return damage_result * 2;
    }

    return damage_result;
}

bool player::is_critical_hit()
{
    int crit_result = random_number(1, 100);
    return crit_result < crit_chance;
}

int main()
{
    player gabe(50, 6, 14, 55);
    player olafur(100, 5, 10, 5);

    int gabe_win = 0;
    int olafur_win = 0;

    for (int i = 0; i < 100000; ++i)
    {
        while (gabe.health > 0 && olafur.health > 0)
        {
            gabe.health -= olafur.damage();
            olafur.health -= gabe.damage();
        }

        if (gabe.health > 0)
        {
            gabe_win++;
        }
        if (olafur.health > 0)
        {
            olafur_win++;
        }

        gabe.health = gabe.max_health;
        olafur.health = olafur.max_health;
    }
}