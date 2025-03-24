# Get calib data filenames
file(GLOB_RECURSE calib_files *.xml)
list(SORT calib_files)

# A helper function to rename and process calibration files
function(add_calib_target calib_file)
    # Get calib data file's base name
    get_filename_component(base_name ${calib_file} NAME_WE)

    # Add target to put sensor driver calibration data file into the 'bin' output
    add_custom_target(${base_name}_calib
                      ALL
                      COMMAND ${CMAKE_COMMAND} -E copy ${calib_file} ${LIB_ROOT}/${CMAKE_BUILD_TYPE}/bin/${base_name}.xml
                      DEPENDS ${calib_file}
                      COMMENT "Configuring ${base_name} calibration database"
                      )

    # Add dependencies
    add_dependencies(${module}_shared ${base_name}_calib)

    # Install the sensor driver config with the new name
    install(FILES ${calib_file}
            DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
            RENAME ${base_name}.xml)
endfunction(add_calib_target)

# Loop over all calib data files and apply renaming
foreach(calib_file ${calib_files})
    add_calib_target(${calib_file})
endforeach()
