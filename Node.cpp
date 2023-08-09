#include "Node.h"

//Default constructor
Node::Node()
{
  m_next = nullptr;
}

// Default destructor
Node::~Node()
{
  //  delete m_next;
  // m_next = nullptr;
}

// Overloaded Constructor
Node::Node(bool value)
{
  m_value = value;
}

// Replaces the value of m_value with its opposite
void Node::ReplaceValue()
{
  if (m_value == true)
  {
    m_value = false;
  }
  else
  {
    m_value = true;
  }
}

// Sets m_next
void Node::SetNext(Node* next)
{
  m_next = next;
}

// Returns the address of the next node
Node* Node::GetNext()
{
  return m_next;
}

// Returns m_value
bool Node::GetValue()
{
  return m_value;
}

