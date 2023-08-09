#include "DecayList.h"

// Default constructor
DecayList::DecayList()
{
  m_head = nullptr;
  m_size = 0;
}

// Destructor
DecayList::~DecayList()
{
  cout << "DecayList is deleted" << endl; 
}

// Returns size of list
int DecayList::GetSize()
{
  return m_size;
}

// Chooses a node to replace value (with opposite value)
void DecayList::InvertValue(int index)
{
  if (m_head == nullptr)
  {
    cout << "The linked list is empty" << endl;
  }
  else
  {
    Node *temp = m_head; 

    for (int i = 0; i < index; i++)
    {
      temp = temp->GetNext(); //Moves to next node
    }
    
    temp->ReplaceValue();
  }
}

// Prints the list of nodes and their values
bool DecayList::PrintDecayList()
{
  if (m_size == 0)
  { //Checks to see if the linked list is empty 
    cout << "The linked list is empty" << endl; //Output if it is empty
    return false;
  }
  else
  {
    //cout << m_head->GetValue() << endl;
    Node *temp = m_head;
    for (int i = 0; i < m_size; i++)
    {
      cout << "|" << temp->GetValue() << "|->";
      temp = temp->GetNext(); //Moves to next node
    }
    
    cout << "END" << endl;
    return true;
  }
}

// Loops list to see if any sequences of 3 or more nodes with a value of 1
int DecayList::TraverseList(bool check)
{
  int position = 0;
  int count = 0;
  int totalChangedNodes = 0;
  int listSize = m_size;

  if (m_size >= 3)
  {
    Node *temp = m_head;
    while (temp != nullptr)
    {
      if (check == temp->GetValue())
      {
	count++;
	position++;
	if (count == 3)
	{
	  position = position - 3;
	  count = 0;
	  m_size -= RemoveNodes(position, 3);
	  temp = m_head;
	  position = 0;
	  totalChangedNodes++;
	}
	else
	{
	  temp = temp->GetNext();
	}
      }
      else
      {
	temp = temp->GetNext();
	count = 0;
	position++;
      }
    }
  }
  return (totalChangedNodes * 3);
}

// Called when 3 or more 1's in a row. Nodes are removed left to right.
int DecayList::RemoveNodes(int index, int numNodes)
{  
  int count = 0;
  if (index == 0)
  {
    while (count < numNodes){
      
      Node *temp = m_head;
      m_head = m_head->GetNext();
      delete temp;
      count++;
    }

    return 3;
  }
  else
  {
    Node *current = new Node;
    Node *previous = new Node;
    current = m_head;
    
    for (int i = 1; i <= index; i++)
    {
      previous = current;
      current = current->GetNext();
    }

    for (int j = 0; j < numNodes; j++)
    {
      current = current->GetNext();
    }
    
    previous->SetNext(current);
    return numNodes;
  }
}

// Checks if the list is empty
bool DecayList::CheckEmpty()
{
  if (m_head == nullptr)
  {
    cout << "Game over" << endl;
    return true;
  }
  else
    return false;
}

// Inserts new Node into end of DecayList
void DecayList::InsertEnd(Node* end)
{

  if(m_head == nullptr)
  {
    m_head = end;
    m_size = 1;
  }
  else
  {
    Node *temp = m_head;
    while(temp->GetNext() != nullptr)
    {
      temp = temp->GetNext();
    }
    temp->SetNext(end);
    m_size++;
  }
}
