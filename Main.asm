.model flat,c
.code

SpeedTestASM	proc
				push ebp
				mov ebp, esp
				push ebx
				push edi
				push esi

				xor eax, eax
				xor ebx, ebx ;assembly enumrator
				mov edi, [ebp+8] ;edi pointer y
				mov esi, [ebp+12] ;esi pointer x
				mov ecx, [ebp+16] ;n num elements
				
				cmp ecx, 0
				jle InvalidNumber
				shl ecx, 2 ;size of array in bytes contrary to bits

@@:
				mov edx, [esi+ebx] ;[val+emplement]
				imul edx, edx ;x*x
				mov [edi+ebx], edx
				add eax, edx
				add ebx, 4
				cmp ebx, ecx
				jl @B ;@F - B = backward to @@


InvalidNumber:
;ordre important
				pop edi
				pop esi
				pop ebx
				pop ebp

				ret

SpeedTestASM	endp
				end