#ifndef NETLIST_TERM_H
#define NETLIST_TERM_H

#include <string>
#include "Indentation.h"
#include "Node.h"

namespace Netlist {

  class Net;
  class Cell;
  class Instance;
  class Node;
  
class Term {
  public :
    void  toXml ( std::ostream& ); //toXml
    enum Type { Internal =1 , External =2 };
    enum Direction { In =1 , Out =2 , Inout =3 , Tristate =4 , Transcv =5, Unknown =6 };
    
private :
    void * owner_ ;
    std :: string name_ ;
    Direction direction_ ;
    Type type_ ;
    Net * net_ ;
    Node node_ ;
public :
    Term ( Cell * , const std :: string & name , Direction );
    Term ( Instance * , const Term * modelTerm );
    ~ Term ();
    bool isInternal () const ;
    bool isExternal () const ;
    inline  const std :: string & getName () const ;
    inline Node * getNode ();
    inline Net  * getNet () const ;
    inline Cell * getCell () const ;
    inline  Instance * getInstance () const ;
    inline Direction getDirection () const ;
    inline Type getType () const ;
    Cell * getOwnerCell () const ;
    Point getPosition () const ;
    void setNet ( Net * );
    void setNet ( const std :: string & );
    void setPosition ( const Point & );
    void setPosition ( int x , int y );
    void setDirection ( Direction );
  //Méthodes static 
    static std::string  toString    ( Type );
    static std::string  toString    ( Direction );
    static Direction    toDirection ( std::string );
};
    inline  const std :: string & Term :: getName () const     { return name_; }
    inline Node *               Term :: getNode ()           { return &node_; }
    inline Net  *               Term :: getNet () const      { return net_; }
    inline Cell *               Term :: getCell () const     { return ( type_ == External ) ? static_cast < Cell * >( owner_ ): NULL ; }
  inline  Instance *            Term :: getInstance () const { return ( type_ == Internal ) ? static_cast < Instance * >( owner_ ): NULL ; }
  inline Term :: Direction            Term :: getDirection () const { return direction_; }
  inline Term :: Type                 Term :: getType () const     { return type_; }


} //netlist namespace
#endif //  NETLIST_TERM_H
