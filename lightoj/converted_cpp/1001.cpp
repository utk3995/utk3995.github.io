#include &lt;bits/stdc++.h&gt;
using namespace std;
int main()
{
	int t;
	cin&gt;&gt;t;
	while (t--){
		int n;
		cin&gt;&gt;n;
		if (n&gt;10)
			cout&lt;&lt;n-10&lt;&lt;" "&lt;&lt;10&lt;&lt;endl;
		else
			cout&lt;&lt;0&lt;&lt;" "&lt;&lt;n&lt;&lt;endl;
	}
	return 0;
}


