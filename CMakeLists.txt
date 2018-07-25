#
# Copyright (C) 2015 Cybernetica
#
# Research/Commercial License Usage
# Licensees holding a valid Research License or Commercial License
# for the Software may use this file according to the written
# agreement between you and Cybernetica.
#
# GNU General Public License Usage
# Alternatively, this file may be used under the terms of the GNU
# General Public License version 3.0 as published by the Free Software
# Foundation and appearing in the file LICENSE.GPLv3 included in the
# packaging of this file.  Please review the following information to
# ensure the GNU General Public License version 3.0 requirements will be
# met: http://www.gnu.org/copyleft/gpl-3.0.html.
#
# For further information, please contact us at sharemind@cyber.ee.
#

CMAKE_MINIMUM_REQUIRED(VERSION "3.0")
PROJECT(SharemindFacilityModuleApis VERSION "2.0.0" LANGUAGES NONE)

INCLUDE("${CMAKE_CURRENT_SOURCE_DIR}/config.local" OPTIONAL)
INCLUDE("${CMAKE_CURRENT_BINARY_DIR}/config.local" OPTIONAL)

FIND_PACKAGE(SharemindCMakeHelpers 1.3 REQUIRED)


# API headers:
FILE(GLOB SharemindFacilityModuleApis_HEADERS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
)
INSTALL(FILES ${SharemindFacilityModuleApis_HEADERS}
        DESTINATION "include/sharemind/facility-module-apis"
        COMPONENT "dev")


# Install cmake files:
SharemindCreateCMakeFindFiles(
    INCLUDE_DIRS
        "${CMAKE_INSTALL_PREFIX}/include"
)


# Packaging:
SharemindSetupPackaging()
SharemindAddComponentPackage("dev"
    NAME "sharemind-facility-module-apis-dev"
    DESCRIPTION "Sharemind Facility Module API development headers"
    DEB_SECTION "libdevel"
    DEB_DEPENDS
        "libc6-dev (>= 2.19)"
        "libstdc++-dev"
)
SharemindPackagingFinalize()
