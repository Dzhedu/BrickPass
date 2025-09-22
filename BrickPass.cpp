#include <iostream>
#include <string>
#include <cctype> // For std::isdigit
#include <sstream> // For std::istringstream
#include <algorithm> // For std::find_if, std::isspace

class BrickPass {
public:
    BrickPass() :
        AllSymbols_("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!#$%&()*+,-./:;<=>?@[]^_`{|}~"),
        Punctuation_("!#$%&()*+,-./:;<=>?@[]^_`{|}~"),
        LatAlfUp_("ABCDEFGHIJKLMNOPQRSTUVWXYZ"),
        LatAlfLow_("abcdefghijklmnopqrstuvwxyz"),
        Digits_("0123456789")
    {}
                
    // Getters for Punctuation_, LatAlfUp_, LatAlfLow_, and Digits_
    const std::string& GetPunctuation() const { return Punctuation_; }
    const std::string& GetLatAlfUp() const { return LatAlfUp_; }
    const std::string& GetLatAlfLow() const { return LatAlfLow_; }
    const std::string& GetDigits() const { return Digits_; }

    void PrintChar() const {
        std::cout << "AllSymbols: " << AllSymbols_ << std::endl;
    }

	// Check that all characters in phrase are in Punctuation_, LatAlfUp_, LaftAlfLow_, or Digits_
    bool IsPhraseValid(const std::string& phrase) const {
        for (char ch : phrase) {
            if (AllSymbols_.find(ch) == std::string::npos) { return false; }
        }
        return true;
    }

    int Encrypt(int salt, int key, std::string phrase) const {
        return 0;
    }



private:
    std::string AllSymbols_;
    std::string Punctuation_;
    std::string LatAlfUp_;
	std::string LatAlfLow_;
    std::string Digits_;
};

int main() {
    BrickPass bp;
	bp.PrintChar();
}