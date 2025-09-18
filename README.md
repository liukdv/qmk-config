# qmk-config
lily58 qmk config


```cd ~/qmk_firmware```
(or where qmk home is)

qmk config user.keyboard=lily58/rev1
qmk config user.keymap=liukdv\

qmk clean -a
qmk compile

qmk flash
(or copy-paste manually .uf2 file)
