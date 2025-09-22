#include "BrickPass.h"
#include <iostream>
#include <algorithm>

BrickPass::BrickPass()
    : AllSymbols_("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!#$%&()*+,-./:;<=>?@[]^_`{|}~"),
      Punctuation_("!#$%&()*+,-./:;<=>?@[]^_`{|}~"),
      LatAlfUp_("ABCDEFGHIJKLMNOPQRSTUVWXYZ"),
      LatAlfLow_("abcdefghijklmnopqrstuvwxyz"),
      Digits_("0123456789")
{}

void BrickPass::PrintChar() const {
    std::cout << "AllSymbols: " << AllSymbols_ << std::endl;
}

BrickPass::Result BrickPass::IsPhraseValid(const std::string& phrase) const {
    for (char ch : phrase) {
        if (AllSymbols_.find(ch) == std::string::npos)
            return Result::Error("Invalid Character in phrase");
    }
    return Result::Ok();
}

int BrickPass::Encrypt(int salt, int key, std::string phrase) const {
    auto result = IsPhraseValid(phrase);
    if (!result.success) {
        std::cerr << result.message << std::endl;
        return result.success;
    }
	std::cout << "Encrypting with salt: " << salt << ", key: " << key << ", phrase: " << phrase << std::endl;
    return 0;
}


BrickPass::Result BrickPass::Result::Ok() { return { true, "" }; }
BrickPass::Result BrickPass::Result::Error(const std::string& msg) { return { false, msg }; }

/*
int main() {
    BrickPass bp;
    bp.PrintChar();
}
*/