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

#MyExecutable
ADD_EXECUTABLE(MyExecutable
	main.cpp
)
TARGET_LINK_LIBRARIES( MyExecutable ${PROJECT_NAME})

#Install binaries
IF(INSTALL_BINARIES)
INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/MyExecutable
	DESTINATION bin
        PERMISSIONS OWNER_READ GROUP_READ WORLD_READ OWNER_WRITE OWNER_EXECUTE)
ENDIF(INSTALL_BINARIES)
