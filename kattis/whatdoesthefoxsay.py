def main():
    testcase = int(input())
    for i in range(testcase):
        recording = input().split()
        x = input().split()
        while x[1] != "does":
            recording = [s for s in recording if s != x[2]]
            x = input().split()
        print(" ".join(recording))

if __name__ == '__main__':
    main()