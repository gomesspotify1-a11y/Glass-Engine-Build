#ifndef KEYLOGIN_H
#define KEYLOGIN_H

#include <string>
#include <stdbool.h>

// Variáveis que o draw.h e outros arquivos precisam
bool bValid = false;
static bool logged_in = false;
std::string ERROR_MESSAGE = "";
std::string g_ExpTime = "Ativa";
std::string g_Token = "OK";
std::string g_Auth = "OK";

inline bool Login(std::string androidID, std::string key) {
    if (key.empty()) {
        ERROR_MESSAGE = "Por favor, digite a Key!";
        return false;
    }

    // Verifica se a key tem o formato do seu bot (GLASS-XXXX)
    if (key.length() >= 10 && key.substr(0, 6) == "GLASS-") {
        logged_in = true;
        bValid = true;
        g_Token = "OK";
        g_Auth = "OK";
        return true;
    }

    ERROR_MESSAGE = "Key invalida ou expirada!";
    return false;
}

#endif
