# Copyright 2014, MY NAME
#
# This file is part of a free library: you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation, either version 3 of
# the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
# General Public License for more details. You should have
# received a copy of the GNU General Public License along with
# this library. If not, see <http://www.gnu.org/licenses/>.

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

#Define the project
SET(PROJECT_NAME MyLibraryName)
SET(PROJECT_DESCRIPTION "")
SET(PROJECT_URL "")
SET(PROJECT_VERSION "0.0.1")
SET(PROJECT_REQUIREMENTS "")

SET(CUSTOM_HEADER_DIR "${PROJECT_NAME}")

SET(CXX_DISABLE_WERROR 1)

#Options
OPTION(BUILD_SHARED_LIBRARY "Build the shared library." TRUE)
OPTION(INSTALL_BINARIES "Install binaries." FALSE)
OPTION(ENABLE_TEST "Enable test" FALSE)

#Find packages
#FIND_PACKAGE(PackageName REQUIRED)

#Configuration
SET(${PROJECT_NAME}_CXXFLAGS "")
SET(${PROJECT_NAME}_LIBS "")

#Include directories
include_directories( ${CMAKE_SOURCE_DIR}/include/ )

#Definition
#add_definitions( "-DMY_DEFINITION" )

#Set sources files
file(GLOB ${PROJECT_NAME}_SRCS src/*.cpp) 

#Set headers files
file(GLOB ${PROJECT_NAME}_HDRS include/*.h)

#Build library
IF(BUILD_SHARED_LIBRARY)
  add_library ( ${PROJECT_NAME} SHARED ${${PROJECT_NAME}_SRCS})
ELSE(BUILD_SHARED_LIBRARY)
  add_library ( ${PROJECT_NAME} ${${PROJECT_NAME}_SRCS})
ENDIF(BUILD_SHARED_LIBRARY)
#TARGET_LINK_LIBRARIES( ${PROJECT_NAME} ${OTHERLIBRARY_LIBS})
LINK_DIRECTORIES( ${PROJECT_BINARY_DIR} )

#Build binaries
IF(EXISTS ${CMAKE_SOURCE_DIR}/bin/CMakeLists.txt)
  ADD_SUBDIRECTORY(bin)
ENDIF()

#Build tests
IF(EXISTS ${CMAKE_SOURCE_DIR}/test/CMakeLists.txt)
  ADD_SUBDIRECTORY(test)
ENDIF()

#Build unit testing
IF(ENABLE_TEST)
  ENABLE_TESTING()
  IF(EXISTS ${CMAKE_SOURCE_DIR}/unitTesting/CMakeLists.txt)
    ADD_SUBDIRECTORY(unitTesting)
  ENDIF()
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

#Configure and install LibraryConfig.cmake.in
CONFIGURE_FILE(${CMAKE_SOURCE_DIR}/LibraryConfig.cmake.in
  "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake" )

INSTALL(FILES ${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
	DESTINATION ${CMAKE_INSTALL_PREFIX}/share/${PROJECT_NAME}
        PERMISSIONS OWNER_READ GROUP_READ WORLD_READ OWNER_WRITE )

#Configure and install LibraryConfigVersion.cmake.in
CONFIGURE_FILE(${CMAKE_SOURCE_DIR}/LibraryConfigVersion.cmake.in
  "${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake" @ONLY)

INSTALL(FILES ${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
	DESTINATION ${CMAKE_INSTALL_PREFIX}/share/${PROJECT_NAME}
        PERMISSIONS OWNER_READ GROUP_READ WORLD_READ OWNER_WRITE )

#Configure and install Library.pc.cmake
SET(install_pkg_prefix "\${prefix}")
SET(install_pkg_exec_prefix "\${exec_prefix}")
SET(install_pkg_libdir "\${libdir}")
SET(install_pkg_include_dir "\${includedir}")
SET(install_libdir_pkgconfig ${CMAKE_INSTALL_PREFIX}/lib/pkgconfig)

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/Library.pc.in
		 ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.pc )

INSTALL(FILES ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.pc
	DESTINATION ${install_libdir_pkgconfig}	
        PERMISSIONS OWNER_READ GROUP_READ WORLD_READ OWNER_WRITE )

#Create documentation
FIND_PACKAGE( Doxygen )

IF(DOXYGEN_FOUND)
  CONFIGURE_FILE(${CMAKE_SOURCE_DIR}/doc/Doxyfile.in ${PROJECT_BINARY_DIR}/doc/Doxyfile )
  add_custom_target(doc
  ${DOXYGEN_EXECUTABLE} ${PROJECT_BINARY_DIR}/doc/Doxyfile
  COMMENT "Generating API documentation with Doxygen" VERBATIM)
  INSTALL(DIRECTORY ${PROJECT_BINARY_DIR}/doc/html/
	  DESTINATION ${CMAKE_INSTALL_PREFIX}/share/doc/${PROJECT_NAME}
 	 )
ENDIF(DOXYGEN_FOUND)
