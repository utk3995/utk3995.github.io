#include &lt;iostream&gt;
#include &lt;stdio.h&gt;
#include &lt;string.h&gt;
using namespace std;

int main()
{

	double pro[110];
	int val[110];
	int t;
	int n;
	int j;
	int count;
	double exp;

	scanf("%d", &t);

	for (int cs = 1; cs &lt;= t; cs++) {
		scanf("%d", &n);
		memset(pro, 0, sizeof pro);
		pro[1] = 1;


		for (int i = 1; i &lt;= n; i++) {
			scanf("%d", val + i);
		}

		exp = val[1];

		for (int i = 2; i &lt;= n; i++) {
			
			for (int k = 1; k &lt;= 6 and i - k &gt;= 1; k++) {
				j = i - k;
				count = min(6, n - j);
				pro[i] = pro[i] + (pro[j] * ( double(1) / double(count)));
			}

			exp = exp + pro[i] * val[i];

		}

		printf("Case %d: %lf\n", cs, exp);

	}

}
