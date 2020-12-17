#pragma once
#include <vector>
#include <Res/Tools/SceneState/Layer.h>
#include <Res/Tools/SceneState/DebugLayer.h>

namespace res{

    class LayerManager{
        private:
            std::vector<Layer*> _layers;
            int _currentLayer;
        public:
            LayerManager();
            void onLoad();
            void update();
            void render();
            void onUnload();
            template<typename T>
            T* emplaceLayer(){
                _layers.emplace_back(new T());
                _layers.back()->onLoad();
                LOG("Loaded '%s'", _layers.back()->getName());
                if(_layers.size() == 1) _currentLayer = 0;
                return _layers.back();
            }

            template<typename T>
            T* emplaceLayer(const char* name){
                _layers.emplace_back(new T());
                _layers.back()->onLoad();
                _layers.back()->setName(name);
                LOG("Loaded '%s'", _layers.back()->getName());


                if(_layers.size() == 1) _currentLayer = 0;
                return (T*)_layers.back();
            }
            Layer& getCurrentLayer();
            Layer& getLayer(int index);

            void setCurrentLayer(int layerIndex);
            const std::vector<Layer*>& getLayers(){return _layers;}


    };

}