import sys
N, M = map(int, input().split())
cant_listen = set()
cant_see = set()
for i in range(N):
    cant_listen.add(sys.stdin.readline().rstrip())
for i in range(M):
    cant_see.add(sys.stdin.readline().rstrip())

cant_listen_and_see = list(cant_listen & cant_see)
cant_listen_and_see.sort()
print(len(cant_listen_and_see))
for dbj in cant_listen_and_see:
    print(dbj)