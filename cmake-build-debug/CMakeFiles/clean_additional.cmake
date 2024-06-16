# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/OOP_LCU_2024Spring_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/OOP_LCU_2024Spring_autogen.dir/ParseCache.txt"
  "OOP_LCU_2024Spring_autogen"
  )
endif()
