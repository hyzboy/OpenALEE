cmake_minimum_required(VERSION 3.0)
SET(CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS TRUE)

project(OpenALEE)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMCMakeModule)

include(math)
include(use_cm_module)

use_cm_module(Core)
use_cm_module(Platform)
use_cm_module(Audio)

set(OPENALEE_RUNTIME_PATH ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(example)

