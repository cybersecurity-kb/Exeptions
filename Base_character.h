#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H

#include <iostream>
using namespace std;

class BaseCharacter {
protected:
    double* x;         
    double* y;         
    int* hp;            

public:
    // Конструктор
    BaseCharacter(double pos_x, double pos_y, int health);
    
    // Конструктор копирования
    BaseCharacter(const BaseCharacter& other);
    
    // Виртуальный деструктор 
    virtual ~BaseCharacter();
    
    // Перемещение
    void move(double delta_x, double delta_y);
    
    // Проверка жив ли
    bool is_alive() const;
    
    // Получить урон
    void get_damage(int amount);
    
    // Геттеры координат
    double get_x() const { return *x; }
    double get_y() const { return *y; }
    
    // Геттер здоровья
    int get_hp() const { return *hp; }
};

#endif
