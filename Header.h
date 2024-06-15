#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include <string.h>
using namespace std;
class node
{
	int data;
	node* next;
public:
	node()
	{
		data = -1;
		next = NULL;
	}
	void setdata(int v)
	{
		data = v;
	}
	int getdata()
	{
		return data;
	}
	void setnext(node* s)
	{
		next = s;
	}
	node* getnext()
	{
		return next;
	}
};
class Queue
{
private:

	node* front;
	node* rear;
public:
	Queue()
	{
		front = NULL;
		rear = NULL;
	}
	node* getfront()
	{
		return front;
	}
	bool enQueue(int a)
	{
		node* newNode = new node();
		newNode->setdata(a);
		if (front == NULL)
		{
			front = newNode;
			rear = newNode;
			return true;
		}
		else
		{
			rear->setnext(newNode);
			rear = newNode;
			return true;
		}
		return false;
	}
	bool deQueue()
	{
		if (front == NULL)
		{
			return false;
		}
		else
		{
			node* temp;
			temp = front;
			front = front->getnext();
			delete(temp);
			return true;
		}
		return false;
	}
	int showFront()
	{
		return front->getdata();
	}
	bool isEmpty()
	{
		if (front == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
class Node
{
private:
	int name;
	Node* next;
	int weight;
public:
	Node()
	{
		name = 0;
		next = NULL;
		weight = 0;
	}
	Node(int name)
	{
		this->name = name;
		next = NULL;
		weight = 0;
	}
	void setname(int name)
	{
		this->name = name;
	}
	int getname()
	{
		return name;
	}
	void setnext(Node* n)
	{
		next = n;
	}
	Node* getnext()
	{
		return next;
	}
	int setweight(int w)
	{
		weight = w;
	}
	int getweight()
	{
		return weight;
	}
};
class Stack
{
	node* top;
public:
	Stack()
	{
		top = NULL;
	}
	bool isEmpty()
	{
		if (top == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void display()
	{
		node* temp = top;
		while (temp->getnext() != NULL)
		{
			cout << temp->getdata() << " ";
			temp = temp->getnext();
		}
	}
	bool push(int d)
	{
		node* newn = new node();
		newn->setdata(d);
		newn->setnext(top);
		top = newn;
		return true;

	}
	int peek()
	{
		if (top != NULL)
		{
			return top->getdata();
		}
		else
		{
			return -11;
		}

	}
	void pop()
	{

		if (top != NULL)
		{
			node* temp;
			temp = top;
			top = top->getnext();
			delete temp;
		}
	}


};
class AdjList
{
private:
	Node** array;
	int number = 0;
public:
	AdjList(int nodes)
	{
		number = nodes;
		array = new Node * [number];
		for (int i = 0; i < number; i++)
		{
			array[i] = NULL;
		}
	}
	void addEdge(int s, int d)
	{
		Node* n = new Node(d);
		Node** temp = new Node * [number]();
		for (int i = 0; i < number; i++)
		{
			temp[i] = array[i];
		}
		while (temp[s] != NULL && temp[s]->getname() != d)
		{
			temp[s] = temp[s]->getnext();
		}
		if (temp[s] == NULL)
		{
			n->setnext(array[s]);
			array[s] = n;
		}
	}
	bool deleteedge(int s, int d)
	{
		Node** temp = new Node * [number];
		Node** temp1 = new Node * [number];
		for (int i = 0; i < number; i++)
		{
			temp[i] = array[i];
			temp1[i] = array[i];
		}
		if (temp[s] != NULL)
		{
			temp1[s] = array[s]->getnext();
			while (temp1[s] != NULL && temp1[s]->getname() != d && temp[s]->getname() != d)
			{
				temp[s] = temp[s]->getnext();
				temp1[s] = temp1[s]->getnext();
			}
			if (temp[s]->getname() == d && temp1[s] == NULL)
			{
				array[s] = NULL;
				delete(temp[s]);
				return true;
			}
			else if (temp[s]->getname() == d && temp1[s] != NULL)
			{
				array[s] = temp1[s];
				delete(temp[s]);
				return true;
			}
			else if (temp1[s] != NULL)
			{
				if (temp1[s]->getname() == d)
				{
					temp[s]->setnext(temp1[s]->getnext());
					delete(temp1[s]);
					return true;
				}
			}
			else
			{
				return false;
			}
		}

	}
	void inDegree()
	{
		int* indegree = new int[number];
		int counter = 0;
		for (int i = 0; i < number; i++)
		{
			indegree[i] = 0;//initializing
		}
		for (int i = 0; i < number; i++)
		{

			for (int j = 0; j < number; j++)
			{
				Node* temp = array[j];
				while (temp != NULL)
				{
					if (temp->getname() == i)
						indegree[i] = indegree[i] + 1;
					temp = temp->getnext();
				}
			}
		}
		cout << "Vertex\t\tIn\t\tOut" << endl;
		for (int k = 0; k < number; k++)
		{
			cout << k << "\t\t" << indegree[k] << endl;
		}
	}
	void outDegree()
	{
		int* outDegree = new int[number];
		int counter = 0;
		for (int i = 0; i < number; i++)
		{
			outDegree[i] = 0;//initializing
		}
		for (int i = 0; i < number; i++)
		{
			Node* temp = array[i];
			while (temp != NULL)
			{
				counter = counter + 1;
				temp = temp->getnext();
			}
			outDegree[i] = counter;
			counter = 0;
		}
		cout << "Vertex\tOut Degree" << endl;
		for (int k = 0; k < number; k++)
		{
			cout << k << "\t\t" << outDegree[k] << endl;
		}
	}
	void inOutDegreeDistributionTable()
	{
		int* indegree = new int[number];
		int* outDegree = new int[number];
		int counter = 0;
		for (int i = 0; i < number; i++)
		{
			indegree[i] = 0;//initializing
			outDegree[i] = 0;//initializing
		}
		for (int i = 0; i < number; i++)
		{

			for (int j = 0; j < number; j++)
			{
				Node* temp = array[j];
				while (temp != NULL)
				{									//in Degree distribution
					if (temp->getname() == i)
						indegree[i] = indegree[i] + 1;
					temp = temp->getnext();
				}
				delete temp;
			}
		}
		for (int i = 0; i < number; i++)
		{
			Node* temp = array[i];
			while (temp != NULL)
			{
				counter = counter + 1;				//out Degree Distribution
				temp = temp->getnext();
			}
			delete temp;
			outDegree[i] = counter;
			counter = 0;
		}
		cout << "Vertex\tIn Degree\tOut Degree" << endl;
		for (int k = 0; k < number; k++)
		{
			cout << k << "\t\t" << indegree[k] << "\t\t" << outDegree[k] << endl;
		}
	}
	bool deletevertex(int s)
	{
		int c = 0;
		array[s] = NULL;
		for (int i = 0; i < number; i++)
		{
			bool k = deleteedge(i, s);
			if (k == true)
			{
				c++;
			}
		}
		if (c != 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void display()
	{
		Node** temp = new Node * [number];
		for (int i = 0; i < number; i++)
		{
			temp[i] = array[i];
		}
		for (int i = 0; i < number; i++)
		{
			cout << ">" << i;
			while (temp[i] != NULL)
			{
				cout << "->" << temp[i]->getname();
				temp[i] = temp[i]->getnext();
			}
			cout << endl;
		}
	}
	int sourcenodes()
	{
		int count = 0;
		int m = 0;
		Node** temp = new Node * [number];
		for (int i = 0; i < number; i++)
		{
			temp[i] = array[i];
		}
		for (int i = 0; i < number; i++)
		{

			for (int j = 0; j < number; j++)
			{

				while (temp[j] != NULL && temp[j]->getname() != i)
				{
					temp[j] = temp[j]->getnext();
				}
				if (temp[j] == NULL)
				{
					m = m + 1;
				}

			}
			if (m == number)
			{
				count++;

			}
			for (int k = 0; k < number; k++)
			{
				temp[k] = array[k];
			}
			m = 0;
		}
		return count;
	}
	int sinknodes()
	{
		int count = 0;
		int m = 0;
		Node** temp = new Node * [number];
		for (int i = 0; i < number; i++)
		{
			temp[i] = array[i];
		}
		for (int i = 0; i < number; i++)
		{
			if (temp[i] == NULL)
			{
				count++;
			}
		}
		return count;
	}
	int isolatednodes()
	{
		int count = 0;
		int sink = 0;
		int source = 0;
		Node** temp = new Node * [number];
		for (int i = 0; i < number; i++)
		{
			temp[i] = array[i];
		}
		for (int i = 0; i < number; i++)
		{

			if (temp[i] == NULL)
			{
				sink++;
			}

			for (int j = 0; j < number; j++)
			{

				while (temp[j] != NULL && temp[j]->getname() != i)
				{
					temp[j] = temp[j]->getnext();
				}
				if (temp[j] == NULL)
				{
					source = source + 1;
				}

			}
			if (source == number && sink == 1)
			{
				count++;

			}
			for (int k = 0; k < number; k++)
			{
				temp[k] = array[k];
			}
			source = 0;
			sink = 0;
		}
		return count;
	}
	string DFS(int p, bool visitedVertices[])
	{
		makeUndirected();
		Node** temp = new Node * [number];
		for (int k = 0; k < number; k++)
		{
			temp[k] = array[k];
		}
		Stack s;
		s.push(p);
		visitedVertices[p] = 1;
		string output = "";
		while (s.isEmpty() != true)
		{
			int c = 0;
			int a = s.peek();
			output = output + to_string(a);
			s.pop();
			while (temp[a] != NULL)
			{
				if (visitedVertices[temp[a]->getname()] != 1)
				{
					s.push(temp[a]->getname());
					visitedVertices[temp[a]->getname()] = 1;

				}
				temp[a] = temp[a]->getnext();
			}

		}
		delete[] temp;
		return output;
	}
	int BFS(int m)
	{
		Queue q;
		Node** temp = new Node * [number];
		for (int k = 0; k < number; k++)
		{
			temp[k] = array[k];
		}
		q.enQueue(m);

		int* visited = new int[number];
		for (int i = 0; i < number; i++)
		{
			visited[i] = 0;
		}
		visited[m] = 1;
		string s = "";
		while (q.isEmpty() != true)
		{
			int p = q.showFront();
			s = s + to_string(p);
			q.deQueue();
			while (temp[p] != NULL && visited[temp[p]->getname()] != 1)
			{
				if (visited[temp[p]->getname()] != 1)
				{
					q.enQueue(temp[p]->getname());
					visited[temp[p]->getname()] = 1;
					temp[p] = temp[p]->getnext();
				}
			}
		}
		//	for (int i = 0;i < number;i++)
			//{
				//while (temp[i] != NULL)
				//{
				//	q.enQueue(temp[i]->getname());
				//	temp[i] = temp[i]->getnext();
				//}

			//}
			//string s = "";
			//while (q.isEmpty() != true)
			//{
			//	int c = 0;
			//	string p=to_string(q.showFront());
			//	for (int i = 0;i < s.length();i++)
			//	{
			//		string o(1, s[i]);
			//		if (p == o)
			//		{
				//		c++;
			//
			//		}
			//	}
			//	if (c == 0)
			//	{
			//		s = s + to_string(q.showFront());
			//		
			//	}
			//	q.deQueue();
			//}
		return s.length();
	}
	int bridgeedges()
	{
		int count = 0;
		int c = BFS(count);
		Node** temp = new Node * [number];
		for (int k = 0; k < number; k++)
		{
			temp[k] = array[k];
		}
		for (int i = 0; i < number; i++)
		{
			for (int j = 0; j < number; j++)
			{
				bool k = deleteedge(i, j);
				if (k == true)
				{

					int a = BFS(0);
					if (a < c)
					{
						count++;
					}
					addEdge(i, j);

				}
			}
		}
		return count;
	}
	int articulationvertex()
	{
		Node** temp = new Node * [number];
		for (int i = 0; i < number; i++)
		{
			temp[i] = array[i];
		}
		int p = 0;
		while (temp[p] == NULL)
		{
			p++;
		}
		int count = 0;
		Queue q;
		int c = BFS(p);
		Node* temp1;
		for (int i = 0; i < number; i++)
		{
			temp1 = array[i];
			array[i] = NULL;
			for (int j = 0; j < number; j++)
			{
				bool k = deleteedge(j, i);
				if (k == true)
				{
					q.enQueue(j);
				}
			}
			p = 0;
			while (temp[p] == NULL)
			{
				p++;
			}
			int a = BFS(p);
			if (a + 1 < c)
			{
				count++;
			}


			while (q.isEmpty() != true)
			{
				addEdge(q.showFront(), i);
				q.deQueue();
			}
			array[i] = temp1;

		}
		return count;
	}
	void makeUndirected()
	{
		for (int i = 0; i < number; i++)
		{
			Node* temp = array[i];
			while (true)
			{
				addEdge(temp->getname(), i);
				if (temp->getnext() != NULL)
					temp = temp->getnext();
				else break;
			}
		}
	}
	void DFS(int p)
	{
		Node** temp = new Node * [number];
		for (int k = 0; k < number; k++)
		{
			temp[k] = array[k];
		}
		Stack s;

		s.push(p);
		int* visited = new int[number];
		for (int i = 0; i < number; i++)
		{
			visited[i] = 0;
		}
		visited[p] = 1;
		string v = "";
		while (s.isEmpty() != true)
		{
			int c = 0;
			int a = s.peek();
			v = v + to_string(a);
			s.pop();
			while (temp[a] != NULL)
			{
				if (visited[temp[a]->getname()] != 1)
				{
					s.push(temp[a]->getname());
					visited[temp[a]->getname()] = 1;

				}
				temp[a] = temp[a]->getnext();
			}

		}
		cout << v;
	}
	string* connectedComponents()
	{
		string* strs = new string[number];// array of strings
		bool* visitedVertices = new bool[number];
		for (int i = 0; i < number; i++)
		{
			visitedVertices[i] = 0;
		}
		for (int i = 0; i < number; i++)
		{
			strs[i] = '0';
		}
		for (int i = 0; i < number; i++)
		{
			if(visitedVertices[i]==false)
				strs[i] = DFS(i, visitedVertices);
		}
		delete[] visitedVertices;
		return strs;
	}
	void weaklyConnectedComponent()
	{
		string* strs;
		strs=connectedComponents();
		int max = 0;
		for (int i = 0; i < number; i++)
		{
				if (max < strs[i].length())
					max = strs[i].length();
		}
		cout << "Size of the largest weakly connected component (WCC) is " << max<<" vertices which is given below: \n"<<endl;
		for (int i = 0; i < number; i++)
		{
			if (strs[i].length() == max)
			{
				string str = strs[i];
				for (int j = 0; j < str.length(); j++)
				{
					cout << "->" << str[j];
				}
				cout << endl;
			}
		}
		delete[] strs;
	}
};