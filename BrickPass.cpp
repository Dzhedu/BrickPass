#include <iostream>
#include <string>

class BrickPass {
public:
    BrickPass()
        : letters_("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"),
          numbers_("0123456789"),
          symbols_("!@#$%^&*()-_=+[]{}|;:',.<>/?`~")
    {
    }

    void PrintChar() const {
        std::cout << "Letters: " << letters_ << std::endl;
        std::cout << "Numbers: " << numbers_ << std::endl;
        std::cout << "Symbols: " << symbols_ << std::endl;
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

    // Example: output entered values
    std::cout << "Salt: " << salt << std::endl;
    std::cout << "Key: " << key << std::endl;
    std::cout << "Phrase: " << phrase << std::endl;

    return 0;
}