def main():
    testcase = input()
    for i in range (int(testcase)):
        length, m = [int(x) for x in input().split()]
        lst = [int(x) for x in input().split()]
        counter = 0
        pre = 0
        aft = 0
        maxi = -10**9
        verifier = False
        for i in range (len(lst)):
            if lst[i] < m:
                if verifier:
                    maxi = max(maxi, pre) 
                pre = 0
                aft = 0
                verifier = False
                # print("ini pre2")
                # print(pre)
                # print("ini aft2")
                # print(aft)
                # print("ini maxi skrg")
                # print(maxi)
                # print("ini verifier")
                # print(verifier)
            if lst[i] == m:
                if verifier == False:
                    verifier = True
                    pre += lst[i]
                    aft = lst[i]
                    # print("ini pre3")
                    # print(pre)
                    # print("ini aft3")
                    # print(aft)
                    # print("ini maxi skrg")
                    # print(maxi)
                    # print("ini verifier")
                    # print(verifier)
                else:
                    maxi = max(maxi, pre)
                    pre = aft
                    aft = lst[i]
                    # print("ini pre4")
                    # print(pre)
                    # print("ini aft4")
                    # print(aft)
                    # print("ini maxi skrg")
                    # print(maxi)
                    # print("ini verifier")
                    # print(verifier)
            if lst[i] > m:
                pre += lst[i]
                aft += lst[i]
                # print("ini pre5")
                # print(pre)
                # print("ini aft5")
                # print(aft)
                # print("ini maxi skrg")
                # print(maxi)
                # print("ini verifier")
                # print(verifier)
        if verifier:
            maxi = max(maxi, pre)
        print(maxi)






if __name__ == '__main__':
    main()
