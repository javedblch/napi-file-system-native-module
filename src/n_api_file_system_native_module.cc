#include <fstream>
#include <string>
#include <napi.h>

std::string readFile(const std::string& filePath) {
    std::ifstream file(filePath);
    std::string content;
    
    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            content += line + "\n";
        }
        file.close();
    } else {
        throw std::runtime_error("Unable to open file");
    }
    return content;
}

void writeFile(const std::string& filePath, const std::string& data) {
    std::ofstream file(filePath);
    
    if (file.is_open()) {
        file << data;
        file.close();
    } else {
        throw std::runtime_error("Unable to create or open file for writing");
    }
}

Napi::Value ReadFileWrapper(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    
    if (info.Length() < 1 || !info[0].IsString()) {
        Napi::TypeError::New(env, "String expected").ThrowAsJavaScriptException();
        return env.Null();
    }
    
    std::string filePath = info[0].As<Napi::String>().Utf8Value();
    std::string content;
    
    try {
        content = readFile(filePath);
    } catch (const std::exception& e) {
        Napi::Error::New(env, e.what()).ThrowAsJavaScriptException();
        return env.Null();
    }
    
    // Return the content as a Napi::String
    return Napi::String::New(env, content);
}

Napi::Value WriteFileWrapper(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    
    if (info.Length() < 2 || !info[0].IsString() || !info[1].IsString()) {
        Napi::TypeError::New(env, "Two strings expected").ThrowAsJavaScriptException();
        return env.Null();
    }
    
    std::string filePath = info[0].As<Napi::String>().Utf8Value();
    std::string data = info[1].As<Napi::String>().Utf8Value();
    
    try {
        writeFile(filePath, data);
    } catch (const std::exception& e) {
        Napi::Error::New(env, e.what()).ThrowAsJavaScriptException();
        return env.Null();
    }
    
    // Return success message as a Napi::String
    return Napi::String::New(env, "File written successfully");
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "readFile"), Napi::Function::New(env, ReadFileWrapper));
    exports.Set(Napi::String::New(env, "writeFile"), Napi::Function::New(env, WriteFileWrapper));
    return exports;
}

NODE_API_MODULE(file_util, Init)