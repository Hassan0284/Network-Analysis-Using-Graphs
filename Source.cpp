#include "../data_Project/Header.h"
#include<iostream>
#include<sstream>
using namespace std;
int main()
{
	int choice = 0;
	cout << "************************************WELCOME***************************************" << endl;
	cout << "----------------------------------------------------------------------------------" << endl;
	 cout<< "|Enter 1 to read from small directed dataset (Arxiv General Relativity category) |" << endl
		  << "----------------------------------------------------------------------------------"<<endl
		<< "|Enter 2 to read from large directed dataset(Arxiv Astro Physics category )      |"<<endl
		 << "----------------------------------------------------------------------------------"<<endl
		<<"Input: ";
	cin>>choice;
	switch (choice)
	{
	case 1:
	{
		string store, temp;
	string str[5];
	ifstream read;
	read.open("CA-GrQc.txt");
	int counter = 0, nodes = 0, edges = 0;
	{
		while (!read.eof())
		{
			getline(read, store);
			if (counter == 1)
			{
				getline(read, store);
				stringstream str(store);
				for (int i = 0; i < 5; i++)
				{
					getline(str, temp, ' ');
					stringstream Final(temp);
					Final >> store;
					if (i == 2)
						nodes = stoi(store);
					if (i == 4)
						edges = stoi(store);
				}
			}
			counter++;
		}
	}
	read.close();
	read.open("CA-GrQc.txt");
	counter = 0;
	int temp1 = 0, temp2 = 0;
	AdjList g(nodes);
	while (!read.eof())
	{
		if (counter == 0)
		{
			for (int i = 0; i < 4; i++)
			{
				getline(read, store);
			}
		}
		getline(read, store);
		for (int i = 0; i < store.length(); i++)
		{
			if (store[i] >= '0' && store[i] <= '9')
			{
				bool flag = false;
				temp1 = 0;
				while (true)
				{
					if (store[i] == '\t')
					{
						flag = true;
						break;
					}
					else if (store[i] == ' ')
					{
						break;
					}
					else
					{
						temp1 = (temp1 * 10) + int(store[i] - '0');
						i++;
					}
				}
				while (true)
				{
					if (store[i] >= '0' && store[i] <= '9')
						break;
					else i++;
				}
				temp2 = 0;
				while (i != store.length())
				{
					temp2 = (temp2 * 10) + int(store[i] - '0');
					i++;
				}
			}
		}
		counter++;
		g.addEdge(temp1, temp2);
	}
		system("CLS");
	int innerChoice = 0;
	cout << endl<<"**********************************WELCOME AGAIN*****************************************" << endl;
	cout << "----------------------------------------------------------------------------------------" << endl;
	cout << "|                                    TASK_01                                            |" << endl;
	cout << "----------------------------------------------------------------------------------------" << endl;
	cout << "|Enter '1' to display the number of nodes and edges in the data set.                    |" << endl
		<< "----------------------------------------------------------------------------------------" << endl
		<< "|Enter '2' to display the number of source nodes.                                       |" << endl
		<< "----------------------------------------------------------------------------------------" << endl
		<< "|Enter '3' to display the number of sink nodes.                                         |" << endl
		<< "----------------------------------------------------------------------------------------" << endl
		<< "|Enter '4' to display the number of isolated nodes.                                     |" << endl
		<< "----------------------------------------------------------------------------------------" << endl
		<< "|Enter '5' to display the number of bridge edges.                                       |" << endl
		<< "----------------------------------------------------------------------------------------" << endl
		<< "|Enter '6' to display the number of articulation nodes.                                 |" << endl
		<< "----------------------------------------------------------------------------------------" << endl
		<< "----------------------------------------------------------------------------------------" << endl
	    << "|                                    TASK_02                                            |" << endl
		<< "----------------------------------------------------------------------------------------" << endl
		<< "|Enter '7' to display the in and out degree distribution of the geaph in table formate. |" << endl 
		<< "----------------------------------------------------------------------------------------" << endl
		<< "|                                    TASK_03                                            |" << endl
		<< "----------------------------------------------------------------------------------------" << endl
		<< "----------------------------------------------------------------------------------------" << endl
		<< "|Enter '8' to display the size of largest WCC and all the WCCs in graph.               |" << endl
		<< "----------------------------------------------------------------------------------------" << endl
		<< "Input: ";
	cin >> innerChoice;
	switch (innerChoice)
	{
	case 1:
	{
		system("CLS");
		cout << "Number of Nodes: "<< nodes << endl;
		cout << "Number of Edges: " << edges << endl;
	}
	break;
	case 2:
	{
		system("CLS");
		g.sourcenodes();
	}
	break;
	case 3:
	{
		system("CLS");
		g.sinknodes();
	}
	break;
	case 4:
	{
		system("CLS");
		g.isolatednodes();
	}
	break;
	case 5:
	{
		system("CLS");
		g.bridgeedges();
	}
	break;
	case 6:
	{
		system("CLS");
		g.articulationvertex();
	}
	break;
	case 7:
	{
		system("CLS");
		g.inOutDegreeDistributionTable();
	}
	break;
	case 8:
	{
		system("CLS");
		g.weaklyConnectedComponent();
	}
	break;
	default:
	{
		system("CLS");
		cout << "Invalid Input :( Terminating.";
		break;
	}
	}
	}
	break;
	case 2:
	{
	string store, temp;
	string str[5];
	ifstream read;
	read.open("CA-AstroPh.txt");
	int counter = 0, nodes = 0, edges = 0;
	{
		while (!read.eof())
		{
			getline(read, store);
			if (counter == 1)
			{
				getline(read, store);
				stringstream str(store);
				for (int i = 0; i < 5; i++)
				{
					getline(str, temp, ' ');
					stringstream Final(temp);
					Final >> store;
					if (i == 2)
						nodes = stoi(store);
					if (i == 4)
						edges = stoi(store);
				}
			}
			counter++;
		}
	}
	read.close();
	read.open("CA-AstroPh.txt");
	counter = 0;
	int temp1 = 0, temp2 = 0;
	AdjList g(nodes);
	while (!read.eof())
	{
		if (counter == 0)
		{
			for (int i = 0; i < 4; i++)
			{
				getline(read, store);
			}
		}
		getline(read, store);
		for (int i = 0; i < store.length(); i++)
		{
			if (store[i] >= '0' && store[i] <= '9')
			{
				bool flag = false;
				temp1 = 0;
				while (true)
				{
					if (store[i] == '\t')
					{
						flag = true;
						break;
					}
					else if (store[i] == ' ')
					{
						break;
					}
					else
					{
						temp1 = (temp1 * 10) + int(store[i] - '0');
						i++;
					}
				}
				while (true)
				{
					if (store[i] >= '0' && store[i] <= '9')
						break;
					else i++;
				}
				temp2 = 0;
				while (i != store.length())
				{
					temp2 = (temp2 * 10) + int(store[i] - '0');
					i++;
				}
			}
		}
		counter++;
		g.addEdge(temp1, temp2);
	}
	int innerChoice = 0;
	cout << endl << "**********************************WELCOME AGAIN*****************************************" << endl;
	cout << "----------------------------------------------------------------------------------------" << endl;
	cout << "|                                    TASK_01                                            |" << endl;
	cout << "----------------------------------------------------------------------------------------" << endl;
	cout << "|Enter '1' to display the number of nodes and edges in the data set.                    |" << endl
		<< "----------------------------------------------------------------------------------------" << endl
		<< "|Enter '2' to display the number of source nodes.                                       |" << endl
		<< "----------------------------------------------------------------------------------------" << endl
		<< "|Enter '3' to display the number of sink nodes.                                         |" << endl
		<< "----------------------------------------------------------------------------------------" << endl
		<< "|Enter '4' to display the number of isolated nodes.                                     |" << endl
		<< "----------------------------------------------------------------------------------------" << endl
		<< "|Enter '5' to display the number of bridge edges.                                       |" << endl
		<< "----------------------------------------------------------------------------------------" << endl
		<< "|Enter '6' to display the number of articulation nodes.                                 |" << endl
		<< "----------------------------------------------------------------------------------------" << endl
		<< "----------------------------------------------------------------------------------------" << endl
		<< "|                                    TASK_02                                            |" << endl
		<< "----------------------------------------------------------------------------------------" << endl
		<< "|Enter '7' to display the in and out degree distribution of the geaph in table formate. |" << endl
		<< "----------------------------------------------------------------------------------------" << endl
		<< "|                                    TASK_03                                            |" << endl
		<< "----------------------------------------------------------------------------------------" << endl
		<< "|Enter '8' to display the size of largest WCC and all the WCCs in graph.               |" << endl
		<< "----------------------------------------------------------------------------------------" << endl
		<< "Input: ";
	cin >> innerChoice;
	switch (innerChoice)
	{
	case 1:
	{
		system("CLS");
		cout << "Number of Nodes: " << nodes << endl;
		cout << "Number of Edges: " << edges << endl;
	}
	break;
	case 2:
	{
		system("CLS");
		g.sourcenodes();
	}
	break;
	case 3:
	{
		system("CLS");
		g.sinknodes();
	}
	break;
	case 4:
	{
		system("CLS");
		g.isolatednodes();
	}
	break;
	case 5:
	{
		system("CLS");
		g.bridgeedges();
	}
	break;
	case 6:
	{
		system("CLS");
		g.articulationvertex();
	}
	break;
	case 7:
	{
		system("CLS");
		g.inOutDegreeDistributionTable();
	}
	break;
	case 8:
	{
		system("CLS");
		g.weaklyConnectedComponent();
	}
	break;
	default:
	{
		system("CLS");
		cout << "Invalid Input :( Terminating.";
		break;
	}
	}
	}
	break;
	default:
		cout << "Invalid Input :( Terminating.";
		break;
	}
	return 0;
}
