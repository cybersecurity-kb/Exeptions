#include "Weapon.h"
#include "BaseCharacter.h"  
#include <cmath>
using namespace std;

// Конструктор
Weapon::Weapon(string n, int d, double r) {
    name = new string(n);
    damage = new int(d);
    range = new double(r);
}

// Конструктор копирования 
Weapon::Weapon(const Weapon& other) {
    name = new string(*(other.name));
    damage = new int(*(other.damage));
    range = new double(*(other.range));
}

// Деструктор
Weapon::~Weapon() {
    delete name;
    delete damage;
    delete range;
}

// Удар оружием
void Weapon::hit(BaseCharacter* actor, BaseCharacter* target) {
    // Проверяем, живa ли цель?
    if (!target->is_alive()) {
        cout << "Враг уже повержен" << endl;
        return;
    }
    
    // Вычисляем расстояние между персонажами
    double dx = actor->get_x() - target->get_x();
    double dy = actor->get_y() - target->get_y();
    double distance = sqrt(dx*dx + dy*dy);
    
    // Проверяем дальность
    if (distance > *range) {
        cout << "Враг слишком далеко для оружия " << *name << endl;
        return;
    }
    
    // Наносим урон
    cout << "Врагу нанесен урон оружием " << *name 
         << " в размере " << *damage << endl;
    target->get_damage(*damage);
}

// Вывод оружия 
ostream& operator<<(ostream& os, const Weapon& w) {
    os << *(w.name);
    return os;
}

// Ввод оружия 
istream& operator>>(istream& is, Weapon& w) {
    string n;
    int d;
    double r;
    
    cout << "Введите название оружия: ";
    is >> n;
    cout << "Введите урон: ";
    is >> d;
    cout << "Введите радиус действия: ";
    is >> r;
    
    *(w.name) = n;
    *(w.damage) = d;
    *(w.range) = r;
    
    return is;
}
