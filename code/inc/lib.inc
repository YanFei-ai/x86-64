; lib.inc
; Copyright (c) 2009-2012 mik 
; All rights reserved.

%ifndef LIB_INC
%define LIB_INC

; ����� lib16 ��ĺ�����ת��ƫ����

%define LIB16_PUTC			0
%define LIB16_PUTS			1
%define LIB16_HEX_TO_CHAR		2
%define LIB16_GET_HEX_STRING		3
%define	LIB16_TEST_CPUID		4
%define LIB16_GET_DWORD_HEX_STRING	5
%define LIB16_PRINTLN			6
%define LIB16_GET_DISPLAYFAMILY_DISPLAYMODEL	7
%define LIB16_CLEAR_SCREEN		8



; ����� lib32 ��ĺ�����ת��ƫ����
%define	LIB32_PUTC			0
%define LIB32_PRINTLN			1
%define LIB32_PUTS			2
%define LIB32_GET_DWORD_HEX_STRING	3
%define LIB32_HEX_TO_CHAR		4
%define LIB32_LOWERS_TO_UPPERS		5
%define LIB32_DUMP_FLAGS		6
%define LIB32_UPPERS_TO_LOWERS		7
%define LIB32_STRLEN			8
%define LIB32_TEST_PRINTLN		9
%define LIB32_REVERSE			10
%define LIB32_GET_BYTE_HEX_STRING	11
%define LIB32_GET_QWORD_HEX_STRING	12
%define LIB32_SUBTRACT64		13
%define LIB32_ADDITION64		14
%define LIB32_PRINT_VALUE		15
%define LIB32_PRINTBLANK		16
%define LIB32_PIRNT_HALF_BYTE_VALUE	17
;* ���������Ǳ���
%define LIB32_XXXX_0                    18
%define LIB32_XXXX_1                    19
%define LIB32_SET_INTERRUPT_HANDLER	20
%define LIB32_SET_IO_BITMAP		21
%define LIB32_GET_MAXPHYADDR		22
%define LIB32_PRINT_BYTE_VALUE		23
%define LIB32_PRINT_WORD_VALUE		24
%define LIB32_PRINT_DWORD_VALUE		25
%define LIB32_PRINT_QWORD_VALUE		26
%define LIB32_SET_CALL_GATE		27
%define LIB32_GET_TSS_BASE		28
%define LIB32_WRITE_GDT_DESCRIPTOR	29
%define LIB32_READ_GDT_DESCRIPTOR	30
%define	LIB32_GET_TR_BASE		31
%define LIB32_SYSTEM_SERVICE		32
%define LIB32_SET_USER_INTERRUPT_HANDLER	33
%define LIB32_SYS_SERVICE_ENTER		34
%define LIB32_SET_SYSENTER		35
%define LIB32_CONFORMING_LIB32_SERVICE	36
%define LIB32_CLIB32_SERVICE_ENTER      37
%define LIB32_SET_LDT_DESCRIPTOR	38
%define LIB32_MOVE_GDT			39
%define LIB32_SET_CLIB32_SERVICE        48
%define LIB32_PRINT_DWORD_DECIMAL	41
%define LIB32_PRINT_DWORD_FLOAT         42
%define LIB32_PRINT_QWORD_FLOAT         43
%define LIB32_PRINT_TWORD_FLOAT         44
%define LIB32_SET_SYSTEM_SERVICE_TABLE  45
%define LIB32_SET_VIDEO_CURRENT         46
%define LIB32_GET_VIDEO_CURRENT         47
%define LIB32_MUL64                     48




;******** long-mode �µ� lib32 ����ú� ************

;*
;* ����Ĵ����� offset ֵ
;*
%define EAX_OFFSET              0
%define ECX_OFFSET              4
%define EDX_OFFSET              8
%define EBX_OFFSET              12
%define ESP_OFFSET              16
%define EBP_OFFSET              20
%define ESI_OFFSET              24
%define EDI_OFFSET              28


%define RAX_OFFSET              0
%define RCX_OFFSET              8
%define RDX_OFFSET              16
%define RBX_OFFSET              24
%define RSP_OFFSET              32
%define RBP_OFFSET              40
%define RSI_OFFSET              48
%define RDI_OFFSET              56
%define R8_OFFSET               64
%define R9_OFFSET               72
%define R10_OFFSET              80
%define R11_OFFSET              88
%define R12_OFFSET              96
%define R13_OFFSET              104
%define R14_OFFSET              112
%define R15_OFFSET              120

%define CONTEXT_POINTER			(debug_context)
%define CONTEXT_POINTER64		(debug_context64)


;* ���� context
;* CONTEXT_POINTER �Ǳ��� context ��Ϣ�Ļ�ַ
;*
%macro STORE_CONTEXT    0
        mov [CONTEXT_POINTER + 0], eax
        mov [CONTEXT_POINTER + 4], ecx
        mov [CONTEXT_POINTER + 8], edx
        mov [CONTEXT_POINTER + 12], ebx
        mov [CONTEXT_POINTER + 16], esp
        mov [CONTEXT_POINTER + 20], ebp
        mov [CONTEXT_POINTER + 24], esi
        mov [CONTEXT_POINTER + 28], edi
%endmacro

; �ָ� context
%macro RESTORE_CONTEXT    0
        mov eax, [CONTEXT_POINTER + 0]
        mov ecx, [CONTEXT_POINTER + 4]
        mov edx, [CONTEXT_POINTER + 8]
        mov ebx, [CONTEXT_POINTER + 12]
        mov esp, [CONTEXT_POINTER + 16]
        mov ebp, [CONTEXT_POINTER + 20]
        mov esi, [CONTEXT_POINTER + 24]
        mov edi, [CONTEXT_POINTER + 28]
%endmacro

;*
;* ���� 64 λ�� context 
;*
%macro STORE_CONTEXT64 0
        mov [CONTEXT_POINTER64 + 0], rax
        mov [CONTEXT_POINTER64 + 8], rcx
        mov [CONTEXT_POINTER64 + 16], rdx
        mov [CONTEXT_POINTER64 + 24], rbx
        mov [CONTEXT_POINTER64 + 32], rsp
        mov [CONTEXT_POINTER64 + 40], rbp
        mov [CONTEXT_POINTER64 + 48], rsi
        mov [CONTEXT_POINTER64 + 56], rdi
	mov [CONTEXT_POINTER64 + 64], r8
	mov [CONTEXT_POINTER64 + 72], r9
	mov [CONTEXT_POINTER64 + 80], r10
	mov [CONTEXT_POINTER64 + 88], r11
	mov [CONTEXT_POINTER64 + 96], r12
	mov [CONTEXT_POINTER64 + 104], r13
	mov [CONTEXT_POINTER64 + 112], r14
	mov [CONTEXT_POINTER64 + 120], r15
%endmacro

; �ָ� 64 λ context
%macro RESTORE_CONTEXT64  0
        mov rax, [CONTEXT_POINTER64 + 0]
        mov rcx, [CONTEXT_POINTER64 + 8]
        mov rdx, [CONTEXT_POINTER64 + 16]
        mov rbx, [CONTEXT_POINTER64 + 24]
        mov rsp, [CONTEXT_POINTER64 + 32]
        mov rbp, [CONTEXT_POINTER64 + 40]
        mov rsi, [CONTEXT_POINTER64 + 48]
        mov rdi, [CONTEXT_POINTER64 + 56]
	mov r8, [CONTEXT_POINTER64 + 64]
	mov r9, [CONTEXT_POINTER64 + 72]
	mov r10, [CONTEXT_POINTER64 + 80]
	mov r11, [CONTEXT_POINTER64 + 88]
	mov r12, [CONTEXT_POINTER64 + 96]
	mov r13, [CONTEXT_POINTER64 + 104]
	mov r14, [CONTEXT_POINTER64 + 112]
	mov r15, [CONTEXT_POINTER64 + 120]
%endmacro






;****************************************************
; ����ĺ궨���� 64-bit ģʽ�µ��� 32 λ lib32 �⺯��
;****************************************************

; putc() ����
%macro LIB32_PUTC_CALL	0
	mov eax, LIB32_PUTC
	call lib32_service
%endmacro

; puts() ����
%macro LIB32_PUTS_CALL	0
	mov eax, LIB32_PUTS
	call lib32_service
%endmacro

; print_dword_value()����
%macro LIB32_PRINT_DWORD_VALUE_CALL	0
	mov eax, LIB32_PRINT_DWORD_VALUE
	call lib32_service
%endmacro

; print_dword_decimal()����
%macro LIB32_PRINT_DWORD_DECIMAL_CALL	0
	mov eax, LIB32_PRINT_DWORD_DECIMAL
	call lib32_service
%endmacro


; print_qword_value() ����
%macro LIB32_PRINT_QWORD_VALUE_CALL	0
	mov eax, LIB32_PRINT_QWORD_VALUE
	call lib32_service
%endmacro

; println()����
%macro LIB32_PRINTLN_CALL	0
	mov eax, LIB32_PRINTLN
	call lib32_service
%endmacro

; printblank()����
%macro LIB32_PRINTBLANK_CALL	0
	mov eax, LIB32_PRINTBLANK
	call lib32_service
%endmacro


; reverse() ����
%macro LIB32_REVERSE_CALL	0
	mov eax, LIB32_REVERSE
	call lib32_service
%endmacro

; dump_flags() ����
%macro LIB32_DUMP_FLAGS_CALL	0
	mov eax, LIB32_DUMP_FLAGS
	call lib32_service
%endmacro


; print_byte_value() ����
%macro LIB32_PRINT_BYTE_VALUE_CALL	0
	mov eax, LIB32_PRINT_BYTE_VALUE
	call lib32_service
%endmacro


; get_MAXPHYADDR() ����
%macro LIB32_GET_MAXPHYADDR_CALL	0
	mov eax, LIB32_GET_MAXPHYADDR
	call lib32_service
%endmacro


%endif