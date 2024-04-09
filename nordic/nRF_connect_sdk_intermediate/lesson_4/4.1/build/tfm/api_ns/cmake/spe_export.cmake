# Generated by CMake

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 2.5)
   message(FATAL_ERROR "CMake >= 2.6.0 required")
endif()
cmake_policy(PUSH)
cmake_policy(VERSION 2.6...3.19)
#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Protect against multiple inclusion, which would fail when already imported targets are added once more.
set(_targetsDefined)
set(_targetsNotDefined)
set(_expectedTargets)
foreach(_expectedTarget tfm_config psa_crypto_config psa_interface)
  list(APPEND _expectedTargets ${_expectedTarget})
  if(NOT TARGET ${_expectedTarget})
    list(APPEND _targetsNotDefined ${_expectedTarget})
  endif()
  if(TARGET ${_expectedTarget})
    list(APPEND _targetsDefined ${_expectedTarget})
  endif()
endforeach()
if("${_targetsDefined}" STREQUAL "${_expectedTargets}")
  unset(_targetsDefined)
  unset(_targetsNotDefined)
  unset(_expectedTargets)
  set(CMAKE_IMPORT_FILE_VERSION)
  cmake_policy(POP)
  return()
endif()
if(NOT "${_targetsDefined}" STREQUAL "")
  message(FATAL_ERROR "Some (but not all) targets in this export set were already defined.\nTargets Defined: ${_targetsDefined}\nTargets not yet defined: ${_targetsNotDefined}\n")
endif()
unset(_targetsDefined)
unset(_targetsNotDefined)
unset(_expectedTargets)


# The installation prefix configured by this project.
set(_IMPORT_PREFIX "/Users/joaovitor/Documents/VSCode/nordic/nRF_connect_sdk_intermediate/lesson_4/4.1/build/tfm/api_ns")

# Create imported target tfm_config
add_library(tfm_config INTERFACE IMPORTED)

set_target_properties(tfm_config PROPERTIES
  INTERFACE_COMPILE_DEFINITIONS "\$<\$<STREQUAL:,CRYPTO>:PSA_API_TEST_CRYPTO>;\$<\$<STREQUAL:,IPC>:PSA_API_TEST_IPC>;PROJECT_CONFIG_HEADER_FILE=\"/Users/joaovitor/Documents/VSCode/nordic/nRF_connect_sdk_intermediate/lesson_4/4.1/build/modules/nrf/modules/trusted-firmware-m/tfm_config.h\";\$<\$<OR:\$<BOOL:OFF>,\$<BOOL:0>>:CONFIG_TFM_CONNECTION_POOL_ENABLE>;TFM_PARTITION_LOG_LEVEL=TFM_PARTITION_LOG_LEVEL_SILENCE;\$<\$<BOOL:>:TFM_SP_LOG_RAW_ENABLED>;TFM_PARTITION_CRYPTO;TFM_PARTITION_PLATFORM;TFM_PARTITION_NS_AGENT_TZ;\$<\$<STREQUAL:,IPC>:PSA_API_TEST_IPC>;\$<\$<STREQUAL:PSA_ALG_GCM,PSA_ALG_GCM>:PS_CRYPTO_AEAD_ALG_GCM>;\$<\$<STREQUAL:PSA_ALG_GCM,PSA_ALG_CCM>:PS_CRYPTO_AEAD_ALG_CCM>;\$<\$<BOOL:ON>:PS_ENCRYPTION>;CRYPTO_HW_ACCELERATOR"
  INTERFACE_LINK_LIBRARIES "psa_crypto_config"
)

# Create imported target psa_crypto_config
add_library(psa_crypto_config INTERFACE IMPORTED)

# Create imported target psa_interface
add_library(psa_interface INTERFACE IMPORTED)

set_target_properties(psa_interface PROPERTIES
  INTERFACE_COMPILE_DEFINITIONS "\$<\$<BOOL:>:CONFIG_TFM_ENABLE_CTX_MGMT>;\$<\$<BOOL:1>:TFM_ISOLATION_LEVEL=1>;\$<\$<BOOL:ON>:CONFIG_TFM_USE_TRUSTZONE>;\$<\$<BOOL:OFF>:TFM_MULTI_CORE_TOPOLOGY>;\$<\$<BOOL:OFF>:CONFIG_TFM_PARTITION_META>;\$<\$<BOOL:>:TFM_MULTI_CORE_TEST>"
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/interface/include"
  INTERFACE_LINK_LIBRARIES "tfm_config"
)

if(CMAKE_VERSION VERSION_LESS 3.0.0)
  message(FATAL_ERROR "This file relies on consumers using CMake 3.0.0 or greater.")
endif()

# Load information for each installed configuration.
get_filename_component(_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
file(GLOB CONFIG_FILES "${_DIR}/spe_export-*.cmake")
foreach(f ${CONFIG_FILES})
  include(${f})
endforeach()

# Cleanup temporary variables.
set(_IMPORT_PREFIX)

# Loop over all imported files and verify that they actually exist
foreach(target ${_IMPORT_CHECK_TARGETS} )
  foreach(file ${_IMPORT_CHECK_FILES_FOR_${target}} )
    if(NOT EXISTS "${file}" )
      message(FATAL_ERROR "The imported target \"${target}\" references the file
   \"${file}\"
but this file does not exist.  Possible reasons include:
* The file was deleted, renamed, or moved to another location.
* An install or uninstall procedure did not complete successfully.
* The installation package was faulty and contained
   \"${CMAKE_CURRENT_LIST_FILE}\"
but not all the files it references.
")
    endif()
  endforeach()
  unset(_IMPORT_CHECK_FILES_FOR_${target})
endforeach()
unset(_IMPORT_CHECK_TARGETS)

# This file does not depend on other imported targets which have
# been exported from the same project but in a separate export set.

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)
