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

#TestTrue
ADD_EXECUTABLE(TestTrue
	TestTrue.cpp
)
TARGET_LINK_LIBRARIES( TestTrue -l${PROJECT_NAME})

ADD_TEST(TestTrue TestTrue)

#TestFalse
ADD_EXECUTABLE(TestFalse
	TestFalse.cpp
)
TARGET_LINK_LIBRARIES( TestFalse -l${PROJECT_NAME})

ADD_TEST(TestFalse TestFalse)
