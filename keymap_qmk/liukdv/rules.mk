LTO_ENABLE = yes
BOOTMAGIC_ENABLE = no         # off, so DF() sticks
EXTRAKEY_ENABLE = yes
NKRO_ENABLE = yes

OLED_ENABLE = yes
OLED_DRIVER = ssd1306
WPM_ENABLE = yes

CONVERT_TO = rp2040_ce

SRC += ./lib/logo_reader.c \
       ./lib/keylogger.c
