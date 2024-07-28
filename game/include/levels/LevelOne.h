//
// Created by ghima on 19-07-2024.
//

#ifndef LIGHTYEARS_LEVELONE_H
#define LIGHTYEARS_LEVELONE_H
namespace ly {
    class BackGroundLayer;

    class LevelOne : public World {
    public:
        explicit LevelOne(Application *application);

        virtual void BeginPlay() override;

        void TestTimer();

        virtual void InitGameStage() override;

    private:
        Application *mApplication;
        shared<BackGroundLayer> mBackgroundLayer;
    };
}
#endif //LIGHTYEARS_LEVELONE_H
