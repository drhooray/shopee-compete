/*
// Sample code to perform I/O:

#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	cout << "Input number is " << num << endl;		// Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here

/* 
	input node num , then enter the edge for 2 node and 

*/ 
#include <iostream>
using namespace std;
/*
struct node{
	struct node* left, *right;
	int lweight, rweight;
	int key;
};

node* newNode(int key){
	node *tmp = new node;
	tmp->key = key;
	tmp->left = tmp->right = NULL;
	return tmp;
}

int findlevel(node *root, int target, int level){
	if (root = NULL)
		return -1;
	if (root->key == target)
		return level;
	int backLevel = findlevel(root->left, target, level+1);
	return (backLevel != -1)? backLevel : findlevel(root->right, target, level+1);
}

node *finddist_lv(node* root, int n1, int n2, int &d1, int &d2, int &dist, int lv){
	if (root == NULL)
		return NULL;

	if (root->key == n1){
		d1 = lv;
		return root;
	}

	node *left_common = finddist_lv(root->left, n1, n2, d1, d2, dist, lv+1);
	node *right_common = finddist_lv(root->right, n1, n2, d1, d2, dist, lv+1);

	if (left_common && right_common){
		dist = d1 + d2 -2*lv;
		return root;
	}
	return (left_common != NULL)?left_common : right_common;
}

int finddist (node* root, int n1, int n2){
	int d1 = -1, d2 = -1, dist;
	node *common = finddist_lv(root, n1, n2, d1, d2, dist, 1);

	if (d1 != -1)
	{
		dist = findlevel(common, n2, 0);
		return dist;
	}
	if (d2 != -1)
	{
		dist = findlevel(common, n1, 0);
		return dist;
	}

	return -1;
}


int main() {
	int num;
	cin >> num;
	int i ;
	for (i = 0 ; i < num-1; i++ ){
		int key1 = 0, key2 = 0; int weight = 0;
		cin>>key1>>key2 >>weight;
		if (key1 == NULL) {
		node* start = newNode(key1);
		start->left = newNode(key2);
		start->lweight = weight;
		} else {
			

		}
	
	}
	return 0;

}
*/
// second method

#define __STDC_LIMIT_MACROS
#include <stdint.h>
#include <climits>

#define INF INT_MAX

template <int M, int N>
void minCostPath(int u, int dest, bool visited[], int graph[M][N]){
	if (u == dest)
		return 0;
	visited[u] = 1;
	int ans = INF;
	string numans;
	//traverse through all
	
	for (int i=0; i< N; i++){
		if (graph[u][i] != INF && !visited[i]) {
			int curr = minCostPath(i, dest, visited, graph);
			if (curr < INF){
				numans += to_string(curr);
			}
		}
	}
	visited[u]=0;
	return numans;
}
//void minCostPath( int u, int dest, bool visited[], int graph[][N]){};

int main(){
	int length;
	int ans;
	string ans_s;
	cin >> length;
	int graph[length][length];
	
	for (int i =0 ; i< length; i++){
		for (int j=0; j< length; j++){
			graph[i][j] = INF;
		}
	}

	bool visited[length] = { 0};

	for (int i =0 ; i< length; i++){
		int x, y = 0; int weight = 0;
		cin >> x >> y >> weight;
		graph[x][y] = weight;
	}

	for (int i = 0 ; i < length; i ++){
		for (int j= i+1; j< length ; j++ ){
			ans_s = minCostPath(i, j, visited, graph);
			ans += stoi(ans_s);
		}
	}
	return ans;

}
