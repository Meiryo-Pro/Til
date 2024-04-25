#include <iostream>
#include <vector>
#include<map>
#include<algorithm>
#include <string>
#include<unordered_map>

using namespace std;

struct Step1Node
{
	vector<int> children;

public:
	Step1Node() {}
	Step1Node(int child)
	{
		children.emplace_back(child);
	}
};

struct Step2Node
{
	int own = 0;
	int parent = 0;
	vector<Step2Node> children;

	Step2Node() {}

	Step2Node(int own) :own(own) {}

public:
	void AddChild(Step2Node child)
	{
		this->children.emplace_back(child);
	}

	void SetParent(int parent)
	{
		this->parent = parent;
	}
};


struct Step3Node
{
	int own = 0;
	int parent = 0;
	vector<Step3Node> children;

	Step3Node() {}

	Step3Node(int own) :own(own) {}

public:
	void AddChild(Step3Node child)
	{
		this->children.emplace_back(child);
	}

	void SetParent(int parent)
	{
		this->parent = parent;
	}
};

struct Step4Node
{
	int own = 0;
	int parent = 0;
	vector<int> connectedNodes;

	Step4Node() {}

	Step4Node(int own) :own(own) {}


	void AddConnectNode(int nodeIndex)
	{
		this->connectedNodes.emplace_back(nodeIndex);
	}

	void SetParent(int parent)
	{
		this->parent = parent;
	}
};

void Step1();
void Step2();
void Step3();
void Step4();
void MakeNode(unordered_map<int, Step4Node>&, int,int);
void SetParent(unordered_map<int, Step4Node>&, int);

int main()
{
	Step4();
}

void Step1()
{
	int N, K, R;
	cin >> N >> K >> R;

	unordered_map<int, Step1Node> tree;

	for (auto i = 0; i < N - 1; ++i)
	{
		int a, b;
		cin >> a >> b;

		if (tree.find(a) == tree.end())
		{
			Step1Node node(b);
			tree[a] = node;
		}
		else
		{
			tree[a].children.emplace_back(b);
		}

		if (tree.find(b) == tree.end())
		{
			Step1Node node;
			tree[b] = node;
		}
	}


	vector<string> ansList;
	for (auto i = 0; i < K; ++i)
	{
		int V;
		cin >> V;

		if (tree[V].children.size() == 0)
		{
			ansList.emplace_back("0");
			continue;
		}

		sort(tree[V].children.begin(), tree[V].children.end());

		string ans;
		int n = tree[V].children.size();
		for (auto i = 0; i < n; ++i)
		{
			if (i == n - 1)
			{
				ans += to_string(tree[V].children[i]);
			}
			else
			{
				ans += to_string(tree[V].children[i]) + " ";
			}
		}
		ansList.emplace_back(ans);
	}

	for (auto& ans : ansList)
	{
		if (ans == "0")
		{
			cout << endl;
		}
		else
		{
			cout << ans << endl;
		}
	}
}

void Step2()
{
	int N, K, R;
	cin >> N >> K >> R;

	unordered_map<int, Step2Node> tree;

	for (auto i = 0; i < N - 1; ++i)
	{
		int a, b;
		cin >> a >> b;

		Step2Node chileNode(b);
		chileNode.SetParent(a);

		if (tree.find(a) == tree.end())
		{
			Step2Node parentNode(a);
			tree[a] = parentNode;
		}
		else
		{
			tree[a].AddChild(chileNode);
		}

		if (tree.find(b) == tree.end())
		{
			tree[b] = chileNode;
		}

		if (tree[b].parent != a)
		{
			tree[b].parent = a;
		}
	}

	vector<int> ansList;
	for (auto i = 0; i < K; ++i)
	{
		int V;
		cin >> V;

		if (tree[V].parent == 0)
		{
			ansList.emplace_back(0);
		}
		else
		{
			ansList.emplace_back(tree[V].parent);
		}

	}

	for (auto& ans : ansList)
	{
		if (ans == 0)
		{
			cout << endl;
		}
		else
		{
			cout << ans << endl;
		}
	}
}

void Step3()
{
	int N, R;
	cin >> N >> R;

	unordered_map<int, Step3Node> tree;

	for (auto i = 0; i < N - 1; ++i)
	{
		int a, b;
		cin >> a >> b;

		Step3Node chileNode(b);
		chileNode.SetParent(a);

		if (tree.find(a) == tree.end())
		{
			Step3Node parentNode(a);
			tree[a] = parentNode;
		}
		else
		{
			tree[a].AddChild(chileNode);
		}

		if (tree.find(b) == tree.end())
		{
			tree[b] = chileNode;
		}

		if (tree[b].parent != a)
		{
			tree[b].parent = a;
		}
	}

	bool ans = true;

	for (auto& node : tree)
	{
		if (node.first == R)
		{
			continue;
		}

		if (node.second.own > node.second.parent)
		{
			ans = false;
			break;
		}

		if (!ans)
		{
			break;
		}
	}

	if (ans)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}

}

void Step4()
{
	int N, R;
	cin >> N >> R;

	unordered_map<int, Step4Node> tree;
	vector<pair<int, int>>  inputs;

	for (auto i = 0; i < N - 1; ++i)
	{
		int a, b;
		cin >> a >> b;
		inputs.emplace_back(make_pair(a, b));

		/*Step4Node aNode(a);
		tree.insert(make_pair(a,aNode));
	    tree.at(a).AddConnectNode(b);

		Step4Node bNode(b);
		tree.insert(make_pair(b, bNode));
		tree.at(b).AddConnectNode(a);*/

		MakeNode(tree,a,b);
		MakeNode(tree,b,a);
	}
		
	SetParent(tree, R);

	for (auto& input : inputs)
	{
		if (tree.at(input.first).parent == tree.at(input.second).own)
		{
			cout << "B" << endl;
		}
		else if (tree.at(input.first).own == tree.at(input.second).parent)
		{
			cout << "A" << endl;
		}
	}
}

void MakeNode(unordered_map<int, Step4Node>& tree, int first,int second)
{
	Step4Node node(first);
	tree.insert(make_pair(first, node));
	tree.at(first).AddConnectNode(second);
}

void SetParent(unordered_map<int, Step4Node>& tree, int current)
{
	if (tree.at(current).connectedNodes.size() == 0)
	{
		return;
	}
	
	for (int i = 0; i< tree.at(current).connectedNodes.size(); ++i)
	{
		if (tree.at(current).connectedNodes.at(i) == tree.at(current).parent)
		{
			continue;
		}

		tree.at(tree.at(current).connectedNodes.at(i)).parent = tree.at(current).own;
		SetParent(tree, tree.at(current).connectedNodes.at(i));
	}

}