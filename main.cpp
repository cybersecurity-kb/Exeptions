#include <iostream>
#include <windows.h>
#include "Weapon.h"
#include "BaseCharacter.h"
#include "BaseEnemy.h"
#include "MainHero.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    
    // 1. СОЗДАЁМ ОРУЖИЕ
    cout << " СОЗДАНИЕ ОРУЖИЯ " << endl;
    
    Weapon* sword = new Weapon("Меч", 30, 1.5);
    Weapon* bow = new Weapon("Лук", 20, 5.0);
    Weapon* axe = new Weapon("Топор", 40, 1.0);
    Weapon* dagger = new Weapon("Кинжал", 15, 1.0);
    
    cout << "Создано оружие: " << *sword << ", " << *bow << ", " << *axe << ", " << *dagger << endl;
    
    // 2. СОЗДАЁМ ГЛАВНОГО ГЕРОЯ 
    cout << "\n СОЗДАНИЕ ГЕРОЯ " << endl;
    MainHero* hero = new MainHero(0, 0, "Сам думай ему имя", 150);
    cout << *hero << endl;
    
    //  3. ГЕРОЙ ПОДБИРАЕТ ОРУЖИЕ 
    cout << "\n ГЕРОЙ ПОДБИРАЕТ ОРУЖИЕ" << endl;
    hero->add_weapon(sword);
    hero->add_weapon(bow);
    hero->add_weapon(axe);
    
    //  4. СОЗДАЁМ ВРАГОВ 
    cout << "\n СОЗДАНИЕ ВРАГОВ" << endl;
    BaseEnemy* goblin = new BaseEnemy(2, 1, dagger, 50);
    BaseEnemy* orc = new BaseEnemy(1, 3, axe, 100);
    BaseEnemy* troll = new BaseEnemy(5, 5, bow, 80);
    
    cout << *goblin << endl;
    cout << *orc << endl;
    cout << *troll << endl;
    
    // 5. ТЕСТИРОВАНИЕ МЕТОДОВ 
    cout << "\n--- ТЕСТИРОВАНИЕ МЕТОДОВ ---" << endl;
    
    // Перемещение
    hero->move(0, 0);
    
    // Смена оружия
    hero->next_weapon();
    hero->next_weapon();
    
    // Удар по врагу
    cout << "\n--- БИТВА С ВРАГАМИ ---" << endl;
    
    // Бой с гоблином
    cout << "\nБой с гоблином:" << endl;
    while (goblin->is_alive() && hero->is_alive()) {
        hero->hit(goblin);
        if (goblin->is_alive()) {
            goblin->hit(hero);
        }
    }
    
    // Лечение героя
    cout << "\n--- ЛЕЧЕНИЕ ---" << endl;
    hero->heal(50);
    
    // Бой с орком
    cout << "\nБой с орком:" << endl;
    hero->move(2, 3);
    while (orc->is_alive() && hero->is_alive()) {
        hero->hit(orc);
        if (orc->is_alive()) {
            orc->hit(hero);
        }
    }
    
    // Бой с троллем
    cout << "\nБой с троллем:" << endl;
    hero->move(5, 5);
    while (troll->is_alive() && hero->is_alive()) {
        hero->hit(troll);
        if (troll->is_alive()) {
            troll->hit(hero);
        }
    }
    
    //  6. ДЕМОНСТРАЦИЯ ОПЕРАТОРА >> 
    cout << "\n ДЕМОНСТРАЦИЯ ВВОДА ОРУЖИЯ (>>) " << endl;
    Weapon* newWeapon = new Weapon("empty", 0, 0);
    cin >> *newWeapon;
    hero->add_weapon(newWeapon);
    
    // 7. ИТОГИ БИТВЫ 
    cout << "   РЕЗУЛЬТАТЫ БИТВЫ" << endl;
   
    if (hero->is_alive()) {
        cout << "Герой " << *hero << endl;
        cout << "ПОБЕДИЛ всех врагов! 🏆" << endl;
    } else {
        cout << "Герой погиб... 💀" << endl;
    }
    
    //  8. ОЧИСТКА ПАМЯТИ 
    cout << "\n ОЧИСТКА ПАМЯТИ " << endl;
    delete goblin;
    delete orc;
    delete troll;
    delete hero;
    delete dagger;
    
    
    return 0;
}
