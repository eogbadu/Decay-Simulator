#include "Decay.h"

// Default constructor
Decay::Decay()
{
  m_file = "";
}

// Destructor
Decay::~Decay()
{
  //  delete m_list;
}

//
void Decay::EmptyLists()
{

}

//
void Decay::LoadFile()
{
  string fileName;
  char value;
  bool boolVal;
  
  cout << "What is the name of the file?" << endl;
  cin >> fileName;
  ifstream inStream;
  inStream.open(fileName);
  if(inStream.fail())
  {
    cout << "File failed to load.\n";
  }
  else
  {
    while (!inStream.eof())
    {
   
      DecayList *tempList = new DecayList();
      inStream >> value;
      
      while (value != ';')
      {
	if (value == '1')
	  boolVal = true;
	else if (value == '0')
	  boolVal = false;

	Node *tempNode = new Node(boolVal);
       	tempList->InsertEnd(tempNode);
      
	
	inStream >> value;
	
      }
      cout << endl;
      if (tempList->GetSize() > 0)
	m_list.push_back(tempList);
    }
  }
  inStream.close();
  Start();
}

//
void Decay::ChooseList()
{
  int selection;
  int x = 1;
  cout << "Which Decay scenario do you want to experience?" << endl;
  for (unsigned int i = 0; i < m_list.size(); i++)
  {
    x++;
    cout << i + 1 << ". List " << i + 1 << "(" << m_list.at(i)->GetSize()
	 << " nodes)" <<endl; 
  }
  
  cout << x << ". Quit" << endl;
  cin >> selection;
  
  RunSimulation(selection);
}

//
void Decay::CreateRandomList()
{
  srand(time(NULL));
  int size, number;
  bool boolVal;
  cout << "How large a list would you like?" << endl;
  cin >> size;
  size = size * 3;
  
  DecayList *tempList = new DecayList();
  for (int i = 0; i < size; i++)
  {
    number = rand() % 2;
    if (number == 1)
      boolVal = true;
    else if (number == 0)
      boolVal = false;
    
    Node *tempNode = new Node(boolVal);
    tempList->InsertEnd(tempNode);
  }
   if (tempList->GetSize() > 0)
        m_list.push_back(tempList);
  Start();
}

//
void Decay::RunSimulation(int index)
{
  int selection, noChangedNodes;
  bool flag = false;
  index--;
  cout << "The sequence has been initialized." << endl;
  m_list.at(index)->PrintDecayList();
  cout << "Which node to change?" << endl;
  for (int i = 1; i <= m_list.at(index)->GetSize(); i++)
  {
    cout << i << " ";
  }
  cout << endl;
  cin >> selection;
  m_list.at(index)->InvertValue(selection - 1);
  
  noChangedNodes = m_list.at(index)->TraverseList(true);
  cout << noChangedNodes << " nodes removed!" << endl;

  while (flag != true)
  {
    if (m_list.at(index)->GetSize() == 0)
    {
      cout << "All nodes from that list have been removed!" << endl;
      m_list.at(index)->PrintDecayList();
      flag = true;
    }
    else
    {
      m_list.at(index)->PrintDecayList();
      cout << "Which node to change?" << endl;
      
      for (int i = 1; i <= m_list.at(index)->GetSize(); i++)
      {
	cout << i << " ";
      }
      cout << endl;
      cin >> selection;
      m_list.at(index)->InvertValue(selection - 1);

      noChangedNodes = m_list.at(index)->TraverseList(true);
      cout << noChangedNodes << " nodes removed!" << endl;
    }
  }
  Start();
}

//
void Decay::Start()
{
  int choice;
  
  cout << "Welcome to Decay, where you code a frustrating system instead ";
  cout << "of doing your physics homework." << endl;
  cout << "1. Load File" << endl;
  cout << "2. Simulate Loaded File" << endl;
  cout << "3. Simulate Random List" << endl;
  cout << "4. Quit" << endl;

  cin >> choice;
  while ((choice < 1) ||(choice > 4))
  {
    cout << "Please enter a valid choice (1 - 4)" << endl;
    cout << "Welcome to Decay, where you code a frustrating system instead ";
    cout << "of doing your physics homework." << endl;
    cout << "1. Load File" << endl;
    cout << "2. Simulate Loaded File" << endl;
    cout << "3. Simulate Random List" << endl;
    cout << "4. Quit" << endl;

    cin >> choice;
  }

  switch(choice)
  {
  case 1:
    LoadFile();
    break;
  case 2:
    ChooseList();
    break;
  case 3:
    CreateRandomList();
    break;
  case 4:
    exit(1);
    break;
  default:
    exit(1);
  }
}
