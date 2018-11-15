//
#include"Net.h"
#include"Cell.h"
#include"Node.h"

namespace Netlist {
    using namespace std;
    class Cell;
    class Node;
   

Net :: Net ( Cell * owner, const std :: string & name, Term :: Type type)

    : owner_ (owner)
    , name_  (name)
    , id_    ()
    , type_ (type)
    , nodes_ ()
{ owner->add(this);
}
    
    Net :: ~ Net ()
{
    //??
}

  
Node * Net :: getNode ( size_t id ) const
{
    for ( vector<Node*>::const_iterator inod=nodes_.begin() ; inod != nodes_.end() ; ++inod ) {
        if ((*inod)->getId() == id)  return *inod;
    }
    return NULL;
}
size_t Net :: getFreeNodeId () const
{
    
  size_t freeNodeId=0;
  for (vector <Node*>:: const_iterator it=nodes_.begin(); it!=nodes_.end(); ++it )
    {
      if (*it == NULL)
        return freeNodeId;
      else
        freeNodeId++;
    }
  return nodes_.size();
  
}
  
void Net :: add ( Node * node )
{
  if ( node )
    {
      size_t id = node-> getId();
      if (id == Node:: noid )
        {
          id = getFreeNodeId ();
          node-> setId(id);
        }
      if (id < nodes_.size())
        {
          if (nodes_[id ]!= NULL)
            {
              cerr << "attention case pleine" << endl;
              nodes_[id]-> setId (Node::noid);
            }
          nodes_[id]=node;
        }
  
  else
    {
      for (size_t i = nodes_.size(); i<id; ++i)
        nodes_.push_back (NULL);
      
      nodes_.push_back (node);
    }
}
}
bool Net :: remove ( Node * node )
{
    for ( vector <Node*>::iterator inode= nodes_.begin (); inode!= nodes_.end(); ++inode)
    {
        if (*inode==node)
        {
            nodes_.erase (inode);
            return true;
        }
    }
    return false;
}


}
