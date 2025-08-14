#include <iostream>
#include <string>
#include <cctype> // Для std::isdigit

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

    // Статический метод для проверки, состоит ли строка только из цифр
    static bool IsNumber(const std::string& str) {
        if (str.empty()) return false;
        for (char c : str) {
            if (!std::isdigit(static_cast<unsigned char>(c))) {
                return false;
            }
        }
        return true;
    }

private:
    std::string letters_;  // All Latin alphabet letters
    std::string numbers_;  // All digits
    std::string symbols_;  // All symbols
};

int main() {
    std::string salt, key, phrase;

    std::cout << "Enter salt value: ";
    std::getline(std::cin, salt);

    std::cout << "Enter key value: ";
    std::getline(std::cin, key);

    std::cout << "Enter phrase value: ";
    std::getline(std::cin, phrase);

    BrickPass bp;
    bp.PrintChar();

    std::cout << "Salt: " << salt << std::endl;
    std::cout << "Key: " << key << std::endl;
    std::cout << "Phrase: " << phrase << std::endl;

    return 0;
}