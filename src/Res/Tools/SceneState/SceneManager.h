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
            Scene* emplaceScene();
            Scene* emplaceScene(const char* name);
            Scene& getCurrentScene();
            Scene& getScene(int index);

            void setCurrentScene(int sceneIndex);


    };

}