
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class PasswordError : public exception {
public:
    const char* what() const throw() {
        return "Ошибка пароля!";
    }
};

class LengthError : public PasswordError {
public:
    const char* what() const throw() {
        return "Ошибка длины: пароль должен быть не менее 9 символов!";
    }
};

class RegisterError : public PasswordError {
public:
    const char* what() const throw() {
        return "Ошибка регистра: в пароле должны быть и большие, и маленькие буквы!";
    }
};

class DigitError : public PasswordError {
public:
    const char* what() const throw() {
        return "Ошибка: в пароле должна быть хотя бы одна цифра!";
    }
};

class ForbiddenLetterError : public PasswordError {
public:
    const char* what() const throw() {
        return "Ошибка: в пароле есть запрещённые символы (l, I, 1, o, O, 0)!";
    }
};

// ФУНКЦИЯ ПРОВЕРКИ ПАРОЛЯ 
string get_password() {
    string password;

    cout << "Введите пароль: ";
    getline(cin, password);

    // 1. ПРОВЕРКА ДЛИНЫ 
    if (password.length() < 9) {
        throw LengthError();
    }

    // 2. ПРОВЕРКА ЗАПРЕЩЁННЫХ СИМВОЛОВ
    for (char c : password) {
        if (c == 'l' || c == 'I' || c == '1' ||
            c == 'o' || c == 'O' || c == '0') {
            throw ForbiddenLetterError();
        }
    }

    // 3. ПРОВЕРКА РЕГИСТРА 
    bool hasUpper = false; // есть большая буква
    bool hasLower = false; // есть маленькая буква

    for (char c : password) {
        if (isupper(c)) {
            hasUpper = true;
        }
        if (islower(c)) {
            hasLower = true;
        }
    }

    // Если нет хотя бы одного вида регистра
    if (!hasUpper || !hasLower) {
        throw RegisterError();
    }

    // 4. ПРОВЕРКА НАЛИЧИЯ ЦИФР
    bool hasDigit = false;
    for (char c : password) {
        if (isdigit(c)) {
            hasDigit = true;
            break;
        }
    }

    if (!hasDigit) {
        throw DigitError();
    }

    return password;
}

int main() {
    setlocale(LC_ALL, "Rus");
    cout << "Требования к паролю:" << endl;
    cout << "длина не менее 9 символов" << endl;
    cout << "есть большие и маленькие буквы" << endl;
    cout << "есть хотя бы одна цифра" << endl;
    cout << "нет запрещённых символов: l, I, 1, o, O, 0\n" << endl;

    string password;
    bool success = false;

    // Цикл для повторного ввода при ошибке
    while (!success) {
        try {
            password = get_password();
            // Если дошли сюда - исключений не было
            cout << "\n ПАРОЛЬ ПРИНЯТ!" << endl;
            cout << "Ваш пароль: " << password << endl;
            success = true;

        }
        catch (LengthError& e) {
            cout << "\nНе подходит " << e.what() << endl;

        }
        catch (RegisterError& e) {
            cout << "\nНе подходит " << e.what() << endl;

        }
        catch (DigitError& e) {
            cout << "\nНе подходит " << e.what() << endl;

        }
        catch (ForbiddenLetterError& e) {
            cout << "\nНе подходит " << e.what() << endl;
            cout << "Не используйте: l, I, 1, o, O, 0\n" << endl;

        }
        catch (PasswordError& e) {
            cout << "\nНе подходит " << e.what() << endl;
        }


        cin.clear();
    }

    return 0;
}