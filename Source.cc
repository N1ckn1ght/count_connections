#include <iostream>
#include <map>

using namespace std;

void merge(map <int, int>& dict, int a, int b, int x, int size) {
	for (int i = 0; i < size; i++) {
		if (dict[i] == a || dict[i] == b) {
			dict[i] = x;
		}
	}
}

int main() {
	int n;
	cin >> n;
	map <int, int> dict;
	
	for (int i = 1; i <= n; i++) {
		dict[i] = 0;
	}

	int a, b, 
		i = 0, merged = 0;

	while (cin >> a >> b) {

		if (dict.find(a) != dict.end() && dict.find(b) != dict.end()) {

			if (dict[a] == 0 && dict[b] == 0) {
				dict[a] = ++i;
				dict[b] = i;
			}

			else if (dict[a] == 0 || dict[b] == 0) {
				if (dict[a] == 0) {
					dict[a] = dict[b];
				}
				else {
					dict[b] = dict[a];
				}
			}

			else {
				merge(dict, dict[a], dict[b], ++i, n);
				merged += 2;
			}

		}
	}

	for (int j = 1; j <= n; j++) {
		if (dict[j] == 0) {
			i++;
		}
	}

  // Остановить выплонение программы можно с помощью отправки Ctrl + Z символа (это EOF).
	cout << endl << "The answer is: " << (i - merged - 1) << endl;

}
