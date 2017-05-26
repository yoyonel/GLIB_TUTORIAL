cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project("GLIB_TUTORIAL" C)

set(CMAKE_BUILD_TYPE "Debug")

# "CMake modules for GNOME libraries and tools"
# urls: 
# - https://stackoverflow.com/questions/36868143/what-is-the-recommended-way-of-using-glib2-with-cmake
# - https://github.com/nemequ/gnome-cmake/
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/../gnome-cmake/modules)

find_package(GObject REQUIRED)
find_package(GLib REQUIRED)

MESSAGE("- GLib_VERSION: ${GLib_VERSION}")
MESSAGE("- GLib_LIBRARY: ${GLib_LIBRARY}")
MESSAGE("- GLib_INCLUDE_DIRS: ${GLib_INCLUDE_DIRS}")

include_directories(${GLib_INCLUDE_DIRS})

#####################
## Le_code_minimal ##
#####################
# include_directories(${CMAKE_SOURCE_DIR}/src/Le_code_minimal/include)

# add_executable(
#   Le_code_minimal
#   src/Le_code_minimal/main.c
#   src/Le_code_minimal/vehicule.c
# )

# # "This was trivial to fix, just a matter of adding -lgobject-2.0 to the"
# # url: https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=713688
# target_link_libraries(
# 	Le_code_minimal
# 	${GObject_LIBRARY}
# 	${GLib_LIBRARY}
# 	)


# add_executable(
#   Le_code_minimal_with_macros
#   src/Le_code_minimal/main.c
#   src/Le_code_minimal/vehicule_with_macros.c
# )

# # "This was trivial to fix, just a matter of adding -lgobject-2.0 to the"
# # url: https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=713688
# target_link_libraries(
# 	Le_code_minimal_with_macros
# 	${GObject_LIBRARY}
# 	${GLib_LIBRARY}
# 	)
#####################

#######################
## Le Code Minimal   ##
#######################
add_subdirectory(projects/Le_code_minimal)
#####################

#####################
## Champs Public   ##
#####################
add_subdirectory(projects/Champs_public)
#####################

#####################
## Champs Prives   ##
#####################
add_subdirectory(projects/Champs_prives)
#####################

############################
## Constructor/Destructor ##
############################
add_subdirectory(projects/Constructor_Destructor)
############################

########################
## Membres de classes ##
########################
add_subdirectory(projects/Membres_de_classes)
########################

########################
## Membres de classes ##
########################
add_subdirectory(projects/Methodes_Virtuelles)
########################

########################
## Membres de classes ##
########################
add_subdirectory(projects/Proprietes)
########################

########################
## Membres de classes ##
########################
add_subdirectory(projects/GObject_Builder)
########################
