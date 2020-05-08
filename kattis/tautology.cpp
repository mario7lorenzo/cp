#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	string wff;
	while (cin >> wff, wff != "0") {
		set<char> vars;
		unordered_map<char, int> sv;
		int piv = 0;
		for (auto i : wff) {
			if (i == 'p' || i == 'q' || i == 'r' || i == 's' || i == 't') {
				if (vars.find(i) == vars.end()) {
					sv[i] = piv;
					piv++;
					vars.insert(i);
				} 
			}
		}
		bool tautology = true;
		string simpen = wff;
		for (int i = 0; i < pow(2, vars.size()); i++) {
			bitset<5> bs(i);
			string tmp = "";
			for (int j = 0; j < wff.size(); j++) {
				if (wff[j] == 'p' || wff[j] == 'q' || wff[j] == 'r' || wff[j] == 's' || wff[j] == 't') {
					tmp += to_string(bs[sv[wff[j]]]);
				}
				else {
					tmp += wff[j];
				}
			}
			wff = tmp;
			piv = 0;
			stack<char> stk;
			char baru, b, a;
			for (auto i : wff) {
				baru = i;
				while (true) {
					if (stk.size() > 0) {
						b = stk.top();
						stk.pop();
						if (b == 'N') {
							if (baru == '1') {
								baru = '0';
							}
							else if (baru == '0') {
								baru = '1';
							}
							else {
								stk.push(b);
								stk.push(baru);
								break;
							}
						}
						else if (b == '0' || b == '1') {
							a = stk.top();
							stk.pop();
							if ((a == 'K' || a == 'A' || a == 'C' || a == 'E') && (baru == '1' || baru == '0')) {
								if (a == 'K') {
									if (b == '1' && baru == '1') {
                                        baru = '1';
                                    }
                                    else if (b == '1' && baru == '0') {
                                        baru = '0';
                                    }
                                    else if (b == '0' && baru == '1') {
                                        baru = '0';
                                    }
                                    else if (b == '0' && baru == '0') {
                                        baru = '0';
                                    }
								}
								if (a == 'A') {
									if (b == '1' && baru == '1') {
                                        baru = '1';
                                    }
                                    else if (b == '1' && baru == '0') {
                                        baru = '1';
                                    }
                                    else if (b == '0' && baru == '1') {
                                        baru = '1';
                                    }
                                    else if (b == '0' && baru == '0') {
                                        baru = '0';
                                    }
								}
								if (a == 'C') {
									if (b == '1' && baru == '1') {
                                        baru = '1';
                                    }
                                    else if (b == '1' && baru == '0') {
                                        baru = '0';
                                    }
                                    else if (b == '0' && baru == '1') {
                                        baru = '1';
                                    }
                                    else if (b == '0' && baru == '0') {
                                        baru = '1';
                                    }
								}
								if (a == 'E') {
									if (b == '1' && baru == '1') {
                                        baru = '1';
                                    }
                                    else if (b == '1' && baru == '0') {
                                        baru = '0';
                                    }
                                    else if (b == '0' && baru == '1') {
                                        baru = '0';
                                    }
                                    else if (b == '0' && baru == '0') {
                                        baru = '1';
                                    }
								}
							}
							else {
								stk.push(a);
								stk.push(b);
								stk.push(baru);
								break;
							}
						}
						else {
							stk.push(b);
							stk.push(baru);
							break;
						}
					}
					else {
						stk.push(baru);
						break;
					}
				}
			}
			if (stk.top() == '0') {
				tautology = false;
				break;
			}
			wff = simpen;
		}
		if (tautology) {
			cout << "tautology" << endl;
		}
		else {
			cout << "not" << endl;
		}
	}
}