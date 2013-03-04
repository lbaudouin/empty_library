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


SET(PROJECT_NAME MyProjectName)
SET(PROJECT_DESCRIPTION "")
SET(PROJECT_URL "")

SET(CUSTOM_HEADER_DIR "${PROJECT_NAME}")

SET(CXX_DISABLE_WERROR 1)

#Options
OPTION(BUILD_SHARED_LIBRARY "Build the shared library." TRUE)
OPTION(INSTALL_BINARIES "Install binaries." FALSE)
OPTION(INSTALL_COMPLETE "Install completion files." FALSE)

#Include directories
include_directories (
	${CMAKE_SOURCE_DIR}/include/
)

#Set sources files
file(GLOB MY_SRCS src/*.cpp) 

#Set headers files
file(GLOB MY_HDRS include/*.h)

#Build libray
IF(BUILD_SHARED_LIBRARY)
  add_library ( ${PROJECT_NAME} SHARED ${MY_SRCS})
ELSE(BUILD_SHARED_LIBRARY)
  add_library ( ${PROJECT_NAME} ${MY_SRCS})
ENDIF(BUILD_SHARED_LIBRARY)
#TARGET_LINK_LIBRARIES( ${PROJECT_NAME})

#Build test
LINK_DIRECTORIES( ${PROJECT_BINARY_DIR} )
ADD_SUBDIRECTORY(test)

#Install headers
file(GLOB Matcher_HDRS include/*.h)
INSTALL(FILES ${MY_HDRS}
	DESTINATION ${CMAKE_INSTALL_PREFIX}/include/${PROJECT_NAME}/
        PERMISSIONS OWNER_READ GROUP_READ WORLD_READ OWNER_WRITE
)

#Install library
INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_SHARED_LIBRARY_PREFIX}${PROJECT_NAME}${CMAKE_SHARED_LIBRARY_SUFFIX} 
	DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/
        PERMISSIONS OWNER_READ GROUP_READ WORLD_READ OWNER_WRITE
)

#Create documentation
FIND_PACKAGE( Doxygen )

add_custom_target(doc
${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/doc/Doxyfile
COMMENT "Generating API documentation with Doxygen" VERBATIM)

