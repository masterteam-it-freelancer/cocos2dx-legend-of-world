LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_LDLIBS := -llog

LOCAL_MODULE := MyGame_shared

LOCAL_MODULE_FILENAME := libMyGame

LOCAL_SRC_FILES :=  $(LOCAL_PATH)/../../../Classes/AppDelegate.cpp \
                     $(LOCAL_PATH)/../../../Classes/AboutScene.cpp \
                     $(LOCAL_PATH)/../../../Classes/EndGameScene.cpp \ 
                     $(LOCAL_PATH)/../../../Classes/ChooseHeroScene.cpp \
                     $(LOCAL_PATH)/../../../Classes/CScene.cpp \
                     $(LOCAL_PATH)/../../../Classes/LoadingScene.cpp \
                     $(LOCAL_PATH)/../../../Classes/LoadingScene_MidlleLevel.cpp \
                     $(LOCAL_PATH)/../../../Classes/LoadingScene_HardestLevel.cpp \
                     $(LOCAL_PATH)/../../../Classes/MainMenuScene.cpp \
                     $(LOCAL_PATH)/../../../Classes/MarketplaceScene.cpp \
                     $(LOCAL_PATH)/../../../Classes/PlayGameScene.cpp \
                     $(LOCAL_PATH)/../../../Classes/PlayGameScene_MiddleLevel.cpp \
                     $(LOCAL_PATH)/../../../Classes/PlayGameScene_HardestLevel.cpp \
                     $(LOCAL_PATH)/../../../Classes/SettingGameScene.cpp \
                     $(LOCAL_PATH)/../../../Classes/SplashScene.cpp \
                     $(LOCAL_PATH)/../../../Classes/SceneManager.cpp \
                     $(LOCAL_PATH)/../../../Classes/ResourceManager.cpp \
                   $(LOCAL_PATH)/../../../Classes/PlaySceneFile/BaseClasses/CChampion.cpp \
                   $(LOCAL_PATH)/../../../Classes/PlaySceneFile/BaseClasses/CDynamicObject.cpp \
                   $(LOCAL_PATH)/../../../Classes/PlaySceneFile/BaseClasses/CMonster.cpp \
                   $(LOCAL_PATH)/../../../Classes/PlaySceneFile/BaseClasses/CObject.cpp \
                   $(LOCAL_PATH)/../../../Classes/PlaySceneFile/BaseClasses/CSkill.cpp \
                   $(LOCAL_PATH)/../../../Classes/PlaySceneFile/BaseClasses/GameStates.cpp \
                   $(LOCAL_PATH)/../../../Classes/PlaySceneFile/BaseClasses/PlayerStates.cpp \
                   $(LOCAL_PATH)/../../../Classes/PlaySceneFile/BaseClasses/MonsterStates.cpp \
                   $(LOCAL_PATH)/../../../Classes/PlaySceneFile/BaseClasses/CPoint.cpp  \
                   $(LOCAL_PATH)/../../../Classes/PlaySceneFile/BaseClasses/LevelPoint.cpp \
                   $(LOCAL_PATH)/../../../Classes/PlaySceneFile/BaseClasses/CStaticObject.cpp \
                   $(LOCAL_PATH)/../../../Classes/PlaySceneFile/BaseClasses/JoyStick.cpp \
                   $(LOCAL_PATH)/../../../Classes/PlaySceneFile/BaseClasses/MyProgressingBar.cpp \
                   $(LOCAL_PATH)/../../../Classes/PlaySceneFile/Champions/CChampion_ElfArcher_1.cpp \
                   $(LOCAL_PATH)/../../../Classes/PlaySceneFile/Champions/CChampion_ElfFairy_1.cpp \
                   $(LOCAL_PATH)/../../../Classes/PlaySceneFile/Champions/CChampion_Golem_1.cpp \
                   $(LOCAL_PATH)/../../../Classes/PlaySceneFile/Champions/CChampion_Knight_1.cpp \
                   $(LOCAL_PATH)/../../../Classes/PlaySceneFile/Champions/CChampion_Knight_2.cpp \
                   $(LOCAL_PATH)/../../../Classes/PlaySceneFile/Champions/CChampion_Knight_3.cpp \
                   $(LOCAL_PATH)/../../../Classes/PlaySceneFile/Champions/CChampion_Orc_1.cpp \
                   $(LOCAL_PATH)/../../../Classes/PlaySceneFile/Champions/CChampion_Troll_1.cpp \
                   $(LOCAL_PATH)/../../../Classes/PlaySceneFile/Champions/CChampionManager.cpp \
                   $(LOCAL_PATH)/../../../Classes/PlaySceneFile/Monsters/CMonsterManager.cpp  \
                   $(LOCAL_PATH)/../../../Classes/PlaySceneFile/OtherSprites/CBuilding.cpp \
                   $(LOCAL_PATH)/../../../Classes/PlaySceneFile/OtherSprites/CStaticSprite.cpp \
                   $(LOCAL_PATH)/../../../Classes/PlaySceneFile/UI/JoyStick/SneakyInput/SneakyButton.cpp \
                   $(LOCAL_PATH)/../../../Classes/PlaySceneFile/UI/JoyStick/SneakyInput/SneakyButtonSkinnedBase.cpp \
                   $(LOCAL_PATH)/../../../Classes/PlaySceneFile/UI/JoyStick/SneakyInput/SneakyJoystick.cpp \
                   $(LOCAL_PATH)/../../../Classes/PlaySceneFile/UI/JoyStick/SneakyInput/SneakyJoystickSkinnedBase.cpp \
                   $(LOCAL_PATH)/../../../Classes/PlaySceneFile/UI/JoyStick/Extras/ContactListener.cpp
                   
                               
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../../Classes

# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END


LOCAL_STATIC_LIBRARIES := cc_static

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-module, cocos)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
