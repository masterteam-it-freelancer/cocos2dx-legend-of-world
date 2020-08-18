#/****************************************************************************
# Copyright (c) 2013-2014 cocos2d-x.org
# Copyright (c) 2015-2017 Chukong Technologies Inc.
#
# http://www.cocos2d-x.org
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
# ****************************************************************************/

cmake_minimum_required(VERSION 3.6)

set(APP_NAME LegendOfWorldProject)

project(${APP_NAME})

set(COCOS2DX_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cocos2d)
set(CMAKE_MODULE_PATH ${COCOS2DX_ROOT_PATH}/cmake/Modules/)

include(CocosBuildSet)
add_subdirectory(${COCOS2DX_ROOT_PATH}/cocos ${ENGINE_BINARY_PATH}/cocos/core)

# record sources, headers, resources...
set(GAME_SOURCE)
set(GAME_HEADER)

set(GAME_RES_FOLDER
    "${CMAKE_CURRENT_SOURCE_DIR}/Resources"
    )
if(APPLE OR WINDOWS)
    cocos_mark_multi_resources(common_res_files RES_TO "Resources" FOLDERS ${GAME_RES_FOLDER})
endif()

# add cross-platforms source files and header files 
list(APPEND GAME_SOURCE
     Classes/AppDelegate.cpp
     Classes/AboutScene.cpp
     Classes/EndGameScene.cpp
     Classes/ChooseHeroScene.cpp
     Classes/CScene.cpp
     Classes/LoadingScene.cpp
     Classes/LoadingScene_MidlleLevel.cpp
     Classes/LoadingScene_HardestLevel.cpp
     Classes/MainMenuScene.cpp
     Classes/MarketplaceScene.cpp
     Classes/PlayGameScene.cpp
     Classes/PlayGameScene_MiddleLevel.cpp
     Classes/PlayGameScene_HardestLevel.cpp
     Classes/SettingGameScene.cpp
     Classes/SplashScene.cpp
     Classes/SceneManager.cpp
     Classes/ResourceManager.cpp


     Classes/PlaySceneFile/BaseClasses/CChampion.cpp
     Classes/PlaySceneFile/BaseClasses/CDynamicObject.cpp
     Classes/PlaySceneFile/BaseClasses/CMonster.cpp
     Classes/PlaySceneFile/BaseClasses/CObject.cpp
     Classes/PlaySceneFile/BaseClasses/CSkill.cpp
     Classes/PlaySceneFile/BaseClasses/CPoint.cpp
     Classes/PlaySceneFile/BaseClasses/LevelPoint.cpp
     Classes/PlaySceneFile/BaseClasses/GameStates.cpp
     Classes/PlaySceneFile/BaseClasses/PlayerStates.cpp
     Classes/PlaySceneFile/BaseClasses/MonsterStates.cpp
     Classes/PlaySceneFile/BaseClasses/CStaticObject.cpp
     Classes/PlaySceneFile/BaseClasses/Joystick.cpp
     Classes/PlaySceneFile/BaseClasses/MyProgressingBar.cpp


     Classes/PlaySceneFile/Champions/CChampion_ElfArcher_1.cpp
     Classes/PlaySceneFile/Champions/CChampion_ElfFairy_1.cpp
     Classes/PlaySceneFile/Champions/CChampion_Golem_1.cpp
     Classes/PlaySceneFile/Champions/CChampion_Knight_1.cpp
     Classes/PlaySceneFile/Champions/CChampion_Knight_2.cpp
     Classes/PlaySceneFile/Champions/CChampion_Knight_3.cpp

     Classes/PlaySceneFile/Champions/CChampion_Orc_1.cpp
     Classes/PlaySceneFile/Champions/CChampion_Troll_1.cpp
     Classes/PlaySceneFile/Champions/CChampionManager.cpp
     Classes/PlaySceneFile/Monsters/CMonsterManager.cpp

     Classes/PlaySceneFile/OtherSprites/CBuilding.cpp
     Classes/PlaySceneFile/OtherSprites/CStaticSprite.cpp

     Classes/PlaySceneFile/UI/JoyStick/SneakyInput/SneakyButton.cpp
     Classes/PlaySceneFile/UI/JoyStick/SneakyInput/SneakyButtonSkinnedBase.cpp
     Classes/PlaySceneFile/UI/JoyStick/SneakyInput/SneakyJoystick.cpp
     Classes/PlaySceneFile/UI/JoyStick/SneakyInput/SneakyJoystickSkinnedBase.cpp

     Classes/PlaySceneFile/UI/JoyStick/Extras/ContactListener.cpp


     
     )
list(APPEND GAME_HEADER
     Classes/AppDelegate.h
     Classes/AboutScene.h
     Classes/EndGameScene.h
     Classes/ChooseHeroScene.h
     Classes/CScene.h
     Classes/LoadingScene.h
     Classes/LoadingScene_MidlleLevel.h
     Classes/LoadingScene_HardestLevel.h
     Classes/MainMenuScene.h
     Classes/MarketplaceScene.h
     Classes/PlayGameScene.h
     Classes/PlayGameScene_MiddleLevel.h
     Classes/PlayGameScene_HardestLevel.h
     Classes/SettingGameScene.h
     Classes/SplashScene.h
     Classes/SceneManager.h
     Classes/ResourceManager.h

     Classes/PlaySceneFile/BaseClasses/CChampion.h
     Classes/PlaySceneFile/BaseClasses/CDynamicObject.h
     Classes/PlaySceneFile/BaseClasses/CMonster.h
     Classes/PlaySceneFile/BaseClasses/CObject.h
     Classes/PlaySceneFile/BaseClasses/CSkill.h
     Classes/PlaySceneFile/BaseClasses/CPoint.h
     Classes/PlaySceneFile/BaseClasses/LevelPoint.h
     Classes/PlaySceneFile/BaseClasses/GameStates.h
     Classes/PlaySceneFile/BaseClasses/PlayerStates.h
     Classes/PlaySceneFile/BaseClasses/MonsterStates.h
     Classes/PlaySceneFile/BaseClasses/InputEnum.h
     Classes/PlaySceneFile/BaseClasses/CStaticObject.h
     Classes/PlaySceneFile/BaseClasses/Joystick.h
     Classes/PlaySceneFile/BaseClasses/MyProgressingBar.h

     Classes/PlaySceneFile/Champions/CChampion_ElfArcher_1.h
     Classes/PlaySceneFile/Champions/CChampion_ElfFairy_1.h
     Classes/PlaySceneFile/Champions/CChampion_Golem_1.h
     Classes/PlaySceneFile/Champions/CChampion_Knight_1.h
     Classes/PlaySceneFile/Champions/CChampion_Knight_2.h
     Classes/PlaySceneFile/Champions/CChampion_Knight_3.h
     Classes/PlaySceneFile/Champions/CChampion_Orc_1.h
     Classes/PlaySceneFile/Champions/CChampion_Troll_1.h
     Classes/PlaySceneFile/Champions/CChampionManager.h
     Classes/PlaySceneFile/Monsters/CMonsterManager.h


     Classes/PlaySceneFile/OtherSprites/CBuilding.h
     Classes/PlaySceneFile/OtherSprites/CStaticSprite.h

     
     Classes/PlaySceneFile/UI/JoyStick/SneakyInput/SneakyButton.h
     Classes/PlaySceneFile/UI/JoyStick/SneakyInput/SneakyButtonSkinnedBase.h
     Classes/PlaySceneFile/UI/JoyStick/SneakyInput/SneakyJoystick.h
     Classes/PlaySceneFile/UI/JoyStick/SneakyInput/SneakyJoystickSkinnedBase.h

     Classes/PlaySceneFile/UI/JoyStick/Extras/ContactListener.h
     )

if(ANDROID)
    # change APP_NAME to the share library name for Android, it's value depend on AndroidManifest.xml
    set(APP_NAME MyGame)
    list(APPEND GAME_SOURCE
         proj.android/app/jni/hellocpp/main.cpp
         )
elseif(LINUX)
    list(APPEND GAME_SOURCE
         proj.linux/main.cpp
         )
elseif(WINDOWS)
    list(APPEND GAME_HEADER
         proj.win32/main.h
         proj.win32/resource.h
         )
    list(APPEND GAME_SOURCE
         proj.win32/main.cpp
         proj.win32/game.rc
         ${common_res_files}
         )
elseif(APPLE)
    if(IOS)
        list(APPEND GAME_HEADER
             proj.ios_mac/ios/AppController.h
             proj.ios_mac/ios/RootViewController.h
             )
        set(APP_UI_RES
            proj.ios_mac/ios/LaunchScreen.storyboard
            proj.ios_mac/ios/LaunchScreenBackground.png
            proj.ios_mac/ios/Images.xcassets
            )
        list(APPEND GAME_SOURCE
             proj.ios_mac/ios/main.m
             proj.ios_mac/ios/AppController.mm
             proj.ios_mac/ios/RootViewController.mm
             proj.ios_mac/ios/Prefix.pch
             ${APP_UI_RES}
             )
    elseif(MACOSX)
        set(APP_UI_RES
            proj.ios_mac/mac/Icon.icns
            proj.ios_mac/mac/Info.plist
            )
        list(APPEND GAME_SOURCE
             proj.ios_mac/mac/main.cpp
             proj.ios_mac/mac/Prefix.pch
             ${APP_UI_RES}
             )
    endif()
    list(APPEND GAME_SOURCE ${common_res_files})
endif()

# mark app complie info and libs info
set(all_code_files
    ${GAME_HEADER}
    ${GAME_SOURCE}
    )
if(NOT ANDROID)
    add_executable(${APP_NAME} ${all_code_files})
else()
    add_library(${APP_NAME} SHARED ${all_code_files})
    add_subdirectory(${COCOS2DX_ROOT_PATH}/cocos/platform/android ${ENGINE_BINARY_PATH}/cocos/platform)
    target_link_libraries(${APP_NAME} -Wl,--whole-archive cpp_android_spec -Wl,--no-whole-archive)
endif()

target_link_libraries(${APP_NAME} cocos2d)
target_include_directories(${APP_NAME}
        PRIVATE Classes
        PRIVATE ${COCOS2DX_ROOT_PATH}/cocos/audio/include/
)

# mark app resources
setup_cocos_app_config(${APP_NAME})
if(APPLE)
    set_target_properties(${APP_NAME} PROPERTIES RESOURCE "${APP_UI_RES}")
    if(MACOSX)
        set_target_properties(${APP_NAME} PROPERTIES
                              MACOSX_BUNDLE_INFO_PLIST "${CMAKE_CURRENT_SOURCE_DIR}/proj.ios_mac/mac/Info.plist"
                              )
    elseif(IOS)
        cocos_pak_xcode(${APP_NAME} INFO_PLIST "iOSBundleInfo.plist.in")
        set_xcode_property(${APP_NAME} ASSETCATALOG_COMPILER_APPICON_NAME "AppIcon")
        set_xcode_property(${APP_NAME} DEVELOPMENT_TEAM "")
        set_xcode_property(${APP_NAME} CODE_SIGN_IDENTITY "iPhone Developer")
    endif()
elseif(WINDOWS)
    cocos_copy_target_dll(${APP_NAME})
endif()

if(LINUX OR WINDOWS)
    set(APP_RES_DIR "$<TARGET_FILE_DIR:${APP_NAME}>/Resources")
    cocos_copy_target_res(${APP_NAME} COPY_TO ${APP_RES_DIR} FOLDERS ${GAME_RES_FOLDER})
endif()
