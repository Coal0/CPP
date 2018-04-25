#include <iostream> // for `std::cout`
#include <string>   // for `std::string`

enum class MonsterType {
    OGRE,
    DRAGON,
    ORC,
    GIANT_SPIDER,
    SLIME
};

struct Monster {
    MonsterType type;
    std::string name;
    int health;
};

std::string getMonsterTypeStringFromMonster(Monster monster) {
    switch(monster.type) {
        case MonsterType::OGRE: return "Ogre";
        case MonsterType::DRAGON: return "Dragon";
        case MonsterType::ORC: return "Orc";
        case MonsterType::GIANT_SPIDER: return "Giant Spider";
        case MonsterType::SLIME: return "Slime";
        default: return "???";
    }
}

void printMonster(Monster monster) {
    std::string type_str = getMonsterTypeStringFromMonster(monster);
    std::string name = monster.name;
    int health = monster.health;
	std::cout << "This " << type_str << " is named " << name << " and has "
		<< health << " health.\n";
}

int main() {
    Monster torg = {MonsterType::OGRE, "Torg", 145};
    Monster blurp = {MonsterType::SLIME, "Blurp", 23};
    printMonster(torg);
    printMonster(blurp);
}
