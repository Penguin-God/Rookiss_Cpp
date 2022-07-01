%include "io64.inc"

section .text
global CMAIN
CMAIN:
    ;write your code here
    
    ; 연습 문제 : 배열의 모든 값 반복문 이용해서 출력하기
     
    xor ecx, ecx
printLoop:
    PRINT_HEX 1, [a+ecx]
    NEWLINE
    inc ecx
    cmp ecx, 5
    jne printLoop
    
         
    xor ecx, ecx
printLoopB:
    PRINT_HEX 2, [b+ecx*2]
    NEWLINE
    inc ecx
    cmp ecx, 5
    jne printLoopB
    
    xor rax, rax
    ret
    
section .data
    a db 0x01, 0x02, 0x03, 0x04, 0x05
    
    b times 5 dw 1 ; 2바이트 짜리 5개 1로 초기값 설정