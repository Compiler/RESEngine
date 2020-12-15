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
            Scene* emplaceScene();
            Scene* emplaceScene(const char* name);
            Scene& getCurrentScene();
            Scene& getScene(int index);

            void setCurrentScene(int sceneIndex);
            const std::vector<Scene*>& getScenes(){return _scenes;}


    };

}