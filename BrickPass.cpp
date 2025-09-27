#include "BrickPass.h"
#include "Version.h"
#include <iostream>

/* The BrickPass library was developed by Dzhedu.
Git repository: https://github.com/Dzhedu/BrickPass
Can be used to encrypt password information.*/

BrickPass::BrickPass()
    : AllSymbols_("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!#$%&()*+,-./:;<=>?@[]^_`{|}~")
{}
const char* BrickPass::GetVersion() {
    return BRICKPASS_VERSION_STRING;
}

BrickPass::Result BrickPass::IsPhraseValid(const std::string& phrase) const {
    for (char ch : phrase) {
        if (AllSymbols_.find(ch) == std::string::npos)
            return Result::Error("Invalid Character in phrase");
    }
    return Result::Ok();
}

BrickPass::Result BrickPass::SaltIsValid(int salt) const {
    if (salt < 1 || salt > 1000000000) {
        return Result::Error("Salt must be between 1 and 1000000000");
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
    while (lengthPhrase > lengthSalt) {
		resultSalt += clonedSalt;
        lengthSalt = resultSalt.length();
    if (lengthSalt > lengthPhrase) {
        resultSalt = resultSalt.substr(0, lengthPhrase);
        }
    }
    return resultSalt;
}
BrickPass::Result BrickPass::Shift(std::string strSalt, int key, std::string phrase) const {
    std::string resultPhrase = "";
    for (size_t i = 0; i < phrase.length(); ++i) {
        char ch = phrase[i];
        size_t pos = AllSymbols_.find(ch);
        if (pos != std::string::npos) {
            size_t newPos = (pos + (strSalt[i] - '0')) % AllSymbols_.length();
            resultPhrase += AllSymbols_[newPos];
        }
    }
	int resultKey = key;
    if (key > resultPhrase.length()) {
        resultKey = key % resultPhrase.length();
    }
    std::string firstPart = resultPhrase.substr(0, resultKey);
    std::string secondPart = resultPhrase.substr(resultKey);
    resultPhrase = secondPart + firstPart;
    return { true, resultPhrase };
}

BrickPass::Result BrickPass::ReverseShift(std::string strSalt, int key, std::string phrase) const {
    std::string mutationPhrase = "";
	int ResultKey = key;
    if (key > phrase.length()) {
        ResultKey = key % phrase.length();
    }
    std::string firstPart = phrase.substr(0, phrase.length() - ResultKey);
    std::string secondPart = phrase.substr(phrase.length() - ResultKey);
    mutationPhrase = secondPart + firstPart;
	std::string resultPhraseTemp = mutationPhrase;
    std::string resultPhrase = "";
    for (size_t i = 0; i < resultPhraseTemp.length(); ++i) {
        char ch = resultPhraseTemp[i];
        size_t pos = AllSymbols_.find(ch);
        if (pos != std::string::npos) {
            size_t newPos = (pos + AllSymbols_.length() - (strSalt[i] - '0')) % AllSymbols_.length();
            resultPhrase += AllSymbols_[newPos];
        }
    }
    return { true, resultPhrase };
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
	auto shiftResult = Shift(strSalt, key, phrase);
    return shiftResult;
}
BrickPass::Result BrickPass::Decrypt(int salt, int key, std::string phrase) const {
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
    auto reverseShiftResult = ReverseShift(strSalt, key, phrase);
    return reverseShiftResult;
}


BrickPass::Result BrickPass::Result::Ok() { return { true, "" }; }
BrickPass::Result BrickPass::Result::Error(const std::string& msg) { return { false, msg }; }
