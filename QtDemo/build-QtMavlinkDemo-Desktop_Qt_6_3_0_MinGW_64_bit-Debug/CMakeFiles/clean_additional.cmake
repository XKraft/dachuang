# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\QtMavlinkDemo_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QtMavlinkDemo_autogen.dir\\ParseCache.txt"
  "QtMavlinkDemo_autogen"
  )
endif()
