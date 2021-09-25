;demo.asm
;2021.9.25

;建立一个1.44MB的floppy映像文件，demo.img
;生成命令：nasm demo.asm -o demo.img

;用0填满1.44MB的floppy空间

times 0x168000-($-$$) db 0