#include <iostream>
#include <string>
#include <cctype> // Для std::isdigit
#include <sstream> // Для std::istringstream

class BrickPass {
public:
    BrickPass()
        : letters_("ABCDEFGHIJKLMNñOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"),
          numbers_("0123456789"),
          symbols_("!@#$%^&*()-_=+[]{}|;:',.<>/?`~")
    {
    }

    void PrintChar() const {
        std::cout << "Letters: " << letters_ << std::endl;
        std::cout << "Numbers: " << numbers_ << std::endl;
        std::cout << "Symbols: " << symbols_ << std::endl;
    }

    // Encrypt: salt - двухзначное число, key - трехзначное число, phrase - строка
    static int Encrypt(int salt, int key, const std::string& phrase) {
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
        std::cout << "Encryption started..." << std::endl;
        // ...
        return 0;
    }

private:
    std::string letters_;  // All Latin alphabet letters
    std::string numbers_;  // All digits
    std::string symbols_;  // All symbols
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