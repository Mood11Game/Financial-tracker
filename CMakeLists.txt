cmake_minimum_required(VERSION 3.16)

project(project VERSION 0.1 LANGUAGES CXX)

# Настройки для macOS
if(APPLE)
    set(CMAKE_OSX_ARCHITECTURES "arm64" CACHE INTERNAL "")
    set(CMAKE_MACOSX_RPATH ON)
endif()

# Автоматизация Qt
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Поиск Qt (все возможные модули)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Core Gui Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Core Gui Network)

# Все исходные файлы
file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")
file(GLOB FORMS "*.ui")

qt_add_executable(project
    MANUAL_FINALIZATION
    ${SOURCES}
    ${HEADERS}
    ${FORMS}
)

# Подключение всех Qt-модулей
target_link_libraries(project PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::Network
)

# Финализация для Qt6
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(project)
endif()
