
add_library(simpleLibrary
  Triangle.cpp
  Hailstone.cpp
  Awards.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)

