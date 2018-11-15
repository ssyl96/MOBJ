//
#include "Term.h"
#include "Net.h"
#include "Cell.h"
#include "Instance.h"

namespace Netlist {
  
  using namespace std;

  Term :: Term ( Cell * owner, const string & name, Term :: Direction direction)
    : owner_     ( owner )
    , name_      ( name )
    , direction_ ( direction )
    , type_      ( External )
    , net_       ( NULL )
    , node_      ( this, Node::noid )
  { owner->add (this); }

  Term :: Term (Instance* owner, const Term* modelTerm )
    : owner_     ( owner )
    , name_      ( modelTerm->getName () )
    , direction_ ( modelTerm ->getDirection () )
    , type_      ( Internal )
    , net_       ( NULL )
    , node_      ( this, Node::noid )
  { owner->add (this); }

 Term :: ~Term ()
 { }

 bool Term ::  isInternal () const
 { return type_== Internal;  }

 bool Term :: isExternal () const
 { return type_== External;  }


 Cell * Term :: getOwnerCell () const
 { return ( type_ == External ) ? static_cast < Cell * >( owner_ ): static_cast < Instance * >( owner_)->Instance::getMasterCell() ; }

 Point Term :: getPosition () const
 { return node_.getPosition(); }
  
  
void Term  ::   setNet ( Net * net )
{
  if (net)
    {
      if (net->getCell ()!= getOwnerCell())
        cerr << "erreur Term et Net n'appartiennent pas a la meme cell"<< endl;
    }
  net_ = net;
  net-> add (& node_); 
}
void Term ::   setNet ( const std :: string & s )
{
  setNet (getOwnerCell() -> getNet(s));
  
}
  
void Term ::   setPosition ( const Point & pos )
{ node_.setPosition ( pos ); }
  
void Term ::  setPosition ( int x , int y )
{ node_.setPosition ( x , y ); }
  
void Term ::  setDirection ( Direction direction )
{ direction_ = direction; }

 void  Term::toXml ( ostream& stream )
{
  
  stream << indent   << "<term name =\" " <<name_ <<" \" "" direction =\"" << ""<< direction_<< "\/"">\n";

}
  
  
  
  
 


  
}
