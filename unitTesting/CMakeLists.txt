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

#TestPass
ADD_EXECUTABLE(TestPass
        TestPass.cpp
)
TARGET_LINK_LIBRARIES( TestPass ${PROJECT_NAME})

ADD_TEST(TestPass TestPass)

#TestFail
ADD_EXECUTABLE(TestFail
        TestFail.cpp
)
TARGET_LINK_LIBRARIES( TestFail ${PROJECT_NAME})

ADD_TEST(TestFail TestFail)
