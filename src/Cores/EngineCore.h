#pragma once
#include <Cores/Core.h>

namespace res{

    class EngineCore : public Core{
        private:

        public:
            explicit EngineCore() = default;
            virtual void onLoad() override;
            virtual void update() override;
            virtual void render() override;
            virtual void onUnload() override;

    };

}