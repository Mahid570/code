
def solve():
    n = int(input())
    s = input()

    freq = [0] * 26
    v = []

    for c in s:
        freq[ord(c) - ord('a')] += 1

        if not v or v[-1][0] != c:
            v.append([c, 1])
        else:
            v[-1][1] += 1

    mx = max(freq)

    if len(v) > 3:
        print("NO")
        return

    if len(v) <= 2:
        print("YES")
        return

    mid = n // 2
    pos = v[0][1]

    if mid >= pos + v[1][1]:
        print("NO")
        return

    c = v[1][0]
    cnt = freq[ord(c) - ord('a')]

    if cnt != mx:
        print("NO")
        return

    if n % 2:
        print("YES" if 2 * cnt > n else "NO")
    else:
        if s[mid-1] != c or s[mid] != c:
            print("NO")
            return

        print("YES" if 2 * cnt >= n else "NO")


for _ in range(int(input())):
    solve()
