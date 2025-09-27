#pragma once
#include <string>
#include "Version.h"

class BrickPass {
public:
    BrickPass();

    static const char* GetVersion();

    struct Result {
        bool success;
        std::string message;

        static Result Ok();
        static Result Error(const std::string& msg);
    };

    Result IsPhraseValid(const std::string& phrase) const;
	Result SaltIsValid(int salt) const;
	Result KeyIsValid(int key) const;
    Result Encrypt(int salt, int key, std::string phrase) const;
	Result Decrypt(int salt, int key, std::string phrase) const;
	Result Shift(std::string strSalt, int key, std::string phrase) const;
	Result ReverseShift(std::string strSalt, int key, std::string phrase) const;
	std::string StrComplate(const std::string salt, const std::string phrase) const;

private:
    std::string AllSymbols_;
};
