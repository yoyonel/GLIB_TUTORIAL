cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project("GLIB_TUTORIAL" C)

set(CMAKE_BUILD_TYPE "Debug")

# "CMake modules for GNOME libraries and tools"
# urls: 
# - https://stackoverflow.com/questions/36868143/what-is-the-recommended-way-of-using-glib2-with-cmake
# - https://github.com/nemequ/gnome-cmake/
list(APPEND CMAKE_MODULE_PATH $ENV{GNOME_CMAKE_MODULES})

find_package(GObject REQUIRED)
find_package(GLib REQUIRED)

MESSAGE("- GLib_VERSION: ${GLib_VERSION}")
MESSAGE("- GLib_LIBRARY: ${GLib_LIBRARY}")
MESSAGE("- GLib_INCLUDE_DIRS: ${GLib_INCLUDE_DIRS}")

include_directories(${GLib_INCLUDE_DIRS})

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
