/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cpp -arch arm64 -miphoneos-version-min=7.0 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS15.0.sdk adonis_test.c


/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cpp adonis_test.c


clang -arch arm64 -miphoneos-version-min=7.0 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS15.0.sdk adonis_test.c -S -O3 -o -
    .section    __TEXT,__text,regular,pure_instructions
    .ios_version_min 7, 0    sdk_version 15, 0
    .globl    _main                           ; -- Begin function main
    .p2align    2
_main:                                  ; @main
    .cfi_startproc
; %bb.0:
    mov    w0, #0
    ret
    .cfi_endproc
                                        ; -- End function
.subsections_via_symbols

/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang -arch arm64  -miphoneos-version-min=7.0 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS15.0.sdk adonis_test.c -S -O3 -o -
	.section	__TEXT,__text,regular,pure_instructions
	.build_version ios, 15, 0	sdk_version 15, 0
	.globl	_main                           ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	xorl	%eax, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
.subsections_via_symbols


```
$ /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cpp adonis_test.c -arch arm64 -miphoneos-version-min=7.0 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS15.0.sdk 

/Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS.sdk/usr/include/sys/cdefs.h:825:2: error: Unsupported architecture
#error Unsupported architecture
```
