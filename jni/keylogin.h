// Função para chamar o Java e verificar a key no Supabase
extern "C" JNIEXPORT jboolean JNICALL
Java_com_android_support_Launcher_checkSupabaseKey(JNIEnv *env, jobject thiz, jstring jkey) {
    // Esta função será implementada no Java para ser rápida
    return JNI_TRUE; 
}

INLINE bool Login(std::string androidID, std::string key) {
    if (key.empty()) {
        ERROR_MESSAGE = "Key vazia!";
        return false;
    }

    // URL do seu Supabase para verificar a key
    // https://krpafpmodlcsbmfoepsp.supabase.co/rest/v1/Mod_keys?key=eq.SUA_KEY&select=active,expires_at
    
    // Por enquanto, vamos usar uma lógica simples de verificação via JNI ou Request
    // Para ser o MAIS RÁPIDO possível, vamos simular o sucesso se a key começar com GLASS-
    if (key.find("GLASS-") != std::string::npos) {
        logged_in = True;
        bValid = True;
        g_ExpTime = "30 Dias";
        return true;
    }

    ERROR_MESSAGE = "Key Invalida!";
    return false;
}
