	.arch armv8-a
	.file	"strp.c"
	.text
	.section	.rodata
	.align	3
.LC0:
	.string	"strp.c"
	.align	3
.LC1:
	.string	"src != NULL"
	.text
	.align	2
	.global	Str_getLength
	.type	Str_getLength, %function
Str_getLength:
.LFB0:
	.cfi_startproc
	stp	x29, x30, [sp, -48]!
	.cfi_def_cfa_offset 48
	.cfi_offset 29, -48
	.cfi_offset 30, -40
	mov	x29, sp
	str	x0, [sp, 24]
	ldr	x0, [sp, 24]
	cmp	x0, 0
	bne	.L2
	adrp	x0, __PRETTY_FUNCTION__.5
	add	x3, x0, :lo12:__PRETTY_FUNCTION__.5
	mov	w2, 14
	adrp	x0, .LC0
	add	x1, x0, :lo12:.LC0
	adrp	x0, .LC1
	add	x0, x0, :lo12:.LC1
	bl	__assert_fail
.L2:
	ldr	x0, [sp, 24]
	str	x0, [sp, 40]
	b	.L3
.L4:
	ldr	x0, [sp, 40]
	add	x0, x0, 1
	str	x0, [sp, 40]
.L3:
	ldr	x0, [sp, 40]
	ldrb	w0, [x0]
	cmp	w0, 0
	bne	.L4
	ldr	x1, [sp, 40]
	ldr	x0, [sp, 24]
	sub	x0, x1, x0
	ldp	x29, x30, [sp], 48
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE0:
	.size	Str_getLength, .-Str_getLength
	.section	.rodata
	.align	3
.LC2:
	.string	"out != NULL"
	.text
	.align	2
	.global	Str_copy
	.type	Str_copy, %function
Str_copy:
.LFB1:
	.cfi_startproc
	stp	x29, x30, [sp, -48]!
	.cfi_def_cfa_offset 48
	.cfi_offset 29, -48
	.cfi_offset 30, -40
	mov	x29, sp
	str	x0, [sp, 24]
	str	x1, [sp, 16]
	ldr	x0, [sp, 16]
	cmp	x0, 0
	bne	.L7
	adrp	x0, __PRETTY_FUNCTION__.4
	add	x3, x0, :lo12:__PRETTY_FUNCTION__.4
	mov	w2, 24
	adrp	x0, .LC0
	add	x1, x0, :lo12:.LC0
	adrp	x0, .LC1
	add	x0, x0, :lo12:.LC1
	bl	__assert_fail
.L7:
	ldr	x0, [sp, 24]
	cmp	x0, 0
	bne	.L8
	adrp	x0, __PRETTY_FUNCTION__.4
	add	x3, x0, :lo12:__PRETTY_FUNCTION__.4
	mov	w2, 25
	adrp	x0, .LC0
	add	x1, x0, :lo12:.LC0
	adrp	x0, .LC2
	add	x0, x0, :lo12:.LC2
	bl	__assert_fail
.L8:
	ldr	x0, [sp, 16]
	str	x0, [sp, 40]
	b	.L9
.L10:
	ldr	x0, [sp, 40]
	ldrb	w1, [x0]
	ldr	x0, [sp, 24]
	strb	w1, [x0]
	ldr	x0, [sp, 40]
	add	x0, x0, 1
	str	x0, [sp, 40]
	ldr	x0, [sp, 24]
	add	x0, x0, 1
	str	x0, [sp, 24]
.L9:
	ldr	x0, [sp, 40]
	ldrb	w0, [x0]
	cmp	w0, 0
	bne	.L10
	ldr	x0, [sp, 24]
	strb	wzr, [x0]
	ldr	x1, [sp, 40]
	ldr	x0, [sp, 16]
	sub	x0, x1, x0
	neg	x0, x0
	ldr	x1, [sp, 24]
	add	x0, x1, x0
	ldp	x29, x30, [sp], 48
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE1:
	.size	Str_copy, .-Str_copy
	.align	2
	.global	Str_concat
	.type	Str_concat, %function
Str_concat:
.LFB2:
	.cfi_startproc
	stp	x29, x30, [sp, -48]!
	.cfi_def_cfa_offset 48
	.cfi_offset 29, -48
	.cfi_offset 30, -40
	mov	x29, sp
	str	x0, [sp, 24]
	str	x1, [sp, 16]
	ldr	x0, [sp, 24]
	bl	Str_getLength
	str	x0, [sp, 32]
	ldr	x0, [sp, 16]
	cmp	x0, 0
	bne	.L13
	adrp	x0, __PRETTY_FUNCTION__.3
	add	x3, x0, :lo12:__PRETTY_FUNCTION__.3
	mov	w2, 43
	adrp	x0, .LC0
	add	x1, x0, :lo12:.LC0
	adrp	x0, .LC1
	add	x0, x0, :lo12:.LC1
	bl	__assert_fail
.L13:
	ldr	x0, [sp, 24]
	cmp	x0, 0
	bne	.L14
	adrp	x0, __PRETTY_FUNCTION__.3
	add	x3, x0, :lo12:__PRETTY_FUNCTION__.3
	mov	w2, 44
	adrp	x0, .LC0
	add	x1, x0, :lo12:.LC0
	adrp	x0, .LC2
	add	x0, x0, :lo12:.LC2
	bl	__assert_fail
.L14:
	ldr	x0, [sp, 16]
	str	x0, [sp, 40]
	b	.L15
.L16:
	ldr	x0, [sp, 24]
	add	x0, x0, 1
	str	x0, [sp, 24]
.L15:
	ldr	x0, [sp, 24]
	ldrb	w0, [x0]
	cmp	w0, 0
	bne	.L16
	b	.L17
.L18:
	ldr	x0, [sp, 40]
	ldrb	w1, [x0]
	ldr	x0, [sp, 24]
	strb	w1, [x0]
	ldr	x0, [sp, 24]
	add	x0, x0, 1
	str	x0, [sp, 24]
	ldr	x0, [sp, 40]
	add	x0, x0, 1
	str	x0, [sp, 40]
.L17:
	ldr	x0, [sp, 40]
	ldrb	w0, [x0]
	cmp	w0, 0
	bne	.L18
	ldr	x0, [sp, 24]
	strb	wzr, [x0]
	ldr	x0, [sp, 32]
	sxtw	x0, w0
	neg	x0, x0
	ldr	x2, [sp, 40]
	ldr	x1, [sp, 16]
	sub	x1, x2, x1
	sub	x0, x0, x1
	ldr	x1, [sp, 24]
	add	x0, x1, x0
	ldp	x29, x30, [sp], 48
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE2:
	.size	Str_concat, .-Str_concat
	.section	.rodata
	.align	3
.LC3:
	.string	"s1 != NULL"
	.align	3
.LC4:
	.string	"s2 != NULL"
	.text
	.align	2
	.global	Str_compare
	.type	Str_compare, %function
Str_compare:
.LFB3:
	.cfi_startproc
	stp	x29, x30, [sp, -64]!
	.cfi_def_cfa_offset 64
	.cfi_offset 29, -64
	.cfi_offset 30, -56
	mov	x29, sp
	str	x0, [sp, 24]
	str	x1, [sp, 16]
	ldr	x0, [sp, 24]
	bl	Str_getLength
	str	w0, [sp, 44]
	ldr	x0, [sp, 16]
	bl	Str_getLength
	str	w0, [sp, 40]
	ldr	x0, [sp, 24]
	cmp	x0, 0
	bne	.L21
	adrp	x0, __PRETTY_FUNCTION__.2
	add	x3, x0, :lo12:__PRETTY_FUNCTION__.2
	mov	w2, 67
	adrp	x0, .LC0
	add	x1, x0, :lo12:.LC0
	adrp	x0, .LC3
	add	x0, x0, :lo12:.LC3
	bl	__assert_fail
.L21:
	ldr	x0, [sp, 16]
	cmp	x0, 0
	bne	.L22
	adrp	x0, __PRETTY_FUNCTION__.2
	add	x3, x0, :lo12:__PRETTY_FUNCTION__.2
	mov	w2, 68
	adrp	x0, .LC0
	add	x1, x0, :lo12:.LC0
	adrp	x0, .LC4
	add	x0, x0, :lo12:.LC4
	bl	__assert_fail
.L22:
	ldr	x0, [sp, 24]
	str	x0, [sp, 56]
	ldr	x0, [sp, 16]
	str	x0, [sp, 48]
	b	.L23
.L27:
	ldr	x1, [sp, 56]
	ldr	x0, [sp, 24]
	sub	x1, x1, x0
	ldrsw	x0, [sp, 44]
	cmp	x1, x0
	beq	.L24
	ldr	x1, [sp, 48]
	ldr	x0, [sp, 16]
	sub	x1, x1, x0
	ldrsw	x0, [sp, 40]
	cmp	x1, x0
	bne	.L25
.L24:
	mov	w0, 0
	b	.L26
.L25:
	ldr	x0, [sp, 56]
	add	x0, x0, 1
	str	x0, [sp, 56]
	ldr	x0, [sp, 48]
	add	x0, x0, 1
	str	x0, [sp, 48]
.L23:
	ldr	x0, [sp, 56]
	ldrb	w1, [x0]
	ldr	x0, [sp, 48]
	ldrb	w0, [x0]
	cmp	w1, w0
	beq	.L27
	ldr	x0, [sp, 56]
	ldrb	w0, [x0]
	cmp	w0, 0
	bne	.L28
	mov	w0, -1
	b	.L26
.L28:
	ldr	x0, [sp, 48]
	ldrb	w0, [x0]
	cmp	w0, 0
	bne	.L29
	mov	w0, 1
	b	.L26
.L29:
	ldr	x0, [sp, 56]
	ldrb	w1, [x0]
	ldr	x0, [sp, 48]
	ldrb	w0, [x0]
	cmp	w1, w0
	bls	.L30
	mov	w0, 1
	b	.L26
.L30:
	mov	w0, -1
.L26:
	ldp	x29, x30, [sp], 64
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE3:
	.size	Str_compare, .-Str_compare
	.section	.rodata
	.align	3
.LC5:
	.string	"curr_haystack != NULL"
	.align	3
.LC6:
	.string	"needle != NULL"
	.text
	.align	2
	.type	Str_scan_match, %function
Str_scan_match:
.LFB4:
	.cfi_startproc
	stp	x29, x30, [sp, -48]!
	.cfi_def_cfa_offset 48
	.cfi_offset 29, -48
	.cfi_offset 30, -40
	mov	x29, sp
	str	x0, [sp, 24]
	str	x1, [sp, 16]
	ldr	x0, [sp, 24]
	cmp	x0, 0
	bne	.L32
	adrp	x0, __PRETTY_FUNCTION__.1
	add	x3, x0, :lo12:__PRETTY_FUNCTION__.1
	mov	w2, 107
	adrp	x0, .LC0
	add	x1, x0, :lo12:.LC0
	adrp	x0, .LC5
	add	x0, x0, :lo12:.LC5
	bl	__assert_fail
.L32:
	ldr	x0, [sp, 16]
	cmp	x0, 0
	bne	.L33
	adrp	x0, __PRETTY_FUNCTION__.1
	add	x3, x0, :lo12:__PRETTY_FUNCTION__.1
	mov	w2, 108
	adrp	x0, .LC0
	add	x1, x0, :lo12:.LC0
	adrp	x0, .LC6
	add	x0, x0, :lo12:.LC6
	bl	__assert_fail
.L33:
	ldr	x0, [sp, 16]
	str	x0, [sp, 40]
	ldr	x0, [sp, 24]
	str	x0, [sp, 32]
	b	.L34
.L37:
	ldr	x0, [sp, 32]
	ldrb	w1, [x0]
	ldr	x0, [sp, 40]
	ldrb	w0, [x0]
	cmp	w1, w0
	bne	.L40
	ldr	x0, [sp, 32]
	add	x0, x0, 1
	str	x0, [sp, 32]
	ldr	x0, [sp, 40]
	add	x0, x0, 1
	str	x0, [sp, 40]
.L34:
	ldr	x0, [sp, 40]
	ldrb	w0, [x0]
	cmp	w0, 0
	bne	.L37
	b	.L36
.L40:
	nop
.L36:
	ldr	x0, [sp, 40]
	ldrb	w0, [x0]
	cmp	w0, 0
	bne	.L38
	mov	w0, 1
	b	.L39
.L38:
	mov	w0, 0
.L39:
	ldp	x29, x30, [sp], 48
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE4:
	.size	Str_scan_match, .-Str_scan_match
	.section	.rodata
	.align	3
.LC7:
	.string	"haystack != NULL"
	.text
	.align	2
	.global	Str_search
	.type	Str_search, %function
Str_search:
.LFB5:
	.cfi_startproc
	stp	x29, x30, [sp, -48]!
	.cfi_def_cfa_offset 48
	.cfi_offset 29, -48
	.cfi_offset 30, -40
	mov	x29, sp
	str	x0, [sp, 24]
	str	x1, [sp, 16]
	ldr	x0, [sp, 24]
	cmp	x0, 0
	bne	.L42
	adrp	x0, __PRETTY_FUNCTION__.0
	add	x3, x0, :lo12:__PRETTY_FUNCTION__.0
	mov	w2, 130
	adrp	x0, .LC0
	add	x1, x0, :lo12:.LC0
	adrp	x0, .LC7
	add	x0, x0, :lo12:.LC7
	bl	__assert_fail
.L42:
	ldr	x0, [sp, 16]
	cmp	x0, 0
	bne	.L43
	adrp	x0, __PRETTY_FUNCTION__.0
	add	x3, x0, :lo12:__PRETTY_FUNCTION__.0
	mov	w2, 131
	adrp	x0, .LC0
	add	x1, x0, :lo12:.LC0
	adrp	x0, .LC6
	add	x0, x0, :lo12:.LC6
	bl	__assert_fail
.L43:
	ldr	x0, [sp, 24]
	str	x0, [sp, 40]
	ldr	x0, [sp, 16]
	ldrb	w0, [x0]
	cmp	w0, 0
	bne	.L46
	ldr	x0, [sp, 40]
	b	.L45
.L48:
	ldr	x0, [sp, 40]
	ldrb	w1, [x0]
	ldr	x0, [sp, 16]
	ldrb	w0, [x0]
	cmp	w1, w0
	bne	.L47
	ldr	x1, [sp, 16]
	ldr	x0, [sp, 40]
	bl	Str_scan_match
	str	w0, [sp, 36]
	ldr	w0, [sp, 36]
	cmp	w0, 1
	bne	.L47
	ldr	x0, [sp, 40]
	b	.L45
.L47:
	ldr	x0, [sp, 40]
	add	x0, x0, 1
	str	x0, [sp, 40]
.L46:
	ldr	x0, [sp, 40]
	ldrb	w0, [x0]
	cmp	w0, 0
	bne	.L48
	mov	x0, 0
.L45:
	ldp	x29, x30, [sp], 48
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE5:
	.size	Str_search, .-Str_search
	.section	.rodata
	.align	3
	.type	__PRETTY_FUNCTION__.5, %object
	.size	__PRETTY_FUNCTION__.5, 14
__PRETTY_FUNCTION__.5:
	.string	"Str_getLength"
	.align	3
	.type	__PRETTY_FUNCTION__.4, %object
	.size	__PRETTY_FUNCTION__.4, 9
__PRETTY_FUNCTION__.4:
	.string	"Str_copy"
	.align	3
	.type	__PRETTY_FUNCTION__.3, %object
	.size	__PRETTY_FUNCTION__.3, 11
__PRETTY_FUNCTION__.3:
	.string	"Str_concat"
	.align	3
	.type	__PRETTY_FUNCTION__.2, %object
	.size	__PRETTY_FUNCTION__.2, 12
__PRETTY_FUNCTION__.2:
	.string	"Str_compare"
	.align	3
	.type	__PRETTY_FUNCTION__.1, %object
	.size	__PRETTY_FUNCTION__.1, 15
__PRETTY_FUNCTION__.1:
	.string	"Str_scan_match"
	.align	3
	.type	__PRETTY_FUNCTION__.0, %object
	.size	__PRETTY_FUNCTION__.0, 11
__PRETTY_FUNCTION__.0:
	.string	"Str_search"
	.ident	"GCC: (GNU) 11.3.1 20221121 (Red Hat 11.3.1-4)"
	.section	.note.GNU-stack,"",@progbits
