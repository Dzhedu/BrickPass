#include "BrickPass.h"
#include <iostream>
#include <algorithm>
#include <vector>

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

BrickPass::Result BrickPass::SaltIsValid(int salt) const {
    if (salt < 1 || salt > 9999) {
        return Result::Error("Salt must be between 1 and 9999");
    }
    return Result::Ok();
}
BrickPass::Result BrickPass::KeyIsValid(int key) const {
    if (key < 1 || key > 99) {
        return Result::Error("Key must be between 1 and 99");
    }
    return Result::Ok();
}
std::string BrickPass::StrComplate(const std::string salt, const std::string phrase) const {
    std::string clonedSalt = salt;
    int lengthSalt = salt.length();
    int lengthPhrase = phrase.length();
	std::string resultSalt = salt;
    while (phrase.length() > salt.length()) {
		resultSalt += clonedSalt;
        lengthSalt = resultSalt.length();
    if (lengthSalt > lengthPhrase) {
        resultSalt = resultSalt.substr(0, lengthPhrase);
        }
    }
    return resultSalt;
}

BrickPass::Result BrickPass::Encrypt(int salt, int key, std::string phrase) const {
    auto result = IsPhraseValid(phrase);
    if (!result.success) {
        return { result.success, result.message };
    }

	auto saltResult = SaltIsValid(salt);
    if (!saltResult.success) {
        return { saltResult.success, saltResult.message };
    }
	auto keyResult = KeyIsValid(key);
    if (!keyResult.success) {
        return { keyResult.success, keyResult.message };
	}
	std::string strSalt = std::to_string(salt);

    if (strSalt.length() < phrase.length()) {
        strSalt = StrComplate(strSalt, phrase);
    }
    else if (strSalt.length() > phrase.length()) {
        strSalt = strSalt.substr(0, phrase.length());
    } else
        {
        strSalt = strSalt;
	}
    return {true,"Encripted Phrase"};
}


BrickPass::Result BrickPass::Result::Ok() { return { true, "" }; }
BrickPass::Result BrickPass::Result::Error(const std::string& msg) { return { false, msg }; }

/*
int main() {
    BrickPass bp;
    bp.PrintChar();
}
*/