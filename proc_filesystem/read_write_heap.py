#!/usr/bin/python3


"""script that finds a string in the heap of a running process"""
import sys


def init():
    """Initial"""
    if len(sys.argv) != 4:
        print('Usage: read_write_heap.py pid s r')
        exit(1)
    pid = sys.argv[1]
    s = sys.argv[2]
    r = sys.argv[3]

    try:
        maps_file = open('/proc/{}/maps'.format(pid), 'r')
    except Exception as e:
        print(e)
        exit(1)

    try:
        mem_file = open('/proc/{}/mem'.format(pid), 'r+b', 0)
    except Exception as e:
        maps_file.close()
        print(e)
        exit(1)

    for i in maps_file.readlines():
        split_line = i.split()
        if '[heap]' in split_line:
            mem = split_line[0].split('-')
            mem_start = int(mem[0], 16)
            mem_end = int(mem[1], 16)
            mem_file.seek(mem_start)
            x = mem_file.read(mem_end - mem_start)
            y = x.find(str.encode(s))

            if y == -1:
                break

            mem_file.seek(mem_start + y)
            mem_file.write(str.encode(r) + b'\x00')
            break

    mem_file.close()
    maps_file.close()


if __name__ == '__main__':
    init()