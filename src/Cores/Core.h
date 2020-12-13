#pragma once

namespace res{

    class Core{
        private:

        public:
            explicit Core() = default;
            virtual void onLoad() = 0;
            virtual void update() = 0;
            virtual void render() = 0;
            virtual void onUnload() = 0;

    };

}