#-------------------------------------------------
#
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
#
#-------------------------------------------------

#If use Qt
#QT       += core gui svg

unix {
    TARGET = libname

    isEmpty(PREFIX){
        PREFIX = /usr/local/lib/
    }

    target.path = $$PREFIX

    INSTALLS += target
}

win32 {
    TARGET = LibName
}

TEMPLATE = lib

SOURCES += src/my_class.cpp

HEADERS += include/my_class.h

OTHER_FILES += README