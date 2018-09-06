# メモリ使用が正しいかチェックする方法
0_sample/hellomemoryleak.cppを用いてメモリリークが発生していることを確認する。
## コンパイル時オプションでチェック
```
$ cd 0_sample
$ g++ hellomemoryleak.cpp -g -fsanitize=address -fno-omit-frame-pointer
$ ./a.out

=================================================================
==6511==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 5 byte(s) in 1 object(s) allocated from:
    #0 0x7f9bf4e86c71 in operator new[](unsigned long) /build/gcc/src/gcc/libsanitizer/asan/asan_new_delete.cc:93
    #1 0x55d7c0445b96 in main /home/fujiwara/Documents/github/ogis-fujiwara/odai/0_sample/hellomemoryleak.cpp:5
    #2 0x7f9bf40c506a in __libc_start_main (/usr/lib/libc.so.6+0x2306a)

SUMMARY: AddressSanitizer: 5 byte(s) leaked in 1 allocation(s).

```
## valgrindでチェック
```
$ cd 0_sample
$ g++ hellowmemoryleak.cpp -g
$ valgrind ./a.out
==6338== Memcheck, a memory error detector
==6338== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==6338== Using Valgrind-3.14.0.GIT and LibVEX; rerun with -h for copyright info
==6338== Command: ./a.out
==6338==
==6338==
==6338== HEAP SUMMARY:
==6338==     in use at exit: 5 bytes in 1 blocks
==6338==   total heap usage: 2 allocs, 1 frees, 72,709 bytes allocated
==6338==
==6338== LEAK SUMMARY:
==6338==    definitely lost: 5 bytes in 1 blocks
==6338==    indirectly lost: 0 bytes in 0 blocks
==6338==      possibly lost: 0 bytes in 0 blocks
==6338==    still reachable: 0 bytes in 0 blocks
==6338==         suppressed: 0 bytes in 0 blocks
==6338== Rerun with --leak-check=full to see details of leaked memory
==6338==
==6338== For counts of detected and suppressed errors, rerun with: -v
==6338== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```