#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>
using namespace std;

// ИСКЛЮЧЕНИЯ 
class WeaponError : public exception {
public:
    const char* what() const noexcept override {
        return "Ошибка оружия!";
    }
};

class NoWeaponError : public WeaponError {
public:
    const char* what() const noexcept override {
        return "У вас нет оружия!";
    }
};

//  КЛАСС
class Weapon {
private:
    string* name;   // название оружия 
    int* damage;    // урон 
    double* range;  // радиус действия 

public:
    // Конструктор
    Weapon(string n, int d, double r);
    
    // Конструктор копирования
    Weapon(const Weapon& other);
    
    // Деструктор
    ~Weapon();
    
    // Геттеры
    string getName() const { return *name; }
    int getDamage() const { return *damage; }
    double getRange() const { return *range; }
    
    // Основной метод - удар
    void hit(class BaseCharacter* actor, class BaseCharacter* target);
    
    // Дружественные операторы
    friend ostream& operator<<(ostream& os, const Weapon& w);
    friend istream& operator>>(istream& is, Weapon& w);
};

#endif
