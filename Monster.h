// Monster

#ifndef MONSTER_H
#define MONSTER_H

#include "Creature.h"
#include "Random.h"

class Monster : public Creature {
public:
    enum Type {
        dragon,
        orc,
        slime,
        max_types,
    };
    
private:
    inline static Creature monsterData[] {
        Creature { "dragon", 'D', 20, 4, 100 },
        Creature { "orc" , 'o', 4, 2, 25 },
        Creature { "slime", 's', 1, 1, 10 },
    };

    static_assert(std::size(monsterData) == max_types);

public:
    Monster(Type t)
    : Creature{ monsterData[t] }
    {}

    static Monster getRandomMonster() {
        int num { static_cast<Type>(Random::get(0, max_types-1)) };
        return Monster { static_cast<Type>(num) };
    }
};

#endif