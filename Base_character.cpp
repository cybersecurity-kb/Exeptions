#include "BaseCharacter.h"

// Конструктор
BaseCharacter::BaseCharacter(double pos_x, double pos_y, int health) {
    x = new double(pos_x);
    y = new double(pos_y);
    hp = new int(health);
}

// Конструктор копирования
BaseCharacter::BaseCharacter(const BaseCharacter& other) {
    x = new double(*(other.x));
    y = new double(*(other.y));
    hp = new int(*(other.hp));
}

// Деструктор
BaseCharacter::~BaseCharacter() {
    delete x;
    delete y;
    delete hp;
}

// Перемещение
void BaseCharacter::move(double delta_x, double delta_y) {
    *x += delta_x;
    *y += delta_y;
    cout << "Переместился на (" << delta_x << ", " << delta_y 
         << "). Новая позиция: (" << *x << ", " << *y << ")" << endl;
}

// Проверка жив ли
bool BaseCharacter::is_alive() const {
    return *hp > 0;
}

// Получение урона
void BaseCharacter::get_damage(int amount) {
    *hp -= amount;
    if (*hp < 0) *hp = 0;
    cout << "Получен урон " << amount << ". Осталось здоровья: " << *hp << endl;
}
