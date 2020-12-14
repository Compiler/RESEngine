#pragma once

namespace res{

    class Scene3D{
        private:
            

        public:
            virtual void onLoad() = 0;
            virtual void update() = 0;
            virtual void render() = 0;
            virtual void onUnload() = 0;

    };

}