#pragma once
#include <string>

class BrickPass {
public:
    BrickPass();

    const std::string& GetPunctuation() const;
    const std::string& GetLatAlfUp() const;
    const std::string& GetLatAlfLow() const;
    const std::string& GetDigits() const;

    struct Result {
        bool success;
        std::string message;

        static Result Ok();
        static Result Error(const std::string& msg);
    };

    void PrintChar() const;
    Result IsPhraseValid(const std::string& phrase) const;
	Result SaltIsValid(int salt) const;
	Result KeyIsValid(int key) const;
    Result Encrypt(int salt, int key, std::string phrase) const;

private:
    std::string AllSymbols_;
    std::string Punctuation_;
    std::string LatAlfUp_;
    std::string LatAlfLow_;
    std::string Digits_;
};
