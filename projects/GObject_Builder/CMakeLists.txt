#####################
## GObject Builder ##
#####################
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project("GLIB_TUTORIAL_GObject_Builder" C)

include_directories(gob/gen)

add_library(
  GObject_Builder_gen
  gob/gen/test-object.c
  gob/gen/test-object.h
  gob/gen/test-object-private.h
)

# "This was trivial to fix, just a matter of adding -lgobject-2.0 to the"
# url: https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=713688
target_link_libraries(
	GObject_Builder_gen
	${GObject_LIBRARY}
	${GLib_LIBRARY}
	)

add_executable(
	GObject_Builder
	src/main.c
	)

target_link_libraries(
	GObject_Builder
	GObject_Builder_gen	
	)
#####################
