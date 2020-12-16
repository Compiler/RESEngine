#pragma once
#include <vector>
#include <Res/Tools/SceneState/Scene.h>
#include <Res/Tools/SceneState/Scene3D.h>

namespace res{

    class SceneManager{
        private:
            std::vector<Scene*> _scenes;
            int _currentScene;
        public:
            SceneManager();
            void onLoad();
            void update();
            void render();
            template<typename T>
            T* emplaceScene(){
                _scenes.emplace_back(new T());
                if(_scenes.size() == 1) _currentScene = 0;
                return _scenes.back();
            }

            template<typename T>
            T* emplaceScene(const char* name){
                _scenes.emplace_back(new T());
                _scenes.back()->setName(name);
                if(_scenes.size() == 1) _currentScene = 0;
                return (T*)_scenes.back();
            }
            Scene& getCurrentScene();
            Scene& getScene(int index);

            void setCurrentScene(int sceneIndex);
            const std::vector<Scene*>& getScenes(){return _scenes;}


    };

}