add_library(pico-st7735 INTERFACE)

target_sources(pico-st7735 INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/adafruit-st7735.cpp
    ${CMAKE_CURRENT_LIST_DIR}/adafruit-st7735.h
)

target_include_directories(pico-st7735 INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}
)

if (NOT TARGET adafruit-st7735-and-st7789-library)
    add_subdirectory(../../libs/adafruit-st7735-and-st7789-library build_pac-adafruit-st7735-and-st7789-library)
endif()

target_link_libraries(pico-st7735 INTERFACE
    pac-adafruit-st7735-and-st7789-library
)