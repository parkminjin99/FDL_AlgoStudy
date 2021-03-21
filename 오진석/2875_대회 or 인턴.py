N, M, K = map(int, input().split()) # N : 여학생 수, M : 남학생 수, K : 인턴쉽 참여인원

while K:
    if N >= 2 * M:
        N = N - 1
        
    else:
        M = M - 1
    K  = K - 1
        
print(min(M, N//2))

