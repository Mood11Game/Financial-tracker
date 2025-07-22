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

# Поиск необходимых компонентов Qt
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Core Gui Network Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Core Gui Network Sql)

# Поиск PostgreSQL
find_package(PostgreSQL REQUIRED)

# Проверка наличия драйвера QPSQL
if(NOT Qt${QT_VERSION_MAJOR}Sql_POSTGRESQL_FOUND)
    message(WARNING "PostgreSQL driver not found in Qt SQL. Please install qt-psql package.")
endif()

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

# Подключение всех необходимых библиотек
target_link_libraries(project PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::Network
    Qt${QT_VERSION_MAJOR}::Sql
    PostgreSQL::PostgreSQL
)

# Дополнительные настройки для macOS
if(APPLE)
    # Добавляем путь к библиотекам PostgreSQL (для Homebrew)
    find_library(POSTGRESQL_LIB NAMES pq libpq.dylib PATHS /usr/local/opt/libpq/lib)
    if(POSTGRESQL_LIB)
        target_link_libraries(project PRIVATE ${POSTGRESQL_LIB})
    endif()
endif()

# Финализация для Qt6
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(project)
endif()
