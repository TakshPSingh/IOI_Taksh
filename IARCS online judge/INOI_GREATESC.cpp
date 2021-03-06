﻿// INOI_GREATESC.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
long long n, m, t1, t2, s, t;
bool visited[3505] = { 0 };
long long dist[3505];
vector <long long> adj[3505];
int main()
{
	cin >> n >> m;
	for (long long i = 1; i <= m; ++i)
	{
		cin >> t1 >> t2;
		adj[t1].push_back(t2);
		adj[t2].push_back(t1);
	}
	cin >> s >> t;
	queue <long long> q;
	q.push(s);
	visited[s] = true;
	dist[s] = 0;
	while (!q.empty())
	{
		long long v = q.front();
		q.pop();
		for (long long i = 0; i < adj[v].size(); ++i)
		{
			long long p = adj[v][i];
			//cout << "[[ vav";
			if (visited[p] == false)
			{
				visited[p] = true;
				q.push(p);
				dist[p] = dist[v] + 1;
				//cout << "-- " << dist[p];
			}
		}
	}
	cout << dist[t];
	return 0;
}
