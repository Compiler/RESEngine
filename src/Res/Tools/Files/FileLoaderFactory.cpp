#include "FileLoaderFactory.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
namespace res { namespace FileLoaderFactory{


    void loadTextFromFile(const char fileName[], std::string& dst){
        std::ifstream t(fileName);
        std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
        dst = str;
        if(dst.empty()){
            WARN("Couldn't open : '%s'", fileName);
        }
    }
	unsigned char* loadImage(const char name[], int* width, int* height, int* numOfColChannels, int req_comp) {
		stbi_set_flip_vertically_on_load(true);
		return stbi_load(name, width, height, numOfColChannels, req_comp);
	}

	void free(void* data) { stbi_image_free(data); }

}}