#######################
## Le Code Minimal   ##
#######################
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project("GLIB_TUTORIAL_Le_Code_Minimal" C)

include_directories(include)

# MESSAGE( CMAKE_SOURCE_DIR : ${CMAKE_SOURCE_DIR})

add_executable(
  Le_Code_Minimal
  src/main.c
  src/vehicule.c
  include/vehicule.h
)

# "This was trivial to fix, just a matter of adding -lgobject-2.0 to the"
# url: https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=713688
target_link_libraries(
	Le_Code_Minimal
	${GObject_LIBRARY}
	${GLib_LIBRARY}
	)

add_executable(
  Le_Code_Minimal_Avec_Macros
  src/main.c
  src/vehicule_with_macros.c
  include/vehicule.h
)

# "This was trivial to fix, just a matter of adding -lgobject-2.0 to the"
# url: https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=713688
target_link_libraries(
	Le_Code_Minimal_Avec_Macros
	${GObject_LIBRARY}
	${GLib_LIBRARY}
	)
#####################
