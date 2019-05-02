SET(howdy_SRCS
      howdy.cpp
      parser.cpp
      widget.cpp
      config.cpp
      model.cpp
)

set(howdy_UI
    ui/model.ui
    ui/widget.ui
    ui/config.ui
)

ki18n_wrap_ui(howdy_SRCS ${howdy_UI})
add_library( howdy MODULE ${howdy_SRCS} )
target_link_libraries( howdy
                       KF5::CoreAddons
                       KF5::ConfigWidgets
                       KF5::I18n
                       Qt5::Core
                       Qt5::Widgets
		       KF5::WidgetsAddons
)

install(TARGETS howdy DESTINATION ${PLUGIN_INSTALL_DIR})
