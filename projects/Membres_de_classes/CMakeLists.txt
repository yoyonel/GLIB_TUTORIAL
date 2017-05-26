########################
## Membres de classes ##
########################
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project("GLIB_TUTORIAL_Membres_de_classes" C)

include_directories(include)

add_executable(
  Membres_de_classes
  src/vehicule.c
  src/main.c
  include/vehicule.h
)

# "This was trivial to fix, just a matter of adding -lgobject-2.0 to the"
# url: https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=713688
target_link_libraries(
	Membres_de_classes
	${GObject_LIBRARY}
	${GLib_LIBRARY}
	)
########################
