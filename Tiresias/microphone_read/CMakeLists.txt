#
# Copyright (c) 2024 Nordic Semiconductor
#
# SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
#

cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(microphone_read)

target_sources(app PRIVATE 
    src/main.c src/drivers/cs47l63_comm.c 
    ${ZEPHYR_CIRRUS_LOGIC_MODULE_DIR}/cs47l63/cs47l63.c
    ${ZEPHYR_CIRRUS_LOGIC_MODULE_DIR}/common/regmap.c
    ${ZEPHYR_CIRRUS_LOGIC_MODULE_DIR}/cs47l63/generated/cs47l63_syscfg_regs.c
)

# Add the main directory and its subdirectories to the include directories
include_directories(
    /opt/nordic/ncs/v2.6.0/modules/hal/cirrus-logic
    /opt/nordic/ncs/v2.6.0/modules/hal/cirrus-logic/common
    /opt/nordic/ncs/v2.6.0/modules/hal/cirrus-logic/cs47l63
    /opt/nordic/ncs/v2.6.0/modules/hal/cirrus-logic/cs47l63/config
    /opt/nordic/ncs/v2.6.0/modules/hal/cirrus-logic/cs47l63/generated
    # Add more directories as needed
)