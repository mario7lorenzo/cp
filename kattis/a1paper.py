def main():
	n = int(input())
	possible = False
	kertas = input().split()
	butuh = 1
	ukuran = 1
	tiapukuran = []
	for i in range (len(kertas)):
		butuh = (2 * butuh) - int(kertas[i])
		ukuran += 1;
		if butuh <= 0:
			possible = True
			break
		else:
			tiapukuran.append(butuh)
	if (not possible):
		print("impossible")
	else:
		ind = ukuran - 1
		panjang = 0.000
		keberapa = len(tiapukuran) - 1
		while (ind > 1):
			pangkat = (-3-(2*(ukuran-2)))/4
			pengali = 2**pangkat
			panjang += tiapukuran[keberapa] * pengali
			keberapa -= 1
			ukuran -= 1
			ind -= 1
		panjang += 2**(-3/4)
		print(panjang)



if __name__ == '__main__':
	main()