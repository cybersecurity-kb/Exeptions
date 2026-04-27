#ifndef MAIN_HERO_H
#define MAIN_HERO_H

#include "BaseCharacter.h"
#include "Weapon.h"
#include <vector>

class MainHero : public BaseCharacter {
private:
    string* name;                       
    vector<Weapon*>* inventory;        
    Weapon* currentWeapon;              
    int currentIndex;                   

public:
    // Конструктор
    MainHero(double pos_x, double pos_y, string n, int health);
    
    // Деструктор
    ~MainHero();
    
    // Удар по врагу
    void hit(BaseEnemy* target);
    
    // Добавить оружие
    void add_weapon(Weapon* w);
    
    // Сменить оружие
    void next_weapon();
    
    // Лечение
    void heal(int amount);
    
    // Вывод информации о герое
    friend ostream& operator<<(ostream& os, const MainHero& hero);
};

#endif
