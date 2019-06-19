configure_file(config.h.in config.h IMMEDIATE @ONLY)

set(KCM_HOWDY_SRCS
      kcmhowdy.cpp
      configwidget.cpp
      modelwidget.cpp
      facemodel.cpp
      facemodelslist.cpp
      addwidget.cpp
)

set(KCM_HOWDY_UI
     ui/modelwidget.ui
     ui/configwidget.ui
     ui/addwidget.ui 
)

qt5_wrap_ui(KCM_HOWDY_SRCS ${KCM_HOWDY_UI})
add_library( kcm_howdy MODULE ${KCM_HOWDY_SRCS} )
target_link_libraries( kcm_howdy
                       KF5::ConfigWidgets
                       Qt5::Widgets
)

install(TARGETS kcm_howdy DESTINATION ${PLUGIN_INSTALL_DIR})
