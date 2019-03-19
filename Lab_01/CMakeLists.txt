set (OUTPUT_FILE_NAME Complex)
set (BACKUP_VERSION 0)
set (COMPILE_FLAGS "-Wall" "-g")
set (DEPENDENCIES "-MMD -MP")
set (LANG_EXT "cpp")
cmake_minimum_required(VERSION 3.7.2)
project(LAB08)

############################################################
# prevent for in-source building
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
set(CMAKE_DISABLE_SOURCE_CHANGES  ON)
if ("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
  message(SEND_ERROR "In-source builds are not allowed.")
endif ()
############################################################

############################################################
include_directories(include)
file(GLOB SOURCES "sources/*.cpp" *.cpp)
add_compile_options (${COMPILE_FLAGS})
add_executable(${OUTPUT_FILE_NAME} ${SOURCES})
add_custom_target (run ./${OUTPUT_FILE_NAME} ${LAB_NUMBER})
add_custom_target (memcheck @valgrind ./${OUTPUT_FILE_NAME})
############################################################

############################################################
# CREATING ARCHIVE
  add_custom_command ( OUTPUT ${OUTPUT_FILE_NAME}_archive
  #DEPENDS ${OUTPUT_FILE_NAME}_archive
  COMMAND mkdir ${OUTPUT_FILE_NAME}_archive
  COMMAND cp -r ../include ../sources ../*.cpp ../CMakeLists.txt ${OUTPUT_FILE_NAME}_archive
  COMMAND tar -czf ../${OUTPUT_FILE_NAME}_lab.tar.gz ${OUTPUT_FILE_NAME}_archive
  COMMAND rm -r ${OUTPUT_FILE_NAME}_archive
)

add_custom_target(pack
  ${CMAKE_COMMAND} -E echo "archive created!"
    DEPENDS ${OUTPUT_FILE_NAME}_archive
    )
############################################################

############################################################
# CREATING BACKUP
add_custom_command (OUTPUT back
  COMMAND tar -czf ../backup.tar.gz  ../include ../sources ../*.cpp 
  #DEPENDS back
)

add_custom_target (backup
    ${CMAKE_COMMAND} -E echo "backup created!"
    DEPENDS back
)
############################################################

############################################################
# RESTORING FROM BACKUP
add_custom_command (OUTPUT returning_files
  COMMAND tar -xzf ../backup.tar.gz -C ../
  #DEPENDS returning_files
)

add_custom_target (restore
    ${CMAKE_COMMAND} -E echo "restoring from backup..."
    DEPENDS returning_files
)
############################################################
# COMMIT A SUICIDE 
add_custom_command (OUTPUT SUICIDING
  COMMAND rm -rf *
 # DEPENDS SUICIDING
)

add_custom_target (suicide
    ${CMAKE_COMMAND} -E echo "goodbye cruel world..."
    DEPENDS SUICIDING
)
############################################################
# PACK INTO ZIP
add_custom_command (OUTPUT ZIPPING
  COMMAND mkdir ${OUTPUT_FILE_NAME}_archive
  COMMAND cp -r ../include ../sources ../*.cpp ../CMakeLists.txt ${OUTPUT_FILE_NAME}_archive
  COMMAND zip -r ../${OUTPUT_FILE_NAME}_lab.zip ${OUTPUT_FILE_NAME}_archive
  COMMAND rm -r ${OUTPUT_FILE_NAME}_archive
 # DEPENDS ZIPPING
)

add_custom_target (zip
    ${CMAKE_COMMAND} -E echo "zip made..."
    DEPENDS ZIPPING
)
############################################################