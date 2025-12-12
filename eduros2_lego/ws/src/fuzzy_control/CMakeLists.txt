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

# LibTorch
set(Torch_DIR "/usr/local/libtorch/share/cmake/Torch")
find_package(Torch REQUIRED)

# --- Librería con la lógica fuzzy ---
add_library(fuzzyEngine src/fuzzyEngine.cpp)

target_include_directories(fuzzyEngine PUBLIC
  include
  /usr/local/include   # aquí está fl/Headers.h
)

target_link_libraries(fuzzyEngine /usr/local/lib/libfuzzylite.so)

# --- Ejecutables (nodos) ---
add_executable(fuzzyEncoders src/fuzzyEncoders.cpp)
add_executable(fuzzyMugimendua src/fuzzyMugimendua.cpp)
add_executable(ikasDatuenBiltegitzea src/ikasDatuenBiltegitzea.cpp)
add_executable(fuzzyNNMugimendua src/fuzzyNNMugimendua.cpp)

target_include_directories(fuzzyEncoders PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}>)

target_include_directories(fuzzyMugimendua PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}>)

target_include_directories(ikasDatuenBiltegitzea PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}>)

target_include_directories(fuzzyNNMugimendua PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}>)

target_compile_features(fuzzyEncoders PUBLIC c_std_99 cxx_std_17)
target_compile_features(fuzzyMugimendua PUBLIC c_std_99 cxx_std_17)
target_compile_features(ikasDatuenBiltegitzea PUBLIC c_std_99 cxx_std_17)
target_compile_features(fuzzyNNMugimendua PUBLIC c_std_99 cxx_std_17)

ament_target_dependencies(fuzzyEncoders rclcpp std_msgs mezuak)
ament_target_dependencies(fuzzyMugimendua rclcpp std_msgs mezuak)
ament_target_dependencies(ikasDatuenBiltegitzea rclcpp std_msgs mezuak)
ament_target_dependencies(fuzzyNNMugimendua rclcpp std_msgs mezuak)

target_link_libraries(fuzzyEncoders fuzzyEngine)
target_link_libraries(fuzzyMugimendua fuzzyEngine)
target_link_libraries(ikasDatuenBiltegitzea fuzzyEngine)
target_link_libraries(fuzzyNNMugimendua fuzzyEngine "${TORCH_LIBRARIES}")

# --- Instalación ---
install(TARGETS fuzzyEngine fuzzyEncoders fuzzyMugimendua ikasDatuenBiltegitzea fuzzyNNMugimendua
  ARCHIVE DESTINATION lib/${PROJECT_NAME}
  LIBRARY DESTINATION lib/${PROJECT_NAME}
  RUNTIME DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY include/
  DESTINATION include/${PROJECT_NAME})

# Instalar el modelo TorchScript en la carpeta de instalación ikas_datuak
install(FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/model/model.pt
  DESTINATION share/ikas_datuak
)

# Tests opcionales
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
