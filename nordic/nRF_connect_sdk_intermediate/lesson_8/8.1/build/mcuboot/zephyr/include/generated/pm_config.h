/* File generated by /opt/nordic/ncs/v2.6.0/nrf/scripts/partition_manager_output.py, do not modify */
#ifndef PM_CONFIG_H__
#define PM_CONFIG_H__
#define PM_MCUBOOT_OFFSET 0x0
#define PM_MCUBOOT_ADDRESS 0x0
#define PM_MCUBOOT_END_ADDRESS 0xc000
#define PM_MCUBOOT_SIZE 0xc000
#define PM_MCUBOOT_NAME mcuboot
#define PM_MCUBOOT_ID 0
#define PM_mcuboot_ID PM_MCUBOOT_ID
#define PM_mcuboot_IS_ENABLED 1
#define PM_0_LABEL MCUBOOT
#define PM_MCUBOOT_DEV flash_controller
#define PM_MCUBOOT_DEFAULT_DRIVER_KCONFIG CONFIG_SOC_FLASH_NRF
#define PM_MCUBOOT_PAD_OFFSET 0xc000
#define PM_MCUBOOT_PAD_ADDRESS 0xc000
#define PM_MCUBOOT_PAD_END_ADDRESS 0xc200
#define PM_MCUBOOT_PAD_SIZE 0x200
#define PM_MCUBOOT_PAD_NAME mcuboot_pad
#define PM_MCUBOOT_PAD_ID 1
#define PM_mcuboot_pad_ID PM_MCUBOOT_PAD_ID
#define PM_mcuboot_pad_IS_ENABLED 1
#define PM_1_LABEL MCUBOOT_PAD
#define PM_MCUBOOT_PAD_DEV flash_controller
#define PM_MCUBOOT_PAD_DEFAULT_DRIVER_KCONFIG CONFIG_SOC_FLASH_NRF
#define PM_MCUBOOT_PRIMARY_OFFSET 0xc000
#define PM_MCUBOOT_PRIMARY_ADDRESS 0xc000
#define PM_MCUBOOT_PRIMARY_END_ADDRESS 0x84000
#define PM_MCUBOOT_PRIMARY_SIZE 0x78000
#define PM_MCUBOOT_PRIMARY_NAME mcuboot_primary
#define PM_MCUBOOT_PRIMARY_ID 2
#define PM_mcuboot_primary_ID PM_MCUBOOT_PRIMARY_ID
#define PM_mcuboot_primary_IS_ENABLED 1
#define PM_2_LABEL MCUBOOT_PRIMARY
#define PM_MCUBOOT_PRIMARY_DEV flash_controller
#define PM_MCUBOOT_PRIMARY_DEFAULT_DRIVER_KCONFIG CONFIG_SOC_FLASH_NRF
#define PM_TFM_SECURE_OFFSET 0xc000
#define PM_TFM_SECURE_ADDRESS 0xc000
#define PM_TFM_SECURE_END_ADDRESS 0x14000
#define PM_TFM_SECURE_SIZE 0x8000
#define PM_TFM_SECURE_NAME tfm_secure
#define PM_TFM_SECURE_ID 3
#define PM_tfm_secure_ID PM_TFM_SECURE_ID
#define PM_tfm_secure_IS_ENABLED 1
#define PM_3_LABEL TFM_SECURE
#define PM_TFM_SECURE_DEV flash_controller
#define PM_TFM_SECURE_DEFAULT_DRIVER_KCONFIG CONFIG_SOC_FLASH_NRF
#define PM_MCUBOOT_PRIMARY_APP_OFFSET 0xc200
#define PM_MCUBOOT_PRIMARY_APP_ADDRESS 0xc200
#define PM_MCUBOOT_PRIMARY_APP_END_ADDRESS 0x84000
#define PM_MCUBOOT_PRIMARY_APP_SIZE 0x77e00
#define PM_MCUBOOT_PRIMARY_APP_NAME mcuboot_primary_app
#define PM_MCUBOOT_PRIMARY_APP_ID 4
#define PM_mcuboot_primary_app_ID PM_MCUBOOT_PRIMARY_APP_ID
#define PM_mcuboot_primary_app_IS_ENABLED 1
#define PM_4_LABEL MCUBOOT_PRIMARY_APP
#define PM_MCUBOOT_PRIMARY_APP_DEV flash_controller
#define PM_MCUBOOT_PRIMARY_APP_DEFAULT_DRIVER_KCONFIG CONFIG_SOC_FLASH_NRF
#define PM_TFM_OFFSET 0xc200
#define PM_TFM_ADDRESS 0xc200
#define PM_TFM_END_ADDRESS 0x14000
#define PM_TFM_SIZE 0x7e00
#define PM_TFM_NAME tfm
#define PM_TFM_ID 5
#define PM_tfm_ID PM_TFM_ID
#define PM_tfm_IS_ENABLED 1
#define PM_5_LABEL TFM
#define PM_TFM_DEV flash_controller
#define PM_TFM_DEFAULT_DRIVER_KCONFIG CONFIG_SOC_FLASH_NRF
#define PM_APP_OFFSET 0x14000
#define PM_APP_ADDRESS 0x14000
#define PM_APP_END_ADDRESS 0x84000
#define PM_APP_SIZE 0x70000
#define PM_APP_NAME app
#define PM_APP_ID 6
#define PM_app_ID PM_APP_ID
#define PM_app_IS_ENABLED 1
#define PM_6_LABEL APP
#define PM_APP_DEV flash_controller
#define PM_APP_DEFAULT_DRIVER_KCONFIG CONFIG_SOC_FLASH_NRF
#define PM_TFM_NONSECURE_OFFSET 0x14000
#define PM_TFM_NONSECURE_ADDRESS 0x14000
#define PM_TFM_NONSECURE_END_ADDRESS 0x84000
#define PM_TFM_NONSECURE_SIZE 0x70000
#define PM_TFM_NONSECURE_NAME tfm_nonsecure
#define PM_TFM_NONSECURE_ID 7
#define PM_tfm_nonsecure_ID PM_TFM_NONSECURE_ID
#define PM_tfm_nonsecure_IS_ENABLED 1
#define PM_7_LABEL TFM_NONSECURE
#define PM_TFM_NONSECURE_DEV flash_controller
#define PM_TFM_NONSECURE_DEFAULT_DRIVER_KCONFIG CONFIG_SOC_FLASH_NRF
#define PM_MCUBOOT_SECONDARY_OFFSET 0x84000
#define PM_MCUBOOT_SECONDARY_ADDRESS 0x84000
#define PM_MCUBOOT_SECONDARY_END_ADDRESS 0xfc000
#define PM_MCUBOOT_SECONDARY_SIZE 0x78000
#define PM_MCUBOOT_SECONDARY_NAME mcuboot_secondary
#define PM_MCUBOOT_SECONDARY_ID 8
#define PM_mcuboot_secondary_ID PM_MCUBOOT_SECONDARY_ID
#define PM_mcuboot_secondary_IS_ENABLED 1
#define PM_8_LABEL MCUBOOT_SECONDARY
#define PM_MCUBOOT_SECONDARY_DEV flash_controller
#define PM_MCUBOOT_SECONDARY_DEFAULT_DRIVER_KCONFIG CONFIG_SOC_FLASH_NRF
#define PM_EMPTY_0_OFFSET 0xfc000
#define PM_EMPTY_0_ADDRESS 0xfc000
#define PM_EMPTY_0_END_ADDRESS 0x100000
#define PM_EMPTY_0_SIZE 0x4000
#define PM_EMPTY_0_NAME EMPTY_0
#define PM_EMPTY_0_ID 9
#define PM_empty_0_ID PM_EMPTY_0_ID
#define PM_empty_0_IS_ENABLED 1
#define PM_9_LABEL EMPTY_0
#define PM_EMPTY_0_DEV flash_controller
#define PM_EMPTY_0_DEFAULT_DRIVER_KCONFIG CONFIG_SOC_FLASH_NRF
#define PM_OTP_OFFSET 0x0
#define PM_OTP_ADDRESS 0xff8100
#define PM_OTP_END_ADDRESS 0xff83fc
#define PM_OTP_SIZE 0x2fc
#define PM_OTP_NAME otp
#define PM_MCUBOOT_SRAM_OFFSET 0x0
#define PM_MCUBOOT_SRAM_ADDRESS 0x20000000
#define PM_MCUBOOT_SRAM_END_ADDRESS 0x20008000
#define PM_MCUBOOT_SRAM_SIZE 0x8000
#define PM_MCUBOOT_SRAM_NAME mcuboot_sram
#define PM_SRAM_SECURE_OFFSET 0x0
#define PM_SRAM_SECURE_ADDRESS 0x20000000
#define PM_SRAM_SECURE_END_ADDRESS 0x20008000
#define PM_SRAM_SECURE_SIZE 0x8000
#define PM_SRAM_SECURE_NAME sram_secure
#define PM_TFM_SRAM_OFFSET 0x0
#define PM_TFM_SRAM_ADDRESS 0x20000000
#define PM_TFM_SRAM_END_ADDRESS 0x20008000
#define PM_TFM_SRAM_SIZE 0x8000
#define PM_TFM_SRAM_NAME tfm_sram
#define PM_SRAM_NONSECURE_OFFSET 0x8000
#define PM_SRAM_NONSECURE_ADDRESS 0x20008000
#define PM_SRAM_NONSECURE_END_ADDRESS 0x20080000
#define PM_SRAM_NONSECURE_SIZE 0x78000
#define PM_SRAM_NONSECURE_NAME sram_nonsecure
#define PM_SRAM_PRIMARY_OFFSET 0x8000
#define PM_SRAM_PRIMARY_ADDRESS 0x20008000
#define PM_SRAM_PRIMARY_END_ADDRESS 0x20070000
#define PM_SRAM_PRIMARY_SIZE 0x68000
#define PM_SRAM_PRIMARY_NAME sram_primary
#define PM_RPMSG_NRF53_SRAM_OFFSET 0x70000
#define PM_RPMSG_NRF53_SRAM_ADDRESS 0x20070000
#define PM_RPMSG_NRF53_SRAM_END_ADDRESS 0x20080000
#define PM_RPMSG_NRF53_SRAM_SIZE 0x10000
#define PM_RPMSG_NRF53_SRAM_NAME rpmsg_nrf53_sram
#define PM_NUM 10
#define PM_ALL_BY_SIZE "mcuboot_pad otp EMPTY_0 tfm tfm_sram mcuboot_sram sram_secure tfm_secure mcuboot rpmsg_nrf53_sram sram_primary app tfm_nonsecure mcuboot_primary_app mcuboot_secondary mcuboot_primary sram_nonsecure"
#define PM_ADDRESS 0x0
#define PM_SIZE 0xc000
#define PM_SRAM_ADDRESS 0x20000000
#define PM_SRAM_SIZE 0x8000
#endif /* PM_CONFIG_H__ */