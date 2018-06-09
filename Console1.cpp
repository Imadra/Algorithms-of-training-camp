#include <bits/stdc++.h>

using namespace std;

int p[1111];
int sz[1111];
char t[1111], s[111][111], tmp[1111];
char SEP;

int main() {
	SEP = char (30);
	#ifdef AKALI
		freopen ("input.txt", "r", stdin);
	#endif

	int n; scanf ("%d", &n);

	for (int i = 0; i <= n; i++) {
		gets (s[i]);
		sz[i] = strlen (s[i]);
	}

	while (gets (tmp)) {
		int len = strlen (tmp);

		for (int i = 1; i <= n; i++) {
			int tmp = 0;

			for (int j = 0; j < sz[i]; j++)
				t[tmp++] = s[i][j];

			t[tmp++] = SEP;

			for (int j = 0; j < len; j++)
				t[tmp++] = ::tmp[j];

			for (int j = 1; j < sz[i] + len + 1; j++)
            {
				int d = p[j - 1];

				while (d > 0 && t[d] != t[j])
					d = p[d - 1];

				if (t[d] == t[j])
					++d;

				p[j] = d;

				if (d == sz[i]) {
					puts (::tmp);
					goto l;
				}
			}
		}
		l:;
	}
	return 0;
}
