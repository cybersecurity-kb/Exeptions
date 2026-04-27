#ifndef BASE_ENEMY_H
#define BASE_ENEMY_H

#include "BaseCharacter.h"
#include "Weapon.h"

class BaseEnemy : public BaseCharacter {
private:
    Weapon* weapon;     

public:
    // Конструктор
    BaseEnemy(double pos_x, double pos_y, Weapon* w, int health);
    
    // Деструктор
    ~BaseEnemy();
    
    // Удар по цели
    void hit(BaseCharacter* target);
    
    // Вывод информации о враге
    friend ostream& operator<<(ostream& os, const BaseEnemy& enemy);
};

#endif
