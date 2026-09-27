project(eui CXX ASM)

# see https://github.com/open-ead/nnheaders/blob/master/MIGRATE.md#phase-2-compatibility-gate-of-open-ead-libraries-sead-and-nintendosdk-nex
option(EUI_USE_OLD_NNHEADERS_REPO "Migration setting for the nnsdk and nnware repo split" ON)

add_library(eui OBJECT
    include/euiControlBase.h
    include/message/euiFontMgr.h
    include/message/euiScalableFontMgr.h
    include/sys/euiSharcArchive.h

    src/euiControlBase.cpp
)

target_compile_options(eui PRIVATE -fno-exceptions)
target_compile_options(eui PRIVATE -fno-strict-aliasing)
target_compile_options(eui PRIVATE -Wno-invalid-offsetof)
target_include_directories(eui PUBLIC include/)

if(NOT TARGET sead)
  add_subdirectory(../sead)
endif()
if(NOT TARGET agl)
  add_subdirectory(../agl)
endif()
target_link_libraries(eui PUBLIC agl sead)

if(EUI_USE_OLD_NNHEADERS_REPO)
  # we are supposed to link old SDK here but eui never did,
  # it just depended on other projects to provide the sdk headers
  target_compile_definitions(eui PUBLIC EUI_USE_OLD_NNHEADERS_REPO)
else()
  message(STATUS "Using new nnware repo! Please see https://github.com/open-ead/nnheaders/blob/master/MIGRATE.md")
  message(STATUS "If you do not wish to migrate at this time, put `set(EUI_USE_OLD_NNHEADERS_REPO OFF CACHE BOOL \"Disable nnsdk migration\") in your CMakeLists.txt, or pass -DSEAD_USE_OLD_NNHEADERS_REPO=ON to cmake command")
  if(NOT TARGET nn_font)
    message(FATAL_ERROR "Cannot find NintendoWare. You need to add open-ead/nnware to your project, and put `add_subdirectory(path/to/nnware)` somewhere in your CMakeLists.txt")
  endif()
  target_link_libraries(eui PUBLIC nn_font)
endif()
