#include <iostream>
#include <string>
#include <cctype> // Для std::isdigit
#include <sstream> // Для std::istringstream
#include <algorithm> // Для std::find_if, std::isspace

class BrickPass {
public:
    BrickPass()
        : characters_("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^-_=+[]{};:,./?~")
    {
    }

    void PrintChar() const {
        std::cout << "Characters: " << characters_ << std::endl;
    }

    // Вспомогательная функция для обрезки пробелов с начала и конца строки
    static std::string Trim(const std::string& str) {
        auto start = std::find_if_not(str.begin(), str.end(), [](unsigned char ch) { return std::isspace(ch); });
        auto end = std::find_if_not(str.rbegin(), str.rend(), [](unsigned char ch) { return std::isspace(ch); }).base();
        if (start >= end) return "";
        return std::string(start, end);
    }

    // Вспомогательная функция для проверки наличия пробелов в строке
    static bool ContainsWhitespace(const std::string& str) {
        return std::any_of(str.begin(), str.end(), [](unsigned char ch) { return std::isspace(ch); });
    }

    // Encrypt: salt - двухзначное число, key - трехзначное число, phrase - строка
    static int Encrypt(int salt, int key, std::string phrase) {
        // Обрезаем пробелы с начала и конца
        phrase = Trim(phrase);

        // Проверка диапазона для salt
        if (salt < 10 || salt > 99) {
            std::cout << "Salt must be a two-digit number." << std::endl;
            return 1;
        }
        // Проверка диапазона для key
        if (key < 100 || key > 999) {
            std::cout << "Key must be a three-digit number." << std::endl;
            return 1;
        }
        if (phrase.empty()) {
            std::cout << "Phrase must be a non-empty string." << std::endl;
            return 1;
        }
        // Проверка на наличие пробелов внутри строки
        if (ContainsWhitespace(phrase)) {
            std::cout << "Phrase must not contain any whitespace characters." << std::endl;
            return 1;
        }
        std::cout << "Encryption started..." << std::endl;
        // ...
        return 0;
    }

private:
    std::string characters_;  // All Characters
};

int main() {
    std::string saltStr, keyStr, phrase;
    int salt, key;

    std::cout << "Enter salt value: ";
    std::getline(std::cin, saltStr);
    std::cout << "Enter key value: ";
    std::getline(std::cin, keyStr);
    std::cout << "Enter phrase value: ";
    std::getline(std::cin, phrase);

    // Обрезаем пробелы с начала и конца для phrase
    phrase = BrickPass::Trim(phrase);

    // Проверка, что saltStr и keyStr — числа
    std::istringstream issSalt(saltStr), issKey(keyStr);
    if (!(issSalt >> salt) || !(issKey >> key)) {
        std::cout << "Salt and Key must be numbers." << std::endl;
        return 1;
    }

    BrickPass bp;
    bp.PrintChar(); 

    std::cout << "Salt: " << salt << std::endl;
    std::cout << "Key: " << key << std::endl;
    std::cout << "Phrase: " << phrase << std::endl;

    // Вызов функции Encrypt
    int result = BrickPass::Encrypt(salt, key, phrase);
    if (result == 1) {
        return 1;
    }

    return 0;
}