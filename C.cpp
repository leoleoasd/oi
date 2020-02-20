pwn:     file format elf64-x86-64


Disassembly of section .init:

0000000000400470 <_init>:
400470:	48 83 ec 08          	sub    $0x8,%rsp
400474:	48 8b 05 7d 0b 20 00 	mov    0x200b7d(%rip),%rax        # 600ff8 <__gmon_start__>
40047b:	48 85 c0             	test   %rax,%rax
40047e:	74 02                	je     400482 <_init+0x12>
400480:	ff d0                	callq  *%rax
400482:	48 83 c4 08          	add    $0x8,%rsp
400486:	c3                   	retq

Disassembly of section .plt:

0000000000400490 <.plt>:
400490:	ff 35 72 0b 20 00    	pushq  0x200b72(%rip)        # 601008 <_GLOBAL_OFFSET_TABLE_+0x8>
400496:	ff 25 74 0b 20 00    	jmpq   *0x200b74(%rip)        # 601010 <_GLOBAL_OFFSET_TABLE_+0x10>
40049c:	0f 1f 40 00          	nopl   0x0(%rax)

00000000004004a0 <write@plt>:
4004a0:	ff 25 72 0b 20 00    	jmpq   *0x200b72(%rip)        # 601018 <write@GLIBC_2.2.5>
4004a6:	68 00 00 00 00       	pushq  $0x0
4004ab:	e9 e0 ff ff ff       	jmpq   400490 <.plt>

00000000004004b0 <strlen@plt>:
4004b0:	ff 25 6a 0b 20 00    	jmpq   *0x200b6a(%rip)        # 601020 <strlen@GLIBC_2.2.5>
4004b6:	68 01 00 00 00       	pushq  $0x1
4004bb:	e9 d0 ff ff ff       	jmpq   400490 <.plt>

00000000004004c0 <system@plt>:
4004c0:	ff 25 62 0b 20 00    	jmpq   *0x200b62(%rip)        # 601028 <system@GLIBC_2.2.5>
4004c6:	68 02 00 00 00       	pushq  $0x2
4004cb:	e9 c0 ff ff ff       	jmpq   400490 <.plt>

00000000004004d0 <read@plt>:
4004d0:	ff 25 5a 0b 20 00    	jmpq   *0x200b5a(%rip)        # 601030 <read@GLIBC_2.2.5>
4004d6:	68 03 00 00 00       	pushq  $0x3
4004db:	e9 b0 ff ff ff       	jmpq   400490 <.plt>

Disassembly of section .text:

00000000004004e0 <_start>:
4004e0:	31 ed                	xor    %ebp,%ebp
4004e2:	49 89 d1             	mov    %rdx,%r9
4004e5:	5e                   	pop    %rsi
4004e6:	48 89 e2             	mov    %rsp,%rdx
4004e9:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
4004ed:	50                   	push   %rax
4004ee:	54                   	push   %rsp
4004ef:	49 c7 c0 f0 06 40 00 	mov    $0x4006f0,%r8
4004f6:	48 c7 c1 80 06 40 00 	mov    $0x400680,%rcx
4004fd:	48 c7 c7 0a 06 40 00 	mov    $0x40060a,%rdi
400504:	ff 15 e6 0a 20 00    	callq  *0x200ae6(%rip)        # 600ff0 <__libc_start_main@GLIBC_2.2.5>
40050a:	f4                   	hlt
40050b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000400510 <deregister_tm_clones>:
400510:	b8 4f 10 60 00       	mov    $0x60104f,%eax
400515:	55                   	push   %rbp
400516:	48 2d 48 10 60 00    	sub    $0x601048,%rax
40051c:	48 83 f8 0e          	cmp    $0xe,%rax
400520:	48 89 e5             	mov    %rsp,%rbp
400523:	76 1b                	jbe    400540 <deregister_tm_clones+0x30>
400525:	b8 00 00 00 00       	mov    $0x0,%eax
40052a:	48 85 c0             	test   %rax,%rax
40052d:	74 11                	je     400540 <deregister_tm_clones+0x30>
40052f:	5d                   	pop    %rbp
400530:	bf 48 10 60 00       	mov    $0x601048,%edi
400535:	ff e0                	jmpq   *%rax
400537:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
40053e:	00 00
400540:	5d                   	pop    %rbp
400541:	c3                   	retq
400542:	0f 1f 40 00          	nopl   0x0(%rax)
400546:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
40054d:	00 00 00

0000000000400550 <register_tm_clones>:
400550:	be 48 10 60 00       	mov    $0x601048,%esi
400555:	55                   	push   %rbp
400556:	48 81 ee 48 10 60 00 	sub    $0x601048,%rsi
40055d:	48 c1 fe 03          	sar    $0x3,%rsi
400561:	48 89 e5             	mov    %rsp,%rbp
400564:	48 89 f0             	mov    %rsi,%rax
400567:	48 c1 e8 3f          	shr    $0x3f,%rax
40056b:	48 01 c6             	add    %rax,%rsi
40056e:	48 d1 fe             	sar    %rsi
400571:	74 15                	je     400588 <register_tm_clones+0x38>
400573:	b8 00 00 00 00       	mov    $0x0,%eax
400578:	48 85 c0             	test   %rax,%rax
40057b:	74 0b                	je     400588 <register_tm_clones+0x38>
40057d:	5d                   	pop    %rbp
40057e:	bf 48 10 60 00       	mov    $0x601048,%edi
400583:	ff e0                	jmpq   *%rax
400585:	0f 1f 00             	nopl   (%rax)
400588:	5d                   	pop    %rbp
400589:	c3                   	retq
40058a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000400590 <__do_global_dtors_aux>:
400590:	80 3d b1 0a 20 00 00 	cmpb   $0x0,0x200ab1(%rip)        # 601048 <__TMC_END__>
400597:	75 11                	jne    4005aa <__do_global_dtors_aux+0x1a>
400599:	55                   	push   %rbp
40059a:	48 89 e5             	mov    %rsp,%rbp
40059d:	e8 6e ff ff ff       	callq  400510 <deregister_tm_clones>
4005a2:	5d                   	pop    %rbp
4005a3:	c6 05 9e 0a 20 00 01 	movb   $0x1,0x200a9e(%rip)        # 601048 <__TMC_END__>
4005aa:	f3 c3                	repz retq
4005ac:	0f 1f 40 00          	nopl   0x0(%rax)

00000000004005b0 <frame_dummy>:
4005b0:	bf 18 0e 60 00       	mov    $0x600e18,%edi
4005b5:	48 83 3f 00          	cmpq   $0x0,(%rdi)
4005b9:	75 05                	jne    4005c0 <frame_dummy+0x10>
4005bb:	eb 93                	jmp    400550 <register_tm_clones>
4005bd:	0f 1f 00             	nopl   (%rax)
4005c0:	b8 00 00 00 00       	mov    $0x0,%eax
4005c5:	48 85 c0             	test   %rax,%rax
4005c8:	74 f1                	je     4005bb <frame_dummy+0xb>
4005ca:	55                   	push   %rbp
4005cb:	48 89 e5             	mov    %rsp,%rbp
4005ce:	ff d0                	callq  *%rax
4005d0:	5d                   	pop    %rbp
4005d1:	e9 7a ff ff ff       	jmpq   400550 <register_tm_clones>

00000000004005d6 <shell>:
4005d6:	55                   	push   %rbp
4005d7:	48 89 e5             	mov    %rsp,%rbp
4005da:	48 8d 3d 23 01 00 00 	lea    0x123(%rip),%rdi        # 400704 <_IO_stdin_used+0x4>
4005e1:	e8 da fe ff ff       	callq  4004c0 <system@plt>
4005e6:	90                   	nop
4005e7:	5d                   	pop    %rbp
4005e8:	c3                   	retq

00000000004005e9 <vuln>:
4005e9:	55                   	push   %rbp
4005ea:	48 89 e5             	mov    %rsp,%rbp
4005ed:	48 83 ec 10          	sub    $0x10,%rsp
4005f1:	48 8d 45 f6          	lea    -0xa(%rbp),%rax
4005f5:	ba 50 00 00 00       	mov    $0x50,%edx
4005fa:	48 89 c6             	mov    %rax,%rsi
4005fd:	bf 00 00 00 00       	mov    $0x0,%edi
400602:	e8 c9 fe ff ff       	callq  4004d0 <read@plt>
400607:	90                   	nop
400608:	c9                   	leaveq
400609:	c3                   	retq

000000000040060a <main>:
40060a:	55                   	push   %rbp
40060b:	48 89 e5             	mov    %rsp,%rbp
40060e:	48 83 ec 20          	sub    $0x20,%rsp
400612:	48 b8 57 65 6c 63 6f 	movabs $0x20656d6f636c6557,%rax
400619:	6d 65 20
40061c:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
400620:	48 b8 74 6f 20 4a 61 	movabs $0x276b63614a206f74,%rax
400627:	63 6b 27
40062a:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
40062e:	48 b8 73 20 50 77 6e 	movabs $0x2e2e2e6e77502073,%rax
400635:	2e 2e 2e
400638:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
40063c:	66 c7 45 f8 0a 00    	movw   $0xa,-0x8(%rbp)
400642:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
400646:	48 89 c7             	mov    %rax,%rdi
400649:	e8 62 fe ff ff       	callq  4004b0 <strlen@plt>
40064e:	48 89 c2             	mov    %rax,%rdx
400651:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
400655:	48 89 c6             	mov    %rax,%rsi
400658:	bf 01 00 00 00       	mov    $0x1,%edi
40065d:	e8 3e fe ff ff       	callq  4004a0 <write@plt>
400662:	b8 00 00 00 00       	mov    $0x0,%eax
400667:	e8 7d ff ff ff       	callq  4005e9 <vuln>
40066c:	b8 00 00 00 00       	mov    $0x0,%eax
400671:	c9                   	leaveq
400672:	c3                   	retq
400673:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
40067a:	00 00 00
40067d:	0f 1f 00             	nopl   (%rax)

0000000000400680 <__libc_csu_init>:
400680:	41 57                	push   %r15
400682:	41 56                	push   %r14
400684:	41 89 ff             	mov    %edi,%r15d
400687:	41 55                	push   %r13
400689:	41 54                	push   %r12
40068b:	4c 8d 25 76 07 20 00 	lea    0x200776(%rip),%r12        # 600e08 <__frame_dummy_init_array_entry>
400692:	55                   	push   %rbp
400693:	48 8d 2d 76 07 20 00 	lea    0x200776(%rip),%rbp        # 600e10 <__init_array_end>
40069a:	53                   	push   %rbx
40069b:	49 89 f6             	mov    %rsi,%r14
40069e:	49 89 d5             	mov    %rdx,%r13
4006a1:	4c 29 e5             	sub    %r12,%rbp
4006a4:	48 83 ec 08          	sub    $0x8,%rsp
4006a8:	48 c1 fd 03          	sar    $0x3,%rbp
4006ac:	e8 bf fd ff ff       	callq  400470 <_init>
4006b1:	48 85 ed             	test   %rbp,%rbp
4006b4:	74 20                	je     4006d6 <__libc_csu_init+0x56>
4006b6:	31 db                	xor    %ebx,%ebx
4006b8:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
4006bf:	00
4006c0:	4c 89 ea             	mov    %r13,%rdx
4006c3:	4c 89 f6             	mov    %r14,%rsi
4006c6:	44 89 ff             	mov    %r15d,%edi
4006c9:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
4006cd:	48 83 c3 01          	add    $0x1,%rbx
4006d1:	48 39 dd             	cmp    %rbx,%rbp
4006d4:	75 ea                	jne    4006c0 <__libc_csu_init+0x40>
4006d6:	48 83 c4 08          	add    $0x8,%rsp
4006da:	5b                   	pop    %rbx
4006db:	5d                   	pop    %rbp
4006dc:	41 5c                	pop    %r12
4006de:	41 5d                	pop    %r13
4006e0:	41 5e                	pop    %r14
4006e2:	41 5f                	pop    %r15
4006e4:	c3                   	retq
4006e5:	90                   	nop
4006e6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
4006ed:	00 00 00

00000000004006f0 <__libc_csu_fini>:
4006f0:	f3 c3                	repz retq

Disassembly of section .fini:

00000000004006f4 <_fini>:
4006f4:	48 83 ec 08          	sub    $0x8,%rsp
4006f8:	48 83 c4 08          	add    $0x8,%rsp
4006fc:	c3                   	retq