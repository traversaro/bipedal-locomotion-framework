# Copyright (C) 2020 Istituto Italiano di Tecnologia (IIT). All rights reserved.
# This software may be modified and distributed under the terms of the
# GNU Lesser General Public License v2.1 or any later version.

include_directories(${CMAKE_CURRENT_BINARY_DIR})
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/ResourceFolderPath.h.in" "${CMAKE_CURRENT_BINARY_DIR}/ResourceFolderPath.h" @ONLY)
add_bipedal_test(
 NAME BareBonesBaseEstimator
 SOURCES FloatingBaseEstimatorTest.cpp
 LINKS BipedalLocomotion::FloatingBaseEstimators BipedalLocomotion::ParametersHandler Eigen3::Eigen iDynTree::idyntree-modelio-urdf)

add_bipedal_test(
 NAME InvariantEKFBaseEstimatorTest
 SOURCES InvariantEKFBaseEstimatorTest.cpp
 LINKS BipedalLocomotion::FloatingBaseEstimators BipedalLocomotion::ParametersHandler Eigen3::Eigen iDynTree::idyntree-modelio-urdf MANIF::manif)

