cmake_minimum_required(VERSION 3.8)
project(fuzzy_control)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Dependencias ROS2
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(mezuak REQUIRED)

# --- Librería con la lógica fuzzy ---
add_library(fuzzyEngine src/fuzzyEngine.cpp)

# Añadimos cabeceras propias y las de fuzzylite
target_include_directories(fuzzyEngine PUBLIC
  include
  /usr/local/include   # aquí está fl/Headers.h
)

# Enlazamos directamente con la librería fuzzylite
target_link_libraries(fuzzyEngine /usr/local/lib/libfuzzylite.so)

# --- Ejecutable principal (el nodo) ---
add_executable(fuzzyEncoders src/fuzzyEncoders.cpp)
target_include_directories(fuzzyEncoders PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}>)
target_compile_features(fuzzyEncoders PUBLIC c_std_99 cxx_std_17)

# Vincular dependencias ROS2 y la librería fuzzyEngine
ament_target_dependencies(fuzzyEncoders
  rclcpp
  std_msgs
  mezuak
)
target_link_libraries(fuzzyEncoders fuzzyEngine)

# --- Instalación ---
install(TARGETS fuzzyEngine fuzzyEncoders
  ARCHIVE DESTINATION lib/${PROJECT_NAME}
  LIBRARY DESTINATION lib/${PROJECT_NAME}
  RUNTIME DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY include/
  DESTINATION include/${PROJECT_NAME})

# Tests opcionales
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
