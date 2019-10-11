#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	vector<int> prices;
	vector<int> deces;
	vector<int> preprices;
	int temp;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		prices.push_back(temp);
	}
	if (n == 2)
	{
		preprices.push_back(1);
		preprices.push_back(2 * prices[0] - 1);
	}
	else if (n == 3)
	{
		int a = 3 * prices[1] - 2 * prices[2];
		preprices.push_back(a);
		preprices.push_back(2 * prices[0] - a);
		preprices.push_back(3 * prices[1] - 2 * prices[0]);
	}
	else
	{
		deces.push_back(prices[0] * 2);
		deces.push_back(prices[1] * 3 - prices[0] * 2);
		for (int i = 2; i < n - 1; ++i)
		{
			deces.push_back(3 * prices[i] - 3 * prices[i - 1]);
		}
		deces.push_back(2 * prices[n - 1] - 3 * prices[n - 2]);

		for (int a = 1; a < deces[0]; ++a)
		{

			int dd = 2;
			int state;
			preprices.push_back(a);
			cout << a << ' ';
			preprices.push_back(deces[0] - a);
			cout << deces[0] - a << ' ';
			preprices.push_back(deces[1]);
			cout << deces[1] << ' ';
			int flag = 0;
			for (int i = 0; i < n - 3; ++i)
			{
				int a = deces[i + 2] + preprices[i];
				cout << a << ' ';
				if (a <= -2)
				{
					flag = 1;
					break;
				}
				else if (a == -1)
				{
					a = 1;
					preprices[i] += 2;
				}
				else if (a == 0)
				{
					preprices[i] += 1;
					a = 1;
				}
				preprices.push_back(a);
			}
			else if (preprices[n - 3] + deces[n - 1] != 0)
			{
				flag = 1;
			}

			else if (preprices[n - 2] + preprices[n - 1] != 2 * prices[n - 1])
			{
				preprices.clear();
				continue;
			}

			else break;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		cout << preprices[i] << ' ';
	}
	return 0;
}
