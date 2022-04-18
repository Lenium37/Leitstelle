# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)


# Find the QtWidgets library
find_package(Qt5Widgets CONFIG REQUIRED)
# Find the QXml library
find_package(Qt5Xml REQUIRED)

set(main_headers
        vehicle_window.h
        main_window.h
        leitstellenwindow.h
        alarm_dialog.h
        vehicle.h
        leitstelle.h
        xml_vehicle_list_reader.h
        vehicle_label.h
        vehicle_label_menu.h
        info_window.h
        digital_clock.h
        digital_timer.h
        crew_window.h
        alarm_window.h
        )

set(main_srcs
        main.cpp
        main_window.cpp
        leitstellenwindow.cpp
        alarm_dialog.cpp
        vehicle_window.cpp
        vehicle.cpp
        leitstelle.cpp
        xml_vehicle_list_reader.cpp
        vehicle_label.cpp
        vehicle_label_menu.cpp
        info_window.cpp
        crew_window.cpp
        alarm_window.cpp
        )

set(main_ui
        main_window.ui
        vehicle_window.ui
        info_window.ui
        crew_window.ui
        leitstellenwindow.ui
        alarm_dialog.ui
        alarm_window.ui
        )

qt5_add_resources(RESOURCE_FILES resources/kln/resources.qrc)

set(UI_EXECUTABLE_NAME ${PROJECT_NAME})

#include(fixturemanager/CMakeLists.txt)
#include(player_edit_view/CMakeLists.txt)
#include(playlist_and_player/CMakeLists.txt)
#include(playlist_view/CMakeLists.txt)


add_executable(${UI_EXECUTABLE_NAME}
        ${main_srcs}
        ${main_headers}
        ${main_ui}
        ${RESOURCE_FILES}
        )


install(TARGETS ${UI_EXECUTABLE_NAME} DESTINATION bin)


target_link_libraries(${UI_EXECUTABLE_NAME} Qt5::Widgets Qt5::Xml)