# Copyright 2013, MY NAME
#
# This file is part of reconstruction3D.
# reconstruction3D is free software: you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public License
# as published by the Free Software Foundation, either version 3 of
# the License, or (at your option) any later version.
#
# reconstruction3D is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# General Lesser Public License for more details.  You should have
# received a copy of the GNU Lesser General Public License along with
# reconstruction3D. If not, see <http://www.gnu.org/licenses/>.

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

SET(PROJECT_NAME MyLibraryName)
SET(PROJECT_DESCRIPTION "")
SET(PROJECT_URL "")

SET(CUSTOM_HEADER_DIR "${PROJECT_NAME}")

SET(CXX_DISABLE_WERROR 1)

#Options
OPTION(BUILD_SHARED_LIBRARY "Build the shared library." TRUE)
OPTION(INSTALL_BINARIES "Install binaries." FALSE)
OPTION(ENABLE_TEST "Enable test" FALSE)

#Include directories
include_directories ( ${CMAKE_SOURCE_DIR}/include/ )

#Set sources files
file(GLOB ${PROJECT_NAME}_SRCS src/*.cpp) 

#Set headers files
file(GLOB ${PROJECT_NAME}_HDRS include/*.h)

#Build libray
IF(BUILD_SHARED_LIBRARY)
  add_library ( ${PROJECT_NAME} SHARED ${${PROJECT_NAME}_SRCS})
ELSE(BUILD_SHARED_LIBRARY)
  add_library ( ${PROJECT_NAME} ${${PROJECT_NAME}_SRCS})
ENDIF(BUILD_SHARED_LIBRARY)
#TARGET_LINK_LIBRARIES( ${PROJECT_NAME})
LINK_DIRECTORIES( ${PROJECT_BINARY_DIR} )

#Build binaries
ADD_SUBDIRECTORY(bin)

#Build tests
ADD_SUBDIRECTORY(test)

#Build unit testing
IF(ENABLE_TEST)
  ENABLE_TESTING()
  ADD_SUBDIRECTORY(unitTesting)
ENDIF(ENABLE_TEST)

#Install headers
INSTALL(FILES ${${PROJECT_NAME}_HDRS}
	DESTINATION ${CMAKE_INSTALL_PREFIX}/include/${PROJECT_NAME}/
        PERMISSIONS OWNER_READ GROUP_READ WORLD_READ OWNER_WRITE
)

#Install library
INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_SHARED_LIBRARY_PREFIX}${PROJECT_NAME}${CMAKE_SHARED_LIBRARY_SUFFIX} 
	DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/
        PERMISSIONS OWNER_READ GROUP_READ WORLD_READ OWNER_WRITE
)

#Install complete
IF(INSTALL_BINARIES)
  OPTION(INSTALL_COMPLETE "Install completion files." FALSE)
  IF(INSTALL_COMPLETE)
    SET(COMPLETION_DIR /etc/bash_completion.d/ CACHE PATH "Completion folder")
    file(GLOB Matcher_COMPLETE complete/*.sh)
    INSTALL(FILES ${Matcher_COMPLETE}
	DESTINATION ${COMPLETION_DIR}
        PERMISSIONS OWNER_READ GROUP_READ WORLD_READ OWNER_WRITE
    )
  ENDIF(INSTALL_COMPLETE)
ENDIF(INSTALL_BINARIES)

#Configure
SET(${PROJECT_NAME}_CXXFLAGS "")

#Configure and install LibraryConfig.cmake.in
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/LibraryConfig.cmake.in
  "${PROJECT_BINARY_DIR}/MatcherConfig.cmake" )

INSTALL(FILES ${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
	DESTINATION ${CMAKE_INSTALL_PREFIX}/share/${PROJECT_NAME}
        PERMISSIONS OWNER_READ GROUP_READ WORLD_READ OWNER_WRITE )

#Configure and install Library.pc.cmake
SET(install_pkg_prefix "\${prefix}")
SET(install_pkg_exec_prefix "\${exec_prefix}")
SET(install_pkg_libdir "\${libdir}")
SET(install_pkg_include_dir "\${includedir}")
SET(install_libdir_pkgconfig ${CMAKE_INSTALL_PREFIX}/lib/pkgconfig)
SET(PROJECT_DESCRIPTION "")
SET(PROJECT_VERSION "")
SET(PROJECT_REQUIREMENTS "")

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/Library.pc.cmake
		 ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.pc )

INSTALL(FILES ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.pc
	DESTINATION ${install_libdir_pkgconfig}	
        PERMISSIONS OWNER_READ GROUP_READ WORLD_READ OWNER_WRITE )

#Create documentation
FIND_PACKAGE( Doxygen )

add_custom_target(doc
${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/doc/Doxyfile
COMMENT "Generating API documentation with Doxygen" VERBATIM)
