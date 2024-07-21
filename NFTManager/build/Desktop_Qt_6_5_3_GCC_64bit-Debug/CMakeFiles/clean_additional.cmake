# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/appNFTManager_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/appNFTManager_autogen.dir/ParseCache.txt"
  "appNFTManager_autogen"
  )
endif()
