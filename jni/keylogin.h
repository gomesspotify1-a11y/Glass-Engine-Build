#ifndef KEYLOGIN_H
#define KEYLOGIN_H

#include <string>

#ifdef MAIN_CPP
    bool bValid = false;
    bool logged_in = false;
    bool is_logging_in = false;
    std::string ERROR_MESSAGE = "";
    std::string g_ExpTime = "Ativa";
    std::string g_Token = "OK";
    std::string g_Auth = "OK";
#else
    extern bool bValid;
    extern bool logged_in;
    extern bool is_logging_in;
    extern std::string ERROR_MESSAGE;
    extern std::string g_ExpTime;
    extern std::string g_Token;
    extern std::string g_Auth;
#endif

inline bool Login(std::string androidID, std::string key) {
    if (key.empty()) {
        ERROR_MESSAGE = "Digite a Key!";
        return false;
    }
    if (key.length() >= 10 && key.substr(0, 6) == "GLASS-") {
        logged_in = true;
        bValid = true;
        g_Token = "OK";
        g_Auth = "OK";
        is_logging_in = false;
        return true;
    }
    ERROR_MESSAGE = "Key invalida!";
    return false;
}

#endif
