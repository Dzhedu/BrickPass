#include <iostream>
#include <string>
#include <cctype> // For std::isdigit
#include <sstream> // For std::istringstream
#include <algorithm> // For std::find_if, std::isspace

class BrickPass {
public:
    BrickPass()
        : characters_("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^-_=+[]{};:,./?~"),
          Letters_("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"),
          Numbers_("0123456789"),
          Symbols_("!@#$%^-_=+[]{};:,./?~")
    {
    }

    void PrintChar() const {
        std::cout << "Characters: " << characters_ << std::endl;
    }

    // Helper function to trim whitespace from the beginning and end of a string
    static std::string Trim(const std::string& str) {
        auto start = std::find_if_not(str.begin(), str.end(), [](unsigned char ch) { return std::isspace(ch); });
        auto end = std::find_if_not(str.rbegin(), str.rend(), [](unsigned char ch) { return std::isspace(ch); }).base();
        if (start >= end) return "";
        return std::string(start, end);
    }

    // Check that all characters in phrase are in Letters_, Numbers_, or Symbols_
    bool IsPhraseValid(const std::string& phrase) const {
        for (char ch : phrase) {
            if (Letters_.find(ch) == std::string::npos &&
                Numbers_.find(ch) == std::string::npos &&
                Symbols_.find(ch) == std::string::npos) {
                return false;
            }
        }
        return true;
    }

    // Encrypt: salt - two-digit number, key - three-digit number, phrase - string
    int Encrypt(int salt, int key, std::string phrase) const {
        phrase = Trim(phrase);

        if (salt < 10 || salt > 99) {
            std::cout << "Salt must be a two-digit number." << std::endl;
            return 1;
        }
        if (key < 100 || key > 999) {
            std::cout << "Key must be a three-digit number." << std::endl;
            return 1;
        }
        if (phrase.empty()) {
            std::cout << "Phrase must be a non-empty string." << std::endl;
            return 1;
        }
        if (!IsPhraseValid(phrase)) {
            std::cout << "Phrase can only contain the following characters: "
                      << Letters_ << Numbers_ << Symbols_ << std::endl;
            return 1;
        }
        std::cout << "Encryption started..." << std::endl;
        // ...
        return 0;
    }

    // Getters for Letters_, Numbers_, Symbols_
    const std::string& GetLetters() const { return Letters_; }
    const std::string& GetNumbers() const { return Numbers_; }
    const std::string& GetSymbols() const { return Symbols_; }

private:
    std::string characters_;  // All characters
    std::string Letters_;     // All letters
    std::string Numbers_;     // All numbers
    std::string Symbols_;     // All symbols
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

    // Trim whitespace from the beginning and end of phrase
    phrase = BrickPass::Trim(phrase);

    // Check that saltStr and keyStr are numbers
    std::istringstream issSalt(saltStr), issKey(keyStr);
    if (!(issSalt >> salt) || !(issKey >> key)) {
        std::cout << "Salt and Key must be numbers." << std::endl;
        return 1;
    }

    BrickPass bp;
    bp.PrintChar();

    // Check that phrase contains only allowed characters
    for (char ch : phrase) {
        if (bp.GetLetters().find(ch) == std::string::npos &&
            bp.GetNumbers().find(ch) == std::string::npos &&
            bp.GetSymbols().find(ch) == std::string::npos) {
            std::cout << "Phrase can only contain the following characters: "
                      << bp.GetLetters() << bp.GetNumbers() << bp.GetSymbols() << std::endl;
            return 1;
        }
    }

    std::cout << "Salt: " << salt << std::endl;
    std::cout << "Key: " << key << std::endl;
    std::cout << "Phrase: " << phrase << std::endl;

    int result = bp.Encrypt(salt, key, phrase);
    if (result == 1) {
        return 1;
    }

    return 0;
}