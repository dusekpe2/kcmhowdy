project(kcm-howdy)
cmake_minimum_required(VERSION 3.12)

set(QT_MIN_VERSION "5.11.0")
set(KF5_MIN_VERSION "5.50.0")

find_package(ECM ${KF5_MIN_VERSION} REQUIRED NO_MODULE)

set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${CMAKE_MODULE_PATH})

include(KDEInstallDirs)
include(KDECMakeSettings)

find_package(Qt5 ${QT_MIN_VERSION} COMPONENTS Core Widgets REQUIRED)

find_package(KF5 ${KF5_MIN_VERSION} REQUIRED COMPONENTS
    Auth
    ConfigWidgets
)

install(FILES   kcm_howdy.desktop  DESTINATION ${SERVICES_INSTALL_DIR} )

kauth_install_actions(org.kde.kcontrol.kcmhowdy kcm_howdy.actions)

add_executable(kcmhowdy_authhelper howdyauthhelper.cpp)
target_link_libraries(kcmhowdy_authhelper KF5::Auth KF5::ConfigCore)

kauth_install_helper_files(kcmhowdy_authhelper org.kde.kcontrol.kcmhowdy root)
install(TARGETS kcmhowdy_authhelper DESTINATION ${KAUTH_HELPER_INSTALL_DIR})

add_subdirectory(src)


