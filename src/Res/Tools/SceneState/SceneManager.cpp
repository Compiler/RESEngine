#include "SceneManager.h"

namespace res{


    SceneManager::SceneManager(){
        _currentScene = -1;
    }
    void SceneManager::onLoad(){
        _scenes[_currentScene]->onLoad();
    }

    void SceneManager::update(){
        _scenes[_currentScene]->update();
    }

    void SceneManager::render(){
        _scenes[_currentScene]->render();
    }


    void SceneManager::setCurrentScene(int sceneIndex){
        if(sceneIndex == _currentScene) return;
        if(sceneIndex < _scenes.size() && sceneIndex >= 0){
            LOG("Swapped from '%s' to '%s'", _scenes[_currentScene]->getName(), _scenes[sceneIndex]->getName());
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

    Scene& SceneManager::getScene(int index){
        if(index < 0 && index >= _scenes.size()){
            ERROR("getIndex failed, '%d' out of bounds", index);
        }
        return *_scenes[index];
    }


}