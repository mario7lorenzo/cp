def main():
    testcase = input()
    for _ in range (int(testcase)):
        n = int(input())
        lst = []
        for _ in range(n):
            name, kelas, gjls = input().split()
            name = name[:-1]
            kelas = kelas.split('-')
            multiplier = 10**12
            panjang = len(kelas)
            kelas = (10-panjang)*['middle'] + kelas
            score = 0
            panjang = 10
            while panjang > 0:
                if kelas[panjang-1] == 'upper':
                    score += 5 * multiplier
                elif kelas[panjang-1] == 'middle':
                    score += 2 * multiplier
                else:
                    score += multiplier
                multiplier /= 10
                panjang -= 1
            lst.append([-score, name])
        lst.sort()
        for i in range (len(lst)):
            print(lst[i])
        print("==============================")


if __name__ == '__main__':
    main()