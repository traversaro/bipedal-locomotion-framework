# This software may be modified and distributed under the terms of the
# BSD-3-Clause license.
# Authors: Ines Sorrentino, Lorenzo Moretti

if(FRAMEWORK_COMPILE_MotorCurrentTrackingApplication)

  install(FILES blf-motor-current-tracking.py
    PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
    DESTINATION "${CMAKE_INSTALL_BINDIR}")

  install_ini_files(${CMAKE_CURRENT_SOURCE_DIR}/config)

endif()
