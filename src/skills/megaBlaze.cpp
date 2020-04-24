#include "skills/megaBlaze.h"

megaBlaze::megaBlaze()
{
    name = "Mega Blaze";
    description = "A powerful fire spell that attacks all enemies.";
    energy_cost = 7;
}

megaBlaze::~megaBlaze()
{
    //dtor
}

void megaBlaze::use (Entity *user, std::vector <Entity*> targets) {
    Skill::use (user, targets);
    int damage = 25;
    if (user->faction == "player") {
        for (Entity* combatant : targets) {
            if (!(combatant->faction == "player") && combatant->is_alive ()) {
                user->damage_magic (combatant, damage, "fire");
                for (int i = 0; i < combatant->statuses.size (); i++) {
                    std::vector <Entity*> player; player.push_back (user);
                }
            }
        }
    } else {
        for (Entity* target : targets) {
            user->damage_magic (target, damage, "fire");
        }
    }
}
