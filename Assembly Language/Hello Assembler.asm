%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    ;write your code here
    
    PRINT_STRING msg ; : Hello Wotld 출력
    
    ; 오른쪽 값을 왼쪽의 레지스터에 복사
    ; mov reg1, 리터럴
    ; mov reg1, reg2 

    ; 레지스터 <-> 메모리
    ;mov rax, a ; a 변수의 주솟값을 넣음
    ;mov rax, [a] ; a 변수의 값을 a의 주소부터 8바이트만끔 쭉 뽑아서 다 쳐넣음 ㅋㅋ
    ;mov al, [a] ; 마지막 부분만 바꾸기
    
    ;mov rax, 0
    ;mov al, [a] ; 0으로 밀고 넣으면 rax를 a로 밀어버릴 수 있음
    
    ;mov [a], byte 0x55
    ;mov [a], word 0x5566 ; 크기 초과하면 다음 메모리까지 침범해서 바꿔버림. 변수간의 독립성? 그딴거 없음
    ;mov [a], cl
   
    ;add a, b => (a = a + b)
    ;sub //
    ; 메모리끼리의 연산은 안됨
    
    ; mul : 곱하기
    ; mul bl => ax = al * bl
    ; 계산은 al하고 bl에서 하는데 연산 결과는 뜬금없이 ax에다가 저장함
    
    ; div : 나누기
    ; div bl => ax / bl
    ; 연산 결과는 al(몫), ah(나머지)에 각각 저장
    
    xor rax, rax
    ret
    
    ; 초기화 된 데이터
    ; 변수이름, 크기, 초기값
    ; 크기 종류 : db(1), dw(2), dd(4), dq(8)
section .data
    msg db "Hello Assembler", 0x00 ; 0x00은 문자열의 끝을 나타내기 위해 넣음 , 써도 그냥 다음 주소값에 넣음
    a db 0x11
    b dw 0x2222
    c dd 0x33333333
    d dq 0x4444444444444444


    ; 초기화되지 않은 데이터    
    ; 변수이름, 크기, 개수
    ; 크기 종류 : resb(1), resw(2), resd(4), resq(8)
section .bss
    num resb 1

    