project(eui CXX ASM)

add_library(eui OBJECT
	include/euiControlBase.h

	src/euiControlBase.cpp
)

target_compile_options(eui PRIVATE -fno-exceptions)
target_compile_options(eui PRIVATE -fno-strict-aliasing)
target_compile_options(eui PRIVATE -Wno-invalid-offsetof)
target_include_directories(eui PUBLIC include/)

if(NOT TARGET agl)
  add_subdirectory(../agl)
endif()
target_link_libraries(eui PUBLIC agl)
