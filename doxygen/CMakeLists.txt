
#check if Doxygen is installed
find_package (Doxygen)

message("worldIMAKER_SOURCE_DIR     " ${WorldIMaker_SOURCE_DIR})
message("WorldIMAKER_BINARY_DIR     " ${WorldIMaker_BINARY_DIR})
message("DOXYGEN_EXECUTABLE     " ${DOXYGEN_EXECUTABLE})

if(DOXYGEN_FOUND)
  #set input and output files
  set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
  set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

  #Request to confidure file
  configure_file (${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
  message("Dofygen build started")

  #Options
  add_custom_target (
    html ALL
    COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Generating API documentation with Doxygen"
    VERBATIM)
else (DOXYGEN_FOUND)
  message("Doxygen not found")
endif (DOXYGEN_FOUND)
