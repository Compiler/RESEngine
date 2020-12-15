#include "SceneManager.h"

namespace res{


    SceneManager::SceneManager(){
        _currentScene = -1;
    }
    Scene* SceneManager::emplaceScene(){
        _scenes.emplace_back(new Scene3D());
        if(_scenes.size() == 1) _currentScene = 0;
        return _scenes.back();
    }
    
    Scene* SceneManager::emplaceScene(const char* name){
        _scenes.emplace_back(new Scene3D());
        _scenes.back()->setName(name);
        if(_scenes.size() == 1){
            _currentScene = 0;
        }
        return _scenes.back();
    }

    void SceneManager::setCurrentScene(int sceneIndex){
        if(sceneIndex < _scenes.size() && sceneIndex >= 0){
            _currentScene = sceneIndex;
        }else{
            WARN("Scene not set: %d out of bounds", sceneIndex);
        }

    }

    Scene& SceneManager::getCurrentScene(){
        if(_currentScene == -1){
            ERROR("Requested currentScene but it isnt set");
        }
        return *_scenes[_currentScene];
     }

            Scene& getScene();
    Scene& SceneManager::getScene(int index){
        if(index < 0 && index >= _scenes.size()){
            ERROR("getIndex failed, '%d' out of bounds", index);
        }
        return *_scenes[index];
    }


}