# Copyright 2013, MY NAME
#
# This is free software: you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public License
# as published by the Free Software Foundation, either version 3 of
# the License, or (at your option) any later version.
#
# This software is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# General Lesser Public License for more details.  You should have
# received a copy of the GNU Lesser General Public License along with
# software. If not, see <http://www.gnu.org/licenses/>.

#MyExecutable
ADD_EXECUTABLE(MyExecutable
	main.cpp
	../src/my_class.cpp
)
#TARGET_LINK_LIBRARIES( MyExecutable -l<name>)

#Install binaries
IF(INSTALL_BINARIES)
INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/MyExecutable
	DESTINATION ${CMAKE_INSTALL_PREFIX}/bin/
        PERMISSIONS OWNER_READ GROUP_READ WORLD_READ OWNER_WRITE OWNER_EXECUTE)
ENDIF(INSTALL_BINARIES)
