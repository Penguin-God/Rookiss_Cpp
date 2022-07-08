%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    
    ; cmp dst, src (des가 기준)
    ; 비교를 한 결과는 Flag Register에 저장됨
    
    ; 조건에 따른 코드 흐름을 정할 때 JUMP [label] 시리즈를 사용해서 결정함
    ; JMP : 무조건 점프
    ; JE : JumpEquals 같으면 점프
    ; JNE : JumpNorEquals 다르면 점프
    ; JG : JumpGreater 크면 점프
    ; JGE : JumpGreaterEquals 크거나 같으면 점프
    ; ....등등 이외에도 많이 있음
    
    ; 두 숫자가 같으면 1, 아니면 0을 출력하는 프로그램
    
    mov rax, 20
    mov rbx, 20
    
    cmp rax, rbx
    
    je LABEL_HI
    
    ; 놀라운 상식 : 조건이 일치하면 라벨 안의 코드로 점프를 하는 것이지 조건이 일치할 때만 라벨 안의 코드가 실행되는 것이 아니다.
    mov rcx, 0 ; 이 코드가 실행된다는 뜻은 jump를 하지 않았다는 뜻.
    jmp notEquals ; 근데 조건이 불일치해도 LABEL_HI가 실행됨.
    ; 때문에 기껏 0으로 만든걸 1로 밀어버리지 않게 하기 위해서 그 부분을 무조건 건너뛰도록 하는 코드.
    
LABEL_HI:
    mov rcx, 1
notEquals:
    ;PRINT_HEX 1, rcx
    ;NEWLINE

    ; 연습문제 : 어떤 숫자가 짝수면 1, 홀수면 0을 출력하는 프로그램
    mov ax, 14
    mov bl, 2
    div bl
    
    cmp ah, 0
    je even
    
    mov rcx, 0
    jmp odd
    
even:
    mov rcx, 1
odd:
    PRINT_HEX 1, rcx
    NEWLINE

    
    xor rax, rax
    ret