cmake_minimum_required(VERSION 3.12)
FIND_PACKAGE(ECM REQUIRED NO_MODULE)
SET(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${CMAKE_MODULE_PATH})

# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

INCLUDE(KDEInstallDirs)
INCLUDE(KDECompilerSettings)
INCLUDE(KDECMakeSettings)
INCLUDE(FeatureSummary)
INCLUDE(GenerateExportHeader)


FIND_PACKAGE(Qt5 COMPONENTS Core Widgets REQUIRED)
FIND_PACKAGE(KF5ConfigWidgets REQUIRED)
FIND_PACKAGE(KF5CoreAddons REQUIRED)
FIND_PACKAGE(KF5I18n REQUIRED)
FIND_PACKAGE(KF5 COMPONENTS DocTools)

SET(howdy_SRCS
      howdy.cpp
      parser.cpp
      widget.cpp
      widget.ui
      config.cpp
      config.ui
      )
SET(PLUGIN_INSTALL_DIR "/usr/lib/x86_64-linux-gnu/qt5/plugins")
SET(SERVICES_INSTALL_DIR "/usr/share/kservices5")

ADD_LIBRARY( howdy MODULE ${howdy_SRCS} )
target_link_LIBRARIES( howdy
                       KF5::CoreAddons
                       KF5::ConfigWidgets
                       KF5::I18n
                       Qt5::Core
                       Qt5::Widgets
		       KF5::WidgetsAddons
                     )

INSTALL(TARGETS howdy          DESTINATION ${PLUGIN_INSTALL_DIR})
INSTALL(FILES   howdy.desktop  DESTINATION ${SERVICES_INSTALL_DIR} )

