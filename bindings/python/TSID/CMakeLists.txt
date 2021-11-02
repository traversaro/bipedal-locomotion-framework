# Copyright (C) 2021 Istituto Italiano di Tecnologia (IIT). All rights reserved.
# This software may be modified and distributed under the terms of the
# GNU Lesser General Public License v2.1 or any later version.

if(FRAMEWORK_COMPILE_TSID)

  set(H_PREFIX include/BipedalLocomotion/bindings/TSID)

  add_bipedal_locomotion_python_module(
    NAME TSIDBindings
    SOURCES src/BaseDynamicsTask.cpp src/CoMTask.cpp src/FeasibleContactWrenchTask.cpp src/JointDynamicsTask.cpp src/JointTrackingTask.cpp src/Module.cpp src/QPTSID.cpp src/SE3Task.cpp src/SO3Task.cpp src/TaskSpaceInverseDynamics.cpp src/TSIDLinearTask.cpp src/VariableRegularizationTask.cpp
    HEADERS ${H_PREFIX}/BaseDynamicsTask.h ${H_PREFIX}/CoMTask.h ${H_PREFIX}/FeasibleContactWrenchTask.h ${H_PREFIX}/JointDynamicsTask.h ${H_PREFIX}/JointTrackingTask.h ${H_PREFIX}/Module.h ${H_PREFIX}/QPTSID.h ${H_PREFIX}/SE3Task.h ${H_PREFIX}/SO3Task.h ${H_PREFIX}/TaskSpaceInverseDynamics.h ${H_PREFIX}/TSIDLinearTask.h ${H_PREFIX}/VariableRegularizationTask.h
    LINK_LIBRARIES BipedalLocomotion::TSID
    TESTS tests/test_TSID.py
    )

endif()