#####################
## Champs Privés   ##
#####################
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project("GLIB_TUTORIAL_Champs_Prives" C)

include_directories(include)

# MESSAGE( CMAKE_SOURCE_DIR : ${CMAKE_SOURCE_DIR})

add_executable(
  Champs_prives
  src/vehicule.c
  src/main.c
  include/vehicule.h
)

# "This was trivial to fix, just a matter of adding -lgobject-2.0 to the"
# url: https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=713688
target_link_libraries(
	Champs_prives
	${GObject_LIBRARY}
	${GLib_LIBRARY}
	)
#####################
