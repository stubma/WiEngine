GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 1


   1              		.file	"pthread.c"
   2              		.text
   3              		.p2align 4,,15
   4              	.globl _ptw32_processTerminate
   5              		.def	_ptw32_processTerminate;	.scl	2;	.type	32;	.endef
   6              	_ptw32_processTerminate:
   7 0000 55       		pushl	%ebp
   8 0001 89E5     		movl	%esp, %ebp
   9 0003 53       		pushl	%ebx
  10 0004 52       		pushl	%edx
  11 0005 8B150000 		movl	_ptw32_processInitialized, %edx
  11      0000
  12 000b 85D2     		testl	%edx, %edx
  13 000d 0F84A000 		je	L1
  13      0000
  14 0013 A10C0000 		movl	_ptw32_selfThreadKey, %eax
  14      00
  15 0018 85C0     		testl	%eax, %eax
  16 001a 0F85B300 		jne	L11
  16      0000
  17              	L3:
  18 0020 A1100000 		movl	_ptw32_cleanupKey, %eax
  18      00
  19 0025 85C0     		testl	%eax, %eax
  20 0027 0F858B00 		jne	L12
  20      0000
  21              	L4:
  22 002d 83EC0C   		subl	$12, %esp
  23 0030 68000000 		pushl	$_ptw32_thread_reuse_lock
  23      00
  24 0035 E8000000 		call	_EnterCriticalSection@4
  24      00
  25 003a A1040000 		movl	_ptw32_threadReuseTop, %eax
  25      00
  26 003f 83C40C   		addl	$12, %esp
  27 0042 83F801   		cmpl	$1, %eax
  28 0045 7416     		je	L10
  29              		.p2align 4,,7
  30              	L8:
  31 0047 83EC0C   		subl	$12, %esp
  32 004a 8B5810   		movl	16(%eax), %ebx
  33 004d 50       		pushl	%eax
  34 004e E8000000 		call	_free
  34      00
  35 0053 83C410   		addl	$16, %esp
  36 0056 89D8     		movl	%ebx, %eax
  37 0058 83FB01   		cmpl	$1, %ebx
  38 005b 75EA     		jne	L8
  39              	L10:
  40 005d 83EC0C   		subl	$12, %esp
  41 0060 68000000 		pushl	$_ptw32_thread_reuse_lock
  41      00
  42 0065 E8000000 		call	_LeaveCriticalSection@4
  42      00
  43 006a 68000000 		pushl	$_ptw32_spinlock_test_init_lock
  43      00
  44 006f E8000000 		call	_DeleteCriticalSection@4
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 2


  44      00
  45 0074 68000000 		pushl	$_ptw32_rwlock_test_init_lock
  45      00
  46 0079 E8000000 		call	_DeleteCriticalSection@4
  46      00
  47 007e 68000000 		pushl	$_ptw32_cond_test_init_lock
  47      00
  48 0083 E8000000 		call	_DeleteCriticalSection@4
  48      00
  49 0088 68000000 		pushl	$_ptw32_cond_list_lock
  49      00
  50 008d E8000000 		call	_DeleteCriticalSection@4
  50      00
  51 0092 68000000 		pushl	$_ptw32_mutex_test_init_lock
  51      00
  52 0097 E8000000 		call	_DeleteCriticalSection@4
  52      00
  53 009c 68000000 		pushl	$_ptw32_thread_reuse_lock
  53      00
  54 00a1 E8000000 		call	_DeleteCriticalSection@4
  54      00
  55 00a6 83C40C   		addl	$12, %esp
  56 00a9 C7050000 		movl	$0, _ptw32_processInitialized
  56      00000000 
  56      0000
  57              	L1:
  58 00b3 8B5DFC   		movl	-4(%ebp), %ebx
  59 00b6 C9       		leave
  60 00b7 C3       		ret
  61              	L12:
  62 00b8 83EC0C   		subl	$12, %esp
  63 00bb 50       		pushl	%eax
  64 00bc E8EF4600 		call	_pthread_key_delete
  64      00
  65 00c1 83C410   		addl	$16, %esp
  66 00c4 C7051000 		movl	$0, _ptw32_cleanupKey
  66      00000000 
  66      0000
  67 00ce E95AFFFF 		jmp	L4
  67      FF
  68              	L11:
  69 00d3 83EC0C   		subl	$12, %esp
  70 00d6 50       		pushl	%eax
  71 00d7 E8D44600 		call	_pthread_key_delete
  71      00
  72 00dc 83C410   		addl	$16, %esp
  73 00df C7050C00 		movl	$0, _ptw32_selfThreadKey
  73      00000000 
  73      0000
  74 00e9 E932FFFF 		jmp	L3
  74      FF
  75 00ee 89F6     		.p2align 4,,15
  76              	.globl _ptw32_threadStart@4
  77              		.def	_ptw32_threadStart@4;	.scl	2;	.type	32;	.endef
  78              	_ptw32_threadStart@4:
  79 00f0 55       		pushl	%ebp
  80 00f1 89E5     		movl	%esp, %ebp
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 3


  81 00f3 57       		pushl	%edi
  82 00f4 56       		pushl	%esi
  83 00f5 53       		pushl	%ebx
  84 00f6 83EC18   		subl	$24, %esp
  85 00f9 8B4D08   		movl	8(%ebp), %ecx
  86 00fc 8B19     		movl	(%ecx), %ebx
  87 00fe 8B7908   		movl	8(%ecx), %edi
  88 0101 8B710C   		movl	12(%ecx), %esi
  89 0104 897DEC   		movl	%edi, -20(%ebp)
  90 0107 51       		pushl	%ecx
  91 0108 8975E8   		movl	%esi, -24(%ebp)
  92 010b 895DF0   		movl	%ebx, -16(%ebp)
  93 010e E8000000 		call	_free
  93      00
  94 0113 5E       		popl	%esi
  95 0114 A10C0000 		movl	_ptw32_selfThreadKey, %eax
  95      00
  96 0119 5F       		popl	%edi
  97 011a 53       		pushl	%ebx
  98 011b 50       		pushl	%eax
  99 011c E86F4700 		call	_pthread_setspecific
  99      00
 100 0121 8B55F0   		movl	-16(%ebp), %edx
 101 0124 C7421401 		movl	$1, 20(%edx)
 101      000000
 102 012b 83C240   		addl	$64, %edx
 103 012e 891424   		movl	%edx, (%esp)
 104 0131 E8000000 		call	__setjmp
 104      00
 105 0136 83C410   		addl	$16, %esp
 106 0139 85C0     		testl	%eax, %eax
 107 013b 7433     		je	L22
 108 013d 48       		decl	%eax
 109 013e 7422     		je	L23
 110 0140 8B4DF0   		movl	-16(%ebp), %ecx
 111 0143 83CBFF   		orl	$-1, %ebx
 112 0146 C74118FF 		movl	$-1, 24(%ecx)
 112      FFFFFF
 113              	L15:
 114 014d 83EC0C   		subl	$12, %esp
 115 0150 53       		pushl	%ebx
 116 0151 E8000000 		call	__endthreadex
 116      00
 117 0156 8D65F4   		leal	-12(%ebp), %esp
 118 0159 89D8     		movl	%ebx, %eax
 119 015b 5B       		popl	%ebx
 120 015c 5E       		popl	%esi
 121 015d 5F       		popl	%edi
 122 015e 5D       		popl	%ebp
 123 015f C20400   		ret	$4
 124              		.p2align 4,,7
 125              	L23:
 126 0162 8B45F0   		movl	-16(%ebp), %eax
 127 0165 8B5818   		movl	24(%eax), %ebx
 128 0168 EBE3     		jmp	L15
 129 016a 8DB60000 		.p2align 4,,7
 129      0000
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 4


 130              	L22:
 131 0170 83EC0C   		subl	$12, %esp
 132 0173 8B55E8   		movl	-24(%ebp), %edx
 133 0176 52       		pushl	%edx
 134 0177 FF55EC   		call	*-20(%ebp)
 135 017a 8B5DF0   		movl	-16(%ebp), %ebx
 136 017d 83C410   		addl	$16, %esp
 137 0180 894318   		movl	%eax, 24(%ebx)
 138 0183 89C3     		movl	%eax, %ebx
 139 0185 EBC6     		jmp	L15
 140 0187 89F68DBC 		.p2align 4,,15
 140      27000000 
 140      00
 141              	.globl _ptw32_tkAssocDestroy
 142              		.def	_ptw32_tkAssocDestroy;	.scl	2;	.type	32;	.endef
 143              	_ptw32_tkAssocDestroy:
 144 0190 55       		pushl	%ebp
 145 0191 89E5     		movl	%esp, %ebp
 146 0193 8B5508   		movl	8(%ebp), %edx
 147 0196 85D2     		testl	%edx, %edx
 148 0198 7466     		je	L24
 149 019a 8B4210   		movl	16(%edx), %eax
 150 019d 8B4A08   		movl	8(%edx), %ecx
 151 01a0 85C0     		testl	%eax, %eax
 152 01a2 7403     		je	L26
 153 01a4 894808   		movl	%ecx, 8(%eax)
 154              	L26:
 155 01a7 85C9     		testl	%ecx, %ecx
 156 01a9 7403     		je	L27
 157 01ab 894110   		movl	%eax, 16(%ecx)
 158              	L27:
 159 01ae 8B02     		movl	(%edx), %eax
 160 01b0 39908400 		cmpl	%edx, 132(%eax)
 160      0000
 161 01b6 7440     		je	L33
 162              	L28:
 163 01b8 39908800 		cmpl	%edx, 136(%eax)
 163      0000
 164 01be 7430     		je	L34
 165              	L29:
 166 01c0 8B4214   		movl	20(%edx), %eax
 167 01c3 8B4A0C   		movl	12(%edx), %ecx
 168 01c6 85C0     		testl	%eax, %eax
 169 01c8 7403     		je	L30
 170 01ca 89480C   		movl	%ecx, 12(%eax)
 171              	L30:
 172 01cd 85C9     		testl	%ecx, %ecx
 173 01cf 7403     		je	L31
 174 01d1 894114   		movl	%eax, 20(%ecx)
 175              	L31:
 176 01d4 8B4204   		movl	4(%edx), %eax
 177 01d7 39500C   		cmpl	%edx, 12(%eax)
 178 01da 7409     		je	L35
 179              	L32:
 180 01dc 895508   		movl	%edx, 8(%ebp)
 181 01df 5D       		popl	%ebp
 182 01e0 E9000000 		jmp	_free
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 5


 182      00
 183              		.p2align 4,,7
 184              	L35:
 185 01e5 89480C   		movl	%ecx, 12(%eax)
 186 01e8 EBF2     		jmp	L32
 187 01ea 8DB60000 		.p2align 4,,7
 187      0000
 188              	L34:
 189 01f0 89888800 		movl	%ecx, 136(%eax)
 189      0000
 190 01f6 EBC8     		jmp	L29
 191              		.p2align 4,,7
 192              	L33:
 193 01f8 89888400 		movl	%ecx, 132(%eax)
 193      0000
 194 01fe EBB8     		jmp	L28
 195              		.p2align 4,,7
 196              	L24:
 197 0200 5D       		popl	%ebp
 198 0201 C3       		ret
 199 0202 8DB42600 		.p2align 4,,15
 199      0000008D 
 199      BC270000 
 199      0000
 200              	.globl _ptw32_callUserDestroyRoutines
 201              		.def	_ptw32_callUserDestroyRoutines;	.scl	2;	.type	32;	.endef
 202              	_ptw32_callUserDestroyRoutines:
 203 0210 55       		pushl	%ebp
 204 0211 89E5     		movl	%esp, %ebp
 205 0213 57       		pushl	%edi
 206 0214 56       		pushl	%esi
 207 0215 53       		pushl	%ebx
 208 0216 83EC1C   		subl	$28, %esp
 209 0219 8B4508   		movl	8(%ebp), %eax
 210 021c 85C0     		testl	%eax, %eax
 211 021e 0F843F01 		je	L36
 211      0000
 212 0224 8945E8   		movl	%eax, -24(%ebp)
 213 0227 83C028   		addl	$40, %eax
 214 022a C745EC00 		movl	$0, -20(%ebp)
 214      000000
 215 0231 8945E0   		movl	%eax, -32(%ebp)
 216              	L38:
 217 0234 83EC0C   		subl	$12, %esp
 218 0237 8B5DEC   		movl	-20(%ebp), %ebx
 219 023a 8B45E0   		movl	-32(%ebp), %eax
 220 023d 43       		incl	%ebx
 221 023e 50       		pushl	%eax
 222 023f 895DEC   		movl	%ebx, -20(%ebp)
 223 0242 C745F000 		movl	$0, -16(%ebp)
 223      000000
 224 0249 E8421C00 		call	_pthread_mutex_lock
 224      00
 225 024e 8B4DE8   		movl	-24(%ebp), %ecx
 226 0251 8B918400 		movl	132(%ecx), %edx
 226      0000
 227 0257 89918800 		movl	%edx, 136(%ecx)
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 6


 227      0000
 228 025d 8B55E0   		movl	-32(%ebp), %edx
 229 0260 58       		popl	%eax
 230 0261 52       		pushl	%edx
 231              		.p2align 4,,7
 232              	L51:
 233 0262 E8A91F00 		call	_pthread_mutex_unlock
 233      00
 234              	L52:
 235 0267 83C410   		addl	$16, %esp
 236              	L41:
 237 026a 83EC0C   		subl	$12, %esp
 238 026d 8B7DE0   		movl	-32(%ebp), %edi
 239 0270 57       		pushl	%edi
 240 0271 E81A1C00 		call	_pthread_mutex_lock
 240      00
 241 0276 83C410   		addl	$16, %esp
 242 0279 8B75E8   		movl	-24(%ebp), %esi
 243 027c 8B9E8800 		movl	136(%esi), %ebx
 243      0000
 244 0282 85DB     		testl	%ebx, %ebx
 245 0284 0F84BF00 		je	L50
 245      0000
 246 028a 83EC0C   		subl	$12, %esp
 247 028d 8B4B04   		movl	4(%ebx), %ecx
 248 0290 83C108   		addl	$8, %ecx
 249 0293 51       		pushl	%ecx
 250 0294 E8472000 		call	_pthread_mutex_trylock
 250      00
 251 0299 83C410   		addl	$16, %esp
 252 029c 83F810   		cmpl	$16, %eax
 253 029f 0F848400 		je	L53
 253      0000
 254 02a5 8B75E8   		movl	-24(%ebp), %esi
 255 02a8 8B4B08   		movl	8(%ebx), %ecx
 256 02ab 83EC0C   		subl	$12, %esp
 257 02ae 898E8800 		movl	%ecx, 136(%esi)
 257      0000
 258 02b4 8B7304   		movl	4(%ebx), %esi
 259 02b7 8B3E     		movl	(%esi), %edi
 260 02b9 8B5604   		movl	4(%esi), %edx
 261 02bc 57       		pushl	%edi
 262 02bd 8955E4   		movl	%edx, -28(%ebp)
 263 02c0 E8000000 		call	_TlsGetValue@4
 263      00
 264 02c5 89C7     		movl	%eax, %edi
 265 02c7 C7042400 		movl	$0, (%esp)
 265      000000
 266 02ce 8B0E     		movl	(%esi), %ecx
 267 02d0 51       		pushl	%ecx
 268 02d1 E8000000 		call	_TlsSetValue@8
 268      00
 269 02d6 85FF     		testl	%edi, %edi
 270 02d8 5A       		popl	%edx
 271 02d9 59       		popl	%ecx
 272 02da 7406     		je	L47
 273 02dc 837DEC04 		cmpl	$4, -20(%ebp)
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 7


 274 02e0 7E1E     		jle	L54
 275              	L47:
 276 02e2 83EC0C   		subl	$12, %esp
 277 02e5 8D7E08   		leal	8(%esi), %edi
 278 02e8 53       		pushl	%ebx
 279 02e9 E8A2FEFF 		call	_ptw32_tkAssocDestroy
 279      FF
 280 02ee 8B5DE0   		movl	-32(%ebp), %ebx
 281 02f1 58       		popl	%eax
 282 02f2 53       		pushl	%ebx
 283 02f3 E8181F00 		call	_pthread_mutex_unlock
 283      00
 284 02f8 893C24   		movl	%edi, (%esp)
 285 02fb E962FFFF 		jmp	L51
 285      FF
 286              	L54:
 287 0300 83EC0C   		subl	$12, %esp
 288 0303 8B4DE0   		movl	-32(%ebp), %ecx
 289 0306 51       		pushl	%ecx
 290 0307 E8041F00 		call	_pthread_mutex_unlock
 290      00
 291 030c 8D5608   		leal	8(%esi), %edx
 292 030f 891424   		movl	%edx, (%esp)
 293 0312 E8F91E00 		call	_pthread_mutex_unlock
 293      00
 294 0317 8B5DF0   		movl	-16(%ebp), %ebx
 295 031a 893C24   		movl	%edi, (%esp)
 296 031d 43       		incl	%ebx
 297 031e 895DF0   		movl	%ebx, -16(%ebp)
 298 0321 FF55E4   		call	*-28(%ebp)
 299 0324 E93EFFFF 		jmp	L52
 299      FF
 300              	L53:
 301 0329 83EC0C   		subl	$12, %esp
 302 032c 8B55E0   		movl	-32(%ebp), %edx
 303 032f 52       		pushl	%edx
 304 0330 E8DB1E00 		call	_pthread_mutex_unlock
 304      00
 305 0335 C7042401 		movl	$1, (%esp)
 305      000000
 306 033c E8000000 		call	_Sleep@4
 306      00
 307 0341 83C40C   		addl	$12, %esp
 308 0344 E921FFFF 		jmp	L41
 308      FF
 309              	L50:
 310 0349 83EC0C   		subl	$12, %esp
 311 034c 8B55E0   		movl	-32(%ebp), %edx
 312 034f 52       		pushl	%edx
 313 0350 E8BB1E00 		call	_pthread_mutex_unlock
 313      00
 314 0355 8B75F0   		movl	-16(%ebp), %esi
 315 0358 83C410   		addl	$16, %esp
 316 035b 85F6     		testl	%esi, %esi
 317 035d 0F85D1FE 		jne	L38
 317      FFFF
 318              	L36:
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 8


 319 0363 8D65F4   		leal	-12(%ebp), %esp
 320 0366 5B       		popl	%ebx
 321 0367 5E       		popl	%esi
 322 0368 5F       		popl	%edi
 323 0369 5D       		popl	%ebp
 324 036a C3       		ret
 325 036b 908D7426 		.p2align 4,,15
 325      00
 326              	.globl _ptw32_semwait
 327              		.def	_ptw32_semwait;	.scl	2;	.type	32;	.endef
 328              	_ptw32_semwait:
 329 0370 55       		pushl	%ebp
 330 0371 89E5     		movl	%esp, %ebp
 331 0373 57       		pushl	%edi
 332 0374 56       		pushl	%esi
 333 0375 53       		pushl	%ebx
 334 0376 83EC0C   		subl	$12, %esp
 335 0379 8B5508   		movl	8(%ebp), %edx
 336 037c C745F016 		movl	$22, -16(%ebp)
 336      000000
 337 0383 8B32     		movl	(%edx), %esi
 338 0385 85F6     		testl	%esi, %esi
 339 0387 745B     		je	L57
 340 0389 83EC0C   		subl	$12, %esp
 341 038c 8D7E04   		leal	4(%esi), %edi
 342 038f 57       		pushl	%edi
 343 0390 E8FB1A00 		call	_pthread_mutex_lock
 343      00
 344 0395 83C410   		addl	$16, %esp
 345 0398 85C0     		testl	%eax, %eax
 346 039a 8945F0   		movl	%eax, -16(%ebp)
 347 039d 7417     		je	L64
 348              	L63:
 349 039f E8000000 		call	__errno
 349      00
 350 03a4 83CAFF   		orl	$-1, %edx
 351 03a7 8B4DF0   		movl	-16(%ebp), %ecx
 352 03aa 8908     		movl	%ecx, (%eax)
 353              	L55:
 354 03ac 8D65F4   		leal	-12(%ebp), %esp
 355 03af 89D0     		movl	%edx, %eax
 356 03b1 5B       		popl	%ebx
 357 03b2 5E       		popl	%esi
 358 03b3 5F       		popl	%edi
 359 03b4 5D       		popl	%ebp
 360 03b5 C3       		ret
 361              		.p2align 4,,7
 362              	L64:
 363 03b6 8B1E     		movl	(%esi), %ebx
 364 03b8 83EC0C   		subl	$12, %esp
 365 03bb 4B       		decl	%ebx
 366 03bc 891E     		movl	%ebx, (%esi)
 367 03be 57       		pushl	%edi
 368 03bf E84C1E00 		call	_pthread_mutex_unlock
 368      00
 369 03c4 83C410   		addl	$16, %esp
 370 03c7 85DB     		testl	%ebx, %ebx
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 9


 371 03c9 7804     		js	L65
 372              	L62:
 373 03cb 31D2     		xorl	%edx, %edx
 374 03cd EBDD     		jmp	L55
 375              	L65:
 376 03cf 50       		pushl	%eax
 377 03d0 50       		pushl	%eax
 378 03d1 6AFF     		pushl	$-1
 379 03d3 8B5608   		movl	8(%esi), %edx
 380 03d6 52       		pushl	%edx
 381 03d7 E8000000 		call	_WaitForSingleObject@8
 381      00
 382 03dc 31D2     		xorl	%edx, %edx
 383 03de 5E       		popl	%esi
 384 03df 85C0     		testl	%eax, %eax
 385 03e1 5F       		popl	%edi
 386 03e2 74C8     		je	L55
 387              		.p2align 4,,7
 388              	L57:
 389 03e4 8B45F0   		movl	-16(%ebp), %eax
 390 03e7 85C0     		testl	%eax, %eax
 391 03e9 74E0     		je	L62
 392 03eb EBB2     		jmp	L63
 393 03ed 8D7600   		.p2align 4,,15
 394              	.globl _ptw32_get_exception_services_code
 395              		.def	_ptw32_get_exception_services_code;	.scl	2;	.type	32;	.endef
 396              	_ptw32_get_exception_services_code:
 397 03f0 55       		pushl	%ebp
 398 03f1 31C0     		xorl	%eax, %eax
 399 03f3 89E5     		movl	%esp, %ebp
 400 03f5 5D       		popl	%ebp
 401 03f6 C3       		ret
 402 03f7 89F68DBC 		.p2align 4,,15
 402      27000000 
 402      00
 403              	.globl _pthread_attr_init
 404              		.def	_pthread_attr_init;	.scl	2;	.type	32;	.endef
 405              	_pthread_attr_init:
 406 0400 55       		pushl	%ebp
 407 0401 BA160000 		movl	$22, %edx
 407      00
 408 0406 89E5     		movl	%esp, %ebp
 409 0408 53       		pushl	%ebx
 410 0409 50       		pushl	%eax
 411 040a 8B5D08   		movl	8(%ebp), %ebx
 412 040d 85DB     		testl	%ebx, %ebx
 413 040f 744A     		je	L67
 414 0411 83EC0C   		subl	$12, %esp
 415 0414 6A1C     		pushl	$28
 416 0416 E8000000 		call	_malloc
 416      00
 417 041b BA0C0000 		movl	$12, %edx
 417      00
 418 0420 83C410   		addl	$16, %esp
 419 0423 85C0     		testl	%eax, %eax
 420 0425 7434     		je	L67
 421 0427 C7400800 		movl	$0, 8(%eax)
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 10


 421      000000
 422 042e C7400400 		movl	$0, 4(%eax)
 422      000000
 423 0435 C7400C00 		movl	$0, 12(%eax)
 423      000000
 424 043c C7401000 		movl	$0, 16(%eax)
 424      000000
 425 0443 C7401401 		movl	$1, 20(%eax)
 425      000000
 426 044a C7401801 		movl	$1, 24(%eax)
 426      000000
 427 0451 C700EEFF 		movl	$-993984530, (%eax)
 427      C0C4
 428 0457 8903     		movl	%eax, (%ebx)
 429 0459 31D2     		xorl	%edx, %edx
 430              	L67:
 431 045b 8B5DFC   		movl	-4(%ebp), %ebx
 432 045e 89D0     		movl	%edx, %eax
 433 0460 89EC     		movl	%ebp, %esp
 434 0462 5D       		popl	%ebp
 435 0463 C3       		ret
 436 0464 8DB60000 		.p2align 4,,15
 436      00008DBF 
 436      00000000 
 437              	.globl _pthread_attr_destroy
 438              		.def	_pthread_attr_destroy;	.scl	2;	.type	32;	.endef
 439              	_pthread_attr_destroy:
 440 0470 55       		pushl	%ebp
 441 0471 31D2     		xorl	%edx, %edx
 442 0473 89E5     		movl	%esp, %ebp
 443 0475 53       		pushl	%ebx
 444 0476 50       		pushl	%eax
 445 0477 8B5D08   		movl	8(%ebp), %ebx
 446 047a 85DB     		testl	%ebx, %ebx
 447 047c 740E     		je	L73
 448 047e 8B03     		movl	(%ebx), %eax
 449 0480 85C0     		testl	%eax, %eax
 450 0482 7408     		je	L73
 451 0484 8138EEFF 		cmpl	$-993984530, (%eax)
 451      C0C4
 452 048a 7405     		je	L74
 453              	L73:
 454 048c BA010000 		movl	$1, %edx
 454      00
 455              	L74:
 456 0491 B8160000 		movl	$22, %eax
 456      00
 457 0496 85D2     		testl	%edx, %edx
 458 0498 7407     		je	L75
 459              	L70:
 460 049a 8B5DFC   		movl	-4(%ebp), %ebx
 461 049d 89EC     		movl	%ebp, %esp
 462 049f 5D       		popl	%ebp
 463 04a0 C3       		ret
 464              		.p2align 4,,7
 465              	L75:
 466 04a1 8B13     		movl	(%ebx), %edx
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 11


 467 04a3 83EC0C   		subl	$12, %esp
 468 04a6 C7020000 		movl	$0, (%edx)
 468      0000
 469 04ac 52       		pushl	%edx
 470 04ad E8000000 		call	_free
 470      00
 471 04b2 31C0     		xorl	%eax, %eax
 472 04b4 C7030000 		movl	$0, (%ebx)
 472      0000
 473 04ba EBDE     		jmp	L70
 474 04bc 8D742600 		.p2align 4,,15
 475              	.globl _pthread_attr_getdetachstate
 476              		.def	_pthread_attr_getdetachstate;	.scl	2;	.type	32;	.endef
 477              	_pthread_attr_getdetachstate:
 478 04c0 55       		pushl	%ebp
 479 04c1 31C9     		xorl	%ecx, %ecx
 480 04c3 89E5     		movl	%esp, %ebp
 481 04c5 53       		pushl	%ebx
 482 04c6 8B4508   		movl	8(%ebp), %eax
 483 04c9 8B5D0C   		movl	12(%ebp), %ebx
 484 04cc 85C0     		testl	%eax, %eax
 485 04ce 740E     		je	L80
 486 04d0 8B10     		movl	(%eax), %edx
 487 04d2 85D2     		testl	%edx, %edx
 488 04d4 7408     		je	L80
 489 04d6 813AEEFF 		cmpl	$-993984530, (%edx)
 489      C0C4
 490 04dc 7405     		je	L81
 491              	L80:
 492 04de B9010000 		movl	$1, %ecx
 492      00
 493              	L81:
 494 04e3 85C9     		testl	%ecx, %ecx
 495 04e5 7510     		jne	L78
 496 04e7 85DB     		testl	%ebx, %ebx
 497 04e9 740C     		je	L78
 498 04eb 8B08     		movl	(%eax), %ecx
 499 04ed 31C0     		xorl	%eax, %eax
 500 04ef 8B510C   		movl	12(%ecx), %edx
 501 04f2 8913     		movl	%edx, (%ebx)
 502              	L76:
 503 04f4 5B       		popl	%ebx
 504 04f5 5D       		popl	%ebp
 505 04f6 C3       		ret
 506              		.p2align 4,,7
 507              	L78:
 508 04f7 B8160000 		movl	$22, %eax
 508      00
 509 04fc C7030100 		movl	$1, (%ebx)
 509      0000
 510 0502 EBF0     		jmp	L76
 511 0504 8DB60000 		.p2align 4,,15
 511      00008DBF 
 511      00000000 
 512              	.globl _pthread_attr_setdetachstate
 513              		.def	_pthread_attr_setdetachstate;	.scl	2;	.type	32;	.endef
 514              	_pthread_attr_setdetachstate:
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 12


 515 0510 55       		pushl	%ebp
 516 0511 31C9     		xorl	%ecx, %ecx
 517 0513 89E5     		movl	%esp, %ebp
 518 0515 53       		pushl	%ebx
 519 0516 8B4508   		movl	8(%ebp), %eax
 520 0519 8B5D0C   		movl	12(%ebp), %ebx
 521 051c 85C0     		testl	%eax, %eax
 522 051e 740E     		je	L85
 523 0520 8B10     		movl	(%eax), %edx
 524 0522 85D2     		testl	%edx, %edx
 525 0524 7408     		je	L85
 526 0526 813AEEFF 		cmpl	$-993984530, (%edx)
 526      C0C4
 527 052c 7405     		je	L86
 528              	L85:
 529 052e B9010000 		movl	$1, %ecx
 529      00
 530              	L86:
 531 0533 BA160000 		movl	$22, %edx
 531      00
 532 0538 85C9     		testl	%ecx, %ecx
 533 053a 7511     		jne	L82
 534 053c BA160000 		movl	$22, %edx
 534      00
 535 0541 83FB01   		cmpl	$1, %ebx
 536 0544 7707     		ja	L82
 537 0546 8B10     		movl	(%eax), %edx
 538 0548 895A0C   		movl	%ebx, 12(%edx)
 539 054b 31D2     		xorl	%edx, %edx
 540              	L82:
 541 054d 5B       		popl	%ebx
 542 054e 89D0     		movl	%edx, %eax
 543 0550 5D       		popl	%ebp
 544 0551 C3       		ret
 545 0552 8DB42600 		.p2align 4,,15
 545      0000008D 
 545      BC270000 
 545      0000
 546              	.globl _pthread_attr_getstackaddr
 547              		.def	_pthread_attr_getstackaddr;	.scl	2;	.type	32;	.endef
 548              	_pthread_attr_getstackaddr:
 549 0560 55       		pushl	%ebp
 550 0561 89E5     		movl	%esp, %ebp
 551 0563 53       		pushl	%ebx
 552 0564 31DB     		xorl	%ebx, %ebx
 553 0566 8B4D08   		movl	8(%ebp), %ecx
 554 0569 85C9     		testl	%ecx, %ecx
 555 056b 740E     		je	L91
 556 056d 8B11     		movl	(%ecx), %edx
 557 056f 85D2     		testl	%edx, %edx
 558 0571 7408     		je	L91
 559 0573 813AEEFF 		cmpl	$-993984530, (%edx)
 559      C0C4
 560 0579 7405     		je	L92
 561              	L91:
 562 057b BB010000 		movl	$1, %ebx
 562      00
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 13


 563              	L92:
 564 0580 B8160000 		movl	$22, %eax
 564      00
 565 0585 85DB     		testl	%ebx, %ebx
 566 0587 750C     		jne	L88
 567 0589 8B11     		movl	(%ecx), %edx
 568 058b 31C0     		xorl	%eax, %eax
 569 058d 8B4D0C   		movl	12(%ebp), %ecx
 570 0590 8B5A04   		movl	4(%edx), %ebx
 571 0593 8919     		movl	%ebx, (%ecx)
 572              	L88:
 573 0595 5B       		popl	%ebx
 574 0596 5D       		popl	%ebp
 575 0597 C3       		ret
 576 0598 908DB426 		.p2align 4,,15
 576      00000000 
 577              	.globl _pthread_attr_setstackaddr
 578              		.def	_pthread_attr_setstackaddr;	.scl	2;	.type	32;	.endef
 579              	_pthread_attr_setstackaddr:
 580 05a0 55       		pushl	%ebp
 581 05a1 31C9     		xorl	%ecx, %ecx
 582 05a3 89E5     		movl	%esp, %ebp
 583 05a5 8B5508   		movl	8(%ebp), %edx
 584 05a8 85D2     		testl	%edx, %edx
 585 05aa 740E     		je	L96
 586 05ac 8B02     		movl	(%edx), %eax
 587 05ae 85C0     		testl	%eax, %eax
 588 05b0 7408     		je	L96
 589 05b2 8138EEFF 		cmpl	$-993984530, (%eax)
 589      C0C4
 590 05b8 7405     		je	L97
 591              	L96:
 592 05ba B9010000 		movl	$1, %ecx
 592      00
 593              	L97:
 594 05bf B8160000 		movl	$22, %eax
 594      00
 595 05c4 85C9     		testl	%ecx, %ecx
 596 05c6 750A     		jne	L93
 597 05c8 8B0A     		movl	(%edx), %ecx
 598 05ca 8B450C   		movl	12(%ebp), %eax
 599 05cd 894104   		movl	%eax, 4(%ecx)
 600 05d0 31C0     		xorl	%eax, %eax
 601              	L93:
 602 05d2 5D       		popl	%ebp
 603 05d3 C3       		ret
 604 05d4 8DB60000 		.p2align 4,,15
 604      00008DBF 
 604      00000000 
 605              	.globl _pthread_attr_getstacksize
 606              		.def	_pthread_attr_getstacksize;	.scl	2;	.type	32;	.endef
 607              	_pthread_attr_getstacksize:
 608 05e0 55       		pushl	%ebp
 609 05e1 89E5     		movl	%esp, %ebp
 610 05e3 53       		pushl	%ebx
 611 05e4 31DB     		xorl	%ebx, %ebx
 612 05e6 8B4D08   		movl	8(%ebp), %ecx
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 14


 613 05e9 85C9     		testl	%ecx, %ecx
 614 05eb 740E     		je	L101
 615 05ed 8B11     		movl	(%ecx), %edx
 616 05ef 85D2     		testl	%edx, %edx
 617 05f1 7408     		je	L101
 618 05f3 813AEEFF 		cmpl	$-993984530, (%edx)
 618      C0C4
 619 05f9 7405     		je	L102
 620              	L101:
 621 05fb BB010000 		movl	$1, %ebx
 621      00
 622              	L102:
 623 0600 B8160000 		movl	$22, %eax
 623      00
 624 0605 85DB     		testl	%ebx, %ebx
 625 0607 750C     		jne	L98
 626 0609 8B11     		movl	(%ecx), %edx
 627 060b 31C0     		xorl	%eax, %eax
 628 060d 8B4D0C   		movl	12(%ebp), %ecx
 629 0610 8B5A08   		movl	8(%edx), %ebx
 630 0613 8919     		movl	%ebx, (%ecx)
 631              	L98:
 632 0615 5B       		popl	%ebx
 633 0616 5D       		popl	%ebp
 634 0617 C3       		ret
 635 0618 908DB426 		.p2align 4,,15
 635      00000000 
 636              	.globl _pthread_attr_setstacksize
 637              		.def	_pthread_attr_setstacksize;	.scl	2;	.type	32;	.endef
 638              	_pthread_attr_setstacksize:
 639 0620 55       		pushl	%ebp
 640 0621 31C9     		xorl	%ecx, %ecx
 641 0623 89E5     		movl	%esp, %ebp
 642 0625 8B5508   		movl	8(%ebp), %edx
 643 0628 85D2     		testl	%edx, %edx
 644 062a 740E     		je	L106
 645 062c 8B02     		movl	(%edx), %eax
 646 062e 85C0     		testl	%eax, %eax
 647 0630 7408     		je	L106
 648 0632 8138EEFF 		cmpl	$-993984530, (%eax)
 648      C0C4
 649 0638 7405     		je	L107
 650              	L106:
 651 063a B9010000 		movl	$1, %ecx
 651      00
 652              	L107:
 653 063f B8160000 		movl	$22, %eax
 653      00
 654 0644 85C9     		testl	%ecx, %ecx
 655 0646 750A     		jne	L103
 656 0648 8B0A     		movl	(%edx), %ecx
 657 064a 8B450C   		movl	12(%ebp), %eax
 658 064d 894108   		movl	%eax, 8(%ecx)
 659 0650 31C0     		xorl	%eax, %eax
 660              	L103:
 661 0652 5D       		popl	%ebp
 662 0653 C3       		ret
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 15


 663 0654 8DB60000 		.p2align 4,,15
 663      00008DBF 
 663      00000000 
 664              	.globl _pthread_attr_getscope
 665              		.def	_pthread_attr_getscope;	.scl	2;	.type	32;	.endef
 666              	_pthread_attr_getscope:
 667 0660 55       		pushl	%ebp
 668 0661 31C0     		xorl	%eax, %eax
 669 0663 89E5     		movl	%esp, %ebp
 670 0665 8B5508   		movl	8(%ebp), %edx
 671 0668 8B0A     		movl	(%edx), %ecx
 672 066a 8B5118   		movl	24(%ecx), %edx
 673 066d 8B4D0C   		movl	12(%ebp), %ecx
 674 0670 8911     		movl	%edx, (%ecx)
 675 0672 5D       		popl	%ebp
 676 0673 C3       		ret
 677 0674 8DB60000 		.p2align 4,,15
 677      00008DBF 
 677      00000000 
 678              	.globl _pthread_attr_setscope
 679              		.def	_pthread_attr_setscope;	.scl	2;	.type	32;	.endef
 680              	_pthread_attr_setscope:
 681 0680 55       		pushl	%ebp
 682 0681 B8300000 		movl	$48, %eax
 682      00
 683 0686 89E5     		movl	%esp, %ebp
 684 0688 8B550C   		movl	12(%ebp), %edx
 685 068b 85D2     		testl	%edx, %edx
 686 068d 7408     		je	L109
 687 068f 4A       		decl	%edx
 688 0690 740E     		je	L115
 689 0692 B8160000 		movl	$22, %eax
 689      00
 690              	L109:
 691 0697 5D       		popl	%ebp
 692 0698 C3       		ret
 693 0699 8DB42600 		.p2align 4,,7
 693      000000
 694              	L115:
 695 06a0 8B4D08   		movl	8(%ebp), %ecx
 696 06a3 31C0     		xorl	%eax, %eax
 697 06a5 8B11     		movl	(%ecx), %edx
 698 06a7 C7421801 		movl	$1, 24(%edx)
 698      000000
 699 06ae EBE7     		jmp	L109
 700              		.p2align 4,,15
 701              	.globl _pthread_barrier_init
 702              		.def	_pthread_barrier_init;	.scl	2;	.type	32;	.endef
 703              	_pthread_barrier_init:
 704 06b0 55       		pushl	%ebp
 705 06b1 89E5     		movl	%esp, %ebp
 706 06b3 57       		pushl	%edi
 707 06b4 56       		pushl	%esi
 708 06b5 53       		pushl	%ebx
 709 06b6 83EC0C   		subl	$12, %esp
 710 06b9 8B4508   		movl	8(%ebp), %eax
 711 06bc 8B7D0C   		movl	12(%ebp), %edi
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 16


 712 06bf 8B7510   		movl	16(%ebp), %esi
 713 06c2 85C0     		testl	%eax, %eax
 714 06c4 7404     		je	L118
 715 06c6 85F6     		testl	%esi, %esi
 716 06c8 750D     		jne	L117
 717              	L118:
 718 06ca B8160000 		movl	$22, %eax
 718      00
 719              	L116:
 720 06cf 8D65F4   		leal	-12(%ebp), %esp
 721 06d2 5B       		popl	%ebx
 722 06d3 5E       		popl	%esi
 723 06d4 5F       		popl	%edi
 724 06d5 5D       		popl	%ebp
 725 06d6 C3       		ret
 726              		.p2align 4,,7
 727              	L117:
 728 06d7 51       		pushl	%ecx
 729 06d8 51       		pushl	%ecx
 730 06d9 6A18     		pushl	$24
 731 06db 6A01     		pushl	$1
 732 06dd E8000000 		call	_calloc
 732      00
 733 06e2 83C410   		addl	$16, %esp
 734 06e5 89C3     		movl	%eax, %ebx
 735 06e7 85C0     		testl	%eax, %eax
 736 06e9 7467     		je	L119
 737 06eb 85FF     		testl	%edi, %edi
 738 06ed 7471     		je	L120
 739 06ef 8B07     		movl	(%edi), %eax
 740 06f1 85C0     		testl	%eax, %eax
 741 06f3 746B     		je	L120
 742 06f5 8B00     		movl	(%eax), %eax
 743              	L121:
 744 06f7 897304   		movl	%esi, 4(%ebx)
 745 06fa 52       		pushl	%edx
 746 06fb 8933     		movl	%esi, (%ebx)
 747 06fd 6A00     		pushl	$0
 748 06ff 8D7310   		leal	16(%ebx), %esi
 749 0702 50       		pushl	%eax
 750 0703 89430C   		movl	%eax, 12(%ebx)
 751 0706 56       		pushl	%esi
 752 0707 C7430800 		movl	$0, 8(%ebx)
 752      000000
 753 070e E8BD3300 		call	_sem_init
 753      00
 754 0713 83C410   		addl	$16, %esp
 755 0716 85C0     		testl	%eax, %eax
 756 0718 752C     		jne	L122
 757 071a 8B4B0C   		movl	12(%ebx), %ecx
 758 071d 50       		pushl	%eax
 759 071e 8D5314   		leal	20(%ebx), %edx
 760 0721 6A00     		pushl	$0
 761 0723 51       		pushl	%ecx
 762 0724 52       		pushl	%edx
 763 0725 E8A63300 		call	_sem_init
 763      00
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 17


 764 072a 83C410   		addl	$16, %esp
 765 072d 85C0     		testl	%eax, %eax
 766 072f 7509     		jne	L123
 767 0731 8B7508   		movl	8(%ebp), %esi
 768 0734 31C0     		xorl	%eax, %eax
 769 0736 891E     		movl	%ebx, (%esi)
 770 0738 EB95     		jmp	L116
 771              	L123:
 772 073a 83EC0C   		subl	$12, %esp
 773 073d 56       		pushl	%esi
 774 073e E85D3400 		call	_sem_destroy
 774      00
 775 0743 83C410   		addl	$16, %esp
 776              	L122:
 777 0746 83EC0C   		subl	$12, %esp
 778 0749 53       		pushl	%ebx
 779 074a E8000000 		call	_free
 779      00
 780 074f 83C410   		addl	$16, %esp
 781              	L119:
 782 0752 B80C0000 		movl	$12, %eax
 782      00
 783 0757 E973FFFF 		jmp	L116
 783      FF
 784 075c 8D742600 		.p2align 4,,7
 785              	L120:
 786 0760 31C0     		xorl	%eax, %eax
 787 0762 EB93     		jmp	L121
 788 0764 8DB60000 		.p2align 4,,15
 788      00008DBF 
 788      00000000 
 789              	.globl _pthread_barrier_destroy
 790              		.def	_pthread_barrier_destroy;	.scl	2;	.type	32;	.endef
 791              	_pthread_barrier_destroy:
 792 0770 55       		pushl	%ebp
 793 0771 89E5     		movl	%esp, %ebp
 794 0773 57       		pushl	%edi
 795 0774 56       		pushl	%esi
 796 0775 53       		pushl	%ebx
 797 0776 83EC0C   		subl	$12, %esp
 798 0779 8B7508   		movl	8(%ebp), %esi
 799 077c 85F6     		testl	%esi, %esi
 800 077e 7406     		je	L126
 801 0780 8B1E     		movl	(%esi), %ebx
 802 0782 85DB     		testl	%ebx, %ebx
 803 0784 750D     		jne	L125
 804              	L126:
 805 0786 B8160000 		movl	$22, %eax
 805      00
 806              	L124:
 807 078b 8D65F4   		leal	-12(%ebp), %esp
 808 078e 5B       		popl	%ebx
 809 078f 5E       		popl	%esi
 810 0790 5F       		popl	%edi
 811 0791 5D       		popl	%ebp
 812 0792 C3       		ret
 813              		.p2align 4,,7
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 18


 814              	L125:
 815 0793 83EC0C   		subl	$12, %esp
 816 0796 8D5310   		leal	16(%ebx), %edx
 817 0799 C7060000 		movl	$0, (%esi)
 817      0000
 818 079f 8955F0   		movl	%edx, -16(%ebp)
 819 07a2 52       		pushl	%edx
 820 07a3 E8F83300 		call	_sem_destroy
 820      00
 821 07a8 83C410   		addl	$16, %esp
 822 07ab 89C7     		movl	%eax, %edi
 823 07ad 85C0     		testl	%eax, %eax
 824 07af 7406     		je	L129
 825              	L127:
 826 07b1 891E     		movl	%ebx, (%esi)
 827 07b3 89F8     		movl	%edi, %eax
 828 07b5 EBD4     		jmp	L124
 829              	L129:
 830 07b7 83EC0C   		subl	$12, %esp
 831 07ba 8D5314   		leal	20(%ebx), %edx
 832 07bd 52       		pushl	%edx
 833 07be E8DD3300 		call	_sem_destroy
 833      00
 834 07c3 83C410   		addl	$16, %esp
 835 07c6 89C7     		movl	%eax, %edi
 836 07c8 85C0     		testl	%eax, %eax
 837 07ca 750D     		jne	L128
 838 07cc 83EC0C   		subl	$12, %esp
 839 07cf 53       		pushl	%ebx
 840 07d0 E8000000 		call	_free
 840      00
 841 07d5 31C0     		xorl	%eax, %eax
 842 07d7 EBB2     		jmp	L124
 843              	L128:
 844 07d9 8B4DF0   		movl	-16(%ebp), %ecx
 845 07dc 50       		pushl	%eax
 846 07dd 6A00     		pushl	$0
 847 07df 8B530C   		movl	12(%ebx), %edx
 848 07e2 52       		pushl	%edx
 849 07e3 51       		pushl	%ecx
 850 07e4 E8E73200 		call	_sem_init
 850      00
 851 07e9 83C410   		addl	$16, %esp
 852 07ec EBC3     		jmp	L127
 853 07ee 89F6     		.p2align 4,,15
 854              	.globl _pthread_barrier_wait
 855              		.def	_pthread_barrier_wait;	.scl	2;	.type	32;	.endef
 856              	_pthread_barrier_wait:
 857 07f0 55       		pushl	%ebp
 858 07f1 89E5     		movl	%esp, %ebp
 859 07f3 56       		pushl	%esi
 860 07f4 53       		pushl	%ebx
 861 07f5 8B4508   		movl	8(%ebp), %eax
 862 07f8 85C0     		testl	%eax, %eax
 863 07fa 7406     		je	L132
 864 07fc 8B18     		movl	(%eax), %ebx
 865 07fe 85DB     		testl	%ebx, %ebx
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 19


 866 0800 750E     		jne	L131
 867              	L132:
 868 0802 B8160000 		movl	$22, %eax
 868      00
 869              	L130:
 870 0807 8D65F8   		leal	-8(%ebp), %esp
 871 080a 5B       		popl	%ebx
 872 080b 5E       		popl	%esi
 873 080c 5D       		popl	%ebp
 874 080d C3       		ret
 875 080e 89F6     		.p2align 4,,7
 876              	L131:
 877 0810 83EC0C   		subl	$12, %esp
 878 0813 8B7308   		movl	8(%ebx), %esi
 879 0816 53       		pushl	%ebx
 880 0817 E8000000 		call	_InterlockedDecrement@4
 880      00
 881 081c 83C40C   		addl	$12, %esp
 882 081f 85C0     		testl	%eax, %eax
 883 0821 7550     		jne	L133
 884 0823 8B4304   		movl	4(%ebx), %eax
 885 0826 8903     		movl	%eax, (%ebx)
 886 0828 83F801   		cmpl	$1, %eax
 887 082b 7733     		ja	L145
 888 082d 31C0     		xorl	%eax, %eax
 889              	L136:
 890 082f 85C0     		testl	%eax, %eax
 891 0831 75D4     		jne	L130
 892 0833 BA010000 		movl	$1, %edx
 892      00
 893 0838 8B0D2400 		movl	_ptw32_smp_system, %ecx
 893      0000
 894 083e 29F2     		subl	%esi, %edx
 895 0840 85C9     		testl	%ecx, %ecx
 896 0842 7414     		je	L140
 897 0844 89F0     		movl	%esi, %eax
 898              	/APP
 899 0846 F0       		lock
 900 0847 0FB15308 		cmpxchgl       %edx,8(%ebx)
 901              	/NO_APP
 902              	L144:
 903 084b 39C6     		cmpl	%eax, %esi
 904 084d 0F95C0   		setne	%al
 905 0850 25FF0000 		andl	$255, %eax
 905      00
 906 0855 48       		decl	%eax
 907 0856 EBAF     		jmp	L130
 908              	L140:
 909 0858 89F0     		movl	%esi, %eax
 910              	/APP
 911 085a 0FB15308 		cmpxchgl       %edx,8(%ebx)
 912              	/NO_APP
 913 085e EBEB     		jmp	L144
 914              	L145:
 915 0860 48       		decl	%eax
 916 0861 52       		pushl	%edx
 917 0862 52       		pushl	%edx
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 20


 918 0863 8D54B310 		leal	16(%ebx,%esi,4), %edx
 919 0867 50       		pushl	%eax
 920 0868 52       		pushl	%edx
 921 0869 E8123700 		call	_sem_post_multiple
 921      00
 922              	L143:
 923 086e 83C410   		addl	$16, %esp
 924 0871 EBBC     		jmp	L136
 925              	L133:
 926 0873 83EC0C   		subl	$12, %esp
 927 0876 8D54B310 		leal	16(%ebx,%esi,4), %edx
 928 087a 52       		pushl	%edx
 929 087b E8F0FAFF 		call	_ptw32_semwait
 929      FF
 930 0880 EBEC     		jmp	L143
 931 0882 8DB42600 		.p2align 4,,15
 931      0000008D 
 931      BC270000 
 931      0000
 932              	.globl _pthread_barrierattr_init
 933              		.def	_pthread_barrierattr_init;	.scl	2;	.type	32;	.endef
 934              	_pthread_barrierattr_init:
 935 0890 55       		pushl	%ebp
 936 0891 89E5     		movl	%esp, %ebp
 937 0893 53       		pushl	%ebx
 938 0894 83EC0C   		subl	$12, %esp
 939 0897 31DB     		xorl	%ebx, %ebx
 940 0899 6A04     		pushl	$4
 941 089b 6A01     		pushl	$1
 942 089d E8000000 		call	_calloc
 942      00
 943 08a2 83C410   		addl	$16, %esp
 944 08a5 89C2     		movl	%eax, %edx
 945 08a7 85C0     		testl	%eax, %eax
 946 08a9 7415     		je	L149
 947 08ab C7000000 		movl	$0, (%eax)
 947      0000
 948              	L148:
 949 08b1 8B4D08   		movl	8(%ebp), %ecx
 950 08b4 89D8     		movl	%ebx, %eax
 951 08b6 8911     		movl	%edx, (%ecx)
 952 08b8 8B5DFC   		movl	-4(%ebp), %ebx
 953 08bb 89EC     		movl	%ebp, %esp
 954 08bd 5D       		popl	%ebp
 955 08be C3       		ret
 956 08bf 90       		.p2align 4,,7
 957              	L149:
 958 08c0 BB0C0000 		movl	$12, %ebx
 958      00
 959 08c5 EBEA     		jmp	L148
 960 08c7 89F68DBC 		.p2align 4,,15
 960      27000000 
 960      00
 961              	.globl _pthread_barrierattr_destroy
 962              		.def	_pthread_barrierattr_destroy;	.scl	2;	.type	32;	.endef
 963              	_pthread_barrierattr_destroy:
 964 08d0 55       		pushl	%ebp
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 21


 965 08d1 89E5     		movl	%esp, %ebp
 966 08d3 53       		pushl	%ebx
 967 08d4 51       		pushl	%ecx
 968 08d5 31DB     		xorl	%ebx, %ebx
 969 08d7 8B4508   		movl	8(%ebp), %eax
 970 08da 85C0     		testl	%eax, %eax
 971 08dc 7406     		je	L152
 972 08de 8B10     		movl	(%eax), %edx
 973 08e0 85D2     		testl	%edx, %edx
 974 08e2 750E     		jne	L151
 975              	L152:
 976 08e4 BB160000 		movl	$22, %ebx
 976      00
 977              	L153:
 978 08e9 89D8     		movl	%ebx, %eax
 979 08eb 8B5DFC   		movl	-4(%ebp), %ebx
 980 08ee 89EC     		movl	%ebp, %esp
 981 08f0 5D       		popl	%ebp
 982 08f1 C3       		ret
 983              		.p2align 4,,7
 984              	L151:
 985 08f2 83EC0C   		subl	$12, %esp
 986 08f5 C7000000 		movl	$0, (%eax)
 986      0000
 987 08fb 52       		pushl	%edx
 988 08fc E8000000 		call	_free
 988      00
 989 0901 83C410   		addl	$16, %esp
 990 0904 EBE3     		jmp	L153
 991 0906 8D76008D 		.p2align 4,,15
 991      BC270000 
 991      0000
 992              	.globl _pthread_barrierattr_getpshared
 993              		.def	_pthread_barrierattr_getpshared;	.scl	2;	.type	32;	.endef
 994              	_pthread_barrierattr_getpshared:
 995 0910 55       		pushl	%ebp
 996 0911 89E5     		movl	%esp, %ebp
 997 0913 8B4508   		movl	8(%ebp), %eax
 998 0916 8B550C   		movl	12(%ebp), %edx
 999 0919 85C0     		testl	%eax, %eax
 1000 091b 7413     		je	L155
 1001 091d 8B00     		movl	(%eax), %eax
 1002 091f 85C0     		testl	%eax, %eax
 1003 0921 740D     		je	L155
 1004 0923 85D2     		testl	%edx, %edx
 1005 0925 7409     		je	L155
 1006 0927 8B08     		movl	(%eax), %ecx
 1007 0929 31C0     		xorl	%eax, %eax
 1008 092b 890A     		movl	%ecx, (%edx)
 1009              	L156:
 1010 092d 5D       		popl	%ebp
 1011 092e C3       		ret
 1012 092f 90       		.p2align 4,,7
 1013              	L155:
 1014 0930 B8160000 		movl	$22, %eax
 1014      00
 1015 0935 EBF6     		jmp	L156
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 22


 1016 0937 89F68DBC 		.p2align 4,,15
 1016      27000000 
 1016      00
 1017              	.globl _pthread_barrierattr_setpshared
 1018              		.def	_pthread_barrierattr_setpshared;	.scl	2;	.type	32;	.endef
 1019              	_pthread_barrierattr_setpshared:
 1020 0940 55       		pushl	%ebp
 1021 0941 89E5     		movl	%esp, %ebp
 1022 0943 8B4508   		movl	8(%ebp), %eax
 1023 0946 8B4D0C   		movl	12(%ebp), %ecx
 1024 0949 85C0     		testl	%eax, %eax
 1025 094b 7413     		je	L158
 1026 094d 8B10     		movl	(%eax), %edx
 1027 094f 85D2     		testl	%edx, %edx
 1028 0951 740D     		je	L158
 1029 0953 83F901   		cmpl	$1, %ecx
 1030 0956 7708     		ja	L158
 1031 0958 31C0     		xorl	%eax, %eax
 1032 095a 890A     		movl	%ecx, (%edx)
 1033              	L161:
 1034 095c 5D       		popl	%ebp
 1035 095d C3       		ret
 1036 095e 89F6     		.p2align 4,,7
 1037              	L158:
 1038 0960 B8160000 		movl	$22, %eax
 1038      00
 1039 0965 EBF5     		jmp	L161
 1040 0967 89F68DBC 		.p2align 4,,15
 1040      27000000 
 1040      00
 1041              	.globl _pthread_setcancelstate
 1042              		.def	_pthread_setcancelstate;	.scl	2;	.type	32;	.endef
 1043              	_pthread_setcancelstate:
 1044 0970 55       		pushl	%ebp
 1045 0971 89E5     		movl	%esp, %ebp
 1046 0973 57       		pushl	%edi
 1047 0974 56       		pushl	%esi
 1048 0975 53       		pushl	%ebx
 1049 0976 83EC0C   		subl	$12, %esp
 1050 0979 8B7508   		movl	8(%ebp), %esi
 1051 097c E82F0F00 		call	_pthread_self
 1051      00
 1052 0981 89C3     		movl	%eax, %ebx
 1053 0983 85C0     		testl	%eax, %eax
 1054 0985 7405     		je	L164
 1055 0987 83FE01   		cmpl	$1, %esi
 1056 098a 7614     		jbe	L163
 1057              	L164:
 1058 098c B8160000 		movl	$22, %eax
 1058      00
 1059              	L162:
 1060 0991 8D65F4   		leal	-12(%ebp), %esp
 1061 0994 5B       		popl	%ebx
 1062 0995 5E       		popl	%esi
 1063 0996 5F       		popl	%edi
 1064 0997 5D       		popl	%ebp
 1065 0998 C3       		ret
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 23


 1066 0999 8DB42600 		.p2align 4,,7
 1066      000000
 1067              	L163:
 1068 09a0 83EC0C   		subl	$12, %esp
 1069 09a3 8D7830   		leal	48(%eax), %edi
 1070 09a6 57       		pushl	%edi
 1071 09a7 E8E41400 		call	_pthread_mutex_lock
 1071      00
 1072 09ac 8B550C   		movl	12(%ebp), %edx
 1073 09af 83C410   		addl	$16, %esp
 1074 09b2 85D2     		testl	%edx, %edx
 1075 09b4 7408     		je	L165
 1076 09b6 8B4D0C   		movl	12(%ebp), %ecx
 1077 09b9 8B5334   		movl	52(%ebx), %edx
 1078 09bc 8911     		movl	%edx, (%ecx)
 1079              	L165:
 1080 09be 897334   		movl	%esi, 52(%ebx)
 1081 09c1 85F6     		testl	%esi, %esi
 1082 09c3 7507     		jne	L166
 1083 09c5 8B7338   		movl	56(%ebx), %esi
 1084 09c8 85F6     		testl	%esi, %esi
 1085 09ca 740D     		je	L180
 1086              	L166:
 1087 09cc 83EC0C   		subl	$12, %esp
 1088 09cf 57       		pushl	%edi
 1089 09d0 E83B1800 		call	_pthread_mutex_unlock
 1089      00
 1090 09d5 31C0     		xorl	%eax, %eax
 1091 09d7 EBB8     		jmp	L162
 1092              	L180:
 1093 09d9 50       		pushl	%eax
 1094 09da 50       		pushl	%eax
 1095 09db 6A00     		pushl	$0
 1096 09dd 8B433C   		movl	60(%ebx), %eax
 1097 09e0 50       		pushl	%eax
 1098 09e1 E8000000 		call	_WaitForSingleObject@8
 1098      00
 1099 09e6 5A       		popl	%edx
 1100 09e7 85C0     		testl	%eax, %eax
 1101 09e9 59       		popl	%ecx
 1102 09ea 75E0     		jne	L166
 1103 09ec 83EC0C   		subl	$12, %esp
 1104 09ef 8B4B3C   		movl	60(%ebx), %ecx
 1105 09f2 C7431404 		movl	$4, 20(%ebx)
 1105      000000
 1106 09f9 C7433401 		movl	$1, 52(%ebx)
 1106      000000
 1107 0a00 51       		pushl	%ecx
 1108 0a01 E8000000 		call	_ResetEvent@4
 1108      00
 1109 0a06 57       		pushl	%edi
 1110 0a07 E8041800 		call	_pthread_mutex_unlock
 1110      00
 1111 0a0c 8B1D0C00 		movl	_ptw32_selfThreadKey, %ebx
 1111      0000
 1112 0a12 58       		popl	%eax
 1113 0a13 53       		pushl	%ebx
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 24


 1114 0a14 E8E73F00 		call	_pthread_getspecific
 1114      00
 1115 0a19 83C410   		addl	$16, %esp
 1116 0a1c 89C3     		movl	%eax, %ebx
 1117 0a1e 85C0     		testl	%eax, %eax
 1118 0a20 740D     		je	L169
 1119 0a22 8A908000 		movb	128(%eax), %dl
 1119      0000
 1120 0a28 83E201   		andl	$1, %edx
 1121 0a2b 84D2     		testb	%dl, %dl
 1122 0a2d 740D     		je	L175
 1123              	L169:
 1124 0a2f 83EC0C   		subl	$12, %esp
 1125 0a32 6AFF     		pushl	$-1
 1126 0a34 E8000000 		call	__endthreadex
 1126      00
 1127 0a39 83C410   		addl	$16, %esp
 1128              	L175:
 1129 0a3c 83EC0C   		subl	$12, %esp
 1130 0a3f 6A01     		pushl	$1
 1131 0a41 E86A0300 		call	_ptw32_pop_cleanup
 1131      00
 1132 0a46 83C410   		addl	$16, %esp
 1133 0a49 85C0     		testl	%eax, %eax
 1134 0a4b 75EF     		jne	L175
 1135 0a4d 8D7B40   		leal	64(%ebx), %edi
 1136 0a50 56       		pushl	%esi
 1137 0a51 56       		pushl	%esi
 1138 0a52 6A02     		pushl	$2
 1139 0a54 57       		pushl	%edi
 1140 0a55 E8000000 		call	_longjmp
 1140      00
 1141 0a5a 8DB60000 		.p2align 4,,15
 1141      0000
 1142              	.globl _pthread_setcanceltype
 1143              		.def	_pthread_setcanceltype;	.scl	2;	.type	32;	.endef
 1144              	_pthread_setcanceltype:
 1145 0a60 55       		pushl	%ebp
 1146 0a61 89E5     		movl	%esp, %ebp
 1147 0a63 57       		pushl	%edi
 1148 0a64 56       		pushl	%esi
 1149 0a65 53       		pushl	%ebx
 1150 0a66 83EC0C   		subl	$12, %esp
 1151 0a69 8B7508   		movl	8(%ebp), %esi
 1152 0a6c E83F0E00 		call	_pthread_self
 1152      00
 1153 0a71 89C3     		movl	%eax, %ebx
 1154 0a73 85C0     		testl	%eax, %eax
 1155 0a75 7405     		je	L183
 1156 0a77 83FE01   		cmpl	$1, %esi
 1157 0a7a 7614     		jbe	L182
 1158              	L183:
 1159 0a7c B8160000 		movl	$22, %eax
 1159      00
 1160              	L181:
 1161 0a81 8D65F4   		leal	-12(%ebp), %esp
 1162 0a84 5B       		popl	%ebx
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 25


 1163 0a85 5E       		popl	%esi
 1164 0a86 5F       		popl	%edi
 1165 0a87 5D       		popl	%ebp
 1166 0a88 C3       		ret
 1167 0a89 8DB42600 		.p2align 4,,7
 1167      000000
 1168              	L182:
 1169 0a90 83EC0C   		subl	$12, %esp
 1170 0a93 8D7830   		leal	48(%eax), %edi
 1171 0a96 57       		pushl	%edi
 1172 0a97 E8F41300 		call	_pthread_mutex_lock
 1172      00
 1173 0a9c 8B550C   		movl	12(%ebp), %edx
 1174 0a9f 83C410   		addl	$16, %esp
 1175 0aa2 85D2     		testl	%edx, %edx
 1176 0aa4 7408     		je	L184
 1177 0aa6 8B4D0C   		movl	12(%ebp), %ecx
 1178 0aa9 8B5338   		movl	56(%ebx), %edx
 1179 0aac 8911     		movl	%edx, (%ecx)
 1180              	L184:
 1181 0aae 8B4B34   		movl	52(%ebx), %ecx
 1182 0ab1 897338   		movl	%esi, 56(%ebx)
 1183 0ab4 85C9     		testl	%ecx, %ecx
 1184 0ab6 7504     		jne	L185
 1185 0ab8 85F6     		testl	%esi, %esi
 1186 0aba 740D     		je	L199
 1187              	L185:
 1188 0abc 83EC0C   		subl	$12, %esp
 1189 0abf 57       		pushl	%edi
 1190 0ac0 E84B1700 		call	_pthread_mutex_unlock
 1190      00
 1191 0ac5 31C0     		xorl	%eax, %eax
 1192 0ac7 EBB8     		jmp	L181
 1193              	L199:
 1194 0ac9 50       		pushl	%eax
 1195 0aca 50       		pushl	%eax
 1196 0acb 6A00     		pushl	$0
 1197 0acd 8B733C   		movl	60(%ebx), %esi
 1198 0ad0 56       		pushl	%esi
 1199 0ad1 E8000000 		call	_WaitForSingleObject@8
 1199      00
 1200 0ad6 59       		popl	%ecx
 1201 0ad7 85C0     		testl	%eax, %eax
 1202 0ad9 5E       		popl	%esi
 1203 0ada 75E0     		jne	L185
 1204 0adc 83EC0C   		subl	$12, %esp
 1205 0adf 8B433C   		movl	60(%ebx), %eax
 1206 0ae2 C7431404 		movl	$4, 20(%ebx)
 1206      000000
 1207 0ae9 C7433401 		movl	$1, 52(%ebx)
 1207      000000
 1208 0af0 50       		pushl	%eax
 1209 0af1 E8000000 		call	_ResetEvent@4
 1209      00
 1210 0af6 57       		pushl	%edi
 1211 0af7 E8141700 		call	_pthread_mutex_unlock
 1211      00
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 26


 1212 0afc 8B1D0C00 		movl	_ptw32_selfThreadKey, %ebx
 1212      0000
 1213 0b02 58       		popl	%eax
 1214 0b03 53       		pushl	%ebx
 1215 0b04 E8F73E00 		call	_pthread_getspecific
 1215      00
 1216 0b09 83C410   		addl	$16, %esp
 1217 0b0c 89C3     		movl	%eax, %ebx
 1218 0b0e 85C0     		testl	%eax, %eax
 1219 0b10 740D     		je	L188
 1220 0b12 8A908000 		movb	128(%eax), %dl
 1220      0000
 1221 0b18 83E201   		andl	$1, %edx
 1222 0b1b 84D2     		testb	%dl, %dl
 1223 0b1d 740D     		je	L194
 1224              	L188:
 1225 0b1f 83EC0C   		subl	$12, %esp
 1226 0b22 6AFF     		pushl	$-1
 1227 0b24 E8000000 		call	__endthreadex
 1227      00
 1228 0b29 83C410   		addl	$16, %esp
 1229              	L194:
 1230 0b2c 83EC0C   		subl	$12, %esp
 1231 0b2f 6A01     		pushl	$1
 1232 0b31 E87A0200 		call	_ptw32_pop_cleanup
 1232      00
 1233 0b36 83C410   		addl	$16, %esp
 1234 0b39 85C0     		testl	%eax, %eax
 1235 0b3b 75EF     		jne	L194
 1236 0b3d 8D7B40   		leal	64(%ebx), %edi
 1237 0b40 50       		pushl	%eax
 1238 0b41 50       		pushl	%eax
 1239 0b42 6A02     		pushl	$2
 1240 0b44 57       		pushl	%edi
 1241 0b45 E8000000 		call	_longjmp
 1241      00
 1242 0b4a 8DB60000 		.p2align 4,,15
 1242      0000
 1243              	.globl _pthread_testcancel
 1244              		.def	_pthread_testcancel;	.scl	2;	.type	32;	.endef
 1245              	_pthread_testcancel:
 1246 0b50 55       		pushl	%ebp
 1247 0b51 89E5     		movl	%esp, %ebp
 1248 0b53 56       		pushl	%esi
 1249 0b54 53       		pushl	%ebx
 1250 0b55 E8560D00 		call	_pthread_self
 1250      00
 1251 0b5a 89C3     		movl	%eax, %ebx
 1252 0b5c 85C0     		testl	%eax, %eax
 1253 0b5e 7408     		je	L200
 1254 0b60 8B5014   		movl	20(%eax), %edx
 1255 0b63 83FA03   		cmpl	$3, %edx
 1256 0b66 7408     		je	L217
 1257              	L200:
 1258 0b68 8D65F8   		leal	-8(%ebp), %esp
 1259 0b6b 5B       		popl	%ebx
 1260 0b6c 5E       		popl	%esi
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 27


 1261 0b6d 5D       		popl	%ebp
 1262 0b6e C3       		ret
 1263 0b6f 90       		.p2align 4,,7
 1264              	L217:
 1265 0b70 83EC0C   		subl	$12, %esp
 1266 0b73 8D7330   		leal	48(%ebx), %esi
 1267 0b76 56       		pushl	%esi
 1268 0b77 E8141300 		call	_pthread_mutex_lock
 1268      00
 1269 0b7c 83C410   		addl	$16, %esp
 1270 0b7f 837B3401 		cmpl	$1, 52(%ebx)
 1271 0b83 750B     		jne	L218
 1272 0b85 83EC0C   		subl	$12, %esp
 1273 0b88 56       		pushl	%esi
 1274 0b89 E8821600 		call	_pthread_mutex_unlock
 1274      00
 1275 0b8e EBD8     		jmp	L200
 1276              	L218:
 1277 0b90 83EC0C   		subl	$12, %esp
 1278 0b93 8B433C   		movl	60(%ebx), %eax
 1279 0b96 50       		pushl	%eax
 1280 0b97 E8000000 		call	_ResetEvent@4
 1280      00
 1281 0b9c C7431404 		movl	$4, 20(%ebx)
 1281      000000
 1282 0ba3 56       		pushl	%esi
 1283 0ba4 E8671600 		call	_pthread_mutex_unlock
 1283      00
 1284 0ba9 C7433401 		movl	$1, 52(%ebx)
 1284      000000
 1285 0bb0 893424   		movl	%esi, (%esp)
 1286 0bb3 E8581600 		call	_pthread_mutex_unlock
 1286      00
 1287 0bb8 5A       		popl	%edx
 1288 0bb9 8B150C00 		movl	_ptw32_selfThreadKey, %edx
 1288      0000
 1289 0bbf 52       		pushl	%edx
 1290 0bc0 E83B3E00 		call	_pthread_getspecific
 1290      00
 1291 0bc5 83C410   		addl	$16, %esp
 1292 0bc8 89C3     		movl	%eax, %ebx
 1293 0bca 85C0     		testl	%eax, %eax
 1294 0bcc 740D     		je	L206
 1295 0bce 8A888000 		movb	128(%eax), %cl
 1295      0000
 1296 0bd4 83E101   		andl	$1, %ecx
 1297 0bd7 84C9     		testb	%cl, %cl
 1298 0bd9 740D     		je	L212
 1299              	L206:
 1300 0bdb 83EC0C   		subl	$12, %esp
 1301 0bde 6AFF     		pushl	$-1
 1302 0be0 E8000000 		call	__endthreadex
 1302      00
 1303 0be5 83C410   		addl	$16, %esp
 1304              	L212:
 1305 0be8 83EC0C   		subl	$12, %esp
 1306 0beb 6A01     		pushl	$1
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 28


 1307 0bed E8BE0100 		call	_ptw32_pop_cleanup
 1307      00
 1308 0bf2 83C410   		addl	$16, %esp
 1309 0bf5 85C0     		testl	%eax, %eax
 1310 0bf7 75EF     		jne	L212
 1311 0bf9 8D7340   		leal	64(%ebx), %esi
 1312 0bfc 50       		pushl	%eax
 1313 0bfd 50       		pushl	%eax
 1314 0bfe 6A02     		pushl	$2
 1315 0c00 56       		pushl	%esi
 1316 0c01 E8000000 		call	_longjmp
 1316      00
 1317 0c06 8D76008D 		.p2align 4,,15
 1317      BC270000 
 1317      0000
 1318              	.globl _pthread_cancel
 1319              		.def	_pthread_cancel;	.scl	2;	.type	32;	.endef
 1320              	_pthread_cancel:
 1321 0c10 55       		pushl	%ebp
 1322 0c11 89E5     		movl	%esp, %ebp
 1323 0c13 57       		pushl	%edi
 1324 0c14 56       		pushl	%esi
 1325 0c15 53       		pushl	%ebx
 1326 0c16 83EC10   		subl	$16, %esp
 1327 0c19 8B750C   		movl	12(%ebp), %esi
 1328 0c1c 8B5D08   		movl	8(%ebp), %ebx
 1329 0c1f 6A00     		pushl	$0
 1330 0c21 56       		pushl	%esi
 1331 0c22 53       		pushl	%ebx
 1332 0c23 E8980900 		call	_pthread_kill
 1332      00
 1333 0c28 83C410   		addl	$16, %esp
 1334 0c2b 89C7     		movl	%eax, %edi
 1335 0c2d 85C0     		testl	%eax, %eax
 1336 0c2f 740F     		je	L245
 1337              	L219:
 1338 0c31 8D65F4   		leal	-12(%ebp), %esp
 1339 0c34 5B       		popl	%ebx
 1340 0c35 5E       		popl	%esi
 1341 0c36 5F       		popl	%edi
 1342 0c37 5D       		popl	%ebp
 1343 0c38 C3       		ret
 1344 0c39 8DB42600 		.p2align 4,,7
 1344      000000
 1345              	L245:
 1346 0c40 E86B0C00 		call	_pthread_self
 1346      00
 1347 0c45 89D1     		movl	%edx, %ecx
 1348 0c47 89C2     		movl	%eax, %edx
 1349 0c49 85D2     		testl	%edx, %edx
 1350 0c4b B80C0000 		movl	$12, %eax
 1350      00
 1351 0c50 74DF     		je	L219
 1352 0c52 51       		pushl	%ecx
 1353 0c53 52       		pushl	%edx
 1354 0c54 56       		pushl	%esi
 1355 0c55 8D7330   		leal	48(%ebx), %esi
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 29


 1356 0c58 53       		pushl	%ebx
 1357 0c59 E8120D00 		call	_pthread_equal
 1357      00
 1358 0c5e 893424   		movl	%esi, (%esp)
 1359 0c61 8945F0   		movl	%eax, -16(%ebp)
 1360 0c64 E8271200 		call	_pthread_mutex_lock
 1360      00
 1361 0c69 8B4338   		movl	56(%ebx), %eax
 1362 0c6c 83C410   		addl	$16, %esp
 1363 0c6f 85C0     		testl	%eax, %eax
 1364 0c71 0F85DE00 		jne	L222
 1364      0000
 1365 0c77 8B5334   		movl	52(%ebx), %edx
 1366 0c7a 85D2     		testl	%edx, %edx
 1367 0c7c 0F85D300 		jne	L222
 1367      0000
 1368 0c82 8B4B14   		movl	20(%ebx), %ecx
 1369 0c85 83F903   		cmpl	$3, %ecx
 1370 0c88 0F87C700 		ja	L222
 1370      0000
 1371 0c8e 8B55F0   		movl	-16(%ebp), %edx
 1372 0c91 85D2     		testl	%edx, %edx
 1373 0c93 7566     		jne	L246
 1374 0c95 83EC0C   		subl	$12, %esp
 1375 0c98 8B4B04   		movl	4(%ebx), %ecx
 1376 0c9b 894DEC   		movl	%ecx, -20(%ebp)
 1377 0c9e 51       		pushl	%ecx
 1378 0c9f E8000000 		call	_SuspendThread@4
 1378      00
 1379 0ca4 8B55EC   		movl	-20(%ebp), %edx
 1380 0ca7 C7042400 		movl	$0, (%esp)
 1380      000000
 1381 0cae 52       		pushl	%edx
 1382 0caf E8000000 		call	_WaitForSingleObject@8
 1382      00
 1383 0cb4 5A       		popl	%edx
 1384 0cb5 3D020100 		cmpl	$258, %eax
 1384      00
 1385 0cba 59       		popl	%ecx
 1386 0cbb 7407     		je	L247
 1387              	L239:
 1388 0cbd 89F8     		movl	%edi, %eax
 1389 0cbf E96DFFFF 		jmp	L219
 1389      FF
 1390              	L247:
 1391 0cc4 C7431404 		movl	$4, 20(%ebx)
 1391      000000
 1392 0ccb C7433401 		movl	$1, 52(%ebx)
 1392      000000
 1393 0cd2 50       		pushl	%eax
 1394 0cd3 8B5DEC   		movl	-20(%ebp), %ebx
 1395 0cd6 6A00     		pushl	$0
 1396 0cd8 53       		pushl	%ebx
 1397 0cd9 68205300 		pushl	$_ptw32_cancel_callback@4
 1397      00
 1398 0cde FF152C00 		call	*_ptw32_register_cancelation
 1398      0000
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 30


 1399 0ce4 893424   		movl	%esi, (%esp)
 1400 0ce7 E8241500 		call	_pthread_mutex_unlock
 1400      00
 1401 0cec 58       		popl	%eax
 1402 0ced 8B45EC   		movl	-20(%ebp), %eax
 1403 0cf0 50       		pushl	%eax
 1404 0cf1 E8000000 		call	_ResumeThread@4
 1404      00
 1405 0cf6 83C40C   		addl	$12, %esp
 1406 0cf9 EBC2     		jmp	L239
 1407              	L246:
 1408 0cfb 83EC0C   		subl	$12, %esp
 1409 0cfe C7431404 		movl	$4, 20(%ebx)
 1409      000000
 1410 0d05 C7433401 		movl	$1, 52(%ebx)
 1410      000000
 1411 0d0c 56       		pushl	%esi
 1412 0d0d E8FE1400 		call	_pthread_mutex_unlock
 1412      00
 1413 0d12 8B1D0C00 		movl	_ptw32_selfThreadKey, %ebx
 1413      0000
 1414 0d18 58       		popl	%eax
 1415 0d19 53       		pushl	%ebx
 1416 0d1a E8E13C00 		call	_pthread_getspecific
 1416      00
 1417 0d1f 83C410   		addl	$16, %esp
 1418 0d22 89C3     		movl	%eax, %ebx
 1419 0d24 85C0     		testl	%eax, %eax
 1420 0d26 740D     		je	L226
 1421 0d28 8A888000 		movb	128(%eax), %cl
 1421      0000
 1422 0d2e 83E101   		andl	$1, %ecx
 1423 0d31 84C9     		testb	%cl, %cl
 1424 0d33 740D     		je	L232
 1425              	L226:
 1426 0d35 83EC0C   		subl	$12, %esp
 1427 0d38 6AFF     		pushl	$-1
 1428 0d3a E8000000 		call	__endthreadex
 1428      00
 1429 0d3f 83C410   		addl	$16, %esp
 1430              	L232:
 1431 0d42 83EC0C   		subl	$12, %esp
 1432 0d45 6A01     		pushl	$1
 1433 0d47 E8640000 		call	_ptw32_pop_cleanup
 1433      00
 1434 0d4c 83C410   		addl	$16, %esp
 1435 0d4f 85C0     		testl	%eax, %eax
 1436 0d51 75EF     		jne	L232
 1437 0d53 EB42     		jmp	L248
 1438              		.p2align 4,,7
 1439              	L222:
 1440 0d55 8B5314   		movl	20(%ebx), %edx
 1441 0d58 83FA02   		cmpl	$2, %edx
 1442 0d5b 761E     		jbe	L249
 1443 0d5d 8B5314   		movl	20(%ebx), %edx
 1444 0d60 83FA03   		cmpl	$3, %edx
 1445 0d63 7605     		jbe	L242
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 31


 1446              	L244:
 1447 0d65 BF030000 		movl	$3, %edi
 1447      00
 1448              	L242:
 1449 0d6a 83EC0C   		subl	$12, %esp
 1450 0d6d 56       		pushl	%esi
 1451 0d6e E89D1400 		call	_pthread_mutex_unlock
 1451      00
 1452 0d73 83C410   		addl	$16, %esp
 1453 0d76 E942FFFF 		jmp	L239
 1453      FF
 1454              	L249:
 1455 0d7b 83EC0C   		subl	$12, %esp
 1456 0d7e 8B4B3C   		movl	60(%ebx), %ecx
 1457 0d81 C7431403 		movl	$3, 20(%ebx)
 1457      000000
 1458 0d88 51       		pushl	%ecx
 1459 0d89 E8000000 		call	_SetEvent@4
 1459      00
 1460 0d8e 83C40C   		addl	$12, %esp
 1461 0d91 85C0     		testl	%eax, %eax
 1462 0d93 75D5     		jne	L242
 1463 0d95 EBCE     		jmp	L244
 1464              	L248:
 1465 0d97 8D7340   		leal	64(%ebx), %esi
 1466 0d9a 50       		pushl	%eax
 1467 0d9b 50       		pushl	%eax
 1468 0d9c 6A02     		pushl	$2
 1469 0d9e 56       		pushl	%esi
 1470 0d9f E8000000 		call	_longjmp
 1470      00
 1471 0da4 8DB60000 		.p2align 4,,15
 1471      00008DBF 
 1471      00000000 
 1472              	.globl _ptw32_pop_cleanup
 1473              		.def	_ptw32_pop_cleanup;	.scl	2;	.type	32;	.endef
 1474              	_ptw32_pop_cleanup:
 1475 0db0 55       		pushl	%ebp
 1476 0db1 89E5     		movl	%esp, %ebp
 1477 0db3 53       		pushl	%ebx
 1478 0db4 83EC10   		subl	$16, %esp
 1479 0db7 A1100000 		movl	_ptw32_cleanupKey, %eax
 1479      00
 1480 0dbc 50       		pushl	%eax
 1481 0dbd E83E3C00 		call	_pthread_getspecific
 1481      00
 1482 0dc2 83C410   		addl	$16, %esp
 1483 0dc5 89C3     		movl	%eax, %ebx
 1484 0dc7 85C0     		testl	%eax, %eax
 1485 0dc9 7422     		je	L251
 1486 0dcb 8B4508   		movl	8(%ebp), %eax
 1487 0dce 85C0     		testl	%eax, %eax
 1488 0dd0 7406     		je	L252
 1489 0dd2 8B03     		movl	(%ebx), %eax
 1490 0dd4 85C0     		testl	%eax, %eax
 1491 0dd6 751E     		jne	L253
 1492              	L252:
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 32


 1493 0dd8 8B151000 		movl	_ptw32_cleanupKey, %edx
 1493      0000
 1494 0dde 50       		pushl	%eax
 1495 0ddf 50       		pushl	%eax
 1496 0de0 8B4B08   		movl	8(%ebx), %ecx
 1497 0de3 51       		pushl	%ecx
 1498 0de4 52       		pushl	%edx
 1499 0de5 E8A63A00 		call	_pthread_setspecific
 1499      00
 1500 0dea 83C410   		addl	$16, %esp
 1501              	L251:
 1502 0ded 89D8     		movl	%ebx, %eax
 1503 0def 8B5DFC   		movl	-4(%ebp), %ebx
 1504 0df2 89EC     		movl	%ebp, %esp
 1505 0df4 5D       		popl	%ebp
 1506 0df5 C3       		ret
 1507              		.p2align 4,,7
 1508              	L253:
 1509 0df6 83EC0C   		subl	$12, %esp
 1510 0df9 8B4B04   		movl	4(%ebx), %ecx
 1511 0dfc 51       		pushl	%ecx
 1512 0dfd FFD0     		call	*%eax
 1513 0dff 83C410   		addl	$16, %esp
 1514 0e02 EBD4     		jmp	L252
 1515 0e04 8DB60000 		.p2align 4,,15
 1515      00008DBF 
 1515      00000000 
 1516              	.globl _ptw32_push_cleanup
 1517              		.def	_ptw32_push_cleanup;	.scl	2;	.type	32;	.endef
 1518              	_ptw32_push_cleanup:
 1519 0e10 55       		pushl	%ebp
 1520 0e11 89E5     		movl	%esp, %ebp
 1521 0e13 53       		pushl	%ebx
 1522 0e14 83EC10   		subl	$16, %esp
 1523 0e17 8B5D08   		movl	8(%ebp), %ebx
 1524 0e1a 8B550C   		movl	12(%ebp), %edx
 1525 0e1d 8B4D10   		movl	16(%ebp), %ecx
 1526 0e20 8913     		movl	%edx, (%ebx)
 1527 0e22 894B04   		movl	%ecx, 4(%ebx)
 1528 0e25 8B151000 		movl	_ptw32_cleanupKey, %edx
 1528      0000
 1529 0e2b 52       		pushl	%edx
 1530 0e2c E8CF3B00 		call	_pthread_getspecific
 1530      00
 1531 0e31 83C410   		addl	$16, %esp
 1532 0e34 894308   		movl	%eax, 8(%ebx)
 1533 0e37 895D0C   		movl	%ebx, 12(%ebp)
 1534 0e3a 8B151000 		movl	_ptw32_cleanupKey, %edx
 1534      0000
 1535 0e40 8B5DFC   		movl	-4(%ebp), %ebx
 1536 0e43 895508   		movl	%edx, 8(%ebp)
 1537 0e46 89EC     		movl	%ebp, %esp
 1538 0e48 5D       		popl	%ebp
 1539 0e49 E9423A00 		jmp	_pthread_setspecific
 1539      00
 1540 0e4e 89F6     		.p2align 4,,15
 1541              	.globl _pthread_condattr_init
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 33


 1542              		.def	_pthread_condattr_init;	.scl	2;	.type	32;	.endef
 1543              	_pthread_condattr_init:
 1544 0e50 55       		pushl	%ebp
 1545 0e51 89E5     		movl	%esp, %ebp
 1546 0e53 53       		pushl	%ebx
 1547 0e54 83EC0C   		subl	$12, %esp
 1548 0e57 31DB     		xorl	%ebx, %ebx
 1549 0e59 6A04     		pushl	$4
 1550 0e5b 6A01     		pushl	$1
 1551 0e5d E8000000 		call	_calloc
 1551      00
 1552 0e62 83C410   		addl	$16, %esp
 1553 0e65 89C2     		movl	%eax, %edx
 1554 0e67 85C0     		testl	%eax, %eax
 1555 0e69 7415     		je	L257
 1556              	L256:
 1557 0e6b 8B4D08   		movl	8(%ebp), %ecx
 1558 0e6e 89D8     		movl	%ebx, %eax
 1559 0e70 8911     		movl	%edx, (%ecx)
 1560 0e72 8B5DFC   		movl	-4(%ebp), %ebx
 1561 0e75 89EC     		movl	%ebp, %esp
 1562 0e77 5D       		popl	%ebp
 1563 0e78 C3       		ret
 1564 0e79 8DB42600 		.p2align 4,,7
 1564      000000
 1565              	L257:
 1566 0e80 BB0C0000 		movl	$12, %ebx
 1566      00
 1567 0e85 EBE4     		jmp	L256
 1568 0e87 89F68DBC 		.p2align 4,,15
 1568      27000000 
 1568      00
 1569              	.globl _pthread_condattr_destroy
 1570              		.def	_pthread_condattr_destroy;	.scl	2;	.type	32;	.endef
 1571              	_pthread_condattr_destroy:
 1572 0e90 55       		pushl	%ebp
 1573 0e91 89E5     		movl	%esp, %ebp
 1574 0e93 56       		pushl	%esi
 1575 0e94 53       		pushl	%ebx
 1576 0e95 31F6     		xorl	%esi, %esi
 1577 0e97 8B5D08   		movl	8(%ebp), %ebx
 1578 0e9a 85DB     		testl	%ebx, %ebx
 1579 0e9c 7406     		je	L260
 1580 0e9e 8B03     		movl	(%ebx), %eax
 1581 0ea0 85C0     		testl	%eax, %eax
 1582 0ea2 750E     		jne	L259
 1583              	L260:
 1584 0ea4 BE160000 		movl	$22, %esi
 1584      00
 1585              	L261:
 1586 0ea9 8D65F8   		leal	-8(%ebp), %esp
 1587 0eac 89F0     		movl	%esi, %eax
 1588 0eae 5B       		popl	%ebx
 1589 0eaf 5E       		popl	%esi
 1590 0eb0 5D       		popl	%ebp
 1591 0eb1 C3       		ret
 1592              		.p2align 4,,7
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 34


 1593              	L259:
 1594 0eb2 83EC0C   		subl	$12, %esp
 1595 0eb5 50       		pushl	%eax
 1596 0eb6 E8000000 		call	_free
 1596      00
 1597 0ebb 83C410   		addl	$16, %esp
 1598 0ebe C7030000 		movl	$0, (%ebx)
 1598      0000
 1599 0ec4 EBE3     		jmp	L261
 1600 0ec6 8D76008D 		.p2align 4,,15
 1600      BC270000 
 1600      0000
 1601              	.globl _pthread_condattr_getpshared
 1602              		.def	_pthread_condattr_getpshared;	.scl	2;	.type	32;	.endef
 1603              	_pthread_condattr_getpshared:
 1604 0ed0 55       		pushl	%ebp
 1605 0ed1 89E5     		movl	%esp, %ebp
 1606 0ed3 8B4508   		movl	8(%ebp), %eax
 1607 0ed6 8B550C   		movl	12(%ebp), %edx
 1608 0ed9 85C0     		testl	%eax, %eax
 1609 0edb 7413     		je	L263
 1610 0edd 8B00     		movl	(%eax), %eax
 1611 0edf 85C0     		testl	%eax, %eax
 1612 0ee1 740D     		je	L263
 1613 0ee3 85D2     		testl	%edx, %edx
 1614 0ee5 7409     		je	L263
 1615 0ee7 8B08     		movl	(%eax), %ecx
 1616 0ee9 31C0     		xorl	%eax, %eax
 1617 0eeb 890A     		movl	%ecx, (%edx)
 1618              	L264:
 1619 0eed 5D       		popl	%ebp
 1620 0eee C3       		ret
 1621 0eef 90       		.p2align 4,,7
 1622              	L263:
 1623 0ef0 B8160000 		movl	$22, %eax
 1623      00
 1624 0ef5 EBF6     		jmp	L264
 1625 0ef7 89F68DBC 		.p2align 4,,15
 1625      27000000 
 1625      00
 1626              	.globl _pthread_condattr_setpshared
 1627              		.def	_pthread_condattr_setpshared;	.scl	2;	.type	32;	.endef
 1628              	_pthread_condattr_setpshared:
 1629 0f00 55       		pushl	%ebp
 1630 0f01 89E5     		movl	%esp, %ebp
 1631 0f03 8B4508   		movl	8(%ebp), %eax
 1632 0f06 8B4D0C   		movl	12(%ebp), %ecx
 1633 0f09 85C0     		testl	%eax, %eax
 1634 0f0b 7413     		je	L266
 1635 0f0d 8B10     		movl	(%eax), %edx
 1636 0f0f 85D2     		testl	%edx, %edx
 1637 0f11 740D     		je	L266
 1638 0f13 83F901   		cmpl	$1, %ecx
 1639 0f16 7708     		ja	L266
 1640 0f18 31C0     		xorl	%eax, %eax
 1641 0f1a 890A     		movl	%ecx, (%edx)
 1642              	L269:
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 35


 1643 0f1c 5D       		popl	%ebp
 1644 0f1d C3       		ret
 1645 0f1e 89F6     		.p2align 4,,7
 1646              	L266:
 1647 0f20 B8160000 		movl	$22, %eax
 1647      00
 1648 0f25 EBF5     		jmp	L269
 1649 0f27 89F68DBC 		.p2align 4,,15
 1649      27000000 
 1649      00
 1650              	.globl _pthread_cond_init
 1651              		.def	_pthread_cond_init;	.scl	2;	.type	32;	.endef
 1652              	_pthread_cond_init:
 1653 0f30 55       		pushl	%ebp
 1654 0f31 B8160000 		movl	$22, %eax
 1654      00
 1655 0f36 89E5     		movl	%esp, %ebp
 1656 0f38 57       		pushl	%edi
 1657 0f39 56       		pushl	%esi
 1658 0f3a 53       		pushl	%ebx
 1659 0f3b 31DB     		xorl	%ebx, %ebx
 1660 0f3d 83EC0C   		subl	$12, %esp
 1661 0f40 8B7508   		movl	8(%ebp), %esi
 1662 0f43 8B550C   		movl	12(%ebp), %edx
 1663 0f46 85F6     		testl	%esi, %esi
 1664 0f48 0F84C100 		je	L270
 1664      0000
 1665 0f4e 85D2     		testl	%edx, %edx
 1666 0f50 740F     		je	L272
 1667 0f52 8B02     		movl	(%edx), %eax
 1668 0f54 85C0     		testl	%eax, %eax
 1669 0f56 7409     		je	L272
 1670 0f58 833801   		cmpl	$1, (%eax)
 1671 0f5b 0F841101 		je	L285
 1671      0000
 1672              	L272:
 1673 0f61 BE0C0000 		movl	$12, %esi
 1673      00
 1674 0f66 52       		pushl	%edx
 1675 0f67 52       		pushl	%edx
 1676 0f68 6A20     		pushl	$32
 1677 0f6a 6A01     		pushl	$1
 1678 0f6c E8000000 		call	_calloc
 1678      00
 1679 0f71 83C410   		addl	$16, %esp
 1680 0f74 89C3     		movl	%eax, %ebx
 1681 0f76 85C0     		testl	%eax, %eax
 1682 0f78 743E     		je	L273
 1683 0f7a C7000000 		movl	$0, (%eax)
 1683      0000
 1684 0f80 8D7B10   		leal	16(%ebx), %edi
 1685 0f83 C7400800 		movl	$0, 8(%eax)
 1685      000000
 1686 0f8a C7400400 		movl	$0, 4(%eax)
 1686      000000
 1687 0f91 50       		pushl	%eax
 1688 0f92 6A01     		pushl	$1
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 36


 1689 0f94 6A00     		pushl	$0
 1690 0f96 57       		pushl	%edi
 1691 0f97 E8342B00 		call	_sem_init
 1691      00
 1692 0f9c 83C410   		addl	$16, %esp
 1693 0f9f 85C0     		testl	%eax, %eax
 1694 0fa1 7474     		je	L275
 1695 0fa3 E8000000 		call	__errno
 1695      00
 1696 0fa8 8B30     		movl	(%eax), %esi
 1697              	L276:
 1698 0faa 83EC0C   		subl	$12, %esp
 1699 0fad 53       		pushl	%ebx
 1700 0fae 31DB     		xorl	%ebx, %ebx
 1701 0fb0 E8000000 		call	_free
 1701      00
 1702 0fb5 83C410   		addl	$16, %esp
 1703              	L273:
 1704 0fb8 85F6     		testl	%esi, %esi
 1705 0fba 754C     		jne	L281
 1706              	L284:
 1707 0fbc 83EC0C   		subl	$12, %esp
 1708 0fbf 68000000 		pushl	$_ptw32_cond_list_lock
 1708      00
 1709 0fc4 E8000000 		call	_EnterCriticalSection@4
 1709      00
 1710 0fc9 A1180000 		movl	_ptw32_cond_list_tail, %eax
 1710      00
 1711 0fce 83C40C   		addl	$12, %esp
 1712 0fd1 89431C   		movl	%eax, 28(%ebx)
 1713 0fd4 C7431800 		movl	$0, 24(%ebx)
 1713      000000
 1714 0fdb 85C0     		testl	%eax, %eax
 1715 0fdd 7403     		je	L282
 1716 0fdf 895818   		movl	%ebx, 24(%eax)
 1717              	L282:
 1718 0fe2 8B3D1400 		movl	_ptw32_cond_list_head, %edi
 1718      0000
 1719 0fe8 891D1800 		movl	%ebx, _ptw32_cond_list_tail
 1719      0000
 1720 0fee 85FF     		testl	%edi, %edi
 1721 0ff0 7506     		jne	L283
 1722 0ff2 891D1400 		movl	%ebx, _ptw32_cond_list_head
 1722      0000
 1723              	L283:
 1724 0ff8 83EC0C   		subl	$12, %esp
 1725 0ffb 68000000 		pushl	$_ptw32_cond_list_lock
 1725      00
 1726 1000 E8000000 		call	_LeaveCriticalSection@4
 1726      00
 1727 1005 83C40C   		addl	$12, %esp
 1728              	L281:
 1729 1008 8B4D08   		movl	8(%ebp), %ecx
 1730 100b 89F0     		movl	%esi, %eax
 1731 100d 8919     		movl	%ebx, (%ecx)
 1732              	L270:
 1733 100f 8D65F4   		leal	-12(%ebp), %esp
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 37


 1734 1012 5B       		popl	%ebx
 1735 1013 5E       		popl	%esi
 1736 1014 5F       		popl	%edi
 1737 1015 5D       		popl	%ebp
 1738 1016 C3       		ret
 1739              		.p2align 4,,7
 1740              	L275:
 1741 1017 8D530C   		leal	12(%ebx), %edx
 1742 101a 50       		pushl	%eax
 1743 101b 8955F0   		movl	%edx, -16(%ebp)
 1744 101e 6A00     		pushl	$0
 1745 1020 6A00     		pushl	$0
 1746 1022 52       		pushl	%edx
 1747 1023 E8A82A00 		call	_sem_init
 1747      00
 1748 1028 83C410   		addl	$16, %esp
 1749 102b 85C0     		testl	%eax, %eax
 1750 102d 7418     		je	L277
 1751 102f E8000000 		call	__errno
 1751      00
 1752 1034 8B30     		movl	(%eax), %esi
 1753              	L278:
 1754 1036 83EC0C   		subl	$12, %esp
 1755 1039 57       		pushl	%edi
 1756 103a E8612B00 		call	_sem_destroy
 1756      00
 1757 103f 83C410   		addl	$16, %esp
 1758 1042 E963FFFF 		jmp	L276
 1758      FF
 1759              		.p2align 4,,7
 1760              	L277:
 1761 1047 8D4B14   		leal	20(%ebx), %ecx
 1762 104a 50       		pushl	%eax
 1763 104b 50       		pushl	%eax
 1764 104c 6A00     		pushl	$0
 1765 104e 51       		pushl	%ecx
 1766 104f E85C0B00 		call	_pthread_mutex_init
 1766      00
 1767 1054 83C410   		addl	$16, %esp
 1768 1057 89C6     		movl	%eax, %esi
 1769 1059 85C0     		testl	%eax, %eax
 1770 105b 0F845BFF 		je	L284
 1770      FFFF
 1771              	L280:
 1772 1061 83EC0C   		subl	$12, %esp
 1773 1064 8B55F0   		movl	-16(%ebp), %edx
 1774 1067 52       		pushl	%edx
 1775 1068 E8332B00 		call	_sem_destroy
 1775      00
 1776 106d 83C410   		addl	$16, %esp
 1777 1070 EBC4     		jmp	L278
 1778              		.p2align 4,,7
 1779              	L285:
 1780 1072 BE280000 		movl	$40, %esi
 1780      00
 1781 1077 E93CFFFF 		jmp	L273
 1781      FF
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 38


 1782 107c 8D742600 		.p2align 4,,15
 1783              	.globl _pthread_cond_destroy
 1784              		.def	_pthread_cond_destroy;	.scl	2;	.type	32;	.endef
 1785              	_pthread_cond_destroy:
 1786 1080 55       		pushl	%ebp
 1787 1081 89E5     		movl	%esp, %ebp
 1788 1083 57       		pushl	%edi
 1789 1084 56       		pushl	%esi
 1790 1085 31F6     		xorl	%esi, %esi
 1791 1087 53       		pushl	%ebx
 1792 1088 83EC0C   		subl	$12, %esp
 1793 108b 8B5D08   		movl	8(%ebp), %ebx
 1794 108e C745F000 		movl	$0, -16(%ebp)
 1794      000000
 1795 1095 C745EC00 		movl	$0, -20(%ebp)
 1795      000000
 1796 109c 85DB     		testl	%ebx, %ebx
 1797 109e 7406     		je	L288
 1798 10a0 8B03     		movl	(%ebx), %eax
 1799 10a2 85C0     		testl	%eax, %eax
 1800 10a4 750D     		jne	L287
 1801              	L288:
 1802 10a6 B8160000 		movl	$22, %eax
 1802      00
 1803              	L286:
 1804 10ab 8D65F4   		leal	-12(%ebp), %esp
 1805 10ae 5B       		popl	%ebx
 1806 10af 5E       		popl	%esi
 1807 10b0 5F       		popl	%edi
 1808 10b1 5D       		popl	%ebp
 1809 10b2 C3       		ret
 1810              		.p2align 4,,7
 1811              	L287:
 1812 10b3 40       		incl	%eax
 1813 10b4 0F846C01 		je	L289
 1813      0000
 1814 10ba 83EC0C   		subl	$12, %esp
 1815 10bd 68000000 		pushl	$_ptw32_cond_list_lock
 1815      00
 1816 10c2 E8000000 		call	_EnterCriticalSection@4
 1816      00
 1817 10c7 8B3B     		movl	(%ebx), %edi
 1818 10c9 8D7710   		leal	16(%edi), %esi
 1819 10cc 56       		pushl	%esi
 1820 10cd E83E2C00 		call	_sem_wait
 1820      00
 1821 10d2 83C410   		addl	$16, %esp
 1822 10d5 85C0     		testl	%eax, %eax
 1823 10d7 7409     		je	L290
 1824 10d9 E8000000 		call	__errno
 1824      00
 1825 10de 8B00     		movl	(%eax), %eax
 1826 10e0 EBC9     		jmp	L286
 1827              		.p2align 4,,7
 1828              	L290:
 1829 10e2 83EC0C   		subl	$12, %esp
 1830 10e5 8D5714   		leal	20(%edi), %edx
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 39


 1831 10e8 8955E8   		movl	%edx, -24(%ebp)
 1832 10eb 52       		pushl	%edx
 1833 10ec E8EF1100 		call	_pthread_mutex_trylock
 1833      00
 1834 10f1 83C410   		addl	$16, %esp
 1835 10f4 85C0     		testl	%eax, %eax
 1836 10f6 8945F0   		movl	%eax, -16(%ebp)
 1837 10f9 0F851601 		jne	L309
 1837      0000
 1838 10ff 8B5704   		movl	4(%edi), %edx
 1839 1102 3917     		cmpl	%edx, (%edi)
 1840 1104 7E5C     		jle	L292
 1841 1106 83EC0C   		subl	$12, %esp
 1842 1109 56       		pushl	%esi
 1843 110a E8E12D00 		call	_sem_post
 1843      00
 1844 110f 83C410   		addl	$16, %esp
 1845 1112 85C0     		testl	%eax, %eax
 1846 1114 7540     		jne	L310
 1847              	L293:
 1848 1116 83EC0C   		subl	$12, %esp
 1849 1119 8B45E8   		movl	-24(%ebp), %eax
 1850 111c BE100000 		movl	$16, %esi
 1850      00
 1851 1121 50       		pushl	%eax
 1852 1122 E8E91000 		call	_pthread_mutex_unlock
 1852      00
 1853 1127 8945EC   		movl	%eax, -20(%ebp)
 1854              	L307:
 1855 112a C7042400 		movl	$_ptw32_cond_list_lock, (%esp)
 1855      000000
 1856              	L308:
 1857 1131 E8000000 		call	_LeaveCriticalSection@4
 1857      00
 1858 1136 8B45F0   		movl	-16(%ebp), %eax
 1859 1139 83C40C   		addl	$12, %esp
 1860 113c 85C0     		testl	%eax, %eax
 1861 113e 0F8567FF 		jne	L286
 1861      FFFF
 1862 1144 8B45EC   		movl	-20(%ebp), %eax
 1863 1147 85C0     		testl	%eax, %eax
 1864 1149 0F855CFF 		jne	L286
 1864      FFFF
 1865 114f 89F0     		movl	%esi, %eax
 1866 1151 E955FFFF 		jmp	L286
 1866      FF
 1867              	L310:
 1868 1156 E8000000 		call	__errno
 1868      00
 1869 115b 8B08     		movl	(%eax), %ecx
 1870 115d 894DF0   		movl	%ecx, -16(%ebp)
 1871 1160 EBB4     		jmp	L293
 1872              	L292:
 1873 1162 83EC0C   		subl	$12, %esp
 1874 1165 C7030000 		movl	$0, (%ebx)
 1874      0000
 1875 116b 56       		pushl	%esi
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 40


 1876 116c E82F2A00 		call	_sem_destroy
 1876      00
 1877 1171 83C410   		addl	$16, %esp
 1878 1174 85C0     		testl	%eax, %eax
 1879 1176 0F858A00 		jne	L311
 1879      0000
 1880              	L295:
 1881 117c 83EC0C   		subl	$12, %esp
 1882 117f 8D770C   		leal	12(%edi), %esi
 1883 1182 56       		pushl	%esi
 1884 1183 E8182A00 		call	_sem_destroy
 1884      00
 1885 1188 83C410   		addl	$16, %esp
 1886 118b 85C0     		testl	%eax, %eax
 1887 118d 756B     		jne	L312
 1888              	L296:
 1889 118f 83EC0C   		subl	$12, %esp
 1890 1192 8B4DE8   		movl	-24(%ebp), %ecx
 1891 1195 51       		pushl	%ecx
 1892 1196 E8751000 		call	_pthread_mutex_unlock
 1892      00
 1893 119b 83C410   		addl	$16, %esp
 1894 119e 89C6     		movl	%eax, %esi
 1895 11a0 85C0     		testl	%eax, %eax
 1896 11a2 7443     		je	L313
 1897              	L297:
 1898 11a4 393D1400 		cmpl	%edi, _ptw32_cond_list_head
 1898      0000
 1899 11aa 742D     		je	L314
 1900 11ac 8B571C   		movl	28(%edi), %edx
 1901 11af 8B4F18   		movl	24(%edi), %ecx
 1902 11b2 894A18   		movl	%ecx, 24(%edx)
 1903              	L299:
 1904 11b5 393D1800 		cmpl	%edi, _ptw32_cond_list_tail
 1904      0000
 1905 11bb 7414     		je	L315
 1906 11bd 8B5F18   		movl	24(%edi), %ebx
 1907 11c0 89531C   		movl	%edx, 28(%ebx)
 1908              	L301:
 1909 11c3 83EC0C   		subl	$12, %esp
 1910 11c6 57       		pushl	%edi
 1911 11c7 E8000000 		call	_free
 1911      00
 1912 11cc E959FFFF 		jmp	L307
 1912      FF
 1913              	L315:
 1914 11d1 89151800 		movl	%edx, _ptw32_cond_list_tail
 1914      0000
 1915 11d7 EBEA     		jmp	L301
 1916              	L314:
 1917 11d9 8B5F18   		movl	24(%edi), %ebx
 1918 11dc 8B571C   		movl	28(%edi), %edx
 1919 11df 891D1400 		movl	%ebx, _ptw32_cond_list_head
 1919      0000
 1920 11e5 EBCE     		jmp	L299
 1921              	L313:
 1922 11e7 83EC0C   		subl	$12, %esp
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 41


 1923 11ea 8B45E8   		movl	-24(%ebp), %eax
 1924 11ed 50       		pushl	%eax
 1925 11ee E87D0A00 		call	_pthread_mutex_destroy
 1925      00
 1926 11f3 83C410   		addl	$16, %esp
 1927 11f6 89C6     		movl	%eax, %esi
 1928 11f8 EBAA     		jmp	L297
 1929              	L312:
 1930 11fa E8000000 		call	__errno
 1930      00
 1931 11ff 8B10     		movl	(%eax), %edx
 1932 1201 8955EC   		movl	%edx, -20(%ebp)
 1933 1204 EB89     		jmp	L296
 1934              	L311:
 1935 1206 E8000000 		call	__errno
 1935      00
 1936 120b 8B18     		movl	(%eax), %ebx
 1937 120d 895DF0   		movl	%ebx, -16(%ebp)
 1938 1210 E967FFFF 		jmp	L295
 1938      FF
 1939              	L309:
 1940 1215 83EC0C   		subl	$12, %esp
 1941 1218 56       		pushl	%esi
 1942 1219 E8D22C00 		call	_sem_post
 1942      00
 1943 121e 8B45F0   		movl	-16(%ebp), %eax
 1944 1221 E985FEFF 		jmp	L286
 1944      FF
 1945              		.p2align 4,,7
 1946              	L289:
 1947 1226 83EC0C   		subl	$12, %esp
 1948 1229 68000000 		pushl	$_ptw32_cond_test_init_lock
 1948      00
 1949 122e E8000000 		call	_EnterCriticalSection@4
 1949      00
 1950 1233 83C40C   		addl	$12, %esp
 1951 1236 833BFF   		cmpl	$-1, (%ebx)
 1952 1239 7414     		je	L316
 1953 123b C745F010 		movl	$16, -16(%ebp)
 1953      000000
 1954              	L304:
 1955 1242 83EC0C   		subl	$12, %esp
 1956 1245 68000000 		pushl	$_ptw32_cond_test_init_lock
 1956      00
 1957 124a E9E2FEFF 		jmp	L308
 1957      FF
 1958              	L316:
 1959 124f C7030000 		movl	$0, (%ebx)
 1959      0000
 1960 1255 EBEB     		jmp	L304
 1961 1257 89F68DBC 		.p2align 4,,15
 1961      27000000 
 1961      00
 1962              	.globl _pthread_cond_wait
 1963              		.def	_pthread_cond_wait;	.scl	2;	.type	32;	.endef
 1964              	_pthread_cond_wait:
 1965 1260 55       		pushl	%ebp
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 42


 1966 1261 89E5     		movl	%esp, %ebp
 1967 1263 83EC0C   		subl	$12, %esp
 1968 1266 8B550C   		movl	12(%ebp), %edx
 1969 1269 6A00     		pushl	$0
 1970 126b 52       		pushl	%edx
 1971 126c 8B5508   		movl	8(%ebp), %edx
 1972 126f 52       		pushl	%edx
 1973 1270 E8CB4000 		call	_ptw32_cond_timedwait
 1973      00
 1974 1275 89EC     		movl	%ebp, %esp
 1975 1277 5D       		popl	%ebp
 1976 1278 C3       		ret
 1977 1279 8DB42600 		.p2align 4,,15
 1977      000000
 1978              	.globl _pthread_cond_timedwait
 1979              		.def	_pthread_cond_timedwait;	.scl	2;	.type	32;	.endef
 1980              	_pthread_cond_timedwait:
 1981 1280 55       		pushl	%ebp
 1982 1281 89E5     		movl	%esp, %ebp
 1983 1283 8B5510   		movl	16(%ebp), %edx
 1984 1286 85D2     		testl	%edx, %edx
 1985 1288 7406     		je	L344
 1986 128a 5D       		popl	%ebp
 1987 128b E9B04000 		jmp	_ptw32_cond_timedwait
 1987      00
 1988              		.p2align 4,,7
 1989              	L344:
 1990 1290 B8160000 		movl	$22, %eax
 1990      00
 1991 1295 5D       		popl	%ebp
 1992 1296 C3       		ret
 1993 1297 89F68DBC 		.p2align 4,,15
 1993      27000000 
 1993      00
 1994              	.globl _pthread_cond_signal
 1995              		.def	_pthread_cond_signal;	.scl	2;	.type	32;	.endef
 1996              	_pthread_cond_signal:
 1997 12a0 55       		pushl	%ebp
 1998 12a1 89E5     		movl	%esp, %ebp
 1999 12a3 83EC10   		subl	$16, %esp
 2000 12a6 8B5508   		movl	8(%ebp), %edx
 2001 12a9 6A00     		pushl	$0
 2002 12ab 52       		pushl	%edx
 2003 12ac E8BF4100 		call	_ptw32_cond_unblock
 2003      00
 2004 12b1 89EC     		movl	%ebp, %esp
 2005 12b3 5D       		popl	%ebp
 2006 12b4 C3       		ret
 2007 12b5 8D742600 		.p2align 4,,15
 2007      8DBC2700 
 2007      000000
 2008              	.globl _pthread_cond_broadcast
 2009              		.def	_pthread_cond_broadcast;	.scl	2;	.type	32;	.endef
 2010              	_pthread_cond_broadcast:
 2011 12c0 55       		pushl	%ebp
 2012 12c1 89E5     		movl	%esp, %ebp
 2013 12c3 83EC10   		subl	$16, %esp
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 43


 2014 12c6 8B5508   		movl	8(%ebp), %edx
 2015 12c9 6A01     		pushl	$1
 2016 12cb 52       		pushl	%edx
 2017 12cc E89F4100 		call	_ptw32_cond_unblock
 2017      00
 2018 12d1 89EC     		movl	%ebp, %esp
 2019 12d3 5D       		popl	%ebp
 2020 12d4 C3       		ret
 2021 12d5 8D742600 		.p2align 4,,15
 2021      8DBC2700 
 2021      000000
 2022              	.globl _pthread_create
 2023              		.def	_pthread_create;	.scl	2;	.type	32;	.endef
 2024              	_pthread_create:
 2025 12e0 55       		pushl	%ebp
 2026 12e1 89E5     		movl	%esp, %ebp
 2027 12e3 57       		pushl	%edi
 2028 12e4 56       		pushl	%esi
 2029 12e5 53       		pushl	%ebx
 2030 12e6 31DB     		xorl	%ebx, %ebx
 2031 12e8 81ECBC00 		subl	$188, %esp
 2031      0000
 2032 12ee 8B4D08   		movl	8(%ebp), %ecx
 2033 12f1 8B450C   		movl	12(%ebp), %eax
 2034 12f4 C7854CFF 		movl	$11, -180(%ebp)
 2034      FFFF0B00 
 2034      0000
 2035 12fe C78548FF 		movl	$0, -184(%ebp)
 2035      FFFF0000 
 2035      0000
 2036 1308 C7410400 		movl	$0, 4(%ecx)
 2036      000000
 2037 130f 85C0     		testl	%eax, %eax
 2038 1311 7402     		je	L367
 2039 1313 8B18     		movl	(%eax), %ebx
 2040              	L367:
 2041 1315 E8B60600 		call	_ptw32_new
 2041      00
 2042 131a 898550FF 		movl	%eax, -176(%ebp)
 2042      FFFF
 2043 1320 899554FF 		movl	%edx, -172(%ebp)
 2043      FFFF
 2044 1326 8B9550FF 		movl	-176(%ebp), %edx
 2044      FFFF
 2045 132c 85D2     		testl	%edx, %edx
 2046 132e 0F85CC00 		jne	L389
 2046      0000
 2047              	L369:
 2048 1334 8B854CFF 		movl	-180(%ebp), %eax
 2048      FFFF
 2049 133a 85C0     		testl	%eax, %eax
 2050 133c 0F84A100 		je	L381
 2050      0000
 2051 1342 8BB550FF 		movl	-176(%ebp), %esi
 2051      FFFF
 2052 1348 85F6     		testl	%esi, %esi
 2053 134a 7451     		je	L385
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 44


 2054 134c FC       		cld
 2055 134d 8DBD58FF 		leal	-168(%ebp), %edi
 2055      FFFF
 2056 1353 B9230000 		movl	$35, %ecx
 2056      00
 2057 1358 F3       		rep
 2058 1359 A5       		movsl
 2059 135a 53       		pushl	%ebx
 2060 135b 8BB550FF 		movl	-176(%ebp), %esi
 2060      FFFF
 2061 1361 53       		pushl	%ebx
 2062 1362 8B9D54FF 		movl	-172(%ebp), %ebx
 2062      FFFF
 2063 1368 53       		pushl	%ebx
 2064 1369 56       		pushl	%esi
 2065 136a E8810700 		call	_ptw32_threadReusePush
 2065      00
 2066 136f 8B4594   		movl	-108(%ebp), %eax
 2067 1372 83C410   		addl	$16, %esp
 2068 1375 85C0     		testl	%eax, %eax
 2069 1377 755C     		jne	L390
 2070              	L383:
 2071 1379 83EC0C   		subl	$12, %esp
 2072 137c 8D4D88   		leal	-120(%ebp), %ecx
 2073 137f 8D7D80   		leal	-128(%ebp), %edi
 2074 1382 51       		pushl	%ecx
 2075 1383 E8E80800 		call	_pthread_mutex_destroy
 2075      00
 2076 1388 893C24   		movl	%edi, (%esp)
 2077 138b E8E00800 		call	_pthread_mutex_destroy
 2077      00
 2078 1390 8B855CFF 		movl	-164(%ebp), %eax
 2078      FFFF
 2079 1396 83C410   		addl	$16, %esp
 2080 1399 85C0     		testl	%eax, %eax
 2081 139b 752A     		jne	L391
 2082              	L385:
 2083 139d 8B9548FF 		movl	-184(%ebp), %edx
 2083      FFFF
 2084 13a3 85D2     		testl	%edx, %edx
 2085 13a5 7412     		je	L387
 2086 13a7 83EC0C   		subl	$12, %esp
 2087 13aa 8BB548FF 		movl	-184(%ebp), %esi
 2087      FFFF
 2088 13b0 56       		pushl	%esi
 2089 13b1 E8000000 		call	_free
 2089      00
 2090 13b6 83C410   		addl	$16, %esp
 2091              	L387:
 2092 13b9 8B854CFF 		movl	-180(%ebp), %eax
 2092      FFFF
 2093 13bf 8D65F4   		leal	-12(%ebp), %esp
 2094 13c2 5B       		popl	%ebx
 2095 13c3 5E       		popl	%esi
 2096 13c4 5F       		popl	%edi
 2097 13c5 5D       		popl	%ebp
 2098 13c6 C3       		ret
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 45


 2099              	L391:
 2100 13c7 83EC0C   		subl	$12, %esp
 2101 13ca 50       		pushl	%eax
 2102 13cb E8000000 		call	_CloseHandle@4
 2102      00
 2103 13d0 83C40C   		addl	$12, %esp
 2104 13d3 EBC8     		jmp	L385
 2105              	L390:
 2106 13d5 83EC0C   		subl	$12, %esp
 2107 13d8 50       		pushl	%eax
 2108 13d9 E8000000 		call	_CloseHandle@4
 2108      00
 2109 13de 83C40C   		addl	$12, %esp
 2110 13e1 EB96     		jmp	L383
 2111              		.p2align 4,,7
 2112              	L381:
 2113 13e3 8B5D08   		movl	8(%ebp), %ebx
 2114 13e6 8B8D50FF 		movl	-176(%ebp), %ecx
 2114      FFFF
 2115 13ec 8BBD54FF 		movl	-172(%ebp), %edi
 2115      FFFF
 2116 13f2 890B     		movl	%ecx, (%ebx)
 2117 13f4 897B04   		movl	%edi, 4(%ebx)
 2118 13f7 EBC0     		jmp	L387
 2119 13f9 8DB42600 		.p2align 4,,7
 2119      000000
 2120              	L389:
 2121 1400 83EC0C   		subl	$12, %esp
 2122 1403 8BBD50FF 		movl	-176(%ebp), %edi
 2122      FFFF
 2123 1409 8B472C   		movl	44(%edi), %eax
 2124 140c 6A10     		pushl	$16
 2125 140e 898544FF 		movl	%eax, -188(%ebp)
 2125      FFFF
 2126 1414 E8000000 		call	_malloc
 2126      00
 2127 1419 83C410   		addl	$16, %esp
 2128 141c 85C0     		testl	%eax, %eax
 2129 141e 898548FF 		movl	%eax, -184(%ebp)
 2129      FFFF
 2130 1424 0F840AFF 		je	L369
 2130      FFFF
 2131 142a 8BB548FF 		movl	-184(%ebp), %esi
 2131      FFFF
 2132 1430 8B9550FF 		movl	-176(%ebp), %edx
 2132      FFFF
 2133 1436 8B8D54FF 		movl	-172(%ebp), %ecx
 2133      FFFF
 2134 143c 85DB     		testl	%ebx, %ebx
 2135 143e 8916     		movl	%edx, (%esi)
 2136 1440 894E04   		movl	%ecx, 4(%esi)
 2137 1443 8B5510   		movl	16(%ebp), %edx
 2138 1446 8B4D14   		movl	20(%ebp), %ecx
 2139 1449 895608   		movl	%edx, 8(%esi)
 2140 144c 894E0C   		movl	%ecx, 12(%esi)
 2141 144f 0F84CB00 		je	L371
 2141      0000
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 46


 2142 1455 8B4B0C   		movl	12(%ebx), %ecx
 2143 1458 8B7308   		movl	8(%ebx), %esi
 2144 145b 894F24   		movl	%ecx, 36(%edi)
 2145 145e 8B5310   		movl	16(%ebx), %edx
 2146 1461 8B4B14   		movl	20(%ebx), %ecx
 2147 1464 899544FF 		movl	%edx, -188(%ebp)
 2147      FFFF
 2148 146a 85C9     		testl	%ecx, %ecx
 2149 146c 0F849B00 		je	L392
 2149      0000
 2150              	L373:
 2151 1472 B8010000 		movl	$1, %eax
 2151      00
 2152 1477 8B8D48FF 		movl	-184(%ebp), %ecx
 2152      FFFF
 2153 147d 85C0     		testl	%eax, %eax
 2154 147f 0F94C2   		sete	%dl
 2155 1482 81E2FF00 		andl	$255, %edx
 2155      0000
 2156 1488 01D2     		addl	%edx, %edx
 2157 148a 895714   		movl	%edx, 20(%edi)
 2158 148d C7878400 		movl	$0, 132(%edi)
 2158      00000000 
 2158      0000
 2159 1497 50       		pushl	%eax
 2160 1498 50       		pushl	%eax
 2161 1499 57       		pushl	%edi
 2162 149a 6A04     		pushl	$4
 2163 149c 51       		pushl	%ecx
 2164 149d 68F00000 		pushl	$_ptw32_threadStart@4
 2164      00
 2165 14a2 56       		pushl	%esi
 2166 14a3 6A00     		pushl	$0
 2167 14a5 E8000000 		call	__beginthreadex
 2167      00
 2168 14aa 83C420   		addl	$32, %esp
 2169 14ad 89C6     		movl	%eax, %esi
 2170 14af 85C0     		testl	%eax, %eax
 2171 14b1 894704   		movl	%eax, 4(%edi)
 2172 14b4 C7854CFF 		movl	$11, -180(%ebp)
 2172      FFFF0B00 
 2172      0000
 2173 14be 0F8470FE 		je	L369
 2173      FFFF
 2174 14c4 85DB     		testl	%ebx, %ebx
 2175 14c6 741F     		je	L377
 2176 14c8 8B8D44FF 		movl	-188(%ebp), %ecx
 2176      FFFF
 2177 14ce 8BBD54FF 		movl	-172(%ebp), %edi
 2177      FFFF
 2178 14d4 51       		pushl	%ecx
 2179 14d5 8B9D50FF 		movl	-176(%ebp), %ebx
 2179      FFFF
 2180 14db 6A00     		pushl	$0
 2181 14dd 57       		pushl	%edi
 2182 14de 53       		pushl	%ebx
 2183 14df E88C2300 		call	_ptw32_setthreadpriority
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 47


 2183      00
 2184 14e4 83C410   		addl	$16, %esp
 2185              	L377:
 2186 14e7 BA010000 		movl	$1, %edx
 2186      00
 2187 14ec 85D2     		testl	%edx, %edx
 2188 14ee 750F     		jne	L393
 2189              	L376:
 2190 14f0 C7854CFF 		movl	$0, -180(%ebp)
 2190      FFFF0000 
 2190      0000
 2191 14fa E935FEFF 		jmp	L369
 2191      FF
 2192              	L393:
 2193 14ff 83EC0C   		subl	$12, %esp
 2194 1502 56       		pushl	%esi
 2195 1503 E8000000 		call	_ResumeThread@4
 2195      00
 2196 1508 83C40C   		addl	$12, %esp
 2197 150b EBE3     		jmp	L376
 2198              	L392:
 2199 150d E89E0300 		call	_pthread_self
 2199      00
 2200 1512 8B502C   		movl	44(%eax), %edx
 2201 1515 899544FF 		movl	%edx, -188(%ebp)
 2201      FFFF
 2202 151b E952FFFF 		jmp	L373
 2202      FF
 2203              	L371:
 2204 1520 31F6     		xorl	%esi, %esi
 2205 1522 E94BFFFF 		jmp	L373
 2205      FF
 2206 1527 89F68DBC 		.p2align 4,,15
 2206      27000000 
 2206      00
 2207              	.globl _pthread_exit
 2208              		.def	_pthread_exit;	.scl	2;	.type	32;	.endef
 2209              	_pthread_exit:
 2210 1530 55       		pushl	%ebp
 2211 1531 8B150C00 		movl	_ptw32_selfThreadKey, %edx
 2211      0000
 2212 1537 89E5     		movl	%esp, %ebp
 2213 1539 56       		pushl	%esi
 2214 153a 53       		pushl	%ebx
 2215 153b 83EC0C   		subl	$12, %esp
 2216 153e 8B7508   		movl	8(%ebp), %esi
 2217 1541 52       		pushl	%edx
 2218 1542 E8B93400 		call	_pthread_getspecific
 2218      00
 2219 1547 83C410   		addl	$16, %esp
 2220 154a 89C3     		movl	%eax, %ebx
 2221 154c 85C0     		testl	%eax, %eax
 2222 154e 7449     		je	L409
 2223              	L395:
 2224 1550 83EC0C   		subl	$12, %esp
 2225 1553 A10C0000 		movl	_ptw32_selfThreadKey, %eax
 2225      00
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 48


 2226 1558 897318   		movl	%esi, 24(%ebx)
 2227 155b 50       		pushl	%eax
 2228 155c E89F3400 		call	_pthread_getspecific
 2228      00
 2229 1561 83C410   		addl	$16, %esp
 2230 1564 89C3     		movl	%eax, %ebx
 2231 1566 85C0     		testl	%eax, %eax
 2232 1568 740D     		je	L398
 2233 156a 8A908000 		movb	128(%eax), %dl
 2233      0000
 2234 1570 83E201   		andl	$1, %edx
 2235 1573 84D2     		testb	%dl, %dl
 2236 1575 740F     		je	L404
 2237              	L398:
 2238 1577 83EC0C   		subl	$12, %esp
 2239 157a 8B7318   		movl	24(%ebx), %esi
 2240 157d 56       		pushl	%esi
 2241 157e E8000000 		call	__endthreadex
 2241      00
 2242 1583 83C410   		addl	$16, %esp
 2243              		.p2align 4,,7
 2244              	L404:
 2245 1586 83EC0C   		subl	$12, %esp
 2246 1589 6A01     		pushl	$1
 2247 158b E820F8FF 		call	_ptw32_pop_cleanup
 2247      FF
 2248 1590 83C410   		addl	$16, %esp
 2249 1593 85C0     		testl	%eax, %eax
 2250 1595 75EF     		jne	L404
 2251 1597 EB0E     		jmp	L410
 2252              	L409:
 2253 1599 83EC0C   		subl	$12, %esp
 2254 159c 56       		pushl	%esi
 2255 159d E8000000 		call	__endthreadex
 2255      00
 2256 15a2 83C410   		addl	$16, %esp
 2257 15a5 EBA9     		jmp	L395
 2258              		.p2align 4,,7
 2259              	L410:
 2260 15a7 8D4B40   		leal	64(%ebx), %ecx
 2261 15aa 52       		pushl	%edx
 2262 15ab 52       		pushl	%edx
 2263 15ac 6A01     		pushl	$1
 2264 15ae 51       		pushl	%ecx
 2265 15af E8000000 		call	_longjmp
 2265      00
 2266              	.globl _ptw32_processInitialized
 2267              		.data
 2268              		.align 4
 2269              	_ptw32_processInitialized:
 2270 0000 00000000 		.long	0
 2271              	.globl _ptw32_threadReuseTop
 2272              		.align 4
 2273              	_ptw32_threadReuseTop:
 2274 0004 01000000 		.long	1
 2275              	.globl _ptw32_threadReuseBottom
 2276              		.align 4
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 49


 2277              	_ptw32_threadReuseBottom:
 2278 0008 01000000 		.long	1
 2279              	.globl _ptw32_selfThreadKey
 2280              		.align 4
 2281              	_ptw32_selfThreadKey:
 2282 000c 00000000 		.long	0
 2283              	.globl _ptw32_cleanupKey
 2284              		.align 4
 2285              	_ptw32_cleanupKey:
 2286 0010 00000000 		.long	0
 2287              	.globl _ptw32_cond_list_head
 2288              		.align 4
 2289              	_ptw32_cond_list_head:
 2290 0014 00000000 		.long	0
 2291              	.globl _ptw32_cond_list_tail
 2292              		.align 4
 2293              	_ptw32_cond_list_tail:
 2294 0018 00000000 		.long	0
 2295              	.globl _ptw32_concurrency
 2296              		.align 4
 2297              	_ptw32_concurrency:
 2298 001c 00000000 		.long	0
 2299              	.globl _ptw32_features
 2300              		.align 4
 2301              	_ptw32_features:
 2302 0020 00000000 		.long	0
 2303              	.globl _ptw32_smp_system
 2304              		.align 4
 2305              	_ptw32_smp_system:
 2306 0024 01000000 		.long	1
 2307              	.globl _ptw32_interlocked_compare_exchange
 2308              		.align 4
 2309              	_ptw32_interlocked_compare_exchange:
 2310 0028 00000000 		.long	0
 2311              	.globl _ptw32_register_cancelation
 2312              		.align 4
 2313              	_ptw32_register_cancelation:
 2314 002c 00000000 		.long	0
 2315              		.text
 2316 15b4 8DB60000 		.p2align 4,,15
 2316      00008DBF 
 2316      00000000 
 2317              	.globl _pthread_kill
 2318              		.def	_pthread_kill;	.scl	2;	.type	32;	.endef
 2319              	_pthread_kill:
 2320 15c0 55       		pushl	%ebp
 2321 15c1 89E5     		movl	%esp, %ebp
 2322 15c3 57       		pushl	%edi
 2323 15c4 56       		pushl	%esi
 2324 15c5 31FF     		xorl	%edi, %edi
 2325 15c7 53       		pushl	%ebx
 2326 15c8 83EC18   		subl	$24, %esp
 2327 15cb 8B5D08   		movl	8(%ebp), %ebx
 2328 15ce 8B750C   		movl	12(%ebp), %esi
 2329 15d1 68000000 		pushl	$_ptw32_thread_reuse_lock
 2329      00
 2330 15d6 E8000000 		call	_EnterCriticalSection@4
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 50


 2330      00
 2331 15db 83C40C   		addl	$12, %esp
 2332 15de 85DB     		testl	%ebx, %ebx
 2333 15e0 7405     		je	L413
 2334 15e2 39730C   		cmpl	%esi, 12(%ebx)
 2335 15e5 742F     		je	L415
 2336              	L413:
 2337 15e7 BF030000 		movl	$3, %edi
 2337      00
 2338              	L412:
 2339 15ec 83EC0C   		subl	$12, %esp
 2340 15ef 68000000 		pushl	$_ptw32_thread_reuse_lock
 2340      00
 2341 15f4 E8000000 		call	_LeaveCriticalSection@4
 2341      00
 2342 15f9 83C40C   		addl	$12, %esp
 2343 15fc 85FF     		testl	%edi, %edi
 2344 15fe 750C     		jne	L414
 2345 1600 8B5510   		movl	16(%ebp), %edx
 2346 1603 85D2     		testl	%edx, %edx
 2347 1605 7405     		je	L414
 2348 1607 BF160000 		movl	$22, %edi
 2348      00
 2349              	L414:
 2350 160c 8D65F4   		leal	-12(%ebp), %esp
 2351 160f 89F8     		movl	%edi, %eax
 2352 1611 5B       		popl	%ebx
 2353 1612 5E       		popl	%esi
 2354 1613 5F       		popl	%edi
 2355 1614 5D       		popl	%ebp
 2356 1615 C3       		ret
 2357              		.p2align 4,,7
 2358              	L415:
 2359 1616 8B4304   		movl	4(%ebx), %eax
 2360 1619 85C0     		testl	%eax, %eax
 2361 161b 74CA     		je	L413
 2362 161d 83EC0C   		subl	$12, %esp
 2363 1620 50       		pushl	%eax
 2364 1621 E8000000 		call	_GetThreadPriority@4
 2364      00
 2365 1626 83C40C   		addl	$12, %esp
 2366 1629 3DFFFFFF 		cmpl	$2147483647, %eax
 2366      7F
 2367 162e 75BC     		jne	L412
 2368 1630 EBB5     		jmp	L413
 2369 1632 8DB42600 		.p2align 4,,15
 2369      0000008D 
 2369      BC270000 
 2369      0000
 2370              	.globl _pthread_once
 2371              		.def	_pthread_once;	.scl	2;	.type	32;	.endef
 2372              	_pthread_once:
 2373 1640 55       		pushl	%ebp
 2374 1641 89E5     		movl	%esp, %ebp
 2375 1643 57       		pushl	%edi
 2376 1644 56       		pushl	%esi
 2377 1645 53       		pushl	%ebx
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 51


 2378 1646 83EC4C   		subl	$76, %esp
 2379 1649 8B5D08   		movl	8(%ebp), %ebx
 2380 164c 85DB     		testl	%ebx, %ebx
 2381 164e 0F844E02 		je	L418
 2381      0000
 2382 1654 8B450C   		movl	12(%ebp), %eax
 2383 1657 85C0     		testl	%eax, %eax
 2384 1659 0F844302 		je	L418
 2384      0000
 2385 165f 56       		pushl	%esi
 2386 1660 56       		pushl	%esi
 2387 1661 6A00     		pushl	$0
 2388 1663 53       		pushl	%ebx
 2389 1664 E8000000 		call	_InterlockedExchangeAdd@8
 2389      00
 2390 1669 5A       		popl	%edx
 2391 166a 85C0     		testl	%eax, %eax
 2392 166c 59       		popl	%ecx
 2393 166d 0F85BA00 		jne	L419
 2393      0000
 2394 1673 8D5304   		leal	4(%ebx), %edx
 2395 1676 8D7DD8   		leal	-40(%ebp), %edi
 2396 1679 8955D8   		movl	%edx, -40(%ebp)
 2397 167c 8B152400 		movl	_ptw32_smp_system, %edx
 2397      0000
 2398 1682 C745E400 		movl	$0, -28(%ebp)
 2398      000000
 2399 1689 C745E000 		movl	$0, -32(%ebp)
 2399      000000
 2400 1690 C745DC00 		movl	$0, -36(%ebp)
 2400      000000
 2401 1697 85D2     		testl	%edx, %edx
 2402 1699 0F84F501 		je	L420
 2402      0000
 2403 169f 89F8     		movl	%edi, %eax
 2404              	/APP
 2405 16a1 874304   		xchgl          %eax,4(%ebx)
 2406              	/NO_APP
 2407              	L457:
 2408 16a4 8945B4   		movl	%eax, -76(%ebp)
 2409 16a7 8B4DB4   		movl	-76(%ebp), %ecx
 2410 16aa 85C9     		testl	%ecx, %ecx
 2411 16ac 7439     		je	L435
 2412 16ae 8B75B4   		movl	-76(%ebp), %esi
 2413 16b1 83C9FF   		orl	$-1, %ecx
 2414 16b4 85D2     		testl	%edx, %edx
 2415 16b6 897E04   		movl	%edi, 4(%esi)
 2416 16b9 0F84C701 		je	L424
 2416      0000
 2417 16bf 31C0     		xorl	%eax, %eax
 2418              	/APP
 2419 16c1 F0       		lock
 2420 16c2 0FB14E0C 		cmpxchgl       %ecx,12(%esi)
 2421              	/NO_APP
 2422              	L458:
 2423 16c6 85C0     		testl	%eax, %eax
 2424 16c8 0F85A701 		jne	L463
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 52


 2424      0000
 2425              	L428:
 2426 16ce 8D4F08   		leal	8(%edi), %ecx
 2427 16d1 56       		pushl	%esi
 2428 16d2 56       		pushl	%esi
 2429 16d3 6A00     		pushl	$0
 2430 16d5 51       		pushl	%ecx
 2431 16d6 E8000000 		call	_InterlockedExchangeAdd@8
 2431      00
 2432 16db 5A       		popl	%edx
 2433 16dc 89C6     		movl	%eax, %esi
 2434 16de 59       		popl	%ecx
 2435 16df 85C0     		testl	%eax, %eax
 2436 16e1 0F843601 		je	L464
 2436      0000
 2437              	L435:
 2438 16e7 56       		pushl	%esi
 2439 16e8 56       		pushl	%esi
 2440 16e9 6A00     		pushl	$0
 2441 16eb 53       		pushl	%ebx
 2442 16ec E8000000 		call	_InterlockedExchangeAdd@8
 2442      00
 2443 16f1 5A       		popl	%edx
 2444 16f2 85C0     		testl	%eax, %eax
 2445 16f4 59       		popl	%ecx
 2446 16f5 0F84DC00 		je	L465
 2446      0000
 2447              	L436:
 2448 16fb 8D55DC   		leal	-36(%ebp), %edx
 2449 16fe 51       		pushl	%ecx
 2450 16ff 8B5DD8   		movl	-40(%ebp), %ebx
 2451 1702 51       		pushl	%ecx
 2452 1703 6A00     		pushl	$0
 2453 1705 52       		pushl	%edx
 2454 1706 E8000000 		call	_InterlockedExchangeAdd@8
 2454      00
 2455 170b 5E       		popl	%esi
 2456 170c 85C0     		testl	%eax, %eax
 2457 170e 5A       		popl	%edx
 2458 170f 89C2     		movl	%eax, %edx
 2459 1711 743A     		je	L466
 2460              	L440:
 2461 1713 8B352400 		movl	_ptw32_smp_system, %esi
 2461      0000
 2462 1719 83C9FF   		orl	$-1, %ecx
 2463 171c 31DB     		xorl	%ebx, %ebx
 2464 171e 85F6     		testl	%esi, %esi
 2465 1720 7423     		je	L452
 2466 1722 89D8     		movl	%ebx, %eax
 2467              	/APP
 2468 1724 F0       		lock
 2469 1725 0FB14A08 		cmpxchgl       %ecx,8(%edx)
 2470              	/NO_APP
 2471              	L462:
 2472 1729 85C0     		testl	%eax, %eax
 2473 172b 750A     		jne	L467
 2474              	L419:
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 53


 2475 172d 31C0     		xorl	%eax, %eax
 2476              	L416:
 2477 172f 8D65F4   		leal	-12(%ebp), %esp
 2478 1732 5B       		popl	%ebx
 2479 1733 5E       		popl	%esi
 2480 1734 5F       		popl	%edi
 2481 1735 5D       		popl	%ebp
 2482 1736 C3       		ret
 2483              	L467:
 2484 1737 83EC0C   		subl	$12, %esp
 2485 173a 50       		pushl	%eax
 2486 173b E8000000 		call	_SetEvent@4
 2486      00
 2487 1740 83C40C   		addl	$12, %esp
 2488 1743 EBE8     		jmp	L419
 2489              		.p2align 4,,7
 2490              	L452:
 2491 1745 89F0     		movl	%esi, %eax
 2492              	/APP
 2493 1747 0FB14A08 		cmpxchgl       %ecx,8(%edx)
 2494              	/NO_APP
 2495 174b EBDC     		jmp	L462
 2496              	L466:
 2497 174d A1240000 		movl	_ptw32_smp_system, %eax
 2497      00
 2498 1752 85C0     		testl	%eax, %eax
 2499 1754 747A     		je	L442
 2500 1756 89F8     		movl	%edi, %eax
 2501              	/APP
 2502 1758 F0       		lock
 2503 1759 0FB113   		cmpxchgl       %edx,(%ebx)
 2504              	/NO_APP
 2505              	L460:
 2506 175c 39C7     		cmpl	%eax, %edi
 2507 175e 74CD     		je	L419
 2508 1760 8D4F0C   		leal	12(%edi), %ecx
 2509 1763 52       		pushl	%edx
 2510 1764 52       		pushl	%edx
 2511 1765 6A00     		pushl	$0
 2512 1767 51       		pushl	%ecx
 2513 1768 E8000000 		call	_InterlockedExchangeAdd@8
 2513      00
 2514 176d 5B       		popl	%ebx
 2515 176e 85C0     		testl	%eax, %eax
 2516 1770 5E       		popl	%esi
 2517 1771 89C3     		movl	%eax, %ebx
 2518 1773 7413     		je	L468
 2519              	L451:
 2520 1775 8D7704   		leal	4(%edi), %esi
 2521 1778 53       		pushl	%ebx
 2522 1779 53       		pushl	%ebx
 2523 177a 6A00     		pushl	$0
 2524 177c 56       		pushl	%esi
 2525 177d E8000000 		call	_InterlockedExchangeAdd@8
 2525      00
 2526 1782 5A       		popl	%edx
 2527 1783 89C2     		movl	%eax, %edx
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 54


 2528 1785 59       		popl	%ecx
 2529 1786 EB8B     		jmp	L440
 2530              	L468:
 2531 1788 6A00     		pushl	$0
 2532 178a 6A00     		pushl	$0
 2533 178c 6A00     		pushl	$0
 2534 178e 6A00     		pushl	$0
 2535 1790 E8000000 		call	_CreateEventA@16
 2535      00
 2536 1795 8B152400 		movl	_ptw32_smp_system, %edx
 2536      0000
 2537 179b 89C6     		movl	%eax, %esi
 2538 179d 85D2     		testl	%edx, %edx
 2539 179f 7427     		je	L448
 2540 17a1 89D8     		movl	%ebx, %eax
 2541              	/APP
 2542 17a3 F0       		lock
 2543 17a4 0FB1770C 		cmpxchgl       %esi,12(%edi)
 2544              	/NO_APP
 2545              	L461:
 2546 17a8 85C0     		testl	%eax, %eax
 2547 17aa 740E     		je	L469
 2548              	L447:
 2549 17ac 83EC0C   		subl	$12, %esp
 2550 17af 56       		pushl	%esi
 2551 17b0 E8000000 		call	_CloseHandle@4
 2551      00
 2552 17b5 83C40C   		addl	$12, %esp
 2553 17b8 EBBB     		jmp	L451
 2554              	L469:
 2555 17ba 51       		pushl	%ecx
 2556 17bb 51       		pushl	%ecx
 2557 17bc 6AFF     		pushl	$-1
 2558 17be 56       		pushl	%esi
 2559 17bf E8000000 		call	_WaitForSingleObject@8
 2559      00
 2560 17c4 58       		popl	%eax
 2561 17c5 5A       		popl	%edx
 2562 17c6 EBE4     		jmp	L447
 2563              	L448:
 2564 17c8 89D0     		movl	%edx, %eax
 2565              	/APP
 2566 17ca 0FB1770C 		cmpxchgl       %esi,12(%edi)
 2567              	/NO_APP
 2568 17ce EBD8     		jmp	L461
 2569              	L442:
 2570 17d0 89F8     		movl	%edi, %eax
 2571              	/APP
 2572 17d2 0FB113   		cmpxchgl       %edx,(%ebx)
 2573              	/NO_APP
 2574 17d5 EB85     		jmp	L460
 2575              	L465:
 2576 17d7 8D75C8   		leal	-56(%ebp), %esi
 2577 17da 50       		pushl	%eax
 2578 17db 57       		pushl	%edi
 2579 17dc 68A05500 		pushl	$_ptw32_once_on_init_cancel
 2579      00
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 55


 2580 17e1 56       		pushl	%esi
 2581 17e2 E829F6FF 		call	_ptw32_push_cleanup
 2581      FF
 2582 17e7 FF550C   		call	*12(%ebp)
 2583 17ea C7042400 		movl	$0, (%esp)
 2583      000000
 2584 17f1 E8BAF5FF 		call	_ptw32_pop_cleanup
 2584      FF
 2585 17f6 8B0D2400 		movl	_ptw32_smp_system, %ecx
 2585      0000
 2586 17fc 83C410   		addl	$16, %esp
 2587 17ff B8010000 		movl	$1, %eax
 2587      00
 2588 1804 85C9     		testl	%ecx, %ecx
 2589 1806 7407     		je	L437
 2590              	/APP
 2591 1808 8703     		xchgl          %eax,(%ebx)
 2592              	/NO_APP
 2593 180a E9ECFEFF 		jmp	L436
 2593      FF
 2594              	L437:
 2595 180f 89C2     		movl	%eax, %edx
 2596              	/APP
 2597              		0:
 2598 1811 8B03     		movl           (%ebx),%eax
 2599 1813 0FB113   		cmpxchgl       %edx,(%ebx)
 2600 1816 75F9     		jnz            0b
 2601              	/NO_APP
 2602 1818 E9DEFEFF 		jmp	L436
 2602      FF
 2603              	L464:
 2604 181d 6A00     		pushl	$0
 2605 181f 6A00     		pushl	$0
 2606 1821 6A00     		pushl	$0
 2607 1823 6A00     		pushl	$0
 2608 1825 E8000000 		call	_CreateEventA@16
 2608      00
 2609 182a 8B152400 		movl	_ptw32_smp_system, %edx
 2609      0000
 2610 1830 85D2     		testl	%edx, %edx
 2611 1832 8945C4   		movl	%eax, -60(%ebp)
 2612 1835 7433     		je	L431
 2613 1837 89F0     		movl	%esi, %eax
 2614 1839 8B55C4   		movl	-60(%ebp), %edx
 2615              	/APP
 2616 183c F0       		lock
 2617 183d 0FB15708 		cmpxchgl       %edx,8(%edi)
 2618              	/NO_APP
 2619              	L459:
 2620 1841 85C0     		testl	%eax, %eax
 2621 1843 7414     		je	L470
 2622              	L430:
 2623 1845 83EC0C   		subl	$12, %esp
 2624 1848 8B55C4   		movl	-60(%ebp), %edx
 2625 184b 52       		pushl	%edx
 2626 184c E8000000 		call	_CloseHandle@4
 2626      00
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 56


 2627 1851 83C40C   		addl	$12, %esp
 2628 1854 E98EFEFF 		jmp	L435
 2628      FF
 2629              	L470:
 2630 1859 8B45C4   		movl	-60(%ebp), %eax
 2631 185c 56       		pushl	%esi
 2632 185d 56       		pushl	%esi
 2633 185e 6AFF     		pushl	$-1
 2634 1860 50       		pushl	%eax
 2635 1861 E8000000 		call	_WaitForSingleObject@8
 2635      00
 2636 1866 58       		popl	%eax
 2637 1867 5A       		popl	%edx
 2638 1868 EBDB     		jmp	L430
 2639              	L431:
 2640 186a 89D0     		movl	%edx, %eax
 2641 186c 8B75C4   		movl	-60(%ebp), %esi
 2642              	/APP
 2643 186f 0FB17708 		cmpxchgl       %esi,8(%edi)
 2644              	/NO_APP
 2645 1873 EBCC     		jmp	L459
 2646              	L463:
 2647 1875 83EC0C   		subl	$12, %esp
 2648 1878 50       		pushl	%eax
 2649 1879 E8000000 		call	_SetEvent@4
 2649      00
 2650 187e 83C40C   		addl	$12, %esp
 2651 1881 E948FEFF 		jmp	L428
 2651      FF
 2652              	L424:
 2653 1886 89D0     		movl	%edx, %eax
 2654 1888 8B55B4   		movl	-76(%ebp), %edx
 2655              	/APP
 2656 188b 0FB14A0C 		cmpxchgl       %ecx,12(%edx)
 2657              	/NO_APP
 2658 188f E932FEFF 		jmp	L458
 2658      FF
 2659              		.p2align 4,,7
 2660              	L420:
 2661              	/APP
 2662              		0:
 2663 1894 8B4304   		movl           4(%ebx),%eax
 2664 1897 0FB17B04 		cmpxchgl       %edi,4(%ebx)
 2665 189b 75F7     		jnz            0b
 2666              	/NO_APP
 2667 189d E902FEFF 		jmp	L457
 2667      FF
 2668              		.p2align 4,,7
 2669              	L418:
 2670 18a2 B8160000 		movl	$22, %eax
 2670      00
 2671 18a7 E983FEFF 		jmp	L416
 2671      FF
 2672 18ac 8D742600 		.p2align 4,,15
 2673              	.globl _pthread_self
 2674              		.def	_pthread_self;	.scl	2;	.type	32;	.endef
 2675              	_pthread_self:
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 57


 2676 18b0 55       		pushl	%ebp
 2677 18b1 89E5     		movl	%esp, %ebp
 2678 18b3 57       		pushl	%edi
 2679 18b4 56       		pushl	%esi
 2680 18b5 53       		pushl	%ebx
 2681 18b6 83EC18   		subl	$24, %esp
 2682 18b9 8B150C00 		movl	_ptw32_selfThreadKey, %edx
 2682      0000
 2683 18bf 52       		pushl	%edx
 2684 18c0 E83B3100 		call	_pthread_getspecific
 2684      00
 2685 18c5 83C410   		addl	$16, %esp
 2686 18c8 85C0     		testl	%eax, %eax
 2687 18ca 7412     		je	L472
 2688 18cc 8B7008   		movl	8(%eax), %esi
 2689 18cf 8B780C   		movl	12(%eax), %edi
 2690              	L473:
 2691 18d2 89F0     		movl	%esi, %eax
 2692 18d4 89FA     		movl	%edi, %edx
 2693              	L471:
 2694 18d6 8D65F4   		leal	-12(%ebp), %esp
 2695 18d9 5B       		popl	%ebx
 2696 18da 5E       		popl	%esi
 2697 18db 5F       		popl	%edi
 2698 18dc 5D       		popl	%ebp
 2699 18dd C3       		ret
 2700              	L472:
 2701 18de E8ED0000 		call	_ptw32_new
 2701      00
 2702 18e3 89C6     		movl	%eax, %esi
 2703 18e5 89D7     		movl	%edx, %edi
 2704 18e7 85C0     		testl	%eax, %eax
 2705 18e9 74E7     		je	L473
 2706 18eb 80888000 		orb	$1, 128(%eax)
 2706      000001
 2707 18f2 C7402401 		movl	$1, 36(%eax)
 2707      000000
 2708 18f9 E8000000 		call	_GetCurrentThreadId@0
 2708      00
 2709 18fe 8D5604   		leal	4(%esi), %edx
 2710 1901 8906     		movl	%eax, (%esi)
 2711 1903 50       		pushl	%eax
 2712 1904 6A02     		pushl	$2
 2713 1906 6A00     		pushl	$0
 2714 1908 6A00     		pushl	$0
 2715 190a 52       		pushl	%edx
 2716 190b 83EC0C   		subl	$12, %esp
 2717 190e E8000000 		call	_GetCurrentProcess@0
 2717      00
 2718 1913 83C40C   		addl	$12, %esp
 2719 1916 50       		pushl	%eax
 2720 1917 50       		pushl	%eax
 2721 1918 50       		pushl	%eax
 2722 1919 E8000000 		call	_GetCurrentThread@0
 2722      00
 2723 191e 5A       		popl	%edx
 2724 191f 59       		popl	%ecx
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 58


 2725 1920 50       		pushl	%eax
 2726 1921 51       		pushl	%ecx
 2727 1922 E8000000 		call	_GetCurrentProcess@0
 2727      00
 2728 1927 890424   		movl	%eax, (%esp)
 2729 192a E8000000 		call	_DuplicateHandle@28
 2729      00
 2730 192f 5A       		popl	%edx
 2731 1930 85C0     		testl	%eax, %eax
 2732 1932 750F     		jne	L475
 2733 1934 50       		pushl	%eax
 2734 1935 50       		pushl	%eax
 2735 1936 57       		pushl	%edi
 2736 1937 56       		pushl	%esi
 2737 1938 E8B30100 		call	_ptw32_threadReusePush
 2737      00
 2738 193d 31D2     		xorl	%edx, %edx
 2739 193f 31C0     		xorl	%eax, %eax
 2740 1941 EB93     		jmp	L471
 2741              	L475:
 2742 1943 83EC0C   		subl	$12, %esp
 2743 1946 8B5604   		movl	4(%esi), %edx
 2744 1949 52       		pushl	%edx
 2745 194a E8000000 		call	_GetThreadPriority@4
 2745      00
 2746 194f 8B0D0C00 		movl	_ptw32_selfThreadKey, %ecx
 2746      0000
 2747 1955 89462C   		movl	%eax, 44(%esi)
 2748 1958 893424   		movl	%esi, (%esp)
 2749 195b 51       		pushl	%ecx
 2750 195c E82F2F00 		call	_pthread_setspecific
 2750      00
 2751 1961 83C410   		addl	$16, %esp
 2752 1964 E969FFFF 		jmp	L473
 2752      FF
 2753 1969 8DB42600 		.p2align 4,,15
 2753      000000
 2754              	.globl _pthread_equal
 2755              		.def	_pthread_equal;	.scl	2;	.type	32;	.endef
 2756              	_pthread_equal:
 2757 1970 55       		pushl	%ebp
 2758 1971 31C0     		xorl	%eax, %eax
 2759 1973 89E5     		movl	%esp, %ebp
 2760 1975 56       		pushl	%esi
 2761 1976 53       		pushl	%ebx
 2762 1977 8B5510   		movl	16(%ebp), %edx
 2763 197a 8B5D08   		movl	8(%ebp), %ebx
 2764 197d 8B750C   		movl	12(%ebp), %esi
 2765 1980 8B4D14   		movl	20(%ebp), %ecx
 2766 1983 39D3     		cmpl	%edx, %ebx
 2767 1985 7409     		je	L478
 2768              	L477:
 2769 1987 5B       		popl	%ebx
 2770 1988 5E       		popl	%esi
 2771 1989 5D       		popl	%ebp
 2772 198a C3       		ret
 2773 198b 908D7426 		.p2align 4,,7
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 59


 2773      00
 2774              	L478:
 2775 1990 39CE     		cmpl	%ecx, %esi
 2776 1992 75F3     		jne	L477
 2777 1994 B8010000 		movl	$1, %eax
 2777      00
 2778 1999 EBEC     		jmp	L477
 2779 199b 908D7426 		.p2align 4,,15
 2779      00
 2780              	.globl _pthread_setconcurrency
 2781              		.def	_pthread_setconcurrency;	.scl	2;	.type	32;	.endef
 2782              	_pthread_setconcurrency:
 2783 19a0 55       		pushl	%ebp
 2784 19a1 B8160000 		movl	$22, %eax
 2784      00
 2785 19a6 89E5     		movl	%esp, %ebp
 2786 19a8 8B5508   		movl	8(%ebp), %edx
 2787 19ab 85D2     		testl	%edx, %edx
 2788 19ad 7808     		js	L479
 2789 19af 89151C00 		movl	%edx, _ptw32_concurrency
 2789      0000
 2790 19b5 31C0     		xorl	%eax, %eax
 2791              	L479:
 2792 19b7 5D       		popl	%ebp
 2793 19b8 C3       		ret
 2794 19b9 8DB42600 		.p2align 4,,15
 2794      000000
 2795              	.globl _pthread_getconcurrency
 2796              		.def	_pthread_getconcurrency;	.scl	2;	.type	32;	.endef
 2797              	_pthread_getconcurrency:
 2798 19c0 55       		pushl	%ebp
 2799 19c1 A11C0000 		movl	_ptw32_concurrency, %eax
 2799      00
 2800 19c6 89E5     		movl	%esp, %ebp
 2801 19c8 5D       		popl	%ebp
 2802 19c9 C3       		ret
 2803 19ca 8DB60000 		.p2align 4,,15
 2803      0000
 2804              	.globl _ptw32_new
 2805              		.def	_ptw32_new;	.scl	2;	.type	32;	.endef
 2806              	_ptw32_new:
 2807 19d0 55       		pushl	%ebp
 2808 19d1 89E5     		movl	%esp, %ebp
 2809 19d3 57       		pushl	%edi
 2810 19d4 56       		pushl	%esi
 2811 19d5 53       		pushl	%ebx
 2812 19d6 83EC0C   		subl	$12, %esp
 2813 19d9 E8A20000 		call	_ptw32_threadReusePop
 2813      00
 2814 19de 89C6     		movl	%eax, %esi
 2815 19e0 89D7     		movl	%edx, %edi
 2816 19e2 89C3     		movl	%eax, %ebx
 2817 19e4 85C0     		testl	%eax, %eax
 2818 19e6 745F     		je	L488
 2819              	L485:
 2820 19e8 C7432C00 		movl	$0, 44(%ebx)
 2820      000000
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 60


 2821 19ef C7432400 		movl	$0, 36(%ebx)
 2821      000000
 2822 19f6 C7433400 		movl	$0, 52(%ebx)
 2822      000000
 2823 19fd C7433801 		movl	$1, 56(%ebx)
 2823      000000
 2824 1a04 C74330FF 		movl	$-1, 48(%ebx)
 2824      FFFFFF
 2825 1a0b C74328FF 		movl	$-1, 40(%ebx)
 2825      FFFFFF
 2826 1a12 6A00     		pushl	$0
 2827 1a14 6A00     		pushl	$0
 2828 1a16 6A01     		pushl	$1
 2829 1a18 6A00     		pushl	$0
 2830 1a1a E8000000 		call	_CreateEventA@16
 2830      00
 2831 1a1f 85C0     		testl	%eax, %eax
 2832 1a21 89433C   		movl	%eax, 60(%ebx)
 2833 1a24 740C     		je	L489
 2834 1a26 89F0     		movl	%esi, %eax
 2835 1a28 89FA     		movl	%edi, %edx
 2836              	L483:
 2837 1a2a 8D65F4   		leal	-12(%ebp), %esp
 2838 1a2d 5B       		popl	%ebx
 2839 1a2e 5E       		popl	%esi
 2840 1a2f 5F       		popl	%edi
 2841 1a30 5D       		popl	%ebp
 2842 1a31 C3       		ret
 2843              		.p2align 4,,7
 2844              	L489:
 2845 1a32 50       		pushl	%eax
 2846 1a33 50       		pushl	%eax
 2847 1a34 8B530C   		movl	12(%ebx), %edx
 2848 1a37 52       		pushl	%edx
 2849 1a38 8B5308   		movl	8(%ebx), %edx
 2850 1a3b 52       		pushl	%edx
 2851 1a3c E8AF0000 		call	_ptw32_threadReusePush
 2851      00
 2852 1a41 31D2     		xorl	%edx, %edx
 2853 1a43 31C0     		xorl	%eax, %eax
 2854 1a45 EBE3     		jmp	L483
 2855              		.p2align 4,,7
 2856              	L488:
 2857 1a47 52       		pushl	%edx
 2858 1a48 52       		pushl	%edx
 2859 1a49 688C0000 		pushl	$140
 2859      00
 2860 1a4e 6A01     		pushl	$1
 2861 1a50 E8000000 		call	_calloc
 2861      00
 2862 1a55 31D2     		xorl	%edx, %edx
 2863 1a57 89C3     		movl	%eax, %ebx
 2864 1a59 83C410   		addl	$16, %esp
 2865 1a5c 31C0     		xorl	%eax, %eax
 2866 1a5e 85DB     		testl	%ebx, %ebx
 2867 1a60 74C8     		je	L483
 2868 1a62 895B08   		movl	%ebx, 8(%ebx)
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 61


 2869 1a65 89DE     		movl	%ebx, %esi
 2870 1a67 C7430C00 		movl	$0, 12(%ebx)
 2870      000000
 2871 1a6e 31FF     		xorl	%edi, %edi
 2872 1a70 E973FFFF 		jmp	L485
 2872      FF
 2873 1a75 8D742600 		.p2align 4,,15
 2873      8DBC2700 
 2873      000000
 2874              	.globl _ptw32_threadReusePop
 2875              		.def	_ptw32_threadReusePop;	.scl	2;	.type	32;	.endef
 2876              	_ptw32_threadReusePop:
 2877 1a80 55       		pushl	%ebp
 2878 1a81 89E5     		movl	%esp, %ebp
 2879 1a83 56       		pushl	%esi
 2880 1a84 53       		pushl	%ebx
 2881 1a85 31F6     		xorl	%esi, %esi
 2882 1a87 83EC0C   		subl	$12, %esp
 2883 1a8a 31DB     		xorl	%ebx, %ebx
 2884 1a8c 68000000 		pushl	$_ptw32_thread_reuse_lock
 2884      00
 2885 1a91 E8000000 		call	_EnterCriticalSection@4
 2885      00
 2886 1a96 8B150400 		movl	_ptw32_threadReuseTop, %edx
 2886      0000
 2887 1a9c 83C40C   		addl	$12, %esp
 2888 1a9f 83FA01   		cmpl	$1, %edx
 2889 1aa2 7419     		je	L491
 2890 1aa4 8B4A10   		movl	16(%edx), %ecx
 2891 1aa7 890D0400 		movl	%ecx, _ptw32_threadReuseTop
 2891      0000
 2892 1aad 49       		decl	%ecx
 2893 1aae 7425     		je	L493
 2894              	L492:
 2895 1ab0 C7421000 		movl	$0, 16(%edx)
 2895      000000
 2896 1ab7 8B5A08   		movl	8(%edx), %ebx
 2897 1aba 8B720C   		movl	12(%edx), %esi
 2898              	L491:
 2899 1abd 83EC0C   		subl	$12, %esp
 2900 1ac0 68000000 		pushl	$_ptw32_thread_reuse_lock
 2900      00
 2901 1ac5 E8000000 		call	_LeaveCriticalSection@4
 2901      00
 2902 1aca 8D65F8   		leal	-8(%ebp), %esp
 2903 1acd 89D8     		movl	%ebx, %eax
 2904 1acf 89F2     		movl	%esi, %edx
 2905 1ad1 5B       		popl	%ebx
 2906 1ad2 5E       		popl	%esi
 2907 1ad3 5D       		popl	%ebp
 2908 1ad4 C3       		ret
 2909              		.p2align 4,,7
 2910              	L493:
 2911 1ad5 C7050800 		movl	$1, _ptw32_threadReuseBottom
 2911      00000100 
 2911      0000
 2912 1adf EBCF     		jmp	L492
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 62


 2913 1ae1 EB0D9090 		.p2align 4,,15
 2913      90909090 
 2913      90909090 
 2913      909090
 2914              	.globl _ptw32_threadReusePush
 2915              		.def	_ptw32_threadReusePush;	.scl	2;	.type	32;	.endef
 2916              	_ptw32_threadReusePush:
 2917 1af0 55       		pushl	%ebp
 2918 1af1 89E5     		movl	%esp, %ebp
 2919 1af3 57       		pushl	%edi
 2920 1af4 56       		pushl	%esi
 2921 1af5 83EC1C   		subl	$28, %esp
 2922 1af8 8B7D08   		movl	8(%ebp), %edi
 2923 1afb 8B450C   		movl	12(%ebp), %eax
 2924 1afe 68000000 		pushl	$_ptw32_thread_reuse_lock
 2924      00
 2925 1b03 89FE     		movl	%edi, %esi
 2926 1b05 897DF0   		movl	%edi, -16(%ebp)
 2927 1b08 8945F4   		movl	%eax, -12(%ebp)
 2928 1b0b E8000000 		call	_EnterCriticalSection@4
 2928      00
 2929 1b10 31C0     		xorl	%eax, %eax
 2930 1b12 8B4F08   		movl	8(%edi), %ecx
 2931 1b15 83C40C   		addl	$12, %esp
 2932 1b18 8B7F0C   		movl	12(%edi), %edi
 2933 1b1b 894DE8   		movl	%ecx, -24(%ebp)
 2934 1b1e FC       		cld
 2935 1b1f 897DEC   		movl	%edi, -20(%ebp)
 2936 1b22 B9230000 		movl	$35, %ecx
 2936      00
 2937 1b27 89F7     		movl	%esi, %edi
 2938 1b29 F3       		rep
 2939 1b2a AB       		stosl
 2940 1b2b 8B4DEC   		movl	-20(%ebp), %ecx
 2941 1b2e 8B55E8   		movl	-24(%ebp), %edx
 2942 1b31 894E0C   		movl	%ecx, 12(%esi)
 2943 1b34 895608   		movl	%edx, 8(%esi)
 2944 1b37 8B460C   		movl	12(%esi), %eax
 2945 1b3a 40       		incl	%eax
 2946 1b3b 89460C   		movl	%eax, 12(%esi)
 2947 1b3e A1080000 		movl	_ptw32_threadReuseBottom, %eax
 2947      00
 2948 1b43 C7461001 		movl	$1, 16(%esi)
 2948      000000
 2949 1b4a 83F801   		cmpl	$1, %eax
 2950 1b4d 7421     		je	L495
 2951 1b4f 8B4DF0   		movl	-16(%ebp), %ecx
 2952 1b52 894810   		movl	%ecx, 16(%eax)
 2953              	L496:
 2954 1b55 83EC0C   		subl	$12, %esp
 2955 1b58 89350800 		movl	%esi, _ptw32_threadReuseBottom
 2955      0000
 2956 1b5e 68000000 		pushl	$_ptw32_thread_reuse_lock
 2956      00
 2957 1b63 E8000000 		call	_LeaveCriticalSection@4
 2957      00
 2958 1b68 8D65F8   		leal	-8(%ebp), %esp
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 63


 2959 1b6b 5E       		popl	%esi
 2960 1b6c 5F       		popl	%edi
 2961 1b6d 5D       		popl	%ebp
 2962 1b6e C3       		ret
 2963 1b6f 90       		.p2align 4,,7
 2964              	L495:
 2965 1b70 8B55F0   		movl	-16(%ebp), %edx
 2966 1b73 89150400 		movl	%edx, _ptw32_threadReuseTop
 2966      0000
 2967 1b79 EBDA     		jmp	L496
 2968 1b7b 908D7426 		.p2align 4,,15
 2968      00
 2969              	.globl _pthreadCancelableWait
 2970              		.def	_pthreadCancelableWait;	.scl	2;	.type	32;	.endef
 2971              	_pthreadCancelableWait:
 2972 1b80 55       		pushl	%ebp
 2973 1b81 89E5     		movl	%esp, %ebp
 2974 1b83 83EC10   		subl	$16, %esp
 2975 1b86 8B5508   		movl	8(%ebp), %edx
 2976 1b89 6AFF     		pushl	$-1
 2977 1b8b 52       		pushl	%edx
 2978 1b8c E81F3A00 		call	_ptw32_cancelable_wait
 2978      00
 2979 1b91 89EC     		movl	%ebp, %esp
 2980 1b93 5D       		popl	%ebp
 2981 1b94 C3       		ret
 2982 1b95 8D742600 		.p2align 4,,15
 2982      8DBC2700 
 2982      000000
 2983              	.globl _pthreadCancelableTimedWait
 2984              		.def	_pthreadCancelableTimedWait;	.scl	2;	.type	32;	.endef
 2985              	_pthreadCancelableTimedWait:
 2986 1ba0 55       		pushl	%ebp
 2987 1ba1 89E5     		movl	%esp, %ebp
 2988 1ba3 5D       		popl	%ebp
 2989 1ba4 E9073A00 		jmp	_ptw32_cancelable_wait
 2989      00
 2990              		.data
 2991              		.align 4
 2992              	_ptw32_recursive_mutexattr_s:
 2993 0030 00000000 		.long	0
 2994 0034 01000000 		.long	1
 2995              		.align 4
 2996              	_ptw32_errorcheck_mutexattr_s:
 2997 0038 00000000 		.long	0
 2998 003c 02000000 		.long	2
 2999              		.align 4
 3000              	_ptw32_recursive_mutexattr:
 3001 0040 30000000 		.long	_ptw32_recursive_mutexattr_s
 3002              		.align 4
 3003              	_ptw32_errorcheck_mutexattr:
 3004 0044 38000000 		.long	_ptw32_errorcheck_mutexattr_s
 3005 0048 00000000 		.text
 3005      00000000 
 3006 1ba9 8DB42600 		.p2align 4,,15
 3006      000000
 3007              	.globl _pthread_mutex_init
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 64


 3008              		.def	_pthread_mutex_init;	.scl	2;	.type	32;	.endef
 3009              	_pthread_mutex_init:
 3010 1bb0 55       		pushl	%ebp
 3011 1bb1 B8160000 		movl	$22, %eax
 3011      00
 3012 1bb6 89E5     		movl	%esp, %ebp
 3013 1bb8 57       		pushl	%edi
 3014 1bb9 56       		pushl	%esi
 3015 1bba 31FF     		xorl	%edi, %edi
 3016 1bbc 53       		pushl	%ebx
 3017 1bbd 83EC0C   		subl	$12, %esp
 3018 1bc0 8B4D08   		movl	8(%ebp), %ecx
 3019 1bc3 8B750C   		movl	12(%ebp), %esi
 3020 1bc6 85C9     		testl	%ecx, %ecx
 3021 1bc8 7466     		je	L526
 3022 1bca 85F6     		testl	%esi, %esi
 3023 1bcc 740F     		je	L528
 3024 1bce 8B06     		movl	(%esi), %eax
 3025 1bd0 85C0     		testl	%eax, %eax
 3026 1bd2 7409     		je	L528
 3027 1bd4 833801   		cmpl	$1, (%eax)
 3028 1bd7 0F848300 		je	L534
 3028      0000
 3029              	L528:
 3030 1bdd 50       		pushl	%eax
 3031 1bde 50       		pushl	%eax
 3032 1bdf 6A18     		pushl	$24
 3033 1be1 6A01     		pushl	$1
 3034 1be3 E8000000 		call	_calloc
 3034      00
 3035 1be8 83C410   		addl	$16, %esp
 3036 1beb 89C3     		movl	%eax, %ebx
 3037 1bed 85C0     		testl	%eax, %eax
 3038 1bef 7463     		je	L535
 3039 1bf1 C7000000 		movl	$0, (%eax)
 3039      0000
 3040 1bf7 85F6     		testl	%esi, %esi
 3041 1bf9 C7400400 		movl	$0, 4(%eax)
 3041      000000
 3042 1c00 744E     		je	L531
 3043 1c02 8B06     		movl	(%esi), %eax
 3044 1c04 85C0     		testl	%eax, %eax
 3045 1c06 7448     		je	L531
 3046 1c08 8B4004   		movl	4(%eax), %eax
 3047              	L532:
 3048 1c0b 894308   		movl	%eax, 8(%ebx)
 3049 1c0e C7430C00 		movl	$0, 12(%ebx)
 3049      000000
 3050 1c15 6A00     		pushl	$0
 3051 1c17 6A00     		pushl	$0
 3052 1c19 6A00     		pushl	$0
 3053 1c1b 6A00     		pushl	$0
 3054 1c1d E8000000 		call	_CreateEventA@16
 3054      00
 3055 1c22 85C0     		testl	%eax, %eax
 3056 1c24 894314   		movl	%eax, 20(%ebx)
 3057 1c27 740F     		je	L536
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 65


 3058              	L530:
 3059 1c29 8B5508   		movl	8(%ebp), %edx
 3060 1c2c 89F8     		movl	%edi, %eax
 3061 1c2e 891A     		movl	%ebx, (%edx)
 3062              	L526:
 3063 1c30 8D65F4   		leal	-12(%ebp), %esp
 3064 1c33 5B       		popl	%ebx
 3065 1c34 5E       		popl	%esi
 3066 1c35 5F       		popl	%edi
 3067 1c36 5D       		popl	%ebp
 3068 1c37 C3       		ret
 3069              		.p2align 4,,7
 3070              	L536:
 3071 1c38 83EC0C   		subl	$12, %esp
 3072 1c3b BF1C0000 		movl	$28, %edi
 3072      00
 3073 1c40 53       		pushl	%ebx
 3074 1c41 31DB     		xorl	%ebx, %ebx
 3075 1c43 E8000000 		call	_free
 3075      00
 3076 1c48 83C410   		addl	$16, %esp
 3077 1c4b EBDC     		jmp	L530
 3078 1c4d 8D7600   		.p2align 4,,7
 3079              	L531:
 3080 1c50 31C0     		xorl	%eax, %eax
 3081 1c52 EBB7     		jmp	L532
 3082              		.p2align 4,,7
 3083              	L535:
 3084 1c54 BF0C0000 		movl	$12, %edi
 3084      00
 3085 1c59 EBCE     		jmp	L530
 3086 1c5b 908D7426 		.p2align 4,,7
 3086      00
 3087              	L534:
 3088 1c60 B8280000 		movl	$40, %eax
 3088      00
 3089 1c65 EBC9     		jmp	L526
 3090 1c67 89F68DBC 		.p2align 4,,15
 3090      27000000 
 3090      00
 3091              	.globl _pthread_mutex_destroy
 3092              		.def	_pthread_mutex_destroy;	.scl	2;	.type	32;	.endef
 3093              	_pthread_mutex_destroy:
 3094 1c70 55       		pushl	%ebp
 3095 1c71 89E5     		movl	%esp, %ebp
 3096 1c73 57       		pushl	%edi
 3097 1c74 56       		pushl	%esi
 3098 1c75 53       		pushl	%ebx
 3099 1c76 31DB     		xorl	%ebx, %ebx
 3100 1c78 83EC0C   		subl	$12, %esp
 3101 1c7b 8B7508   		movl	8(%ebp), %esi
 3102 1c7e 8B06     		movl	(%esi), %eax
 3103 1c80 83F8FC   		cmpl	$-4, %eax
 3104 1c83 0F878E00 		ja	L538
 3104      0000
 3105 1c89 83EC0C   		subl	$12, %esp
 3106 1c8c 8D7DF0   		leal	-16(%ebp), %edi
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 66


 3107 1c8f 8945F0   		movl	%eax, -16(%ebp)
 3108 1c92 57       		pushl	%edi
 3109 1c93 E8480600 		call	_pthread_mutex_trylock
 3109      00
 3110 1c98 83C410   		addl	$16, %esp
 3111 1c9b 89C3     		movl	%eax, %ebx
 3112 1c9d 85C0     		testl	%eax, %eax
 3113 1c9f 7526     		jne	L547
 3114 1ca1 8B55F0   		movl	-16(%ebp), %edx
 3115 1ca4 837A0801 		cmpl	$1, 8(%edx)
 3116 1ca8 745A     		je	L550
 3117              	L541:
 3118 1caa 83EC0C   		subl	$12, %esp
 3119 1cad C7060000 		movl	$0, (%esi)
 3119      0000
 3120 1cb3 57       		pushl	%edi
 3121 1cb4 E8570500 		call	_pthread_mutex_unlock
 3121      00
 3122 1cb9 83C410   		addl	$16, %esp
 3123 1cbc 89C3     		movl	%eax, %ebx
 3124 1cbe 85C0     		testl	%eax, %eax
 3125 1cc0 740F     		je	L551
 3126 1cc2 8B7DF0   		movl	-16(%ebp), %edi
 3127 1cc5 893E     		movl	%edi, (%esi)
 3128              		.p2align 4,,7
 3129              	L547:
 3130 1cc7 8D65F4   		leal	-12(%ebp), %esp
 3131 1cca 89D8     		movl	%ebx, %eax
 3132 1ccc 5B       		popl	%ebx
 3133 1ccd 5E       		popl	%esi
 3134 1cce 5F       		popl	%edi
 3135 1ccf 5D       		popl	%ebp
 3136 1cd0 C3       		ret
 3137              	L551:
 3138 1cd1 8B4DF0   		movl	-16(%ebp), %ecx
 3139 1cd4 83EC0C   		subl	$12, %esp
 3140 1cd7 8B5114   		movl	20(%ecx), %edx
 3141 1cda 52       		pushl	%edx
 3142 1cdb E8000000 		call	_CloseHandle@4
 3142      00
 3143 1ce0 83C40C   		addl	$12, %esp
 3144 1ce3 85C0     		testl	%eax, %eax
 3145 1ce5 750C     		jne	L543
 3146 1ce7 8B55F0   		movl	-16(%ebp), %edx
 3147 1cea BB160000 		movl	$22, %ebx
 3147      00
 3148 1cef 8916     		movl	%edx, (%esi)
 3149 1cf1 EBD4     		jmp	L547
 3150              	L543:
 3151 1cf3 83EC0C   		subl	$12, %esp
 3152 1cf6 8B45F0   		movl	-16(%ebp), %eax
 3153 1cf9 50       		pushl	%eax
 3154 1cfa E8000000 		call	_free
 3154      00
 3155 1cff 83C410   		addl	$16, %esp
 3156 1d02 EBC3     		jmp	L547
 3157              		.p2align 4,,7
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 67


 3158              	L550:
 3159 1d04 8B4204   		movl	4(%edx), %eax
 3160 1d07 83F801   		cmpl	$1, %eax
 3161 1d0a 749E     		je	L541
 3162 1d0c 48       		decl	%eax
 3163 1d0d BB100000 		movl	$16, %ebx
 3163      00
 3164 1d12 894204   		movl	%eax, 4(%edx)
 3165 1d15 EBB0     		jmp	L547
 3166              		.p2align 4,,7
 3167              	L538:
 3168 1d17 83EC0C   		subl	$12, %esp
 3169 1d1a 68000000 		pushl	$_ptw32_mutex_test_init_lock
 3169      00
 3170 1d1f E8000000 		call	_EnterCriticalSection@4
 3170      00
 3171 1d24 83C40C   		addl	$12, %esp
 3172 1d27 833EFC   		cmpl	$-4, (%esi)
 3173 1d2a 7618     		jbe	L548
 3174 1d2c C7060000 		movl	$0, (%esi)
 3174      0000
 3175              	L549:
 3176 1d32 83EC0C   		subl	$12, %esp
 3177 1d35 68000000 		pushl	$_ptw32_mutex_test_init_lock
 3177      00
 3178 1d3a E8000000 		call	_LeaveCriticalSection@4
 3178      00
 3179 1d3f 83C40C   		addl	$12, %esp
 3180 1d42 EB83     		jmp	L547
 3181              		.p2align 4,,7
 3182              	L548:
 3183 1d44 BB100000 		movl	$16, %ebx
 3183      00
 3184 1d49 EBE7     		jmp	L549
 3185 1d4b 908D7426 		.p2align 4,,15
 3185      00
 3186              	.globl _pthread_mutexattr_init
 3187              		.def	_pthread_mutexattr_init;	.scl	2;	.type	32;	.endef
 3188              	_pthread_mutexattr_init:
 3189 1d50 55       		pushl	%ebp
 3190 1d51 89E5     		movl	%esp, %ebp
 3191 1d53 53       		pushl	%ebx
 3192 1d54 83EC0C   		subl	$12, %esp
 3193 1d57 31DB     		xorl	%ebx, %ebx
 3194 1d59 6A08     		pushl	$8
 3195 1d5b 6A01     		pushl	$1
 3196 1d5d E8000000 		call	_calloc
 3196      00
 3197 1d62 83C410   		addl	$16, %esp
 3198 1d65 89C2     		movl	%eax, %edx
 3199 1d67 85C0     		testl	%eax, %eax
 3200 1d69 741B     		je	L555
 3201 1d6b C7000000 		movl	$0, (%eax)
 3201      0000
 3202 1d71 C7400400 		movl	$0, 4(%eax)
 3202      000000
 3203              	L554:
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 68


 3204 1d78 8B4D08   		movl	8(%ebp), %ecx
 3205 1d7b 89D8     		movl	%ebx, %eax
 3206 1d7d 8911     		movl	%edx, (%ecx)
 3207 1d7f 8B5DFC   		movl	-4(%ebp), %ebx
 3208 1d82 89EC     		movl	%ebp, %esp
 3209 1d84 5D       		popl	%ebp
 3210 1d85 C3       		ret
 3211              		.p2align 4,,7
 3212              	L555:
 3213 1d86 BB0C0000 		movl	$12, %ebx
 3213      00
 3214 1d8b EBEB     		jmp	L554
 3215 1d8d 8D7600   		.p2align 4,,15
 3216              	.globl _pthread_mutexattr_destroy
 3217              		.def	_pthread_mutexattr_destroy;	.scl	2;	.type	32;	.endef
 3218              	_pthread_mutexattr_destroy:
 3219 1d90 55       		pushl	%ebp
 3220 1d91 89E5     		movl	%esp, %ebp
 3221 1d93 53       		pushl	%ebx
 3222 1d94 50       		pushl	%eax
 3223 1d95 31DB     		xorl	%ebx, %ebx
 3224 1d97 8B4508   		movl	8(%ebp), %eax
 3225 1d9a 85C0     		testl	%eax, %eax
 3226 1d9c 7406     		je	L558
 3227 1d9e 8B10     		movl	(%eax), %edx
 3228 1da0 85D2     		testl	%edx, %edx
 3229 1da2 750E     		jne	L557
 3230              	L558:
 3231 1da4 BB160000 		movl	$22, %ebx
 3231      00
 3232              	L559:
 3233 1da9 89D8     		movl	%ebx, %eax
 3234 1dab 8B5DFC   		movl	-4(%ebp), %ebx
 3235 1dae 89EC     		movl	%ebp, %esp
 3236 1db0 5D       		popl	%ebp
 3237 1db1 C3       		ret
 3238              		.p2align 4,,7
 3239              	L557:
 3240 1db2 83EC0C   		subl	$12, %esp
 3241 1db5 C7000000 		movl	$0, (%eax)
 3241      0000
 3242 1dbb 52       		pushl	%edx
 3243 1dbc E8000000 		call	_free
 3243      00
 3244 1dc1 83C410   		addl	$16, %esp
 3245 1dc4 EBE3     		jmp	L559
 3246 1dc6 8D76008D 		.p2align 4,,15
 3246      BC270000 
 3246      0000
 3247              	.globl _pthread_mutexattr_getpshared
 3248              		.def	_pthread_mutexattr_getpshared;	.scl	2;	.type	32;	.endef
 3249              	_pthread_mutexattr_getpshared:
 3250 1dd0 55       		pushl	%ebp
 3251 1dd1 89E5     		movl	%esp, %ebp
 3252 1dd3 8B4508   		movl	8(%ebp), %eax
 3253 1dd6 8B550C   		movl	12(%ebp), %edx
 3254 1dd9 85C0     		testl	%eax, %eax
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 69


 3255 1ddb 7413     		je	L561
 3256 1ddd 8B00     		movl	(%eax), %eax
 3257 1ddf 85C0     		testl	%eax, %eax
 3258 1de1 740D     		je	L561
 3259 1de3 85D2     		testl	%edx, %edx
 3260 1de5 7409     		je	L561
 3261 1de7 8B08     		movl	(%eax), %ecx
 3262 1de9 31C0     		xorl	%eax, %eax
 3263 1deb 890A     		movl	%ecx, (%edx)
 3264              	L562:
 3265 1ded 5D       		popl	%ebp
 3266 1dee C3       		ret
 3267 1def 90       		.p2align 4,,7
 3268              	L561:
 3269 1df0 B8160000 		movl	$22, %eax
 3269      00
 3270 1df5 EBF6     		jmp	L562
 3271 1df7 89F68DBC 		.p2align 4,,15
 3271      27000000 
 3271      00
 3272              	.globl _pthread_mutexattr_setpshared
 3273              		.def	_pthread_mutexattr_setpshared;	.scl	2;	.type	32;	.endef
 3274              	_pthread_mutexattr_setpshared:
 3275 1e00 55       		pushl	%ebp
 3276 1e01 89E5     		movl	%esp, %ebp
 3277 1e03 8B4508   		movl	8(%ebp), %eax
 3278 1e06 8B4D0C   		movl	12(%ebp), %ecx
 3279 1e09 85C0     		testl	%eax, %eax
 3280 1e0b 7413     		je	L564
 3281 1e0d 8B10     		movl	(%eax), %edx
 3282 1e0f 85D2     		testl	%edx, %edx
 3283 1e11 740D     		je	L564
 3284 1e13 83F901   		cmpl	$1, %ecx
 3285 1e16 7708     		ja	L564
 3286 1e18 31C0     		xorl	%eax, %eax
 3287 1e1a 890A     		movl	%ecx, (%edx)
 3288              	L567:
 3289 1e1c 5D       		popl	%ebp
 3290 1e1d C3       		ret
 3291 1e1e 89F6     		.p2align 4,,7
 3292              	L564:
 3293 1e20 B8160000 		movl	$22, %eax
 3293      00
 3294 1e25 EBF5     		jmp	L567
 3295 1e27 89F68DBC 		.p2align 4,,15
 3295      27000000 
 3295      00
 3296              	.globl _pthread_mutexattr_settype
 3297              		.def	_pthread_mutexattr_settype;	.scl	2;	.type	32;	.endef
 3298              	_pthread_mutexattr_settype:
 3299 1e30 55       		pushl	%ebp
 3300 1e31 31C0     		xorl	%eax, %eax
 3301 1e33 89E5     		movl	%esp, %ebp
 3302 1e35 8B5508   		movl	8(%ebp), %edx
 3303 1e38 8B4D0C   		movl	12(%ebp), %ecx
 3304 1e3b 85D2     		testl	%edx, %edx
 3305 1e3d 7411     		je	L569
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 70


 3306 1e3f 8B12     		movl	(%edx), %edx
 3307 1e41 85D2     		testl	%edx, %edx
 3308 1e43 740B     		je	L569
 3309 1e45 83F902   		cmpl	$2, %ecx
 3310 1e48 7706     		ja	L569
 3311 1e4a 894A04   		movl	%ecx, 4(%edx)
 3312              	L576:
 3313 1e4d 5D       		popl	%ebp
 3314 1e4e C3       		ret
 3315 1e4f 90       		.p2align 4,,7
 3316              	L569:
 3317 1e50 B8160000 		movl	$22, %eax
 3317      00
 3318 1e55 EBF6     		jmp	L576
 3319 1e57 89F68DBC 		.p2align 4,,15
 3319      27000000 
 3319      00
 3320              	.globl _pthread_mutexattr_gettype
 3321              		.def	_pthread_mutexattr_gettype;	.scl	2;	.type	32;	.endef
 3322              	_pthread_mutexattr_gettype:
 3323 1e60 55       		pushl	%ebp
 3324 1e61 31D2     		xorl	%edx, %edx
 3325 1e63 89E5     		movl	%esp, %ebp
 3326 1e65 8B4508   		movl	8(%ebp), %eax
 3327 1e68 8B4D0C   		movl	12(%ebp), %ecx
 3328 1e6b 85C0     		testl	%eax, %eax
 3329 1e6d 7413     		je	L578
 3330 1e6f 8B00     		movl	(%eax), %eax
 3331 1e71 85C0     		testl	%eax, %eax
 3332 1e73 740D     		je	L578
 3333 1e75 85C9     		testl	%ecx, %ecx
 3334 1e77 7409     		je	L578
 3335 1e79 8B4004   		movl	4(%eax), %eax
 3336 1e7c 8901     		movl	%eax, (%ecx)
 3337              	L579:
 3338 1e7e 89D0     		movl	%edx, %eax
 3339 1e80 5D       		popl	%ebp
 3340 1e81 C3       		ret
 3341              		.p2align 4,,7
 3342              	L578:
 3343 1e82 BA160000 		movl	$22, %edx
 3343      00
 3344 1e87 EBF5     		jmp	L579
 3345 1e89 8DB42600 		.p2align 4,,15
 3345      000000
 3346              	.globl _pthread_mutex_lock
 3347              		.def	_pthread_mutex_lock;	.scl	2;	.type	32;	.endef
 3348              	_pthread_mutex_lock:
 3349 1e90 55       		pushl	%ebp
 3350 1e91 B8160000 		movl	$22, %eax
 3350      00
 3351 1e96 89E5     		movl	%esp, %ebp
 3352 1e98 57       		pushl	%edi
 3353 1e99 56       		pushl	%esi
 3354 1e9a 31FF     		xorl	%edi, %edi
 3355 1e9c 53       		pushl	%ebx
 3356 1e9d 83EC0C   		subl	$12, %esp
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 71


 3357 1ea0 8B7508   		movl	8(%ebp), %esi
 3358 1ea3 8B1E     		movl	(%esi), %ebx
 3359 1ea5 85DB     		testl	%ebx, %ebx
 3360 1ea7 742A     		je	L580
 3361 1ea9 83FBFC   		cmpl	$-4, %ebx
 3362 1eac 0F873901 		ja	L631
 3362      0000
 3363              	L582:
 3364 1eb2 8B5308   		movl	8(%ebx), %edx
 3365 1eb5 85D2     		testl	%edx, %edx
 3366 1eb7 756B     		jne	L592
 3367 1eb9 8B0D2400 		movl	_ptw32_smp_system, %ecx
 3367      0000
 3368 1ebf BA010000 		movl	$1, %edx
 3368      00
 3369 1ec4 85C9     		testl	%ecx, %ecx
 3370 1ec6 7451     		je	L594
 3371              	/APP
 3372 1ec8 8713     		xchgl          %edx,(%ebx)
 3373              	/NO_APP
 3374              	L595:
 3375 1eca 83CEFF   		orl	$-1, %esi
 3376 1ecd 85D2     		testl	%edx, %edx
 3377 1ecf 750F     		jne	L597
 3378              	L605:
 3379 1ed1 89F8     		movl	%edi, %eax
 3380              	L580:
 3381 1ed3 8D65F4   		leal	-12(%ebp), %esp
 3382 1ed6 5B       		popl	%ebx
 3383 1ed7 5E       		popl	%esi
 3384 1ed8 5F       		popl	%edi
 3385 1ed9 5D       		popl	%ebp
 3386 1eda C3       		ret
 3387 1edb 908D7426 		.p2align 4,,7
 3387      00
 3388              	L597:
 3389 1ee0 85C9     		testl	%ecx, %ecx
 3390 1ee2 742C     		je	L600
 3391 1ee4 89F0     		movl	%esi, %eax
 3392              	/APP
 3393 1ee6 8703     		xchgl          %eax,(%ebx)
 3394              	/NO_APP
 3395              	L601:
 3396 1ee8 85C0     		testl	%eax, %eax
 3397 1eea 74E5     		je	L605
 3398 1eec 50       		pushl	%eax
 3399 1eed 50       		pushl	%eax
 3400 1eee 6AFF     		pushl	$-1
 3401 1ef0 8B4314   		movl	20(%ebx), %eax
 3402 1ef3 50       		pushl	%eax
 3403 1ef4 E8000000 		call	_WaitForSingleObject@8
 3403      00
 3404 1ef9 59       		popl	%ecx
 3405 1efa 85C0     		testl	%eax, %eax
 3406 1efc 5A       		popl	%edx
 3407 1efd 7508     		jne	L626
 3408 1eff 8B0D2400 		movl	_ptw32_smp_system, %ecx
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 72


 3408      0000
 3409 1f05 EBD9     		jmp	L597
 3410              	L626:
 3411 1f07 BF160000 		movl	$22, %edi
 3411      00
 3412 1f0c EBC3     		jmp	L605
 3413 1f0e 89F6     		.p2align 4,,7
 3414              	L600:
 3415              	/APP
 3416              		0:
 3417 1f10 8B03     		movl           (%ebx),%eax
 3418 1f12 0FB133   		cmpxchgl       %esi,(%ebx)
 3419 1f15 75F9     		jnz            0b
 3420              	/NO_APP
 3421 1f17 EBCF     		jmp	L601
 3422              	L594:
 3423              	/APP
 3424              		0:
 3425 1f19 8B03     		movl           (%ebx),%eax
 3426 1f1b 0FB113   		cmpxchgl       %edx,(%ebx)
 3427 1f1e 75F9     		jnz            0b
 3428              	/NO_APP
 3429 1f20 89C2     		movl	%eax, %edx
 3430 1f22 EBA6     		jmp	L595
 3431              	L592:
 3432 1f24 E887F9FF 		call	_pthread_self
 3432      FF
 3433 1f29 8B352400 		movl	_ptw32_smp_system, %esi
 3433      0000
 3434 1f2f 31C9     		xorl	%ecx, %ecx
 3435 1f31 85F6     		testl	%esi, %esi
 3436 1f33 8955EC   		movl	%edx, -20(%ebp)
 3437 1f36 8945E8   		movl	%eax, -24(%ebp)
 3438 1f39 BA010000 		movl	$1, %edx
 3438      00
 3439 1f3e 0F849D00 		je	L607
 3439      0000
 3440 1f44 89C8     		movl	%ecx, %eax
 3441              	/APP
 3442 1f46 F0       		lock
 3443 1f47 0FB113   		cmpxchgl       %edx,(%ebx)
 3444              	/NO_APP
 3445              	L629:
 3446 1f4a 85C0     		testl	%eax, %eax
 3447 1f4c 7518     		jne	L633
 3448              	L630:
 3449 1f4e 8B4DE8   		movl	-24(%ebp), %ecx
 3450 1f51 8B75EC   		movl	-20(%ebp), %esi
 3451 1f54 C7430401 		movl	$1, 4(%ebx)
 3451      000000
 3452 1f5b 894B0C   		movl	%ecx, 12(%ebx)
 3453 1f5e 897310   		movl	%esi, 16(%ebx)
 3454 1f61 E96BFFFF 		jmp	L605
 3454      FF
 3455              	L633:
 3456 1f66 8B45EC   		movl	-20(%ebp), %eax
 3457 1f69 8B4DE8   		movl	-24(%ebp), %ecx
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 73


 3458 1f6c 50       		pushl	%eax
 3459 1f6d 51       		pushl	%ecx
 3460 1f6e 8B7310   		movl	16(%ebx), %esi
 3461 1f71 56       		pushl	%esi
 3462 1f72 83CEFF   		orl	$-1, %esi
 3463 1f75 8B530C   		movl	12(%ebx), %edx
 3464 1f78 52       		pushl	%edx
 3465 1f79 E8F2F9FF 		call	_pthread_equal
 3465      FF
 3466 1f7e 83C410   		addl	$16, %esp
 3467 1f81 85C0     		testl	%eax, %eax
 3468 1f83 741C     		je	L615
 3469 1f85 837B0801 		cmpl	$1, 8(%ebx)
 3470 1f89 740A     		je	L634
 3471 1f8b BF240000 		movl	$36, %edi
 3471      00
 3472 1f90 E93CFFFF 		jmp	L605
 3472      FF
 3473              	L634:
 3474 1f95 8B5304   		movl	4(%ebx), %edx
 3475 1f98 42       		incl	%edx
 3476 1f99 895304   		movl	%edx, 4(%ebx)
 3477 1f9c E930FFFF 		jmp	L605
 3477      FF
 3478              		.p2align 4,,7
 3479              	L615:
 3480 1fa1 8B152400 		movl	_ptw32_smp_system, %edx
 3480      0000
 3481 1fa7 85D2     		testl	%edx, %edx
 3482 1fa9 742D     		je	L618
 3483 1fab 89F0     		movl	%esi, %eax
 3484              	/APP
 3485 1fad 8703     		xchgl          %eax,(%ebx)
 3486              	/NO_APP
 3487              	L619:
 3488 1faf 85C0     		testl	%eax, %eax
 3489 1fb1 7418     		je	L616
 3490 1fb3 50       		pushl	%eax
 3491 1fb4 50       		pushl	%eax
 3492 1fb5 6AFF     		pushl	$-1
 3493 1fb7 8B4B14   		movl	20(%ebx), %ecx
 3494 1fba 51       		pushl	%ecx
 3495 1fbb E8000000 		call	_WaitForSingleObject@8
 3495      00
 3496 1fc0 5A       		popl	%edx
 3497 1fc1 85C0     		testl	%eax, %eax
 3498 1fc3 59       		popl	%ecx
 3499 1fc4 74DB     		je	L615
 3500 1fc6 BF160000 		movl	$22, %edi
 3500      00
 3501              	L616:
 3502 1fcb 85FF     		testl	%edi, %edi
 3503 1fcd 0F85FEFE 		jne	L605
 3503      FFFF
 3504 1fd3 E976FFFF 		jmp	L630
 3504      FF
 3505              	L618:
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 74


 3506              	/APP
 3507              		0:
 3508 1fd8 8B03     		movl           (%ebx),%eax
 3509 1fda 0FB133   		cmpxchgl       %esi,(%ebx)
 3510 1fdd 75F9     		jnz            0b
 3511              	/NO_APP
 3512 1fdf EBCE     		jmp	L619
 3513              	L607:
 3514 1fe1 89F0     		movl	%esi, %eax
 3515              	/APP
 3516 1fe3 0FB113   		cmpxchgl       %edx,(%ebx)
 3517              	/NO_APP
 3518 1fe6 E95FFFFF 		jmp	L629
 3518      FF
 3519              	L631:
 3520 1feb 83EC0C   		subl	$12, %esp
 3521 1fee 31DB     		xorl	%ebx, %ebx
 3522 1ff0 68000000 		pushl	$_ptw32_mutex_test_init_lock
 3522      00
 3523 1ff5 E8000000 		call	_EnterCriticalSection@4
 3523      00
 3524 1ffa 8B06     		movl	(%esi), %eax
 3525 1ffc 83C40C   		addl	$12, %esp
 3526 1fff 83F8FF   		cmpl	$-1, %eax
 3527 2002 7455     		je	L635
 3528 2004 83F8FE   		cmpl	$-2, %eax
 3529 2007 7447     		je	L636
 3530 2009 83F8FD   		cmpl	$-3, %eax
 3531 200c 742E     		je	L637
 3532 200e 85C0     		testl	%eax, %eax
 3533 2010 7423     		je	L638
 3534              	L585:
 3535 2012 83EC0C   		subl	$12, %esp
 3536 2015 89DF     		movl	%ebx, %edi
 3537 2017 68000000 		pushl	$_ptw32_mutex_test_init_lock
 3537      00
 3538 201c E8000000 		call	_LeaveCriticalSection@4
 3538      00
 3539 2021 89D8     		movl	%ebx, %eax
 3540 2023 83C40C   		addl	$12, %esp
 3541 2026 85DB     		testl	%ebx, %ebx
 3542 2028 0F85A5FE 		jne	L580
 3542      FFFF
 3543 202e 8B1E     		movl	(%esi), %ebx
 3544 2030 E97DFEFF 		jmp	L582
 3544      FF
 3545              	L638:
 3546 2035 BB160000 		movl	$22, %ebx
 3546      00
 3547 203a EBD6     		jmp	L585
 3548              	L637:
 3549 203c 50       		pushl	%eax
 3550 203d 50       		pushl	%eax
 3551 203e 68440000 		pushl	$_ptw32_errorcheck_mutexattr
 3551      00
 3552              	L628:
 3553 2043 56       		pushl	%esi
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 75


 3554 2044 E867FBFF 		call	_pthread_mutex_init
 3554      FF
 3555 2049 83C410   		addl	$16, %esp
 3556 204c 89C3     		movl	%eax, %ebx
 3557 204e EBC2     		jmp	L585
 3558              	L636:
 3559 2050 50       		pushl	%eax
 3560 2051 50       		pushl	%eax
 3561 2052 68400000 		pushl	$_ptw32_recursive_mutexattr
 3561      00
 3562 2057 EBEA     		jmp	L628
 3563              	L635:
 3564 2059 50       		pushl	%eax
 3565 205a 50       		pushl	%eax
 3566 205b 6A00     		pushl	$0
 3567 205d EBE4     		jmp	L628
 3568              		.def	___divdi3;	.scl	2;	.type	32;	.endef
 3569 205f 90       		.p2align 4,,15
 3570              	.globl _pthread_mutex_timedlock
 3571              		.def	_pthread_mutex_timedlock;	.scl	2;	.type	32;	.endef
 3572              	_pthread_mutex_timedlock:
 3573 2060 55       		pushl	%ebp
 3574 2061 89E5     		movl	%esp, %ebp
 3575 2063 57       		pushl	%edi
 3576 2064 56       		pushl	%esi
 3577 2065 53       		pushl	%ebx
 3578 2066 83EC0C   		subl	$12, %esp
 3579 2069 8B7508   		movl	8(%ebp), %esi
 3580 206c 8B1E     		movl	(%esi), %ebx
 3581 206e 83FBFC   		cmpl	$-4, %ebx
 3582 2071 0F872001 		ja	L702
 3582      0000
 3583              	L654:
 3584 2077 8B4308   		movl	8(%ebx), %eax
 3585 207a 85C0     		testl	%eax, %eax
 3586 207c 7566     		jne	L664
 3587 207e 8B0D2400 		movl	_ptw32_smp_system, %ecx
 3587      0000
 3588 2084 BA010000 		movl	$1, %edx
 3588      00
 3589 2089 85C9     		testl	%ecx, %ecx
 3590 208b 744C     		je	L666
 3591              	/APP
 3592 208d 8713     		xchgl          %edx,(%ebx)
 3593              	/NO_APP
 3594              	L667:
 3595 208f 83CEFF   		orl	$-1, %esi
 3596 2092 85D2     		testl	%edx, %edx
 3597 2094 750A     		jne	L669
 3598              	L677:
 3599 2096 31C0     		xorl	%eax, %eax
 3600              	L653:
 3601 2098 8D65F4   		leal	-12(%ebp), %esp
 3602 209b 5B       		popl	%ebx
 3603 209c 5E       		popl	%esi
 3604 209d 5F       		popl	%edi
 3605 209e 5D       		popl	%ebp
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 76


 3606 209f C3       		ret
 3607              		.p2align 4,,7
 3608              	L669:
 3609 20a0 85C9     		testl	%ecx, %ecx
 3610 20a2 742C     		je	L672
 3611 20a4 89F0     		movl	%esi, %eax
 3612              	/APP
 3613 20a6 8703     		xchgl          %eax,(%ebx)
 3614              	/NO_APP
 3615              	L673:
 3616 20a8 85C0     		testl	%eax, %eax
 3617 20aa 74EA     		je	L677
 3618 20ac 8B4D0C   		movl	12(%ebp), %ecx
 3619 20af 52       		pushl	%edx
 3620 20b0 52       		pushl	%edx
 3621 20b1 51       		pushl	%ecx
 3622 20b2 8B5314   		movl	20(%ebx), %edx
 3623 20b5 52       		pushl	%edx
 3624 20b6 E8353600 		call	_ptw32_timed_eventwait
 3624      00
 3625 20bb 83C410   		addl	$16, %esp
 3626 20be 85C0     		testl	%eax, %eax
 3627 20c0 75D6     		jne	L653
 3628 20c2 8B0D2400 		movl	_ptw32_smp_system, %ecx
 3628      0000
 3629 20c8 EBD6     		jmp	L669
 3630 20ca 8DB60000 		.p2align 4,,7
 3630      0000
 3631              	L672:
 3632              	/APP
 3633              		0:
 3634 20d0 8B03     		movl           (%ebx),%eax
 3635 20d2 0FB133   		cmpxchgl       %esi,(%ebx)
 3636 20d5 75F9     		jnz            0b
 3637              	/NO_APP
 3638 20d7 EBCF     		jmp	L673
 3639              	L666:
 3640              	/APP
 3641              		0:
 3642 20d9 8B03     		movl           (%ebx),%eax
 3643 20db 0FB113   		cmpxchgl       %edx,(%ebx)
 3644 20de 75F9     		jnz            0b
 3645              	/NO_APP
 3646 20e0 89C2     		movl	%eax, %edx
 3647 20e2 EBAB     		jmp	L667
 3648              	L664:
 3649 20e4 E8C7F7FF 		call	_pthread_self
 3649      FF
 3650 20e9 31C9     		xorl	%ecx, %ecx
 3651 20eb 89C6     		movl	%eax, %esi
 3652 20ed 89D7     		movl	%edx, %edi
 3653 20ef A1240000 		movl	_ptw32_smp_system, %eax
 3653      00
 3654 20f4 BA010000 		movl	$1, %edx
 3654      00
 3655 20f9 8945F0   		movl	%eax, -16(%ebp)
 3656 20fc 85C0     		testl	%eax, %eax
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 77


 3657 20fe 0F848800 		je	L679
 3657      0000
 3658 2104 89C8     		movl	%ecx, %eax
 3659              	/APP
 3660 2106 F0       		lock
 3661 2107 0FB113   		cmpxchgl       %edx,(%ebx)
 3662              	/NO_APP
 3663              	L700:
 3664 210a 85C0     		testl	%eax, %eax
 3665 210c 7512     		jne	L704
 3666              	L701:
 3667 210e C7430401 		movl	$1, 4(%ebx)
 3667      000000
 3668 2115 89730C   		movl	%esi, 12(%ebx)
 3669 2118 897B10   		movl	%edi, 16(%ebx)
 3670 211b E976FFFF 		jmp	L677
 3670      FF
 3671              	L704:
 3672 2120 57       		pushl	%edi
 3673 2121 56       		pushl	%esi
 3674 2122 8B4B10   		movl	16(%ebx), %ecx
 3675 2125 51       		pushl	%ecx
 3676 2126 8B530C   		movl	12(%ebx), %edx
 3677 2129 52       		pushl	%edx
 3678 212a E841F8FF 		call	_pthread_equal
 3678      FF
 3679 212f 83C410   		addl	$16, %esp
 3680 2132 85C0     		testl	%eax, %eax
 3681 2134 741C     		je	L687
 3682 2136 837B0801 		cmpl	$1, 8(%ebx)
 3683 213a 740A     		je	L705
 3684 213c B8240000 		movl	$36, %eax
 3684      00
 3685 2141 E952FFFF 		jmp	L653
 3685      FF
 3686              	L705:
 3687 2146 8B7304   		movl	4(%ebx), %esi
 3688 2149 46       		incl	%esi
 3689 214a 897304   		movl	%esi, 4(%ebx)
 3690 214d E944FFFF 		jmp	L677
 3690      FF
 3691              		.p2align 4,,7
 3692              	L687:
 3693 2152 8B0D2400 		movl	_ptw32_smp_system, %ecx
 3693      0000
 3694 2158 85C9     		testl	%ecx, %ecx
 3695 215a 7424     		je	L690
 3696 215c 83C8FF   		orl	$-1, %eax
 3697              	/APP
 3698 215f 8703     		xchgl          %eax,(%ebx)
 3699              	/NO_APP
 3700              	L691:
 3701 2161 85C0     		testl	%eax, %eax
 3702 2163 74A9     		je	L701
 3703 2165 8B550C   		movl	12(%ebp), %edx
 3704 2168 50       		pushl	%eax
 3705 2169 50       		pushl	%eax
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 78


 3706 216a 52       		pushl	%edx
 3707 216b 8B4314   		movl	20(%ebx), %eax
 3708 216e 50       		pushl	%eax
 3709 216f E87C3500 		call	_ptw32_timed_eventwait
 3709      00
 3710 2174 83C410   		addl	$16, %esp
 3711 2177 85C0     		testl	%eax, %eax
 3712 2179 74D7     		je	L687
 3713 217b E918FFFF 		jmp	L653
 3713      FF
 3714              	L690:
 3715 2180 83CAFF   		orl	$-1, %edx
 3716              	/APP
 3717              		0:
 3718 2183 8B03     		movl           (%ebx),%eax
 3719 2185 0FB113   		cmpxchgl       %edx,(%ebx)
 3720 2188 75F9     		jnz            0b
 3721              	/NO_APP
 3722 218a EBD5     		jmp	L691
 3723              	L679:
 3724 218c 8B45F0   		movl	-16(%ebp), %eax
 3725              	/APP
 3726 218f 0FB113   		cmpxchgl       %edx,(%ebx)
 3727              	/NO_APP
 3728 2192 E973FFFF 		jmp	L700
 3728      FF
 3729              	L702:
 3730 2197 83EC0C   		subl	$12, %esp
 3731 219a 31DB     		xorl	%ebx, %ebx
 3732 219c 68000000 		pushl	$_ptw32_mutex_test_init_lock
 3732      00
 3733 21a1 E8000000 		call	_EnterCriticalSection@4
 3733      00
 3734 21a6 8B06     		movl	(%esi), %eax
 3735 21a8 83C40C   		addl	$12, %esp
 3736 21ab 83F8FF   		cmpl	$-1, %eax
 3737 21ae 7453     		je	L706
 3738 21b0 83F8FE   		cmpl	$-2, %eax
 3739 21b3 7445     		je	L707
 3740 21b5 83F8FD   		cmpl	$-3, %eax
 3741 21b8 742C     		je	L708
 3742 21ba 85C0     		testl	%eax, %eax
 3743 21bc 7421     		je	L709
 3744              	L657:
 3745 21be 83EC0C   		subl	$12, %esp
 3746 21c1 68000000 		pushl	$_ptw32_mutex_test_init_lock
 3746      00
 3747 21c6 E8000000 		call	_LeaveCriticalSection@4
 3747      00
 3748 21cb 89D8     		movl	%ebx, %eax
 3749 21cd 83C40C   		addl	$12, %esp
 3750 21d0 85DB     		testl	%ebx, %ebx
 3751 21d2 0F85C0FE 		jne	L653
 3751      FFFF
 3752 21d8 8B1E     		movl	(%esi), %ebx
 3753 21da E998FEFF 		jmp	L654
 3753      FF
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 79


 3754              	L709:
 3755 21df BB160000 		movl	$22, %ebx
 3755      00
 3756 21e4 EBD8     		jmp	L657
 3757              	L708:
 3758 21e6 53       		pushl	%ebx
 3759 21e7 53       		pushl	%ebx
 3760 21e8 68440000 		pushl	$_ptw32_errorcheck_mutexattr
 3760      00
 3761              	L699:
 3762 21ed 56       		pushl	%esi
 3763 21ee E8BDF9FF 		call	_pthread_mutex_init
 3763      FF
 3764 21f3 83C410   		addl	$16, %esp
 3765 21f6 89C3     		movl	%eax, %ebx
 3766 21f8 EBC4     		jmp	L657
 3767              	L707:
 3768 21fa 57       		pushl	%edi
 3769 21fb 57       		pushl	%edi
 3770 21fc 68400000 		pushl	$_ptw32_recursive_mutexattr
 3770      00
 3771 2201 EBEA     		jmp	L699
 3772              	L706:
 3773 2203 50       		pushl	%eax
 3774 2204 50       		pushl	%eax
 3775 2205 6A00     		pushl	$0
 3776 2207 EBE4     		jmp	L699
 3777 2209 8DB42600 		.p2align 4,,15
 3777      000000
 3778              	.globl _pthread_mutex_unlock
 3779              		.def	_pthread_mutex_unlock;	.scl	2;	.type	32;	.endef
 3780              	_pthread_mutex_unlock:
 3781 2210 55       		pushl	%ebp
 3782 2211 89E5     		movl	%esp, %ebp
 3783 2213 56       		pushl	%esi
 3784 2214 53       		pushl	%ebx
 3785 2215 31F6     		xorl	%esi, %esi
 3786 2217 8B5508   		movl	8(%ebp), %edx
 3787 221a 8B1A     		movl	(%edx), %ebx
 3788 221c 83FBFC   		cmpl	$-4, %ebx
 3789 221f 773F     		ja	L711
 3790 2221 8B4308   		movl	8(%ebx), %eax
 3791 2224 85C0     		testl	%eax, %eax
 3792 2226 7558     		jne	L712
 3793 2228 8B152400 		movl	_ptw32_smp_system, %edx
 3793      0000
 3794 222e 85D2     		testl	%edx, %edx
 3795 2230 743E     		je	L713
 3796 2232 89F0     		movl	%esi, %eax
 3797              	/APP
 3798 2234 8703     		xchgl          %eax,(%ebx)
 3799              	/NO_APP
 3800              	L714:
 3801 2236 85C0     		testl	%eax, %eax
 3802 2238 742D     		je	L721
 3803              	L726:
 3804 223a 85C0     		testl	%eax, %eax
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 80


 3805 223c 7809     		js	L732
 3806              	L730:
 3807 223e 8D65F8   		leal	-8(%ebp), %esp
 3808 2241 89F0     		movl	%esi, %eax
 3809 2243 5B       		popl	%ebx
 3810 2244 5E       		popl	%esi
 3811 2245 5D       		popl	%ebp
 3812 2246 C3       		ret
 3813              	L732:
 3814 2247 83EC0C   		subl	$12, %esp
 3815 224a 8B4B14   		movl	20(%ebx), %ecx
 3816 224d 51       		pushl	%ecx
 3817 224e E8000000 		call	_SetEvent@4
 3817      00
 3818 2253 83C40C   		addl	$12, %esp
 3819 2256 85C0     		testl	%eax, %eax
 3820 2258 75E4     		jne	L730
 3821 225a 8DB60000 		.p2align 4,,7
 3821      0000
 3822              	L711:
 3823 2260 BE160000 		movl	$22, %esi
 3823      00
 3824 2265 EBD7     		jmp	L730
 3825              		.p2align 4,,7
 3826              	L721:
 3827 2267 BE010000 		movl	$1, %esi
 3827      00
 3828 226c EBD0     		jmp	L730
 3829 226e 89F6     		.p2align 4,,7
 3830              	L713:
 3831              	/APP
 3832              		0:
 3833 2270 8B03     		movl           (%ebx),%eax
 3834 2272 0FB133   		cmpxchgl       %esi,(%ebx)
 3835 2275 75F9     		jnz            0b
 3836              	/NO_APP
 3837 2277 EBBD     		jmp	L714
 3838 2279 8DB42600 		.p2align 4,,7
 3838      000000
 3839              	L712:
 3840 2280 E82BF6FF 		call	_pthread_self
 3840      FF
 3841 2285 52       		pushl	%edx
 3842 2286 50       		pushl	%eax
 3843 2287 8B5310   		movl	16(%ebx), %edx
 3844 228a 52       		pushl	%edx
 3845 228b 8B4B0C   		movl	12(%ebx), %ecx
 3846 228e 51       		pushl	%ecx
 3847 228f E8DCF6FF 		call	_pthread_equal
 3847      FF
 3848 2294 83C410   		addl	$16, %esp
 3849 2297 85C0     		testl	%eax, %eax
 3850 2299 74CC     		je	L721
 3851 229b 837B0801 		cmpl	$1, 8(%ebx)
 3852 229f 7423     		je	L733
 3853              	L723:
 3854 22a1 8B152400 		movl	_ptw32_smp_system, %edx
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 81


 3854      0000
 3855 22a7 C7430C00 		movl	$0, 12(%ebx)
 3855      000000
 3856 22ae 85D2     		testl	%edx, %edx
 3857 22b0 7406     		je	L725
 3858 22b2 89F0     		movl	%esi, %eax
 3859              	/APP
 3860 22b4 8703     		xchgl          %eax,(%ebx)
 3861              	/NO_APP
 3862 22b6 EB82     		jmp	L726
 3863              	L725:
 3864              	/APP
 3865              		0:
 3866 22b8 8B03     		movl           (%ebx),%eax
 3867 22ba 0FB133   		cmpxchgl       %esi,(%ebx)
 3868 22bd 75F9     		jnz            0b
 3869              	/NO_APP
 3870 22bf E976FFFF 		jmp	L726
 3870      FF
 3871              	L733:
 3872 22c4 8B4B04   		movl	4(%ebx), %ecx
 3873 22c7 49       		decl	%ecx
 3874 22c8 894B04   		movl	%ecx, 4(%ebx)
 3875 22cb 85C9     		testl	%ecx, %ecx
 3876 22cd 74D2     		je	L723
 3877 22cf E96AFFFF 		jmp	L730
 3877      FF
 3878 22d4 8DB60000 		.p2align 4,,15
 3878      00008DBF 
 3878      00000000 
 3879              	.globl _pthread_mutex_trylock
 3880              		.def	_pthread_mutex_trylock;	.scl	2;	.type	32;	.endef
 3881              	_pthread_mutex_trylock:
 3882 22e0 55       		pushl	%ebp
 3883 22e1 89E5     		movl	%esp, %ebp
 3884 22e3 57       		pushl	%edi
 3885 22e4 56       		pushl	%esi
 3886 22e5 31F6     		xorl	%esi, %esi
 3887 22e7 53       		pushl	%ebx
 3888 22e8 83EC0C   		subl	$12, %esp
 3889 22eb 8B7D08   		movl	8(%ebp), %edi
 3890 22ee 8B1F     		movl	(%edi), %ebx
 3891 22f0 83FBFC   		cmpl	$-4, %ebx
 3892 22f3 777B     		ja	L756
 3893              	L735:
 3894 22f5 8B3D2400 		movl	_ptw32_smp_system, %edi
 3894      0000
 3895 22fb 31C9     		xorl	%ecx, %ecx
 3896 22fd BA010000 		movl	$1, %edx
 3896      00
 3897 2302 85FF     		testl	%edi, %edi
 3898 2304 7460     		je	L746
 3899 2306 89C8     		movl	%ecx, %eax
 3900              	/APP
 3901 2308 F0       		lock
 3902 2309 0FB113   		cmpxchgl       %edx,(%ebx)
 3903              	/NO_APP
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 82


 3904              	L755:
 3905 230c 85C0     		testl	%eax, %eax
 3906 230e 7525     		jne	L745
 3907 2310 8B5308   		movl	8(%ebx), %edx
 3908 2313 85D2     		testl	%edx, %edx
 3909 2315 750A     		jne	L757
 3910              	L734:
 3911 2317 8D65F4   		leal	-12(%ebp), %esp
 3912 231a 89F0     		movl	%esi, %eax
 3913 231c 5B       		popl	%ebx
 3914 231d 5E       		popl	%esi
 3915 231e 5F       		popl	%edi
 3916 231f 5D       		popl	%ebp
 3917 2320 C3       		ret
 3918              		.p2align 4,,7
 3919              	L757:
 3920 2321 C7430401 		movl	$1, 4(%ebx)
 3920      000000
 3921 2328 E883F5FF 		call	_pthread_self
 3921      FF
 3922 232d 89430C   		movl	%eax, 12(%ebx)
 3923 2330 895310   		movl	%edx, 16(%ebx)
 3924 2333 EBE2     		jmp	L734
 3925              		.p2align 4,,7
 3926              	L745:
 3927 2335 837B0801 		cmpl	$1, 8(%ebx)
 3928 2339 7407     		je	L758
 3929              	L751:
 3930 233b BE100000 		movl	$16, %esi
 3930      00
 3931 2340 EBD5     		jmp	L734
 3932              	L758:
 3933 2342 E869F5FF 		call	_pthread_self
 3933      FF
 3934 2347 52       		pushl	%edx
 3935 2348 50       		pushl	%eax
 3936 2349 8B4B10   		movl	16(%ebx), %ecx
 3937 234c 51       		pushl	%ecx
 3938 234d 8B430C   		movl	12(%ebx), %eax
 3939 2350 50       		pushl	%eax
 3940 2351 E81AF6FF 		call	_pthread_equal
 3940      FF
 3941 2356 83C410   		addl	$16, %esp
 3942 2359 85C0     		testl	%eax, %eax
 3943 235b 74DE     		je	L751
 3944 235d 8B7B04   		movl	4(%ebx), %edi
 3945 2360 47       		incl	%edi
 3946 2361 897B04   		movl	%edi, 4(%ebx)
 3947 2364 EBB1     		jmp	L734
 3948              		.p2align 4,,7
 3949              	L746:
 3950 2366 89F8     		movl	%edi, %eax
 3951              	/APP
 3952 2368 0FB113   		cmpxchgl       %edx,(%ebx)
 3953              	/NO_APP
 3954 236b EB9F     		jmp	L755
 3955 236d 8D7600   		.p2align 4,,7
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 83


 3956              	L756:
 3957 2370 83EC0C   		subl	$12, %esp
 3958 2373 31DB     		xorl	%ebx, %ebx
 3959 2375 68000000 		pushl	$_ptw32_mutex_test_init_lock
 3959      00
 3960 237a E8000000 		call	_EnterCriticalSection@4
 3960      00
 3961 237f 8B07     		movl	(%edi), %eax
 3962 2381 83C40C   		addl	$12, %esp
 3963 2384 83F8FF   		cmpl	$-1, %eax
 3964 2387 7453     		je	L759
 3965 2389 83F8FE   		cmpl	$-2, %eax
 3966 238c 7445     		je	L760
 3967 238e 83F8FD   		cmpl	$-3, %eax
 3968 2391 742C     		je	L761
 3969 2393 85C0     		testl	%eax, %eax
 3970 2395 7421     		je	L762
 3971              	L738:
 3972 2397 83EC0C   		subl	$12, %esp
 3973 239a 89DE     		movl	%ebx, %esi
 3974 239c 68000000 		pushl	$_ptw32_mutex_test_init_lock
 3974      00
 3975 23a1 E8000000 		call	_LeaveCriticalSection@4
 3975      00
 3976 23a6 83C40C   		addl	$12, %esp
 3977 23a9 85DB     		testl	%ebx, %ebx
 3978 23ab 0F8566FF 		jne	L734
 3978      FFFF
 3979 23b1 8B1F     		movl	(%edi), %ebx
 3980 23b3 E93DFFFF 		jmp	L735
 3980      FF
 3981              	L762:
 3982 23b8 BB160000 		movl	$22, %ebx
 3982      00
 3983 23bd EBD8     		jmp	L738
 3984              	L761:
 3985 23bf 50       		pushl	%eax
 3986 23c0 50       		pushl	%eax
 3987 23c1 68440000 		pushl	$_ptw32_errorcheck_mutexattr
 3987      00
 3988              	L754:
 3989 23c6 57       		pushl	%edi
 3990 23c7 E8E4F7FF 		call	_pthread_mutex_init
 3990      FF
 3991 23cc 83C410   		addl	$16, %esp
 3992 23cf 89C3     		movl	%eax, %ebx
 3993 23d1 EBC4     		jmp	L738
 3994              	L760:
 3995 23d3 50       		pushl	%eax
 3996 23d4 50       		pushl	%eax
 3997 23d5 68400000 		pushl	$_ptw32_recursive_mutexattr
 3997      00
 3998 23da EBEA     		jmp	L754
 3999              	L759:
 4000 23dc 50       		pushl	%eax
 4001 23dd 50       		pushl	%eax
 4002 23de 6A00     		pushl	$0
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 84


 4003 23e0 EBE4     		jmp	L754
 4004 23e2 8DB42600 		.p2align 4,,15
 4004      0000008D 
 4004      BC270000 
 4004      0000
 4005              	.globl _pthread_mutexattr_setkind_np
 4006              		.def	_pthread_mutexattr_setkind_np;	.scl	2;	.type	32;	.endef
 4007              	_pthread_mutexattr_setkind_np:
 4008 23f0 55       		pushl	%ebp
 4009 23f1 89E5     		movl	%esp, %ebp
 4010 23f3 5D       		popl	%ebp
 4011 23f4 E937FAFF 		jmp	_pthread_mutexattr_settype
 4011      FF
 4012 23f9 8DB42600 		.p2align 4,,15
 4012      000000
 4013              	.globl _pthread_mutexattr_getkind_np
 4014              		.def	_pthread_mutexattr_getkind_np;	.scl	2;	.type	32;	.endef
 4015              	_pthread_mutexattr_getkind_np:
 4016 2400 55       		pushl	%ebp
 4017 2401 89E5     		movl	%esp, %ebp
 4018 2403 5D       		popl	%ebp
 4019 2404 E957FAFF 		jmp	_pthread_mutexattr_gettype
 4019      FF
 4020 2409 8DB42600 		.p2align 4,,15
 4020      000000
 4021              	.globl _pthread_getw32threadhandle_np
 4022              		.def	_pthread_getw32threadhandle_np;	.scl	2;	.type	32;	.endef
 4023              	_pthread_getw32threadhandle_np:
 4024 2410 55       		pushl	%ebp
 4025 2411 89E5     		movl	%esp, %ebp
 4026 2413 8B5508   		movl	8(%ebp), %edx
 4027 2416 5D       		popl	%ebp
 4028 2417 8B4204   		movl	4(%edx), %eax
 4029 241a C3       		ret
 4030 241b 908D7426 		.p2align 4,,15
 4030      00
 4031              	.globl _pthread_delay_np
 4032              		.def	_pthread_delay_np;	.scl	2;	.type	32;	.endef
 4033              	_pthread_delay_np:
 4034 2420 55       		pushl	%ebp
 4035 2421 B9160000 		movl	$22, %ecx
 4035      00
 4036 2426 89E5     		movl	%esp, %ebp
 4037 2428 56       		pushl	%esi
 4038 2429 53       		pushl	%ebx
 4039 242a 8B5508   		movl	8(%ebp), %edx
 4040 242d 85D2     		testl	%edx, %edx
 4041 242f 7471     		je	L766
 4042 2431 8B02     		movl	(%edx), %eax
 4043 2433 85C0     		testl	%eax, %eax
 4044 2435 0F852701 		jne	L790
 4044      0000
 4045 243b 8B5204   		movl	4(%edx), %edx
 4046 243e 85D2     		testl	%edx, %edx
 4047 2440 0F840001 		je	L791
 4047      0000
 4048              	L768:
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 85


 4049 2446 8D1C80   		leal	(%eax,%eax,4), %ebx
 4050 2449 B983DE1B 		movl	$1125899907, %ecx
 4050      43
 4051 244e 8D349B   		leal	(%ebx,%ebx,4), %esi
 4052 2451 8D1CB6   		leal	(%esi,%esi,4), %ebx
 4053 2454 8DB23F42 		leal	999999(%edx), %esi
 4053      0F00
 4054 245a 89F0     		movl	%esi, %eax
 4055 245c C1FE1F   		sarl	$31, %esi
 4056 245f F7E9     		imull	%ecx
 4057 2461 C1FA12   		sarl	$18, %edx
 4058 2464 29F2     		subl	%esi, %edx
 4059 2466 8D34DA   		leal	(%edx,%ebx,8), %esi
 4060 2469 E842F4FF 		call	_pthread_self
 4060      FF
 4061 246e 85C0     		testl	%eax, %eax
 4062 2470 B90C0000 		movl	$12, %ecx
 4062      00
 4063 2475 742B     		je	L766
 4064 2477 8B5034   		movl	52(%eax), %edx
 4065 247a 89C3     		movl	%eax, %ebx
 4066 247c 85D2     		testl	%edx, %edx
 4067 247e 0F85B100 		jne	L771
 4067      0000
 4068 2484 50       		pushl	%eax
 4069 2485 50       		pushl	%eax
 4070 2486 56       		pushl	%esi
 4071 2487 8B433C   		movl	60(%ebx), %eax
 4072 248a 50       		pushl	%eax
 4073 248b E8000000 		call	_WaitForSingleObject@8
 4073      00
 4074 2490 5E       		popl	%esi
 4075 2491 85C0     		testl	%eax, %eax
 4076 2493 5A       		popl	%edx
 4077 2494 741E     		je	L792
 4078 2496 B9160000 		movl	$22, %ecx
 4078      00
 4079 249b 3D020100 		cmpl	$258, %eax
 4079      00
 4080 24a0 740E     		je	L789
 4081              		.p2align 4,,7
 4082              	L766:
 4083 24a2 8D65F8   		leal	-8(%ebp), %esp
 4084 24a5 89C8     		movl	%ecx, %eax
 4085 24a7 5B       		popl	%ebx
 4086 24a8 5E       		popl	%esi
 4087 24a9 5D       		popl	%ebp
 4088 24aa C3       		ret
 4089 24ab 908D7426 		.p2align 4,,7
 4089      00
 4090              	L789:
 4091 24b0 31C9     		xorl	%ecx, %ecx
 4092 24b2 EBEE     		jmp	L766
 4093              	L792:
 4094 24b4 83EC0C   		subl	$12, %esp
 4095 24b7 8D7330   		leal	48(%ebx), %esi
 4096 24ba 56       		pushl	%esi
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 86


 4097 24bb E8D0F9FF 		call	_pthread_mutex_lock
 4097      FF
 4098 24c0 83C410   		addl	$16, %esp
 4099 24c3 8B4B14   		movl	20(%ebx), %ecx
 4100 24c6 83F903   		cmpl	$3, %ecx
 4101 24c9 7610     		jbe	L794
 4102 24cb 83EC0C   		subl	$12, %esp
 4103 24ce 56       		pushl	%esi
 4104 24cf E83CFDFF 		call	_pthread_mutex_unlock
 4104      FF
 4105 24d4 B9030000 		movl	$3, %ecx
 4105      00
 4106 24d9 EBC7     		jmp	L766
 4107              	L794:
 4108 24db 83EC0C   		subl	$12, %esp
 4109 24de C7431404 		movl	$4, 20(%ebx)
 4109      000000
 4110 24e5 C7433401 		movl	$1, 52(%ebx)
 4110      000000
 4111 24ec 56       		pushl	%esi
 4112 24ed E81EFDFF 		call	_pthread_mutex_unlock
 4112      FF
 4113 24f2 8B350C00 		movl	_ptw32_selfThreadKey, %esi
 4113      0000
 4114 24f8 59       		popl	%ecx
 4115 24f9 56       		pushl	%esi
 4116 24fa E8012500 		call	_pthread_getspecific
 4116      00
 4117 24ff 83C410   		addl	$16, %esp
 4118 2502 89C3     		movl	%eax, %ebx
 4119 2504 85C0     		testl	%eax, %eax
 4120 2506 740D     		je	L776
 4121 2508 8A908000 		movb	128(%eax), %dl
 4121      0000
 4122 250e 83E201   		andl	$1, %edx
 4123 2511 84D2     		testb	%dl, %dl
 4124 2513 740D     		je	L782
 4125              	L776:
 4126 2515 83EC0C   		subl	$12, %esp
 4127 2518 6AFF     		pushl	$-1
 4128 251a E8000000 		call	__endthreadex
 4128      00
 4129 251f 83C410   		addl	$16, %esp
 4130              	L782:
 4131 2522 83EC0C   		subl	$12, %esp
 4132 2525 6A01     		pushl	$1
 4133 2527 E884E8FF 		call	_ptw32_pop_cleanup
 4133      FF
 4134 252c 83C410   		addl	$16, %esp
 4135 252f 85C0     		testl	%eax, %eax
 4136 2531 75EF     		jne	L782
 4137 2533 EB35     		jmp	L795
 4138              		.p2align 4,,7
 4139              	L771:
 4140 2535 83EC0C   		subl	$12, %esp
 4141 2538 56       		pushl	%esi
 4142 2539 E8000000 		call	_Sleep@4
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 87


 4142      00
 4143 253e 83C40C   		addl	$12, %esp
 4144 2541 E96AFFFF 		jmp	L789
 4144      FF
 4145              		.p2align 4,,7
 4146              	L791:
 4147 2546 E805E6FF 		call	_pthread_testcancel
 4147      FF
 4148 254b 83EC0C   		subl	$12, %esp
 4149 254e 6A00     		pushl	$0
 4150 2550 E8000000 		call	_Sleep@4
 4150      00
 4151 2555 83C40C   		addl	$12, %esp
 4152 2558 E8F3E5FF 		call	_pthread_testcancel
 4152      FF
 4153 255d E94EFFFF 		jmp	L789
 4153      FF
 4154              		.p2align 4,,7
 4155              	L790:
 4156 2562 8B5204   		movl	4(%edx), %edx
 4157 2565 E9DCFEFF 		jmp	L768
 4157      FF
 4158              	L795:
 4159 256a 8D4B40   		leal	64(%ebx), %ecx
 4160 256d 50       		pushl	%eax
 4161 256e 50       		pushl	%eax
 4162 256f 6A02     		pushl	$2
 4163 2571 51       		pushl	%ecx
 4164 2572 E8000000 		call	_longjmp
 4164      00
 4165 2577 89F68DBC 		.p2align 4,,15
 4165      27000000 
 4165      00
 4166              	.globl _pthread_num_processors_np
 4167              		.def	_pthread_num_processors_np;	.scl	2;	.type	32;	.endef
 4168              	_pthread_num_processors_np:
 4169 2580 55       		pushl	%ebp
 4170 2581 89E5     		movl	%esp, %ebp
 4171 2583 53       		pushl	%ebx
 4172 2584 83EC18   		subl	$24, %esp
 4173 2587 31DB     		xorl	%ebx, %ebx
 4174 2589 8D55F4   		leal	-12(%ebp), %edx
 4175 258c 52       		pushl	%edx
 4176 258d 8D55F0   		leal	-16(%ebp), %edx
 4177 2590 52       		pushl	%edx
 4178 2591 51       		pushl	%ecx
 4179 2592 E8000000 		call	_GetCurrentProcess@0
 4179      00
 4180 2597 890424   		movl	%eax, (%esp)
 4181 259a E8000000 		call	_GetProcessAffinityMask@12
 4181      00
 4182 259f 5A       		popl	%edx
 4183 25a0 85C0     		testl	%eax, %eax
 4184 25a2 742C     		je	L798
 4185 25a4 31C9     		xorl	%ecx, %ecx
 4186 25a6 B8010000 		movl	$1, %eax
 4186      00
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 88


 4187 25ab 8B55F0   		movl	-16(%ebp), %edx
 4188 25ae 89F6     		.p2align 4,,7
 4189              	L804:
 4190 25b0 85D0     		testl	%eax, %edx
 4191 25b2 7401     		je	L801
 4192 25b4 41       		incl	%ecx
 4193              	L801:
 4194 25b5 01C0     		addl	%eax, %eax
 4195 25b7 75F7     		jne	L804
 4196 25b9 894DF8   		movl	%ecx, -8(%ebp)
 4197              	L805:
 4198 25bc 85DB     		testl	%ebx, %ebx
 4199 25be 7407     		je	L797
 4200 25c0 C745F801 		movl	$1, -8(%ebp)
 4200      000000
 4201              	L797:
 4202 25c7 8B45F8   		movl	-8(%ebp), %eax
 4203 25ca 8B5DFC   		movl	-4(%ebp), %ebx
 4204 25cd C9       		leave
 4205 25ce C3       		ret
 4206 25cf 90       		.p2align 4,,7
 4207              	L798:
 4208 25d0 BB0B0000 		movl	$11, %ebx
 4208      00
 4209 25d5 EBE5     		jmp	L805
 4210              	LC0:
 4211 25d7 4B45524E 		.ascii "KERNEL32.DLL\0"
 4211      454C3332 
 4211      2E444C4C 
 4211      00
 4212              	LC1:
 4213 25e4 496E7465 		.ascii "InterlockedCompareExchange\0"
 4213      726C6F63 
 4213      6B656443 
 4213      6F6D7061 
 4213      72654578 
 4214              	LC2:
 4215 25ff 51555345 		.ascii "QUSEREX.DLL\0"
 4215      5245582E 
 4215      444C4C00 
 4216              	LC4:
 4217 260b 51756575 		.ascii "QueueUserAPCEx_Init\0"
 4217      65557365 
 4217      72415043 
 4217      45785F49 
 4217      6E697400 
 4218              	LC3:
 4219 261f 51756575 		.ascii "QueueUserAPCEx\0"
 4219      65557365 
 4219      72415043 
 4219      457800
 4220 262e 89F6     		.p2align 4,,15
 4221              	.globl _pthread_win32_process_attach_np
 4222              		.def	_pthread_win32_process_attach_np;	.scl	2;	.type	32;	.endef
 4223              	_pthread_win32_process_attach_np:
 4224 2630 55       		pushl	%ebp
 4225 2631 89E5     		movl	%esp, %ebp
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 89


 4226 2633 53       		pushl	%ebx
 4227 2634 83EC14   		subl	$20, %esp
 4228 2637 8B150000 		movl	_ptw32_processInitialized, %edx
 4228      0000
 4229 263d 85D2     		testl	%edx, %edx
 4230 263f 0F849D01 		je	L810
 4230      0000
 4231 2645 BB010000 		movl	$1, %ebx
 4231      00
 4232              	L811:
 4233 264a 8D4DF8   		leal	-8(%ebp), %ecx
 4234 264d 50       		pushl	%eax
 4235 264e 8D55F4   		leal	-12(%ebp), %edx
 4236 2651 51       		pushl	%ecx
 4237 2652 52       		pushl	%edx
 4238 2653 51       		pushl	%ecx
 4239 2654 C7052000 		movl	$0, _ptw32_features
 4239      00000000 
 4239      0000
 4240 265e E8000000 		call	_GetCurrentProcess@0
 4240      00
 4241 2663 890424   		movl	%eax, (%esp)
 4242 2666 E8000000 		call	_GetProcessAffinityMask@12
 4242      00
 4243 266b 5A       		popl	%edx
 4244 266c 85C0     		testl	%eax, %eax
 4245 266e 0F845F01 		je	L814
 4245      0000
 4246 2674 31C9     		xorl	%ecx, %ecx
 4247 2676 B8010000 		movl	$1, %eax
 4247      00
 4248 267b 8B55F8   		movl	-8(%ebp), %edx
 4249 267e 89F6     		.p2align 4,,7
 4250              	L820:
 4251 2680 85D0     		testl	%eax, %edx
 4252 2682 7401     		je	L817
 4253 2684 41       		incl	%ecx
 4254              	L817:
 4255 2685 01C0     		addl	%eax, %eax
 4256 2687 75F7     		jne	L820
 4257 2689 49       		decl	%ecx
 4258 268a 0F9FC2   		setg	%dl
 4259 268d 81E2FF00 		andl	$255, %edx
 4259      0000
 4260 2693 89152400 		movl	%edx, _ptw32_smp_system
 4260      0000
 4261              	L821:
 4262 2699 83EC0C   		subl	$12, %esp
 4263 269c 68D72500 		pushl	$LC0
 4263      00
 4264 26a1 E8000000 		call	_LoadLibraryA@4
 4264      00
 4265 26a6 A3000000 		movl	%eax, _ptw32_h_kernel32
 4265      00
 4266 26ab C70424E4 		movl	$LC1, (%esp)
 4266      250000
 4267 26b2 50       		pushl	%eax
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 90


 4268 26b3 E8000000 		call	_GetProcAddress@8
 4268      00
 4269 26b8 5A       		popl	%edx
 4270 26b9 A3280000 		movl	%eax, _ptw32_interlocked_compare_exchange
 4270      00
 4271 26be 59       		popl	%ecx
 4272 26bf 85C0     		testl	%eax, %eax
 4273 26c1 0F84E100 		je	L833
 4273      0000
 4274 26c7 8B152000 		movl	_ptw32_features, %edx
 4274      0000
 4275 26cd 83CA01   		orl	$1, %edx
 4276 26d0 89152000 		movl	%edx, _ptw32_features
 4276      0000
 4277              	L823:
 4278 26d6 83EC0C   		subl	$12, %esp
 4279 26d9 68FF2500 		pushl	$LC2
 4279      00
 4280 26de E8000000 		call	_LoadLibraryA@4
 4280      00
 4281 26e3 83C40C   		addl	$12, %esp
 4282 26e6 A3100000 		movl	%eax, _ptw32_h_quserex
 4282      00
 4283 26eb 85C0     		testl	%eax, %eax
 4284 26ed 0F859C00 		jne	L834
 4284      0000
 4285              	L824:
 4286 26f3 8B0D2C00 		movl	_ptw32_register_cancelation, %ecx
 4286      0000
 4287 26f9 85C9     		testl	%ecx, %ecx
 4288 26fb 754B     		jne	L825
 4289 26fd A1100000 		movl	_ptw32_h_quserex, %eax
 4289      00
 4290 2702 C7052C00 		movl	$_ptw32_RegisterCancelation, _ptw32_register_cancelation
 4290      0000A050 
 4290      0000
 4291 270c 85C0     		testl	%eax, %eax
 4292 270e 752A     		jne	L835
 4293              	L826:
 4294 2710 C7051000 		movl	$0, _ptw32_h_quserex
 4294      00000000 
 4294      0000
 4295              	L827:
 4296 271a 8B151000 		movl	_ptw32_h_quserex, %edx
 4296      0000
 4297 2720 85D2     		testl	%edx, %edx
 4298 2722 740F     		je	L830
 4299 2724 8B0D2000 		movl	_ptw32_features, %ecx
 4299      0000
 4300 272a 83C902   		orl	$2, %ecx
 4301 272d 890D2000 		movl	%ecx, _ptw32_features
 4301      0000
 4302              	L830:
 4303 2733 89D8     		movl	%ebx, %eax
 4304 2735 8B5DFC   		movl	-4(%ebp), %ebx
 4305 2738 C9       		leave
 4306 2739 C3       		ret
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 91


 4307              	L835:
 4308 273a 83EC0C   		subl	$12, %esp
 4309 273d 50       		pushl	%eax
 4310 273e E8000000 		call	_FreeLibrary@4
 4310      00
 4311 2743 83C40C   		addl	$12, %esp
 4312 2746 EBC8     		jmp	L826
 4313              	L825:
 4314 2748 8B151000 		movl	_ptw32_h_quserex, %edx
 4314      0000
 4315 274e 50       		pushl	%eax
 4316 274f 50       		pushl	%eax
 4317 2750 680B2600 		pushl	$LC4
 4317      00
 4318 2755 52       		pushl	%edx
 4319 2756 E8000000 		call	_GetProcAddress@8
 4319      00
 4320 275b 5A       		popl	%edx
 4321 275c 85C0     		testl	%eax, %eax
 4322 275e 59       		popl	%ecx
 4323 275f 7406     		je	L829
 4324 2761 FFD0     		call	*%eax
 4325 2763 85C0     		testl	%eax, %eax
 4326 2765 75B3     		jne	L827
 4327              	L829:
 4328 2767 83EC0C   		subl	$12, %esp
 4329 276a 8B0D1000 		movl	_ptw32_h_quserex, %ecx
 4329      0000
 4330 2770 C7052C00 		movl	$_ptw32_RegisterCancelation, _ptw32_register_cancelation
 4330      0000A050 
 4330      0000
 4331 277a 51       		pushl	%ecx
 4332 277b E8000000 		call	_FreeLibrary@4
 4332      00
 4333 2780 83C40C   		addl	$12, %esp
 4334 2783 C7051000 		movl	$0, _ptw32_h_quserex
 4334      00000000 
 4334      0000
 4335 278d EB8B     		jmp	L827
 4336              	L834:
 4337 278f 51       		pushl	%ecx
 4338 2790 51       		pushl	%ecx
 4339 2791 681F2600 		pushl	$LC3
 4339      00
 4340 2796 50       		pushl	%eax
 4341 2797 E8000000 		call	_GetProcAddress@8
 4341      00
 4342 279c A32C0000 		movl	%eax, _ptw32_register_cancelation
 4342      00
 4343 27a1 58       		popl	%eax
 4344 27a2 5A       		popl	%edx
 4345 27a3 E94BFFFF 		jmp	L824
 4345      FF
 4346              	L833:
 4347 27a8 83EC0C   		subl	$12, %esp
 4348 27ab 8B0D0000 		movl	_ptw32_h_kernel32, %ecx
 4348      0000
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 92


 4349 27b1 C7052800 		movl	$_ptw32_InterlockedCompareExchange@12, _ptw32_interlocked_compare_exchange
 4349      0000504A 
 4349      0000
 4350 27bb 51       		pushl	%ecx
 4351 27bc E8000000 		call	_FreeLibrary@4
 4351      00
 4352 27c1 83C40C   		addl	$12, %esp
 4353 27c4 C7050000 		movl	$0, _ptw32_h_kernel32
 4353      00000000 
 4353      0000
 4354 27ce E903FFFF 		jmp	L823
 4354      FF
 4355              		.p2align 4,,7
 4356              	L814:
 4357 27d3 C7052400 		movl	$0, _ptw32_smp_system
 4357      00000000 
 4357      0000
 4358 27dd E9B7FEFF 		jmp	L821
 4358      FF
 4359              	L810:
 4360 27e2 C7050000 		movl	$1, _ptw32_processInitialized
 4360      00000100 
 4360      0000
 4361 27ec 50       		pushl	%eax
 4362 27ed 50       		pushl	%eax
 4363 27ee 6A00     		pushl	$0
 4364 27f0 680C0000 		pushl	$_ptw32_selfThreadKey
 4364      00
 4365 27f5 E8461F00 		call	_pthread_key_create
 4365      00
 4366 27fa 83C410   		addl	$16, %esp
 4367 27fd 85C0     		testl	%eax, %eax
 4368 27ff 7515     		jne	L813
 4369 2801 50       		pushl	%eax
 4370 2802 50       		pushl	%eax
 4371 2803 6A00     		pushl	$0
 4372 2805 68100000 		pushl	$_ptw32_cleanupKey
 4372      00
 4373 280a E8311F00 		call	_pthread_key_create
 4373      00
 4374 280f 83C410   		addl	$16, %esp
 4375 2812 85C0     		testl	%eax, %eax
 4376 2814 7405     		je	L812
 4377              	L813:
 4378 2816 E8E5D7FF 		call	_ptw32_processTerminate
 4378      FF
 4379              	L812:
 4380 281b 83EC0C   		subl	$12, %esp
 4381 281e 68000000 		pushl	$_ptw32_thread_reuse_lock
 4381      00
 4382 2823 E8000000 		call	_InitializeCriticalSection@4
 4382      00
 4383 2828 68000000 		pushl	$_ptw32_mutex_test_init_lock
 4383      00
 4384 282d E8000000 		call	_InitializeCriticalSection@4
 4384      00
 4385 2832 68000000 		pushl	$_ptw32_cond_list_lock
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 93


 4385      00
 4386 2837 E8000000 		call	_InitializeCriticalSection@4
 4386      00
 4387 283c 68000000 		pushl	$_ptw32_cond_test_init_lock
 4387      00
 4388 2841 E8000000 		call	_InitializeCriticalSection@4
 4388      00
 4389 2846 68000000 		pushl	$_ptw32_rwlock_test_init_lock
 4389      00
 4390 284b E8000000 		call	_InitializeCriticalSection@4
 4390      00
 4391 2850 68000000 		pushl	$_ptw32_spinlock_test_init_lock
 4391      00
 4392 2855 E8000000 		call	_InitializeCriticalSection@4
 4392      00
 4393 285a 8B1D0000 		movl	_ptw32_processInitialized, %ebx
 4393      0000
 4394 2860 83C40C   		addl	$12, %esp
 4395 2863 E9E2FDFF 		jmp	L811
 4395      FF
 4396              	LC5:
 4397 2868 51756575 		.ascii "QueueUserAPCEx_Fini\0"
 4397      65557365 
 4397      72415043 
 4397      45785F46 
 4397      696E6900 
 4398 287c 8D742600 		.p2align 4,,15
 4399              	.globl _pthread_win32_process_detach_np
 4400              		.def	_pthread_win32_process_detach_np;	.scl	2;	.type	32;	.endef
 4401              	_pthread_win32_process_detach_np:
 4402 2880 55       		pushl	%ebp
 4403 2881 89E5     		movl	%esp, %ebp
 4404 2883 57       		pushl	%edi
 4405 2884 56       		pushl	%esi
 4406 2885 81EC9000 		subl	$144, %esp
 4406      0000
 4407 288b A1000000 		movl	_ptw32_processInitialized, %eax
 4407      00
 4408 2890 85C0     		testl	%eax, %eax
 4409 2892 750C     		jne	L847
 4410              	L837:
 4411 2894 8D65F8   		leal	-8(%ebp), %esp
 4412 2897 B8010000 		movl	$1, %eax
 4412      00
 4413 289c 5E       		popl	%esi
 4414 289d 5F       		popl	%edi
 4415 289e 5D       		popl	%ebp
 4416 289f C3       		ret
 4417              		.p2align 4,,7
 4418              	L847:
 4419 28a0 83EC0C   		subl	$12, %esp
 4420 28a3 A10C0000 		movl	_ptw32_selfThreadKey, %eax
 4420      00
 4421 28a8 50       		pushl	%eax
 4422 28a9 E8522100 		call	_pthread_getspecific
 4422      00
 4423 28ae 83C410   		addl	$16, %esp
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 94


 4424 28b1 85C0     		testl	%eax, %eax
 4425 28b3 7406     		je	L838
 4426 28b5 83782401 		cmpl	$1, 36(%eax)
 4427 28b9 744E     		je	L848
 4428              	L838:
 4429 28bb E840D7FF 		call	_ptw32_processTerminate
 4429      FF
 4430 28c0 A1100000 		movl	_ptw32_h_quserex, %eax
 4430      00
 4431 28c5 85C0     		testl	%eax, %eax
 4432 28c7 7517     		jne	L849
 4433              	L844:
 4434 28c9 A1000000 		movl	_ptw32_h_kernel32, %eax
 4434      00
 4435 28ce 85C0     		testl	%eax, %eax
 4436 28d0 74C2     		je	L837
 4437 28d2 83EC0C   		subl	$12, %esp
 4438 28d5 50       		pushl	%eax
 4439 28d6 E8000000 		call	_FreeLibrary@4
 4439      00
 4440 28db 83C40C   		addl	$12, %esp
 4441 28de EBB4     		jmp	L837
 4442              	L849:
 4443 28e0 56       		pushl	%esi
 4444 28e1 56       		pushl	%esi
 4445 28e2 68682800 		pushl	$LC5
 4445      00
 4446 28e7 50       		pushl	%eax
 4447 28e8 E8000000 		call	_GetProcAddress@8
 4447      00
 4448 28ed 5A       		popl	%edx
 4449 28ee 85C0     		testl	%eax, %eax
 4450 28f0 59       		popl	%ecx
 4451 28f1 7402     		je	L845
 4452 28f3 FFD0     		call	*%eax
 4453              	L845:
 4454 28f5 83EC0C   		subl	$12, %esp
 4455 28f8 8B151000 		movl	_ptw32_h_quserex, %edx
 4455      0000
 4456 28fe 52       		pushl	%edx
 4457 28ff E8000000 		call	_FreeLibrary@4
 4457      00
 4458 2904 83C40C   		addl	$12, %esp
 4459 2907 EBC0     		jmp	L844
 4460              	L848:
 4461 2909 8B500C   		movl	12(%eax), %edx
 4462 290c 8B4008   		movl	8(%eax), %eax
 4463 290f 89C6     		movl	%eax, %esi
 4464 2911 85C0     		testl	%eax, %eax
 4465 2913 7445     		je	L843
 4466 2915 FC       		cld
 4467 2916 8DBD68FF 		leal	-152(%ebp), %edi
 4467      FFFF
 4468 291c B9230000 		movl	$35, %ecx
 4468      00
 4469 2921 F3       		rep
 4470 2922 A5       		movsl
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 95


 4471 2923 51       		pushl	%ecx
 4472 2924 51       		pushl	%ecx
 4473 2925 52       		pushl	%edx
 4474 2926 50       		pushl	%eax
 4475 2927 E8C4F1FF 		call	_ptw32_threadReusePush
 4475      FF
 4476 292c 8B45A4   		movl	-92(%ebp), %eax
 4477 292f 83C410   		addl	$16, %esp
 4478 2932 85C0     		testl	%eax, %eax
 4479 2934 754B     		jne	L850
 4480              	L841:
 4481 2936 83EC0C   		subl	$12, %esp
 4482 2939 8D4D98   		leal	-104(%ebp), %ecx
 4483 293c 51       		pushl	%ecx
 4484 293d E82EF3FF 		call	_pthread_mutex_destroy
 4484      FF
 4485 2942 8D5590   		leal	-112(%ebp), %edx
 4486 2945 891424   		movl	%edx, (%esp)
 4487 2948 E823F3FF 		call	_pthread_mutex_destroy
 4487      FF
 4488 294d 8B856CFF 		movl	-148(%ebp), %eax
 4488      FFFF
 4489 2953 83C410   		addl	$16, %esp
 4490 2956 85C0     		testl	%eax, %eax
 4491 2958 7519     		jne	L851
 4492              	L843:
 4493 295a 8B3D0C00 		movl	_ptw32_selfThreadKey, %edi
 4493      0000
 4494 2960 50       		pushl	%eax
 4495 2961 50       		pushl	%eax
 4496 2962 6A00     		pushl	$0
 4497 2964 8B37     		movl	(%edi), %esi
 4498 2966 56       		pushl	%esi
 4499 2967 E8000000 		call	_TlsSetValue@8
 4499      00
 4500 296c 5F       		popl	%edi
 4501 296d 58       		popl	%eax
 4502 296e E948FFFF 		jmp	L838
 4502      FF
 4503              	L851:
 4504 2973 83EC0C   		subl	$12, %esp
 4505 2976 50       		pushl	%eax
 4506 2977 E8000000 		call	_CloseHandle@4
 4506      00
 4507 297c 83C40C   		addl	$12, %esp
 4508 297f EBD9     		jmp	L843
 4509              	L850:
 4510 2981 83EC0C   		subl	$12, %esp
 4511 2984 50       		pushl	%eax
 4512 2985 E8000000 		call	_CloseHandle@4
 4512      00
 4513 298a 83C40C   		addl	$12, %esp
 4514 298d EBA7     		jmp	L841
 4515 298f 90       		.p2align 4,,15
 4516              	.globl _pthread_win32_thread_attach_np
 4517              		.def	_pthread_win32_thread_attach_np;	.scl	2;	.type	32;	.endef
 4518              	_pthread_win32_thread_attach_np:
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 96


 4519 2990 55       		pushl	%ebp
 4520 2991 B8010000 		movl	$1, %eax
 4520      00
 4521 2996 89E5     		movl	%esp, %ebp
 4522 2998 5D       		popl	%ebp
 4523 2999 C3       		ret
 4524 299a 8DB60000 		.p2align 4,,15
 4524      0000
 4525              	.globl _pthread_win32_thread_detach_np
 4526              		.def	_pthread_win32_thread_detach_np;	.scl	2;	.type	32;	.endef
 4527              	_pthread_win32_thread_detach_np:
 4528 29a0 55       		pushl	%ebp
 4529 29a1 89E5     		movl	%esp, %ebp
 4530 29a3 57       		pushl	%edi
 4531 29a4 56       		pushl	%esi
 4532 29a5 53       		pushl	%ebx
 4533 29a6 81EC9C00 		subl	$156, %esp
 4533      0000
 4534 29ac 8B150000 		movl	_ptw32_processInitialized, %edx
 4534      0000
 4535 29b2 85D2     		testl	%edx, %edx
 4536 29b4 750D     		jne	L861
 4537              	L854:
 4538 29b6 8D65F4   		leal	-12(%ebp), %esp
 4539 29b9 B8010000 		movl	$1, %eax
 4539      00
 4540 29be 5B       		popl	%ebx
 4541 29bf 5E       		popl	%esi
 4542 29c0 5F       		popl	%edi
 4543 29c1 5D       		popl	%ebp
 4544 29c2 C3       		ret
 4545              		.p2align 4,,7
 4546              	L861:
 4547 29c3 83EC0C   		subl	$12, %esp
 4548 29c6 8B150C00 		movl	_ptw32_selfThreadKey, %edx
 4548      0000
 4549 29cc 52       		pushl	%edx
 4550 29cd E82E2000 		call	_pthread_getspecific
 4550      00
 4551 29d2 83C410   		addl	$16, %esp
 4552 29d5 89C6     		movl	%eax, %esi
 4553 29d7 85C0     		testl	%eax, %eax
 4554 29d9 74DB     		je	L854
 4555 29db 8D7E30   		leal	48(%esi), %edi
 4556 29de 50       		pushl	%eax
 4557 29df 50       		pushl	%eax
 4558 29e0 8B4E0C   		movl	12(%esi), %ecx
 4559 29e3 51       		pushl	%ecx
 4560 29e4 8B4608   		movl	8(%esi), %eax
 4561 29e7 50       		pushl	%eax
 4562 29e8 E823D8FF 		call	_ptw32_callUserDestroyRoutines
 4562      FF
 4563 29ed 893C24   		movl	%edi, (%esp)
 4564 29f0 E89BF4FF 		call	_pthread_mutex_lock
 4564      FF
 4565 29f5 C7461406 		movl	$6, 20(%esi)
 4565      000000
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 97


 4566 29fc 893C24   		movl	%edi, (%esp)
 4567 29ff E80CF8FF 		call	_pthread_mutex_unlock
 4567      FF
 4568 2a04 83C410   		addl	$16, %esp
 4569 2a07 837E2401 		cmpl	$1, 36(%esi)
 4570 2a0b 75A9     		jne	L854
 4571 2a0d 8B4608   		movl	8(%esi), %eax
 4572 2a10 8B560C   		movl	12(%esi), %edx
 4573 2a13 85C0     		testl	%eax, %eax
 4574 2a15 89C6     		movl	%eax, %esi
 4575 2a17 7445     		je	L860
 4576 2a19 FC       		cld
 4577 2a1a 8DBD58FF 		leal	-168(%ebp), %edi
 4577      FFFF
 4578 2a20 B9230000 		movl	$35, %ecx
 4578      00
 4579 2a25 F3       		rep
 4580 2a26 A5       		movsl
 4581 2a27 56       		pushl	%esi
 4582 2a28 56       		pushl	%esi
 4583 2a29 52       		pushl	%edx
 4584 2a2a 50       		pushl	%eax
 4585 2a2b E8C0F0FF 		call	_ptw32_threadReusePush
 4585      FF
 4586 2a30 8B4594   		movl	-108(%ebp), %eax
 4587 2a33 83C410   		addl	$16, %esp
 4588 2a36 85C0     		testl	%eax, %eax
 4589 2a38 754B     		jne	L862
 4590              	L858:
 4591 2a3a 83EC0C   		subl	$12, %esp
 4592 2a3d 8D7588   		leal	-120(%ebp), %esi
 4593 2a40 8D5D80   		leal	-128(%ebp), %ebx
 4594 2a43 56       		pushl	%esi
 4595 2a44 E827F2FF 		call	_pthread_mutex_destroy
 4595      FF
 4596 2a49 891C24   		movl	%ebx, (%esp)
 4597 2a4c E81FF2FF 		call	_pthread_mutex_destroy
 4597      FF
 4598 2a51 8B855CFF 		movl	-164(%ebp), %eax
 4598      FFFF
 4599 2a57 83C410   		addl	$16, %esp
 4600 2a5a 85C0     		testl	%eax, %eax
 4601 2a5c 7519     		jne	L863
 4602              	L860:
 4603 2a5e 8B3D0C00 		movl	_ptw32_selfThreadKey, %edi
 4603      0000
 4604 2a64 53       		pushl	%ebx
 4605 2a65 53       		pushl	%ebx
 4606 2a66 6A00     		pushl	$0
 4607 2a68 8B17     		movl	(%edi), %edx
 4608 2a6a 52       		pushl	%edx
 4609 2a6b E8000000 		call	_TlsSetValue@8
 4609      00
 4610 2a70 58       		popl	%eax
 4611 2a71 5A       		popl	%edx
 4612 2a72 E93FFFFF 		jmp	L854
 4612      FF
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 98


 4613              	L863:
 4614 2a77 83EC0C   		subl	$12, %esp
 4615 2a7a 50       		pushl	%eax
 4616 2a7b E8000000 		call	_CloseHandle@4
 4616      00
 4617 2a80 83C40C   		addl	$12, %esp
 4618 2a83 EBD9     		jmp	L860
 4619              	L862:
 4620 2a85 83EC0C   		subl	$12, %esp
 4621 2a88 50       		pushl	%eax
 4622 2a89 E8000000 		call	_CloseHandle@4
 4622      00
 4623 2a8e 83C40C   		addl	$12, %esp
 4624 2a91 EBA7     		jmp	L858
 4625 2a93 8DB60000 		.p2align 4,,15
 4625      00008DBC 
 4625      27000000 
 4625      00
 4626              	.globl _pthread_win32_test_features_np
 4627              		.def	_pthread_win32_test_features_np;	.scl	2;	.type	32;	.endef
 4628              	_pthread_win32_test_features_np:
 4629 2aa0 55       		pushl	%ebp
 4630 2aa1 8B152000 		movl	_ptw32_features, %edx
 4630      0000
 4631 2aa7 89E5     		movl	%esp, %ebp
 4632 2aa9 8B4D08   		movl	8(%ebp), %ecx
 4633 2aac 5D       		popl	%ebp
 4634 2aad 21CA     		andl	%ecx, %edx
 4635 2aaf 39CA     		cmpl	%ecx, %edx
 4636 2ab1 0F94C0   		sete	%al
 4637 2ab4 25FF0000 		andl	$255, %eax
 4637      00
 4638 2ab9 C3       		ret
 4639 2aba 8DB60000 		.p2align 4,,15
 4639      0000
 4640              	.globl _pthread_timechange_handler_np
 4641              		.def	_pthread_timechange_handler_np;	.scl	2;	.type	32;	.endef
 4642              	_pthread_timechange_handler_np:
 4643 2ac0 55       		pushl	%ebp
 4644 2ac1 89E5     		movl	%esp, %ebp
 4645 2ac3 56       		pushl	%esi
 4646 2ac4 53       		pushl	%ebx
 4647 2ac5 31DB     		xorl	%ebx, %ebx
 4648 2ac7 83EC1C   		subl	$28, %esp
 4649 2aca 68000000 		pushl	$_ptw32_cond_list_lock
 4649      00
 4650 2acf E8000000 		call	_EnterCriticalSection@4
 4650      00
 4651 2ad4 8B151400 		movl	_ptw32_cond_list_head, %edx
 4651      0000
 4652 2ada 83C40C   		addl	$12, %esp
 4653 2add 8955F4   		movl	%edx, -12(%ebp)
 4654 2ae0 85D2     		testl	%edx, %edx
 4655 2ae2 7422     		je	L867
 4656 2ae4 8D75F4   		leal	-12(%ebp), %esi
 4657              		.p2align 4,,7
 4658              	L870:
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 99


 4659 2ae7 83EC0C   		subl	$12, %esp
 4660 2aea 56       		pushl	%esi
 4661 2aeb E8D0E7FF 		call	_pthread_cond_broadcast
 4661      FF
 4662 2af0 83C410   		addl	$16, %esp
 4663 2af3 8B4DF4   		movl	-12(%ebp), %ecx
 4664 2af6 89C3     		movl	%eax, %ebx
 4665 2af8 8B5118   		movl	24(%ecx), %edx
 4666 2afb 8955F4   		movl	%edx, -12(%ebp)
 4667 2afe 85D2     		testl	%edx, %edx
 4668 2b00 7404     		je	L867
 4669 2b02 85C0     		testl	%eax, %eax
 4670 2b04 74E1     		je	L870
 4671              	L867:
 4672 2b06 83EC0C   		subl	$12, %esp
 4673 2b09 68000000 		pushl	$_ptw32_cond_list_lock
 4673      00
 4674 2b0e E8000000 		call	_LeaveCriticalSection@4
 4674      00
 4675 2b13 83C40C   		addl	$12, %esp
 4676 2b16 85DB     		testl	%ebx, %ebx
 4677 2b18 0F95C0   		setne	%al
 4678 2b1b 25FF0000 		andl	$255, %eax
 4678      00
 4679 2b20 8D65F8   		leal	-8(%ebp), %esp
 4680 2b23 48       		decl	%eax
 4681 2b24 5B       		popl	%ebx
 4682 2b25 83E0F5   		andl	$-11, %eax
 4683 2b28 5E       		popl	%esi
 4684 2b29 83C00B   		addl	$11, %eax
 4685 2b2c 5D       		popl	%ebp
 4686 2b2d C3       		ret
 4687 2b2e 89F6     		.p2align 4,,15
 4688              	.globl _pthread_rwlock_init
 4689              		.def	_pthread_rwlock_init;	.scl	2;	.type	32;	.endef
 4690              	_pthread_rwlock_init:
 4691 2b30 55       		pushl	%ebp
 4692 2b31 B8160000 		movl	$22, %eax
 4692      00
 4693 2b36 89E5     		movl	%esp, %ebp
 4694 2b38 57       		pushl	%edi
 4695 2b39 56       		pushl	%esi
 4696 2b3a 53       		pushl	%ebx
 4697 2b3b 31DB     		xorl	%ebx, %ebx
 4698 2b3d 83EC0C   		subl	$12, %esp
 4699 2b40 8B7D08   		movl	8(%ebp), %edi
 4700 2b43 8B550C   		movl	12(%ebp), %edx
 4701 2b46 85FF     		testl	%edi, %edi
 4702 2b48 7413     		je	L874
 4703 2b4a 85D2     		testl	%edx, %edx
 4704 2b4c 7417     		je	L876
 4705 2b4e 8B02     		movl	(%edx), %eax
 4706 2b50 85C0     		testl	%eax, %eax
 4707 2b52 7411     		je	L876
 4708 2b54 BE160000 		movl	$22, %esi
 4708      00
 4709              	L877:
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 100


 4710 2b59 891F     		movl	%ebx, (%edi)
 4711 2b5b 89F0     		movl	%esi, %eax
 4712              	L874:
 4713 2b5d 8D65F4   		leal	-12(%ebp), %esp
 4714 2b60 5B       		popl	%ebx
 4715 2b61 5E       		popl	%esi
 4716 2b62 5F       		popl	%edi
 4717 2b63 5D       		popl	%ebp
 4718 2b64 C3       		ret
 4719              		.p2align 4,,7
 4720              	L876:
 4721 2b65 BE0C0000 		movl	$12, %esi
 4721      00
 4722 2b6a 53       		pushl	%ebx
 4723 2b6b 53       		pushl	%ebx
 4724 2b6c 6A1C     		pushl	$28
 4725 2b6e 6A01     		pushl	$1
 4726 2b70 E8000000 		call	_calloc
 4726      00
 4727 2b75 83C410   		addl	$16, %esp
 4728 2b78 89C3     		movl	%eax, %ebx
 4729 2b7a 85C0     		testl	%eax, %eax
 4730 2b7c 74DB     		je	L877
 4731 2b7e C7400C00 		movl	$0, 12(%eax)
 4731      000000
 4732 2b85 C7401000 		movl	$0, 16(%eax)
 4732      000000
 4733 2b8c C7401400 		movl	$0, 20(%eax)
 4733      000000
 4734 2b93 51       		pushl	%ecx
 4735 2b94 51       		pushl	%ecx
 4736 2b95 6A00     		pushl	$0
 4737 2b97 50       		pushl	%eax
 4738 2b98 E813F0FF 		call	_pthread_mutex_init
 4738      FF
 4739 2b9d 83C410   		addl	$16, %esp
 4740 2ba0 89C6     		movl	%eax, %esi
 4741 2ba2 85C0     		testl	%eax, %eax
 4742 2ba4 7556     		jne	L880
 4743 2ba6 52       		pushl	%edx
 4744 2ba7 52       		pushl	%edx
 4745 2ba8 8D5304   		leal	4(%ebx), %edx
 4746 2bab 6A00     		pushl	$0
 4747 2bad 8955F0   		movl	%edx, -16(%ebp)
 4748 2bb0 52       		pushl	%edx
 4749 2bb1 E8FAEFFF 		call	_pthread_mutex_init
 4749      FF
 4750 2bb6 83C410   		addl	$16, %esp
 4751 2bb9 89C6     		movl	%eax, %esi
 4752 2bbb 85C0     		testl	%eax, %eax
 4753 2bbd 7531     		jne	L882
 4754 2bbf 8D4B08   		leal	8(%ebx), %ecx
 4755 2bc2 50       		pushl	%eax
 4756 2bc3 50       		pushl	%eax
 4757 2bc4 6A00     		pushl	$0
 4758 2bc6 51       		pushl	%ecx
 4759 2bc7 E864E3FF 		call	_pthread_cond_init
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 101


 4759      FF
 4760 2bcc 83C410   		addl	$16, %esp
 4761 2bcf 89C6     		movl	%eax, %esi
 4762 2bd1 85C0     		testl	%eax, %eax
 4763 2bd3 750C     		jne	L884
 4764 2bd5 C74318E2 		movl	$262974946, 24(%ebx)
 4764      ADAC0F
 4765 2bdc E978FFFF 		jmp	L877
 4765      FF
 4766              	L884:
 4767 2be1 83EC0C   		subl	$12, %esp
 4768 2be4 8B55F0   		movl	-16(%ebp), %edx
 4769 2be7 52       		pushl	%edx
 4770 2be8 E883F0FF 		call	_pthread_mutex_destroy
 4770      FF
 4771 2bed 83C410   		addl	$16, %esp
 4772              	L882:
 4773 2bf0 83EC0C   		subl	$12, %esp
 4774 2bf3 53       		pushl	%ebx
 4775 2bf4 E877F0FF 		call	_pthread_mutex_destroy
 4775      FF
 4776 2bf9 83C410   		addl	$16, %esp
 4777              	L880:
 4778 2bfc 83EC0C   		subl	$12, %esp
 4779 2bff 53       		pushl	%ebx
 4780 2c00 31DB     		xorl	%ebx, %ebx
 4781 2c02 E8000000 		call	_free
 4781      00
 4782 2c07 83C410   		addl	$16, %esp
 4783 2c0a E94AFFFF 		jmp	L877
 4783      FF
 4784 2c0f 90       		.p2align 4,,15
 4785              	.globl _pthread_rwlock_destroy
 4786              		.def	_pthread_rwlock_destroy;	.scl	2;	.type	32;	.endef
 4787              	_pthread_rwlock_destroy:
 4788 2c10 55       		pushl	%ebp
 4789 2c11 89E5     		movl	%esp, %ebp
 4790 2c13 57       		pushl	%edi
 4791 2c14 56       		pushl	%esi
 4792 2c15 31FF     		xorl	%edi, %edi
 4793 2c17 53       		pushl	%ebx
 4794 2c18 83EC0C   		subl	$12, %esp
 4795 2c1b 8B7508   		movl	8(%ebp), %esi
 4796 2c1e C745F000 		movl	$0, -16(%ebp)
 4796      000000
 4797 2c25 C745EC00 		movl	$0, -20(%ebp)
 4797      000000
 4798 2c2c 85F6     		testl	%esi, %esi
 4799 2c2e 7418     		je	L904
 4800 2c30 8B1E     		movl	(%esi), %ebx
 4801 2c32 85DB     		testl	%ebx, %ebx
 4802 2c34 7412     		je	L904
 4803 2c36 83FBFF   		cmpl	$-1, %ebx
 4804 2c39 0F840101 		je	L888
 4804      0000
 4805 2c3f 817B18E2 		cmpl	$262974946, 24(%ebx)
 4805      ADAC0F
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 102


 4806 2c46 740D     		je	L889
 4807              	L904:
 4808 2c48 B8160000 		movl	$22, %eax
 4808      00
 4809              	L885:
 4810 2c4d 8D65F4   		leal	-12(%ebp), %esp
 4811 2c50 5B       		popl	%ebx
 4812 2c51 5E       		popl	%esi
 4813 2c52 5F       		popl	%edi
 4814 2c53 5D       		popl	%ebp
 4815 2c54 C3       		ret
 4816              	L889:
 4817 2c55 83EC0C   		subl	$12, %esp
 4818 2c58 53       		pushl	%ebx
 4819 2c59 E832F2FF 		call	_pthread_mutex_lock
 4819      FF
 4820 2c5e 83C410   		addl	$16, %esp
 4821 2c61 85C0     		testl	%eax, %eax
 4822 2c63 75E8     		jne	L885
 4823 2c65 83EC0C   		subl	$12, %esp
 4824 2c68 8D5304   		leal	4(%ebx), %edx
 4825 2c6b 8955E8   		movl	%edx, -24(%ebp)
 4826 2c6e 52       		pushl	%edx
 4827 2c6f E81CF2FF 		call	_pthread_mutex_lock
 4827      FF
 4828 2c74 83C410   		addl	$16, %esp
 4829 2c77 89C7     		movl	%eax, %edi
 4830 2c79 85C0     		testl	%eax, %eax
 4831 2c7b 7560     		jne	L903
 4832 2c7d 8B5310   		movl	16(%ebx), %edx
 4833 2c80 85D2     		testl	%edx, %edx
 4834 2c82 7E35     		jle	L905
 4835              	L893:
 4836 2c84 83EC0C   		subl	$12, %esp
 4837 2c87 8B75E8   		movl	-24(%ebp), %esi
 4838 2c8a 56       		pushl	%esi
 4839 2c8b E880F5FF 		call	_pthread_mutex_unlock
 4839      FF
 4840 2c90 891C24   		movl	%ebx, (%esp)
 4841 2c93 89C7     		movl	%eax, %edi
 4842 2c95 E876F5FF 		call	_pthread_mutex_unlock
 4842      FF
 4843 2c9a C745EC10 		movl	$16, -20(%ebp)
 4843      000000
 4844 2ca1 8945F0   		movl	%eax, -16(%ebp)
 4845              	L902:
 4846 2ca4 83C410   		addl	$16, %esp
 4847              	L897:
 4848 2ca7 89F8     		movl	%edi, %eax
 4849 2ca9 85FF     		testl	%edi, %edi
 4850 2cab 75A0     		jne	L885
 4851 2cad 8B45F0   		movl	-16(%ebp), %eax
 4852 2cb0 85C0     		testl	%eax, %eax
 4853 2cb2 7599     		jne	L885
 4854 2cb4 8B45EC   		movl	-20(%ebp), %eax
 4855 2cb7 EB94     		jmp	L885
 4856              	L905:
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 103


 4857 2cb9 8B4B14   		movl	20(%ebx), %ecx
 4858 2cbc 394B0C   		cmpl	%ecx, 12(%ebx)
 4859 2cbf 7FC3     		jg	L893
 4860 2cc1 83EC0C   		subl	$12, %esp
 4861 2cc4 8B7DE8   		movl	-24(%ebp), %edi
 4862 2cc7 C7431800 		movl	$0, 24(%ebx)
 4862      000000
 4863 2cce 57       		pushl	%edi
 4864 2ccf E83CF5FF 		call	_pthread_mutex_unlock
 4864      FF
 4865 2cd4 83C410   		addl	$16, %esp
 4866 2cd7 89C7     		movl	%eax, %edi
 4867 2cd9 85C0     		testl	%eax, %eax
 4868 2cdb 7410     		je	L895
 4869              	L903:
 4870 2cdd 83EC0C   		subl	$12, %esp
 4871 2ce0 53       		pushl	%ebx
 4872 2ce1 E82AF5FF 		call	_pthread_mutex_unlock
 4872      FF
 4873 2ce6 89F8     		movl	%edi, %eax
 4874 2ce8 E960FFFF 		jmp	L885
 4874      FF
 4875              	L895:
 4876 2ced 83EC0C   		subl	$12, %esp
 4877 2cf0 53       		pushl	%ebx
 4878 2cf1 E81AF5FF 		call	_pthread_mutex_unlock
 4878      FF
 4879 2cf6 83C410   		addl	$16, %esp
 4880 2cf9 85C0     		testl	%eax, %eax
 4881 2cfb 0F854CFF 		jne	L885
 4881      FFFF
 4882 2d01 83EC0C   		subl	$12, %esp
 4883 2d04 8D4B08   		leal	8(%ebx), %ecx
 4884 2d07 C7060000 		movl	$0, (%esi)
 4884      0000
 4885 2d0d 51       		pushl	%ecx
 4886 2d0e E86DE3FF 		call	_pthread_cond_destroy
 4886      FF
 4887 2d13 8B55E8   		movl	-24(%ebp), %edx
 4888 2d16 89C7     		movl	%eax, %edi
 4889 2d18 58       		popl	%eax
 4890 2d19 52       		pushl	%edx
 4891 2d1a E851EFFF 		call	_pthread_mutex_destroy
 4891      FF
 4892 2d1f 891C24   		movl	%ebx, (%esp)
 4893 2d22 8945F0   		movl	%eax, -16(%ebp)
 4894 2d25 E846EFFF 		call	_pthread_mutex_destroy
 4894      FF
 4895 2d2a 891C24   		movl	%ebx, (%esp)
 4896 2d2d 8945EC   		movl	%eax, -20(%ebp)
 4897 2d30 E8000000 		call	_free
 4897      00
 4898 2d35 E96AFFFF 		jmp	L902
 4898      FF
 4899 2d3a 8DB60000 		.p2align 4,,7
 4899      0000
 4900              	L888:
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 104


 4901 2d40 83EC0C   		subl	$12, %esp
 4902 2d43 68000000 		pushl	$_ptw32_rwlock_test_init_lock
 4902      00
 4903 2d48 E8000000 		call	_EnterCriticalSection@4
 4903      00
 4904 2d4d 83C40C   		addl	$12, %esp
 4905 2d50 833EFF   		cmpl	$-1, (%esi)
 4906 2d53 741A     		je	L906
 4907 2d55 BF100000 		movl	$16, %edi
 4907      00
 4908              	L899:
 4909 2d5a 83EC0C   		subl	$12, %esp
 4910 2d5d 68000000 		pushl	$_ptw32_rwlock_test_init_lock
 4910      00
 4911 2d62 E8000000 		call	_LeaveCriticalSection@4
 4911      00
 4912 2d67 83C40C   		addl	$12, %esp
 4913 2d6a E938FFFF 		jmp	L897
 4913      FF
 4914              	L906:
 4915 2d6f C7060000 		movl	$0, (%esi)
 4915      0000
 4916 2d75 EBE3     		jmp	L899
 4917 2d77 89F68DBC 		.p2align 4,,15
 4917      27000000 
 4917      00
 4918              	.globl _pthread_rwlockattr_init
 4919              		.def	_pthread_rwlockattr_init;	.scl	2;	.type	32;	.endef
 4920              	_pthread_rwlockattr_init:
 4921 2d80 55       		pushl	%ebp
 4922 2d81 89E5     		movl	%esp, %ebp
 4923 2d83 53       		pushl	%ebx
 4924 2d84 83EC0C   		subl	$12, %esp
 4925 2d87 31DB     		xorl	%ebx, %ebx
 4926 2d89 6A04     		pushl	$4
 4927 2d8b 6A01     		pushl	$1
 4928 2d8d E8000000 		call	_calloc
 4928      00
 4929 2d92 83C410   		addl	$16, %esp
 4930 2d95 89C2     		movl	%eax, %edx
 4931 2d97 85C0     		testl	%eax, %eax
 4932 2d99 7415     		je	L910
 4933 2d9b C7000000 		movl	$0, (%eax)
 4933      0000
 4934              	L909:
 4935 2da1 8B4D08   		movl	8(%ebp), %ecx
 4936 2da4 89D8     		movl	%ebx, %eax
 4937 2da6 8911     		movl	%edx, (%ecx)
 4938 2da8 8B5DFC   		movl	-4(%ebp), %ebx
 4939 2dab 89EC     		movl	%ebp, %esp
 4940 2dad 5D       		popl	%ebp
 4941 2dae C3       		ret
 4942 2daf 90       		.p2align 4,,7
 4943              	L910:
 4944 2db0 BB0C0000 		movl	$12, %ebx
 4944      00
 4945 2db5 EBEA     		jmp	L909
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 105


 4946 2db7 89F68DBC 		.p2align 4,,15
 4946      27000000 
 4946      00
 4947              	.globl _pthread_rwlockattr_destroy
 4948              		.def	_pthread_rwlockattr_destroy;	.scl	2;	.type	32;	.endef
 4949              	_pthread_rwlockattr_destroy:
 4950 2dc0 55       		pushl	%ebp
 4951 2dc1 89E5     		movl	%esp, %ebp
 4952 2dc3 53       		pushl	%ebx
 4953 2dc4 50       		pushl	%eax
 4954 2dc5 31DB     		xorl	%ebx, %ebx
 4955 2dc7 8B4508   		movl	8(%ebp), %eax
 4956 2dca 85C0     		testl	%eax, %eax
 4957 2dcc 7406     		je	L913
 4958 2dce 8B10     		movl	(%eax), %edx
 4959 2dd0 85D2     		testl	%edx, %edx
 4960 2dd2 750E     		jne	L912
 4961              	L913:
 4962 2dd4 BB160000 		movl	$22, %ebx
 4962      00
 4963              	L914:
 4964 2dd9 89D8     		movl	%ebx, %eax
 4965 2ddb 8B5DFC   		movl	-4(%ebp), %ebx
 4966 2dde 89EC     		movl	%ebp, %esp
 4967 2de0 5D       		popl	%ebp
 4968 2de1 C3       		ret
 4969              		.p2align 4,,7
 4970              	L912:
 4971 2de2 83EC0C   		subl	$12, %esp
 4972 2de5 C7000000 		movl	$0, (%eax)
 4972      0000
 4973 2deb 52       		pushl	%edx
 4974 2dec E8000000 		call	_free
 4974      00
 4975 2df1 83C410   		addl	$16, %esp
 4976 2df4 EBE3     		jmp	L914
 4977 2df6 8D76008D 		.p2align 4,,15
 4977      BC270000 
 4977      0000
 4978              	.globl _pthread_rwlockattr_getpshared
 4979              		.def	_pthread_rwlockattr_getpshared;	.scl	2;	.type	32;	.endef
 4980              	_pthread_rwlockattr_getpshared:
 4981 2e00 55       		pushl	%ebp
 4982 2e01 89E5     		movl	%esp, %ebp
 4983 2e03 8B4508   		movl	8(%ebp), %eax
 4984 2e06 8B550C   		movl	12(%ebp), %edx
 4985 2e09 85C0     		testl	%eax, %eax
 4986 2e0b 7413     		je	L916
 4987 2e0d 8B00     		movl	(%eax), %eax
 4988 2e0f 85C0     		testl	%eax, %eax
 4989 2e11 740D     		je	L916
 4990 2e13 85D2     		testl	%edx, %edx
 4991 2e15 7409     		je	L916
 4992 2e17 8B08     		movl	(%eax), %ecx
 4993 2e19 31C0     		xorl	%eax, %eax
 4994 2e1b 890A     		movl	%ecx, (%edx)
 4995              	L917:
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 106


 4996 2e1d 5D       		popl	%ebp
 4997 2e1e C3       		ret
 4998 2e1f 90       		.p2align 4,,7
 4999              	L916:
 5000 2e20 B8160000 		movl	$22, %eax
 5000      00
 5001 2e25 EBF6     		jmp	L917
 5002 2e27 89F68DBC 		.p2align 4,,15
 5002      27000000 
 5002      00
 5003              	.globl _pthread_rwlockattr_setpshared
 5004              		.def	_pthread_rwlockattr_setpshared;	.scl	2;	.type	32;	.endef
 5005              	_pthread_rwlockattr_setpshared:
 5006 2e30 55       		pushl	%ebp
 5007 2e31 89E5     		movl	%esp, %ebp
 5008 2e33 8B4508   		movl	8(%ebp), %eax
 5009 2e36 8B4D0C   		movl	12(%ebp), %ecx
 5010 2e39 85C0     		testl	%eax, %eax
 5011 2e3b 7413     		je	L919
 5012 2e3d 8B10     		movl	(%eax), %edx
 5013 2e3f 85D2     		testl	%edx, %edx
 5014 2e41 740D     		je	L919
 5015 2e43 83F901   		cmpl	$1, %ecx
 5016 2e46 7708     		ja	L919
 5017 2e48 31C0     		xorl	%eax, %eax
 5018 2e4a 890A     		movl	%ecx, (%edx)
 5019              	L922:
 5020 2e4c 5D       		popl	%ebp
 5021 2e4d C3       		ret
 5022 2e4e 89F6     		.p2align 4,,7
 5023              	L919:
 5024 2e50 B8160000 		movl	$22, %eax
 5024      00
 5025 2e55 EBF5     		jmp	L922
 5026 2e57 89F68DBC 		.p2align 4,,15
 5026      27000000 
 5026      00
 5027              	.globl _pthread_rwlock_rdlock
 5028              		.def	_pthread_rwlock_rdlock;	.scl	2;	.type	32;	.endef
 5029              	_pthread_rwlock_rdlock:
 5030 2e60 55       		pushl	%ebp
 5031 2e61 89E5     		movl	%esp, %ebp
 5032 2e63 57       		pushl	%edi
 5033 2e64 56       		pushl	%esi
 5034 2e65 53       		pushl	%ebx
 5035 2e66 83EC0C   		subl	$12, %esp
 5036 2e69 8B7508   		movl	8(%ebp), %esi
 5037 2e6c 85F6     		testl	%esi, %esi
 5038 2e6e 7418     		je	L940
 5039 2e70 8B1E     		movl	(%esi), %ebx
 5040 2e72 85DB     		testl	%ebx, %ebx
 5041 2e74 7412     		je	L940
 5042 2e76 83FBFF   		cmpl	$-1, %ebx
 5043 2e79 0F849100 		je	L941
 5043      0000
 5044              	L926:
 5045 2e7f 817B18E2 		cmpl	$262974946, 24(%ebx)
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 107


 5045      ADAC0F
 5046 2e86 740D     		je	L932
 5047              	L940:
 5048 2e88 B8160000 		movl	$22, %eax
 5048      00
 5049              	L923:
 5050 2e8d 8D65F4   		leal	-12(%ebp), %esp
 5051 2e90 5B       		popl	%ebx
 5052 2e91 5E       		popl	%esi
 5053 2e92 5F       		popl	%edi
 5054 2e93 5D       		popl	%ebp
 5055 2e94 C3       		ret
 5056              	L932:
 5057 2e95 83EC0C   		subl	$12, %esp
 5058 2e98 53       		pushl	%ebx
 5059 2e99 E8F2EFFF 		call	_pthread_mutex_lock
 5059      FF
 5060 2e9e 83C410   		addl	$16, %esp
 5061 2ea1 85C0     		testl	%eax, %eax
 5062 2ea3 75E8     		jne	L923
 5063 2ea5 8B530C   		movl	12(%ebx), %edx
 5064 2ea8 42       		incl	%edx
 5065 2ea9 89530C   		movl	%edx, 12(%ebx)
 5066 2eac 81FAFFFF 		cmpl	$2147483647, %edx
 5066      FF7F
 5067 2eb2 740F     		je	L942
 5068              	L934:
 5069 2eb4 895D08   		movl	%ebx, 8(%ebp)
 5070 2eb7 8D65F4   		leal	-12(%ebp), %esp
 5071 2eba 5B       		popl	%ebx
 5072 2ebb 5E       		popl	%esi
 5073 2ebc 5F       		popl	%edi
 5074 2ebd 5D       		popl	%ebp
 5075 2ebe E94DF3FF 		jmp	_pthread_mutex_unlock
 5075      FF
 5076              	L942:
 5077 2ec3 83EC0C   		subl	$12, %esp
 5078 2ec6 8D7304   		leal	4(%ebx), %esi
 5079 2ec9 56       		pushl	%esi
 5080 2eca E8C1EFFF 		call	_pthread_mutex_lock
 5080      FF
 5081 2ecf 83C410   		addl	$16, %esp
 5082 2ed2 89C7     		movl	%eax, %edi
 5083 2ed4 85C0     		testl	%eax, %eax
 5084 2ed6 7524     		jne	L939
 5085 2ed8 8B4B0C   		movl	12(%ebx), %ecx
 5086 2edb 8B4314   		movl	20(%ebx), %eax
 5087 2ede 83EC0C   		subl	$12, %esp
 5088 2ee1 29C1     		subl	%eax, %ecx
 5089 2ee3 894B0C   		movl	%ecx, 12(%ebx)
 5090 2ee6 C7431400 		movl	$0, 20(%ebx)
 5090      000000
 5091 2eed 56       		pushl	%esi
 5092 2eee E81DF3FF 		call	_pthread_mutex_unlock
 5092      FF
 5093 2ef3 83C410   		addl	$16, %esp
 5094 2ef6 89C7     		movl	%eax, %edi
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 108


 5095 2ef8 85C0     		testl	%eax, %eax
 5096 2efa 74B8     		je	L934
 5097              	L939:
 5098 2efc 83EC0C   		subl	$12, %esp
 5099 2eff 53       		pushl	%ebx
 5100 2f00 E80BF3FF 		call	_pthread_mutex_unlock
 5100      FF
 5101 2f05 89F8     		movl	%edi, %eax
 5102 2f07 EB84     		jmp	L923
 5103 2f09 8DB42600 		.p2align 4,,7
 5103      000000
 5104              	L941:
 5105 2f10 83EC0C   		subl	$12, %esp
 5106 2f13 31DB     		xorl	%ebx, %ebx
 5107 2f15 68000000 		pushl	$_ptw32_rwlock_test_init_lock
 5107      00
 5108 2f1a E8000000 		call	_EnterCriticalSection@4
 5108      00
 5109 2f1f 8B06     		movl	(%esi), %eax
 5110 2f21 83C40C   		addl	$12, %esp
 5111 2f24 83F8FF   		cmpl	$-1, %eax
 5112 2f27 742F     		je	L943
 5113 2f29 85C0     		testl	%eax, %eax
 5114 2f2b 7505     		jne	L928
 5115 2f2d BB160000 		movl	$22, %ebx
 5115      00
 5116              	L928:
 5117 2f32 83EC0C   		subl	$12, %esp
 5118 2f35 68000000 		pushl	$_ptw32_rwlock_test_init_lock
 5118      00
 5119 2f3a E8000000 		call	_LeaveCriticalSection@4
 5119      00
 5120 2f3f 83C40C   		addl	$12, %esp
 5121 2f42 85DB     		testl	%ebx, %ebx
 5122 2f44 740B     		je	L938
 5123 2f46 89D8     		movl	%ebx, %eax
 5124 2f48 83FB10   		cmpl	$16, %ebx
 5125 2f4b 0F853CFF 		jne	L923
 5125      FFFF
 5126              	L938:
 5127 2f51 8B1E     		movl	(%esi), %ebx
 5128 2f53 E927FFFF 		jmp	L926
 5128      FF
 5129              	L943:
 5130 2f58 51       		pushl	%ecx
 5131 2f59 51       		pushl	%ecx
 5132 2f5a 6A00     		pushl	$0
 5133 2f5c 56       		pushl	%esi
 5134 2f5d E8CEFBFF 		call	_pthread_rwlock_init
 5134      FF
 5135 2f62 83C410   		addl	$16, %esp
 5136 2f65 89C3     		movl	%eax, %ebx
 5137 2f67 EBC9     		jmp	L928
 5138 2f69 8DB42600 		.p2align 4,,15
 5138      000000
 5139              	.globl _pthread_rwlock_timedrdlock
 5140              		.def	_pthread_rwlock_timedrdlock;	.scl	2;	.type	32;	.endef
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 109


 5141              	_pthread_rwlock_timedrdlock:
 5142 2f70 55       		pushl	%ebp
 5143 2f71 89E5     		movl	%esp, %ebp
 5144 2f73 57       		pushl	%edi
 5145 2f74 56       		pushl	%esi
 5146 2f75 53       		pushl	%ebx
 5147 2f76 83EC0C   		subl	$12, %esp
 5148 2f79 8B7508   		movl	8(%ebp), %esi
 5149 2f7c 8B550C   		movl	12(%ebp), %edx
 5150 2f7f 8955F0   		movl	%edx, -16(%ebp)
 5151 2f82 85F6     		testl	%esi, %esi
 5152 2f84 7418     		je	L962
 5153 2f86 8B1E     		movl	(%esi), %ebx
 5154 2f88 85DB     		testl	%ebx, %ebx
 5155 2f8a 7412     		je	L962
 5156 2f8c 83FBFF   		cmpl	$-1, %ebx
 5157 2f8f 0F84A200 		je	L963
 5157      0000
 5158              	L947:
 5159 2f95 817B18E2 		cmpl	$262974946, 24(%ebx)
 5159      ADAC0F
 5160 2f9c 740D     		je	L953
 5161              	L962:
 5162 2f9e B8160000 		movl	$22, %eax
 5162      00
 5163              	L944:
 5164 2fa3 8D65F4   		leal	-12(%ebp), %esp
 5165 2fa6 5B       		popl	%ebx
 5166 2fa7 5E       		popl	%esi
 5167 2fa8 5F       		popl	%edi
 5168 2fa9 5D       		popl	%ebp
 5169 2faa C3       		ret
 5170              	L953:
 5171 2fab 50       		pushl	%eax
 5172 2fac 50       		pushl	%eax
 5173 2fad 8B55F0   		movl	-16(%ebp), %edx
 5174 2fb0 52       		pushl	%edx
 5175 2fb1 53       		pushl	%ebx
 5176 2fb2 E8A9F0FF 		call	_pthread_mutex_timedlock
 5176      FF
 5177 2fb7 83C410   		addl	$16, %esp
 5178 2fba 85C0     		testl	%eax, %eax
 5179 2fbc 75E5     		jne	L944
 5180 2fbe 8B4B0C   		movl	12(%ebx), %ecx
 5181 2fc1 41       		incl	%ecx
 5182 2fc2 894B0C   		movl	%ecx, 12(%ebx)
 5183 2fc5 81F9FFFF 		cmpl	$2147483647, %ecx
 5183      FF7F
 5184 2fcb 740F     		je	L964
 5185              	L955:
 5186 2fcd 895D08   		movl	%ebx, 8(%ebp)
 5187 2fd0 8D65F4   		leal	-12(%ebp), %esp
 5188 2fd3 5B       		popl	%ebx
 5189 2fd4 5E       		popl	%esi
 5190 2fd5 5F       		popl	%edi
 5191 2fd6 5D       		popl	%ebp
 5192 2fd7 E934F2FF 		jmp	_pthread_mutex_unlock
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 110


 5192      FF
 5193              	L964:
 5194 2fdc 50       		pushl	%eax
 5195 2fdd 50       		pushl	%eax
 5196 2fde 8B75F0   		movl	-16(%ebp), %esi
 5197 2fe1 56       		pushl	%esi
 5198 2fe2 8D7304   		leal	4(%ebx), %esi
 5199 2fe5 56       		pushl	%esi
 5200 2fe6 E875F0FF 		call	_pthread_mutex_timedlock
 5200      FF
 5201 2feb 83C410   		addl	$16, %esp
 5202 2fee 89C7     		movl	%eax, %edi
 5203 2ff0 85C0     		testl	%eax, %eax
 5204 2ff2 741D     		je	L956
 5205 2ff4 3D4C2700 		cmpl	$10060, %eax
 5205      00
 5206 2ff9 740D     		je	L965
 5207              	L961:
 5208 2ffb 83EC0C   		subl	$12, %esp
 5209 2ffe 53       		pushl	%ebx
 5210 2fff E80CF2FF 		call	_pthread_mutex_unlock
 5210      FF
 5211 3004 89F8     		movl	%edi, %eax
 5212 3006 EB9B     		jmp	L944
 5213              	L965:
 5214 3008 8B5314   		movl	20(%ebx), %edx
 5215 300b 42       		incl	%edx
 5216 300c 895314   		movl	%edx, 20(%ebx)
 5217 300f EBEA     		jmp	L961
 5218              	L956:
 5219 3011 8B4B0C   		movl	12(%ebx), %ecx
 5220 3014 8B4314   		movl	20(%ebx), %eax
 5221 3017 83EC0C   		subl	$12, %esp
 5222 301a 29C1     		subl	%eax, %ecx
 5223 301c 894B0C   		movl	%ecx, 12(%ebx)
 5224 301f C7431400 		movl	$0, 20(%ebx)
 5224      000000
 5225 3026 56       		pushl	%esi
 5226 3027 E8E4F1FF 		call	_pthread_mutex_unlock
 5226      FF
 5227 302c 83C410   		addl	$16, %esp
 5228 302f 89C7     		movl	%eax, %edi
 5229 3031 85C0     		testl	%eax, %eax
 5230 3033 7498     		je	L955
 5231 3035 EBC4     		jmp	L961
 5232              		.p2align 4,,7
 5233              	L963:
 5234 3037 83EC0C   		subl	$12, %esp
 5235 303a 31DB     		xorl	%ebx, %ebx
 5236 303c 68000000 		pushl	$_ptw32_rwlock_test_init_lock
 5236      00
 5237 3041 E8000000 		call	_EnterCriticalSection@4
 5237      00
 5238 3046 8B06     		movl	(%esi), %eax
 5239 3048 83C40C   		addl	$12, %esp
 5240 304b 83F8FF   		cmpl	$-1, %eax
 5241 304e 742F     		je	L966
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 111


 5242 3050 85C0     		testl	%eax, %eax
 5243 3052 7505     		jne	L949
 5244 3054 BB160000 		movl	$22, %ebx
 5244      00
 5245              	L949:
 5246 3059 83EC0C   		subl	$12, %esp
 5247 305c 68000000 		pushl	$_ptw32_rwlock_test_init_lock
 5247      00
 5248 3061 E8000000 		call	_LeaveCriticalSection@4
 5248      00
 5249 3066 83C40C   		addl	$12, %esp
 5250 3069 85DB     		testl	%ebx, %ebx
 5251 306b 740B     		je	L960
 5252 306d 89D8     		movl	%ebx, %eax
 5253 306f 83FB10   		cmpl	$16, %ebx
 5254 3072 0F852BFF 		jne	L944
 5254      FFFF
 5255              	L960:
 5256 3078 8B1E     		movl	(%esi), %ebx
 5257 307a E916FFFF 		jmp	L947
 5257      FF
 5258              	L966:
 5259 307f 50       		pushl	%eax
 5260 3080 50       		pushl	%eax
 5261 3081 6A00     		pushl	$0
 5262 3083 56       		pushl	%esi
 5263 3084 E8A7FAFF 		call	_pthread_rwlock_init
 5263      FF
 5264 3089 83C410   		addl	$16, %esp
 5265 308c 89C3     		movl	%eax, %ebx
 5266 308e EBC9     		jmp	L949
 5267              		.p2align 4,,15
 5268              	.globl _pthread_rwlock_wrlock
 5269              		.def	_pthread_rwlock_wrlock;	.scl	2;	.type	32;	.endef
 5270              	_pthread_rwlock_wrlock:
 5271 3090 55       		pushl	%ebp
 5272 3091 89E5     		movl	%esp, %ebp
 5273 3093 57       		pushl	%edi
 5274 3094 56       		pushl	%esi
 5275 3095 53       		pushl	%ebx
 5276 3096 83EC2C   		subl	$44, %esp
 5277 3099 8B7508   		movl	8(%ebp), %esi
 5278 309c 85F6     		testl	%esi, %esi
 5279 309e 7418     		je	L991
 5280 30a0 8B1E     		movl	(%esi), %ebx
 5281 30a2 85DB     		testl	%ebx, %ebx
 5282 30a4 7412     		je	L991
 5283 30a6 83FBFF   		cmpl	$-1, %ebx
 5284 30a9 0F84E100 		je	L992
 5284      0000
 5285              	L970:
 5286 30af 817B18E2 		cmpl	$262974946, 24(%ebx)
 5286      ADAC0F
 5287 30b6 740D     		je	L976
 5288              	L991:
 5289 30b8 B8160000 		movl	$22, %eax
 5289      00
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 112


 5290              	L967:
 5291 30bd 8D65F4   		leal	-12(%ebp), %esp
 5292 30c0 5B       		popl	%ebx
 5293 30c1 5E       		popl	%esi
 5294 30c2 5F       		popl	%edi
 5295 30c3 5D       		popl	%ebp
 5296 30c4 C3       		ret
 5297              	L976:
 5298 30c5 83EC0C   		subl	$12, %esp
 5299 30c8 53       		pushl	%ebx
 5300 30c9 E8C2EDFF 		call	_pthread_mutex_lock
 5300      FF
 5301 30ce 83C410   		addl	$16, %esp
 5302 30d1 85C0     		testl	%eax, %eax
 5303 30d3 75E8     		jne	L967
 5304 30d5 83EC0C   		subl	$12, %esp
 5305 30d8 8D5304   		leal	4(%ebx), %edx
 5306 30db 8955D4   		movl	%edx, -44(%ebp)
 5307 30de 52       		pushl	%edx
 5308 30df E8ACEDFF 		call	_pthread_mutex_lock
 5308      FF
 5309 30e4 83C410   		addl	$16, %esp
 5310 30e7 89C7     		movl	%eax, %edi
 5311 30e9 85C0     		testl	%eax, %eax
 5312 30eb 0F858F00 		jne	L993
 5312      0000
 5313 30f1 8B4310   		movl	16(%ebx), %eax
 5314 30f4 85C0     		testl	%eax, %eax
 5315 30f6 7576     		jne	L979
 5316 30f8 8B4314   		movl	20(%ebx), %eax
 5317 30fb 85C0     		testl	%eax, %eax
 5318 30fd 7E0F     		jle	L980
 5319 30ff 8B4B0C   		movl	12(%ebx), %ecx
 5320 3102 29C1     		subl	%eax, %ecx
 5321 3104 894B0C   		movl	%ecx, 12(%ebx)
 5322 3107 C7431400 		movl	$0, 20(%ebx)
 5322      000000
 5323              	L980:
 5324 310e 8B430C   		movl	12(%ebx), %eax
 5325 3111 85C0     		testl	%eax, %eax
 5326 3113 7E59     		jle	L979
 5327 3115 F7D8     		negl	%eax
 5328 3117 894314   		movl	%eax, 20(%ebx)
 5329 311a 8D55D8   		leal	-40(%ebp), %edx
 5330 311d 8D7308   		leal	8(%ebx), %esi
 5331 3120 50       		pushl	%eax
 5332 3121 53       		pushl	%ebx
 5333 3122 68605200 		pushl	$_ptw32_rwlock_cancelwrwait
 5333      00
 5334 3127 52       		pushl	%edx
 5335 3128 E8E3DCFF 		call	_ptw32_push_cleanup
 5335      FF
 5336 312d 83C410   		addl	$16, %esp
 5337              	L982:
 5338 3130 50       		pushl	%eax
 5339 3131 50       		pushl	%eax
 5340 3132 8B45D4   		movl	-44(%ebp), %eax
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 113


 5341 3135 50       		pushl	%eax
 5342 3136 56       		pushl	%esi
 5343 3137 E824E1FF 		call	_pthread_cond_wait
 5343      FF
 5344 313c 83C410   		addl	$16, %esp
 5345 313f 89C7     		movl	%eax, %edi
 5346 3141 85C0     		testl	%eax, %eax
 5347 3143 7507     		jne	L983
 5348 3145 8B5314   		movl	20(%ebx), %edx
 5349 3148 85D2     		testl	%edx, %edx
 5350 314a 78E4     		js	L982
 5351              	L983:
 5352 314c 83EC0C   		subl	$12, %esp
 5353 314f 85FF     		testl	%edi, %edi
 5354 3151 0F95C1   		setne	%cl
 5355 3154 81E1FF00 		andl	$255, %ecx
 5355      0000
 5356 315a 51       		pushl	%ecx
 5357 315b E850DCFF 		call	_ptw32_pop_cleanup
 5357      FF
 5358 3160 83C410   		addl	$16, %esp
 5359 3163 85FF     		testl	%edi, %edi
 5360 3165 7512     		jne	L988
 5361 3167 C7430C00 		movl	$0, 12(%ebx)
 5361      000000
 5362              	L979:
 5363 316e 85FF     		testl	%edi, %edi
 5364 3170 7507     		jne	L988
 5365 3172 8B7310   		movl	16(%ebx), %esi
 5366 3175 46       		incl	%esi
 5367 3176 897310   		movl	%esi, 16(%ebx)
 5368              	L988:
 5369 3179 89F8     		movl	%edi, %eax
 5370 317b E93DFFFF 		jmp	L967
 5370      FF
 5371              	L993:
 5372 3180 83EC0C   		subl	$12, %esp
 5373 3183 53       		pushl	%ebx
 5374 3184 E887F0FF 		call	_pthread_mutex_unlock
 5374      FF
 5375 3189 EBEE     		jmp	L988
 5376 318b 908D7426 		.p2align 4,,7
 5376      00
 5377              	L992:
 5378 3190 83EC0C   		subl	$12, %esp
 5379 3193 31DB     		xorl	%ebx, %ebx
 5380 3195 68000000 		pushl	$_ptw32_rwlock_test_init_lock
 5380      00
 5381 319a E8000000 		call	_EnterCriticalSection@4
 5381      00
 5382 319f 8B06     		movl	(%esi), %eax
 5383 31a1 83C40C   		addl	$12, %esp
 5384 31a4 83F8FF   		cmpl	$-1, %eax
 5385 31a7 742F     		je	L994
 5386 31a9 85C0     		testl	%eax, %eax
 5387 31ab 7505     		jne	L972
 5388 31ad BB160000 		movl	$22, %ebx
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 114


 5388      00
 5389              	L972:
 5390 31b2 83EC0C   		subl	$12, %esp
 5391 31b5 68000000 		pushl	$_ptw32_rwlock_test_init_lock
 5391      00
 5392 31ba E8000000 		call	_LeaveCriticalSection@4
 5392      00
 5393 31bf 83C40C   		addl	$12, %esp
 5394 31c2 85DB     		testl	%ebx, %ebx
 5395 31c4 740B     		je	L990
 5396 31c6 89D8     		movl	%ebx, %eax
 5397 31c8 83FB10   		cmpl	$16, %ebx
 5398 31cb 0F85ECFE 		jne	L967
 5398      FFFF
 5399              	L990:
 5400 31d1 8B1E     		movl	(%esi), %ebx
 5401 31d3 E9D7FEFF 		jmp	L970
 5401      FF
 5402              	L994:
 5403 31d8 53       		pushl	%ebx
 5404 31d9 53       		pushl	%ebx
 5405 31da 6A00     		pushl	$0
 5406 31dc 56       		pushl	%esi
 5407 31dd E84EF9FF 		call	_pthread_rwlock_init
 5407      FF
 5408 31e2 83C410   		addl	$16, %esp
 5409 31e5 89C3     		movl	%eax, %ebx
 5410 31e7 EBC9     		jmp	L972
 5411 31e9 8DB42600 		.p2align 4,,15
 5411      000000
 5412              	.globl _pthread_rwlock_timedwrlock
 5413              		.def	_pthread_rwlock_timedwrlock;	.scl	2;	.type	32;	.endef
 5414              	_pthread_rwlock_timedwrlock:
 5415 31f0 55       		pushl	%ebp
 5416 31f1 89E5     		movl	%esp, %ebp
 5417 31f3 57       		pushl	%edi
 5418 31f4 56       		pushl	%esi
 5419 31f5 53       		pushl	%ebx
 5420 31f6 83EC2C   		subl	$44, %esp
 5421 31f9 8B7508   		movl	8(%ebp), %esi
 5422 31fc 85F6     		testl	%esi, %esi
 5423 31fe 7418     		je	L1019
 5424 3200 8B1E     		movl	(%esi), %ebx
 5425 3202 85DB     		testl	%ebx, %ebx
 5426 3204 7412     		je	L1019
 5427 3206 83FBFF   		cmpl	$-1, %ebx
 5428 3209 0F84E500 		je	L1020
 5428      0000
 5429              	L998:
 5430 320f 817B18E2 		cmpl	$262974946, 24(%ebx)
 5430      ADAC0F
 5431 3216 740D     		je	L1004
 5432              	L1019:
 5433 3218 B8160000 		movl	$22, %eax
 5433      00
 5434              	L995:
 5435 321d 8D65F4   		leal	-12(%ebp), %esp
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 115


 5436 3220 5B       		popl	%ebx
 5437 3221 5E       		popl	%esi
 5438 3222 5F       		popl	%edi
 5439 3223 5D       		popl	%ebp
 5440 3224 C3       		ret
 5441              	L1004:
 5442 3225 8B550C   		movl	12(%ebp), %edx
 5443 3228 50       		pushl	%eax
 5444 3229 50       		pushl	%eax
 5445 322a 52       		pushl	%edx
 5446 322b 53       		pushl	%ebx
 5447 322c E82FEEFF 		call	_pthread_mutex_timedlock
 5447      FF
 5448 3231 83C410   		addl	$16, %esp
 5449 3234 85C0     		testl	%eax, %eax
 5450 3236 75E5     		jne	L995
 5451 3238 8B450C   		movl	12(%ebp), %eax
 5452 323b 57       		pushl	%edi
 5453 323c 8D5304   		leal	4(%ebx), %edx
 5454 323f 57       		pushl	%edi
 5455 3240 8955D4   		movl	%edx, -44(%ebp)
 5456 3243 50       		pushl	%eax
 5457 3244 52       		pushl	%edx
 5458 3245 E816EEFF 		call	_pthread_mutex_timedlock
 5458      FF
 5459 324a 83C410   		addl	$16, %esp
 5460 324d 89C7     		movl	%eax, %edi
 5461 324f 85C0     		testl	%eax, %eax
 5462 3251 0F859200 		jne	L1021
 5462      0000
 5463 3257 8B7310   		movl	16(%ebx), %esi
 5464 325a 85F6     		testl	%esi, %esi
 5465 325c 7579     		jne	L1007
 5466 325e 8B4314   		movl	20(%ebx), %eax
 5467 3261 85C0     		testl	%eax, %eax
 5468 3263 7E0F     		jle	L1008
 5469 3265 8B4B0C   		movl	12(%ebx), %ecx
 5470 3268 29C1     		subl	%eax, %ecx
 5471 326a 894B0C   		movl	%ecx, 12(%ebx)
 5472 326d C7431400 		movl	$0, 20(%ebx)
 5472      000000
 5473              	L1008:
 5474 3274 8B430C   		movl	12(%ebx), %eax
 5475 3277 85C0     		testl	%eax, %eax
 5476 3279 7E5C     		jle	L1007
 5477 327b F7D8     		negl	%eax
 5478 327d 894314   		movl	%eax, 20(%ebx)
 5479 3280 8D7DD8   		leal	-40(%ebp), %edi
 5480 3283 8D7308   		leal	8(%ebx), %esi
 5481 3286 50       		pushl	%eax
 5482 3287 53       		pushl	%ebx
 5483 3288 68605200 		pushl	$_ptw32_rwlock_cancelwrwait
 5483      00
 5484 328d 57       		pushl	%edi
 5485 328e E87DDBFF 		call	_ptw32_push_cleanup
 5485      FF
 5486 3293 83C410   		addl	$16, %esp
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 116


 5487              	L1010:
 5488 3296 8B4D0C   		movl	12(%ebp), %ecx
 5489 3299 50       		pushl	%eax
 5490 329a 8B55D4   		movl	-44(%ebp), %edx
 5491 329d 51       		pushl	%ecx
 5492 329e 52       		pushl	%edx
 5493 329f 56       		pushl	%esi
 5494 32a0 E8DBDFFF 		call	_pthread_cond_timedwait
 5494      FF
 5495 32a5 83C410   		addl	$16, %esp
 5496 32a8 89C7     		movl	%eax, %edi
 5497 32aa 85C0     		testl	%eax, %eax
 5498 32ac 7507     		jne	L1011
 5499 32ae 8B5314   		movl	20(%ebx), %edx
 5500 32b1 85D2     		testl	%edx, %edx
 5501 32b3 78E1     		js	L1010
 5502              	L1011:
 5503 32b5 83EC0C   		subl	$12, %esp
 5504 32b8 85FF     		testl	%edi, %edi
 5505 32ba 0F95C1   		setne	%cl
 5506 32bd 81E1FF00 		andl	$255, %ecx
 5506      0000
 5507 32c3 51       		pushl	%ecx
 5508 32c4 E8E7DAFF 		call	_ptw32_pop_cleanup
 5508      FF
 5509 32c9 83C410   		addl	$16, %esp
 5510 32cc 85FF     		testl	%edi, %edi
 5511 32ce 7512     		jne	L1016
 5512 32d0 C7430C00 		movl	$0, 12(%ebx)
 5512      000000
 5513              	L1007:
 5514 32d7 85FF     		testl	%edi, %edi
 5515 32d9 7507     		jne	L1016
 5516 32db 8B4310   		movl	16(%ebx), %eax
 5517 32de 40       		incl	%eax
 5518 32df 894310   		movl	%eax, 16(%ebx)
 5519              	L1016:
 5520 32e2 89F8     		movl	%edi, %eax
 5521 32e4 E934FFFF 		jmp	L995
 5521      FF
 5522              	L1021:
 5523 32e9 83EC0C   		subl	$12, %esp
 5524 32ec 53       		pushl	%ebx
 5525 32ed E81EEFFF 		call	_pthread_mutex_unlock
 5525      FF
 5526 32f2 EBEE     		jmp	L1016
 5527              		.p2align 4,,7
 5528              	L1020:
 5529 32f4 83EC0C   		subl	$12, %esp
 5530 32f7 31DB     		xorl	%ebx, %ebx
 5531 32f9 68000000 		pushl	$_ptw32_rwlock_test_init_lock
 5531      00
 5532 32fe E8000000 		call	_EnterCriticalSection@4
 5532      00
 5533 3303 8B06     		movl	(%esi), %eax
 5534 3305 83C40C   		addl	$12, %esp
 5535 3308 83F8FF   		cmpl	$-1, %eax
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 117


 5536 330b 742F     		je	L1022
 5537 330d 85C0     		testl	%eax, %eax
 5538 330f 7505     		jne	L1000
 5539 3311 BB160000 		movl	$22, %ebx
 5539      00
 5540              	L1000:
 5541 3316 83EC0C   		subl	$12, %esp
 5542 3319 68000000 		pushl	$_ptw32_rwlock_test_init_lock
 5542      00
 5543 331e E8000000 		call	_LeaveCriticalSection@4
 5543      00
 5544 3323 83C40C   		addl	$12, %esp
 5545 3326 85DB     		testl	%ebx, %ebx
 5546 3328 740B     		je	L1018
 5547 332a 89D8     		movl	%ebx, %eax
 5548 332c 83FB10   		cmpl	$16, %ebx
 5549 332f 0F85E8FE 		jne	L995
 5549      FFFF
 5550              	L1018:
 5551 3335 8B1E     		movl	(%esi), %ebx
 5552 3337 E9D3FEFF 		jmp	L998
 5552      FF
 5553              	L1022:
 5554 333c 50       		pushl	%eax
 5555 333d 50       		pushl	%eax
 5556 333e 6A00     		pushl	$0
 5557 3340 56       		pushl	%esi
 5558 3341 E8EAF7FF 		call	_pthread_rwlock_init
 5558      FF
 5559 3346 83C410   		addl	$16, %esp
 5560 3349 89C3     		movl	%eax, %ebx
 5561 334b EBC9     		jmp	L1000
 5562 334d 8D7600   		.p2align 4,,15
 5563              	.globl _pthread_rwlock_unlock
 5564              		.def	_pthread_rwlock_unlock;	.scl	2;	.type	32;	.endef
 5565              	_pthread_rwlock_unlock:
 5566 3350 55       		pushl	%ebp
 5567 3351 89E5     		movl	%esp, %ebp
 5568 3353 57       		pushl	%edi
 5569 3354 56       		pushl	%esi
 5570 3355 53       		pushl	%ebx
 5571 3356 83EC0C   		subl	$12, %esp
 5572 3359 8B4508   		movl	8(%ebp), %eax
 5573 335c 85C0     		testl	%eax, %eax
 5574 335e 7416     		je	L1034
 5575 3360 8B18     		movl	(%eax), %ebx
 5576 3362 85DB     		testl	%ebx, %ebx
 5577 3364 7410     		je	L1034
 5578 3366 31C0     		xorl	%eax, %eax
 5579 3368 83FBFF   		cmpl	$-1, %ebx
 5580 336b 740E     		je	L1023
 5581 336d 817B18E2 		cmpl	$262974946, 24(%ebx)
 5581      ADAC0F
 5582 3374 740D     		je	L1027
 5583              	L1034:
 5584 3376 B8160000 		movl	$22, %eax
 5584      00
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 118


 5585              	L1023:
 5586 337b 8D65F4   		leal	-12(%ebp), %esp
 5587 337e 5B       		popl	%ebx
 5588 337f 5E       		popl	%esi
 5589 3380 5F       		popl	%edi
 5590 3381 5D       		popl	%ebp
 5591 3382 C3       		ret
 5592              	L1027:
 5593 3383 8B4310   		movl	16(%ebx), %eax
 5594 3386 85C0     		testl	%eax, %eax
 5595 3388 754B     		jne	L1028
 5596 338a 83EC0C   		subl	$12, %esp
 5597 338d 8D7B04   		leal	4(%ebx), %edi
 5598 3390 57       		pushl	%edi
 5599 3391 E8FAEAFF 		call	_pthread_mutex_lock
 5599      FF
 5600 3396 83C410   		addl	$16, %esp
 5601 3399 89C6     		movl	%eax, %esi
 5602 339b 85C0     		testl	%eax, %eax
 5603 339d 75DC     		jne	L1023
 5604 339f 8B5314   		movl	20(%ebx), %edx
 5605 33a2 42       		incl	%edx
 5606 33a3 895314   		movl	%edx, 20(%ebx)
 5607 33a6 85D2     		testl	%edx, %edx
 5608 33a8 7418     		je	L1035
 5609              	L1030:
 5610 33aa 83EC0C   		subl	$12, %esp
 5611 33ad 57       		pushl	%edi
 5612              	L1033:
 5613 33ae E85DEEFF 		call	_pthread_mutex_unlock
 5613      FF
 5614 33b3 83C410   		addl	$16, %esp
 5615 33b6 89C2     		movl	%eax, %edx
 5616 33b8 85F6     		testl	%esi, %esi
 5617 33ba 89F0     		movl	%esi, %eax
 5618 33bc 75BD     		jne	L1023
 5619 33be 89D0     		movl	%edx, %eax
 5620 33c0 EBB9     		jmp	L1023
 5621              	L1035:
 5622 33c2 83EC0C   		subl	$12, %esp
 5623 33c5 8D5308   		leal	8(%ebx), %edx
 5624 33c8 52       		pushl	%edx
 5625 33c9 E8D2DEFF 		call	_pthread_cond_signal
 5625      FF
 5626 33ce 83C410   		addl	$16, %esp
 5627 33d1 89C6     		movl	%eax, %esi
 5628 33d3 EBD5     		jmp	L1030
 5629              	L1028:
 5630 33d5 83EC0C   		subl	$12, %esp
 5631 33d8 48       		decl	%eax
 5632 33d9 8D4B04   		leal	4(%ebx), %ecx
 5633 33dc 894310   		movl	%eax, 16(%ebx)
 5634 33df 51       		pushl	%ecx
 5635 33e0 E82BEEFF 		call	_pthread_mutex_unlock
 5635      FF
 5636 33e5 891C24   		movl	%ebx, (%esp)
 5637 33e8 89C6     		movl	%eax, %esi
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 119


 5638 33ea EBC2     		jmp	L1033
 5639 33ec 8D742600 		.p2align 4,,15
 5640              	.globl _pthread_rwlock_tryrdlock
 5641              		.def	_pthread_rwlock_tryrdlock;	.scl	2;	.type	32;	.endef
 5642              	_pthread_rwlock_tryrdlock:
 5643 33f0 55       		pushl	%ebp
 5644 33f1 89E5     		movl	%esp, %ebp
 5645 33f3 57       		pushl	%edi
 5646 33f4 56       		pushl	%esi
 5647 33f5 53       		pushl	%ebx
 5648 33f6 83EC0C   		subl	$12, %esp
 5649 33f9 8B7508   		movl	8(%ebp), %esi
 5650 33fc 85F6     		testl	%esi, %esi
 5651 33fe 7418     		je	L1053
 5652 3400 8B1E     		movl	(%esi), %ebx
 5653 3402 85DB     		testl	%ebx, %ebx
 5654 3404 7412     		je	L1053
 5655 3406 83FBFF   		cmpl	$-1, %ebx
 5656 3409 0F849100 		je	L1054
 5656      0000
 5657              	L1039:
 5658 340f 817B18E2 		cmpl	$262974946, 24(%ebx)
 5658      ADAC0F
 5659 3416 740D     		je	L1045
 5660              	L1053:
 5661 3418 B8160000 		movl	$22, %eax
 5661      00
 5662              	L1036:
 5663 341d 8D65F4   		leal	-12(%ebp), %esp
 5664 3420 5B       		popl	%ebx
 5665 3421 5E       		popl	%esi
 5666 3422 5F       		popl	%edi
 5667 3423 5D       		popl	%ebp
 5668 3424 C3       		ret
 5669              	L1045:
 5670 3425 83EC0C   		subl	$12, %esp
 5671 3428 53       		pushl	%ebx
 5672 3429 E8B2EEFF 		call	_pthread_mutex_trylock
 5672      FF
 5673 342e 83C410   		addl	$16, %esp
 5674 3431 85C0     		testl	%eax, %eax
 5675 3433 75E8     		jne	L1036
 5676 3435 8B530C   		movl	12(%ebx), %edx
 5677 3438 42       		incl	%edx
 5678 3439 89530C   		movl	%edx, 12(%ebx)
 5679 343c 81FAFFFF 		cmpl	$2147483647, %edx
 5679      FF7F
 5680 3442 740F     		je	L1055
 5681              	L1047:
 5682 3444 895D08   		movl	%ebx, 8(%ebp)
 5683 3447 8D65F4   		leal	-12(%ebp), %esp
 5684 344a 5B       		popl	%ebx
 5685 344b 5E       		popl	%esi
 5686 344c 5F       		popl	%edi
 5687 344d 5D       		popl	%ebp
 5688 344e E9BDEDFF 		jmp	_pthread_mutex_unlock
 5688      FF
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 120


 5689              	L1055:
 5690 3453 83EC0C   		subl	$12, %esp
 5691 3456 8D7304   		leal	4(%ebx), %esi
 5692 3459 56       		pushl	%esi
 5693 345a E831EAFF 		call	_pthread_mutex_lock
 5693      FF
 5694 345f 83C410   		addl	$16, %esp
 5695 3462 89C7     		movl	%eax, %edi
 5696 3464 85C0     		testl	%eax, %eax
 5697 3466 7524     		jne	L1052
 5698 3468 8B4B0C   		movl	12(%ebx), %ecx
 5699 346b 8B4314   		movl	20(%ebx), %eax
 5700 346e 83EC0C   		subl	$12, %esp
 5701 3471 29C1     		subl	%eax, %ecx
 5702 3473 894B0C   		movl	%ecx, 12(%ebx)
 5703 3476 C7431400 		movl	$0, 20(%ebx)
 5703      000000
 5704 347d 56       		pushl	%esi
 5705 347e E88DEDFF 		call	_pthread_mutex_unlock
 5705      FF
 5706 3483 83C410   		addl	$16, %esp
 5707 3486 89C7     		movl	%eax, %edi
 5708 3488 85C0     		testl	%eax, %eax
 5709 348a 74B8     		je	L1047
 5710              	L1052:
 5711 348c 83EC0C   		subl	$12, %esp
 5712 348f 53       		pushl	%ebx
 5713 3490 E87BEDFF 		call	_pthread_mutex_unlock
 5713      FF
 5714 3495 89F8     		movl	%edi, %eax
 5715 3497 EB84     		jmp	L1036
 5716 3499 8DB42600 		.p2align 4,,7
 5716      000000
 5717              	L1054:
 5718 34a0 83EC0C   		subl	$12, %esp
 5719 34a3 31DB     		xorl	%ebx, %ebx
 5720 34a5 68000000 		pushl	$_ptw32_rwlock_test_init_lock
 5720      00
 5721 34aa E8000000 		call	_EnterCriticalSection@4
 5721      00
 5722 34af 8B06     		movl	(%esi), %eax
 5723 34b1 83C40C   		addl	$12, %esp
 5724 34b4 83F8FF   		cmpl	$-1, %eax
 5725 34b7 742F     		je	L1056
 5726 34b9 85C0     		testl	%eax, %eax
 5727 34bb 7505     		jne	L1041
 5728 34bd BB160000 		movl	$22, %ebx
 5728      00
 5729              	L1041:
 5730 34c2 83EC0C   		subl	$12, %esp
 5731 34c5 68000000 		pushl	$_ptw32_rwlock_test_init_lock
 5731      00
 5732 34ca E8000000 		call	_LeaveCriticalSection@4
 5732      00
 5733 34cf 83C40C   		addl	$12, %esp
 5734 34d2 85DB     		testl	%ebx, %ebx
 5735 34d4 740B     		je	L1051
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 121


 5736 34d6 89D8     		movl	%ebx, %eax
 5737 34d8 83FB10   		cmpl	$16, %ebx
 5738 34db 0F853CFF 		jne	L1036
 5738      FFFF
 5739              	L1051:
 5740 34e1 8B1E     		movl	(%esi), %ebx
 5741 34e3 E927FFFF 		jmp	L1039
 5741      FF
 5742              	L1056:
 5743 34e8 51       		pushl	%ecx
 5744 34e9 51       		pushl	%ecx
 5745 34ea 6A00     		pushl	$0
 5746 34ec 56       		pushl	%esi
 5747 34ed E83EF6FF 		call	_pthread_rwlock_init
 5747      FF
 5748 34f2 83C410   		addl	$16, %esp
 5749 34f5 89C3     		movl	%eax, %ebx
 5750 34f7 EBC9     		jmp	L1041
 5751 34f9 8DB42600 		.p2align 4,,15
 5751      000000
 5752              	.globl _pthread_rwlock_trywrlock
 5753              		.def	_pthread_rwlock_trywrlock;	.scl	2;	.type	32;	.endef
 5754              	_pthread_rwlock_trywrlock:
 5755 3500 55       		pushl	%ebp
 5756 3501 89E5     		movl	%esp, %ebp
 5757 3503 57       		pushl	%edi
 5758 3504 56       		pushl	%esi
 5759 3505 53       		pushl	%ebx
 5760 3506 83EC0C   		subl	$12, %esp
 5761 3509 8B7508   		movl	8(%ebp), %esi
 5762 350c 85F6     		testl	%esi, %esi
 5763 350e 7418     		je	L1079
 5764 3510 8B1E     		movl	(%esi), %ebx
 5765 3512 85DB     		testl	%ebx, %ebx
 5766 3514 7412     		je	L1079
 5767 3516 83FBFF   		cmpl	$-1, %ebx
 5768 3519 0F84B600 		je	L1080
 5768      0000
 5769              	L1060:
 5770 351f 817B18E2 		cmpl	$262974946, 24(%ebx)
 5770      ADAC0F
 5771 3526 740D     		je	L1066
 5772              	L1079:
 5773 3528 B8160000 		movl	$22, %eax
 5773      00
 5774              	L1057:
 5775 352d 8D65F4   		leal	-12(%ebp), %esp
 5776 3530 5B       		popl	%ebx
 5777 3531 5E       		popl	%esi
 5778 3532 5F       		popl	%edi
 5779 3533 5D       		popl	%ebp
 5780 3534 C3       		ret
 5781              	L1066:
 5782 3535 83EC0C   		subl	$12, %esp
 5783 3538 53       		pushl	%ebx
 5784 3539 E8A2EDFF 		call	_pthread_mutex_trylock
 5784      FF
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 122


 5785 353e 83C410   		addl	$16, %esp
 5786 3541 85C0     		testl	%eax, %eax
 5787 3543 75E8     		jne	L1057
 5788 3545 83EC0C   		subl	$12, %esp
 5789 3548 8D7304   		leal	4(%ebx), %esi
 5790 354b 56       		pushl	%esi
 5791 354c E88FEDFF 		call	_pthread_mutex_trylock
 5791      FF
 5792 3551 83C410   		addl	$16, %esp
 5793 3554 89C7     		movl	%eax, %edi
 5794 3556 85C0     		testl	%eax, %eax
 5795 3558 7565     		jne	L1081
 5796 355a 8B4310   		movl	16(%ebx), %eax
 5797 355d 85C0     		testl	%eax, %eax
 5798 355f 754E     		jne	L1070
 5799 3561 8B4314   		movl	20(%ebx), %eax
 5800 3564 85C0     		testl	%eax, %eax
 5801 3566 7E0F     		jle	L1071
 5802 3568 8B4B0C   		movl	12(%ebx), %ecx
 5803 356b 29C1     		subl	%eax, %ecx
 5804 356d 894B0C   		movl	%ecx, 12(%ebx)
 5805 3570 C7431400 		movl	$0, 20(%ebx)
 5805      000000
 5806              	L1071:
 5807 3577 8B530C   		movl	12(%ebx), %edx
 5808 357a 85D2     		testl	%edx, %edx
 5809 357c 7E38     		jle	L1072
 5810 357e 83EC0C   		subl	$12, %esp
 5811 3581 56       		pushl	%esi
 5812 3582 E889ECFF 		call	_pthread_mutex_unlock
 5812      FF
 5813 3587 83C410   		addl	$16, %esp
 5814 358a 89C7     		movl	%eax, %edi
 5815 358c 85C0     		testl	%eax, %eax
 5816 358e 740D     		je	L1073
 5817 3590 83EC0C   		subl	$12, %esp
 5818 3593 53       		pushl	%ebx
 5819 3594 E877ECFF 		call	_pthread_mutex_unlock
 5819      FF
 5820              	L1076:
 5821 3599 89F8     		movl	%edi, %eax
 5822 359b EB90     		jmp	L1057
 5823              	L1073:
 5824 359d 83EC0C   		subl	$12, %esp
 5825 35a0 53       		pushl	%ebx
 5826 35a1 E86AECFF 		call	_pthread_mutex_unlock
 5826      FF
 5827 35a6 83C410   		addl	$16, %esp
 5828 35a9 89C7     		movl	%eax, %edi
 5829 35ab 85C0     		testl	%eax, %eax
 5830 35ad 75EA     		jne	L1076
 5831              	L1070:
 5832 35af BF100000 		movl	$16, %edi
 5832      00
 5833 35b4 EBE3     		jmp	L1076
 5834              	L1072:
 5835 35b6 C7431001 		movl	$1, 16(%ebx)
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 123


 5835      000000
 5836 35bd EBDA     		jmp	L1076
 5837              	L1081:
 5838 35bf 83EC0C   		subl	$12, %esp
 5839 35c2 53       		pushl	%ebx
 5840 35c3 E848ECFF 		call	_pthread_mutex_unlock
 5840      FF
 5841 35c8 83C410   		addl	$16, %esp
 5842 35cb 85C0     		testl	%eax, %eax
 5843 35cd 0F855AFF 		jne	L1057
 5843      FFFF
 5844 35d3 EBC4     		jmp	L1076
 5845              		.p2align 4,,7
 5846              	L1080:
 5847 35d5 83EC0C   		subl	$12, %esp
 5848 35d8 31DB     		xorl	%ebx, %ebx
 5849 35da 68000000 		pushl	$_ptw32_rwlock_test_init_lock
 5849      00
 5850 35df E8000000 		call	_EnterCriticalSection@4
 5850      00
 5851 35e4 8B06     		movl	(%esi), %eax
 5852 35e6 83C40C   		addl	$12, %esp
 5853 35e9 83F8FF   		cmpl	$-1, %eax
 5854 35ec 742F     		je	L1082
 5855 35ee 85C0     		testl	%eax, %eax
 5856 35f0 7505     		jne	L1062
 5857 35f2 BB160000 		movl	$22, %ebx
 5857      00
 5858              	L1062:
 5859 35f7 83EC0C   		subl	$12, %esp
 5860 35fa 68000000 		pushl	$_ptw32_rwlock_test_init_lock
 5860      00
 5861 35ff E8000000 		call	_LeaveCriticalSection@4
 5861      00
 5862 3604 83C40C   		addl	$12, %esp
 5863 3607 85DB     		testl	%ebx, %ebx
 5864 3609 740B     		je	L1078
 5865 360b 89D8     		movl	%ebx, %eax
 5866 360d 83FB10   		cmpl	$16, %ebx
 5867 3610 0F8517FF 		jne	L1057
 5867      FFFF
 5868              	L1078:
 5869 3616 8B1E     		movl	(%esi), %ebx
 5870 3618 E902FFFF 		jmp	L1060
 5870      FF
 5871              	L1082:
 5872 361d 53       		pushl	%ebx
 5873 361e 53       		pushl	%ebx
 5874 361f 6A00     		pushl	$0
 5875 3621 56       		pushl	%esi
 5876 3622 E809F5FF 		call	_pthread_rwlock_init
 5876      FF
 5877 3627 83C410   		addl	$16, %esp
 5878 362a 89C3     		movl	%eax, %ebx
 5879 362c EBC9     		jmp	L1062
 5880 362e 89F6     		.p2align 4,,15
 5881              	.globl _pthread_attr_setschedpolicy
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 124


 5882              		.def	_pthread_attr_setschedpolicy;	.scl	2;	.type	32;	.endef
 5883              	_pthread_attr_setschedpolicy:
 5884 3630 55       		pushl	%ebp
 5885 3631 31D2     		xorl	%edx, %edx
 5886 3633 89E5     		movl	%esp, %ebp
 5887 3635 8B4508   		movl	8(%ebp), %eax
 5888 3638 85C0     		testl	%eax, %eax
 5889 363a 740E     		je	L1086
 5890 363c 8B00     		movl	(%eax), %eax
 5891 363e 85C0     		testl	%eax, %eax
 5892 3640 7408     		je	L1086
 5893 3642 8138EEFF 		cmpl	$-993984530, (%eax)
 5893      C0C4
 5894 3648 7405     		je	L1087
 5895              	L1086:
 5896 364a BA010000 		movl	$1, %edx
 5896      00
 5897              	L1087:
 5898 364f B8160000 		movl	$22, %eax
 5898      00
 5899 3654 85D2     		testl	%edx, %edx
 5900 3656 7514     		jne	L1083
 5901 3658 8B550C   		movl	12(%ebp), %edx
 5902 365b 85D2     		testl	%edx, %edx
 5903 365d 0F95C0   		setne	%al
 5904 3660 25FF0000 		andl	$255, %eax
 5904      00
 5905 3665 48       		decl	%eax
 5906 3666 83E0D0   		andl	$-48, %eax
 5907 3669 83C030   		addl	$48, %eax
 5908              	L1083:
 5909 366c 5D       		popl	%ebp
 5910 366d C3       		ret
 5911 366e 89F6     		.p2align 4,,15
 5912              	.globl _pthread_attr_getschedpolicy
 5913              		.def	_pthread_attr_getschedpolicy;	.scl	2;	.type	32;	.endef
 5914              	_pthread_attr_getschedpolicy:
 5915 3670 55       		pushl	%ebp
 5916 3671 31D2     		xorl	%edx, %edx
 5917 3673 89E5     		movl	%esp, %ebp
 5918 3675 8B4508   		movl	8(%ebp), %eax
 5919 3678 8B4D0C   		movl	12(%ebp), %ecx
 5920 367b 85C0     		testl	%eax, %eax
 5921 367d 740E     		je	L1093
 5922 367f 8B00     		movl	(%eax), %eax
 5923 3681 85C0     		testl	%eax, %eax
 5924 3683 7408     		je	L1093
 5925 3685 8138EEFF 		cmpl	$-993984530, (%eax)
 5925      C0C4
 5926 368b 7405     		je	L1094
 5927              	L1093:
 5928 368d BA010000 		movl	$1, %edx
 5928      00
 5929              	L1094:
 5930 3692 85D2     		testl	%edx, %edx
 5931 3694 751A     		jne	L1091
 5932 3696 85C9     		testl	%ecx, %ecx
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 125


 5933 3698 7416     		je	L1091
 5934 369a B8160000 		movl	$22, %eax
 5934      00
 5935 369f 83F902   		cmpl	$2, %ecx
 5936 36a2 7608     		jbe	L1089
 5937 36a4 C7010000 		movl	$0, (%ecx)
 5937      0000
 5938 36aa 31C0     		xorl	%eax, %eax
 5939              	L1089:
 5940 36ac 5D       		popl	%ebp
 5941 36ad C3       		ret
 5942 36ae 89F6     		.p2align 4,,7
 5943              	L1091:
 5944 36b0 B8160000 		movl	$22, %eax
 5944      00
 5945 36b5 EBF5     		jmp	L1089
 5946 36b7 89F68DBC 		.p2align 4,,15
 5946      27000000 
 5946      00
 5947              	.globl _pthread_attr_setschedparam
 5948              		.def	_pthread_attr_setschedparam;	.scl	2;	.type	32;	.endef
 5949              	_pthread_attr_setschedparam:
 5950 36c0 55       		pushl	%ebp
 5951 36c1 31D2     		xorl	%edx, %edx
 5952 36c3 89E5     		movl	%esp, %ebp
 5953 36c5 57       		pushl	%edi
 5954 36c6 56       		pushl	%esi
 5955 36c7 53       		pushl	%ebx
 5956 36c8 83EC0C   		subl	$12, %esp
 5957 36cb 8B5D08   		movl	8(%ebp), %ebx
 5958 36ce 8B750C   		movl	12(%ebp), %esi
 5959 36d1 85DB     		testl	%ebx, %ebx
 5960 36d3 740E     		je	L1100
 5961 36d5 8B03     		movl	(%ebx), %eax
 5962 36d7 85C0     		testl	%eax, %eax
 5963 36d9 7408     		je	L1100
 5964 36db 8138EEFF 		cmpl	$-993984530, (%eax)
 5964      C0C4
 5965 36e1 7405     		je	L1101
 5966              	L1100:
 5967 36e3 BA010000 		movl	$1, %edx
 5967      00
 5968              	L1101:
 5969 36e8 85D2     		testl	%edx, %edx
 5970 36ea 7517     		jne	L1103
 5971 36ec 85F6     		testl	%esi, %esi
 5972 36ee 7413     		je	L1103
 5973 36f0 83EC0C   		subl	$12, %esp
 5974 36f3 8B3E     		movl	(%esi), %edi
 5975 36f5 6A00     		pushl	$0
 5976 36f7 E8B40200 		call	_sched_get_priority_min
 5976      00
 5977 36fc 83C410   		addl	$16, %esp
 5978 36ff 39C7     		cmpl	%eax, %edi
 5979 3701 7D0D     		jge	L1104
 5980              	L1103:
 5981 3703 B8160000 		movl	$22, %eax
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 126


 5981      00
 5982              	L1096:
 5983 3708 8D65F4   		leal	-12(%ebp), %esp
 5984 370b 5B       		popl	%ebx
 5985 370c 5E       		popl	%esi
 5986 370d 5F       		popl	%edi
 5987 370e 5D       		popl	%ebp
 5988 370f C3       		ret
 5989              	L1104:
 5990 3710 83EC0C   		subl	$12, %esp
 5991 3713 6A00     		pushl	$0
 5992 3715 E8660200 		call	_sched_get_priority_max
 5992      00
 5993 371a 83C410   		addl	$16, %esp
 5994 371d 39C7     		cmpl	%eax, %edi
 5995 371f 7FE2     		jg	L1103
 5996 3721 8B0B     		movl	(%ebx), %ecx
 5997 3723 8B16     		movl	(%esi), %edx
 5998 3725 31C0     		xorl	%eax, %eax
 5999 3727 895110   		movl	%edx, 16(%ecx)
 6000 372a EBDC     		jmp	L1096
 6001 372c 8D742600 		.p2align 4,,15
 6002              	.globl _pthread_attr_getschedparam
 6003              		.def	_pthread_attr_getschedparam;	.scl	2;	.type	32;	.endef
 6004              	_pthread_attr_getschedparam:
 6005 3730 55       		pushl	%ebp
 6006 3731 31C9     		xorl	%ecx, %ecx
 6007 3733 89E5     		movl	%esp, %ebp
 6008 3735 53       		pushl	%ebx
 6009 3736 8B4508   		movl	8(%ebp), %eax
 6010 3739 8B5D0C   		movl	12(%ebp), %ebx
 6011 373c 85C0     		testl	%eax, %eax
 6012 373e 740E     		je	L1109
 6013 3740 8B10     		movl	(%eax), %edx
 6014 3742 85D2     		testl	%edx, %edx
 6015 3744 7408     		je	L1109
 6016 3746 813AEEFF 		cmpl	$-993984530, (%edx)
 6016      C0C4
 6017 374c 7405     		je	L1110
 6018              	L1109:
 6019 374e B9010000 		movl	$1, %ecx
 6019      00
 6020              	L1110:
 6021 3753 85C9     		testl	%ecx, %ecx
 6022 3755 7510     		jne	L1107
 6023 3757 85DB     		testl	%ebx, %ebx
 6024 3759 740C     		je	L1107
 6025 375b 8B08     		movl	(%eax), %ecx
 6026 375d 31C0     		xorl	%eax, %eax
 6027 375f 8B5110   		movl	16(%ecx), %edx
 6028 3762 8913     		movl	%edx, (%ebx)
 6029              	L1105:
 6030 3764 5B       		popl	%ebx
 6031 3765 5D       		popl	%ebp
 6032 3766 C3       		ret
 6033              		.p2align 4,,7
 6034              	L1107:
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 127


 6035 3767 B8160000 		movl	$22, %eax
 6035      00
 6036 376c EBF6     		jmp	L1105
 6037 376e 89F6     		.p2align 4,,15
 6038              	.globl _pthread_attr_setinheritsched
 6039              		.def	_pthread_attr_setinheritsched;	.scl	2;	.type	32;	.endef
 6040              	_pthread_attr_setinheritsched:
 6041 3770 55       		pushl	%ebp
 6042 3771 31C9     		xorl	%ecx, %ecx
 6043 3773 89E5     		movl	%esp, %ebp
 6044 3775 53       		pushl	%ebx
 6045 3776 8B4508   		movl	8(%ebp), %eax
 6046 3779 8B5D0C   		movl	12(%ebp), %ebx
 6047 377c 85C0     		testl	%eax, %eax
 6048 377e 740E     		je	L1114
 6049 3780 8B10     		movl	(%eax), %edx
 6050 3782 85D2     		testl	%edx, %edx
 6051 3784 7408     		je	L1114
 6052 3786 813AEEFF 		cmpl	$-993984530, (%edx)
 6052      C0C4
 6053 378c 7405     		je	L1115
 6054              	L1114:
 6055 378e B9010000 		movl	$1, %ecx
 6055      00
 6056              	L1115:
 6057 3793 BA160000 		movl	$22, %edx
 6057      00
 6058 3798 85C9     		testl	%ecx, %ecx
 6059 379a 7511     		jne	L1111
 6060 379c BA160000 		movl	$22, %edx
 6060      00
 6061 37a1 83FB01   		cmpl	$1, %ebx
 6062 37a4 7707     		ja	L1111
 6063 37a6 8B10     		movl	(%eax), %edx
 6064 37a8 895A14   		movl	%ebx, 20(%edx)
 6065 37ab 31D2     		xorl	%edx, %edx
 6066              	L1111:
 6067 37ad 5B       		popl	%ebx
 6068 37ae 89D0     		movl	%edx, %eax
 6069 37b0 5D       		popl	%ebp
 6070 37b1 C3       		ret
 6071 37b2 8DB42600 		.p2align 4,,15
 6071      0000008D 
 6071      BC270000 
 6071      0000
 6072              	.globl _pthread_attr_getinheritsched
 6073              		.def	_pthread_attr_getinheritsched;	.scl	2;	.type	32;	.endef
 6074              	_pthread_attr_getinheritsched:
 6075 37c0 55       		pushl	%ebp
 6076 37c1 31C9     		xorl	%ecx, %ecx
 6077 37c3 89E5     		movl	%esp, %ebp
 6078 37c5 53       		pushl	%ebx
 6079 37c6 8B4508   		movl	8(%ebp), %eax
 6080 37c9 8B5D0C   		movl	12(%ebp), %ebx
 6081 37cc 85C0     		testl	%eax, %eax
 6082 37ce 740E     		je	L1121
 6083 37d0 8B10     		movl	(%eax), %edx
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 128


 6084 37d2 85D2     		testl	%edx, %edx
 6085 37d4 7408     		je	L1121
 6086 37d6 813AEEFF 		cmpl	$-993984530, (%edx)
 6086      C0C4
 6087 37dc 7405     		je	L1122
 6088              	L1121:
 6089 37de B9010000 		movl	$1, %ecx
 6089      00
 6090              	L1122:
 6091 37e3 85C9     		testl	%ecx, %ecx
 6092 37e5 7510     		jne	L1119
 6093 37e7 85DB     		testl	%ebx, %ebx
 6094 37e9 740C     		je	L1119
 6095 37eb 8B08     		movl	(%eax), %ecx
 6096 37ed 31C0     		xorl	%eax, %eax
 6097 37ef 8B5114   		movl	20(%ecx), %edx
 6098 37f2 8913     		movl	%edx, (%ebx)
 6099              	L1117:
 6100 37f4 5B       		popl	%ebx
 6101 37f5 5D       		popl	%ebp
 6102 37f6 C3       		ret
 6103              		.p2align 4,,7
 6104              	L1119:
 6105 37f7 B8160000 		movl	$22, %eax
 6105      00
 6106 37fc EBF6     		jmp	L1117
 6107 37fe 89F6     		.p2align 4,,15
 6108              	.globl _pthread_setschedparam
 6109              		.def	_pthread_setschedparam;	.scl	2;	.type	32;	.endef
 6110              	_pthread_setschedparam:
 6111 3800 55       		pushl	%ebp
 6112 3801 89E5     		movl	%esp, %ebp
 6113 3803 57       		pushl	%edi
 6114 3804 56       		pushl	%esi
 6115 3805 53       		pushl	%ebx
 6116 3806 83EC10   		subl	$16, %esp
 6117 3809 8B5514   		movl	20(%ebp), %edx
 6118 380c 8B5D08   		movl	8(%ebp), %ebx
 6119 380f 8B750C   		movl	12(%ebp), %esi
 6120 3812 8B7D10   		movl	16(%ebp), %edi
 6121 3815 8955F0   		movl	%edx, -16(%ebp)
 6122 3818 6A00     		pushl	$0
 6123 381a 56       		pushl	%esi
 6124 381b 53       		pushl	%ebx
 6125 381c E89FDDFF 		call	_pthread_kill
 6125      FF
 6126 3821 83C410   		addl	$16, %esp
 6127 3824 85C0     		testl	%eax, %eax
 6128 3826 7513     		jne	L1123
 6129 3828 B8160000 		movl	$22, %eax
 6129      00
 6130 382d 83FF02   		cmpl	$2, %edi
 6131 3830 7709     		ja	L1123
 6132 3832 B8300000 		movl	$48, %eax
 6132      00
 6133 3837 85FF     		testl	%edi, %edi
 6134 3839 7408     		je	L1127
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 129


 6135              	L1123:
 6136 383b 8D65F4   		leal	-12(%ebp), %esp
 6137 383e 5B       		popl	%ebx
 6138 383f 5E       		popl	%esi
 6139 3840 5F       		popl	%edi
 6140 3841 5D       		popl	%ebp
 6141 3842 C3       		ret
 6142              	L1127:
 6143 3843 8B45F0   		movl	-16(%ebp), %eax
 6144 3846 8B08     		movl	(%eax), %ecx
 6145 3848 89750C   		movl	%esi, 12(%ebp)
 6146 384b 894D14   		movl	%ecx, 20(%ebp)
 6147 384e 895D08   		movl	%ebx, 8(%ebp)
 6148 3851 C7451000 		movl	$0, 16(%ebp)
 6148      000000
 6149 3858 8D65F4   		leal	-12(%ebp), %esp
 6150 385b 5B       		popl	%ebx
 6151 385c 5E       		popl	%esi
 6152 385d 5F       		popl	%edi
 6153 385e 5D       		popl	%ebp
 6154 385f EB0F     		jmp	_ptw32_setthreadpriority
 6155 3861 EB0D9090 		.p2align 4,,15
 6155      90909090 
 6155      90909090 
 6155      909090
 6156              	.globl _ptw32_setthreadpriority
 6157              		.def	_ptw32_setthreadpriority;	.scl	2;	.type	32;	.endef
 6158              	_ptw32_setthreadpriority:
 6159 3870 55       		pushl	%ebp
 6160 3871 89E5     		movl	%esp, %ebp
 6161 3873 57       		pushl	%edi
 6162 3874 56       		pushl	%esi
 6163 3875 53       		pushl	%ebx
 6164 3876 83EC18   		subl	$24, %esp
 6165 3879 8B7510   		movl	16(%ebp), %esi
 6166 387c 8B5508   		movl	8(%ebp), %edx
 6167 387f 56       		pushl	%esi
 6168 3880 8B5D14   		movl	20(%ebp), %ebx
 6169 3883 8955F0   		movl	%edx, -16(%ebp)
 6170 3886 89DF     		movl	%ebx, %edi
 6171 3888 E8230100 		call	_sched_get_priority_min
 6171      00
 6172 388d 83C410   		addl	$16, %esp
 6173 3890 39C3     		cmpl	%eax, %ebx
 6174 3892 7D0D     		jge	L1137
 6175              	L1130:
 6176 3894 B8160000 		movl	$22, %eax
 6176      00
 6177              	L1128:
 6178 3899 8D65F4   		leal	-12(%ebp), %esp
 6179 389c 5B       		popl	%ebx
 6180 389d 5E       		popl	%esi
 6181 389e 5F       		popl	%edi
 6182 389f 5D       		popl	%ebp
 6183 38a0 C3       		ret
 6184              		.p2align 4,,7
 6185              	L1137:
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 130


 6186 38a1 83EC0C   		subl	$12, %esp
 6187 38a4 56       		pushl	%esi
 6188 38a5 E8D60000 		call	_sched_get_priority_max
 6188      00
 6189 38aa 83C410   		addl	$16, %esp
 6190 38ad 39C3     		cmpl	%eax, %ebx
 6191 38af 7FE3     		jg	L1130
 6192 38b1 83FBF1   		cmpl	$-15, %ebx
 6193 38b4 7E5C     		jle	L1131
 6194 38b6 83FBFE   		cmpl	$-2, %ebx
 6195 38b9 7D57     		jge	L1131
 6196 38bb BFFEFFFF 		movl	$-2, %edi
 6196      FF
 6197              	L1132:
 6198 38c0 83EC0C   		subl	$12, %esp
 6199 38c3 8B4DF0   		movl	-16(%ebp), %ecx
 6200 38c6 83C128   		addl	$40, %ecx
 6201 38c9 51       		pushl	%ecx
 6202 38ca 894DEC   		movl	%ecx, -20(%ebp)
 6203 38cd E8BEE5FF 		call	_pthread_mutex_lock
 6203      FF
 6204 38d2 83C410   		addl	$16, %esp
 6205 38d5 89C6     		movl	%eax, %esi
 6206 38d7 85C0     		testl	%eax, %eax
 6207 38d9 7404     		je	L1138
 6208              	L1134:
 6209 38db 89F0     		movl	%esi, %eax
 6210 38dd EBBA     		jmp	L1128
 6211              	L1138:
 6212 38df 50       		pushl	%eax
 6213 38e0 50       		pushl	%eax
 6214 38e1 57       		pushl	%edi
 6215 38e2 8B7DF0   		movl	-16(%ebp), %edi
 6216 38e5 8B5704   		movl	4(%edi), %edx
 6217 38e8 52       		pushl	%edx
 6218 38e9 E8000000 		call	_SetThreadPriority@8
 6218      00
 6219 38ee 5A       		popl	%edx
 6220 38ef 85C0     		testl	%eax, %eax
 6221 38f1 59       		popl	%ecx
 6222 38f2 7516     		jne	L1135
 6223 38f4 BE160000 		movl	$22, %esi
 6223      00
 6224              	L1136:
 6225 38f9 83EC0C   		subl	$12, %esp
 6226 38fc 8B5DEC   		movl	-20(%ebp), %ebx
 6227 38ff 53       		pushl	%ebx
 6228 3900 E80BE9FF 		call	_pthread_mutex_unlock
 6228      FF
 6229 3905 83C410   		addl	$16, %esp
 6230 3908 EBD1     		jmp	L1134
 6231              	L1135:
 6232 390a 8B4DF0   		movl	-16(%ebp), %ecx
 6233 390d 89592C   		movl	%ebx, 44(%ecx)
 6234 3910 EBE7     		jmp	L1136
 6235              		.p2align 4,,7
 6236              	L1131:
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 131


 6237 3912 8D53FD   		leal	-3(%ebx), %edx
 6238 3915 83FA0B   		cmpl	$11, %edx
 6239 3918 77A6     		ja	L1132
 6240 391a BF020000 		movl	$2, %edi
 6240      00
 6241 391f EB9F     		jmp	L1132
 6242 3921 EB0D9090 		.p2align 4,,15
 6242      90909090 
 6242      90909090 
 6242      909090
 6243              	.globl _pthread_getschedparam
 6244              		.def	_pthread_getschedparam;	.scl	2;	.type	32;	.endef
 6245              	_pthread_getschedparam:
 6246 3930 55       		pushl	%ebp
 6247 3931 89E5     		movl	%esp, %ebp
 6248 3933 57       		pushl	%edi
 6249 3934 56       		pushl	%esi
 6250 3935 53       		pushl	%ebx
 6251 3936 83EC10   		subl	$16, %esp
 6252 3939 8B450C   		movl	12(%ebp), %eax
 6253 393c 8B5D08   		movl	8(%ebp), %ebx
 6254 393f 6A00     		pushl	$0
 6255 3941 8B7D10   		movl	16(%ebp), %edi
 6256 3944 50       		pushl	%eax
 6257 3945 53       		pushl	%ebx
 6258 3946 E875DCFF 		call	_pthread_kill
 6258      FF
 6259 394b 83C410   		addl	$16, %esp
 6260 394e 85C0     		testl	%eax, %eax
 6261 3950 751C     		jne	L1139
 6262 3952 83FF02   		cmpl	$2, %edi
 6263 3955 761F     		jbe	L1142
 6264 3957 8B5514   		movl	20(%ebp), %edx
 6265 395a 85D2     		testl	%edx, %edx
 6266 395c 7418     		je	L1142
 6267 395e C7070000 		movl	$0, (%edi)
 6267      0000
 6268 3964 8B4D14   		movl	20(%ebp), %ecx
 6269 3967 8B5B2C   		movl	44(%ebx), %ebx
 6270 396a 31C0     		xorl	%eax, %eax
 6271 396c 8919     		movl	%ebx, (%ecx)
 6272              	L1139:
 6273 396e 8D65F4   		leal	-12(%ebp), %esp
 6274 3971 5B       		popl	%ebx
 6275 3972 5E       		popl	%esi
 6276 3973 5F       		popl	%edi
 6277 3974 5D       		popl	%ebp
 6278 3975 C3       		ret
 6279              		.p2align 4,,7
 6280              	L1142:
 6281 3976 B8160000 		movl	$22, %eax
 6281      00
 6282 397b EBF1     		jmp	L1139
 6283 397d 8D7600   		.p2align 4,,15
 6284              	.globl _sched_get_priority_max
 6285              		.def	_sched_get_priority_max;	.scl	2;	.type	32;	.endef
 6286              	_sched_get_priority_max:
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 132


 6287 3980 55       		pushl	%ebp
 6288 3981 89E5     		movl	%esp, %ebp
 6289 3983 50       		pushl	%eax
 6290 3984 50       		pushl	%eax
 6291 3985 837D0802 		cmpl	$2, 8(%ebp)
 6292 3989 7709     		ja	L1145
 6293 398b B80F0000 		movl	$15, %eax
 6293      00
 6294              	L1143:
 6295 3990 89EC     		movl	%ebp, %esp
 6296 3992 5D       		popl	%ebp
 6297 3993 C3       		ret
 6298              		.p2align 4,,7
 6299              	L1145:
 6300 3994 E8000000 		call	__errno
 6300      00
 6301 3999 C7001600 		movl	$22, (%eax)
 6301      0000
 6302 399f 83C8FF   		orl	$-1, %eax
 6303 39a2 EBEC     		jmp	L1143
 6304 39a4 8DB60000 		.p2align 4,,15
 6304      00008DBF 
 6304      00000000 
 6305              	.globl _sched_get_priority_min
 6306              		.def	_sched_get_priority_min;	.scl	2;	.type	32;	.endef
 6307              	_sched_get_priority_min:
 6308 39b0 55       		pushl	%ebp
 6309 39b1 89E5     		movl	%esp, %ebp
 6310 39b3 50       		pushl	%eax
 6311 39b4 50       		pushl	%eax
 6312 39b5 837D0802 		cmpl	$2, 8(%ebp)
 6313 39b9 7709     		ja	L1148
 6314 39bb B8F1FFFF 		movl	$-15, %eax
 6314      FF
 6315              	L1146:
 6316 39c0 89EC     		movl	%ebp, %esp
 6317 39c2 5D       		popl	%ebp
 6318 39c3 C3       		ret
 6319              		.p2align 4,,7
 6320              	L1148:
 6321 39c4 E8000000 		call	__errno
 6321      00
 6322 39c9 C7001600 		movl	$22, (%eax)
 6322      0000
 6323 39cf 83C8FF   		orl	$-1, %eax
 6324 39d2 EBEC     		jmp	L1146
 6325 39d4 8DB60000 		.p2align 4,,15
 6325      00008DBF 
 6325      00000000 
 6326              	.globl _sched_setscheduler
 6327              		.def	_sched_setscheduler;	.scl	2;	.type	32;	.endef
 6328              	_sched_setscheduler:
 6329 39e0 55       		pushl	%ebp
 6330 39e1 89E5     		movl	%esp, %ebp
 6331 39e3 53       		pushl	%ebx
 6332 39e4 53       		pushl	%ebx
 6333 39e5 8B5D08   		movl	8(%ebp), %ebx
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 133


 6334 39e8 85DB     		testl	%ebx, %ebx
 6335 39ea 7524     		jne	L1157
 6336              	L1150:
 6337 39ec 8B550C   		movl	12(%ebp), %edx
 6338 39ef 85D2     		testl	%edx, %edx
 6339 39f1 750D     		jne	L1158
 6340 39f3 31C0     		xorl	%eax, %eax
 6341              	L1149:
 6342 39f5 8B5DFC   		movl	-4(%ebp), %ebx
 6343 39f8 89EC     		movl	%ebp, %esp
 6344 39fa 5D       		popl	%ebp
 6345 39fb C3       		ret
 6346 39fc 8D742600 		.p2align 4,,7
 6347              	L1158:
 6348 3a00 E8000000 		call	__errno
 6348      00
 6349 3a05 C7002800 		movl	$40, (%eax)
 6349      0000
 6350              	L1156:
 6351 3a0b 83C8FF   		orl	$-1, %eax
 6352 3a0e EBE5     		jmp	L1149
 6353              		.p2align 4,,7
 6354              	L1157:
 6355 3a10 E8000000 		call	_GetCurrentProcessId@0
 6355      00
 6356 3a15 39C3     		cmpl	%eax, %ebx
 6357 3a17 74D3     		je	L1150
 6358 3a19 51       		pushl	%ecx
 6359 3a1a 53       		pushl	%ebx
 6360 3a1b 6A00     		pushl	$0
 6361 3a1d 68000200 		pushl	$512
 6361      00
 6362 3a22 E8000000 		call	_OpenProcess@12
 6362      00
 6363 3a27 5A       		popl	%edx
 6364 3a28 85C0     		testl	%eax, %eax
 6365 3a2a 75C0     		jne	L1150
 6366 3a2c E8000000 		call	__errno
 6366      00
 6367 3a31 89C3     		movl	%eax, %ebx
 6368 3a33 E8000000 		call	_GetLastError@0
 6368      00
 6369 3a38 83F805   		cmpl	$5, %eax
 6370 3a3b 0F95C1   		setne	%cl
 6371 3a3e 81E1FF00 		andl	$255, %ecx
 6371      0000
 6372 3a44 8D540901 		leal	1(%ecx,%ecx), %edx
 6373 3a48 8913     		movl	%edx, (%ebx)
 6374 3a4a EBBF     		jmp	L1156
 6375 3a4c 8D742600 		.p2align 4,,15
 6376              	.globl _sched_getscheduler
 6377              		.def	_sched_getscheduler;	.scl	2;	.type	32;	.endef
 6378              	_sched_getscheduler:
 6379 3a50 55       		pushl	%ebp
 6380 3a51 89E5     		movl	%esp, %ebp
 6381 3a53 53       		pushl	%ebx
 6382 3a54 53       		pushl	%ebx
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 134


 6383 3a55 8B5D08   		movl	8(%ebp), %ebx
 6384 3a58 85DB     		testl	%ebx, %ebx
 6385 3a5a 7509     		jne	L1165
 6386              	L1160:
 6387 3a5c 31C0     		xorl	%eax, %eax
 6388              	L1159:
 6389 3a5e 8B5DFC   		movl	-4(%ebp), %ebx
 6390 3a61 89EC     		movl	%ebp, %esp
 6391 3a63 5D       		popl	%ebp
 6392 3a64 C3       		ret
 6393              		.p2align 4,,7
 6394              	L1165:
 6395 3a65 E8000000 		call	_GetCurrentProcessId@0
 6395      00
 6396 3a6a 39C3     		cmpl	%eax, %ebx
 6397 3a6c 74EE     		je	L1160
 6398 3a6e 51       		pushl	%ecx
 6399 3a6f 53       		pushl	%ebx
 6400 3a70 6A00     		pushl	$0
 6401 3a72 68000400 		pushl	$1024
 6401      00
 6402 3a77 E8000000 		call	_OpenProcess@12
 6402      00
 6403 3a7c 5A       		popl	%edx
 6404 3a7d 85C0     		testl	%eax, %eax
 6405 3a7f 75DB     		jne	L1160
 6406 3a81 E8000000 		call	__errno
 6406      00
 6407 3a86 89C3     		movl	%eax, %ebx
 6408 3a88 E8000000 		call	_GetLastError@0
 6408      00
 6409 3a8d 83F805   		cmpl	$5, %eax
 6410 3a90 0F95C1   		setne	%cl
 6411 3a93 81E1FF00 		andl	$255, %ecx
 6411      0000
 6412 3a99 83C8FF   		orl	$-1, %eax
 6413 3a9c 8D540901 		leal	1(%ecx,%ecx), %edx
 6414 3aa0 8913     		movl	%edx, (%ebx)
 6415 3aa2 EBBA     		jmp	L1159
 6416 3aa4 8DB60000 		.p2align 4,,15
 6416      00008DBF 
 6416      00000000 
 6417              	.globl _sched_yield
 6418              		.def	_sched_yield;	.scl	2;	.type	32;	.endef
 6419              	_sched_yield:
 6420 3ab0 55       		pushl	%ebp
 6421 3ab1 89E5     		movl	%esp, %ebp
 6422 3ab3 83EC14   		subl	$20, %esp
 6423 3ab6 6A00     		pushl	$0
 6424 3ab8 E8000000 		call	_Sleep@4
 6424      00
 6425 3abd 89EC     		movl	%ebp, %esp
 6426 3abf 31C0     		xorl	%eax, %eax
 6427 3ac1 5D       		popl	%ebp
 6428 3ac2 C3       		ret
 6429 3ac3 8DB60000 		.p2align 4,,15
 6429      00008DBC 
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 135


 6429      27000000 
 6429      00
 6430              	.globl _sem_init
 6431              		.def	_sem_init;	.scl	2;	.type	32;	.endef
 6432              	_sem_init:
 6433 3ad0 55       		pushl	%ebp
 6434 3ad1 89E5     		movl	%esp, %ebp
 6435 3ad3 57       		pushl	%edi
 6436 3ad4 56       		pushl	%esi
 6437 3ad5 31F6     		xorl	%esi, %esi
 6438 3ad7 53       		pushl	%ebx
 6439 3ad8 31DB     		xorl	%ebx, %ebx
 6440 3ada 83EC0C   		subl	$12, %esp
 6441 3add 8B550C   		movl	12(%ebp), %edx
 6442 3ae0 8B7D10   		movl	16(%ebp), %edi
 6443 3ae3 85D2     		testl	%edx, %edx
 6444 3ae5 7429     		je	L1168
 6445 3ae7 BB010000 		movl	$1, %ebx
 6445      00
 6446              	L1169:
 6447 3aec 85DB     		testl	%ebx, %ebx
 6448 3aee 7510     		jne	L1179
 6449              	L1178:
 6450 3af0 8B5508   		movl	8(%ebp), %edx
 6451 3af3 31C0     		xorl	%eax, %eax
 6452 3af5 8932     		movl	%esi, (%edx)
 6453              	L1167:
 6454 3af7 8D65F4   		leal	-12(%ebp), %esp
 6455 3afa 5B       		popl	%ebx
 6456 3afb 5E       		popl	%esi
 6457 3afc 5F       		popl	%edi
 6458 3afd 5D       		popl	%ebp
 6459 3afe C3       		ret
 6460 3aff 90       		.p2align 4,,7
 6461              	L1179:
 6462 3b00 E8000000 		call	__errno
 6462      00
 6463 3b05 8918     		movl	%ebx, (%eax)
 6464 3b07 83C8FF   		orl	$-1, %eax
 6465 3b0a EBEB     		jmp	L1167
 6466 3b0c 8D742600 		.p2align 4,,7
 6467              	L1168:
 6468 3b10 85FF     		testl	%edi, %edi
 6469 3b12 787C     		js	L1180
 6470 3b14 50       		pushl	%eax
 6471 3b15 50       		pushl	%eax
 6472 3b16 6A0C     		pushl	$12
 6473 3b18 6A01     		pushl	$1
 6474 3b1a E8000000 		call	_calloc
 6474      00
 6475 3b1f 83C410   		addl	$16, %esp
 6476 3b22 89C6     		movl	%eax, %esi
 6477 3b24 85C0     		testl	%eax, %eax
 6478 3b26 7458     		je	L1181
 6479 3b28 8938     		movl	%edi, (%eax)
 6480 3b2a 57       		pushl	%edi
 6481 3b2b 57       		pushl	%edi
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 136


 6482 3b2c 8D7804   		leal	4(%eax), %edi
 6483 3b2f 6A00     		pushl	$0
 6484 3b31 57       		pushl	%edi
 6485 3b32 E879E0FF 		call	_pthread_mutex_init
 6485      FF
 6486 3b37 83C410   		addl	$16, %esp
 6487 3b3a 85C0     		testl	%eax, %eax
 6488 3b3c 7417     		je	L1182
 6489 3b3e BB1C0000 		movl	$28, %ebx
 6489      00
 6490              	L1176:
 6491 3b43 85DB     		testl	%ebx, %ebx
 6492 3b45 74A9     		je	L1178
 6493 3b47 83EC0C   		subl	$12, %esp
 6494 3b4a 56       		pushl	%esi
 6495 3b4b E8000000 		call	_free
 6495      00
 6496 3b50 83C410   		addl	$16, %esp
 6497 3b53 EB97     		jmp	L1169
 6498              	L1182:
 6499 3b55 6A00     		pushl	$0
 6500 3b57 68FF7F00 		pushl	$32767
 6500      00
 6501 3b5c 6A00     		pushl	$0
 6502 3b5e 6A00     		pushl	$0
 6503 3b60 E8000000 		call	_CreateSemaphoreA@16
 6503      00
 6504 3b65 85C0     		testl	%eax, %eax
 6505 3b67 894608   		movl	%eax, 8(%esi)
 6506 3b6a 75D7     		jne	L1176
 6507 3b6c 83EC0C   		subl	$12, %esp
 6508 3b6f BB1C0000 		movl	$28, %ebx
 6508      00
 6509 3b74 57       		pushl	%edi
 6510 3b75 E8F6E0FF 		call	_pthread_mutex_destroy
 6510      FF
 6511 3b7a 83C410   		addl	$16, %esp
 6512 3b7d EBC4     		jmp	L1176
 6513 3b7f 90       		.p2align 4,,7
 6514              	L1181:
 6515 3b80 BB0C0000 		movl	$12, %ebx
 6515      00
 6516 3b85 E962FFFF 		jmp	L1169
 6516      FF
 6517 3b8a 8DB60000 		.p2align 4,,7
 6517      0000
 6518              	L1180:
 6519 3b90 BB160000 		movl	$22, %ebx
 6519      00
 6520 3b95 E952FFFF 		jmp	L1169
 6520      FF
 6521 3b9a 8DB60000 		.p2align 4,,15
 6521      0000
 6522              	.globl _sem_destroy
 6523              		.def	_sem_destroy;	.scl	2;	.type	32;	.endef
 6524              	_sem_destroy:
 6525 3ba0 55       		pushl	%ebp
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 137


 6526 3ba1 89E5     		movl	%esp, %ebp
 6527 3ba3 57       		pushl	%edi
 6528 3ba4 56       		pushl	%esi
 6529 3ba5 53       		pushl	%ebx
 6530 3ba6 83EC0C   		subl	$12, %esp
 6531 3ba9 8B7508   		movl	8(%ebp), %esi
 6532 3bac C745F000 		movl	$0, -16(%ebp)
 6532      000000
 6533 3bb3 85F6     		testl	%esi, %esi
 6534 3bb5 7406     		je	L1198
 6535 3bb7 8B06     		movl	(%esi), %eax
 6536 3bb9 85C0     		testl	%eax, %eax
 6537 3bbb 752B     		jne	L1199
 6538              	L1198:
 6539 3bbd BB160000 		movl	$22, %ebx
 6539      00
 6540              	L1186:
 6541 3bc2 85DB     		testl	%ebx, %ebx
 6542 3bc4 7412     		je	L1196
 6543              	L1197:
 6544 3bc6 E8000000 		call	__errno
 6544      00
 6545 3bcb 8918     		movl	%ebx, (%eax)
 6546 3bcd 83C8FF   		orl	$-1, %eax
 6547              	L1183:
 6548 3bd0 8D65F4   		leal	-12(%ebp), %esp
 6549 3bd3 5B       		popl	%ebx
 6550 3bd4 5E       		popl	%esi
 6551 3bd5 5F       		popl	%edi
 6552 3bd6 5D       		popl	%ebp
 6553 3bd7 C3       		ret
 6554              		.p2align 4,,7
 6555              	L1196:
 6556 3bd8 83EC0C   		subl	$12, %esp
 6557 3bdb 8B75F0   		movl	-16(%ebp), %esi
 6558 3bde 56       		pushl	%esi
 6559 3bdf E8000000 		call	_free
 6559      00
 6560 3be4 31C0     		xorl	%eax, %eax
 6561 3be6 EBE8     		jmp	L1183
 6562              		.p2align 4,,7
 6563              	L1199:
 6564 3be8 83EC0C   		subl	$12, %esp
 6565 3beb 89C7     		movl	%eax, %edi
 6566 3bed 83C704   		addl	$4, %edi
 6567 3bf0 C7060000 		movl	$0, (%esi)
 6567      0000
 6568 3bf6 57       		pushl	%edi
 6569 3bf7 8945F0   		movl	%eax, -16(%ebp)
 6570 3bfa E8E1E6FF 		call	_pthread_mutex_trylock
 6570      FF
 6571 3bff 83C410   		addl	$16, %esp
 6572 3c02 89C3     		movl	%eax, %ebx
 6573 3c04 85C0     		testl	%eax, %eax
 6574 3c06 75BE     		jne	L1197
 6575 3c08 8B4DF0   		movl	-16(%ebp), %ecx
 6576 3c0b 8B11     		movl	(%ecx), %edx
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 138


 6577 3c0d 85D2     		testl	%edx, %edx
 6578 3c0f 786F     		js	L1188
 6579 3c11 83EC0C   		subl	$12, %esp
 6580 3c14 57       		pushl	%edi
 6581 3c15 E8F6E5FF 		call	_pthread_mutex_unlock
 6581      FF
 6582 3c1a 58       		popl	%eax
 6583 3c1b 8B45F0   		movl	-16(%ebp), %eax
 6584 3c1e 8B5808   		movl	8(%eax), %ebx
 6585 3c21 53       		pushl	%ebx
 6586 3c22 E8000000 		call	_CloseHandle@4
 6586      00
 6587 3c27 83C40C   		addl	$12, %esp
 6588 3c2a 85C0     		testl	%eax, %eax
 6589 3c2c 7507     		jne	L1189
 6590 3c2e 8B55F0   		movl	-16(%ebp), %edx
 6591 3c31 8916     		movl	%edx, (%esi)
 6592 3c33 EB88     		jmp	L1198
 6593              	L1189:
 6594 3c35 83EC0C   		subl	$12, %esp
 6595 3c38 57       		pushl	%edi
 6596 3c39 E832E0FF 		call	_pthread_mutex_destroy
 6596      FF
 6597 3c3e 83C410   		addl	$16, %esp
 6598 3c41 89C3     		movl	%eax, %ebx
 6599 3c43 85C0     		testl	%eax, %eax
 6600 3c45 7491     		je	L1196
 6601 3c47 6A00     		pushl	$0
 6602 3c49 68FF7F00 		pushl	$32767
 6602      00
 6603 3c4e 6A00     		pushl	$0
 6604 3c50 6A00     		pushl	$0
 6605 3c52 E8000000 		call	_CreateSemaphoreA@16
 6605      00
 6606 3c57 8B7DF0   		movl	-16(%ebp), %edi
 6607 3c5a 85C0     		testl	%eax, %eax
 6608 3c5c 894708   		movl	%eax, 8(%edi)
 6609 3c5f 7507     		jne	L1192
 6610 3c61 31DB     		xorl	%ebx, %ebx
 6611 3c63 E95AFFFF 		jmp	L1186
 6611      FF
 6612              	L1192:
 6613 3c68 8B4DF0   		movl	-16(%ebp), %ecx
 6614 3c6b 83FB10   		cmpl	$16, %ebx
 6615 3c6e 890E     		movl	%ecx, (%esi)
 6616 3c70 0F8547FF 		jne	L1198
 6616      FFFF
 6617 3c76 E947FFFF 		jmp	L1186
 6617      FF
 6618 3c7b 908D7426 		.p2align 4,,7
 6618      00
 6619              	L1188:
 6620 3c80 83EC0C   		subl	$12, %esp
 6621 3c83 BB100000 		movl	$16, %ebx
 6621      00
 6622 3c88 57       		pushl	%edi
 6623 3c89 E882E5FF 		call	_pthread_mutex_unlock
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 139


 6623      FF
 6624 3c8e 83C410   		addl	$16, %esp
 6625 3c91 E92CFFFF 		jmp	L1186
 6625      FF
 6626 3c96 8D76008D 		.p2align 4,,15
 6626      BC270000 
 6626      0000
 6627              	.globl _sem_trywait
 6628              		.def	_sem_trywait;	.scl	2;	.type	32;	.endef
 6629              	_sem_trywait:
 6630 3ca0 55       		pushl	%ebp
 6631 3ca1 89E5     		movl	%esp, %ebp
 6632 3ca3 57       		pushl	%edi
 6633 3ca4 56       		pushl	%esi
 6634 3ca5 BE160000 		movl	$22, %esi
 6634      00
 6635 3caa 53       		pushl	%ebx
 6636 3cab 83EC0C   		subl	$12, %esp
 6637 3cae 8B5508   		movl	8(%ebp), %edx
 6638 3cb1 8B1A     		movl	(%edx), %ebx
 6639 3cb3 85DB     		testl	%ebx, %ebx
 6640 3cb5 742A     		je	L1202
 6641 3cb7 83EC0C   		subl	$12, %esp
 6642 3cba 8D7B04   		leal	4(%ebx), %edi
 6643 3cbd 57       		pushl	%edi
 6644 3cbe E8CDE1FF 		call	_pthread_mutex_lock
 6644      FF
 6645 3cc3 83C410   		addl	$16, %esp
 6646 3cc6 89C6     		movl	%eax, %esi
 6647 3cc8 85C0     		testl	%eax, %eax
 6648 3cca 7519     		jne	L1207
 6649 3ccc 8B03     		movl	(%ebx), %eax
 6650 3cce 85C0     		testl	%eax, %eax
 6651 3cd0 7E29     		jle	L1204
 6652 3cd2 48       		decl	%eax
 6653 3cd3 8903     		movl	%eax, (%ebx)
 6654              	L1205:
 6655 3cd5 83EC0C   		subl	$12, %esp
 6656 3cd8 57       		pushl	%edi
 6657 3cd9 E832E5FF 		call	_pthread_mutex_unlock
 6657      FF
 6658 3cde 83C410   		addl	$16, %esp
 6659              	L1202:
 6660 3ce1 85F6     		testl	%esi, %esi
 6661 3ce3 7412     		je	L1206
 6662              	L1207:
 6663 3ce5 E8000000 		call	__errno
 6663      00
 6664 3cea 8930     		movl	%esi, (%eax)
 6665 3cec 83C8FF   		orl	$-1, %eax
 6666              	L1200:
 6667 3cef 8D65F4   		leal	-12(%ebp), %esp
 6668 3cf2 5B       		popl	%ebx
 6669 3cf3 5E       		popl	%esi
 6670 3cf4 5F       		popl	%edi
 6671 3cf5 5D       		popl	%ebp
 6672 3cf6 C3       		ret
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 140


 6673              		.p2align 4,,7
 6674              	L1206:
 6675 3cf7 31C0     		xorl	%eax, %eax
 6676 3cf9 EBF4     		jmp	L1200
 6677              	L1204:
 6678 3cfb BE0B0000 		movl	$11, %esi
 6678      00
 6679 3d00 EBD3     		jmp	L1205
 6680 3d02 8DB42600 		.p2align 4,,15
 6680      0000008D 
 6680      BC270000 
 6680      0000
 6681              	.globl _sem_wait
 6682              		.def	_sem_wait;	.scl	2;	.type	32;	.endef
 6683              	_sem_wait:
 6684 3d10 55       		pushl	%ebp
 6685 3d11 89E5     		movl	%esp, %ebp
 6686 3d13 57       		pushl	%edi
 6687 3d14 56       		pushl	%esi
 6688 3d15 53       		pushl	%ebx
 6689 3d16 83EC2C   		subl	$44, %esp
 6690 3d19 8B5508   		movl	8(%ebp), %edx
 6691 3d1c C745D416 		movl	$22, -44(%ebp)
 6691      000000
 6692 3d23 8B32     		movl	(%edx), %esi
 6693 3d25 85F6     		testl	%esi, %esi
 6694 3d27 744C     		je	L1210
 6695 3d29 8D7E04   		leal	4(%esi), %edi
 6696 3d2c E81FCEFF 		call	_pthread_testcancel
 6696      FF
 6697 3d31 83EC0C   		subl	$12, %esp
 6698 3d34 57       		pushl	%edi
 6699 3d35 E856E1FF 		call	_pthread_mutex_lock
 6699      FF
 6700 3d3a 83C410   		addl	$16, %esp
 6701 3d3d 85C0     		testl	%eax, %eax
 6702 3d3f 8945D4   		movl	%eax, -44(%ebp)
 6703 3d42 741C     		je	L1215
 6704              	L1214:
 6705 3d44 E8000000 		call	__errno
 6705      00
 6706 3d49 8B5DD4   		movl	-44(%ebp), %ebx
 6707 3d4c 8918     		movl	%ebx, (%eax)
 6708 3d4e 83C8FF   		orl	$-1, %eax
 6709              	L1208:
 6710 3d51 8D65F4   		leal	-12(%ebp), %esp
 6711 3d54 5B       		popl	%ebx
 6712 3d55 5E       		popl	%esi
 6713 3d56 5F       		popl	%edi
 6714 3d57 5D       		popl	%ebp
 6715 3d58 C3       		ret
 6716 3d59 8DB42600 		.p2align 4,,7
 6716      000000
 6717              	L1215:
 6718 3d60 8B1E     		movl	(%esi), %ebx
 6719 3d62 83EC0C   		subl	$12, %esp
 6720 3d65 4B       		decl	%ebx
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 141


 6721 3d66 891E     		movl	%ebx, (%esi)
 6722 3d68 57       		pushl	%edi
 6723 3d69 E8A2E4FF 		call	_pthread_mutex_unlock
 6723      FF
 6724 3d6e 83C410   		addl	$16, %esp
 6725 3d71 85DB     		testl	%ebx, %ebx
 6726 3d73 780B     		js	L1216
 6727              	L1210:
 6728 3d75 8B4DD4   		movl	-44(%ebp), %ecx
 6729 3d78 85C9     		testl	%ecx, %ecx
 6730 3d7a 75C8     		jne	L1214
 6731 3d7c 31C0     		xorl	%eax, %eax
 6732 3d7e EBD1     		jmp	L1208
 6733              	L1216:
 6734 3d80 8D55D8   		leal	-40(%ebp), %edx
 6735 3d83 57       		pushl	%edi
 6736 3d84 56       		pushl	%esi
 6737 3d85 68C05700 		pushl	$_ptw32_sem_wait_cleanup
 6737      00
 6738 3d8a 52       		pushl	%edx
 6739 3d8b E880D0FF 		call	_ptw32_push_cleanup
 6739      FF
 6740 3d90 8B4608   		movl	8(%esi), %eax
 6741 3d93 5B       		popl	%ebx
 6742 3d94 50       		pushl	%eax
 6743 3d95 E8E6DDFF 		call	_pthreadCancelableWait
 6743      FF
 6744 3d9a 890424   		movl	%eax, (%esp)
 6745 3d9d 8945D4   		movl	%eax, -44(%ebp)
 6746 3da0 E80BD0FF 		call	_ptw32_pop_cleanup
 6746      FF
 6747 3da5 83C410   		addl	$16, %esp
 6748 3da8 EBCB     		jmp	L1210
 6749 3daa 8DB60000 		.p2align 4,,15
 6749      0000
 6750              	.globl _sem_timedwait
 6751              		.def	_sem_timedwait;	.scl	2;	.type	32;	.endef
 6752              	_sem_timedwait:
 6753 3db0 55       		pushl	%ebp
 6754 3db1 89E5     		movl	%esp, %ebp
 6755 3db3 57       		pushl	%edi
 6756 3db4 56       		pushl	%esi
 6757 3db5 83CFFF   		orl	$-1, %edi
 6758 3db8 53       		pushl	%ebx
 6759 3db9 83EC3C   		subl	$60, %esp
 6760 3dbc 8B5D08   		movl	8(%ebp), %ebx
 6761 3dbf 8B4D0C   		movl	12(%ebp), %ecx
 6762 3dc2 C745BC00 		movl	$0, -68(%ebp)
 6762      000000
 6763 3dc9 8B13     		movl	(%ebx), %edx
 6764 3dcb 85C9     		testl	%ecx, %ecx
 6765 3dcd 8955B8   		movl	%edx, -72(%ebp)
 6766 3dd0 7474     		je	L1221
 6767 3dd2 8B01     		movl	(%ecx), %eax
 6768 3dd4 BBE80300 		movl	$1000, %ebx
 6768      00
 6769 3dd9 F7EB     		imull	%ebx
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 142


 6770 3ddb 89C6     		movl	%eax, %esi
 6771 3ddd 89D7     		movl	%edx, %edi
 6772 3ddf 8B4104   		movl	4(%ecx), %eax
 6773 3de2 6A00     		pushl	$0
 6774 3de4 89C1     		movl	%eax, %ecx
 6775 3de6 6840420F 		pushl	$1000000
 6775      00
 6776 3deb C1F91F   		sarl	$31, %ecx
 6777 3dee 0520A107 		addl	$500000, %eax
 6777      00
 6778 3df3 83D100   		adcl	$0, %ecx
 6779 3df6 51       		pushl	%ecx
 6780 3df7 50       		pushl	%eax
 6781 3df8 E8000000 		call	___divdi3
 6781      00
 6782 3dfd 01C6     		addl	%eax, %esi
 6783 3dff 11D7     		adcl	%edx, %edi
 6784 3e01 8D55D8   		leal	-40(%ebp), %edx
 6785 3e04 891424   		movl	%edx, (%esp)
 6786 3e07 E8000000 		call	__ftime
 6786      00
 6787 3e0c 8B45D8   		movl	-40(%ebp), %eax
 6788 3e0f 83C410   		addl	$16, %esp
 6789 3e12 F7EB     		imull	%ebx
 6790 3e14 89C1     		movl	%eax, %ecx
 6791 3e16 89D3     		movl	%edx, %ebx
 6792 3e18 0FBF45DC 		movswl	-36(%ebp),%eax
 6793 3e1c 89C2     		movl	%eax, %edx
 6794 3e1e C1FA1F   		sarl	$31, %edx
 6795 3e21 01C1     		addl	%eax, %ecx
 6796 3e23 11D3     		adcl	%edx, %ebx
 6797 3e25 39DF     		cmpl	%ebx, %edi
 6798 3e27 0F8CB700 		jl	L1222
 6798      0000
 6799 3e2d 7F08     		jg	L1223
 6800 3e2f 39CE     		cmpl	%ecx, %esi
 6801 3e31 0F86AD00 		jbe	L1222
 6801      0000
 6802              	L1223:
 6803 3e37 89F0     		movl	%esi, %eax
 6804 3e39 29C8     		subl	%ecx, %eax
 6805 3e3b 83F8FF   		cmpl	$-1, %eax
 6806 3e3e 0F849600 		je	L1232
 6806      0000
 6807              	L1225:
 6808 3e44 89C7     		movl	%eax, %edi
 6809              	L1221:
 6810 3e46 E805CDFF 		call	_pthread_testcancel
 6810      FF
 6811 3e4b 8B75B8   		movl	-72(%ebp), %esi
 6812 3e4e 83EC0C   		subl	$12, %esp
 6813 3e51 83C604   		addl	$4, %esi
 6814 3e54 56       		pushl	%esi
 6815 3e55 E836E0FF 		call	_pthread_mutex_lock
 6815      FF
 6816 3e5a 83C410   		addl	$16, %esp
 6817 3e5d 85C0     		testl	%eax, %eax
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 143


 6818 3e5f 8945BC   		movl	%eax, -68(%ebp)
 6819 3e62 751F     		jne	L1231
 6820 3e64 8B45B8   		movl	-72(%ebp), %eax
 6821 3e67 83EC0C   		subl	$12, %esp
 6822 3e6a 8B18     		movl	(%eax), %ebx
 6823 3e6c 4B       		decl	%ebx
 6824 3e6d 8918     		movl	%ebx, (%eax)
 6825 3e6f 56       		pushl	%esi
 6826 3e70 E89BE3FF 		call	_pthread_mutex_unlock
 6826      FF
 6827 3e75 83C410   		addl	$16, %esp
 6828 3e78 85DB     		testl	%ebx, %ebx
 6829 3e7a 7820     		js	L1233
 6830              	L1230:
 6831 3e7c 8B7DBC   		movl	-68(%ebp), %edi
 6832 3e7f 85FF     		testl	%edi, %edi
 6833 3e81 7415     		je	L1229
 6834              	L1231:
 6835 3e83 E8000000 		call	__errno
 6835      00
 6836 3e88 8B5DBC   		movl	-68(%ebp), %ebx
 6837 3e8b 8918     		movl	%ebx, (%eax)
 6838 3e8d 83C8FF   		orl	$-1, %eax
 6839              	L1217:
 6840 3e90 8D65F4   		leal	-12(%ebp), %esp
 6841 3e93 5B       		popl	%ebx
 6842 3e94 5E       		popl	%esi
 6843 3e95 5F       		popl	%edi
 6844 3e96 5D       		popl	%ebp
 6845 3e97 C3       		ret
 6846              		.p2align 4,,7
 6847              	L1229:
 6848 3e98 31C0     		xorl	%eax, %eax
 6849 3e9a EBF4     		jmp	L1217
 6850              	L1233:
 6851 3e9c 8D4DBC   		leal	-68(%ebp), %ecx
 6852 3e9f 8D55C0   		leal	-64(%ebp), %edx
 6853 3ea2 894DC4   		movl	%ecx, -60(%ebp)
 6854 3ea5 8D5DC8   		leal	-56(%ebp), %ebx
 6855 3ea8 8B75B8   		movl	-72(%ebp), %esi
 6856 3eab 51       		pushl	%ecx
 6857 3eac 8975C0   		movl	%esi, -64(%ebp)
 6858 3eaf 52       		pushl	%edx
 6859 3eb0 68105800 		pushl	$_ptw32_sem_timedwait_cleanup
 6859      00
 6860 3eb5 53       		pushl	%ebx
 6861 3eb6 E855CFFF 		call	_ptw32_push_cleanup
 6861      FF
 6862 3ebb 58       		popl	%eax
 6863 3ebc 5A       		popl	%edx
 6864 3ebd 57       		pushl	%edi
 6865 3ebe 8B7DB8   		movl	-72(%ebp), %edi
 6866 3ec1 8B7708   		movl	8(%edi), %esi
 6867 3ec4 56       		pushl	%esi
 6868 3ec5 E8D6DCFF 		call	_pthreadCancelableTimedWait
 6868      FF
 6869 3eca 890424   		movl	%eax, (%esp)
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 144


 6870 3ecd 8945BC   		movl	%eax, -68(%ebp)
 6871 3ed0 E8DBCEFF 		call	_ptw32_pop_cleanup
 6871      FF
 6872 3ed5 83C410   		addl	$16, %esp
 6873 3ed8 EBA2     		jmp	L1230
 6874              	L1232:
 6875 3eda B8FEFFFF 		movl	$-2, %eax
 6875      FF
 6876 3edf E960FFFF 		jmp	L1225
 6876      FF
 6877              		.p2align 4,,7
 6878              	L1222:
 6879 3ee4 31C0     		xorl	%eax, %eax
 6880 3ee6 E959FFFF 		jmp	L1225
 6880      FF
 6881 3eeb 908D7426 		.p2align 4,,15
 6881      00
 6882              	.globl _sem_post
 6883              		.def	_sem_post;	.scl	2;	.type	32;	.endef
 6884              	_sem_post:
 6885 3ef0 55       		pushl	%ebp
 6886 3ef1 89E5     		movl	%esp, %ebp
 6887 3ef3 57       		pushl	%edi
 6888 3ef4 56       		pushl	%esi
 6889 3ef5 BE160000 		movl	$22, %esi
 6889      00
 6890 3efa 53       		pushl	%ebx
 6891 3efb 83EC0C   		subl	$12, %esp
 6892 3efe 8B5508   		movl	8(%ebp), %edx
 6893 3f01 8B1A     		movl	(%edx), %ebx
 6894 3f03 85DB     		testl	%ebx, %ebx
 6895 3f05 7431     		je	L1236
 6896 3f07 83EC0C   		subl	$12, %esp
 6897 3f0a 8D7B04   		leal	4(%ebx), %edi
 6898 3f0d 57       		pushl	%edi
 6899 3f0e E87DDFFF 		call	_pthread_mutex_lock
 6899      FF
 6900 3f13 83C410   		addl	$16, %esp
 6901 3f16 89C6     		movl	%eax, %esi
 6902 3f18 85C0     		testl	%eax, %eax
 6903 3f1a 7520     		jne	L1242
 6904 3f1c 8B03     		movl	(%ebx), %eax
 6905 3f1e 3DFFFFFF 		cmpl	$2147483647, %eax
 6905      7F
 6906 3f23 744E     		je	L1238
 6907 3f25 40       		incl	%eax
 6908 3f26 8903     		movl	%eax, (%ebx)
 6909 3f28 85C0     		testl	%eax, %eax
 6910 3f2a 7E28     		jle	L1243
 6911              	L1240:
 6912 3f2c 83EC0C   		subl	$12, %esp
 6913 3f2f 57       		pushl	%edi
 6914 3f30 E8DBE2FF 		call	_pthread_mutex_unlock
 6914      FF
 6915 3f35 83C410   		addl	$16, %esp
 6916              	L1236:
 6917 3f38 85F6     		testl	%esi, %esi
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 145


 6918 3f3a 7414     		je	L1241
 6919              	L1242:
 6920 3f3c E8000000 		call	__errno
 6920      00
 6921 3f41 8930     		movl	%esi, (%eax)
 6922 3f43 83C8FF   		orl	$-1, %eax
 6923              	L1234:
 6924 3f46 8D65F4   		leal	-12(%ebp), %esp
 6925 3f49 5B       		popl	%ebx
 6926 3f4a 5E       		popl	%esi
 6927 3f4b 5F       		popl	%edi
 6928 3f4c 5D       		popl	%ebp
 6929 3f4d C3       		ret
 6930 3f4e 89F6     		.p2align 4,,7
 6931              	L1241:
 6932 3f50 31C0     		xorl	%eax, %eax
 6933 3f52 EBF2     		jmp	L1234
 6934              	L1243:
 6935 3f54 50       		pushl	%eax
 6936 3f55 6A00     		pushl	$0
 6937 3f57 6A01     		pushl	$1
 6938 3f59 8B4308   		movl	8(%ebx), %eax
 6939 3f5c 50       		pushl	%eax
 6940 3f5d E8000000 		call	_ReleaseSemaphore@12
 6940      00
 6941 3f62 5A       		popl	%edx
 6942 3f63 85C0     		testl	%eax, %eax
 6943 3f65 75C5     		jne	L1240
 6944 3f67 8B13     		movl	(%ebx), %edx
 6945 3f69 BE160000 		movl	$22, %esi
 6945      00
 6946 3f6e 4A       		decl	%edx
 6947 3f6f 8913     		movl	%edx, (%ebx)
 6948 3f71 EBB9     		jmp	L1240
 6949              	L1238:
 6950 3f73 BE220000 		movl	$34, %esi
 6950      00
 6951 3f78 EBB2     		jmp	L1240
 6952 3f7a 8DB60000 		.p2align 4,,15
 6952      0000
 6953              	.globl _sem_post_multiple
 6954              		.def	_sem_post_multiple;	.scl	2;	.type	32;	.endef
 6955              	_sem_post_multiple:
 6956 3f80 55       		pushl	%ebp
 6957 3f81 89E5     		movl	%esp, %ebp
 6958 3f83 57       		pushl	%edi
 6959 3f84 56       		pushl	%esi
 6960 3f85 53       		pushl	%ebx
 6961 3f86 83EC0C   		subl	$12, %esp
 6962 3f89 8B5508   		movl	8(%ebp), %edx
 6963 3f8c 8B7D0C   		movl	12(%ebp), %edi
 6964 3f8f 8B1A     		movl	(%edx), %ebx
 6965 3f91 85DB     		testl	%ebx, %ebx
 6966 3f93 0F849700 		je	L1246
 6966      0000
 6967 3f99 85FF     		testl	%edi, %edi
 6968 3f9b 0F8E8F00 		jle	L1246
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 146


 6968      0000
 6969 3fa1 83EC0C   		subl	$12, %esp
 6970 3fa4 8D5304   		leal	4(%ebx), %edx
 6971 3fa7 8955F0   		movl	%edx, -16(%ebp)
 6972 3faa 52       		pushl	%edx
 6973 3fab E8E0DEFF 		call	_pthread_mutex_lock
 6973      FF
 6974 3fb0 83C410   		addl	$16, %esp
 6975 3fb3 89C6     		movl	%eax, %esi
 6976 3fb5 85C0     		testl	%eax, %eax
 6977 3fb7 7552     		jne	L1256
 6978 3fb9 B9FFFFFF 		movl	$2147483647, %ecx
 6978      7F
 6979 3fbe 8B13     		movl	(%ebx), %edx
 6980 3fc0 29F9     		subl	%edi, %ecx
 6981 3fc2 39CA     		cmpl	%ecx, %edx
 6982 3fc4 7F5E     		jg	L1249
 6983 3fc6 89D1     		movl	%edx, %ecx
 6984 3fc8 8D0417   		leal	(%edi,%edx), %eax
 6985 3fcb F7D9     		negl	%ecx
 6986 3fcd 8903     		movl	%eax, (%ebx)
 6987 3fcf 85C9     		testl	%ecx, %ecx
 6988 3fd1 7E25     		jle	L1254
 6989 3fd3 39F9     		cmpl	%edi, %ecx
 6990 3fd5 50       		pushl	%eax
 6991 3fd6 89C8     		movl	%ecx, %eax
 6992 3fd8 6A00     		pushl	$0
 6993 3fda 7E02     		jle	L1252
 6994 3fdc 89F8     		movl	%edi, %eax
 6995              	L1252:
 6996 3fde 50       		pushl	%eax
 6997 3fdf 8B4308   		movl	8(%ebx), %eax
 6998 3fe2 50       		pushl	%eax
 6999 3fe3 E8000000 		call	_ReleaseSemaphore@12
 6999      00
 7000 3fe8 5A       		popl	%edx
 7001 3fe9 85C0     		testl	%eax, %eax
 7002 3feb 750B     		jne	L1254
 7003 3fed 8B33     		movl	(%ebx), %esi
 7004 3fef 29FE     		subl	%edi, %esi
 7005 3ff1 8933     		movl	%esi, (%ebx)
 7006 3ff3 BE160000 		movl	$22, %esi
 7006      00
 7007              	L1254:
 7008 3ff8 83EC0C   		subl	$12, %esp
 7009 3ffb 8B5DF0   		movl	-16(%ebp), %ebx
 7010 3ffe 53       		pushl	%ebx
 7011 3fff E80CE2FF 		call	_pthread_mutex_unlock
 7011      FF
 7012 4004 83C410   		addl	$16, %esp
 7013              	L1247:
 7014 4007 85F6     		testl	%esi, %esi
 7015 4009 7415     		je	L1255
 7016              	L1256:
 7017 400b E8000000 		call	__errno
 7017      00
 7018 4010 8930     		movl	%esi, (%eax)
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 147


 7019 4012 83C8FF   		orl	$-1, %eax
 7020              	L1244:
 7021 4015 8D65F4   		leal	-12(%ebp), %esp
 7022 4018 5B       		popl	%ebx
 7023 4019 5E       		popl	%esi
 7024 401a 5F       		popl	%edi
 7025 401b 5D       		popl	%ebp
 7026 401c C3       		ret
 7027 401d 8D7600   		.p2align 4,,7
 7028              	L1255:
 7029 4020 31C0     		xorl	%eax, %eax
 7030 4022 EBF1     		jmp	L1244
 7031              		.p2align 4,,7
 7032              	L1249:
 7033 4024 BE220000 		movl	$34, %esi
 7033      00
 7034 4029 EBCD     		jmp	L1254
 7035 402b 908D7426 		.p2align 4,,7
 7035      00
 7036              	L1246:
 7037 4030 BE160000 		movl	$22, %esi
 7037      00
 7038 4035 EBD0     		jmp	L1247
 7039 4037 89F68DBC 		.p2align 4,,15
 7039      27000000 
 7039      00
 7040              	.globl _sem_getvalue
 7041              		.def	_sem_getvalue;	.scl	2;	.type	32;	.endef
 7042              	_sem_getvalue:
 7043 4040 55       		pushl	%ebp
 7044 4041 89E5     		movl	%esp, %ebp
 7045 4043 57       		pushl	%edi
 7046 4044 56       		pushl	%esi
 7047 4045 53       		pushl	%ebx
 7048 4046 83EC0C   		subl	$12, %esp
 7049 4049 8B4508   		movl	8(%ebp), %eax
 7050 404c 85C0     		testl	%eax, %eax
 7051 404e 7441     		je	L1259
 7052 4050 8B18     		movl	(%eax), %ebx
 7053 4052 85DB     		testl	%ebx, %ebx
 7054 4054 743B     		je	L1259
 7055 4056 8B550C   		movl	12(%ebp), %edx
 7056 4059 85D2     		testl	%edx, %edx
 7057 405b 7434     		je	L1259
 7058 405d 83EC0C   		subl	$12, %esp
 7059 4060 8D7B04   		leal	4(%ebx), %edi
 7060 4063 57       		pushl	%edi
 7061 4064 E827DEFF 		call	_pthread_mutex_lock
 7061      FF
 7062 4069 83C410   		addl	$16, %esp
 7063 406c 89C6     		movl	%eax, %esi
 7064 406e 85C0     		testl	%eax, %eax
 7065 4070 740A     		je	L1262
 7066              	L1261:
 7067 4072 89F0     		movl	%esi, %eax
 7068              	L1257:
 7069 4074 8D65F4   		leal	-12(%ebp), %esp
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 148


 7070 4077 5B       		popl	%ebx
 7071 4078 5E       		popl	%esi
 7072 4079 5F       		popl	%edi
 7073 407a 5D       		popl	%ebp
 7074 407b C3       		ret
 7075              	L1262:
 7076 407c 83EC0C   		subl	$12, %esp
 7077 407f 8B1B     		movl	(%ebx), %ebx
 7078 4081 57       		pushl	%edi
 7079 4082 E889E1FF 		call	_pthread_mutex_unlock
 7079      FF
 7080 4087 83C410   		addl	$16, %esp
 7081 408a 8B550C   		movl	12(%ebp), %edx
 7082 408d 891A     		movl	%ebx, (%edx)
 7083 408f EBE1     		jmp	L1261
 7084              		.p2align 4,,7
 7085              	L1259:
 7086 4091 E8000000 		call	__errno
 7086      00
 7087 4096 C7001600 		movl	$22, (%eax)
 7087      0000
 7088 409c 83C8FF   		orl	$-1, %eax
 7089 409f EBD3     		jmp	L1257
 7090 40a1 EB0D9090 		.p2align 4,,15
 7090      90909090 
 7090      90909090 
 7090      909090
 7091              	.globl _sem_open
 7092              		.def	_sem_open;	.scl	2;	.type	32;	.endef
 7093              	_sem_open:
 7094 40b0 55       		pushl	%ebp
 7095 40b1 89E5     		movl	%esp, %ebp
 7096 40b3 50       		pushl	%eax
 7097 40b4 50       		pushl	%eax
 7098 40b5 E8000000 		call	__errno
 7098      00
 7099 40ba C7002800 		movl	$40, (%eax)
 7099      0000
 7100 40c0 89EC     		movl	%ebp, %esp
 7101 40c2 83C8FF   		orl	$-1, %eax
 7102 40c5 5D       		popl	%ebp
 7103 40c6 C3       		ret
 7104 40c7 89F68DBC 		.p2align 4,,15
 7104      27000000 
 7104      00
 7105              	.globl _sem_close
 7106              		.def	_sem_close;	.scl	2;	.type	32;	.endef
 7107              	_sem_close:
 7108 40d0 55       		pushl	%ebp
 7109 40d1 89E5     		movl	%esp, %ebp
 7110 40d3 50       		pushl	%eax
 7111 40d4 50       		pushl	%eax
 7112 40d5 E8000000 		call	__errno
 7112      00
 7113 40da C7002800 		movl	$40, (%eax)
 7113      0000
 7114 40e0 89EC     		movl	%ebp, %esp
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 149


 7115 40e2 83C8FF   		orl	$-1, %eax
 7116 40e5 5D       		popl	%ebp
 7117 40e6 C3       		ret
 7118 40e7 89F68DBC 		.p2align 4,,15
 7118      27000000 
 7118      00
 7119              	.globl _sem_unlink
 7120              		.def	_sem_unlink;	.scl	2;	.type	32;	.endef
 7121              	_sem_unlink:
 7122 40f0 55       		pushl	%ebp
 7123 40f1 89E5     		movl	%esp, %ebp
 7124 40f3 50       		pushl	%eax
 7125 40f4 50       		pushl	%eax
 7126 40f5 E8000000 		call	__errno
 7126      00
 7127 40fa C7002800 		movl	$40, (%eax)
 7127      0000
 7128 4100 89EC     		movl	%ebp, %esp
 7129 4102 83C8FF   		orl	$-1, %eax
 7130 4105 5D       		popl	%ebp
 7131 4106 C3       		ret
 7132 4107 89F68DBC 		.p2align 4,,15
 7132      27000000 
 7132      00
 7133              	.globl _pthread_spin_init
 7134              		.def	_pthread_spin_init;	.scl	2;	.type	32;	.endef
 7135              	_pthread_spin_init:
 7136 4110 55       		pushl	%ebp
 7137 4111 B8160000 		movl	$22, %eax
 7137      00
 7138 4116 89E5     		movl	%esp, %ebp
 7139 4118 57       		pushl	%edi
 7140 4119 56       		pushl	%esi
 7141 411a 31F6     		xorl	%esi, %esi
 7142 411c 53       		pushl	%ebx
 7143 411d 83EC1C   		subl	$28, %esp
 7144 4120 8B7D08   		movl	8(%ebp), %edi
 7145 4123 C745F000 		movl	$0, -16(%ebp)
 7145      000000
 7146 412a 85FF     		testl	%edi, %edi
 7147 412c 0F848800 		je	L1266
 7147      0000
 7148 4132 8D55EC   		leal	-20(%ebp), %edx
 7149 4135 50       		pushl	%eax
 7150 4136 31DB     		xorl	%ebx, %ebx
 7151 4138 52       		pushl	%edx
 7152 4139 8D55E8   		leal	-24(%ebp), %edx
 7153 413c 52       		pushl	%edx
 7154 413d 50       		pushl	%eax
 7155 413e E8000000 		call	_GetCurrentProcess@0
 7155      00
 7156 4143 890424   		movl	%eax, (%esp)
 7157 4146 E8000000 		call	_GetProcessAffinityMask@12
 7157      00
 7158 414b 59       		popl	%ecx
 7159 414c 85C0     		testl	%eax, %eax
 7160 414e 0F84D000 		je	L1269
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 150


 7160      0000
 7161 4154 31C9     		xorl	%ecx, %ecx
 7162 4156 B8010000 		movl	$1, %eax
 7162      00
 7163 415b 8B55E8   		movl	-24(%ebp), %edx
 7164 415e 89F6     		.p2align 4,,7
 7165              	L1275:
 7166 4160 85D0     		testl	%eax, %edx
 7167 4162 7401     		je	L1272
 7168 4164 41       		incl	%ecx
 7169              	L1272:
 7170 4165 01C0     		addl	%eax, %eax
 7171 4167 75F7     		jne	L1275
 7172 4169 894DF0   		movl	%ecx, -16(%ebp)
 7173              	L1276:
 7174 416c 85DB     		testl	%ebx, %ebx
 7175 416e 7407     		je	L1268
 7176 4170 C745F001 		movl	$1, -16(%ebp)
 7176      000000
 7177              	L1268:
 7178 4177 837DF001 		cmpl	$1, -16(%ebp)
 7179 417b 7E0B     		jle	L1278
 7180 417d B8280000 		movl	$40, %eax
 7180      00
 7181 4182 837D0C01 		cmpl	$1, 12(%ebp)
 7182 4186 7432     		je	L1266
 7183              	L1278:
 7184 4188 52       		pushl	%edx
 7185 4189 52       		pushl	%edx
 7186 418a 6A08     		pushl	$8
 7187 418c 6A01     		pushl	$1
 7188 418e E8000000 		call	_calloc
 7188      00
 7189 4193 83C410   		addl	$16, %esp
 7190 4196 89C3     		movl	%eax, %ebx
 7191 4198 B80C0000 		movl	$12, %eax
 7191      00
 7192 419d 85DB     		testl	%ebx, %ebx
 7193 419f 7419     		je	L1266
 7194 41a1 8B45F0   		movl	-16(%ebp), %eax
 7195 41a4 83F801   		cmpl	$1, %eax
 7196 41a7 7E2D     		jle	L1281
 7197 41a9 894304   		movl	%eax, 4(%ebx)
 7198 41ac C7030100 		movl	$1, (%ebx)
 7198      0000
 7199              	L1282:
 7200 41b2 85F6     		testl	%esi, %esi
 7201 41b4 750C     		jne	L1285
 7202 41b6 891F     		movl	%ebx, (%edi)
 7203              	L1286:
 7204 41b8 89F0     		movl	%esi, %eax
 7205              	L1266:
 7206 41ba 8D65F4   		leal	-12(%ebp), %esp
 7207 41bd 5B       		popl	%ebx
 7208 41be 5E       		popl	%esi
 7209 41bf 5F       		popl	%edi
 7210 41c0 5D       		popl	%ebp
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 151


 7211 41c1 C3       		ret
 7212              	L1285:
 7213 41c2 83EC0C   		subl	$12, %esp
 7214 41c5 53       		pushl	%ebx
 7215 41c6 E8000000 		call	_free
 7215      00
 7216 41cb 83C410   		addl	$16, %esp
 7217 41ce C7070000 		movl	$0, (%edi)
 7217      0000
 7218 41d4 EBE2     		jmp	L1286
 7219              	L1281:
 7220 41d6 83EC0C   		subl	$12, %esp
 7221 41d9 8D4DE4   		leal	-28(%ebp), %ecx
 7222 41dc 51       		pushl	%ecx
 7223 41dd E86EDBFF 		call	_pthread_mutexattr_init
 7223      FF
 7224 41e2 83C410   		addl	$16, %esp
 7225 41e5 89C6     		movl	%eax, %esi
 7226 41e7 85C0     		testl	%eax, %eax
 7227 41e9 7411     		je	L1289
 7228              	L1283:
 7229 41eb 83EC0C   		subl	$12, %esp
 7230 41ee 8D4DE4   		leal	-28(%ebp), %ecx
 7231 41f1 51       		pushl	%ecx
 7232 41f2 E899DBFF 		call	_pthread_mutexattr_destroy
 7232      FF
 7233 41f7 83C410   		addl	$16, %esp
 7234 41fa EBB6     		jmp	L1282
 7235              	L1289:
 7236 41fc 8B4DE4   		movl	-28(%ebp), %ecx
 7237 41ff 8B450C   		movl	12(%ebp), %eax
 7238 4202 8D55E4   		leal	-28(%ebp), %edx
 7239 4205 8D7304   		leal	4(%ebx), %esi
 7240 4208 8901     		movl	%eax, (%ecx)
 7241 420a 50       		pushl	%eax
 7242 420b 50       		pushl	%eax
 7243 420c 52       		pushl	%edx
 7244 420d 56       		pushl	%esi
 7245 420e E89DD9FF 		call	_pthread_mutex_init
 7245      FF
 7246 4213 83C410   		addl	$16, %esp
 7247 4216 89C6     		movl	%eax, %esi
 7248 4218 85C0     		testl	%eax, %eax
 7249 421a 75CF     		jne	L1283
 7250 421c C7030300 		movl	$3, (%ebx)
 7250      0000
 7251 4222 EBC7     		jmp	L1283
 7252              		.p2align 4,,7
 7253              	L1269:
 7254 4224 BB0B0000 		movl	$11, %ebx
 7254      00
 7255 4229 E93EFFFF 		jmp	L1276
 7255      FF
 7256 422e 89F6     		.p2align 4,,15
 7257              	.globl _pthread_spin_destroy
 7258              		.def	_pthread_spin_destroy;	.scl	2;	.type	32;	.endef
 7259              	_pthread_spin_destroy:
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 152


 7260 4230 55       		pushl	%ebp
 7261 4231 89E5     		movl	%esp, %ebp
 7262 4233 57       		pushl	%edi
 7263 4234 56       		pushl	%esi
 7264 4235 31F6     		xorl	%esi, %esi
 7265 4237 53       		pushl	%ebx
 7266 4238 83EC0C   		subl	$12, %esp
 7267 423b 8B7D08   		movl	8(%ebp), %edi
 7268 423e 85FF     		testl	%edi, %edi
 7269 4240 7406     		je	L1292
 7270 4242 8B1F     		movl	(%edi), %ebx
 7271 4244 85DB     		testl	%ebx, %ebx
 7272 4246 750D     		jne	L1291
 7273              	L1292:
 7274 4248 B8160000 		movl	$22, %eax
 7274      00
 7275              	L1290:
 7276 424d 8D65F4   		leal	-12(%ebp), %esp
 7277 4250 5B       		popl	%ebx
 7278 4251 5E       		popl	%esi
 7279 4252 5F       		popl	%edi
 7280 4253 5D       		popl	%ebp
 7281 4254 C3       		ret
 7282              		.p2align 4,,7
 7283              	L1291:
 7284 4255 83FBFF   		cmpl	$-1, %ebx
 7285 4258 7454     		je	L1293
 7286 425a 833B03   		cmpl	$3, (%ebx)
 7287 425d 743C     		je	L1304
 7288 425f 8B0D2400 		movl	_ptw32_smp_system, %ecx
 7288      0000
 7289 4265 B8010000 		movl	$1, %eax
 7289      00
 7290 426a 85C9     		testl	%ecx, %ecx
 7291 426c 7428     		je	L1297
 7292              	/APP
 7293 426e F0       		lock
 7294 426f 0FB133   		cmpxchgl       %esi,(%ebx)
 7295              	/NO_APP
 7296              	L1298:
 7297 4272 48       		decl	%eax
 7298 4273 7405     		je	L1295
 7299 4275 BE160000 		movl	$22, %esi
 7299      00
 7300              	L1295:
 7301 427a 85F6     		testl	%esi, %esi
 7302 427c 7404     		je	L1305
 7303              	L1301:
 7304 427e 89F0     		movl	%esi, %eax
 7305 4280 EBCB     		jmp	L1290
 7306              		.p2align 4,,7
 7307              	L1305:
 7308 4282 83EC0C   		subl	$12, %esp
 7309 4285 C7070000 		movl	$0, (%edi)
 7309      0000
 7310 428b 53       		pushl	%ebx
 7311 428c E8000000 		call	_free
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 153


 7311      00
 7312 4291 83C410   		addl	$16, %esp
 7313 4294 EBE8     		jmp	L1301
 7314              		.p2align 4,,7
 7315              	L1297:
 7316              	/APP
 7317 4296 0FB133   		cmpxchgl       %esi,(%ebx)
 7318              	/NO_APP
 7319 4299 EBD7     		jmp	L1298
 7320              	L1304:
 7321 429b 83EC0C   		subl	$12, %esp
 7322 429e 8D5304   		leal	4(%ebx), %edx
 7323 42a1 52       		pushl	%edx
 7324 42a2 E8C9D9FF 		call	_pthread_mutex_destroy
 7324      FF
 7325 42a7 83C410   		addl	$16, %esp
 7326 42aa 89C6     		movl	%eax, %esi
 7327 42ac EBCC     		jmp	L1295
 7328              	L1293:
 7329 42ae 83EC0C   		subl	$12, %esp
 7330 42b1 68000000 		pushl	$_ptw32_spinlock_test_init_lock
 7330      00
 7331 42b6 E8000000 		call	_EnterCriticalSection@4
 7331      00
 7332 42bb 83C40C   		addl	$12, %esp
 7333 42be 833FFF   		cmpl	$-1, (%edi)
 7334 42c1 7417     		je	L1306
 7335 42c3 BE100000 		movl	$16, %esi
 7335      00
 7336              	L1303:
 7337 42c8 83EC0C   		subl	$12, %esp
 7338 42cb 68000000 		pushl	$_ptw32_spinlock_test_init_lock
 7338      00
 7339 42d0 E8000000 		call	_LeaveCriticalSection@4
 7339      00
 7340 42d5 83C40C   		addl	$12, %esp
 7341 42d8 EBA4     		jmp	L1301
 7342              	L1306:
 7343 42da C7070000 		movl	$0, (%edi)
 7343      0000
 7344 42e0 EBE6     		jmp	L1303
 7345 42e2 8DB42600 		.p2align 4,,15
 7345      0000008D 
 7345      BC270000 
 7345      0000
 7346              	.globl _pthread_spin_lock
 7347              		.def	_pthread_spin_lock;	.scl	2;	.type	32;	.endef
 7348              	_pthread_spin_lock:
 7349 42f0 55       		pushl	%ebp
 7350 42f1 89E5     		movl	%esp, %ebp
 7351 42f3 57       		pushl	%edi
 7352 42f4 56       		pushl	%esi
 7353 42f5 53       		pushl	%ebx
 7354 42f6 83EC0C   		subl	$12, %esp
 7355 42f9 8B5D08   		movl	8(%ebp), %ebx
 7356 42fc 85DB     		testl	%ebx, %ebx
 7357 42fe 743D     		je	L1323
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 154


 7358 4300 8B13     		movl	(%ebx), %edx
 7359 4302 85D2     		testl	%edx, %edx
 7360 4304 7437     		je	L1323
 7361 4306 83FAFF   		cmpl	$-1, %edx
 7362 4309 745C     		je	L1327
 7363              	L1310:
 7364 430b 8B352400 		movl	_ptw32_smp_system, %esi
 7364      0000
 7365 4311 BB020000 		movl	$2, %ebx
 7365      00
 7366 4316 B9010000 		movl	$1, %ecx
 7366      00
 7367 431b 908D7426 		.p2align 4,,7
 7367      00
 7368              	L1316:
 7369 4320 85F6     		testl	%esi, %esi
 7370 4322 743C     		je	L1319
 7371 4324 89C8     		movl	%ecx, %eax
 7372              	/APP
 7373 4326 F0       		lock
 7374 4327 0FB11A   		cmpxchgl       %ebx,(%edx)
 7375              	/NO_APP
 7376              	L1326:
 7377 432a 83F802   		cmpl	$2, %eax
 7378 432d 74F1     		je	L1316
 7379 432f 8B0A     		movl	(%edx), %ecx
 7380 4331 31C0     		xorl	%eax, %eax
 7381 4333 83F902   		cmpl	$2, %ecx
 7382 4336 740A     		je	L1307
 7383 4338 83F903   		cmpl	$3, %ecx
 7384 433b 740D     		je	L1328
 7385              	L1323:
 7386 433d B8160000 		movl	$22, %eax
 7386      00
 7387              	L1307:
 7388 4342 8D65F4   		leal	-12(%ebp), %esp
 7389 4345 5B       		popl	%ebx
 7390 4346 5E       		popl	%esi
 7391 4347 5F       		popl	%edi
 7392 4348 5D       		popl	%ebp
 7393 4349 C3       		ret
 7394              	L1328:
 7395 434a 8D4A04   		leal	4(%edx), %ecx
 7396 434d 894D08   		movl	%ecx, 8(%ebp)
 7397 4350 8D65F4   		leal	-12(%ebp), %esp
 7398 4353 5B       		popl	%ebx
 7399 4354 5E       		popl	%esi
 7400 4355 5F       		popl	%edi
 7401 4356 5D       		popl	%ebp
 7402 4357 E934DBFF 		jmp	_pthread_mutex_lock
 7402      FF
 7403 435c 8D742600 		.p2align 4,,7
 7404              	L1319:
 7405 4360 89C8     		movl	%ecx, %eax
 7406              	/APP
 7407 4362 0FB11A   		cmpxchgl       %ebx,(%edx)
 7408              	/NO_APP
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 155


 7409 4365 EBC3     		jmp	L1326
 7410              	L1327:
 7411 4367 83EC0C   		subl	$12, %esp
 7412 436a 31F6     		xorl	%esi, %esi
 7413 436c 68000000 		pushl	$_ptw32_spinlock_test_init_lock
 7413      00
 7414 4371 E8000000 		call	_EnterCriticalSection@4
 7414      00
 7415 4376 8B03     		movl	(%ebx), %eax
 7416 4378 83C40C   		addl	$12, %esp
 7417 437b 83F8FF   		cmpl	$-1, %eax
 7418 437e 7426     		je	L1329
 7419 4380 85C0     		testl	%eax, %eax
 7420 4382 7505     		jne	L1313
 7421 4384 BE160000 		movl	$22, %esi
 7421      00
 7422              	L1313:
 7423 4389 83EC0C   		subl	$12, %esp
 7424 438c 68000000 		pushl	$_ptw32_spinlock_test_init_lock
 7424      00
 7425 4391 E8000000 		call	_LeaveCriticalSection@4
 7425      00
 7426 4396 89F0     		movl	%esi, %eax
 7427 4398 83C40C   		addl	$12, %esp
 7428 439b 85F6     		testl	%esi, %esi
 7429 439d 75A3     		jne	L1307
 7430 439f 8B13     		movl	(%ebx), %edx
 7431 43a1 E965FFFF 		jmp	L1310
 7431      FF
 7432              	L1329:
 7433 43a6 51       		pushl	%ecx
 7434 43a7 51       		pushl	%ecx
 7435 43a8 6A00     		pushl	$0
 7436 43aa 53       		pushl	%ebx
 7437 43ab E860FDFF 		call	_pthread_spin_init
 7437      FF
 7438 43b0 83C410   		addl	$16, %esp
 7439 43b3 89C6     		movl	%eax, %esi
 7440 43b5 EBD2     		jmp	L1313
 7441 43b7 89F68DBC 		.p2align 4,,15
 7441      27000000 
 7441      00
 7442              	.globl _pthread_spin_unlock
 7443              		.def	_pthread_spin_unlock;	.scl	2;	.type	32;	.endef
 7444              	_pthread_spin_unlock:
 7445 43c0 55       		pushl	%ebp
 7446 43c1 89E5     		movl	%esp, %ebp
 7447 43c3 53       		pushl	%ebx
 7448 43c4 8B4508   		movl	8(%ebp), %eax
 7449 43c7 85C0     		testl	%eax, %eax
 7450 43c9 743D     		je	L1334
 7451 43cb 8B18     		movl	(%eax), %ebx
 7452 43cd 85DB     		testl	%ebx, %ebx
 7453 43cf 7437     		je	L1334
 7454 43d1 B9010000 		movl	$1, %ecx
 7454      00
 7455 43d6 83FBFF   		cmpl	$-1, %ebx
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 156


 7456 43d9 7432     		je	L1330
 7457 43db A1240000 		movl	_ptw32_smp_system, %eax
 7457      00
 7458 43e0 B9010000 		movl	$1, %ecx
 7458      00
 7459 43e5 BA020000 		movl	$2, %edx
 7459      00
 7460 43ea 85C0     		testl	%eax, %eax
 7461 43ec 743A     		je	L1340
 7462 43ee 89D0     		movl	%edx, %eax
 7463              	/APP
 7464 43f0 F0       		lock
 7465 43f1 0FB10B   		cmpxchgl       %ecx,(%ebx)
 7466              	/NO_APP
 7467              	L1344:
 7468 43f4 89C2     		movl	%eax, %edx
 7469 43f6 83F802   		cmpl	$2, %eax
 7470 43f9 7429     		je	L1335
 7471 43fb 83F802   		cmpl	$2, %eax
 7472 43fe 7F12     		jg	L1343
 7473 4400 B9010000 		movl	$1, %ecx
 7473      00
 7474 4405 4A       		decl	%edx
 7475 4406 7405     		je	L1330
 7476              		.p2align 4,,7
 7477              	L1334:
 7478 4408 B9160000 		movl	$22, %ecx
 7478      00
 7479              	L1330:
 7480 440d 5B       		popl	%ebx
 7481 440e 89C8     		movl	%ecx, %eax
 7482 4410 5D       		popl	%ebp
 7483 4411 C3       		ret
 7484              		.p2align 4,,7
 7485              	L1343:
 7486 4412 83F803   		cmpl	$3, %eax
 7487 4415 75F1     		jne	L1334
 7488 4417 8D5304   		leal	4(%ebx), %edx
 7489 441a 895508   		movl	%edx, 8(%ebp)
 7490 441d 5B       		popl	%ebx
 7491 441e 5D       		popl	%ebp
 7492 441f E9ECDDFF 		jmp	_pthread_mutex_unlock
 7492      FF
 7493              	L1335:
 7494 4424 31C9     		xorl	%ecx, %ecx
 7495 4426 EBE5     		jmp	L1330
 7496              		.p2align 4,,7
 7497              	L1340:
 7498 4428 89D0     		movl	%edx, %eax
 7499              	/APP
 7500 442a 0FB10B   		cmpxchgl       %ecx,(%ebx)
 7501              	/NO_APP
 7502 442d EBC5     		jmp	L1344
 7503 442f 90       		.p2align 4,,15
 7504              	.globl _pthread_spin_trylock
 7505              		.def	_pthread_spin_trylock;	.scl	2;	.type	32;	.endef
 7506              	_pthread_spin_trylock:
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 157


 7507 4430 55       		pushl	%ebp
 7508 4431 89E5     		movl	%esp, %ebp
 7509 4433 56       		pushl	%esi
 7510 4434 53       		pushl	%ebx
 7511 4435 8B5D08   		movl	8(%ebp), %ebx
 7512 4438 85DB     		testl	%ebx, %ebx
 7513 443a 7436     		je	L1354
 7514 443c 8B33     		movl	(%ebx), %esi
 7515 443e 85F6     		testl	%esi, %esi
 7516 4440 7430     		je	L1354
 7517 4442 83FEFF   		cmpl	$-1, %esi
 7518 4445 7460     		je	L1366
 7519              	L1348:
 7520 4447 8B1D2400 		movl	_ptw32_smp_system, %ebx
 7520      0000
 7521 444d B9020000 		movl	$2, %ecx
 7521      00
 7522 4452 BA010000 		movl	$1, %edx
 7522      00
 7523 4457 85DB     		testl	%ebx, %ebx
 7524 4459 7445     		je	L1360
 7525 445b 89D0     		movl	%edx, %eax
 7526              	/APP
 7527 445d F0       		lock
 7528 445e 0FB10E   		cmpxchgl       %ecx,(%esi)
 7529              	/NO_APP
 7530              	L1365:
 7531 4461 89C2     		movl	%eax, %edx
 7532 4463 83F802   		cmpl	$2, %eax
 7533 4466 742E     		je	L1356
 7534 4468 83F802   		cmpl	$2, %eax
 7535 446b 7F13     		jg	L1363
 7536 446d 31C0     		xorl	%eax, %eax
 7537 446f 4A       		decl	%edx
 7538 4470 7405     		je	L1345
 7539              		.p2align 4,,7
 7540              	L1354:
 7541 4472 B8160000 		movl	$22, %eax
 7541      00
 7542              	L1345:
 7543 4477 8D65F8   		leal	-8(%ebp), %esp
 7544 447a 5B       		popl	%ebx
 7545 447b 5E       		popl	%esi
 7546 447c 5D       		popl	%ebp
 7547 447d C3       		ret
 7548 447e 89F6     		.p2align 4,,7
 7549              	L1363:
 7550 4480 83F803   		cmpl	$3, %eax
 7551 4483 75ED     		jne	L1354
 7552 4485 8D5604   		leal	4(%esi), %edx
 7553 4488 895508   		movl	%edx, 8(%ebp)
 7554 448b 8D65F8   		leal	-8(%ebp), %esp
 7555 448e 5B       		popl	%ebx
 7556 448f 5E       		popl	%esi
 7557 4490 5D       		popl	%ebp
 7558 4491 E94ADEFF 		jmp	_pthread_mutex_trylock
 7558      FF
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 158


 7559              		.p2align 4,,7
 7560              	L1356:
 7561 4496 B8100000 		movl	$16, %eax
 7561      00
 7562 449b EBDA     		jmp	L1345
 7563 449d 8D7600   		.p2align 4,,7
 7564              	L1360:
 7565 44a0 89D0     		movl	%edx, %eax
 7566              	/APP
 7567 44a2 0FB10E   		cmpxchgl       %ecx,(%esi)
 7568              	/NO_APP
 7569 44a5 EBBA     		jmp	L1365
 7570              	L1366:
 7571 44a7 83EC0C   		subl	$12, %esp
 7572 44aa 31F6     		xorl	%esi, %esi
 7573 44ac 68000000 		pushl	$_ptw32_spinlock_test_init_lock
 7573      00
 7574 44b1 E8000000 		call	_EnterCriticalSection@4
 7574      00
 7575 44b6 8B03     		movl	(%ebx), %eax
 7576 44b8 83C40C   		addl	$12, %esp
 7577 44bb 83F8FF   		cmpl	$-1, %eax
 7578 44be 7426     		je	L1367
 7579 44c0 85C0     		testl	%eax, %eax
 7580 44c2 7505     		jne	L1351
 7581 44c4 BE160000 		movl	$22, %esi
 7581      00
 7582              	L1351:
 7583 44c9 83EC0C   		subl	$12, %esp
 7584 44cc 68000000 		pushl	$_ptw32_spinlock_test_init_lock
 7584      00
 7585 44d1 E8000000 		call	_LeaveCriticalSection@4
 7585      00
 7586 44d6 89F0     		movl	%esi, %eax
 7587 44d8 83C40C   		addl	$12, %esp
 7588 44db 85F6     		testl	%esi, %esi
 7589 44dd 7598     		jne	L1345
 7590 44df 8B33     		movl	(%ebx), %esi
 7591 44e1 E961FFFF 		jmp	L1348
 7591      FF
 7592              	L1367:
 7593 44e6 50       		pushl	%eax
 7594 44e7 50       		pushl	%eax
 7595 44e8 6A00     		pushl	$0
 7596 44ea 53       		pushl	%ebx
 7597 44eb E820FCFF 		call	_pthread_spin_init
 7597      FF
 7598 44f0 83C410   		addl	$16, %esp
 7599 44f3 89C6     		movl	%eax, %esi
 7600 44f5 EBD2     		jmp	L1351
 7601 44f7 89F68DBC 		.p2align 4,,15
 7601      27000000 
 7601      00
 7602              	.globl _pthread_detach
 7603              		.def	_pthread_detach;	.scl	2;	.type	32;	.endef
 7604              	_pthread_detach:
 7605 4500 55       		pushl	%ebp
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 159


 7606 4501 89E5     		movl	%esp, %ebp
 7607 4503 57       		pushl	%edi
 7608 4504 56       		pushl	%esi
 7609 4505 53       		pushl	%ebx
 7610 4506 81ECB800 		subl	$184, %esp
 7610      0000
 7611 450c 8B4D08   		movl	8(%ebp), %ecx
 7612 450f 8B450C   		movl	12(%ebp), %eax
 7613 4512 68000000 		pushl	$_ptw32_thread_reuse_lock
 7613      00
 7614 4517 89CE     		movl	%ecx, %esi
 7615 4519 898D50FF 		movl	%ecx, -176(%ebp)
 7615      FFFF
 7616 451f 898554FF 		movl	%eax, -172(%ebp)
 7616      FFFF
 7617 4525 C7854CFF 		movl	$0, -180(%ebp)
 7617      FFFF0000 
 7617      0000
 7618 452f E8000000 		call	_EnterCriticalSection@4
 7618      00
 7619 4534 83C40C   		addl	$12, %esp
 7620 4537 85F6     		testl	%esi, %esi
 7621 4539 740F     		je	L1374
 7622 453b 8B8D54FF 		movl	-172(%ebp), %ecx
 7622      FFFF
 7623 4541 394E0C   		cmpl	%ecx, 12(%esi)
 7624 4544 0F84B600 		je	L1385
 7624      0000
 7625              	L1374:
 7626 454a BB030000 		movl	$3, %ebx
 7626      00
 7627              	L1371:
 7628 454f 83EC0C   		subl	$12, %esp
 7629 4552 68000000 		pushl	$_ptw32_thread_reuse_lock
 7629      00
 7630 4557 E8000000 		call	_LeaveCriticalSection@4
 7630      00
 7631 455c 83C40C   		addl	$12, %esp
 7632 455f 85DB     		testl	%ebx, %ebx
 7633 4561 750A     		jne	L1379
 7634 4563 8BBD4CFF 		movl	-180(%ebp), %edi
 7634      FFFF
 7635 4569 85FF     		testl	%edi, %edi
 7636 456b 750A     		jne	L1386
 7637              	L1379:
 7638 456d 8D65F4   		leal	-12(%ebp), %esp
 7639 4570 89D8     		movl	%ebx, %eax
 7640 4572 5B       		popl	%ebx
 7641 4573 5E       		popl	%esi
 7642 4574 5F       		popl	%edi
 7643 4575 5D       		popl	%ebp
 7644 4576 C3       		ret
 7645              		.p2align 4,,7
 7646              	L1386:
 7647 4577 57       		pushl	%edi
 7648 4578 57       		pushl	%edi
 7649 4579 6AFF     		pushl	$-1
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 160


 7650 457b 8B4604   		movl	4(%esi), %eax
 7651 457e 50       		pushl	%eax
 7652 457f E8000000 		call	_WaitForSingleObject@8
 7652      00
 7653 4584 8BB550FF 		movl	-176(%ebp), %esi
 7653      FFFF
 7654 458a 5A       		popl	%edx
 7655 458b 85F6     		testl	%esi, %esi
 7656 458d 59       		popl	%ecx
 7657 458e 74DD     		je	L1379
 7658 4590 FC       		cld
 7659 4591 8DBD58FF 		leal	-168(%ebp), %edi
 7659      FFFF
 7660 4597 B9230000 		movl	$35, %ecx
 7660      00
 7661 459c F3       		rep
 7662 459d A5       		movsl
 7663 459e 50       		pushl	%eax
 7664 459f 8B8D54FF 		movl	-172(%ebp), %ecx
 7664      FFFF
 7665 45a5 50       		pushl	%eax
 7666 45a6 8BB550FF 		movl	-176(%ebp), %esi
 7666      FFFF
 7667 45ac 51       		pushl	%ecx
 7668 45ad 56       		pushl	%esi
 7669 45ae E83DD5FF 		call	_ptw32_threadReusePush
 7669      FF
 7670 45b3 8B4594   		movl	-108(%ebp), %eax
 7671 45b6 83C410   		addl	$16, %esp
 7672 45b9 85C0     		testl	%eax, %eax
 7673 45bb 7535     		jne	L1387
 7674              	L1382:
 7675 45bd 83EC0C   		subl	$12, %esp
 7676 45c0 8D7D88   		leal	-120(%ebp), %edi
 7677 45c3 57       		pushl	%edi
 7678 45c4 E8A7D6FF 		call	_pthread_mutex_destroy
 7678      FF
 7679 45c9 8D5580   		leal	-128(%ebp), %edx
 7680 45cc 891424   		movl	%edx, (%esp)
 7681 45cf E89CD6FF 		call	_pthread_mutex_destroy
 7681      FF
 7682 45d4 8B855CFF 		movl	-164(%ebp), %eax
 7682      FFFF
 7683 45da 83C410   		addl	$16, %esp
 7684 45dd 85C0     		testl	%eax, %eax
 7685 45df 748C     		je	L1379
 7686 45e1 83EC0C   		subl	$12, %esp
 7687 45e4 50       		pushl	%eax
 7688 45e5 E8000000 		call	_CloseHandle@4
 7688      00
 7689 45ea 83C40C   		addl	$12, %esp
 7690 45ed E97BFFFF 		jmp	L1379
 7690      FF
 7691              	L1387:
 7692 45f2 83EC0C   		subl	$12, %esp
 7693 45f5 50       		pushl	%eax
 7694 45f6 E8000000 		call	_CloseHandle@4
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 161


 7694      00
 7695 45fb 83C40C   		addl	$12, %esp
 7696 45fe EBBD     		jmp	L1382
 7697              		.p2align 4,,7
 7698              	L1385:
 7699 4600 837E2401 		cmpl	$1, 36(%esi)
 7700 4604 744B     		je	L1388
 7701 4606 83EC0C   		subl	$12, %esp
 7702 4609 8D7E30   		leal	48(%esi), %edi
 7703 460c 31DB     		xorl	%ebx, %ebx
 7704 460e 57       		pushl	%edi
 7705 460f E87CD8FF 		call	_pthread_mutex_lock
 7705      FF
 7706 4614 83C410   		addl	$16, %esp
 7707 4617 85C0     		testl	%eax, %eax
 7708 4619 0F852BFF 		jne	L1374
 7708      FFFF
 7709 461f 8B5614   		movl	20(%esi), %edx
 7710 4622 83FA06   		cmpl	$6, %edx
 7711 4625 7418     		je	L1375
 7712 4627 C7462401 		movl	$1, 36(%esi)
 7712      000000
 7713              	L1376:
 7714 462e 83EC0C   		subl	$12, %esp
 7715 4631 57       		pushl	%edi
 7716 4632 E8D9DBFF 		call	_pthread_mutex_unlock
 7716      FF
 7717 4637 83C410   		addl	$16, %esp
 7718 463a E910FFFF 		jmp	L1371
 7718      FF
 7719              	L1375:
 7720 463f 837E2401 		cmpl	$1, 36(%esi)
 7721 4643 74E9     		je	L1376
 7722 4645 C7854CFF 		movl	$1, -180(%ebp)
 7722      FFFF0100 
 7722      0000
 7723 464f EBDD     		jmp	L1376
 7724              		.p2align 4,,7
 7725              	L1388:
 7726 4651 BB160000 		movl	$22, %ebx
 7726      00
 7727 4656 E9F4FEFF 		jmp	L1371
 7727      FF
 7728 465b 908D7426 		.p2align 4,,15
 7728      00
 7729              	.globl _pthread_join
 7730              		.def	_pthread_join;	.scl	2;	.type	32;	.endef
 7731              	_pthread_join:
 7732 4660 55       		pushl	%ebp
 7733 4661 89E5     		movl	%esp, %ebp
 7734 4663 57       		pushl	%edi
 7735 4664 56       		pushl	%esi
 7736 4665 53       		pushl	%ebx
 7737 4666 83EC18   		subl	$24, %esp
 7738 4669 8B7508   		movl	8(%ebp), %esi
 7739 466c 8B7D0C   		movl	12(%ebp), %edi
 7740 466f 68000000 		pushl	$_ptw32_thread_reuse_lock
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 162


 7740      00
 7741 4674 8975F0   		movl	%esi, -16(%ebp)
 7742 4677 E8000000 		call	_EnterCriticalSection@4
 7742      00
 7743 467c 8B55F0   		movl	-16(%ebp), %edx
 7744 467f 83C40C   		addl	$12, %esp
 7745 4682 85D2     		testl	%edx, %edx
 7746 4684 740C     		je	L1391
 7747 4686 8B55F0   		movl	-16(%ebp), %edx
 7748 4689 397A0C   		cmpl	%edi, 12(%edx)
 7749 468c 0F848500 		je	L1390
 7749      0000
 7750              	L1391:
 7751 4692 BB030000 		movl	$3, %ebx
 7751      00
 7752              	L1392:
 7753 4697 83EC0C   		subl	$12, %esp
 7754 469a 68000000 		pushl	$_ptw32_thread_reuse_lock
 7754      00
 7755 469f E8000000 		call	_LeaveCriticalSection@4
 7755      00
 7756 46a4 83C40C   		addl	$12, %esp
 7757 46a7 85DB     		testl	%ebx, %ebx
 7758 46a9 740A     		je	L1403
 7759              	L1395:
 7760 46ab 8D65F4   		leal	-12(%ebp), %esp
 7761 46ae 89D8     		movl	%ebx, %eax
 7762 46b0 5B       		popl	%ebx
 7763 46b1 5E       		popl	%esi
 7764 46b2 5F       		popl	%edi
 7765 46b3 5D       		popl	%ebp
 7766 46b4 C3       		ret
 7767              		.p2align 4,,7
 7768              	L1403:
 7769 46b5 BB020000 		movl	$2, %ebx
 7769      00
 7770 46ba E8F1D1FF 		call	_pthread_self
 7770      FF
 7771 46bf 85C0     		testl	%eax, %eax
 7772 46c1 74E8     		je	L1395
 7773 46c3 57       		pushl	%edi
 7774 46c4 BB240000 		movl	$36, %ebx
 7774      00
 7775 46c9 56       		pushl	%esi
 7776 46ca 52       		pushl	%edx
 7777 46cb 50       		pushl	%eax
 7778 46cc E89FD2FF 		call	_pthread_equal
 7778      FF
 7779 46d1 83C410   		addl	$16, %esp
 7780 46d4 85C0     		testl	%eax, %eax
 7781 46d6 75D3     		jne	L1395
 7782 46d8 8B4DF0   		movl	-16(%ebp), %ecx
 7783 46db 83EC0C   		subl	$12, %esp
 7784 46de 8B5904   		movl	4(%ecx), %ebx
 7785 46e1 53       		pushl	%ebx
 7786 46e2 E899D4FF 		call	_pthreadCancelableWait
 7786      FF
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 163


 7787 46e7 83C410   		addl	$16, %esp
 7788 46ea 85C0     		testl	%eax, %eax
 7789 46ec 7522     		jne	L1400
 7790 46ee 8B5510   		movl	16(%ebp), %edx
 7791 46f1 85D2     		testl	%edx, %edx
 7792 46f3 740B     		je	L1401
 7793 46f5 8B45F0   		movl	-16(%ebp), %eax
 7794 46f8 8B5D10   		movl	16(%ebp), %ebx
 7795 46fb 8B4818   		movl	24(%eax), %ecx
 7796 46fe 890B     		movl	%ecx, (%ebx)
 7797              	L1401:
 7798 4700 50       		pushl	%eax
 7799 4701 50       		pushl	%eax
 7800 4702 57       		pushl	%edi
 7801 4703 56       		pushl	%esi
 7802 4704 E8F7FDFF 		call	_pthread_detach
 7802      FF
 7803 4709 83C410   		addl	$16, %esp
 7804 470c 89C3     		movl	%eax, %ebx
 7805 470e EB9B     		jmp	L1395
 7806              	L1400:
 7807 4710 BB030000 		movl	$3, %ebx
 7807      00
 7808 4715 EB94     		jmp	L1395
 7809              		.p2align 4,,7
 7810              	L1390:
 7811 4717 8B45F0   		movl	-16(%ebp), %eax
 7812 471a 83782401 		cmpl	$1, 36(%eax)
 7813 471e 0F94C1   		sete	%cl
 7814 4721 31DB     		xorl	%ebx, %ebx
 7815 4723 88CB     		movb	%cl, %bl
 7816 4725 4B       		decl	%ebx
 7817 4726 83E3EA   		andl	$-22, %ebx
 7818 4729 83C316   		addl	$22, %ebx
 7819 472c E966FFFF 		jmp	L1392
 7819      FF
 7820 4731 EB0D9090 		.p2align 4,,15
 7820      90909090 
 7820      90909090 
 7820      909090
 7821              	.globl _pthread_key_create
 7822              		.def	_pthread_key_create;	.scl	2;	.type	32;	.endef
 7823              	_pthread_key_create:
 7824 4740 55       		pushl	%ebp
 7825 4741 89E5     		movl	%esp, %ebp
 7826 4743 57       		pushl	%edi
 7827 4744 56       		pushl	%esi
 7828 4745 31F6     		xorl	%esi, %esi
 7829 4747 53       		pushl	%ebx
 7830 4748 83EC14   		subl	$20, %esp
 7831 474b 8B7D0C   		movl	12(%ebp), %edi
 7832 474e 6A10     		pushl	$16
 7833 4750 6A01     		pushl	$1
 7834 4752 E8000000 		call	_calloc
 7834      00
 7835 4757 83C410   		addl	$16, %esp
 7836 475a 89C3     		movl	%eax, %ebx
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 164


 7837 475c 85C0     		testl	%eax, %eax
 7838 475e 7440     		je	L1410
 7839 4760 E8000000 		call	_TlsAlloc@0
 7839      00
 7840 4765 8903     		movl	%eax, (%ebx)
 7841 4767 40       		incl	%eax
 7842 4768 741D     		je	L1411
 7843 476a 85FF     		testl	%edi, %edi
 7844 476c 740A     		je	L1406
 7845 476e C74308FF 		movl	$-1, 8(%ebx)
 7845      FFFFFF
 7846 4775 897B04   		movl	%edi, 4(%ebx)
 7847              	L1406:
 7848 4778 8B5508   		movl	8(%ebp), %edx
 7849 477b 89F0     		movl	%esi, %eax
 7850 477d 891A     		movl	%ebx, (%edx)
 7851 477f 8D65F4   		leal	-12(%ebp), %esp
 7852 4782 5B       		popl	%ebx
 7853 4783 5E       		popl	%esi
 7854 4784 5F       		popl	%edi
 7855 4785 5D       		popl	%ebp
 7856 4786 C3       		ret
 7857              	L1411:
 7858 4787 83EC0C   		subl	$12, %esp
 7859 478a BE0B0000 		movl	$11, %esi
 7859      00
 7860 478f 53       		pushl	%ebx
 7861 4790 31DB     		xorl	%ebx, %ebx
 7862 4792 E8000000 		call	_free
 7862      00
 7863 4797 83C410   		addl	$16, %esp
 7864 479a EBDC     		jmp	L1406
 7865 479c 8D742600 		.p2align 4,,7
 7866              	L1410:
 7867 47a0 BE0C0000 		movl	$12, %esi
 7867      00
 7868 47a5 EBD1     		jmp	L1406
 7869 47a7 89F68DBC 		.p2align 4,,15
 7869      27000000 
 7869      00
 7870              	.globl _pthread_key_delete
 7871              		.def	_pthread_key_delete;	.scl	2;	.type	32;	.endef
 7872              	_pthread_key_delete:
 7873 47b0 55       		pushl	%ebp
 7874 47b1 89E5     		movl	%esp, %ebp
 7875 47b3 57       		pushl	%edi
 7876 47b4 56       		pushl	%esi
 7877 47b5 53       		pushl	%ebx
 7878 47b6 83EC0C   		subl	$12, %esp
 7879 47b9 8B7508   		movl	8(%ebp), %esi
 7880 47bc 85F6     		testl	%esi, %esi
 7881 47be 7452     		je	L1413
 7882 47c0 8B460C   		movl	12(%esi), %eax
 7883 47c3 85C0     		testl	%eax, %eax
 7884 47c5 7407     		je	L1414
 7885 47c7 8B4604   		movl	4(%esi), %eax
 7886 47ca 85C0     		testl	%eax, %eax
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 165


 7887 47cc 754E     		jne	L1429
 7888              	L1414:
 7889 47ce 83EC0C   		subl	$12, %esp
 7890 47d1 8B3E     		movl	(%esi), %edi
 7891 47d3 57       		pushl	%edi
 7892 47d4 E8000000 		call	_TlsFree@4
 7892      00
 7893 47d9 8B4E04   		movl	4(%esi), %ecx
 7894 47dc 83C40C   		addl	$12, %esp
 7895 47df 85C9     		testl	%ecx, %ecx
 7896 47e1 7423     		je	L1422
 7897 47e3 8D5E08   		leal	8(%esi), %ebx
 7898              		.p2align 4,,7
 7899              	L1423:
 7900 47e6 83EC0C   		subl	$12, %esp
 7901 47e9 53       		pushl	%ebx
 7902 47ea E881D4FF 		call	_pthread_mutex_destroy
 7902      FF
 7903 47ef 83C410   		addl	$16, %esp
 7904 47f2 83F810   		cmpl	$16, %eax
 7905 47f5 750F     		jne	L1422
 7906 47f7 83EC0C   		subl	$12, %esp
 7907 47fa 6A01     		pushl	$1
 7908 47fc E8000000 		call	_Sleep@4
 7908      00
 7909 4801 83C40C   		addl	$12, %esp
 7910 4804 EBE0     		jmp	L1423
 7911              		.p2align 4,,7
 7912              	L1422:
 7913 4806 83EC0C   		subl	$12, %esp
 7914 4809 56       		pushl	%esi
 7915 480a E8000000 		call	_free
 7915      00
 7916 480f 83C410   		addl	$16, %esp
 7917              	L1413:
 7918 4812 8D65F4   		leal	-12(%ebp), %esp
 7919 4815 31C0     		xorl	%eax, %eax
 7920 4817 5B       		popl	%ebx
 7921 4818 5E       		popl	%esi
 7922 4819 5F       		popl	%edi
 7923 481a 5D       		popl	%ebp
 7924 481b C3       		ret
 7925              	L1429:
 7926 481c 83EC0C   		subl	$12, %esp
 7927 481f 8D5608   		leal	8(%esi), %edx
 7928 4822 8955F0   		movl	%edx, -16(%ebp)
 7929 4825 52       		pushl	%edx
 7930 4826 E865D6FF 		call	_pthread_mutex_lock
 7930      FF
 7931 482b 83C410   		addl	$16, %esp
 7932 482e 85C0     		testl	%eax, %eax
 7933 4830 759C     		jne	L1414
 7934 4832 8B5E0C   		movl	12(%esi), %ebx
 7935 4835 85DB     		testl	%ebx, %ebx
 7936 4837 7437     		je	L1416
 7937 4839 8DB42600 		.p2align 4,,7
 7937      000000
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 166


 7938              	L1421:
 7939 4840 83EC0C   		subl	$12, %esp
 7940 4843 8B3B     		movl	(%ebx), %edi
 7941 4845 83C728   		addl	$40, %edi
 7942 4848 57       		pushl	%edi
 7943 4849 E842D6FF 		call	_pthread_mutex_lock
 7943      FF
 7944 484e 83C410   		addl	$16, %esp
 7945 4851 85C0     		testl	%eax, %eax
 7946 4853 752F     		jne	L1419
 7947 4855 83EC0C   		subl	$12, %esp
 7948 4858 53       		pushl	%ebx
 7949 4859 E832B9FF 		call	_ptw32_tkAssocDestroy
 7949      FF
 7950 485e 893C24   		movl	%edi, (%esp)
 7951 4861 E8AAD9FF 		call	_pthread_mutex_unlock
 7951      FF
 7952              	L1428:
 7953 4866 8B5E0C   		movl	12(%esi), %ebx
 7954 4869 83C410   		addl	$16, %esp
 7955 486c 85DB     		testl	%ebx, %ebx
 7956 486e 75D0     		jne	L1421
 7957              	L1416:
 7958 4870 83EC0C   		subl	$12, %esp
 7959 4873 8B5DF0   		movl	-16(%ebp), %ebx
 7960 4876 53       		pushl	%ebx
 7961 4877 E894D9FF 		call	_pthread_mutex_unlock
 7961      FF
 7962 487c 83C410   		addl	$16, %esp
 7963 487f E94AFFFF 		jmp	L1414
 7963      FF
 7964              	L1419:
 7965 4884 83EC0C   		subl	$12, %esp
 7966 4887 53       		pushl	%ebx
 7967 4888 E803B9FF 		call	_ptw32_tkAssocDestroy
 7967      FF
 7968 488d EBD7     		jmp	L1428
 7969 488f 90       		.p2align 4,,15
 7970              	.globl _pthread_setspecific
 7971              		.def	_pthread_setspecific;	.scl	2;	.type	32;	.endef
 7972              	_pthread_setspecific:
 7973 4890 55       		pushl	%ebp
 7974 4891 89E5     		movl	%esp, %ebp
 7975 4893 57       		pushl	%edi
 7976 4894 56       		pushl	%esi
 7977 4895 53       		pushl	%ebx
 7978 4896 83EC0C   		subl	$12, %esp
 7979 4899 8B7D08   		movl	8(%ebp), %edi
 7980 489c 3B3D0C00 		cmpl	_ptw32_selfThreadKey, %edi
 7980      0000
 7981 48a2 0F841801 		je	L1431
 7981      0000
 7982 48a8 E803D0FF 		call	_pthread_self
 7982      FF
 7983 48ad 89C3     		movl	%eax, %ebx
 7984 48af B8020000 		movl	$2, %eax
 7984      00
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 167


 7985 48b4 85DB     		testl	%ebx, %ebx
 7986 48b6 7452     		je	L1430
 7987              	L1433:
 7988 48b8 C745F000 		movl	$0, -16(%ebp)
 7988      000000
 7989 48bf 85FF     		testl	%edi, %edi
 7990 48c1 7444     		je	L1437
 7991 48c3 85DB     		testl	%ebx, %ebx
 7992 48c5 7439     		je	L1438
 7993 48c7 8B4F04   		movl	4(%edi), %ecx
 7994 48ca 85C9     		testl	%ecx, %ecx
 7995 48cc 7432     		je	L1438
 7996 48ce 8B750C   		movl	12(%ebp), %esi
 7997 48d1 85F6     		testl	%esi, %esi
 7998 48d3 742B     		je	L1438
 7999 48d5 83EC0C   		subl	$12, %esp
 8000 48d8 8D5708   		leal	8(%edi), %edx
 8001 48db 8955EC   		movl	%edx, -20(%ebp)
 8002 48de 52       		pushl	%edx
 8003 48df E8ACD5FF 		call	_pthread_mutex_lock
 8003      FF
 8004 48e4 83C410   		addl	$16, %esp
 8005 48e7 85C0     		testl	%eax, %eax
 8006 48e9 7444     		je	L1454
 8007              	L1439:
 8008 48eb 83EC0C   		subl	$12, %esp
 8009 48ee 8B5DEC   		movl	-20(%ebp), %ebx
 8010 48f1 53       		pushl	%ebx
 8011 48f2 E819D9FF 		call	_pthread_mutex_unlock
 8011      FF
 8012 48f7 83C410   		addl	$16, %esp
 8013 48fa 8DB60000 		.p2align 4,,7
 8013      0000
 8014              	L1438:
 8015 4900 8B4DF0   		movl	-16(%ebp), %ecx
 8016 4903 85C9     		testl	%ecx, %ecx
 8017 4905 740B     		je	L1455
 8018              	L1437:
 8019 4907 8B45F0   		movl	-16(%ebp), %eax
 8020              	L1430:
 8021 490a 8D65F4   		leal	-12(%ebp), %esp
 8022 490d 5B       		popl	%ebx
 8023 490e 5E       		popl	%esi
 8024 490f 5F       		popl	%edi
 8025 4910 5D       		popl	%ebp
 8026 4911 C3       		ret
 8027              		.p2align 4,,7
 8028              	L1455:
 8029 4912 8B550C   		movl	12(%ebp), %edx
 8030 4915 50       		pushl	%eax
 8031 4916 50       		pushl	%eax
 8032 4917 52       		pushl	%edx
 8033 4918 8B07     		movl	(%edi), %eax
 8034 491a 50       		pushl	%eax
 8035 491b E8000000 		call	_TlsSetValue@8
 8035      00
 8036 4920 5A       		popl	%edx
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 168


 8037 4921 85C0     		testl	%eax, %eax
 8038 4923 59       		popl	%ecx
 8039 4924 75E1     		jne	L1437
 8040 4926 C745F00B 		movl	$11, -16(%ebp)
 8040      000000
 8041 492d EBD8     		jmp	L1437
 8042              	L1454:
 8043 492f 83EC0C   		subl	$12, %esp
 8044 4932 8D7328   		leal	40(%ebx), %esi
 8045 4935 56       		pushl	%esi
 8046 4936 E855D5FF 		call	_pthread_mutex_lock
 8046      FF
 8047 493b 83C410   		addl	$16, %esp
 8048 493e 8B838400 		movl	132(%ebx), %eax
 8048      0000
 8049 4944 85C0     		testl	%eax, %eax
 8050 4946 740C     		je	L1453
 8051              		.p2align 4,,7
 8052              	L1444:
 8053 4948 397804   		cmpl	%edi, 4(%eax)
 8054 494b 746D     		je	L1441
 8055 494d 8B4008   		movl	8(%eax), %eax
 8056 4950 85C0     		testl	%eax, %eax
 8057 4952 75F4     		jne	L1444
 8058              	L1453:
 8059 4954 50       		pushl	%eax
 8060 4955 50       		pushl	%eax
 8061 4956 6A18     		pushl	$24
 8062 4958 6A01     		pushl	$1
 8063 495a E8000000 		call	_calloc
 8063      00
 8064 495f BA0C0000 		movl	$12, %edx
 8064      00
 8065 4964 83C410   		addl	$16, %esp
 8066 4967 85C0     		testl	%eax, %eax
 8067 4969 743B     		je	L1447
 8068 496b 8B570C   		movl	12(%edi), %edx
 8069 496e 8918     		movl	%ebx, (%eax)
 8070 4970 897804   		movl	%edi, 4(%eax)
 8071 4973 89500C   		movl	%edx, 12(%eax)
 8072 4976 C7401400 		movl	$0, 20(%eax)
 8072      000000
 8073 497d 85D2     		testl	%edx, %edx
 8074 497f 7403     		je	L1448
 8075 4981 894214   		movl	%eax, 20(%edx)
 8076              	L1448:
 8077 4984 89470C   		movl	%eax, 12(%edi)
 8078 4987 8B938400 		movl	132(%ebx), %edx
 8078      0000
 8079 498d C7401000 		movl	$0, 16(%eax)
 8079      000000
 8080 4994 895008   		movl	%edx, 8(%eax)
 8081 4997 85D2     		testl	%edx, %edx
 8082 4999 7403     		je	L1449
 8083 499b 894210   		movl	%eax, 16(%edx)
 8084              	L1449:
 8085 499e 89838400 		movl	%eax, 132(%ebx)
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 169


 8085      0000
 8086 49a4 31D2     		xorl	%edx, %edx
 8087              	L1447:
 8088 49a6 8955F0   		movl	%edx, -16(%ebp)
 8089              	L1445:
 8090 49a9 83EC0C   		subl	$12, %esp
 8091 49ac 56       		pushl	%esi
 8092 49ad E85ED8FF 		call	_pthread_mutex_unlock
 8092      FF
 8093 49b2 83C410   		addl	$16, %esp
 8094 49b5 E931FFFF 		jmp	L1439
 8094      FF
 8095              	L1441:
 8096 49ba 85C0     		testl	%eax, %eax
 8097 49bc 75EB     		jne	L1445
 8098 49be EB94     		jmp	L1453
 8099              		.p2align 4,,7
 8100              	L1431:
 8101 49c0 83EC0C   		subl	$12, %esp
 8102 49c3 57       		pushl	%edi
 8103 49c4 E8370000 		call	_pthread_getspecific
 8103      00
 8104 49c9 83C410   		addl	$16, %esp
 8105 49cc 85C0     		testl	%eax, %eax
 8106 49ce 7408     		je	L1456
 8107 49d0 8B5808   		movl	8(%eax), %ebx
 8108 49d3 E9E0FEFF 		jmp	L1433
 8108      FF
 8109              	L1456:
 8110 49d8 8B4D0C   		movl	12(%ebp), %ecx
 8111 49db B8020000 		movl	$2, %eax
 8111      00
 8112 49e0 85C9     		testl	%ecx, %ecx
 8113 49e2 0F8422FF 		je	L1430
 8113      FFFF
 8114 49e8 8B550C   		movl	12(%ebp), %edx
 8115 49eb 8B1A     		movl	(%edx), %ebx
 8116 49ed E9C6FEFF 		jmp	L1433
 8116      FF
 8117 49f2 8DB42600 		.p2align 4,,15
 8117      0000008D 
 8117      BC270000 
 8117      0000
 8118              	.globl _pthread_getspecific
 8119              		.def	_pthread_getspecific;	.scl	2;	.type	32;	.endef
 8120              	_pthread_getspecific:
 8121 4a00 55       		pushl	%ebp
 8122 4a01 89E5     		movl	%esp, %ebp
 8123 4a03 57       		pushl	%edi
 8124 4a04 56       		pushl	%esi
 8125 4a05 53       		pushl	%ebx
 8126 4a06 83EC0C   		subl	$12, %esp
 8127 4a09 8B7D08   		movl	8(%ebp), %edi
 8128 4a0c C745F000 		movl	$0, -16(%ebp)
 8128      000000
 8129 4a13 85FF     		testl	%edi, %edi
 8130 4a15 742B     		je	L1459
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 170


 8131 4a17 E8000000 		call	_GetLastError@0
 8131      00
 8132 4a1c 89C3     		movl	%eax, %ebx
 8133 4a1e E8000000 		call	_WSAGetLastError@0
 8133      00
 8134 4a23 83EC0C   		subl	$12, %esp
 8135 4a26 89C6     		movl	%eax, %esi
 8136 4a28 8B07     		movl	(%edi), %eax
 8137 4a2a 50       		pushl	%eax
 8138 4a2b E8000000 		call	_TlsGetValue@4
 8138      00
 8139 4a30 53       		pushl	%ebx
 8140 4a31 8945F0   		movl	%eax, -16(%ebp)
 8141 4a34 E8000000 		call	_SetLastError@4
 8141      00
 8142 4a39 56       		pushl	%esi
 8143 4a3a E8000000 		call	_WSASetLastError@4
 8143      00
 8144 4a3f 83C40C   		addl	$12, %esp
 8145              	L1459:
 8146 4a42 8B45F0   		movl	-16(%ebp), %eax
 8147 4a45 8D65F4   		leal	-12(%ebp), %esp
 8148 4a48 5B       		popl	%ebx
 8149 4a49 5E       		popl	%esi
 8150 4a4a 5F       		popl	%edi
 8151 4a4b 5D       		popl	%ebp
 8152 4a4c C3       		ret
 8153 4a4d 8D7600   		.p2align 4,,15
 8154              	.globl _ptw32_InterlockedCompareExchange@12
 8155              		.def	_ptw32_InterlockedCompareExchange@12;	.scl	2;	.type	32;	.endef
 8156              	_ptw32_InterlockedCompareExchange@12:
 8157 4a50 55       		pushl	%ebp
 8158 4a51 89E5     		movl	%esp, %ebp
 8159 4a53 833D2400 		cmpl	$0, _ptw32_smp_system
 8159      000000
 8160 4a5a 8B4D08   		movl	8(%ebp), %ecx
 8161 4a5d 8B550C   		movl	12(%ebp), %edx
 8162 4a60 8B4510   		movl	16(%ebp), %eax
 8163 4a63 740B     		je	L1477
 8164              	/APP
 8165 4a65 F0       		lock
 8166 4a66 0FB111   		cmpxchgl       %edx,(%ecx)
 8167              	/NO_APP
 8168              	L1478:
 8169 4a69 5D       		popl	%ebp
 8170 4a6a C20C00   		ret	$12
 8171 4a6d 8D7600   		.p2align 4,,7
 8172              	L1477:
 8173              	/APP
 8174 4a70 0FB111   		cmpxchgl       %edx,(%ecx)
 8175              	/NO_APP
 8176 4a73 EBF4     		jmp	L1478
 8177 4a75 8D742600 		.p2align 4,,15
 8177      8DBC2700 
 8177      000000
 8178              	.globl _ptw32_InterlockedExchange@8
 8179              		.def	_ptw32_InterlockedExchange@8;	.scl	2;	.type	32;	.endef
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 171


 8180              	_ptw32_InterlockedExchange@8:
 8181 4a80 55       		pushl	%ebp
 8182 4a81 8B0D2400 		movl	_ptw32_smp_system, %ecx
 8182      0000
 8183 4a87 89E5     		movl	%esp, %ebp
 8184 4a89 85C9     		testl	%ecx, %ecx
 8185 4a8b 8B5508   		movl	8(%ebp), %edx
 8186 4a8e 8B450C   		movl	12(%ebp), %eax
 8187 4a91 740D     		je	L1480
 8188              	/APP
 8189 4a93 8702     		xchgl          %eax,(%edx)
 8190              	/NO_APP
 8191              	L1481:
 8192 4a95 5D       		popl	%ebp
 8193 4a96 C20800   		ret	$8
 8194 4a99 8DB42600 		.p2align 4,,7
 8194      000000
 8195              	L1480:
 8196 4aa0 89C1     		movl	%eax, %ecx
 8197              	/APP
 8198              		0:
 8199 4aa2 8B02     		movl           (%edx),%eax
 8200 4aa4 0FB10A   		cmpxchgl       %ecx,(%edx)
 8201 4aa7 75F9     		jnz            0b
 8202              	/NO_APP
 8203 4aa9 EBEA     		jmp	L1481
 8204 4aab 908D7426 		.p2align 4,,15
 8204      00
 8205              	.globl _ptw32_mcs_flag_set
 8206              		.def	_ptw32_mcs_flag_set;	.scl	2;	.type	32;	.endef
 8207              	_ptw32_mcs_flag_set:
 8208 4ab0 55       		pushl	%ebp
 8209 4ab1 83CAFF   		orl	$-1, %edx
 8210 4ab4 89E5     		movl	%esp, %ebp
 8211 4ab6 56       		pushl	%esi
 8212 4ab7 8B352400 		movl	_ptw32_smp_system, %esi
 8212      0000
 8213 4abd 53       		pushl	%ebx
 8214 4abe 8B4D08   		movl	8(%ebp), %ecx
 8215 4ac1 31DB     		xorl	%ebx, %ebx
 8216 4ac3 85F6     		testl	%esi, %esi
 8217 4ac5 741F     		je	L1483
 8218 4ac7 89D8     		movl	%ebx, %eax
 8219              	/APP
 8220 4ac9 F0       		lock
 8221 4aca 0FB111   		cmpxchgl       %edx,(%ecx)
 8222              	/NO_APP
 8223              	L1487:
 8224 4acd 85C0     		testl	%eax, %eax
 8225 4acf 7507     		jne	L1488
 8226              	L1482:
 8227 4ad1 8D65F8   		leal	-8(%ebp), %esp
 8228 4ad4 5B       		popl	%ebx
 8229 4ad5 5E       		popl	%esi
 8230 4ad6 5D       		popl	%ebp
 8231 4ad7 C3       		ret
 8232              		.p2align 4,,7
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 172


 8233              	L1488:
 8234 4ad8 83EC0C   		subl	$12, %esp
 8235 4adb 50       		pushl	%eax
 8236 4adc E8000000 		call	_SetEvent@4
 8236      00
 8237 4ae1 83C40C   		addl	$12, %esp
 8238 4ae4 EBEB     		jmp	L1482
 8239              		.p2align 4,,7
 8240              	L1483:
 8241 4ae6 89F0     		movl	%esi, %eax
 8242              	/APP
 8243 4ae8 0FB111   		cmpxchgl       %edx,(%ecx)
 8244              	/NO_APP
 8245 4aeb EBE0     		jmp	L1487
 8246 4aed 8D7600   		.p2align 4,,15
 8247              	.globl _ptw32_mcs_flag_wait
 8248              		.def	_ptw32_mcs_flag_wait;	.scl	2;	.type	32;	.endef
 8249              	_ptw32_mcs_flag_wait:
 8250 4af0 55       		pushl	%ebp
 8251 4af1 89E5     		movl	%esp, %ebp
 8252 4af3 57       		pushl	%edi
 8253 4af4 56       		pushl	%esi
 8254 4af5 53       		pushl	%ebx
 8255 4af6 83EC14   		subl	$20, %esp
 8256 4af9 8B7D08   		movl	8(%ebp), %edi
 8257 4afc 6A00     		pushl	$0
 8258 4afe 57       		pushl	%edi
 8259 4aff E8000000 		call	_InterlockedExchangeAdd@8
 8259      00
 8260 4b04 89C3     		movl	%eax, %ebx
 8261 4b06 58       		popl	%eax
 8262 4b07 5A       		popl	%edx
 8263 4b08 85DB     		testl	%ebx, %ebx
 8264 4b0a 7408     		je	L1496
 8265              	L1489:
 8266 4b0c 8D65F4   		leal	-12(%ebp), %esp
 8267 4b0f 5B       		popl	%ebx
 8268 4b10 5E       		popl	%esi
 8269 4b11 5F       		popl	%edi
 8270 4b12 5D       		popl	%ebp
 8271 4b13 C3       		ret
 8272              		.p2align 4,,7
 8273              	L1496:
 8274 4b14 6A00     		pushl	$0
 8275 4b16 6A00     		pushl	$0
 8276 4b18 6A00     		pushl	$0
 8277 4b1a 6A00     		pushl	$0
 8278 4b1c E8000000 		call	_CreateEventA@16
 8278      00
 8279 4b21 8B152400 		movl	_ptw32_smp_system, %edx
 8279      0000
 8280 4b27 89C6     		movl	%eax, %esi
 8281 4b29 85D2     		testl	%edx, %edx
 8282 4b2b 7426     		je	L1492
 8283 4b2d 89D8     		movl	%ebx, %eax
 8284              	/APP
 8285 4b2f F0       		lock
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 173


 8286 4b30 0FB137   		cmpxchgl       %esi,(%edi)
 8287              	/NO_APP
 8288              	L1495:
 8289 4b33 85C0     		testl	%eax, %eax
 8290 4b35 740E     		je	L1497
 8291              	L1491:
 8292 4b37 83EC0C   		subl	$12, %esp
 8293 4b3a 56       		pushl	%esi
 8294 4b3b E8000000 		call	_CloseHandle@4
 8294      00
 8295 4b40 83C40C   		addl	$12, %esp
 8296 4b43 EBC7     		jmp	L1489
 8297              	L1497:
 8298 4b45 50       		pushl	%eax
 8299 4b46 50       		pushl	%eax
 8300 4b47 6AFF     		pushl	$-1
 8301 4b49 56       		pushl	%esi
 8302 4b4a E8000000 		call	_WaitForSingleObject@8
 8302      00
 8303 4b4f 5B       		popl	%ebx
 8304 4b50 5F       		popl	%edi
 8305 4b51 EBE4     		jmp	L1491
 8306              		.p2align 4,,7
 8307              	L1492:
 8308 4b53 89D0     		movl	%edx, %eax
 8309              	/APP
 8310 4b55 0FB137   		cmpxchgl       %esi,(%edi)
 8311              	/NO_APP
 8312 4b58 EBD9     		jmp	L1495
 8313 4b5a 8DB60000 		.p2align 4,,15
 8313      0000
 8314              	.globl _ptw32_mcs_lock_acquire
 8315              		.def	_ptw32_mcs_lock_acquire;	.scl	2;	.type	32;	.endef
 8316              	_ptw32_mcs_lock_acquire:
 8317 4b60 55       		pushl	%ebp
 8318 4b61 89E5     		movl	%esp, %ebp
 8319 4b63 57       		pushl	%edi
 8320 4b64 56       		pushl	%esi
 8321 4b65 53       		pushl	%ebx
 8322 4b66 83EC0C   		subl	$12, %esp
 8323 4b69 8B5D0C   		movl	12(%ebp), %ebx
 8324 4b6c 8B7508   		movl	8(%ebp), %esi
 8325 4b6f 8B152400 		movl	_ptw32_smp_system, %edx
 8325      0000
 8326 4b75 8933     		movl	%esi, (%ebx)
 8327 4b77 85D2     		testl	%edx, %edx
 8328 4b79 C7430C00 		movl	$0, 12(%ebx)
 8328      000000
 8329 4b80 C7430800 		movl	$0, 8(%ebx)
 8329      000000
 8330 4b87 C7430400 		movl	$0, 4(%ebx)
 8330      000000
 8331 4b8e 0F84AC00 		je	L1499
 8331      0000
 8332 4b94 89DF     		movl	%ebx, %edi
 8333              	/APP
 8334 4b96 873E     		xchgl          %edi,(%esi)
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 174


 8335              	/NO_APP
 8336              	L1500:
 8337 4b98 85FF     		testl	%edi, %edi
 8338 4b9a 7430     		je	L1498
 8339 4b9c 83C9FF   		orl	$-1, %ecx
 8340 4b9f 31F6     		xorl	%esi, %esi
 8341 4ba1 895F04   		movl	%ebx, 4(%edi)
 8342 4ba4 85D2     		testl	%edx, %edx
 8343 4ba6 0F848400 		je	L1503
 8343      0000
 8344 4bac 89F0     		movl	%esi, %eax
 8345              	/APP
 8346 4bae F0       		lock
 8347 4baf 0FB14F0C 		cmpxchgl       %ecx,12(%edi)
 8348              	/NO_APP
 8349              	L1514:
 8350 4bb3 85C0     		testl	%eax, %eax
 8351 4bb5 7569     		jne	L1516
 8352              	L1507:
 8353 4bb7 8D5308   		leal	8(%ebx), %edx
 8354 4bba 51       		pushl	%ecx
 8355 4bbb 51       		pushl	%ecx
 8356 4bbc 6A00     		pushl	$0
 8357 4bbe 52       		pushl	%edx
 8358 4bbf E8000000 		call	_InterlockedExchangeAdd@8
 8358      00
 8359 4bc4 5F       		popl	%edi
 8360 4bc5 89C6     		movl	%eax, %esi
 8361 4bc7 5A       		popl	%edx
 8362 4bc8 85C0     		testl	%eax, %eax
 8363 4bca 7408     		je	L1517
 8364              	L1498:
 8365 4bcc 8D65F4   		leal	-12(%ebp), %esp
 8366 4bcf 5B       		popl	%ebx
 8367 4bd0 5E       		popl	%esi
 8368 4bd1 5F       		popl	%edi
 8369 4bd2 5D       		popl	%ebp
 8370 4bd3 C3       		ret
 8371              		.p2align 4,,7
 8372              	L1517:
 8373 4bd4 6A00     		pushl	$0
 8374 4bd6 6A00     		pushl	$0
 8375 4bd8 6A00     		pushl	$0
 8376 4bda 6A00     		pushl	$0
 8377 4bdc E8000000 		call	_CreateEventA@16
 8377      00
 8378 4be1 8B152400 		movl	_ptw32_smp_system, %edx
 8378      0000
 8379 4be7 89C7     		movl	%eax, %edi
 8380 4be9 85D2     		testl	%edx, %edx
 8381 4beb 7427     		je	L1510
 8382 4bed 89F0     		movl	%esi, %eax
 8383              	/APP
 8384 4bef F0       		lock
 8385 4bf0 0FB17B08 		cmpxchgl       %edi,8(%ebx)
 8386              	/NO_APP
 8387              	L1515:
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 175


 8388 4bf4 85C0     		testl	%eax, %eax
 8389 4bf6 740E     		je	L1518
 8390              	L1509:
 8391 4bf8 83EC0C   		subl	$12, %esp
 8392 4bfb 57       		pushl	%edi
 8393 4bfc E8000000 		call	_CloseHandle@4
 8393      00
 8394 4c01 83C40C   		addl	$12, %esp
 8395 4c04 EBC6     		jmp	L1498
 8396              	L1518:
 8397 4c06 56       		pushl	%esi
 8398 4c07 56       		pushl	%esi
 8399 4c08 6AFF     		pushl	$-1
 8400 4c0a 57       		pushl	%edi
 8401 4c0b E8000000 		call	_WaitForSingleObject@8
 8401      00
 8402 4c10 59       		popl	%ecx
 8403 4c11 5B       		popl	%ebx
 8404 4c12 EBE4     		jmp	L1509
 8405              	L1510:
 8406 4c14 89D0     		movl	%edx, %eax
 8407              	/APP
 8408 4c16 0FB17B08 		cmpxchgl       %edi,8(%ebx)
 8409              	/NO_APP
 8410 4c1a EBD8     		jmp	L1515
 8411 4c1c 8D742600 		.p2align 4,,7
 8412              	L1516:
 8413 4c20 83EC0C   		subl	$12, %esp
 8414 4c23 50       		pushl	%eax
 8415 4c24 E8000000 		call	_SetEvent@4
 8415      00
 8416 4c29 83C40C   		addl	$12, %esp
 8417 4c2c EB89     		jmp	L1507
 8418 4c2e 89F6     		.p2align 4,,7
 8419              	L1503:
 8420 4c30 89D0     		movl	%edx, %eax
 8421              	/APP
 8422 4c32 0FB14F0C 		cmpxchgl       %ecx,12(%edi)
 8423              	/NO_APP
 8424 4c36 E978FFFF 		jmp	L1514
 8424      FF
 8425 4c3b 908D7426 		.p2align 4,,7
 8425      00
 8426              	L1499:
 8427              	/APP
 8428              		0:
 8429 4c40 8B06     		movl           (%esi),%eax
 8430 4c42 0FB11E   		cmpxchgl       %ebx,(%esi)
 8431 4c45 75F9     		jnz            0b
 8432              	/NO_APP
 8433 4c47 89C7     		movl	%eax, %edi
 8434 4c49 E94AFFFF 		jmp	L1500
 8434      FF
 8435 4c4e 89F6     		.p2align 4,,15
 8436              	.globl _ptw32_mcs_lock_release
 8437              		.def	_ptw32_mcs_lock_release;	.scl	2;	.type	32;	.endef
 8438              	_ptw32_mcs_lock_release:
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 176


 8439 4c50 55       		pushl	%ebp
 8440 4c51 89E5     		movl	%esp, %ebp
 8441 4c53 57       		pushl	%edi
 8442 4c54 56       		pushl	%esi
 8443 4c55 53       		pushl	%ebx
 8444 4c56 83EC14   		subl	$20, %esp
 8445 4c59 8B5D08   		movl	8(%ebp), %ebx
 8446 4c5c 8B33     		movl	(%ebx), %esi
 8447 4c5e 8D7B04   		leal	4(%ebx), %edi
 8448 4c61 6A00     		pushl	$0
 8449 4c63 57       		pushl	%edi
 8450 4c64 E8000000 		call	_InterlockedExchangeAdd@8
 8450      00
 8451 4c69 89C2     		movl	%eax, %edx
 8452 4c6b 58       		popl	%eax
 8453 4c6c 59       		popl	%ecx
 8454 4c6d 85D2     		testl	%edx, %edx
 8455 4c6f 743F     		je	L1539
 8456              	L1520:
 8457 4c71 8B352400 		movl	_ptw32_smp_system, %esi
 8457      0000
 8458 4c77 83C9FF   		orl	$-1, %ecx
 8459 4c7a 31DB     		xorl	%ebx, %ebx
 8460 4c7c 85F6     		testl	%esi, %esi
 8461 4c7e 7421     		je	L1531
 8462 4c80 89D8     		movl	%ebx, %eax
 8463              	/APP
 8464 4c82 F0       		lock
 8465 4c83 0FB14A08 		cmpxchgl       %ecx,8(%edx)
 8466              	/NO_APP
 8467              	L1538:
 8468 4c87 85C0     		testl	%eax, %eax
 8469 4c89 7508     		jne	L1540
 8470              	L1519:
 8471 4c8b 8D65F4   		leal	-12(%ebp), %esp
 8472 4c8e 5B       		popl	%ebx
 8473 4c8f 5E       		popl	%esi
 8474 4c90 5F       		popl	%edi
 8475 4c91 5D       		popl	%ebp
 8476 4c92 C3       		ret
 8477              		.p2align 4,,7
 8478              	L1540:
 8479 4c93 83EC0C   		subl	$12, %esp
 8480 4c96 50       		pushl	%eax
 8481 4c97 E8000000 		call	_SetEvent@4
 8481      00
 8482 4c9c 83C40C   		addl	$12, %esp
 8483 4c9f EBEA     		jmp	L1519
 8484              		.p2align 4,,7
 8485              	L1531:
 8486 4ca1 89F0     		movl	%esi, %eax
 8487              	/APP
 8488 4ca3 0FB14A08 		cmpxchgl       %ecx,8(%edx)
 8489              	/NO_APP
 8490 4ca7 EBDE     		jmp	L1538
 8491 4ca9 8DB42600 		.p2align 4,,7
 8491      000000
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 177


 8492              	L1539:
 8493 4cb0 8B0D2400 		movl	_ptw32_smp_system, %ecx
 8493      0000
 8494 4cb6 85C9     		testl	%ecx, %ecx
 8495 4cb8 0F848400 		je	L1522
 8495      0000
 8496 4cbe 89D8     		movl	%ebx, %eax
 8497              	/APP
 8498 4cc0 F0       		lock
 8499 4cc1 0FB116   		cmpxchgl       %edx,(%esi)
 8500              	/NO_APP
 8501              	L1536:
 8502 4cc4 39C3     		cmpl	%eax, %ebx
 8503 4cc6 74C3     		je	L1519
 8504 4cc8 8D530C   		leal	12(%ebx), %edx
 8505 4ccb 51       		pushl	%ecx
 8506 4ccc 51       		pushl	%ecx
 8507 4ccd 6A00     		pushl	$0
 8508 4ccf 52       		pushl	%edx
 8509 4cd0 E8000000 		call	_InterlockedExchangeAdd@8
 8509      00
 8510 4cd5 5E       		popl	%esi
 8511 4cd6 85C0     		testl	%eax, %eax
 8512 4cd8 5A       		popl	%edx
 8513 4cd9 89C6     		movl	%eax, %esi
 8514 4cdb 7410     		je	L1541
 8515              	L1530:
 8516 4cdd 50       		pushl	%eax
 8517 4cde 50       		pushl	%eax
 8518 4cdf 6A00     		pushl	$0
 8519 4ce1 57       		pushl	%edi
 8520 4ce2 E8000000 		call	_InterlockedExchangeAdd@8
 8520      00
 8521 4ce7 5B       		popl	%ebx
 8522 4ce8 89C2     		movl	%eax, %edx
 8523 4cea 5E       		popl	%esi
 8524 4ceb EB84     		jmp	L1520
 8525              	L1541:
 8526 4ced 6A00     		pushl	$0
 8527 4cef 6A00     		pushl	$0
 8528 4cf1 6A00     		pushl	$0
 8529 4cf3 6A00     		pushl	$0
 8530 4cf5 E8000000 		call	_CreateEventA@16
 8530      00
 8531 4cfa 8B152400 		movl	_ptw32_smp_system, %edx
 8531      0000
 8532 4d00 85D2     		testl	%edx, %edx
 8533 4d02 8945F0   		movl	%eax, -16(%ebp)
 8534 4d05 7430     		je	L1527
 8535 4d07 89F0     		movl	%esi, %eax
 8536 4d09 8B55F0   		movl	-16(%ebp), %edx
 8537              	/APP
 8538 4d0c F0       		lock
 8539 4d0d 0FB1530C 		cmpxchgl       %edx,12(%ebx)
 8540              	/NO_APP
 8541              	L1537:
 8542 4d11 85C0     		testl	%eax, %eax
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 178


 8543 4d13 7411     		je	L1542
 8544              	L1526:
 8545 4d15 83EC0C   		subl	$12, %esp
 8546 4d18 8B75F0   		movl	-16(%ebp), %esi
 8547 4d1b 56       		pushl	%esi
 8548 4d1c E8000000 		call	_CloseHandle@4
 8548      00
 8549 4d21 83C40C   		addl	$12, %esp
 8550 4d24 EBB7     		jmp	L1530
 8551              	L1542:
 8552 4d26 8B45F0   		movl	-16(%ebp), %eax
 8553 4d29 53       		pushl	%ebx
 8554 4d2a 53       		pushl	%ebx
 8555 4d2b 6AFF     		pushl	$-1
 8556 4d2d 50       		pushl	%eax
 8557 4d2e E8000000 		call	_WaitForSingleObject@8
 8557      00
 8558 4d33 58       		popl	%eax
 8559 4d34 5A       		popl	%edx
 8560 4d35 EBDE     		jmp	L1526
 8561              	L1527:
 8562 4d37 89D0     		movl	%edx, %eax
 8563 4d39 8B75F0   		movl	-16(%ebp), %esi
 8564              	/APP
 8565 4d3c 0FB1730C 		cmpxchgl       %esi,12(%ebx)
 8566              	/NO_APP
 8567 4d40 EBCF     		jmp	L1537
 8568              	L1522:
 8569 4d42 89D8     		movl	%ebx, %eax
 8570              	/APP
 8571 4d44 0FB116   		cmpxchgl       %edx,(%esi)
 8572              	/NO_APP
 8573 4d47 E978FFFF 		jmp	L1536
 8573      FF
 8574 4d4c 8D742600 		.p2align 4,,15
 8575              	.globl _ptw32_is_attr
 8576              		.def	_ptw32_is_attr;	.scl	2;	.type	32;	.endef
 8577              	_ptw32_is_attr:
 8578 4d50 55       		pushl	%ebp
 8579 4d51 31C0     		xorl	%eax, %eax
 8580 4d53 89E5     		movl	%esp, %ebp
 8581 4d55 8B5508   		movl	8(%ebp), %edx
 8582 4d58 85D2     		testl	%edx, %edx
 8583 4d5a 740E     		je	L1545
 8584 4d5c 8B12     		movl	(%edx), %edx
 8585 4d5e 85D2     		testl	%edx, %edx
 8586 4d60 7408     		je	L1545
 8587 4d62 813AEEFF 		cmpl	$-993984530, (%edx)
 8587      C0C4
 8588 4d68 7405     		je	L1544
 8589              	L1545:
 8590 4d6a B8010000 		movl	$1, %eax
 8590      00
 8591              	L1544:
 8592 4d6f 5D       		popl	%ebp
 8593 4d70 C3       		ret
 8594 4d71 EB0D9090 		.p2align 4,,15
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 179


 8594      90909090 
 8594      90909090 
 8594      909090
 8595              	.globl _ptw32_processInitialize
 8596              		.def	_ptw32_processInitialize;	.scl	2;	.type	32;	.endef
 8597              	_ptw32_processInitialize:
 8598 4d80 55       		pushl	%ebp
 8599 4d81 89E5     		movl	%esp, %ebp
 8600 4d83 50       		pushl	%eax
 8601 4d84 50       		pushl	%eax
 8602 4d85 8B150000 		movl	_ptw32_processInitialized, %edx
 8602      0000
 8603 4d8b 85D2     		testl	%edx, %edx
 8604 4d8d 7409     		je	L1547
 8605 4d8f B8010000 		movl	$1, %eax
 8605      00
 8606              	L1546:
 8607 4d94 89EC     		movl	%ebp, %esp
 8608 4d96 5D       		popl	%ebp
 8609 4d97 C3       		ret
 8610              		.p2align 4,,7
 8611              	L1547:
 8612 4d98 C7050000 		movl	$1, _ptw32_processInitialized
 8612      00000100 
 8612      0000
 8613 4da2 50       		pushl	%eax
 8614 4da3 50       		pushl	%eax
 8615 4da4 6A00     		pushl	$0
 8616 4da6 680C0000 		pushl	$_ptw32_selfThreadKey
 8616      00
 8617 4dab E890F9FF 		call	_pthread_key_create
 8617      FF
 8618 4db0 83C410   		addl	$16, %esp
 8619 4db3 85C0     		testl	%eax, %eax
 8620 4db5 7515     		jne	L1549
 8621 4db7 50       		pushl	%eax
 8622 4db8 50       		pushl	%eax
 8623 4db9 6A00     		pushl	$0
 8624 4dbb 68100000 		pushl	$_ptw32_cleanupKey
 8624      00
 8625 4dc0 E87BF9FF 		call	_pthread_key_create
 8625      FF
 8626 4dc5 83C410   		addl	$16, %esp
 8627 4dc8 85C0     		testl	%eax, %eax
 8628 4dca 7405     		je	L1548
 8629              	L1549:
 8630 4dcc E82FB2FF 		call	_ptw32_processTerminate
 8630      FF
 8631              	L1548:
 8632 4dd1 83EC0C   		subl	$12, %esp
 8633 4dd4 68000000 		pushl	$_ptw32_thread_reuse_lock
 8633      00
 8634 4dd9 E8000000 		call	_InitializeCriticalSection@4
 8634      00
 8635 4dde 68000000 		pushl	$_ptw32_mutex_test_init_lock
 8635      00
 8636 4de3 E8000000 		call	_InitializeCriticalSection@4
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 180


 8636      00
 8637 4de8 68000000 		pushl	$_ptw32_cond_list_lock
 8637      00
 8638 4ded E8000000 		call	_InitializeCriticalSection@4
 8638      00
 8639 4df2 68000000 		pushl	$_ptw32_cond_test_init_lock
 8639      00
 8640 4df7 E8000000 		call	_InitializeCriticalSection@4
 8640      00
 8641 4dfc 68000000 		pushl	$_ptw32_rwlock_test_init_lock
 8641      00
 8642 4e01 E8000000 		call	_InitializeCriticalSection@4
 8642      00
 8643 4e06 68000000 		pushl	$_ptw32_spinlock_test_init_lock
 8643      00
 8644 4e0b E8000000 		call	_InitializeCriticalSection@4
 8644      00
 8645 4e10 A1000000 		movl	_ptw32_processInitialized, %eax
 8645      00
 8646 4e15 E97AFFFF 		jmp	L1546
 8646      FF
 8647 4e1a 8DB60000 		.p2align 4,,15
 8647      0000
 8648              	.globl _ptw32_threadDestroy
 8649              		.def	_ptw32_threadDestroy;	.scl	2;	.type	32;	.endef
 8650              	_ptw32_threadDestroy:
 8651 4e20 55       		pushl	%ebp
 8652 4e21 89E5     		movl	%esp, %ebp
 8653 4e23 57       		pushl	%edi
 8654 4e24 56       		pushl	%esi
 8655 4e25 81EC9000 		subl	$144, %esp
 8655      0000
 8656 4e2b 8B4508   		movl	8(%ebp), %eax
 8657 4e2e 8B550C   		movl	12(%ebp), %edx
 8658 4e31 89C6     		movl	%eax, %esi
 8659 4e33 85C0     		testl	%eax, %eax
 8660 4e35 7445     		je	L1550
 8661 4e37 FC       		cld
 8662 4e38 8DBD68FF 		leal	-152(%ebp), %edi
 8662      FFFF
 8663 4e3e B9230000 		movl	$35, %ecx
 8663      00
 8664 4e43 F3       		rep
 8665 4e44 A5       		movsl
 8666 4e45 51       		pushl	%ecx
 8667 4e46 51       		pushl	%ecx
 8668 4e47 52       		pushl	%edx
 8669 4e48 50       		pushl	%eax
 8670 4e49 E8A2CCFF 		call	_ptw32_threadReusePush
 8670      FF
 8671 4e4e 8B45A4   		movl	-92(%ebp), %eax
 8672 4e51 83C410   		addl	$16, %esp
 8673 4e54 85C0     		testl	%eax, %eax
 8674 4e56 7539     		jne	L1554
 8675              	L1552:
 8676 4e58 83EC0C   		subl	$12, %esp
 8677 4e5b 8D5598   		leal	-104(%ebp), %edx
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 181


 8678 4e5e 52       		pushl	%edx
 8679 4e5f E80CCEFF 		call	_pthread_mutex_destroy
 8679      FF
 8680 4e64 8D5590   		leal	-112(%ebp), %edx
 8681 4e67 891424   		movl	%edx, (%esp)
 8682 4e6a E801CEFF 		call	_pthread_mutex_destroy
 8682      FF
 8683 4e6f 8B856CFF 		movl	-148(%ebp), %eax
 8683      FFFF
 8684 4e75 83C410   		addl	$16, %esp
 8685 4e78 85C0     		testl	%eax, %eax
 8686 4e7a 7507     		jne	L1555
 8687              	L1550:
 8688 4e7c 8D65F8   		leal	-8(%ebp), %esp
 8689 4e7f 5E       		popl	%esi
 8690 4e80 5F       		popl	%edi
 8691 4e81 5D       		popl	%ebp
 8692 4e82 C3       		ret
 8693              		.p2align 4,,7
 8694              	L1555:
 8695 4e83 83EC0C   		subl	$12, %esp
 8696 4e86 50       		pushl	%eax
 8697 4e87 E8000000 		call	_CloseHandle@4
 8697      00
 8698 4e8c 83C40C   		addl	$12, %esp
 8699 4e8f EBEB     		jmp	L1550
 8700              		.p2align 4,,7
 8701              	L1554:
 8702 4e91 83EC0C   		subl	$12, %esp
 8703 4e94 50       		pushl	%eax
 8704 4e95 E8000000 		call	_CloseHandle@4
 8704      00
 8705 4e9a 83C40C   		addl	$12, %esp
 8706 4e9d EBB9     		jmp	L1552
 8707 4e9f 90       		.p2align 4,,15
 8708              	.globl _ptw32_tkAssocCreate
 8709              		.def	_ptw32_tkAssocCreate;	.scl	2;	.type	32;	.endef
 8710              	_ptw32_tkAssocCreate:
 8711 4ea0 55       		pushl	%ebp
 8712 4ea1 89E5     		movl	%esp, %ebp
 8713 4ea3 56       		pushl	%esi
 8714 4ea4 53       		pushl	%ebx
 8715 4ea5 50       		pushl	%eax
 8716 4ea6 8B7508   		movl	8(%ebp), %esi
 8717 4ea9 50       		pushl	%eax
 8718 4eaa 8B5D0C   		movl	12(%ebp), %ebx
 8719 4ead 6A18     		pushl	$24
 8720 4eaf 6A01     		pushl	$1
 8721 4eb1 E8000000 		call	_calloc
 8721      00
 8722 4eb6 BA0C0000 		movl	$12, %edx
 8722      00
 8723 4ebb 83C410   		addl	$16, %esp
 8724 4ebe 85C0     		testl	%eax, %eax
 8725 4ec0 743B     		je	L1556
 8726 4ec2 8B530C   		movl	12(%ebx), %edx
 8727 4ec5 8930     		movl	%esi, (%eax)
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 182


 8728 4ec7 895804   		movl	%ebx, 4(%eax)
 8729 4eca 89500C   		movl	%edx, 12(%eax)
 8730 4ecd C7401400 		movl	$0, 20(%eax)
 8730      000000
 8731 4ed4 85D2     		testl	%edx, %edx
 8732 4ed6 7403     		je	L1558
 8733 4ed8 894214   		movl	%eax, 20(%edx)
 8734              	L1558:
 8735 4edb 89430C   		movl	%eax, 12(%ebx)
 8736 4ede 8B968400 		movl	132(%esi), %edx
 8736      0000
 8737 4ee4 C7401000 		movl	$0, 16(%eax)
 8737      000000
 8738 4eeb 895008   		movl	%edx, 8(%eax)
 8739 4eee 85D2     		testl	%edx, %edx
 8740 4ef0 7403     		je	L1559
 8741 4ef2 894210   		movl	%eax, 16(%edx)
 8742              	L1559:
 8743 4ef5 89868400 		movl	%eax, 132(%esi)
 8743      0000
 8744 4efb 31D2     		xorl	%edx, %edx
 8745              	L1556:
 8746 4efd 8D65F8   		leal	-8(%ebp), %esp
 8747 4f00 89D0     		movl	%edx, %eax
 8748 4f02 5B       		popl	%ebx
 8749 4f03 5E       		popl	%esi
 8750 4f04 5D       		popl	%ebp
 8751 4f05 C3       		ret
 8752 4f06 8D76008D 		.p2align 4,,15
 8752      BC270000 
 8752      0000
 8753              	.globl _ptw32_relmillisecs
 8754              		.def	_ptw32_relmillisecs;	.scl	2;	.type	32;	.endef
 8755              	_ptw32_relmillisecs:
 8756 4f10 55       		pushl	%ebp
 8757 4f11 89E5     		movl	%esp, %ebp
 8758 4f13 57       		pushl	%edi
 8759 4f14 56       		pushl	%esi
 8760 4f15 53       		pushl	%ebx
 8761 4f16 BBE80300 		movl	$1000, %ebx
 8761      00
 8762 4f1b 83EC1C   		subl	$28, %esp
 8763 4f1e 8B4D08   		movl	8(%ebp), %ecx
 8764 4f21 8B01     		movl	(%ecx), %eax
 8765 4f23 F7EB     		imull	%ebx
 8766 4f25 89C6     		movl	%eax, %esi
 8767 4f27 89D7     		movl	%edx, %edi
 8768 4f29 8B4104   		movl	4(%ecx), %eax
 8769 4f2c 6A00     		pushl	$0
 8770 4f2e 89C1     		movl	%eax, %ecx
 8771 4f30 6840420F 		pushl	$1000000
 8771      00
 8772 4f35 C1F91F   		sarl	$31, %ecx
 8773 4f38 0520A107 		addl	$500000, %eax
 8773      00
 8774 4f3d 83D100   		adcl	$0, %ecx
 8775 4f40 51       		pushl	%ecx
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 183


 8776 4f41 50       		pushl	%eax
 8777 4f42 E8000000 		call	___divdi3
 8777      00
 8778 4f47 01C6     		addl	%eax, %esi
 8779 4f49 11D7     		adcl	%edx, %edi
 8780 4f4b 8D55D8   		leal	-40(%ebp), %edx
 8781 4f4e 891424   		movl	%edx, (%esp)
 8782 4f51 E8000000 		call	__ftime
 8782      00
 8783 4f56 8B45D8   		movl	-40(%ebp), %eax
 8784 4f59 F7EB     		imull	%ebx
 8785 4f5b 89C1     		movl	%eax, %ecx
 8786 4f5d 89D3     		movl	%edx, %ebx
 8787 4f5f 0FBF45DC 		movswl	-36(%ebp),%eax
 8788 4f63 89C2     		movl	%eax, %edx
 8789 4f65 C1FA1F   		sarl	$31, %edx
 8790 4f68 01C1     		addl	%eax, %ecx
 8791 4f6a 11D3     		adcl	%edx, %ebx
 8792 4f6c 83C410   		addl	$16, %esp
 8793 4f6f 39DF     		cmpl	%ebx, %edi
 8794 4f71 7C24     		jl	L1561
 8795 4f73 7F04     		jg	L1562
 8796 4f75 39CE     		cmpl	%ecx, %esi
 8797 4f77 761E     		jbe	L1561
 8798              	L1562:
 8799 4f79 89F0     		movl	%esi, %eax
 8800 4f7b 29C8     		subl	%ecx, %eax
 8801 4f7d 83F8FF   		cmpl	$-1, %eax
 8802 4f80 740E     		je	L1565
 8803              	L1564:
 8804 4f82 8D65F4   		leal	-12(%ebp), %esp
 8805 4f85 5B       		popl	%ebx
 8806 4f86 5E       		popl	%esi
 8807 4f87 5F       		popl	%edi
 8808 4f88 5D       		popl	%ebp
 8809 4f89 C3       		ret
 8810 4f8a 8DB60000 		.p2align 4,,7
 8810      0000
 8811              	L1565:
 8812 4f90 B8FEFFFF 		movl	$-2, %eax
 8812      FF
 8813 4f95 EBEB     		jmp	L1564
 8814              		.p2align 4,,7
 8815              	L1561:
 8816 4f97 31C0     		xorl	%eax, %eax
 8817 4f99 EBE7     		jmp	L1564
 8818 4f9b 908D7426 		.p2align 4,,15
 8818      00
 8819              	.globl _ptw32_throw
 8820              		.def	_ptw32_throw;	.scl	2;	.type	32;	.endef
 8821              	_ptw32_throw:
 8822 4fa0 55       		pushl	%ebp
 8823 4fa1 8B150C00 		movl	_ptw32_selfThreadKey, %edx
 8823      0000
 8824 4fa7 89E5     		movl	%esp, %ebp
 8825 4fa9 56       		pushl	%esi
 8826 4faa 53       		pushl	%ebx
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 184


 8827 4fab 83EC0C   		subl	$12, %esp
 8828 4fae 8B7508   		movl	8(%ebp), %esi
 8829 4fb1 52       		pushl	%edx
 8830 4fb2 E849FAFF 		call	_pthread_getspecific
 8830      FF
 8831 4fb7 83C410   		addl	$16, %esp
 8832 4fba 8D56FF   		leal	-1(%esi), %edx
 8833 4fbd 89C3     		movl	%eax, %ebx
 8834 4fbf 83FA01   		cmpl	$1, %edx
 8835 4fc2 760C     		jbe	L1567
 8836 4fc4 83EC0C   		subl	$12, %esp
 8837 4fc7 6A01     		pushl	$1
 8838 4fc9 E8000000 		call	_exit
 8838      00
 8839 4fce 89F6     		.p2align 4,,7
 8840              	L1567:
 8841 4fd0 85C0     		testl	%eax, %eax
 8842 4fd2 740D     		je	L1569
 8843 4fd4 8A888000 		movb	128(%eax), %cl
 8843      0000
 8844 4fda 83E101   		andl	$1, %ecx
 8845 4fdd 84C9     		testb	%cl, %cl
 8846 4fdf 741F     		je	L1575
 8847              	L1569:
 8848 4fe1 31C0     		xorl	%eax, %eax
 8849 4fe3 83FE01   		cmpl	$1, %esi
 8850 4fe6 7430     		je	L1572
 8851 4fe8 83FE02   		cmpl	$2, %esi
 8852 4feb 7426     		je	L1579
 8853              	L1570:
 8854 4fed 83EC0C   		subl	$12, %esp
 8855 4ff0 50       		pushl	%eax
 8856 4ff1 E8000000 		call	__endthreadex
 8856      00
 8857 4ff6 83C410   		addl	$16, %esp
 8858 4ff9 8DB42600 		.p2align 4,,7
 8858      000000
 8859              	L1575:
 8860 5000 83EC0C   		subl	$12, %esp
 8861 5003 6A01     		pushl	$1
 8862 5005 E8A6BDFF 		call	_ptw32_pop_cleanup
 8862      FF
 8863 500a 83C410   		addl	$16, %esp
 8864 500d 85C0     		testl	%eax, %eax
 8865 500f 75EF     		jne	L1575
 8866 5011 EB0D     		jmp	L1580
 8867              	L1579:
 8868 5013 83C8FF   		orl	$-1, %eax
 8869 5016 EBD5     		jmp	L1570
 8870              	L1572:
 8871 5018 8B4318   		movl	24(%ebx), %eax
 8872 501b EBD0     		jmp	L1570
 8873 501d 8D7600   		.p2align 4,,7
 8874              	L1580:
 8875 5020 50       		pushl	%eax
 8876 5021 50       		pushl	%eax
 8877 5022 56       		pushl	%esi
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 185


 8878 5023 8D7340   		leal	64(%ebx), %esi
 8879 5026 56       		pushl	%esi
 8880 5027 E8000000 		call	_longjmp
 8880      00
 8881 502c 8D742600 		.p2align 4,,15
 8882              	.globl _ptw32_pop_cleanup_all
 8883              		.def	_ptw32_pop_cleanup_all;	.scl	2;	.type	32;	.endef
 8884              	_ptw32_pop_cleanup_all:
 8885 5030 55       		pushl	%ebp
 8886 5031 89E5     		movl	%esp, %ebp
 8887 5033 53       		pushl	%ebx
 8888 5034 50       		pushl	%eax
 8889 5035 8B5D08   		movl	8(%ebp), %ebx
 8890              		.p2align 4,,7
 8891              	L1582:
 8892 5038 83EC0C   		subl	$12, %esp
 8893 503b 53       		pushl	%ebx
 8894 503c E86FBDFF 		call	_ptw32_pop_cleanup
 8894      FF
 8895 5041 83C410   		addl	$16, %esp
 8896 5044 85C0     		testl	%eax, %eax
 8897 5046 75F0     		jne	L1582
 8898 5048 8B5DFC   		movl	-4(%ebp), %ebx
 8899 504b C9       		leave
 8900 504c C3       		ret
 8901 504d 8D7600   		.p2align 4,,15
 8902              	.globl _ptw32_getprocessors
 8903              		.def	_ptw32_getprocessors;	.scl	2;	.type	32;	.endef
 8904              	_ptw32_getprocessors:
 8905 5050 55       		pushl	%ebp
 8906 5051 89E5     		movl	%esp, %ebp
 8907 5053 53       		pushl	%ebx
 8908 5054 83EC18   		subl	$24, %esp
 8909 5057 31DB     		xorl	%ebx, %ebx
 8910 5059 8D55F8   		leal	-8(%ebp), %edx
 8911 505c 52       		pushl	%edx
 8912 505d 8D55F4   		leal	-12(%ebp), %edx
 8913 5060 52       		pushl	%edx
 8914 5061 51       		pushl	%ecx
 8915 5062 E8000000 		call	_GetCurrentProcess@0
 8915      00
 8916 5067 890424   		movl	%eax, (%esp)
 8917 506a E8000000 		call	_GetProcessAffinityMask@12
 8917      00
 8918 506f 5A       		popl	%edx
 8919 5070 85C0     		testl	%eax, %eax
 8920 5072 7421     		je	L1586
 8921 5074 31C9     		xorl	%ecx, %ecx
 8922 5076 B8010000 		movl	$1, %eax
 8922      00
 8923 507b 8B55F4   		movl	-12(%ebp), %edx
 8924 507e 89F6     		.p2align 4,,7
 8925              	L1592:
 8926 5080 85D0     		testl	%eax, %edx
 8927 5082 7401     		je	L1589
 8928 5084 41       		incl	%ecx
 8929              	L1589:
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 186


 8930 5085 01C0     		addl	%eax, %eax
 8931 5087 75F7     		jne	L1592
 8932 5089 8B5508   		movl	8(%ebp), %edx
 8933 508c 890A     		movl	%ecx, (%edx)
 8934              	L1593:
 8935 508e 89D8     		movl	%ebx, %eax
 8936 5090 8B5DFC   		movl	-4(%ebp), %ebx
 8937 5093 C9       		leave
 8938 5094 C3       		ret
 8939              		.p2align 4,,7
 8940              	L1586:
 8941 5095 BB0B0000 		movl	$11, %ebx
 8941      00
 8942 509a EBF2     		jmp	L1593
 8943 509c 8D742600 		.p2align 4,,15
 8944              	.globl _ptw32_RegisterCancelation
 8945              		.def	_ptw32_RegisterCancelation;	.scl	2;	.type	32;	.endef
 8946              	_ptw32_RegisterCancelation:
 8947 50a0 55       		pushl	%ebp
 8948 50a1 89E5     		movl	%esp, %ebp
 8949 50a3 56       		pushl	%esi
 8950 50a4 53       		pushl	%ebx
 8951 50a5 81ECD802 		subl	$728, %esp
 8951      0000
 8952 50ab 8D9D28FD 		leal	-728(%ebp), %ebx
 8952      FFFF
 8953 50b1 8B750C   		movl	12(%ebp), %esi
 8954 50b4 53       		pushl	%ebx
 8955 50b5 56       		pushl	%esi
 8956 50b6 C78528FD 		movl	$65537, -728(%ebp)
 8956      FFFF0100 
 8956      0100
 8957 50c0 E8000000 		call	_GetThreadContext@8
 8957      00
 8958 50c5 C785E0FD 		movl	$_ptw32_cancel_self, -544(%ebp)
 8958      FFFF0053 
 8958      0000
 8959 50cf 53       		pushl	%ebx
 8960 50d0 56       		pushl	%esi
 8961 50d1 E8000000 		call	_SetThreadContext@8
 8961      00
 8962 50d6 8D65F8   		leal	-8(%ebp), %esp
 8963 50d9 5B       		popl	%ebx
 8964 50da 31C0     		xorl	%eax, %eax
 8965 50dc 5E       		popl	%esi
 8966 50dd 5D       		popl	%ebp
 8967 50de C3       		ret
 8968 50df 90       		.p2align 4,,15
 8969              	.globl _ptw32_cond_check_need_init
 8970              		.def	_ptw32_cond_check_need_init;	.scl	2;	.type	32;	.endef
 8971              	_ptw32_cond_check_need_init:
 8972 50e0 55       		pushl	%ebp
 8973 50e1 89E5     		movl	%esp, %ebp
 8974 50e3 56       		pushl	%esi
 8975 50e4 53       		pushl	%ebx
 8976 50e5 31DB     		xorl	%ebx, %ebx
 8977 50e7 83EC0C   		subl	$12, %esp
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 187


 8978 50ea 8B7508   		movl	8(%ebp), %esi
 8979 50ed 68000000 		pushl	$_ptw32_cond_test_init_lock
 8979      00
 8980 50f2 E8000000 		call	_EnterCriticalSection@4
 8980      00
 8981 50f7 8B06     		movl	(%esi), %eax
 8982 50f9 83C40C   		addl	$12, %esp
 8983 50fc 83F8FF   		cmpl	$-1, %eax
 8984 50ff 741F     		je	L1603
 8985 5101 85C0     		testl	%eax, %eax
 8986 5103 7505     		jne	L1601
 8987 5105 BB160000 		movl	$22, %ebx
 8987      00
 8988              	L1601:
 8989 510a 83EC0C   		subl	$12, %esp
 8990 510d 68000000 		pushl	$_ptw32_cond_test_init_lock
 8990      00
 8991 5112 E8000000 		call	_LeaveCriticalSection@4
 8991      00
 8992 5117 8D65F8   		leal	-8(%ebp), %esp
 8993 511a 89D8     		movl	%ebx, %eax
 8994 511c 5B       		popl	%ebx
 8995 511d 5E       		popl	%esi
 8996 511e 5D       		popl	%ebp
 8997 511f C3       		ret
 8998              		.p2align 4,,7
 8999              	L1603:
 9000 5120 53       		pushl	%ebx
 9001 5121 53       		pushl	%ebx
 9002 5122 6A00     		pushl	$0
 9003 5124 56       		pushl	%esi
 9004 5125 E806BEFF 		call	_pthread_cond_init
 9004      FF
 9005 512a 83C410   		addl	$16, %esp
 9006 512d 89C3     		movl	%eax, %ebx
 9007 512f EBD9     		jmp	L1601
 9008 5131 EB0D9090 		.p2align 4,,15
 9008      90909090 
 9008      90909090 
 9008      909090
 9009              	.globl _DllMain@12
 9010              		.def	_DllMain@12;	.scl	2;	.type	32;	.endef
 9011              	_DllMain@12:
 9012 5140 55       		pushl	%ebp
 9013 5141 89E5     		movl	%esp, %ebp
 9014 5143 50       		pushl	%eax
 9015 5144 50       		pushl	%eax
 9016 5145 B8010000 		movl	$1, %eax
 9016      00
 9017 514a 8B550C   		movl	12(%ebp), %edx
 9018 514d 83FA01   		cmpl	$1, %edx
 9019 5150 742F     		je	L1606
 9020 5152 83FA01   		cmpl	$1, %edx
 9021 5155 721E     		jb	L1609
 9022 5157 83FA02   		cmpl	$2, %edx
 9023 515a 7412     		je	L1607
 9024 515c 83FA03   		cmpl	$3, %edx
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 188


 9025 515f 7406     		je	L1608
 9026              	L1605:
 9027 5161 89EC     		movl	%ebp, %esp
 9028 5163 5D       		popl	%ebp
 9029 5164 C20C00   		ret	$12
 9030              	L1608:
 9031 5167 E834D8FF 		call	_pthread_win32_thread_detach_np
 9031      FF
 9032 516c EBF3     		jmp	L1605
 9033              	L1607:
 9034 516e E81DD8FF 		call	_pthread_win32_thread_attach_np
 9034      FF
 9035 5173 EBEC     		jmp	L1605
 9036              		.p2align 4,,7
 9037              	L1609:
 9038 5175 E826D8FF 		call	_pthread_win32_thread_detach_np
 9038      FF
 9039 517a E801D7FF 		call	_pthread_win32_process_detach_np
 9039      FF
 9040 517f EBE0     		jmp	L1605
 9041              		.p2align 4,,7
 9042              	L1606:
 9043 5181 E8AAD4FF 		call	_pthread_win32_process_attach_np
 9043      FF
 9044 5186 EBD9     		jmp	L1605
 9045 5188 908DB426 		.p2align 4,,15
 9045      00000000 
 9046              	.globl _ptw32_mutex_check_need_init
 9047              		.def	_ptw32_mutex_check_need_init;	.scl	2;	.type	32;	.endef
 9048              	_ptw32_mutex_check_need_init:
 9049 5190 55       		pushl	%ebp
 9050 5191 89E5     		movl	%esp, %ebp
 9051 5193 56       		pushl	%esi
 9052 5194 53       		pushl	%ebx
 9053 5195 31F6     		xorl	%esi, %esi
 9054 5197 83EC0C   		subl	$12, %esp
 9055 519a 8B5D08   		movl	8(%ebp), %ebx
 9056 519d 68000000 		pushl	$_ptw32_mutex_test_init_lock
 9056      00
 9057 51a2 E8000000 		call	_EnterCriticalSection@4
 9057      00
 9058 51a7 8B03     		movl	(%ebx), %eax
 9059 51a9 83C40C   		addl	$12, %esp
 9060 51ac 83F8FF   		cmpl	$-1, %eax
 9061 51af 7448     		je	L1622
 9062 51b1 83F8FE   		cmpl	$-2, %eax
 9063 51b4 743A     		je	L1623
 9064 51b6 83F8FD   		cmpl	$-3, %eax
 9065 51b9 7421     		je	L1624
 9066 51bb 85C0     		testl	%eax, %eax
 9067 51bd 7416     		je	L1625
 9068              	L1615:
 9069 51bf 83EC0C   		subl	$12, %esp
 9070 51c2 68000000 		pushl	$_ptw32_mutex_test_init_lock
 9070      00
 9071 51c7 E8000000 		call	_LeaveCriticalSection@4
 9071      00
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 189


 9072 51cc 8D65F8   		leal	-8(%ebp), %esp
 9073 51cf 5B       		popl	%ebx
 9074 51d0 89F0     		movl	%esi, %eax
 9075 51d2 5E       		popl	%esi
 9076 51d3 5D       		popl	%ebp
 9077 51d4 C3       		ret
 9078              		.p2align 4,,7
 9079              	L1625:
 9080 51d5 BE160000 		movl	$22, %esi
 9080      00
 9081 51da EBE3     		jmp	L1615
 9082              	L1624:
 9083 51dc 50       		pushl	%eax
 9084 51dd 50       		pushl	%eax
 9085 51de 68440000 		pushl	$_ptw32_errorcheck_mutexattr
 9085      00
 9086              	L1621:
 9087 51e3 53       		pushl	%ebx
 9088 51e4 E8C7C9FF 		call	_pthread_mutex_init
 9088      FF
 9089 51e9 83C410   		addl	$16, %esp
 9090 51ec 89C6     		movl	%eax, %esi
 9091 51ee EBCF     		jmp	L1615
 9092              	L1623:
 9093 51f0 50       		pushl	%eax
 9094 51f1 50       		pushl	%eax
 9095 51f2 68400000 		pushl	$_ptw32_recursive_mutexattr
 9095      00
 9096 51f7 EBEA     		jmp	L1621
 9097              	L1622:
 9098 51f9 50       		pushl	%eax
 9099 51fa 50       		pushl	%eax
 9100 51fb 6A00     		pushl	$0
 9101 51fd EBE4     		jmp	L1621
 9102 51ff 90       		.p2align 4,,15
 9103              	.globl _ptw32_rwlock_check_need_init
 9104              		.def	_ptw32_rwlock_check_need_init;	.scl	2;	.type	32;	.endef
 9105              	_ptw32_rwlock_check_need_init:
 9106 5200 55       		pushl	%ebp
 9107 5201 89E5     		movl	%esp, %ebp
 9108 5203 56       		pushl	%esi
 9109 5204 53       		pushl	%ebx
 9110 5205 31DB     		xorl	%ebx, %ebx
 9111 5207 83EC0C   		subl	$12, %esp
 9112 520a 8B7508   		movl	8(%ebp), %esi
 9113 520d 68000000 		pushl	$_ptw32_rwlock_test_init_lock
 9113      00
 9114 5212 E8000000 		call	_EnterCriticalSection@4
 9114      00
 9115 5217 8B06     		movl	(%esi), %eax
 9116 5219 83C40C   		addl	$12, %esp
 9117 521c 83F8FF   		cmpl	$-1, %eax
 9118 521f 741F     		je	L1630
 9119 5221 85C0     		testl	%eax, %eax
 9120 5223 7505     		jne	L1628
 9121 5225 BB160000 		movl	$22, %ebx
 9121      00
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 190


 9122              	L1628:
 9123 522a 83EC0C   		subl	$12, %esp
 9124 522d 68000000 		pushl	$_ptw32_rwlock_test_init_lock
 9124      00
 9125 5232 E8000000 		call	_LeaveCriticalSection@4
 9125      00
 9126 5237 8D65F8   		leal	-8(%ebp), %esp
 9127 523a 89D8     		movl	%ebx, %eax
 9128 523c 5B       		popl	%ebx
 9129 523d 5E       		popl	%esi
 9130 523e 5D       		popl	%ebp
 9131 523f C3       		ret
 9132              		.p2align 4,,7
 9133              	L1630:
 9134 5240 50       		pushl	%eax
 9135 5241 50       		pushl	%eax
 9136 5242 6A00     		pushl	$0
 9137 5244 56       		pushl	%esi
 9138 5245 E8E6D8FF 		call	_pthread_rwlock_init
 9138      FF
 9139 524a 83C410   		addl	$16, %esp
 9140 524d 89C3     		movl	%eax, %ebx
 9141 524f EBD9     		jmp	L1628
 9142 5251 EB0D9090 		.p2align 4,,15
 9142      90909090 
 9142      90909090 
 9142      909090
 9143              	.globl _ptw32_rwlock_cancelwrwait
 9144              		.def	_ptw32_rwlock_cancelwrwait;	.scl	2;	.type	32;	.endef
 9145              	_ptw32_rwlock_cancelwrwait:
 9146 5260 55       		pushl	%ebp
 9147 5261 89E5     		movl	%esp, %ebp
 9148 5263 53       		pushl	%ebx
 9149 5264 83EC10   		subl	$16, %esp
 9150 5267 8B5D08   		movl	8(%ebp), %ebx
 9151 526a 8B5314   		movl	20(%ebx), %edx
 9152 526d F7DA     		negl	%edx
 9153 526f 89530C   		movl	%edx, 12(%ebx)
 9154 5272 8D5304   		leal	4(%ebx), %edx
 9155 5275 C7431400 		movl	$0, 20(%ebx)
 9155      000000
 9156 527c 52       		pushl	%edx
 9157 527d E88ECFFF 		call	_pthread_mutex_unlock
 9157      FF
 9158 5282 895D08   		movl	%ebx, 8(%ebp)
 9159 5285 83C410   		addl	$16, %esp
 9160 5288 8B5DFC   		movl	-4(%ebp), %ebx
 9161 528b 89EC     		movl	%ebp, %esp
 9162 528d 5D       		popl	%ebp
 9163 528e E97DCFFF 		jmp	_pthread_mutex_unlock
 9163      FF
 9164 5293 8DB60000 		.p2align 4,,15
 9164      00008DBC 
 9164      27000000 
 9164      00
 9165              	.globl _ptw32_spinlock_check_need_init
 9166              		.def	_ptw32_spinlock_check_need_init;	.scl	2;	.type	32;	.endef
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 191


 9167              	_ptw32_spinlock_check_need_init:
 9168 52a0 55       		pushl	%ebp
 9169 52a1 89E5     		movl	%esp, %ebp
 9170 52a3 56       		pushl	%esi
 9171 52a4 53       		pushl	%ebx
 9172 52a5 31DB     		xorl	%ebx, %ebx
 9173 52a7 83EC0C   		subl	$12, %esp
 9174 52aa 8B7508   		movl	8(%ebp), %esi
 9175 52ad 68000000 		pushl	$_ptw32_spinlock_test_init_lock
 9175      00
 9176 52b2 E8000000 		call	_EnterCriticalSection@4
 9176      00
 9177 52b7 8B06     		movl	(%esi), %eax
 9178 52b9 83C40C   		addl	$12, %esp
 9179 52bc 83F8FF   		cmpl	$-1, %eax
 9180 52bf 741F     		je	L1643
 9181 52c1 85C0     		testl	%eax, %eax
 9182 52c3 7505     		jne	L1641
 9183 52c5 BB160000 		movl	$22, %ebx
 9183      00
 9184              	L1641:
 9185 52ca 83EC0C   		subl	$12, %esp
 9186 52cd 68000000 		pushl	$_ptw32_spinlock_test_init_lock
 9186      00
 9187 52d2 E8000000 		call	_LeaveCriticalSection@4
 9187      00
 9188 52d7 8D65F8   		leal	-8(%ebp), %esp
 9189 52da 89D8     		movl	%ebx, %eax
 9190 52dc 5B       		popl	%ebx
 9191 52dd 5E       		popl	%esi
 9192 52de 5D       		popl	%ebp
 9193 52df C3       		ret
 9194              		.p2align 4,,7
 9195              	L1643:
 9196 52e0 50       		pushl	%eax
 9197 52e1 50       		pushl	%eax
 9198 52e2 6A00     		pushl	$0
 9199 52e4 56       		pushl	%esi
 9200 52e5 E826EEFF 		call	_pthread_spin_init
 9200      FF
 9201 52ea 83C410   		addl	$16, %esp
 9202 52ed 89C3     		movl	%eax, %ebx
 9203 52ef EBD9     		jmp	L1641
 9204              		.comm	_ptw32_thread_reuse_lock, 32	 # 24
 9205              		.comm	_ptw32_mutex_test_init_lock, 32	 # 24
 9206              		.comm	_ptw32_cond_list_lock, 32	 # 24
 9207              		.comm	_ptw32_cond_test_init_lock, 32	 # 24
 9208              		.comm	_ptw32_rwlock_test_init_lock, 32	 # 24
 9209              		.comm	_ptw32_spinlock_test_init_lock, 32	 # 24
 9210 52f1 EB0D9090 		.p2align 4,,15
 9210      90909090 
 9210      90909090 
 9210      909090
 9211              		.def	_ptw32_cancel_self;	.scl	3;	.type	32;	.endef
 9212              	_ptw32_cancel_self:
 9213 5300 55       		pushl	%ebp
 9214 5301 89E5     		movl	%esp, %ebp
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 192


 9215 5303 83EC14   		subl	$20, %esp
 9216 5306 6A02     		pushl	$2
 9217 5308 E893FCFF 		call	_ptw32_throw
 9217      FF
 9218 530d 89EC     		movl	%ebp, %esp
 9219 530f 5D       		popl	%ebp
 9220 5310 C3       		ret
 9221 5311 EB0D9090 		.p2align 4,,15
 9221      90909090 
 9221      90909090 
 9221      909090
 9222              		.def	_ptw32_cancel_callback@4;	.scl	3;	.type	32;	.endef
 9223              	_ptw32_cancel_callback@4:
 9224 5320 55       		pushl	%ebp
 9225 5321 89E5     		movl	%esp, %ebp
 9226 5323 83EC14   		subl	$20, %esp
 9227 5326 6A02     		pushl	$2
 9228 5328 E873FCFF 		call	_ptw32_throw
 9228      FF
 9229 532d 89EC     		movl	%ebp, %esp
 9230 532f 5D       		popl	%ebp
 9231 5330 C20400   		ret	$4
 9232 5333 8DB60000 		.p2align 4,,15
 9232      00008DBC 
 9232      27000000 
 9232      00
 9233              		.def	_ptw32_cond_timedwait;	.scl	3;	.type	32;	.endef
 9234              	_ptw32_cond_timedwait:
 9235 5340 55       		pushl	%ebp
 9236 5341 89E5     		movl	%esp, %ebp
 9237 5343 57       		pushl	%edi
 9238 5344 56       		pushl	%esi
 9239 5345 53       		pushl	%ebx
 9240 5346 83EC3C   		subl	$60, %esp
 9241 5349 8B5D08   		movl	8(%ebp), %ebx
 9242 534c 8B7D0C   		movl	12(%ebp), %edi
 9243 534f C745C400 		movl	$0, -60(%ebp)
 9243      000000
 9244 5356 85DB     		testl	%ebx, %ebx
 9245 5358 7406     		je	L330
 9246 535a 8B03     		movl	(%ebx), %eax
 9247 535c 85C0     		testl	%eax, %eax
 9248 535e 7510     		jne	L329
 9249              	L330:
 9250 5360 B8160000 		movl	$22, %eax
 9250      00
 9251              	L328:
 9252 5365 8D65F4   		leal	-12(%ebp), %esp
 9253 5368 5B       		popl	%ebx
 9254 5369 5E       		popl	%esi
 9255 536a 5F       		popl	%edi
 9256 536b 5D       		popl	%ebp
 9257 536c C3       		ret
 9258 536d 8D7600   		.p2align 4,,7
 9259              	L329:
 9260 5370 40       		incl	%eax
 9261 5371 0F84A900 		je	L1645
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 193


 9261      0000
 9262              	L331:
 9263 5377 8B45C4   		movl	-60(%ebp), %eax
 9264 537a 85C0     		testl	%eax, %eax
 9265 537c 7405     		je	L336
 9266 537e 83F810   		cmpl	$16, %eax
 9267 5381 75E2     		jne	L328
 9268              	L336:
 9269 5383 8B33     		movl	(%ebx), %esi
 9270 5385 83EC0C   		subl	$12, %esp
 9271 5388 8D5E10   		leal	16(%esi), %ebx
 9272 538b 53       		pushl	%ebx
 9273 538c E87FE9FF 		call	_sem_wait
 9273      FF
 9274 5391 83C410   		addl	$16, %esp
 9275 5394 85C0     		testl	%eax, %eax
 9276 5396 7515     		jne	L1644
 9277 5398 8B16     		movl	(%esi), %edx
 9278 539a 83EC0C   		subl	$12, %esp
 9279 539d 42       		incl	%edx
 9280 539e 8916     		movl	%edx, (%esi)
 9281 53a0 53       		pushl	%ebx
 9282 53a1 E84AEBFF 		call	_sem_post
 9282      FF
 9283 53a6 83C410   		addl	$16, %esp
 9284 53a9 85C0     		testl	%eax, %eax
 9285 53ab 7409     		je	L338
 9286              	L1644:
 9287 53ad E8000000 		call	__errno
 9287      00
 9288 53b2 8B00     		movl	(%eax), %eax
 9289 53b4 EBAF     		jmp	L328
 9290              	L338:
 9291 53b6 8D5DC4   		leal	-60(%ebp), %ebx
 9292 53b9 8D4DD8   		leal	-40(%ebp), %ecx
 9293 53bc 895DE0   		movl	%ebx, -32(%ebp)
 9294 53bf 8D55C8   		leal	-56(%ebp), %edx
 9295 53c2 897DD8   		movl	%edi, -40(%ebp)
 9296 53c5 53       		pushl	%ebx
 9297 53c6 8975DC   		movl	%esi, -36(%ebp)
 9298 53c9 51       		pushl	%ecx
 9299 53ca 68705800 		pushl	$_ptw32_cond_wait_cleanup
 9299      00
 9300 53cf 52       		pushl	%edx
 9301 53d0 E83BBAFF 		call	_ptw32_push_cleanup
 9301      FF
 9302 53d5 893C24   		movl	%edi, (%esp)
 9303 53d8 E833CEFF 		call	_pthread_mutex_unlock
 9303      FF
 9304 53dd 83C410   		addl	$16, %esp
 9305 53e0 85C0     		testl	%eax, %eax
 9306 53e2 8945C4   		movl	%eax, -60(%ebp)
 9307 53e5 7412     		je	L1646
 9308              	L339:
 9309 53e7 83EC0C   		subl	$12, %esp
 9310 53ea 6A01     		pushl	$1
 9311 53ec E8BFB9FF 		call	_ptw32_pop_cleanup
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 194


 9311      FF
 9312 53f1 8B45C4   		movl	-60(%ebp), %eax
 9313 53f4 E96CFFFF 		jmp	L328
 9313      FF
 9314              	L1646:
 9315 53f9 8B4510   		movl	16(%ebp), %eax
 9316 53fc 51       		pushl	%ecx
 9317 53fd 8D7E0C   		leal	12(%esi), %edi
 9318 5400 51       		pushl	%ecx
 9319 5401 50       		pushl	%eax
 9320 5402 57       		pushl	%edi
 9321 5403 E8A8E9FF 		call	_sem_timedwait
 9321      FF
 9322 5408 83C410   		addl	$16, %esp
 9323 540b 85C0     		testl	%eax, %eax
 9324 540d 74D8     		je	L339
 9325 540f E8000000 		call	__errno
 9325      00
 9326 5414 8B30     		movl	(%eax), %esi
 9327 5416 8975C4   		movl	%esi, -60(%ebp)
 9328 5419 EBCC     		jmp	L339
 9329 541b 908D7426 		.p2align 4,,7
 9329      00
 9330              	L1645:
 9331 5420 83EC0C   		subl	$12, %esp
 9332 5423 31F6     		xorl	%esi, %esi
 9333 5425 68000000 		pushl	$_ptw32_cond_test_init_lock
 9333      00
 9334 542a E8000000 		call	_EnterCriticalSection@4
 9334      00
 9335 542f 8B03     		movl	(%ebx), %eax
 9336 5431 83C40C   		addl	$12, %esp
 9337 5434 83F8FF   		cmpl	$-1, %eax
 9338 5437 7421     		je	L1647
 9339 5439 85C0     		testl	%eax, %eax
 9340 543b 7505     		jne	L333
 9341 543d BE160000 		movl	$22, %esi
 9341      00
 9342              	L333:
 9343 5442 83EC0C   		subl	$12, %esp
 9344 5445 68000000 		pushl	$_ptw32_cond_test_init_lock
 9344      00
 9345 544a E8000000 		call	_LeaveCriticalSection@4
 9345      00
 9346 544f 8975C4   		movl	%esi, -60(%ebp)
 9347 5452 83C40C   		addl	$12, %esp
 9348 5455 E91DFFFF 		jmp	L331
 9348      FF
 9349              	L1647:
 9350 545a 50       		pushl	%eax
 9351 545b 50       		pushl	%eax
 9352 545c 6A00     		pushl	$0
 9353 545e 53       		pushl	%ebx
 9354 545f E8CCBAFF 		call	_pthread_cond_init
 9354      FF
 9355 5464 83C410   		addl	$16, %esp
 9356 5467 89C6     		movl	%eax, %esi
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 195


 9357 5469 EBD7     		jmp	L333
 9358 546b 908D7426 		.p2align 4,,15
 9358      00
 9359              		.def	_ptw32_cond_unblock;	.scl	3;	.type	32;	.endef
 9360              	_ptw32_cond_unblock:
 9361 5470 55       		pushl	%ebp
 9362 5471 89E5     		movl	%esp, %ebp
 9363 5473 57       		pushl	%edi
 9364 5474 56       		pushl	%esi
 9365 5475 53       		pushl	%ebx
 9366 5476 83EC0C   		subl	$12, %esp
 9367 5479 8B4508   		movl	8(%ebp), %eax
 9368 547c 8B7D0C   		movl	12(%ebp), %edi
 9369 547f 85C0     		testl	%eax, %eax
 9370 5481 7406     		je	L347
 9371 5483 8B18     		movl	(%eax), %ebx
 9372 5485 85DB     		testl	%ebx, %ebx
 9373 5487 750D     		jne	L346
 9374              	L347:
 9375 5489 B8160000 		movl	$22, %eax
 9375      00
 9376              	L345:
 9377 548e 8D65F4   		leal	-12(%ebp), %esp
 9378 5491 5B       		popl	%ebx
 9379 5492 5E       		popl	%esi
 9380 5493 5F       		popl	%edi
 9381 5494 5D       		popl	%ebp
 9382 5495 C3       		ret
 9383              		.p2align 4,,7
 9384              	L346:
 9385 5496 31C0     		xorl	%eax, %eax
 9386 5498 83FBFF   		cmpl	$-1, %ebx
 9387 549b 74F1     		je	L345
 9388 549d 83EC0C   		subl	$12, %esp
 9389 54a0 8D5314   		leal	20(%ebx), %edx
 9390 54a3 8955F0   		movl	%edx, -16(%ebp)
 9391 54a6 52       		pushl	%edx
 9392 54a7 E8E4C9FF 		call	_pthread_mutex_lock
 9392      FF
 9393 54ac 83C410   		addl	$16, %esp
 9394 54af 85C0     		testl	%eax, %eax
 9395 54b1 75DB     		jne	L345
 9396 54b3 8B4308   		movl	8(%ebx), %eax
 9397 54b6 85C0     		testl	%eax, %eax
 9398 54b8 746E     		je	L350
 9399 54ba 8B13     		movl	(%ebx), %edx
 9400 54bc 85D2     		testl	%edx, %edx
 9401 54be 7456     		je	L355
 9402 54c0 85FF     		testl	%edi, %edi
 9403 54c2 7442     		je	L352
 9404 54c4 01D0     		addl	%edx, %eax
 9405 54c6 89D7     		movl	%edx, %edi
 9406 54c8 894308   		movl	%eax, 8(%ebx)
 9407              	L1648:
 9408 54cb C7030000 		movl	$0, (%ebx)
 9408      0000
 9409              	L354:
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 196


 9410 54d1 83EC0C   		subl	$12, %esp
 9411 54d4 8B4DF0   		movl	-16(%ebp), %ecx
 9412 54d7 51       		pushl	%ecx
 9413 54d8 E833CDFF 		call	_pthread_mutex_unlock
 9413      FF
 9414 54dd 83C410   		addl	$16, %esp
 9415 54e0 89C6     		movl	%eax, %esi
 9416 54e2 85C0     		testl	%eax, %eax
 9417 54e4 7404     		je	L1649
 9418              	L361:
 9419 54e6 89F0     		movl	%esi, %eax
 9420 54e8 EBA4     		jmp	L345
 9421              	L1649:
 9422 54ea 50       		pushl	%eax
 9423 54eb 50       		pushl	%eax
 9424 54ec 57       		pushl	%edi
 9425 54ed 8D7B0C   		leal	12(%ebx), %edi
 9426 54f0 57       		pushl	%edi
 9427 54f1 E88AEAFF 		call	_sem_post_multiple
 9427      FF
 9428 54f6 83C410   		addl	$16, %esp
 9429 54f9 85C0     		testl	%eax, %eax
 9430 54fb 74E9     		je	L361
 9431 54fd E8000000 		call	__errno
 9431      00
 9432 5502 8B30     		movl	(%eax), %esi
 9433 5504 EBE0     		jmp	L361
 9434              	L352:
 9435 5506 40       		incl	%eax
 9436 5507 8D4AFF   		leal	-1(%edx), %ecx
 9437 550a BF010000 		movl	$1, %edi
 9437      00
 9438 550f 894308   		movl	%eax, 8(%ebx)
 9439 5512 890B     		movl	%ecx, (%ebx)
 9440 5514 EBBB     		jmp	L354
 9441              	L355:
 9442 5516 8B5DF0   		movl	-16(%ebp), %ebx
 9443 5519 895D08   		movl	%ebx, 8(%ebp)
 9444 551c 8D65F4   		leal	-12(%ebp), %esp
 9445 551f 5B       		popl	%ebx
 9446 5520 5E       		popl	%esi
 9447 5521 5F       		popl	%edi
 9448 5522 5D       		popl	%ebp
 9449 5523 E9E8CCFF 		jmp	_pthread_mutex_unlock
 9449      FF
 9450              	L350:
 9451 5528 8B5304   		movl	4(%ebx), %edx
 9452 552b 3913     		cmpl	%edx, (%ebx)
 9453 552d 7EE7     		jle	L355
 9454 552f 83EC0C   		subl	$12, %esp
 9455 5532 8D7310   		leal	16(%ebx), %esi
 9456 5535 56       		pushl	%esi
 9457 5536 E835AEFF 		call	_ptw32_semwait
 9457      FF
 9458 553b 83C410   		addl	$16, %esp
 9459 553e 85C0     		testl	%eax, %eax
 9460 5540 753A     		jne	L1650
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 197


 9461 5542 8B4304   		movl	4(%ebx), %eax
 9462 5545 85C0     		testl	%eax, %eax
 9463 5547 740D     		je	L357
 9464 5549 8B0B     		movl	(%ebx), %ecx
 9465 554b 29C1     		subl	%eax, %ecx
 9466 554d 890B     		movl	%ecx, (%ebx)
 9467 554f C7430400 		movl	$0, 4(%ebx)
 9467      000000
 9468              	L357:
 9469 5556 85FF     		testl	%edi, %edi
 9470 5558 740C     		je	L358
 9471 555a 8B13     		movl	(%ebx), %edx
 9472 555c 895308   		movl	%edx, 8(%ebx)
 9473 555f 89D7     		movl	%edx, %edi
 9474 5561 E965FFFF 		jmp	L1648
 9474      FF
 9475              	L358:
 9476 5566 8B33     		movl	(%ebx), %esi
 9477 5568 BF010000 		movl	$1, %edi
 9477      00
 9478 556d 4E       		decl	%esi
 9479 556e C7430801 		movl	$1, 8(%ebx)
 9479      000000
 9480 5575 8933     		movl	%esi, (%ebx)
 9481 5577 E955FFFF 		jmp	L354
 9481      FF
 9482              	L1650:
 9483 557c E8000000 		call	__errno
 9483      00
 9484 5581 83EC0C   		subl	$12, %esp
 9485 5584 8B30     		movl	(%eax), %esi
 9486 5586 8B45F0   		movl	-16(%ebp), %eax
 9487 5589 50       		pushl	%eax
 9488 558a E881CCFF 		call	_pthread_mutex_unlock
 9488      FF
 9489 558f E952FFFF 		jmp	L361
 9489      FF
 9490 5594 8DB60000 		.p2align 4,,15
 9490      00008DBF 
 9490      00000000 
 9491              		.def	_ptw32_once_on_init_cancel;	.scl	3;	.type	32;	.endef
 9492              	_ptw32_once_on_init_cancel:
 9493 55a0 55       		pushl	%ebp
 9494 55a1 89E5     		movl	%esp, %ebp
 9495 55a3 5D       		popl	%ebp
 9496 55a4 E9A7F6FF 		jmp	_ptw32_mcs_lock_release
 9496      FF
 9497 55a9 8DB42600 		.p2align 4,,15
 9497      000000
 9498              		.def	_ptw32_cancelable_wait;	.scl	3;	.type	32;	.endef
 9499              	_ptw32_cancelable_wait:
 9500 55b0 55       		pushl	%ebp
 9501 55b1 89E5     		movl	%esp, %ebp
 9502 55b3 57       		pushl	%edi
 9503 55b4 56       		pushl	%esi
 9504 55b5 BE010000 		movl	$1, %esi
 9504      00
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 198


 9505 55ba 53       		pushl	%ebx
 9506 55bb 83EC0C   		subl	$12, %esp
 9507 55be 8B5508   		movl	8(%ebp), %edx
 9508 55c1 8955E8   		movl	%edx, -24(%ebp)
 9509 55c4 E8E7C2FF 		call	_pthread_self
 9509      FF
 9510 55c9 89C3     		movl	%eax, %ebx
 9511 55cb 85C0     		testl	%eax, %eax
 9512 55cd 0F84FD00 		je	L498
 9512      0000
 9513 55d3 8B5034   		movl	52(%eax), %edx
 9514 55d6 85D2     		testl	%edx, %edx
 9515 55d8 0F85E300 		jne	L1651
 9515      0000
 9516 55de 8B4B3C   		movl	60(%ebx), %ecx
 9517 55e1 8D7DE8   		leal	-24(%ebp), %edi
 9518 55e4 894DEC   		movl	%ecx, -20(%ebp)
 9519 55e7 85C9     		testl	%ecx, %ecx
 9520 55e9 7405     		je	L501
 9521 55eb BE020000 		movl	$2, %esi
 9521      00
 9522              	L501:
 9523 55f0 8B550C   		movl	12(%ebp), %edx
 9524 55f3 52       		pushl	%edx
 9525 55f4 6A00     		pushl	$0
 9526 55f6 57       		pushl	%edi
 9527 55f7 56       		pushl	%esi
 9528 55f8 E8000000 		call	_WaitForMultipleObjects@16
 9528      00
 9529 55fd 31D2     		xorl	%edx, %edx
 9530 55ff 85C0     		testl	%eax, %eax
 9531 5601 741E     		je	L502
 9532 5603 83F801   		cmpl	$1, %eax
 9533 5606 7423     		je	L1652
 9534 5608 3D020100 		cmpl	$258, %eax
 9534      00
 9535 560d 0F94C3   		sete	%bl
 9536 5610 31D2     		xorl	%edx, %edx
 9537 5612 88DA     		movb	%bl, %dl
 9538 5614 4A       		decl	%edx
 9539 5615 81E2CAD8 		andl	$-10038, %edx
 9539      FFFF
 9540 561b 81C24C27 		addl	$10060, %edx
 9540      0000
 9541              	L502:
 9542 5621 8D65F4   		leal	-12(%ebp), %esp
 9543 5624 89D0     		movl	%edx, %eax
 9544 5626 5B       		popl	%ebx
 9545 5627 5E       		popl	%esi
 9546 5628 5F       		popl	%edi
 9547 5629 5D       		popl	%ebp
 9548 562a C3       		ret
 9549              	L1652:
 9550 562b 83EC0C   		subl	$12, %esp
 9551 562e 8B7704   		movl	4(%edi), %esi
 9552 5631 56       		pushl	%esi
 9553 5632 E8000000 		call	_ResetEvent@4
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 199


 9553      00
 9554 5637 83C40C   		addl	$12, %esp
 9555 563a 85DB     		testl	%ebx, %ebx
 9556 563c 7423     		je	L505
 9557 563e 83EC0C   		subl	$12, %esp
 9558 5641 8D7330   		leal	48(%ebx), %esi
 9559 5644 56       		pushl	%esi
 9560 5645 E846C8FF 		call	_pthread_mutex_lock
 9560      FF
 9561 564a 83C410   		addl	$16, %esp
 9562 564d 8B7B14   		movl	20(%ebx), %edi
 9563 5650 83FF03   		cmpl	$3, %edi
 9564 5653 7613     		jbe	L1653
 9565 5655 83EC0C   		subl	$12, %esp
 9566 5658 56       		pushl	%esi
 9567 5659 E8B2CBFF 		call	_pthread_mutex_unlock
 9567      FF
 9568 565e 83C410   		addl	$16, %esp
 9569              	L505:
 9570 5661 BA160000 		movl	$22, %edx
 9570      00
 9571 5666 EBB9     		jmp	L502
 9572              	L1653:
 9573 5668 83EC0C   		subl	$12, %esp
 9574 566b C7431404 		movl	$4, 20(%ebx)
 9574      000000
 9575 5672 C7433401 		movl	$1, 52(%ebx)
 9575      000000
 9576 5679 56       		pushl	%esi
 9577 567a E891CBFF 		call	_pthread_mutex_unlock
 9577      FF
 9578 567f 58       		popl	%eax
 9579 5680 A10C0000 		movl	_ptw32_selfThreadKey, %eax
 9579      00
 9580 5685 50       		pushl	%eax
 9581 5686 E875F3FF 		call	_pthread_getspecific
 9581      FF
 9582 568b 83C410   		addl	$16, %esp
 9583 568e 89C3     		movl	%eax, %ebx
 9584 5690 85C0     		testl	%eax, %eax
 9585 5692 740D     		je	L509
 9586 5694 8A888000 		movb	128(%eax), %cl
 9586      0000
 9587 569a 83E101   		andl	$1, %ecx
 9588 569d 84C9     		testb	%cl, %cl
 9589 569f 740D     		je	L515
 9590              	L509:
 9591 56a1 83EC0C   		subl	$12, %esp
 9592 56a4 6AFF     		pushl	$-1
 9593 56a6 E8000000 		call	__endthreadex
 9593      00
 9594 56ab 83C410   		addl	$16, %esp
 9595              	L515:
 9596 56ae 83EC0C   		subl	$12, %esp
 9597 56b1 6A01     		pushl	$1
 9598 56b3 E8F8B6FF 		call	_ptw32_pop_cleanup
 9598      FF
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 200


 9599 56b8 83C410   		addl	$16, %esp
 9600 56bb 85C0     		testl	%eax, %eax
 9601 56bd 75EF     		jne	L515
 9602 56bf EB1E     		jmp	L1654
 9603              		.p2align 4,,7
 9604              	L1651:
 9605 56c1 8D7DE8   		leal	-24(%ebp), %edi
 9606 56c4 E927FFFF 		jmp	L501
 9606      FF
 9607 56c9 8DB42600 		.p2align 4,,7
 9607      000000
 9608              	L498:
 9609 56d0 8D7DE8   		leal	-24(%ebp), %edi
 9610 56d3 C745EC00 		movl	$0, -20(%ebp)
 9610      000000
 9611 56da E911FFFF 		jmp	L501
 9611      FF
 9612              	L1654:
 9613 56df 8D5340   		leal	64(%ebx), %edx
 9614 56e2 56       		pushl	%esi
 9615 56e3 56       		pushl	%esi
 9616 56e4 6A02     		pushl	$2
 9617 56e6 52       		pushl	%edx
 9618 56e7 E8000000 		call	_longjmp
 9618      00
 9619 56ec 8D742600 		.p2align 4,,15
 9620              		.def	_ptw32_timed_eventwait;	.scl	3;	.type	32;	.endef
 9621              	_ptw32_timed_eventwait:
 9622 56f0 55       		pushl	%ebp
 9623 56f1 B8160000 		movl	$22, %eax
 9623      00
 9624 56f6 89E5     		movl	%esp, %ebp
 9625 56f8 57       		pushl	%edi
 9626 56f9 56       		pushl	%esi
 9627 56fa 53       		pushl	%ebx
 9628 56fb 83EC1C   		subl	$28, %esp
 9629 56fe 8B5508   		movl	8(%ebp), %edx
 9630 5701 8B4D0C   		movl	12(%ebp), %ecx
 9631 5704 85D2     		testl	%edx, %edx
 9632 5706 0F849C00 		je	L639
 9632      0000
 9633 570c 83C8FF   		orl	$-1, %eax
 9634 570f 85C9     		testl	%ecx, %ecx
 9635 5711 7466     		je	L643
 9636 5713 8B01     		movl	(%ecx), %eax
 9637 5715 BBE80300 		movl	$1000, %ebx
 9637      00
 9638 571a F7EB     		imull	%ebx
 9639 571c 89C6     		movl	%eax, %esi
 9640 571e 89D7     		movl	%edx, %edi
 9641 5720 8B4104   		movl	4(%ecx), %eax
 9642 5723 6A00     		pushl	$0
 9643 5725 89C1     		movl	%eax, %ecx
 9644 5727 6840420F 		pushl	$1000000
 9644      00
 9645 572c C1F91F   		sarl	$31, %ecx
 9646 572f 0520A107 		addl	$500000, %eax
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 201


 9646      00
 9647 5734 83D100   		adcl	$0, %ecx
 9648 5737 51       		pushl	%ecx
 9649 5738 50       		pushl	%eax
 9650 5739 E8000000 		call	___divdi3
 9650      00
 9651 573e 01C6     		addl	%eax, %esi
 9652 5740 11D7     		adcl	%edx, %edi
 9653 5742 8D55D8   		leal	-40(%ebp), %edx
 9654 5745 891424   		movl	%edx, (%esp)
 9655 5748 E8000000 		call	__ftime
 9655      00
 9656 574d 8B45D8   		movl	-40(%ebp), %eax
 9657 5750 83C410   		addl	$16, %esp
 9658 5753 F7EB     		imull	%ebx
 9659 5755 89C1     		movl	%eax, %ecx
 9660 5757 89D3     		movl	%edx, %ebx
 9661 5759 0FBF45DC 		movswl	-36(%ebp),%eax
 9662 575d 89C2     		movl	%eax, %edx
 9663 575f C1FA1F   		sarl	$31, %edx
 9664 5762 01C1     		addl	%eax, %ecx
 9665 5764 11D3     		adcl	%edx, %ebx
 9666 5766 39DF     		cmpl	%ebx, %edi
 9667 5768 7C4D     		jl	L644
 9668 576a 7F04     		jg	L645
 9669 576c 39CE     		cmpl	%ecx, %esi
 9670 576e 7647     		jbe	L644
 9671              	L645:
 9672 5770 89F0     		movl	%esi, %eax
 9673 5772 29C8     		subl	%ecx, %eax
 9674 5774 83F8FF   		cmpl	$-1, %eax
 9675 5777 7437     		je	L1655
 9676              	L643:
 9677 5779 56       		pushl	%esi
 9678 577a 56       		pushl	%esi
 9679 577b 50       		pushl	%eax
 9680 577c 8B4508   		movl	8(%ebp), %eax
 9681 577f 50       		pushl	%eax
 9682 5780 E8000000 		call	_WaitForSingleObject@8
 9682      00
 9683 5785 89C2     		movl	%eax, %edx
 9684 5787 58       		popl	%eax
 9685 5788 59       		popl	%ecx
 9686 5789 31C0     		xorl	%eax, %eax
 9687 578b 85D2     		testl	%edx, %edx
 9688 578d 7419     		je	L639
 9689 578f 81FA0201 		cmpl	$258, %edx
 9689      0000
 9690 5795 0F94C0   		sete	%al
 9691 5798 25FF0000 		andl	$255, %eax
 9691      00
 9692 579d 48       		decl	%eax
 9693 579e 25CAD8FF 		andl	$-10038, %eax
 9693      FF
 9694 57a3 054C2700 		addl	$10060, %eax
 9694      00
 9695              	L639:
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 202


 9696 57a8 8D65F4   		leal	-12(%ebp), %esp
 9697 57ab 5B       		popl	%ebx
 9698 57ac 5E       		popl	%esi
 9699 57ad 5F       		popl	%edi
 9700 57ae 5D       		popl	%ebp
 9701 57af C3       		ret
 9702              	L1655:
 9703 57b0 B8FEFFFF 		movl	$-2, %eax
 9703      FF
 9704 57b5 EBC2     		jmp	L643
 9705              		.p2align 4,,7
 9706              	L644:
 9707 57b7 31C0     		xorl	%eax, %eax
 9708 57b9 EBBE     		jmp	L643
 9709              	.lcomm _ptw32_h_kernel32,16
 9710              	.lcomm _ptw32_h_quserex,16
 9711 57bb 908D7426 		.p2align 4,,15
 9711      00
 9712              		.def	_ptw32_sem_wait_cleanup;	.scl	3;	.type	32;	.endef
 9713              	_ptw32_sem_wait_cleanup:
 9714 57c0 55       		pushl	%ebp
 9715 57c1 89E5     		movl	%esp, %ebp
 9716 57c3 56       		pushl	%esi
 9717 57c4 53       		pushl	%ebx
 9718 57c5 8B5D08   		movl	8(%ebp), %ebx
 9719 57c8 83EC0C   		subl	$12, %esp
 9720 57cb 8D7304   		leal	4(%ebx), %esi
 9721 57ce 56       		pushl	%esi
 9722 57cf E8BCC6FF 		call	_pthread_mutex_lock
 9722      FF
 9723 57d4 83C410   		addl	$16, %esp
 9724 57d7 85C0     		testl	%eax, %eax
 9725 57d9 7407     		je	L1656
 9726 57db 8D65F8   		leal	-8(%ebp), %esp
 9727 57de 5B       		popl	%ebx
 9728 57df 5E       		popl	%esi
 9729 57e0 5D       		popl	%ebp
 9730 57e1 C3       		ret
 9731              		.p2align 4,,7
 9732              	L1656:
 9733 57e2 50       		pushl	%eax
 9734 57e3 50       		pushl	%eax
 9735 57e4 6A00     		pushl	$0
 9736 57e6 8B5308   		movl	8(%ebx), %edx
 9737 57e9 52       		pushl	%edx
 9738 57ea E8000000 		call	_WaitForSingleObject@8
 9738      00
 9739 57ef 5A       		popl	%edx
 9740 57f0 85C0     		testl	%eax, %eax
 9741 57f2 59       		popl	%ecx
 9742 57f3 7405     		je	L1634
 9743 57f5 8B13     		movl	(%ebx), %edx
 9744 57f7 42       		incl	%edx
 9745 57f8 8913     		movl	%edx, (%ebx)
 9746              	L1634:
 9747 57fa 897508   		movl	%esi, 8(%ebp)
 9748 57fd 8D65F8   		leal	-8(%ebp), %esp
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 203


 9749 5800 5B       		popl	%ebx
 9750 5801 5E       		popl	%esi
 9751 5802 5D       		popl	%ebp
 9752 5803 E908CAFF 		jmp	_pthread_mutex_unlock
 9752      FF
 9753 5808 908DB426 		.p2align 4,,15
 9753      00000000 
 9754              		.def	_ptw32_sem_timedwait_cleanup;	.scl	3;	.type	32;	.endef
 9755              	_ptw32_sem_timedwait_cleanup:
 9756 5810 55       		pushl	%ebp
 9757 5811 89E5     		movl	%esp, %ebp
 9758 5813 57       		pushl	%edi
 9759 5814 56       		pushl	%esi
 9760 5815 53       		pushl	%ebx
 9761 5816 83EC18   		subl	$24, %esp
 9762 5819 8B7D08   		movl	8(%ebp), %edi
 9763 581c 8B1F     		movl	(%edi), %ebx
 9764 581e 8D7304   		leal	4(%ebx), %esi
 9765 5821 56       		pushl	%esi
 9766 5822 E869C6FF 		call	_pthread_mutex_lock
 9766      FF
 9767 5827 83C410   		addl	$16, %esp
 9768 582a 85C0     		testl	%eax, %eax
 9769 582c 7408     		je	L1657
 9770 582e 8D65F4   		leal	-12(%ebp), %esp
 9771 5831 5B       		popl	%ebx
 9772 5832 5E       		popl	%esi
 9773 5833 5F       		popl	%edi
 9774 5834 5D       		popl	%ebp
 9775 5835 C3       		ret
 9776              		.p2align 4,,7
 9777              	L1657:
 9778 5836 50       		pushl	%eax
 9779 5837 50       		pushl	%eax
 9780 5838 6A00     		pushl	$0
 9781 583a 8B5308   		movl	8(%ebx), %edx
 9782 583d 52       		pushl	%edx
 9783 583e E8000000 		call	_WaitForSingleObject@8
 9783      00
 9784 5843 5A       		popl	%edx
 9785 5844 85C0     		testl	%eax, %eax
 9786 5846 59       		popl	%ecx
 9787 5847 7518     		jne	L1637
 9788 5849 8B5704   		movl	4(%edi), %edx
 9789 584c C7020000 		movl	$0, (%edx)
 9789      0000
 9790              	L1638:
 9791 5852 897508   		movl	%esi, 8(%ebp)
 9792 5855 8D65F4   		leal	-12(%ebp), %esp
 9793 5858 5B       		popl	%ebx
 9794 5859 5E       		popl	%esi
 9795 585a 5F       		popl	%edi
 9796 585b 5D       		popl	%ebp
 9797 585c E9AFC9FF 		jmp	_pthread_mutex_unlock
 9797      FF
 9798              		.p2align 4,,7
 9799              	L1637:
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 204


 9800 5861 8B0B     		movl	(%ebx), %ecx
 9801 5863 41       		incl	%ecx
 9802 5864 890B     		movl	%ecx, (%ebx)
 9803 5866 EBEA     		jmp	L1638
 9804 5868 908DB426 		.p2align 4,,15
 9804      00000000 
 9805              		.def	_ptw32_cond_wait_cleanup;	.scl	3;	.type	32;	.endef
 9806              	_ptw32_cond_wait_cleanup:
 9807 5870 55       		pushl	%ebp
 9808 5871 89E5     		movl	%esp, %ebp
 9809 5873 57       		pushl	%edi
 9810 5874 56       		pushl	%esi
 9811 5875 53       		pushl	%ebx
 9812 5876 83EC18   		subl	$24, %esp
 9813 5879 8B5508   		movl	8(%ebp), %edx
 9814 587c 8B5A04   		movl	4(%edx), %ebx
 9815 587f 8B4A08   		movl	8(%edx), %ecx
 9816 5882 894DF0   		movl	%ecx, -16(%ebp)
 9817 5885 8D7B14   		leal	20(%ebx), %edi
 9818 5888 57       		pushl	%edi
 9819 5889 E802C6FF 		call	_pthread_mutex_lock
 9819      FF
 9820 588e 83C410   		addl	$16, %esp
 9821 5891 85C0     		testl	%eax, %eax
 9822 5893 753B     		jne	L1658
 9823 5895 8B7308   		movl	8(%ebx), %esi
 9824 5898 85F6     		testl	%esi, %esi
 9825 589a 7464     		je	L319
 9826 589c 8D4EFF   		leal	-1(%esi), %ecx
 9827 589f 894B08   		movl	%ecx, 8(%ebx)
 9828              	L320:
 9829 58a2 83EC0C   		subl	$12, %esp
 9830 58a5 57       		pushl	%edi
 9831 58a6 E865C9FF 		call	_pthread_mutex_unlock
 9831      FF
 9832 58ab 83C410   		addl	$16, %esp
 9833 58ae 85C0     		testl	%eax, %eax
 9834 58b0 751E     		jne	L1658
 9835 58b2 4E       		decl	%esi
 9836 58b3 7428     		je	L1661
 9837              	L325:
 9838 58b5 8B7D08   		movl	8(%ebp), %edi
 9839 58b8 83EC0C   		subl	$12, %esp
 9840 58bb 8B1F     		movl	(%edi), %ebx
 9841 58bd 53       		pushl	%ebx
 9842 58be E8CDC5FF 		call	_pthread_mutex_lock
 9842      FF
 9843 58c3 83C410   		addl	$16, %esp
 9844 58c6 85C0     		testl	%eax, %eax
 9845 58c8 740B     		je	L317
 9846 58ca 8DB60000 		.p2align 4,,7
 9846      0000
 9847              	L1658:
 9848 58d0 8B4DF0   		movl	-16(%ebp), %ecx
 9849 58d3 8901     		movl	%eax, (%ecx)
 9850              	L317:
 9851 58d5 8D65F4   		leal	-12(%ebp), %esp
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 205


 9852 58d8 5B       		popl	%ebx
 9853 58d9 5E       		popl	%esi
 9854 58da 5F       		popl	%edi
 9855 58db 5D       		popl	%ebp
 9856 58dc C3       		ret
 9857              	L1661:
 9858 58dd 83EC0C   		subl	$12, %esp
 9859 58e0 8D7310   		leal	16(%ebx), %esi
 9860 58e3 56       		pushl	%esi
 9861 58e4 E807E6FF 		call	_sem_post
 9861      FF
 9862 58e9 83C410   		addl	$16, %esp
 9863 58ec 85C0     		testl	%eax, %eax
 9864 58ee 74C5     		je	L325
 9865              	L1660:
 9866 58f0 E8000000 		call	__errno
 9866      00
 9867 58f5 8B00     		movl	(%eax), %eax
 9868 58f7 EBD7     		jmp	L1658
 9869 58f9 8DB42600 		.p2align 4,,7
 9869      000000
 9870              	L319:
 9871 5900 8B5304   		movl	4(%ebx), %edx
 9872 5903 42       		incl	%edx
 9873 5904 895304   		movl	%edx, 4(%ebx)
 9874 5907 81FAFFFF 		cmpl	$1073741823, %edx
 9874      FF3F
 9875 590d 7593     		jne	L320
 9876 590f 83EC0C   		subl	$12, %esp
 9877 5912 8D4B10   		leal	16(%ebx), %ecx
 9878 5915 894DEC   		movl	%ecx, -20(%ebp)
 9879 5918 51       		pushl	%ecx
 9880 5919 E852AAFF 		call	_ptw32_semwait
 9880      FF
 9881 591e 83C410   		addl	$16, %esp
 9882 5921 85C0     		testl	%eax, %eax
 9883 5923 75CB     		jne	L1660
 9884 5925 8B0B     		movl	(%ebx), %ecx
 9885 5927 83EC0C   		subl	$12, %esp
 9886 592a 8B4304   		movl	4(%ebx), %eax
 9887 592d 8B55EC   		movl	-20(%ebp), %edx
 9888 5930 29C1     		subl	%eax, %ecx
 9889 5932 890B     		movl	%ecx, (%ebx)
 9890 5934 52       		pushl	%edx
 9891 5935 E8B6E5FF 		call	_sem_post
 9891      FF
 9892 593a 83C410   		addl	$16, %esp
 9893 593d 85C0     		testl	%eax, %eax
 9894 593f 75AF     		jne	L1660
 9895 5941 C7430400 		movl	$0, 4(%ebx)
 9895      000000
 9896 5948 E955FFFF 		jmp	L320
 9896      FF
 9897              		.def	_ptw32_threadReusePop;	.scl	2;	.type	32;	.endef
 9898              		.def	_ptw32_setthreadpriority;	.scl	2;	.type	32;	.endef
 9899              		.def	__beginthreadex;	.scl	2;	.type	32;	.endef
 9900              		.def	_ptw32_new;	.scl	2;	.type	32;	.endef
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 206


 9901              		.def	_malloc;	.scl	2;	.type	32;	.endef
 9902              		.def	_longjmp;	.scl	2;	.type	32;	.endef
 9903              		.def	_ptw32_pop_cleanup_all;	.scl	2;	.type	32;	.endef
 9904              		.def	_exit;	.scl	2;	.type	32;	.endef
 9905              		.def	__ftime;	.scl	2;	.type	32;	.endef
 9906              		.def	__errno;	.scl	2;	.type	32;	.endef
 9907              		.def	_calloc;	.scl	2;	.type	32;	.endef
 9908              		.def	_ptw32_threadReusePush;	.scl	2;	.type	32;	.endef
 9909              		.def	__endthreadex;	.scl	2;	.type	32;	.endef
 9910              		.def	__setjmp;	.scl	2;	.type	32;	.endef
 9911              		.def	_free;	.scl	2;	.type	32;	.endef
 9912              		.def	_ptw32_processTerminate;	.scl	2;	.type	32;	.endef
 9913 594d 909090   		.section .drectve
 9914              	
 9915 0000 202D6578 		.ascii " -export:pthread_getspecific"
 9915      706F7274 
 9915      3A707468 
 9915      72656164 
 9915      5F676574 
 9916 001c 202D6578 		.ascii " -export:pthread_setspecific"
 9916      706F7274 
 9916      3A707468 
 9916      72656164 
 9916      5F736574 
 9917 0038 202D6578 		.ascii " -export:pthread_key_delete"
 9917      706F7274 
 9917      3A707468 
 9917      72656164 
 9917      5F6B6579 
 9918 0053 202D6578 		.ascii " -export:pthread_key_create"
 9918      706F7274 
 9918      3A707468 
 9918      72656164 
 9918      5F6B6579 
 9919 006e 202D6578 		.ascii " -export:pthread_join"
 9919      706F7274 
 9919      3A707468 
 9919      72656164 
 9919      5F6A6F69 
 9920 0083 202D6578 		.ascii " -export:pthread_detach"
 9920      706F7274 
 9920      3A707468 
 9920      72656164 
 9920      5F646574 
 9921 009a 202D6578 		.ascii " -export:pthread_spin_trylock"
 9921      706F7274 
 9921      3A707468 
 9921      72656164 
 9921      5F737069 
 9922 00b7 202D6578 		.ascii " -export:pthread_spin_unlock"
 9922      706F7274 
 9922      3A707468 
 9922      72656164 
 9922      5F737069 
 9923 00d3 202D6578 		.ascii " -export:pthread_spin_lock"
 9923      706F7274 
 9923      3A707468 
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 207


 9923      72656164 
 9923      5F737069 
 9924 00ed 202D6578 		.ascii " -export:pthread_spin_destroy"
 9924      706F7274 
 9924      3A707468 
 9924      72656164 
 9924      5F737069 
 9925 010a 202D6578 		.ascii " -export:pthread_spin_init"
 9925      706F7274 
 9925      3A707468 
 9925      72656164 
 9925      5F737069 
 9926 0124 202D6578 		.ascii " -export:sem_unlink"
 9926      706F7274 
 9926      3A73656D 
 9926      5F756E6C 
 9926      696E6B
 9927 0137 202D6578 		.ascii " -export:sem_close"
 9927      706F7274 
 9927      3A73656D 
 9927      5F636C6F 
 9927      7365
 9928 0149 202D6578 		.ascii " -export:sem_open"
 9928      706F7274 
 9928      3A73656D 
 9928      5F6F7065 
 9928      6E
 9929 015a 202D6578 		.ascii " -export:sem_getvalue"
 9929      706F7274 
 9929      3A73656D 
 9929      5F676574 
 9929      76616C75 
 9930 016f 202D6578 		.ascii " -export:sem_post_multiple"
 9930      706F7274 
 9930      3A73656D 
 9930      5F706F73 
 9930      745F6D75 
 9931 0189 202D6578 		.ascii " -export:sem_post"
 9931      706F7274 
 9931      3A73656D 
 9931      5F706F73 
 9931      74
 9932 019a 202D6578 		.ascii " -export:sem_timedwait"
 9932      706F7274 
 9932      3A73656D 
 9932      5F74696D 
 9932      65647761 
 9933 01b0 202D6578 		.ascii " -export:sem_wait"
 9933      706F7274 
 9933      3A73656D 
 9933      5F776169 
 9933      74
 9934 01c1 202D6578 		.ascii " -export:sem_trywait"
 9934      706F7274 
 9934      3A73656D 
 9934      5F747279 
 9934      77616974 
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 208


 9935 01d5 202D6578 		.ascii " -export:sem_destroy"
 9935      706F7274 
 9935      3A73656D 
 9935      5F646573 
 9935      74726F79 
 9936 01e9 202D6578 		.ascii " -export:sem_init"
 9936      706F7274 
 9936      3A73656D 
 9936      5F696E69 
 9936      74
 9937 01fa 202D6578 		.ascii " -export:sched_yield"
 9937      706F7274 
 9937      3A736368 
 9937      65645F79 
 9937      69656C64 
 9938 020e 202D6578 		.ascii " -export:sched_getscheduler"
 9938      706F7274 
 9938      3A736368 
 9938      65645F67 
 9938      65747363 
 9939 0229 202D6578 		.ascii " -export:sched_setscheduler"
 9939      706F7274 
 9939      3A736368 
 9939      65645F73 
 9939      65747363 
 9940 0244 202D6578 		.ascii " -export:sched_get_priority_min"
 9940      706F7274 
 9940      3A736368 
 9940      65645F67 
 9940      65745F70 
 9941 0263 202D6578 		.ascii " -export:sched_get_priority_max"
 9941      706F7274 
 9941      3A736368 
 9941      65645F67 
 9941      65745F70 
 9942 0282 202D6578 		.ascii " -export:pthread_getschedparam"
 9942      706F7274 
 9942      3A707468 
 9942      72656164 
 9942      5F676574 
 9943 02a0 202D6578 		.ascii " -export:pthread_setschedparam"
 9943      706F7274 
 9943      3A707468 
 9943      72656164 
 9943      5F736574 
 9944 02be 202D6578 		.ascii " -export:pthread_attr_getinheritsched"
 9944      706F7274 
 9944      3A707468 
 9944      72656164 
 9944      5F617474 
 9945 02e3 202D6578 		.ascii " -export:pthread_attr_setinheritsched"
 9945      706F7274 
 9945      3A707468 
 9945      72656164 
 9945      5F617474 
 9946 0308 202D6578 		.ascii " -export:pthread_attr_getschedparam"
 9946      706F7274 
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 209


 9946      3A707468 
 9946      72656164 
 9946      5F617474 
 9947 032b 202D6578 		.ascii " -export:pthread_attr_setschedparam"
 9947      706F7274 
 9947      3A707468 
 9947      72656164 
 9947      5F617474 
 9948 034e 202D6578 		.ascii " -export:pthread_attr_getschedpolicy"
 9948      706F7274 
 9948      3A707468 
 9948      72656164 
 9948      5F617474 
 9949 0372 202D6578 		.ascii " -export:pthread_attr_setschedpolicy"
 9949      706F7274 
 9949      3A707468 
 9949      72656164 
 9949      5F617474 
 9950 0396 202D6578 		.ascii " -export:pthread_rwlock_trywrlock"
 9950      706F7274 
 9950      3A707468 
 9950      72656164 
 9950      5F72776C 
 9951 03b7 202D6578 		.ascii " -export:pthread_rwlock_tryrdlock"
 9951      706F7274 
 9951      3A707468 
 9951      72656164 
 9951      5F72776C 
 9952 03d8 202D6578 		.ascii " -export:pthread_rwlock_unlock"
 9952      706F7274 
 9952      3A707468 
 9952      72656164 
 9952      5F72776C 
 9953 03f6 202D6578 		.ascii " -export:pthread_rwlock_timedwrlock"
 9953      706F7274 
 9953      3A707468 
 9953      72656164 
 9953      5F72776C 
 9954 0419 202D6578 		.ascii " -export:pthread_rwlock_wrlock"
 9954      706F7274 
 9954      3A707468 
 9954      72656164 
 9954      5F72776C 
 9955 0437 202D6578 		.ascii " -export:pthread_rwlock_timedrdlock"
 9955      706F7274 
 9955      3A707468 
 9955      72656164 
 9955      5F72776C 
 9956 045a 202D6578 		.ascii " -export:pthread_rwlock_rdlock"
 9956      706F7274 
 9956      3A707468 
 9956      72656164 
 9956      5F72776C 
 9957 0478 202D6578 		.ascii " -export:pthread_rwlockattr_setpshared"
 9957      706F7274 
 9957      3A707468 
 9957      72656164 
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 210


 9957      5F72776C 
 9958 049e 202D6578 		.ascii " -export:pthread_rwlockattr_getpshared"
 9958      706F7274 
 9958      3A707468 
 9958      72656164 
 9958      5F72776C 
 9959 04c4 202D6578 		.ascii " -export:pthread_rwlockattr_destroy"
 9959      706F7274 
 9959      3A707468 
 9959      72656164 
 9959      5F72776C 
 9960 04e7 202D6578 		.ascii " -export:pthread_rwlockattr_init"
 9960      706F7274 
 9960      3A707468 
 9960      72656164 
 9960      5F72776C 
 9961 0507 202D6578 		.ascii " -export:pthread_rwlock_destroy"
 9961      706F7274 
 9961      3A707468 
 9961      72656164 
 9961      5F72776C 
 9962 0526 202D6578 		.ascii " -export:pthread_rwlock_init"
 9962      706F7274 
 9962      3A707468 
 9962      72656164 
 9962      5F72776C 
 9963 0542 202D6578 		.ascii " -export:pthread_timechange_handler_np"
 9963      706F7274 
 9963      3A707468 
 9963      72656164 
 9963      5F74696D 
 9964 0568 202D6578 		.ascii " -export:pthread_win32_test_features_np"
 9964      706F7274 
 9964      3A707468 
 9964      72656164 
 9964      5F77696E 
 9965 058f 202D6578 		.ascii " -export:pthread_win32_thread_detach_np"
 9965      706F7274 
 9965      3A707468 
 9965      72656164 
 9965      5F77696E 
 9966 05b6 202D6578 		.ascii " -export:pthread_win32_thread_attach_np"
 9966      706F7274 
 9966      3A707468 
 9966      72656164 
 9966      5F77696E 
 9967 05dd 202D6578 		.ascii " -export:pthread_win32_process_detach_np"
 9967      706F7274 
 9967      3A707468 
 9967      72656164 
 9967      5F77696E 
 9968 0605 202D6578 		.ascii " -export:pthread_win32_process_attach_np"
 9968      706F7274 
 9968      3A707468 
 9968      72656164 
 9968      5F77696E 
 9969 062d 202D6578 		.ascii " -export:pthread_num_processors_np"
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 211


 9969      706F7274 
 9969      3A707468 
 9969      72656164 
 9969      5F6E756D 
 9970 064f 202D6578 		.ascii " -export:pthread_delay_np"
 9970      706F7274 
 9970      3A707468 
 9970      72656164 
 9970      5F64656C 
 9971 0668 202D6578 		.ascii " -export:pthread_getw32threadhandle_np"
 9971      706F7274 
 9971      3A707468 
 9971      72656164 
 9971      5F676574 
 9972 068e 202D6578 		.ascii " -export:pthread_mutexattr_getkind_np"
 9972      706F7274 
 9972      3A707468 
 9972      72656164 
 9972      5F6D7574 
 9973 06b3 202D6578 		.ascii " -export:pthread_mutexattr_setkind_np"
 9973      706F7274 
 9973      3A707468 
 9973      72656164 
 9973      5F6D7574 
 9974 06d8 202D6578 		.ascii " -export:pthread_mutex_trylock"
 9974      706F7274 
 9974      3A707468 
 9974      72656164 
 9974      5F6D7574 
 9975 06f6 202D6578 		.ascii " -export:pthread_mutex_unlock"
 9975      706F7274 
 9975      3A707468 
 9975      72656164 
 9975      5F6D7574 
 9976 0713 202D6578 		.ascii " -export:pthread_mutex_timedlock"
 9976      706F7274 
 9976      3A707468 
 9976      72656164 
 9976      5F6D7574 
 9977 0733 202D6578 		.ascii " -export:pthread_mutex_lock"
 9977      706F7274 
 9977      3A707468 
 9977      72656164 
 9977      5F6D7574 
 9978 074e 202D6578 		.ascii " -export:pthread_mutexattr_gettype"
 9978      706F7274 
 9978      3A707468 
 9978      72656164 
 9978      5F6D7574 
 9979 0770 202D6578 		.ascii " -export:pthread_mutexattr_settype"
 9979      706F7274 
 9979      3A707468 
 9979      72656164 
 9979      5F6D7574 
 9980 0792 202D6578 		.ascii " -export:pthread_mutexattr_setpshared"
 9980      706F7274 
 9980      3A707468 
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 212


 9980      72656164 
 9980      5F6D7574 
 9981 07b7 202D6578 		.ascii " -export:pthread_mutexattr_getpshared"
 9981      706F7274 
 9981      3A707468 
 9981      72656164 
 9981      5F6D7574 
 9982 07dc 202D6578 		.ascii " -export:pthread_mutexattr_destroy"
 9982      706F7274 
 9982      3A707468 
 9982      72656164 
 9982      5F6D7574 
 9983 07fe 202D6578 		.ascii " -export:pthread_mutexattr_init"
 9983      706F7274 
 9983      3A707468 
 9983      72656164 
 9983      5F6D7574 
 9984 081d 202D6578 		.ascii " -export:pthread_mutex_destroy"
 9984      706F7274 
 9984      3A707468 
 9984      72656164 
 9984      5F6D7574 
 9985 083b 202D6578 		.ascii " -export:pthread_mutex_init"
 9985      706F7274 
 9985      3A707468 
 9985      72656164 
 9985      5F6D7574 
 9986 0856 202D6578 		.ascii " -export:pthreadCancelableTimedWait"
 9986      706F7274 
 9986      3A707468 
 9986      72656164 
 9986      43616E63 
 9987 0879 202D6578 		.ascii " -export:pthreadCancelableWait"
 9987      706F7274 
 9987      3A707468 
 9987      72656164 
 9987      43616E63 
 9988 0897 202D6578 		.ascii " -export:pthread_getconcurrency"
 9988      706F7274 
 9988      3A707468 
 9988      72656164 
 9988      5F676574 
 9989 08b6 202D6578 		.ascii " -export:pthread_setconcurrency"
 9989      706F7274 
 9989      3A707468 
 9989      72656164 
 9989      5F736574 
 9990 08d5 202D6578 		.ascii " -export:pthread_equal"
 9990      706F7274 
 9990      3A707468 
 9990      72656164 
 9990      5F657175 
 9991 08eb 202D6578 		.ascii " -export:pthread_self"
 9991      706F7274 
 9991      3A707468 
 9991      72656164 
 9991      5F73656C 
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 213


 9992 0900 202D6578 		.ascii " -export:pthread_once"
 9992      706F7274 
 9992      3A707468 
 9992      72656164 
 9992      5F6F6E63 
 9993 0915 202D6578 		.ascii " -export:pthread_kill"
 9993      706F7274 
 9993      3A707468 
 9993      72656164 
 9993      5F6B696C 
 9994 092a 202D6578 		.ascii " -export:pthread_exit"
 9994      706F7274 
 9994      3A707468 
 9994      72656164 
 9994      5F657869 
 9995 093f 202D6578 		.ascii " -export:pthread_create"
 9995      706F7274 
 9995      3A707468 
 9995      72656164 
 9995      5F637265 
 9996 0956 202D6578 		.ascii " -export:pthread_cond_broadcast"
 9996      706F7274 
 9996      3A707468 
 9996      72656164 
 9996      5F636F6E 
 9997 0975 202D6578 		.ascii " -export:pthread_cond_signal"
 9997      706F7274 
 9997      3A707468 
 9997      72656164 
 9997      5F636F6E 
 9998 0991 202D6578 		.ascii " -export:pthread_cond_timedwait"
 9998      706F7274 
 9998      3A707468 
 9998      72656164 
 9998      5F636F6E 
 9999 09b0 202D6578 		.ascii " -export:pthread_cond_wait"
 9999      706F7274 
 9999      3A707468 
 9999      72656164 
 9999      5F636F6E 
 10000 09ca 202D6578 		.ascii " -export:pthread_cond_destroy"
 10000      706F7274 
 10000      3A707468 
 10000      72656164 
 10000      5F636F6E 
 10001 09e7 202D6578 		.ascii " -export:pthread_cond_init"
 10001      706F7274 
 10001      3A707468 
 10001      72656164 
 10001      5F636F6E 
 10002 0a01 202D6578 		.ascii " -export:pthread_condattr_setpshared"
 10002      706F7274 
 10002      3A707468 
 10002      72656164 
 10002      5F636F6E 
 10003 0a25 202D6578 		.ascii " -export:pthread_condattr_getpshared"
 10003      706F7274 
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 214


 10003      3A707468 
 10003      72656164 
 10003      5F636F6E 
 10004 0a49 202D6578 		.ascii " -export:pthread_condattr_destroy"
 10004      706F7274 
 10004      3A707468 
 10004      72656164 
 10004      5F636F6E 
 10005 0a6a 202D6578 		.ascii " -export:pthread_condattr_init"
 10005      706F7274 
 10005      3A707468 
 10005      72656164 
 10005      5F636F6E 
 10006 0a88 202D6578 		.ascii " -export:ptw32_push_cleanup"
 10006      706F7274 
 10006      3A707477 
 10006      33325F70 
 10006      7573685F 
 10007 0aa3 202D6578 		.ascii " -export:ptw32_pop_cleanup"
 10007      706F7274 
 10007      3A707477 
 10007      33325F70 
 10007      6F705F63 
 10008 0abd 202D6578 		.ascii " -export:pthread_cancel"
 10008      706F7274 
 10008      3A707468 
 10008      72656164 
 10008      5F63616E 
 10009 0ad4 202D6578 		.ascii " -export:pthread_testcancel"
 10009      706F7274 
 10009      3A707468 
 10009      72656164 
 10009      5F746573 
 10010 0aef 202D6578 		.ascii " -export:pthread_setcanceltype"
 10010      706F7274 
 10010      3A707468 
 10010      72656164 
 10010      5F736574 
 10011 0b0d 202D6578 		.ascii " -export:pthread_setcancelstate"
 10011      706F7274 
 10011      3A707468 
 10011      72656164 
 10011      5F736574 
 10012 0b2c 202D6578 		.ascii " -export:pthread_barrierattr_setpshared"
 10012      706F7274 
 10012      3A707468 
 10012      72656164 
 10012      5F626172 
 10013 0b53 202D6578 		.ascii " -export:pthread_barrierattr_getpshared"
 10013      706F7274 
 10013      3A707468 
 10013      72656164 
 10013      5F626172 
 10014 0b7a 202D6578 		.ascii " -export:pthread_barrierattr_destroy"
 10014      706F7274 
 10014      3A707468 
 10014      72656164 
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 215


 10014      5F626172 
 10015 0b9e 202D6578 		.ascii " -export:pthread_barrierattr_init"
 10015      706F7274 
 10015      3A707468 
 10015      72656164 
 10015      5F626172 
 10016 0bbf 202D6578 		.ascii " -export:pthread_barrier_wait"
 10016      706F7274 
 10016      3A707468 
 10016      72656164 
 10016      5F626172 
 10017 0bdc 202D6578 		.ascii " -export:pthread_barrier_destroy"
 10017      706F7274 
 10017      3A707468 
 10017      72656164 
 10017      5F626172 
 10018 0bfc 202D6578 		.ascii " -export:pthread_barrier_init"
 10018      706F7274 
 10018      3A707468 
 10018      72656164 
 10018      5F626172 
 10019 0c19 202D6578 		.ascii " -export:pthread_attr_setscope"
 10019      706F7274 
 10019      3A707468 
 10019      72656164 
 10019      5F617474 
 10020 0c37 202D6578 		.ascii " -export:pthread_attr_getscope"
 10020      706F7274 
 10020      3A707468 
 10020      72656164 
 10020      5F617474 
 10021 0c55 202D6578 		.ascii " -export:pthread_attr_setstacksize"
 10021      706F7274 
 10021      3A707468 
 10021      72656164 
 10021      5F617474 
 10022 0c77 202D6578 		.ascii " -export:pthread_attr_getstacksize"
 10022      706F7274 
 10022      3A707468 
 10022      72656164 
 10022      5F617474 
 10023 0c99 202D6578 		.ascii " -export:pthread_attr_setstackaddr"
 10023      706F7274 
 10023      3A707468 
 10023      72656164 
 10023      5F617474 
 10024 0cbb 202D6578 		.ascii " -export:pthread_attr_getstackaddr"
 10024      706F7274 
 10024      3A707468 
 10024      72656164 
 10024      5F617474 
 10025 0cdd 202D6578 		.ascii " -export:pthread_attr_setdetachstate"
 10025      706F7274 
 10025      3A707468 
 10025      72656164 
 10025      5F617474 
 10026 0d01 202D6578 		.ascii " -export:pthread_attr_getdetachstate"
GAS LISTING C:/DOCUME~1/ADMINI~1/LOCALS~1/Temp/ccspaaaa.s 			page 216


 10026      706F7274 
 10026      3A707468 
 10026      72656164 
 10026      5F617474 
 10027 0d25 202D6578 		.ascii " -export:pthread_attr_destroy"
 10027      706F7274 
 10027      3A707468 
 10027      72656164 
 10027      5F617474 
 10028 0d42 202D6578 		.ascii " -export:pthread_attr_init"
 10028      706F7274 
 10028      3A707468 
 10028      72656164 
 10028      5F617474 
 10029 0d5c 202D6578 		.ascii " -export:ptw32_get_exception_services_code"
 10029      706F7274 
 10029      3A707477 
 10029      33325F67 
 10029      65745F65 
