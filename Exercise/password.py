from re import T
from types import CodeType
import string

ENC = [171, 179, 161, 213, 185, 187, 172, 174, 213, 204, 200, 203, 192]

def check(inp):
    inputString = list(map(lambda x: ord(x), inp))
    payload = bytes.fromhex('67005a00650144005d165a026502640041005a036500a0046503a101010071086500610564015300')
    code = CodeType(0, 0, 0, 0, 4, 64, payload, (248, None),  ('ret', 'inputString', 'i', 'step', 'append', 'returnVal'), (), '<source>', '<module>', 2, b'\x04\x01\x08\x01\x08\x01\x0c\x01')
    exec(code)
    if returnVal == ENC:
        return True
    else:
        return False

def main():
    part1 = 'SKY-'
    part2 = ''
    part3 = ''
    alphabet_string = string.ascii_uppercase
    alphabet_list = list(alphabet_string)
    
    for c1 in alphabet_list:
        part2 += c1
        for c2 in alphabet_list:
            part2 += c2
            for c3 in alphabet_list:
                part2 += c3
                for c4 in alphabet_list:
                    part2 += c4
                    for i in range(10000):
                        part3 = '-'
                        part3 += f'{i:04d}'
                        str1 = part1 + part2 + part3
                        if (check(str1)):
                            print(str1)
                            quit()
                    part2 = part2[:-1]
                part2 = part2[:-1]
            part2 = part2[:-1]
        part2 = part2[:-1]
    
main()
                    