	.arch armv8-a
	.file	"stra.c"
	.text
	.section	.rodata
	.align	3
.LC0:
	.string	"stra.c"
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
	str	xzr, [sp, 40]
	ldr	x0, [sp, 24]
	cmp	x0, 0
	bne	.L3
	adrp	x0, __PRETTY_FUNCTION__.5
	add	x3, x0, :lo12:__PRETTY_FUNCTION__.5
	mov	w2, 14
	adrp	x0, .LC0
	add	x1, x0, :lo12:.LC0
	adrp	x0, .LC1
	add	x0, x0, :lo12:.LC1
	bl	__assert_fail
.L4:
	ldr	x0, [sp, 40]
	add	x0, x0, 1
	str	x0, [sp, 40]
.L3:
	ldr	x1, [sp, 24]
	ldr	x0, [sp, 40]
	add	x0, x1, x0
	ldrb	w0, [x0]
	cmp	w0, 0
	bne	.L4
	ldr	x0, [sp, 40]
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
	str	xzr, [sp, 40]
	ldr	x0, [sp, 16]
	cmp	x0, 0
	bne	.L7
	adrp	x0, __PRETTY_FUNCTION__.4
	add	x3, x0, :lo12:__PRETTY_FUNCTION__.4
	mov	w2, 23
	adrp	x0, .LC0
	add	x1, x0, :lo12:.LC0
	adrp	x0, .LC1
	add	x0, x0, :lo12:.LC1
	bl	__assert_fail
.L7:
	ldr	x0, [sp, 24]
	cmp	x0, 0
	bne	.L9
	adrp	x0, __PRETTY_FUNCTION__.4
	add	x3, x0, :lo12:__PRETTY_FUNCTION__.4
	mov	w2, 24
	adrp	x0, .LC0
	add	x1, x0, :lo12:.LC0
	adrp	x0, .LC2
	add	x0, x0, :lo12:.LC2
	bl	__assert_fail
.L10:
	ldr	x1, [sp, 16]
	ldr	x0, [sp, 40]
	add	x1, x1, x0
	ldr	x2, [sp, 24]
	ldr	x0, [sp, 40]
	add	x0, x2, x0
	ldrb	w1, [x1]
	strb	w1, [x0]
	ldr	x0, [sp, 40]
	add	x0, x0, 1
	str	x0, [sp, 40]
.L9:
	ldr	x1, [sp, 16]
	ldr	x0, [sp, 40]
	add	x0, x1, x0
	ldrb	w0, [x0]
	cmp	w0, 0
	bne	.L10
	ldr	x1, [sp, 24]
	ldr	x0, [sp, 40]
	add	x0, x1, x0
	strb	wzr, [x0]
	ldr	x0, [sp, 24]
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
	str	xzr, [sp, 40]
	str	xzr, [sp, 32]
	ldr	x0, [sp, 16]
	cmp	x0, 0
	bne	.L13
	adrp	x0, __PRETTY_FUNCTION__.3
	add	x3, x0, :lo12:__PRETTY_FUNCTION__.3
	mov	w2, 38
	adrp	x0, .LC0
	add	x1, x0, :lo12:.LC0
	adrp	x0, .LC1
	add	x0, x0, :lo12:.LC1
	bl	__assert_fail
.L13:
	ldr	x0, [sp, 24]
	cmp	x0, 0
	bne	.L15
	adrp	x0, __PRETTY_FUNCTION__.3
	add	x3, x0, :lo12:__PRETTY_FUNCTION__.3
	mov	w2, 39
	adrp	x0, .LC0
	add	x1, x0, :lo12:.LC0
	adrp	x0, .LC2
	add	x0, x0, :lo12:.LC2
	bl	__assert_fail
.L16:
	ldr	x0, [sp, 40]
	add	x0, x0, 1
	str	x0, [sp, 40]
.L15:
	ldr	x1, [sp, 24]
	ldr	x0, [sp, 40]
	add	x0, x1, x0
	ldrb	w0, [x0]
	cmp	w0, 0
	bne	.L16
	b	.L17
.L18:
	ldr	x1, [sp, 16]
	ldr	x0, [sp, 32]
	add	x1, x1, x0
	ldr	x2, [sp, 24]
	ldr	x0, [sp, 40]
	add	x0, x2, x0
	ldrb	w1, [x1]
	strb	w1, [x0]
	ldr	x0, [sp, 32]
	add	x0, x0, 1
	str	x0, [sp, 32]
	ldr	x0, [sp, 40]
	add	x0, x0, 1
	str	x0, [sp, 40]
.L17:
	ldr	x1, [sp, 16]
	ldr	x0, [sp, 32]
	add	x0, x1, x0
	ldrb	w0, [x0]
	cmp	w0, 0
	bne	.L18
	ldr	x1, [sp, 24]
	ldr	x0, [sp, 40]
	add	x0, x1, x0
	strb	wzr, [x0]
	ldr	x0, [sp, 24]
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
	stp	x29, x30, [sp, -48]!
	.cfi_def_cfa_offset 48
	.cfi_offset 29, -48
	.cfi_offset 30, -40
	mov	x29, sp
	str	x0, [sp, 24]
	str	x1, [sp, 16]
	str	xzr, [sp, 40]
	ldr	x0, [sp, 24]
	cmp	x0, 0
	bne	.L21
	adrp	x0, __PRETTY_FUNCTION__.2
	add	x3, x0, :lo12:__PRETTY_FUNCTION__.2
	mov	w2, 58
	adrp	x0, .LC0
	add	x1, x0, :lo12:.LC0
	adrp	x0, .LC3
	add	x0, x0, :lo12:.LC3
	bl	__assert_fail
.L21:
	ldr	x0, [sp, 16]
	cmp	x0, 0
	bne	.L23
	adrp	x0, __PRETTY_FUNCTION__.2
	add	x3, x0, :lo12:__PRETTY_FUNCTION__.2
	mov	w2, 59
	adrp	x0, .LC0
	add	x1, x0, :lo12:.LC0
	adrp	x0, .LC4
	add	x0, x0, :lo12:.LC4
	bl	__assert_fail
.L27:
	ldr	x0, [sp, 24]
	bl	Str_getLength
	mov	x1, x0
	ldr	x0, [sp, 40]
	cmp	x0, x1
	beq	.L24
	ldr	x0, [sp, 16]
	bl	Str_getLength
	mov	x1, x0
	ldr	x0, [sp, 40]
	cmp	x0, x1
	bne	.L25
.L24:
	mov	w0, 0
	b	.L26
.L25:
	ldr	x0, [sp, 40]
	add	x0, x0, 1
	str	x0, [sp, 40]
.L23:
	ldr	x1, [sp, 24]
	ldr	x0, [sp, 40]
	add	x0, x1, x0
	ldrb	w0, [x0]
	strb	w0, [sp, 39]
	ldr	x1, [sp, 16]
	ldr	x0, [sp, 40]
	add	x0, x1, x0
	ldrb	w0, [x0]
	strb	w0, [sp, 38]
	ldrb	w1, [sp, 39]
	ldrb	w0, [sp, 38]
	cmp	w1, w0
	beq	.L27
	ldrb	w0, [sp, 39]
	cmp	w0, 0
	bne	.L28
	mov	w0, -1
	b	.L26
.L28:
	ldrb	w0, [sp, 38]
	cmp	w0, 0
	bne	.L29
	mov	w0, 1
	b	.L26
.L29:
	ldrb	w1, [sp, 39]
	ldrb	w0, [sp, 38]
	cmp	w1, w0
	bls	.L30
	mov	w0, 1
	b	.L26
.L30:
	mov	w0, -1
.L26:
	ldp	x29, x30, [sp], 48
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
	.string	"haystack != NULL"
	.align	3
.LC6:
	.string	"needle != NULL"
	.text
	.align	2
	.type	Str_scan_match, %function
Str_scan_match:
.LFB4:
	.cfi_startproc
	stp	x29, x30, [sp, -64]!
	.cfi_def_cfa_offset 64
	.cfi_offset 29, -64
	.cfi_offset 30, -56
	mov	x29, sp
	str	x0, [sp, 40]
	str	x1, [sp, 32]
	str	x2, [sp, 24]
	str	xzr, [sp, 56]
	ldr	x0, [sp, 40]
	cmp	x0, 0
	bne	.L32
	adrp	x0, __PRETTY_FUNCTION__.1
	add	x3, x0, :lo12:__PRETTY_FUNCTION__.1
	mov	w2, 93
	adrp	x0, .LC0
	add	x1, x0, :lo12:.LC0
	adrp	x0, .LC5
	add	x0, x0, :lo12:.LC5
	bl	__assert_fail
.L32:
	ldr	x0, [sp, 32]
	cmp	x0, 0
	bne	.L34
	adrp	x0, __PRETTY_FUNCTION__.1
	add	x3, x0, :lo12:__PRETTY_FUNCTION__.1
	mov	w2, 94
	adrp	x0, .LC0
	add	x1, x0, :lo12:.LC0
	adrp	x0, .LC6
	add	x0, x0, :lo12:.LC6
	bl	__assert_fail
.L37:
	ldr	x1, [sp, 24]
	ldr	x0, [sp, 56]
	add	x0, x1, x0
	ldr	x1, [sp, 40]
	add	x0, x1, x0
	ldrb	w1, [x0]
	ldr	x2, [sp, 32]
	ldr	x0, [sp, 56]
	add	x0, x2, x0
	ldrb	w0, [x0]
	cmp	w1, w0
	bne	.L40
	ldr	x0, [sp, 56]
	add	x0, x0, 1
	str	x0, [sp, 56]
.L34:
	ldr	x1, [sp, 32]
	ldr	x0, [sp, 56]
	add	x0, x1, x0
	ldrb	w0, [x0]
	cmp	w0, 0
	bne	.L37
	b	.L36
.L40:
	nop
.L36:
	ldr	x1, [sp, 32]
	ldr	x0, [sp, 56]
	add	x0, x1, x0
	ldrb	w0, [x0]
	cmp	w0, 0
	bne	.L38
	mov	w0, 1
	b	.L39
.L38:
	mov	w0, 0
.L39:
	ldp	x29, x30, [sp], 64
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE4:
	.size	Str_scan_match, .-Str_scan_match
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
	str	xzr, [sp, 40]
	ldr	x0, [sp, 24]
	cmp	x0, 0
	bne	.L42
	adrp	x0, __PRETTY_FUNCTION__.0
	add	x3, x0, :lo12:__PRETTY_FUNCTION__.0
	mov	w2, 113
	adrp	x0, .LC0
	add	x1, x0, :lo12:.LC0
	adrp	x0, .LC5
	add	x0, x0, :lo12:.LC5
	bl	__assert_fail
.L42:
	ldr	x0, [sp, 16]
	cmp	x0, 0
	bne	.L43
	adrp	x0, __PRETTY_FUNCTION__.0
	add	x3, x0, :lo12:__PRETTY_FUNCTION__.0
	mov	w2, 114
	adrp	x0, .LC0
	add	x1, x0, :lo12:.LC0
	adrp	x0, .LC6
	add	x0, x0, :lo12:.LC6
	bl	__assert_fail
.L43:
	ldr	x0, [sp, 16]
	ldrb	w0, [x0]
	cmp	w0, 0
	bne	.L46
	ldr	x0, [sp, 24]
	b	.L45
.L48:
	ldr	x1, [sp, 24]
	ldr	x0, [sp, 40]
	add	x0, x1, x0
	ldrb	w1, [x0]
	ldr	x0, [sp, 16]
	ldrb	w0, [x0]
	cmp	w1, w0
	bne	.L47
	ldr	x2, [sp, 40]
	ldr	x1, [sp, 16]
	ldr	x0, [sp, 24]
	bl	Str_scan_match
	str	w0, [sp, 36]
	ldr	w0, [sp, 36]
	cmp	w0, 1
	bne	.L47
	ldr	x1, [sp, 24]
	ldr	x0, [sp, 40]
	add	x0, x1, x0
	b	.L45
.L47:
	ldr	x0, [sp, 40]
	add	x0, x0, 1
	str	x0, [sp, 40]
.L46:
	ldr	x1, [sp, 24]
	ldr	x0, [sp, 40]
	add	x0, x1, x0
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
