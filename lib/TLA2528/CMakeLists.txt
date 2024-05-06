add_library(TLA2528 TLA2528.cpp)
target_link_libraries(TLA2528 PUBLIC PicoPeripherals)
target_include_directories(TLA2528 INTERFACE .)
target_include_directories(TLA2528 PUBLIC . PicoPeripherals)
