#pragma once
#include <Res/res.h>
#include <string>
namespace res{

    class Layer{
        protected:
            const char* m_name;
            static uint32_t m_LAYER_COUNT;
        public:
            Layer();
            Layer(const char* name);
            virtual void onLoad(){};
            virtual void update(){};
            virtual void render(){};
            virtual void onUnload(){};
            void setName(const char* name);
            inline const char* getName(){return m_name;}
    };

}