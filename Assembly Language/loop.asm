%include "io64.inc"

section .text
global CMAIN
CMAIN:
    ;write your code here
    
    ; 놀라운 상식 : 반복문은 사실 조건문을 사용해서 만든 거였음
    mov ecx, 10 ; 반복 횟수 카운팅
    
Label_Loop:
    PRINT_STRING "Hello World"
    NEWLINE
    dec ecx ; -1
    cmp ecx, 0
    jne Label_Loop
    

    ; 연습 문제 : 1부터 100까지 더하는 코드    
    xor rbx, rbx ; 좀 있어보이게 0 대입
    xor rax, rax
addLoop:
    inc rbx
    add rax, rbx
    cmp rbx, 100
    jne addLoop

    PRINT_DEC 1, rax
    NEWLINE
    
    ; loop [라벨] : 어셈블리어에도 양심은 있다는 걸 뜻하는 문법
    ; loop사용 전, ecx에 반복 횟수 대입
    ; loop 할때마다 ecx가 1씩 감소, 0이면 빠져나감, 아니면 라벨로 점프
    
    mov ecx, 100
    xor ebx, ebx
sumLoop:
    add ebx, ecx
    loop sumLoop
  
    PRINT_DEC 1, ebx
    NEWLINE
    
    
    xor rax, rax
    ret