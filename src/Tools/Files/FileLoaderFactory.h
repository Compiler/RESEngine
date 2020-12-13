#pragma once
#include <glad/glad.h>
#include <string>
#include <fstream>
#include <streambuf>
#include <Tools/Logging/FastLogger.h>
#define RES_INTERNAL(x)         "src/Resources/" x
#define RES_INTERNAL_SHADER(x)  RES_INTERNAL("Shaders/") x
#define RES_INTERNAL_TEXTURE(x) RES_INTERNAL("Textures/") x
#define RES_INTERNAL_MODEL(x)   RES_INTERNAL("Models/") x
#define RES_INTERNAL_SOUNDS(x)  RES_INTERNAL("Sounds/") x


namespace res {

    namespace FileLoaderFactory{
        extern void loadTextFromFile(const char fileName[], std::string& dst);
        //rgba default composition
        extern unsigned char* loadImage(const char name[], int* width, int* height, int* numOfColChannels, int req_comp = 4/*STBI_rgb_alpha = 4*/);
        extern void free(void* data);
    }
}