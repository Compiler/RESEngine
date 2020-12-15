#pragma once
#include <Res/res.h>

namespace res{

    class Layer{
        private:
            const char* _name;
            static uint32_t _LAYER_COUNT;
        public:
            Layer();
            Layer(const char* name);
            void setName(const char* name);
            inline const char* getName(){return _name;}
    };

}