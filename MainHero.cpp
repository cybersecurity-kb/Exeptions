#include "MainHero.h"
#include "BaseEnemy.h"
#include <iostream>
using namespace std;

// Конструктор
MainHero::MainHero(double pos_x, double pos_y, string n, int health)
    : BaseCharacter(pos_x, pos_y, health) {
    name = new string(n);
    inventory = new vector<Weapon*>();
    currentWeapon = nullptr;
    currentIndex = -1;
}

// Деструктор
MainHero::~MainHero() {
    delete name;
    for (Weapon* w : *inventory) {
        delete w;
    }
    delete inventory;
}

// Удар по врагу
void MainHero::hit(BaseEnemy* target) {
    if (currentWeapon == nullptr) {
        cout << "Я безоружен" << endl;
        return;
    }
    currentWeapon->hit(this, target);
}

// Добавить оружие
void MainHero::add_weapon(Weapon* w) {
    inventory->push_back(w);
    cout << "Подобрал " << *w << endl;
    
    // Если это единственное оружие - экипируем сразу
    if (inventory->size() == 1) {
        currentWeapon = w;
        currentIndex = 0;
        cout << "Оружие " << *w << " экипировано!" << endl;
    }
}

// Сменить оружие
void MainHero::next_weapon() {
    if (inventory->empty()) {
        cout << "Я безоружен" << endl;
        return;
    }
    
    if (inventory->size() == 1) {
        cout << "У меня только одно оружие" << endl;
        return;
    }
    
    // Переключаемся на следующее
    currentIndex = (currentIndex + 1) % inventory->size();
    currentWeapon = (*inventory)[currentIndex];
    cout << "Сменил оружие на " << *currentWeapon << endl;
}

// Лечение
void MainHero::heal(int amount) {
    const int MAX_HP = 200;
    *hp += amount;
    if (*hp > MAX_HP) {
        *hp = MAX_HP;
    }
    cout << "Полечился, теперь здоровья " << *hp << endl;
}

// Вывод героя
ostream& operator<<(ostream& os, const MainHero& hero) {
    os << "Герой " << *(hero.name) << " на позиции (" 
       << *(hero.x) << ", " << *(hero.y) 
       << ") с здоровьем " << *(hero.hp);
    return os;
}
