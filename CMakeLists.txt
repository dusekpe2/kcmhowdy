cmake_minimum_required(VERSION 3.12)

include(CheckCXXCompilerFlag)

function(enable_cxx_compiler_flag_if_supported flag)
    string(FIND "${CMAKE_CXX_FLAGS}" "${flag}" flag_already_set)
    if(flag_already_set EQUAL -1)
        check_cxx_compiler_flag("${flag}" flag_supported)
        if(flag_supported)
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${flag}" PARENT_SCOPE)
        endif()
        unset(flag_supported CACHE)
    endif()
endfunction()

# example usage
enable_cxx_compiler_flag_if_supported("-Wall")
enable_cxx_compiler_flag_if_supported("-Wextra")
enable_cxx_compiler_flag_if_supported("-pedantic")

find_package(ECM ${KF5_MIN_VERSION} REQUIRED NO_MODULE)

SET(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${CMAKE_MODULE_PATH})

# Create code from a list of Qt designer ui files
#set(CMAKE_AUTOUIC ON)

include(KDEInstallDirs)
include(KDECompilerSettings)
include(KDECMakeSettings)
include(FeatureSummary)
include(GenerateExportHeader)

find_package(Qt5 ${QT_MIN_VERSION} COMPONENTS Core Widgets REQUIRED)

find_package(KF5 ${KF5_MIN_VERSION} REQUIRED COMPONENTS
    CoreAddons
    I18n
    Auth
    ConfigWidgets
    Archive
)
#FIND_PACKAGE(KF5ConfigWidgets REQUIRED)
#FIND_PACKAGE(KF5CoreAddons REQUIRED)
#FIND_PACKAGE(KF5I18n REQUIRED)

#SET(PLUGIN_INSTALL_DIR "/usr/lib/x86_64-linux-gnu/qt5/plugins")
#SET(SERVICES_INSTALL_DIR "/usr/share/kservices5")

install(FILES   kcm_howdy.desktop  DESTINATION ${SERVICES_INSTALL_DIR} )

kauth_install_actions(org.kde.kcontrol.kcmhowdy kcm_howdy.actions)

add_executable(kcmhowdy_authhelper howdyauthhelper.cpp)
target_link_libraries(kcmhowdy_authhelper KF5::Auth KF5::ConfigCore KF5::Archive KF5::I18n)

kauth_install_helper_files(kcmhowdy_authhelper org.kde.kcontrol.kcmhowdy root)
install(TARGETS kcmhowdy_authhelper DESTINATION ${KAUTH_HELPER_INSTALL_DIR})

add_subdirectory(src)

#INSTALL(TARGETS howdy          DESTINATION ${PLUGIN_INSTALL_DIR})



