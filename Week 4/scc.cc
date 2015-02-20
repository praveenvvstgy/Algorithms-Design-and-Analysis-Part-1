#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ssccount;

void dfs_find_ordering(vector<vector<int> > &graph, int i, vector<bool> &explored, vector<int> &ordering, int &t) {
	explored[i] = true;
	for(int j: graph[i]) {
		if (!explored[j])
		{
			dfs_find_ordering(graph, j, explored, ordering, t);
		}
	}
	t++;
	ordering[t] = i;
}
void dfs_find_scc(vector<vector<int> > &graph, int i, vector<bool> &explored, int &s) {
	explored[i] = true;
	ssccount[s]++;
	for(int j: graph[i]) {
		if (!explored[j])
		{
			dfs_find_scc(graph, j, explored, s);
		}
	}
}
int main()
{
	int n, tail, head, t, s;
	cin>>n;
	vector<vector<int> > graph(n), rgraph(n);
	vector<bool> explored(n, false);
	vector<int> ordering(n);
	ssccount = vector<int>(n);
	while(cin>>tail && cin>>head) {
		graph[tail - 1].push_back(head - 1);
		rgraph[head - 1].push_back(tail - 1);
	}

	t = -1;
	for(int i = n - 1; i >= 0; i--) {
		if (!explored[i])
		{
			s = i;
			dfs_find_ordering(rgraph, i, explored, ordering, t);
		}
	}
	fill(explored.begin(), explored.end(), false);
	fill(ssccount.begin(), ssccount.end(), 0);
	t = -1;
	for(int i = n - 1; i >= 0; i--) {
		if (!explored[ordering[i]])
		{
			s = ordering[i];
			dfs_find_scc(graph, ordering[i], explored, s);
		}
	}
	sort(ssccount.begin(),ssccount.end(),[](int i, int j) -> bool{ return (i > j);});
	for(int i = 0; i < 5; i++) {
		cout<<ssccount[i];
		if (i < 4)
		{
			cout<<",";
		}
	}

	return 0;
}