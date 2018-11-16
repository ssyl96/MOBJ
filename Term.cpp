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
 {  return ( type_ == External ) ? static_cast < Cell * >( owner_ ): static_cast < Instance * >( owner_)->Instance::getCell() ; }

 Point Term :: getPosition () const
 { return node_.getPosition(); }
  
  
void Term  ::   setNet ( Net * net )
{
  
  if (net)
    {
      if (net->getCell ()!= getOwnerCell())
        cerr << "Erreur Term et Net n'appartiennent pas a la meme cell"<< endl;
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

  string Term :: toString    ( Term::Type type )
{
  return (type == 1) ? "Internal" : "External";
  
}
  string Term :: toString    ( Term::Direction direction )
  {
    switch (direction)
      {
        case 1:
         return "In";
        case 2:
         return "Out";
        case 3:
         return "Inout";
        case 4:
          return "Tristate";
        case 5:
          return "Transcv";
         case 6:
         return "Unknown";
                
      }
  }
Term ::Direction Term :: toDirection ( string str )
{
  if(str == "In")
    return In;
  if(str == "Out")
    return Out;
  if(str == "Inout")
    return Inout;
  if(str == "Tristate")
    return Tristate;
  if(str == "Transcv")
    return Transcv;
   if(str == "Unknown")
    return Unknown;
}

 void  Term::toXml ( ostream& stream )
{
  stream << indent   << "<term name =\""<<name_ <<"\" direction =\"" << ""<<toString( direction_)<< "\"/"">\n";
}
  
  
  
  
 


  
}
