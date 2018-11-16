//
#ifndef NETLIST_NET_H
#define NETLIST_NET_H

#include<string>
#include<vector>
#include"Indentation.h"
#include"Term.h"




namespace Netlist {
   class Cell ;
   class Node ;
    
class Net {
   
    
    private :
    Cell * owner_ ;
    std :: string name_ ;
    unsigned int id_ ;
    Term :: Type type_ ;
    std :: vector < Node * > nodes_ ;
    
    public :
    void  toXml ( std::ostream& ); //toXml
    Net ( Cell *, const std :: string &, Term :: Type );
    ~ Net ();
    inline Cell * getCell () const ;
    inline const std :: string & getName () const ;
    inline unsigned int getId () const ;
    inline Term :: Type getType () const ;
    inline const std :: vector < Node * >&getNodes () const ;
    Node * getNode ( size_t id ) const ;
    size_t getFreeNodeId () const ;
    void add ( Node * );
    bool remove ( Node * );
    
};
  inline Cell *                          Net ::  getCell () const { return  owner_; }
  inline const std :: string &           Net :: getName () const { return name_; }
  inline unsigned int                    Net ::  getId () const    { return id_; }
  inline Term :: Type                    Net ::  getType ()   const { return type_; }
  inline const std :: vector < Node * >& Net :: getNodes () const { return nodes_; }
    

}// Netlist namespace.

#endif //  NETLIST_NET_H
