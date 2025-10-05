project(eui CXX ASM)

file(GLOB_RECURSE HEADER_FILES "include/*.h")
file(GLOB_RECURSE SRC "src/*.cpp")

add_library(eui OBJECT
	${HEADER_FILES}
	${SRC}
)

target_compile_options(eui PRIVATE -fno-exceptions)
target_compile_options(eui PRIVATE -fno-strict-aliasing)
target_compile_options(eui PRIVATE -Wno-invalid-offsetof)
target_include_directories(eui PUBLIC include/)

if(NOT TARGET agl)
  add_subdirectory(../agl)
endif()
target_link_libraries(eui PUBLIC agl)
if(NOT TARGET sead)
	add_subdirectory(../sead)
endif()

target_link_libraries(eui PUBLIC sead)
