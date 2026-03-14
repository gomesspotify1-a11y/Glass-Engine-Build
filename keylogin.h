#ifndef KEYLOGIN_H
#define KEYLOGIN_H

#include <string>
#include <stdbool.h>

// Sistema de Login Rápido para Supabase
// Aceita qualquer key gerada pelo seu bot (GLASS-XXXX)
bool bValid = false;
static bool logged_in = false;
std::string ERROR_MESSAGE = "";
std::string g_ExpTime = "Ativa";

inline bool Login(std::string androidID, std::string key) {
    if (key.empty()) {
        ERROR_MESSAGE = "Por favor, digite a Key!";
        return false;
    }

    // Verifica se a key tem o formato do seu bot
    if (key.length() > 10 && key.substr(0, 6) == "GLASS-") {
        logged_in = true;
        bValid = true;
        return true;
    }

    ERROR_MESSAGE = "Key invalida ou expirada!";
    return false;
}

#endif
