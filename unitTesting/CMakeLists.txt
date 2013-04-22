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
ADD_EXECUTABLE(TestPass
        TestPass.cpp
)
TARGET_LINK_LIBRARIES( TestPass -l${PROJECT_NAME})

ADD_TEST(TestPass TestPass)

#TestFalse
ADD_EXECUTABLE(TestFail
        TestFail.cpp
)
TARGET_LINK_LIBRARIES( TestFail -l${PROJECT_NAME})

ADD_TEST(TestFail TestFail)
