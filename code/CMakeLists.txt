find_package(Qt5 REQUIRED COMPONENTS Core)


add_executable(AnyBak
  src/main.cpp
)

target_link_libraries(AnyBak PRIVATE Qt5::Core)
