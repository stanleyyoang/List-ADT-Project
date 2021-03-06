//List ADT Project
//By: Stanley Yoang

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>

using namespace std;

vector<int> cat(vector<int> A, vector<int> B);
vector<int> sort(vector<int> A);
vector<int> slice(vector<int> A, int i, int j);
bool sublist(vector<int> A, vector<int> B);
bool subseq(vector<int> A, vector<int> B);
vector<vector<int>> subseqs(vector<int> A);
vector<vector<int>> sublists(vector<int> A);
bool isPerm(vector<int> A, vector<int> B);
vector<vector<int>> allPerms(vector<int> A);

vector<int> cat(vector<int> A, vector<int> B)
{
	vector<int> temp;

	A.insert(A.end(), B.begin(), B.end());
	temp = A;

	return temp;
}

vector<int> sort(vector<int> A)
{
	int temp, pos;

	for (size_t i = 0; i < A.size(); i++)
	{
		pos = i;
		for (size_t j = i + 1; j < A.size(); j++)
		{
			if (A[j] < A[pos])
			{
				pos = j;
			}
		}

		temp = A[pos];
		A[pos] = A[i];
		A[i] = temp;
	}

	return A;
}

vector<int> slice(vector<int> A, int i, int j)
{
	vector<int> temp;

	if (i > j || i < 0 || j > (int)A.size())
		return temp;

	for (int k = i; k < j; k++)
	{
		temp.push_back(A[k]);
	}

	return temp;
}

bool sublist(vector<int> A, vector<int> B)
{
	vector<int>::iterator it;

	it = search(B.begin(), B.end(), A.begin(), A.end());

	if (it == B.end())
		return false;
	else
		return true;
}

bool subseq(vector<int> A, vector<int> B)
{
	size_t i = 0;

	for (size_t j = 0; j < B.size() && i < A.size(); j++)
	{
		if (A[i] == B[j])
			i++;
	}

	if (i == A.size())
		return true;
	else
		return false;
}

vector<vector<int>> subseqs(vector<int> A)
{
	vector<vector<int>> temp;
	vector<int> x;
	double opsize = pow(2, A.size());

	for (int i = 1; i < opsize; i++)
	{
		for (size_t j = 0; j < A.size(); j++)
		{
			if (i & (1 << j))
			{
				x.push_back(A[j]);
			}
		}
		temp.push_back(x);
		x.clear();
	}

	sort(temp.begin(), temp.end());
	temp.erase(unique(temp.begin(), temp.end()), temp.end());

	return temp;
}

vector<vector<int>> sublists(vector<int> A)
{
	vector<vector<int>> temp;
	vector<int> x;

	for (size_t i = 0; i < A.size(); i++)
	{
		for (size_t j = i; j < A.size(); j++)
		{
			for (size_t k = i; k <= j; k++)
			{
				x.push_back(A[k]);
			}
			temp.push_back(x);
			x.clear();
		}
	}

	sort(temp.begin(), temp.end());
	temp.erase(unique(temp.begin(), temp.end()), temp.end());

	return temp;
}

bool isPerm(vector<int> A, vector<int> B)
{
	if (A.size() != B.size())
		return false;
	else
		return is_permutation(A.begin(), A.end(), B.begin());
}

vector<vector<int>> allPerms(vector<int> A)
{
	vector<vector<int>> temp;

	sort(A.begin(), A.end());

	do {
		temp.push_back(A);
	} while (next_permutation(A.begin(), A.end()));

	return temp;
}

int main()
{
	vector<int> A = { 0, 19, 9, 3, 3};
	vector<int> B = { 4, 2, 2, 1 };

	vector<vector<int>> temp = subseqs(A);

	for (size_t i = 0; i < temp.size(); i++)
	{
		for (size_t j = 0; j < temp[i].size(); j++)
		{
			cout << temp[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}

