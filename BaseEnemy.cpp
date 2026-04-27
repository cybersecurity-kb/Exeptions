#include "BaseEnemy.h"
#include "Weapon.h"
using namespace std;

// Конструктор
BaseEnemy::BaseEnemy(double pos_x, double pos_y, Weapon* w, int health)
    : BaseCharacter(pos_x, pos_y, health) {
    weapon = w;
}

// Деструктор
BaseEnemy::~BaseEnemy() {
    // weapon не удаляем, так как это может быть оружие из инвентаря
}

// Удар врага
void BaseEnemy::hit(BaseCharacter* target) {
    weapon->hit(this, target);
}

// Вывод врага
ostream& operator<<(ostream& os, const BaseEnemy& enemy) {
    os << "Враг на позиции (" << *(enemy.x) << ", " << *(enemy.y) 
       << ") с оружием " << *(enemy.weapon);
    return os;
}
