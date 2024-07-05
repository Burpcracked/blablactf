import subprocess
import os
import logging
from ctypes import *

logging.basicConfig(filename='timber', format='пизде́ц: %(message)s', encoding='utf-16', level=logging.CRITICAL)

try:
    lm = cdll.LoadLibrary('./fastlib.so')
    logging.info('[+] fastmath support enabled')
except OSError as e:
    logging.critical(e)
    exit(-1)

flag = os.environ.get('flag'.upper(), '')
if bool(not flag):
    logging.error("err 14")
    exit(14)

rho = subprocess.run(["perl", "-e", "print ($ENV{'FLAG'} =~ m/^DCTF\{[a-z0-9_]+\}$/)"], capture_output=True)
flag_ascii = create_string_buffer(flag.encode('ascii'))

if rho.stdout != b'1':
    logging.warn("stdout wasn't 1")
    exit(255)

steps = []
steps.append('echo "HMQAADBILZXYcLYRUBAetHi06jh4MnM/wsbydu0nBAccAAIYAw8bCA4NFRABHgYUCRoMCgUXGRILFhEdEw=="')
steps.append('base64 -d -')
steps.append('hex')
data = subprocess.run(' | '.join(steps), capture_output=True, shell=True)
data = bytes.fromhex(data.stdout.decode('ascii'))
half_0 = data[:len(data)>>1]
half_1 = data[len(half_0):]
logging.info(half_1)
pi = 0
for i in range(len(half_0)):
    pi |= lm.f6(half_1[i], half_1[i + 1]) ^ half_0[i]
if pi > 0:
    logging.warn('halves are not working')
    exit(pi)

if lm.f4(flag_ascii) + 0x90 != lm.f5(flag_ascii):
    logging.error("polarity was reversed")
    exit(1)

for (a, b), c in zip([(5, 8), (6, 9), (8,10), (11, 15), (7, 14), (14, 18), (15, 19), (17, 25), (23, 29), (28, 30)], [70, 79, 162, 160, 201, 133, 150, 46, 73, 226]):
    if lm.f5(create_string_buffer(flag[a:b].encode('ascii'))) != c:
        logging.critical("too much radiation")
        exit(15)

logging.debug("success")