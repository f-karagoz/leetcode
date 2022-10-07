#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> kWeakestRows ( vector<vector<int>>& mat, int k )
	{
		vector<int> result;

		// Count the soldiers in each row
		vector<int> soldiers;

		for (vector<int> vect1D : mat)
		{
			int count = 0;
			for (int x : vect1D)
				if (x == 1)
					count++;
			soldiers.push_back(count);
		}

		// Match with indexes
		int size = soldiers.size();
		vector<int> index;
		for (int i = 0; i < size; i++)
			index.push_back(i);

		// Classic buble sort
		int tempS;
		int tempI;
		for (int i = 0; i < size - 1; i++)
			for (int k = 0; k < size - 1 - i; k++)
				if (soldiers[k + 1] < soldiers[k]
					|| (soldiers[k + 1] == soldiers[k] && index[k + 1] < index[k]))
				{
					tempS = soldiers[k + 1];
					soldiers[k + 1] = soldiers[k];
					soldiers[k] = tempS;

					tempI = index[k + 1];
					index[k + 1] = index[k];
					index[k] = tempI;
				}
		/*
		// Debug
		cout << "Debug:" << endl;

		for (int x : soldiers)
			cout << x << " ";
		cout << endl;

		for (int x : index)
			cout << x << " ";
		cout << endl << endl;
		*/


		for (int i = 0; i < k; i++)
			result.push_back(index[i]);


		return result;
	}

	void printVector(vector<vector<int>>& vec)
	{
		for (vector<int> vect1D : vec)
		{
			for (int x : vect1D)
				cout << x << " ";
			cout << endl;
		}
	}
};

Solution solution;

int main(void)
{
	vector<int> v1 = {1,2,3,4,5};

	for (int i : v1)
		cout << i << " ";
	cout << endl << endl;

	vector<vector<int>> vect
	{
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};

	solution.printVector(vect);

	vector<vector<int>> vectTest
	{
		{1,0,0,0},
		{1,1,0,0},
		{1,0,0,0},
		{1,1,1,0}
	};

	solution.printVector(vectTest);

	solution.kWeakestRows(vectTest,3);

	return 0;
}