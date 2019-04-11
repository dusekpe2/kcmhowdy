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

SET(kmsettings_PART_SRCS
      howdy.cpp
      parser.cpp
      widget.cpp
      widget.ui
      )

QT5_ADD_RESOURCES(kcm_kmsettings_RCC_SRCS ${kmsettings_RCCS})
ADD_LIBRARY( howdy MODULE ${kmsettings_PART_SRCS} )
TARGET_LINK_LIBRARIES( howdy
                       KF5::CoreAddons
                       KF5::ConfigWidgets
                       KF5::I18n
                       ${SYNNEFO_LIBRARIES}
                       Qt5::Core
                       Qt5::Widgets
		       KF5::WidgetsAddons
                     )

INSTALL(TARGETS howdy          DESTINATION ${PLUGIN_INSTALL_DIR})
INSTALL(FILES   howdy.desktop  DESTINATION ${SERVICES_INSTALL_DIR} )

